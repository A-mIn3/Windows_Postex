## PwnService
   A service wrapper for running payloads when exploiting Windows services weak permissions without being terminated by the SCM. This is needed if we don't want to create additional processes and run only from within the service process. 
You can modify the SERVICE_NAME macro and add your code to the payload function.
It might also be necessary to add some control event processing to the service handler.


## MeterDLL
 A DLL wrapping of meterpreter.
 Can be further improved to include forwarded exports depending on the DLL one wants to spoof.
 

## MSRPC-brute
  Automation of [winexe](https://sourceforge.net/projects/winexe/) for bruteforcing access to Windows RPC (IPC$ share).</br> 
 Please note that even if you have the correct admin credentials you might still not have access due to [UAC remote restrictions](https://support.microsoft.com/en-us/help/951016/description-of-user-account-control-and-remote-restrictions-in-windows).
 
## Disclaimer
Theses tools are made only for educational purposes and can be only used in legitimate penetration tests. Author does not take any responsibility for any actions taken by its users.
