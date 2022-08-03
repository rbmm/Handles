# Handles

version 21H1 19043.964

random viewed huge handles leak in svchost.exe -k DcomLaunch -p -s LSM process. 
160.000+ Events and 100.000+ Semaphores (all is unnamed)
abnormal huge and Registration objects in system - 13988 at maximum
huge count of memory blocks with 200kb size (probably heap(s))
visible many time tag Asyc and qqqqqqqqqqqqqqqq

 
 I  Access       GE        GR        GW        GA        O        mO         H       mH        PT       IA    Name
==================================================================================================================
02 001f0001 { 00020000, 00020000, 00020000, 000f0001} 00000043(00000043) 00000000(00000000) 00000200 00000100 Type
03 000f000f { 00020003, 00020003, 0002000c, 000f000f} 00000043(00000046) 0000012a(00000195) 00000001 00000100 Directory
04 000fffff { 00020001, 00020001, 00020000, 000f0001} 00000183(00000187) 000000b8(000000bf) 00000001 00000100 SymbolicLink
05 001f01ff { 00020005, 0002001a, 000201e0, 000f01ff} 00000839(000009f3) 00000242(000002a1) 00000001 00000100 Token
06 001f003f { 00120000, 00020004, 0002000b, 001f003f} 00000095(000000b1) 000000d5(000000f2) 00000200 00000000 Job
07 001fffff { 00121001, 00020410, 00020bea, 001fffff} 0000007a(000000a6) 00000503(00000854) 00000200 000000b0 Process
08 001fffff { 00121800, 00020048, 00020437, 001fffff} 00000476(00000c04) 0000054a(00000ef9) 00000200 000000b0 Thread
09 001f0003 { 00120001, 00020001, 00020002, 001f0003} 00000001(00000001) 00000003(00000003) 00000200 00000010 Partition
0a 000f0003 { 00020000, 00020001, 00020002, 000f0003} 00000000(00000000) 00000000(00000000) 00000200 000000b0 UserApcReserve
0b 000f0003 { 00020000, 00020001, 00020002, 000f0003} 00000041(00000055) 00000041(00000055) 00000200 000000b0 IoCompletionReserve
0c 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000000(00000002) 00000000(00000002) 00000001 00000192 ActivityReference
0d 001f0000 { 00020000, 00020000, 00020000, 000f0000} 00000001(00000001) 00000000(00000000) 00000001 00000000 PsSiloContextPaged
0e 001f0000 { 00020000, 00020000, 00020000, 000f0000} 00000005(00000005) 00000000(00000000) 00000200 00000000 PsSiloContextNonPaged
0f 001f000f { 00120000, 00020001, 00020002, 001f000f} 00000002(00000007) 00000002(00000007) 00000200 00000000 DebugObject
10 001f0003 { 00120000, 00020001, 00020002, 001f0003} 00028bbd(0002a46a) 00028da6(0002a8e3) 00000200 00000100 Event
11 001f0001 { 00120000, 00020001, 00020000, 001f0001} 0000020d(00000380) 00000255(0000040c) 00000200 00000100 Mutant
12 001f0001 { 00120000, 00020000, 00020001, 001f0001} 00000026(00000026) 00000000(00000001) 00000200 00000100 Callback
13 001f0003 { 00120000, 00020001, 00020002, 001f0003} 00019e83(0001a11e) 00019e8a(0001a13b) 00000200 00000100 Semaphore
14 001f0003 { 00120000, 00020001, 00020002, 001f0003} 000000ed(00000119) 00000117(00000143) 00000200 00000100 Timer
15 001f0003 { 00120000, 00020001, 00020002, 001f0003} 000002f3(00000406) 000002f3(00000406) 00000200 00000100 IRTimer
16 000f0001 { 00020001, 00020001, 00020001, 000f0001} 00000000(00000000) 00000000(00000000) 00000200 00000100 Profile
17 001f0003 { 00020000, 00020001, 00020002, 000f0003} 00000001(00000001) 00000000(00000001) 00000001 00000000 KeyedEvent
18 000f037f { 00020060, 00020303, 0002001c, 000f037f} 00000007(00000008) 000000c8(00000109) 00000200 00000130 WindowStation
19 000f01ff { 00020100, 00020041, 000200be, 000f01ff} 0000000b(0000000e) 0000006a(0000008c) 00000200 00000130 Desktop
1a 000f0003 { 00020000, 00020001, 00020002, 000f0003} 00000136(000001e8) 00000111(000001c1) 00000200 00000130 Composition
1b 000f0003 { 00020000, 00020001, 00020002, 000f0003} 00000014(00000015) 0000001c(0000001e) 00000200 00000130 RawInputManager
1c 000f0000 { 00020000, 00020000, 00020000, 000f0000} 00000014(00000014) 00000014(00000014) 00000200 00000130 CoreMessaging
1d 000f0003 { 00020000, 00020001, 00020002, 000f0003} 00000000(00000000) 00000000(00000000) 00000221 00000130 ActivationObject
1e 000f00ff { 00020003, 00020008, 00020004, 000f00ff} 00000178(00000200) 00000178(00000200) 00000200 00000100 TpWorkerFactory
1f 001f01ff { 001200a0, 00120089, 00120116, 001f01ff} 00000000(00000000) 00000000(00000000) 00000200 00000100 Adapter
20 001f01ff { 001200a0, 00120089, 00120116, 001f01ff} 00000000(00000001) 00000000(00000001) 00000200 00000100 Controller
21 001f01ff { 001200a0, 00120089, 00120116, 001f01ff} 00000207(0000020b) 00000000(00000003) 00000200 00000100 Device
22 001f01ff { 001200a0, 00120089, 00120116, 001f01ff} 000000a3(000000a3) 00000000(00000001) 00000200 00000100 Driver
23 001f0003 { 00120000, 00020001, 00020002, 001f0003} 000002f2(00000425) 000003d8(000005e2) 00000200 00000110 IoCompletion
24 001f0001 { 00020001, 00020001, 00020001, 000f0001} 00000b87(00001021) 00000b5d(00001008) 00000200 00000110 WaitCompletionPacket
25 001f01ff { 001200a0, 00120089, 00120116, 001f01ff} 00009235(0000aa0d) 00000b1f(00001336) 00000200 00000130 File
26 000f003f { 00020000, 00020001, 0002001e, 000f003f} 0000000e(0000000f) 0000000e(00000010) 00000200 00000100 TmTm
27 001f007f { 00120018, 00120001, 0012003e, 001f007f} 00000000(00000001) 00000000(00000001) 00000200 00000100 TmTx
28 001f007f { 0012005c, 00120001, 0012007e, 001f007f} 0000001c(0000001e) 0000001c(0000001e) 00000200 00000100 TmRm
29 000f001f { 0002001c, 00020001, 0002001e, 000f001f} 00000000(00000001) 00000000(00000001) 00000200 00000100 TmEn
2a 001f001f { 00020008, 00020005, 00020002, 000f001f} 000018fd(00003426) 00000558(000009f1) 00000001 00000100 Section
2b 001f0003 { 00120001, 00020001, 00020002, 000f0003} 00000002(00000002) 00000018(00000019) 00000200 00000000 Session
2c 001f003f { 00020039, 00020019, 00020006, 000f003f} 00000c85(0000108e) 00000c89(00001090) 00000001 00000030 Key
2d 001f003f { 00120018, 00120001, 0012003e, 001f003f} 00000000(00000000) 00000000(00000000) 00000001 00000030 RegistryTransaction
2e 001f0001 { 00000000, 00020001, 00010001, 001f0001} 0000086a(00000a20) 00000839(000009fc) 00000200 00000080 ALPC Port
2f 001f0001 { 00000000, 00000000, 00000000, 00000000} 00000001(00000001) 00000001(00000001) 00000001 00000192 EnergyTracker
30 001f0000 { 00020000, 00020000, 00020000, 001f0000} 0000000d(0000000f) 00000006(00000008) 00000200 00000192 PowerRequest
31 001f1fff { 00000010, 00000001, 00000002, 00121fff} 0000001a(0000001d) 00000018(0000001b) 00000200 00000100 WmiGuid
32 00000804 { 00021e90, 0002000d, 00020062, 00021eff} 00002648(000036a4) 00002648(000036a4) 00000200 00000100 EtwRegistration
33 00100000 { 00021e90, 0002000d, 00020062, 00021eff} 00000000(00000000) 00000000(00000000) 00000001 00000100 EtwSessionDemuxEntry
34 00000400 { 00021e90, 0002000d, 00020062, 00021eff} 00000005(00000005) 00000005(00000005) 00000200 00000100 EtwConsumer
35 001f0001 { 00000000, 00000000, 00000000, 00000000} 00000000(00000000) 00000000(00000000) 00000001 00000192 CoverageSampler
36 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000004(00000004) 00000000(00000001) 00000200 00000100 DmaAdapter
37 001f0003 { 00000000, 00000001, 00000002, 000f0003} 00000011(00000016) 00000011(00000016) 00000001 00000132 PcwObject
38 001f0001 { 00000000, 00020001, 00010001, 001f0001} 00000004(00000004) 00000004(00000004) 00000200 00000100 FilterConnectionPort
39 001f0001 { 00000000, 00020001, 00010001, 001f0001} 00000001(00000001) 00000001(00000001) 00000200 00000100 FilterCommunicationPort
3a 001f003f { 00000000, 00000000, 00000000, 00000000} 00000000(00000000) 00000000(00000000) 00000200 00000000 NdisCmState
3b 001f0001 { 00020000, 00020000, 00020001, 000f0001} 0000000c(0000001b) 00000002(00000019) 00000001 00000100 DxgkSharedResource
3c 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000000(00000000) 00000000(00000000) 00000001 00000100 DxgkSharedKeyedMutexObject
3d 001f0003 { 00120000, 00020001, 00020002, 001f0003} 00000002(00000007) 00000004(0000000a) 00000001 00000100 DxgkSharedSyncObject
3e 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000000(00000000) 00000000(00000000) 00000001 00000100 DxgkSharedSwapChainObject
3f 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000001(00000003) 00000001(00000003) 00000001 00000100 DxgkDisplayManagerObject
40 001f0001 { 00020000, 00020000, 00020001, 000f0001} 00000131(00000202) 00000000(00000000) 00000200 00000100 DxgkCurrentDxgThreadObject
41 001f0000 { 00020000, 00020000, 00020000, 001f0000} 00000000(00000000) 00000000(00000000) 00000001 00000100 DxgkSharedProtectedSessionObject
42 001f0003 { 00120000, 00020001, 00020003, 001f0003} 00000000(00000000) 00000000(00000000) 00000001 00000100 DxgkSharedBundleObject
43 001f0003 { 00020000, 00020001, 00020002, 000f0003} 0000000c(0000001b) 0000000e(0000002c) 00000001 00000100 DxgkCompositionObject
44 001f0000 { 00020000, 00020000, 00020000, 000f0000} 00000000(00000000) 00000000(00000000) 00000001 00000100 VRegConfigurationContext

