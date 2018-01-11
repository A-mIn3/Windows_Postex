#include <windows.h>
#include <lm.h>

#define SERVICE_NAME "PWNED"

void WINAPI PwnedServiceCtrlHandler(DWORD opcode);
void PwnedServiceStart(DWORD argc, LPTSTR *argv);
DWORD InvokePayload(void); 


SERVICE_STATUS PwnedServiceStatus;
SERVICE_STATUS_HANDLE PwnedServiceStatusHandle;
HANDLE Stop_Event;


int main(int argc, char **argv)
{
        SERVICE_TABLE_ENTRYA DispatchTable[] = { 
					         {SERVICE_NAME , (LPSERVICE_MAIN_FUNCTIONA)PwnedServiceStart}, 
					         {NULL         ,  NULL}
	                                      };
     
        if(!StartServiceCtrlDispatcherA(DispatchTable))
		return EXIT_FAILURE;
    
        return EXIT_SUCCESS;
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
	
	InvokePayload(); // this might need to be invoked as a separate thread
		
	return;
}

void WINAPI PwnedServiceCtrlHandler(DWORD opcode){

	switch(opcode){
	       
	     case SERVICE_CONTROL_STOP:
			
		   // clean-up ....
		PwnedServiceStatus.dwCurrentState = SERVICE_STOPPED;
		PwnedServiceStatus.dwWaitHint = 0;
		PwnedServiceStatus.dwCheckPoint = 0;
		PwnedServiceStatus.dwWin32ExitCode = 0;
		SetServiceStatus(PwnedServiceStatusHandle, &PwnedServiceStatus);
	           	
                break;

		// more controls can be implemented here	
       }

       return;
}





DWORD InvokePayload(void){

	// add your payload here 
}
