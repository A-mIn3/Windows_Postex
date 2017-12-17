## PwnService
   A service wrapper for running payloads exploting Windows services weak permissions without being terminated by the SCM.
 This is needed if we don't want to create more processes and only run from within the service process.
	All you need to do is modify the SERVICE_NAME macro and add your code to the payload function.
	Note that depending on the target service, it might be necessary to add some control event processing to the service handler,
	otherwise the SCM will not be happy.


## MeterDLL
 A DLL wrapping of meterpreter.
 Can be further improved to include forwarded exports depending on the DLL one wants to spoof.
 
 
 ## MSRPC-brute
  Automation of [winexe](https://sourceforge.net/projects/winexe/) for bruteforcing access to Windows RPC (IPC$ share).</br> 
 Please note that even if you have the correct admin credentials you might still not have access due to [UAC remote restrictions](https://support.microsoft.com/en-us/help/951016/description-of-user-account-control-and-remote-restrictions-in-windows).
 
