# Handles

version 21H1 19043.964

random viewed huge handles leak in svchost.exe -k DcomLaunch -p -s LSM process. 
160.000+ Events and 100.000+ Semaphores (all is unnamed)
abnormal huge and Registration objects in system - 13988 at maximum
huge count of memory blocks with 200kb size (probably heap(s))
visible many time tag Asyc and qqqqqqqqqqqqqqqq

'Asyc' tag used by rpcrt4 - set in HRESULT NdrpInitializeAsyncMsg(void *,_NDR_ASYNC_MESSAGE *) and tested inside 
RpcAsyncCompleteCall;
HRESULT NdrValidateBoth(_RPC_ASYNC_STATE *);
so probably error in asynchronous rpc calls

may be related to Semaphores with name 
\BaseNamedObjects\SM0:4684:120:WilError_03_p0h, 
\BaseNamedObjects\SM0:2780:304:WilStaging_02_p0h and so on..