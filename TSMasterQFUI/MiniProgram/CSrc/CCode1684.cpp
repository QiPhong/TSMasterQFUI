// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Global_Definitions 
 #include <windows.h>
  #include "QFUI/QFUI.h"
 
 


  typedef AgentWndImport* ( * __stdcall CAW)(); 
// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN On_Start NewOn_Start1
// 启动事件 "NewOn_Start1"
void on_start_NewOn_Start1(void) { __try { // 程序启动事件
 HMODULE hm = LoadLibraryA("C:\\Users\\Administrator\\Desktop\\QFUI\\Release\\QWNDHandle.dll");
	if (NULL != hm) {
    typedef  wchar_t* (*TGW)(char*);
 
		TGW tgw = (TGW)GetProcAddress(hm,"?TESTGetWstring@@YAPA_WPAD@Z");
		if (NULL != tgw) {
        wchar_t* w =tgw("12541fg风格和");
        MessageBoxW(0,w,L"1111",0); 
		    delete w;
		
		} else{
        log("NULL != tgw");
    
    }
	
	
	
	
	
		FreeLibrary(hm);
	}
 


} __except (1) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start NewOn_Start1

// CODE BLOCK BEGIN Step_Function  NQ__
// 主step函数，执行周期 5 ms
void step(void) { __try { // 周期 = 5 ms

} __except (1) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