NumberOfHandles=0004a14d

00000004> 00000a82 System
00000190> 00000035 smss.exe  >  \SystemRoot\System32\smss.exe
00000220> 000001cd csrss.exe  >  %SystemRoot%\system32\csrss.exe ObjectDirectory=\Windows SharedSection=1024,20480,768 Windows=On SubSystemType=Windows ServerDll=basesrv,1 ServerDll=winsrv:UserServerDllInitialization,3 ServerDll=sxssrv,4 ProfileControl=Off MaxRequestThreads=16
00000274> 000000a1 wininit.exe  >  wininit.exe
0000027c> 00000256 csrss.exe  >  %SystemRoot%\system32\csrss.exe ObjectDirectory=\Windows SharedSection=1024,20480,768 Windows=On SubSystemType=Windows ServerDll=basesrv,1 ServerDll=winsrv:UserServerDllInitialization,3 ServerDll=sxssrv,4 ProfileControl=Off MaxRequestThreads=16
000002d4> 00000117 winlogon.exe  >  winlogon.exe
000002e8> 00000248 services.exe  >  C:\WINDOWS\system32\services.exe
00000314> 000004de lsass.exe  >  C:\WINDOWS\system32\lsass.exe
00000394> 0000052a svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k DcomLaunch -p
000003b0> 00000020 fontdrvhost.exe  >  "fontdrvhost.exe"
000003b4> 00000020 fontdrvhost.exe  >  "fontdrvhost.exe"
000001d4> 000003f4 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k RPCSS -p

        !!!!! ---------------------->
	   
