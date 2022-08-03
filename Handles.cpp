#include "stdafx.h"

_NT_BEGIN

class COBJECT_ALL_TYPES_INFORMATION
{
	POBJECT_TYPE_INFORMATION _TypeInformation = 0;
	ULONG _NumberOfTypes = 0, _TypeIndexDelta = 0;

	NTSTATUS Init(POBJECT_TYPES_INFORMATION pTypes, ULONG cb);

public:

	ULONG count()
	{
		return _NumberOfTypes;
	}

	ULONG maxIndex()
	{
		return _NumberOfTypes + _TypeIndexDelta;
	}

	operator const OBJECT_TYPE_INFORMATION*()
	{
		return _TypeInformation;
	}

	const OBJECT_TYPE_INFORMATION* operator[](ULONG Index)
	{
		return Index < _NumberOfTypes ? _TypeInformation + Index : 0;
	}

	int TypeIndexToIndex(ULONG TypeIndex);

	const OBJECT_TYPE_INFORMATION* operator[](PCUNICODE_STRING TypeName);

	NTSTATUS Init();

	~COBJECT_ALL_TYPES_INFORMATION()
	{
		if (_TypeInformation)
		{
			delete [] _TypeInformation;
		}
	}
};

int COBJECT_ALL_TYPES_INFORMATION::TypeIndexToIndex(ULONG TypeIndex)
{
	if (ULONG NumberOfTypes = _NumberOfTypes)
	{
		POBJECT_TYPE_INFORMATION TypeInformation = _TypeInformation;

		ULONG index = TypeIndex - _TypeIndexDelta;

		if (index > NumberOfTypes)
		{
			return -1;
		}

		if (TypeInformation[index].TypeIndex == TypeIndex)
		{
			return index;
		}

		index = 0;

		do 
		{
			if (TypeInformation->TypeIndex == TypeIndex)
			{
				return index;
			}
		} while (TypeInformation++, index++, --NumberOfTypes);
	}

	return -1;
}

const OBJECT_TYPE_INFORMATION* COBJECT_ALL_TYPES_INFORMATION::operator[](PCUNICODE_STRING TypeName)
{
	if (ULONG NumberOfTypes = _NumberOfTypes)
	{
		POBJECT_TYPE_INFORMATION TypeInformation = _TypeInformation;

		do 
		{
			if (RtlEqualUnicodeString(TypeName, &TypeInformation->TypeName, TRUE))
			{
				return TypeInformation;
			}
		} while (TypeInformation++, -- NumberOfTypes);
	}

	return 0;
}

extern volatile const UCHAR guz = 0;

NTSTATUS COBJECT_ALL_TYPES_INFORMATION::Init(POBJECT_TYPES_INFORMATION pTypes, ULONG cb)
{
	if (ULONG NumberOfTypes = pTypes->NumberOfTypes)
	{
		union {
			PVOID pv;
			ULONG_PTR up;
			POBJECT_TYPE_INFORMATION TypeInformation;
		};

		if (pv = new UCHAR[cb])
		{
			_NumberOfTypes = NumberOfTypes;
			_TypeInformation = TypeInformation;

			ULONG Index = 0;

			union {
				ULONG_PTR uptr;
				POBJECT_TYPE_INFORMATION pti;
			};

			union {
				PWSTR buf;
				PBYTE pb;
				PVOID pv;
			};

			pti = pTypes->TypeInformation;
			pv = TypeInformation + NumberOfTypes;

			_TypeIndexDelta = pti->TypeIndex;

			DbgPrint(
				" I  Access       GE        GR        GW        GA        O        mO         H       mH        PT       IA    Name\r\n"
				"==================================================================================================================\r\n");
			do 
			{
				DbgPrint("%02x %08x { %08x, %08x, %08x, %08x} %08x(%08x) %08x(%08x) %08x %08x %wZ\r\n", 
					pti->TypeIndex, 
					pti->ValidAccessMask,
					pti->GenericMapping.GenericExecute,
					pti->GenericMapping.GenericRead,
					pti->GenericMapping.GenericWrite,
					pti->GenericMapping.GenericAll,
					pti->TotalNumberOfObjects,
					pti->HighWaterNumberOfObjects,
					pti->TotalNumberOfHandles,
					pti->HighWaterNumberOfHandles,
					pti->PoolType,
					pti->InvalidAttributes,
					&pti->TypeName);

				ULONG Length = pti->TypeName.Length, MaximumLength = pti->TypeName.MaximumLength;
				memcpy(buf, pti->TypeName.Buffer, Length);

				*TypeInformation = *pti;
				TypeInformation++->TypeName.Buffer = buf;
				pb += Length;
				uptr += (sizeof(OBJECT_TYPE_INFORMATION) + MaximumLength + 
					__alignof(OBJECT_TYPE_INFORMATION) - 1) & ~ (__alignof(OBJECT_TYPE_INFORMATION)-1);

			} while (Index++, --NumberOfTypes);

			return STATUS_SUCCESS;
		}

		return STATUS_NO_MEMORY;
	}

	return STATUS_NOT_FOUND;
}