00000218> 00026370 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k DcomLaunch -p -s LSM
		
		<---------------------- !!!!!

000001f4> 00000443 dwm.exe  >  "dwm.exe"
00000464> 000001da svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k NetworkService -s TermService
00000508> 00000185 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalServiceNetworkRestricted -p -s EventLog
00000520> 000000da svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalSystemNetworkRestricted -p -s NcbService
00000528> 000000f7 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s ProfSvc
00000530> 00000227 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceNetworkRestricted -p -s TimeBrokerSvc
00000538> 00000148 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s Schedule
000005bc> 000000fa svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -s CertPropSvc
000005c8> 0000009f svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceNoNetwork -p
000005f4> 000000eb svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s UserManager
0000060c> 00000088 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalSystemNetworkRestricted -p -s hidserv
00000620> 0000007e svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s nsi
00000648> 000000c8 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceAndNoImpersonation -s SCardSvr
00000658> 00000079 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -s SCPolicySvc
000006cc> 000000fe svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceNetworkRestricted -p -s Dhcp
0000075c> 000000b5 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalSystemNetworkRestricted -p -s UmRdpService
000007ac> 00000194 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k NetworkService -p -s NlaSvc
00000344> 000000b3 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceNetworkRestricted -p -s NgcCtnrSvc
00000880> 00000168 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalService -p -s netprofm
00000934> 00000127 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k NetworkService -p -s Dnscache
00000980> 000001bb svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k netsvcs -p -s BITS
00000a5c> 000000ef svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalSystemNetworkRestricted -p -s SysMain
00000a64> 000000a7 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k netsvcs -p -s Themes
00000a6c> 000000a8 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s EventSystem
00000adc> 000000b1 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s SENS
00000af4> 000000c0 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalSystemNetworkRestricted -p -s AudioEndpointBuilder
00000afc> 000000aa svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s FontCache
00000b74> 00000172 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalServiceNetworkRestricted -p
00000bc0> 00000167 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalServiceNetworkRestricted -p
00000bc8> 0000007e svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalServiceNetworkRestricted -p
00000bd0> 000000ae svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k appmodel -p -s StateRepository
000008a4> 0000012a svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k netsvcs -p -s ShellHWDetection
00000c08> 00000108 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s Winmgmt
00000c20> 000000be svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k NetworkService -p -s LanmanWorkstation
00000c2c> 00000165 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k NetSvcs -p -s iphlpsvc
00000cd8> 00019812 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k NetworkService -p -s CryptSvc
00000ce8> 00000097 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalSystemNetworkRestricted -p -s DeviceAssociationService
00000cf4> 00000124 Immersed-service.exe  >  "D:\BTH\Immersed\immersed-service.exe"
00000d44> 00000081 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s SstpSvc
00000d58> 0000011c svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k imgsvc
00000d64> 000000c9 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k iissvcs
00000d6c> 00000167 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s WpnService
00000de0> 000000f4 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s LanmanServer
00000df4> 00000123 dasHost.exe  >  dashost.exe {e3cd8f65-2483-402b-a53515aea8bf864b}
00000ed0> 00000148 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k netsvcs
000010b8> 00000211 sihost.exe  >  sihost.exe
000010d0> 00000135 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k UnistackSvcGroup -s CDPUserSvc
000010f8> 000001f7 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k UnistackSvcGroup -s WpnUserService
00001164> 000000a8 svchost.exe  >  C:\WINDOWS\System32\svchost.exe -k LocalSystemNetworkRestricted -p -s TabletInputService
00001180> 000001cf ctfmon.exe  >  "ctfmon.exe"
0000118c> 000000fa svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s TokenBroker
00001228> 00000126 taskhostw.exe  >  taskhostw.exe {222A245B-E637-4AE9-A93F-A59CA119A75E}
0000124c> 00000139 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s CDPSvc
000012f0> 0000098b explorer.exe  >  C:\WINDOWS\Explorer.EXE
00000a58> 00000092 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalSystemNetworkRestricted -p -s NgcSvc
000014e8> 00000268 StartMenuExperienceHost.exe  >  "C:\Windows\SystemApps\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\StartMenuExperienceHost.exe" -ServerName:App.AppXywbrabmsek0gm3tkwpr5kwzbs55tkqay.mca
0000155c> 000000df RuntimeBroker.exe  >  C:\Windows\System32\RuntimeBroker.exe -Embedding
0000160c> 000004f8 SearchApp.exe  >  "C:\Windows\SystemApps\Microsoft.Windows.Search_cw5n1h2txyewy\SearchApp.exe" -ServerName:CortanaUI.AppX8z9r6jm96hw4bsbneegw0kyxx296wr9t.mca
00001684> 000001ac RuntimeBroker.exe  >  C:\Windows\System32\RuntimeBroker.exe -Embedding
0000180c> 000001ff LockApp.exe  >  "C:\Windows\SystemApps\Microsoft.LockApp_cw5n1h2txyewy\LockApp.exe" -ServerName:WindowsDefaultLockScreen.AppX7y4nbzq37zn4ks9k7amqjywdat7d3j2z.mca
0000188c> 00000144 RuntimeBroker.exe  >  C:\Windows\System32\RuntimeBroker.exe -Embedding
00001954> 00000091 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k LocalService -p -s BthAvctpSvc
00001984> 00000141 RuntimeBroker.exe  >  C:\Windows\System32\RuntimeBroker.exe -Embedding
00000d00> 000000e9 svchost.exe  >  C:\WINDOWS\system32\svchost.exe -k netsvcs -p -s Appinfo