NTSTATUS COBJECT_ALL_TYPES_INFORMATION::Init()
{
	NTSTATUS status;

	ULONG cb = 0x4000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PVOID buf = new UCHAR[cb])
		{
			if (0 <= (status = NtQueryObject(0, ObjectAllTypeInformation, buf, cb, &cb)))
			{
				status = Init((POBJECT_TYPES_INFORMATION)buf, cb);
			}
			delete [] buf;
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	return status;
}

//////////////////////////////////////////////////////////////////////////

NTSTATUS BuildProcessList(_Out_ PSYSTEM_PROCESS_INFORMATION* ppspi)
{
	NTSTATUS status;

	union {
		PBYTE pb;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	ULONG cb = 0x40000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (pb = new BYTE[cb += PAGE_SIZE])
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, pb, cb, &cb)))
			{
				*ppspi = pspi;

				return STATUS_SUCCESS;
			}

			delete [] pb;
		}

	} while(status == STATUS_INFO_LENGTH_MISMATCH);

	return status;
}

PCUNICODE_STRING GetProcessName(_In_ PSYSTEM_PROCESS_INFORMATION pspi, _In_ ULONG_PTR UniqueProcessId)
{
	ULONG NextEntryOffset = 0;

	do 
	{
		(PBYTE&)pspi += NextEntryOffset;

		if (pspi->UniqueProcessId == (HANDLE)UniqueProcessId)
		{
			return &pspi->ImageName;
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	return 0;
}

static OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

NTSTATUS GetProcessCommandLine(_In_ ULONG_PTR UniqueProcessId, _Out_ POBJECT_NAME_INFORMATION* pponi)
{
	CLIENT_ID cid = { (HANDLE)UniqueProcessId };
	HANDLE hProcess;
	NTSTATUS status = NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, const_cast<POBJECT_ATTRIBUTES>(&zoa), &cid);

	if (0 <= status)
	{
		ULONG cb = 0x100;
		do 
		{
			union {
				POBJECT_NAME_INFORMATION poni;
				PBYTE buf;
			};
			if (buf = new UCHAR[cb])
			{
				if (0 <= (status = NtQueryInformationProcess(hProcess, ProcessCommandLineInformation, buf, cb, &cb)))
				{
					*pponi = poni, buf = 0;
				}
				delete [] buf;
			}
		} while (status == STATUS_INFO_LENGTH_MISMATCH);

		NtClose(hProcess);
	}

	return status;
}

void XD(_In_ PSYSTEM_HANDLE_INFORMATION_EX pshie, _In_ ULONG_PTR UniqueProcessId);

NTSTATUS TestHandles(_In_ PSYSTEM_PROCESS_INFORMATION pspi, COBJECT_ALL_TYPES_INFORMATION& ti)
{
	NTSTATUS status;
	ULONG cb = 0x10000;
	do 
	{
		union {
			PVOID buf;
			PSYSTEM_HANDLE_INFORMATION_EX pshie;
		};

		status = STATUS_NO_MEMORY;

		if (buf = LocalAlloc(0, cb + 0x1000))
		{
			if (0 <= (status = NtQuerySystemInformation(SystemExtendedHandleInformation, buf, cb, &cb)))
			{
				if (ULONG_PTR NumberOfHandles = pshie->NumberOfHandles)
				{
					DbgPrint("NumberOfHandles=%08x\n", NumberOfHandles);

					ULONG MaxIndex = ti.maxIndex(), n;
					PULONG cc = (PULONG)alloca(n = MaxIndex * sizeof(ULONG));
					RtlZeroMemory(cc, n);
					n = 0;
					ULONG_PTR UniqueProcessId = 0;

					PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Entry = pshie->Handles;
					do 
					{
						if (Entry->UniqueProcessId != UniqueProcessId)
						{
							if (UniqueProcessId)
							{
								DbgPrint("%08x> %08x %wZ", UniqueProcessId, n, GetProcessName(pspi, UniqueProcessId));

								POBJECT_NAME_INFORMATION poni;
								if (0 <= GetProcessCommandLine(UniqueProcessId, &poni))
								{
									DbgPrint("  >  %wZ", &poni->Name);
									delete [] poni;
								}
								DbgPrint("\n");
							}

							UniqueProcessId = Entry->UniqueProcessId, n = 0;
						}

						if (Entry->ObjectTypeIndex < MaxIndex)
						{
							cc[Entry->ObjectTypeIndex]++;
						}
						else
						{
							__debugbreak();
						}
						n++;

					} while (Entry++, --NumberOfHandles);

					do 
					{
						if (ULONG m = cc[--MaxIndex])
						{
							if (const OBJECT_TYPE_INFORMATION* Type = ti[ti.TypeIndexToIndex(MaxIndex)])
							{
								DbgPrint("%08x %wZ\r\n", m, &Type->TypeName);
							}
							else
							{
								DbgPrint("%08x [%02x]\r\n", m, MaxIndex);
							}
						}
					} while (MaxIndex);
				}

				XD(pshie, 0x218);
			}

			LocalFree(buf);
		}
		else
		{
			break;
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	return status;
}

void XD(_In_ PSYSTEM_HANDLE_INFORMATION_EX pshie, _In_ ULONG_PTR UniqueProcessId)
{
	DbgPrint("\r\n=====================================\r\n");
	union {
		PVOID buf;
		POBJECT_NAME_INFORMATION poni;
	};

	if (buf = new UCHAR[0x10000])
	{
		if (ULONG_PTR NumberOfHandles = pshie->NumberOfHandles)
		{
			HANDLE hProcess, hObject;
			CLIENT_ID cid = { (HANDLE)UniqueProcessId };

			if (0 <= NtOpenProcess(&hProcess, PROCESS_DUP_HANDLE, &zoa, &cid))
			{

				ULONG n = 0;

				PSYSTEM_HANDLE_TABLE_ENTRY_INFO_EX Entry = pshie->Handles;
				do 
				{
					if (Entry->UniqueProcessId == UniqueProcessId)
					{
						switch (Entry->ObjectTypeIndex)
						{
						case 0x32://EtwRegistration
							n++;
							break;
						case 0x13://Semaphore
						case 0x10://Event

							if (0 <= ZwDuplicateObject(hProcess, 
								(HANDLE)Entry->HandleValue, NtCurrentProcess(), &hObject,
								0, 0, DUPLICATE_SAME_ACCESS))
							{
								ULONG cb;
								if (0 <= NtQueryObject(hObject, ObjectNameInformation, buf, 0x10000, &cb))
								{
									if (poni->Name.Length)
									{
										DbgPrint("%08x %02x %wZ\r\n", Entry->HandleValue, Entry->ObjectTypeIndex, &poni->Name);
									}
								}
								else
								{
									__debugbreak();
								}

								NtClose(hObject);
							}
							else
							{
								__debugbreak();
							}
							break;
						}
					}

				} while (Entry++, --NumberOfHandles);

				NtClose(hProcess);
			}
		}

		delete [] buf;
	}
}

void WINAPI ep(void*)
{
	BOOLEAN b;
	RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &b);

	{
		COBJECT_ALL_TYPES_INFORMATION ti;
		PSYSTEM_PROCESS_INFORMATION pspi;

		if (0 <= ti.Init())
		{
			if (0 <= BuildProcessList(&pspi))
			{
				TestHandles(pspi, ti);
				delete [] pspi;
			}
		}
	}

	ExitProcess(0);
}

_NT_END