......

0000000e DxgkCompositionObject
00000001 DxgkDisplayManagerObject
00000004 DxgkSharedSyncObject
00000002 DxgkSharedResource
00000001 FilterCommunicationPort
00000004 FilterConnectionPort
00000011 PcwObject
00000005 EtwConsumer
00002648 EtwRegistration
00000018 WmiGuid
00000006 PowerRequest
00000001 EnergyTracker
00000839 ALPC Port
00000c89 Key
00000018 Session
00000558 Section
0000001c TmRm
0000000e TmTm
00000b1f File
00000b5d WaitCompletionPacket
000003d8 IoCompletion
00000178 TpWorkerFactory
00000014 CoreMessaging
0000001c RawInputManager
00000111 Composition
0000006a Desktop
000000c8 WindowStation
000002f3 IRTimer
00000117 Timer
00019e8a Semaphore       <---------------------- !!!!!
00000255 Mutant
00028da6 Event           <---------------------- !!!!!
00000002 DebugObject
00000041 IoCompletionReserve
00000003 Partition
0000054a Thread
00000503 Process
000000d5 Job
00000242 Token
000000b8 SymbolicLink
0000012a Directory

=====================================

00000294 13 \BaseNamedObjects\SM0:536:304:WilStaging_02_p0
000002b4 10 \Sessions\1\Windows\DwmCatastrophicShutdown
00000304 13 \BaseNamedObjects\SM0:536:304:WilStaging_02_p0h
0000030c 10 \BaseNamedObjects\RCMReadyEvent
0000033c 10 \BaseNamedObjects\TermSrvReadyEvent
000003a0 10 \KernelObjects\MaximumCommitCondition
000004d0 13 \BaseNamedObjects\SM0:536:120:WilError_03_p0
000004d8 13 \BaseNamedObjects\SM0:536:120:WilError_03_p0h

=======================================================
modules in svchost.exe -k DcomLaunch -p -s LSM:

Load: base=00007FF6FEF00000, size=00011000, ep=00007FF6FEF04E80 C:\WINDOWS\system32\svchost.exe
Load: base=00007FFB92DB0000, size=001f5000, ep=0000000000000000 C:\WINDOWS\SYSTEM32\ntdll.dll
Load: base=00007FFB92410000, size=000bd000, ep=00007FFB924270D0 C:\WINDOWS\System32\KERNEL32.DLL
Load: base=00007FFB90780000, size=002c8000, ep=00007FFB90790650 C:\WINDOWS\System32\KERNELBASE.dll
Load: base=00007FFB92900000, size=0009b000, ep=00007FFB9291CD40 C:\WINDOWS\System32\sechost.dll
Load: base=00007FFB91280000, size=0012b000, ep=00007FFB912DEDB0 C:\WINDOWS\System32\RPCRT4.dll
Load: base=00007FFB90540000, size=00100000, ep=00007FFB90556110 C:\WINDOWS\System32\ucrtbase.dll
Load: base=00007FFB8E380000, size=000d7000, ep=00007FFB8E3AC260 c:\windows\system32\lsm.dll
Load: base=00007FFB91A00000, size=0009e000, ep=00007FFB91A07850 C:\WINDOWS\System32\msvcrt.dll
Load: base=00007FFB91660000, size=001a0000, ep=00007FFB91677F30 C:\WINDOWS\System32\USER32.dll
Load: base=00007FFB906F0000, size=00022000, ep=0000000000000000 C:\WINDOWS\System32\win32u.dll
Load: base=00007FFB92A50000, size=0002a000, ep=00007FFB92A548D0 C:\WINDOWS\System32\GDI32.dll
Load: base=00007FFB90BA0000, size=0010b000, ep=00007FFB90BCFE60 C:\WINDOWS\System32\gdi32full.dll
Load: base=00007FFB90B00000, size=0009d000, ep=00007FFB90B15390 C:\WINDOWS\System32\msvcp_win.dll
Load: base=00007FFB924D0000, size=00355000, ep=00007FFB925C2D50 C:\WINDOWS\System32\combase.dll
Load: base=00007FFB92A80000, size=000ac000, ep=00007FFB92A95600 C:\WINDOWS\System32\advapi32.dll
Load: base=00007FFB8E280000, size=0002f000, ep=00007FFB8E284D40 c:\windows\system32\dwmapi.dll
Load: base=00007FFB8FE90000, size=0002c000, ep=00007FFB8FE92DB0 C:\WINDOWS\SYSTEM32\WLDP.DLL
Load: base=00007FFB904F0000, size=0004e000, ep=00007FFB90503280 C:\WINDOWS\System32\cfgmgr32.dll
Load: base=00007FFB90A80000, size=00080000, ep=00007FFB90AB7C50 C:\WINDOWS\System32\bcryptPrimitives.dll
Load: base=00007FFB91950000, size=000ae000, ep=00007FFB9198BBD0 C:\WINDOWS\System32\shcore.dll
Load: base=00007FFB921F0000, size=0006b000, ep=00007FFB92204300 C:\WINDOWS\System32\WS2_32.dll
Load: base=00007FFB8FC00000, size=0006a000, ep=00007FFB8FC11200 C:\WINDOWS\system32\mswsock.dll
Load: base=00007FFB8E090000, size=00007000, ep=00007FFB8E091570 C:\WINDOWS\system32\wshhyperv.dll
Load: base=00007FFB8E080000, size=0000c000, ep=00007FFB8E082BA0 c:\windows\system32\SYSNTFY.dll
Load: base=00007FFB8EE30000, size=000f4000, ep=00007FFB8EE552E0 C:\WINDOWS\SYSTEM32\dxgi.dll
Load: base=00007FFB903B0000, size=00031000, ep=00007FFB903BE390 C:\WINDOWS\system32\sspicli.dll
Load: base=00007FFB903F0000, size=0002e000, ep=00007FFB903F4F10 C:\WINDOWS\System32\Userenv.dll
Load: base=00007FFB901D0000, size=0002c000, ep=00007FFB901D7370 c:\windows\system32\DEVOBJ.dll
Load: base=00007FFB8E460000, size=00012000, ep=00007FFB8E463F10 C:\WINDOWS\SYSTEM32\kernel.appcore.dll
Load: base=00007FFB929A0000, size=000a9000, ep=00007FFB929BD990 C:\WINDOWS\System32\clbcatq.dll
Load: base=00007FFB8BD00000, size=00011000, ep=00007FFB8BD01400 C:\WINDOWS\system32\lsmproxy.dll
Load: base=00007FFB81110000, size=0005f000, ep=00007FFB81118E20 C:\WINDOWS\system32\AppXAllUserStore.dll
Load: base=00007FFB92B30000, size=000cd000, ep=00007FFB92B4CEB0 C:\WINDOWS\System32\OLEAUT32.dll
Load: base=00007FFB7AAD0000, size=00146000, ep=00007FFB7AAD7620 C:\Windows\System32\Windows.StateRepositoryPS.dll


