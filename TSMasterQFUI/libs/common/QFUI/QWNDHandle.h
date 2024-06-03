#pragma once

#define DLL_EXPORTS
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

/**
 * ==========================================================================================================================================================
 * 文件说明：       |   窗口处理函数头文件，主要从panel窗口接管窗口过程，根据panel窗口名称决定那个窗口，名称相同的默认第一个
 * ----------------+-----------------------------------------------------------------------------------------------------------------------------------------
 * 创建时间：       |   2023年11月17日
 * ----------------+-----------------------------------------------------------------------------------------------------------------------------------------
 * 备注：           |   只能TSMaster中使用
 * ==========================================================================================================================================================
*/



#define __START_TSMASTER

#include <windows.h>
#include <windowsx.h>
#include "DLLImportQWND.h"
#include <mutex>
#include<memory>
#include "QWMange.h"
#ifdef __START_TSMASTER



#include "__TSMasterHander.h"
#endif
#include <set>
#include "QFReportForm.h"
#include "QFPictureBox.h"
#include "QFEdit.h"


/**
*新的过程函数
*
*
*
*
*/

class AgentWndImport
{
    protected:
        LRESULT OldLongWinProck = NULL;
        LRESULT OldLongWinProc = NULL;
        LRESULT OldPanelProc = NULL;
        HWND hWndk = NULL;  //父窗口的句柄，因为按键消息都跑父窗口去了
        HWND hWnd = NULL;   //绘图窗口的句柄
        HWND hWin = NULL;   //panel的句柄
    public:
        DLLImportQWND* pwnd = NULL;

        bool isEraseBK = false;//是否擦除背景
        bool isDefaultPaintBK = false;//是否使用默认绘制背景

    public:
        virtual BOOL BindPanel(HWND tsMw, const char* wName, LONG WndProc)=0;
        virtual HWND GetPanelHWND() = 0;

    
        virtual LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

    public:
        virtual void UnBind() = 0;
        virtual DLLImportQWND* BindQwnd(DLLImportQWND* qw) = 0;

    


        virtual void test() = 0;
        virtual void test2(const char*name) = 0;
        virtual int test3() = 0;
        virtual int test4(std::string& str) = 0;
        virtual int __stdcall test5(std::string str) = 0;
        virtual int test6(int i) = 0;

};
typedef  AgentWndImport* (__stdcall*CreaterAW)();
typedef LONG (__stdcall*GETPANELPRO)(int );
typedef LONG (__stdcall*SETPANELPRO)(int,LONG);
typedef int  (*GETPANELH)(int&, const char* wName, int& , int& );
class  AgentWndDLL
{
    private:
     // 唯一单实例对象指针
    static AgentWndDLL* Instance;
    static std::mutex m_Mutex;
    
    HMODULE m_hm= NULL;
    AgentWndDLL(const char* path);
    private:
    
    AgentWndDLL(const AgentWndDLL& aw)=delete;
    const AgentWndDLL &operator=(const AgentWndDLL &signal)=delete;
    public:
    static AgentWndDLL * GetInstance(const char* path = NULL);
    AgentWndImport* m_awi=NULL;
    ~AgentWndDLL();
    int BindPanel(const char* wName);
    int BindPanel(HWND mainHwnd);
    QWND* BindQwnd(DLLImportQWND* qwnd);
    QWMange* CreateQWMange();//创建窗口管理
    QWND*CreateQWND(const char* name,HDC dc,const QRect& rf);   //创建控件
    //创建画刷
    QBrush* CreateSolidBrush(unsigned char A,unsigned char R,unsigned char G,unsigned char B);
    QBrush* CreateLinearGradientBrush(float x1,float y1,unsigned char A1, unsigned char R1, unsigned char G1, unsigned char B1
    , float x2, float y2, unsigned char A2, unsigned char R2, unsigned char G2, unsigned char B2);
    void QDeleteBrush(QBrush* brush);
    QBrush* CreateTextureBrush(const wchar_t* path);

    void PreventScreenshot();//开启截图保护
    void AllowScreenshot();//关闭截图保护

};

AgentWndDLL *AgentWndDLL::Instance = NULL;
std::mutex AgentWndDLL::m_Mutex;
namespace QWNDHANDLE{
    LONG OldLongWinProck = NULL;
    LONG OldLongWinProc = NULL;
    LONG OldPanelProc = NULL;
    int hWndk = NULL;  
    int hWnd = NULL;   
    int hWin = NULL;   

    bool isEraseBK = false;
    bool isDefaultPaintBK = false;
    HDC wdc=NULL;
    DLLImportQWND* qwm =NULL;
    std::set<QWND*> QWNDs;      //保存创建的控件


}

LRESULT PanelWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int hd = (int)hwnd;
    DLLImportQWND* pwnd = QWNDHANDLE::qwm;
    if(hd != QWNDHANDLE::hWin){
            
            if(pwnd){
                int ret = pwnd->MsgHandle(uMsg,wParam,lParam);
                switch(ret){
                    case 1:
                    return TRUE;
                    case 2:
                    return DefWindowProc(hwnd, uMsg, wParam, lParam);
                }
            }
            if(!QWNDHANDLE::isEraseBK && WM_ERASEBKGND == uMsg)return DefWindowProc(hwnd, uMsg, wParam, lParam);
            if(!QWNDHANDLE::isDefaultPaintBK && WM_PAINT == uMsg)return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    else{
        switch(uMsg){
            case WM_SIZE:
                if(pwnd){
                    int ret = pwnd->MsgHandle(uMsg,wParam,lParam);
                    switch(ret){
                        case 1:
                        return TRUE;
                        case 2:
                        return DefWindowProc(hwnd, uMsg, wParam, lParam);
                        
                    }
                }
            break;

        }

    }

    LONG wp= QWNDHANDLE::OldLongWinProc;
    if(hd == QWNDHANDLE::hWndk){
        wp= QWNDHANDLE::OldLongWinProck;   
    }
    else if(hd == QWNDHANDLE::hWin){
        wp= QWNDHANDLE::OldPanelProc;  
    }
    if(!wp)return 1;
#ifndef STRICT

        return(CallWindowProcA((FARPROC)wp, hwnd, uMsg, wParam, lParam));
#else
        return(CallWindowProcA((WNDPROC)wp, hwnd, uMsg, wParam, lParam));
#endif 




}
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int hd = (int)hwnd;
    DLLImportQWND* pwnd = QWNDHANDLE::qwm;



    if (pwnd) {
        int ret = pwnd->MsgHandle(uMsg, wParam, lParam);
        switch (ret) {
        case 1:
            return TRUE;
        case 2:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);

        }
    }

    



    LONG wp = QWNDHANDLE::OldLongWinProc;
    
    if (!wp)return 1;
#ifndef STRICT

    return(CallWindowProcA((FARPROC)wp, hwnd, uMsg, wParam, lParam));
#else
    return(CallWindowProcA((WNDPROC)wp, hwnd, uMsg, wParam, lParam));
#endif 




}

template<class T>
class __AgentWndPtrMangement
{
    bool isFree = false;
    public:

    T* ptr=NULL;
    __AgentWndPtrMangement() { isFree = false; }
    ~__AgentWndPtrMangement(){
        if (!isFree) {
            if (NULL != ptr) {

                delete ptr;
            }
            isFree = true;
        }
    }


};
namespace __Mangement{

    __AgentWndPtrMangement<AgentWndDLL> awpm;

}
AgentWndDLL::AgentWndDLL(const char* path)
{
 
    m_hm = LoadLibraryA(path);
    if(!m_hm)DebugOut("加载DLL失败");

}

AgentWndDLL::~AgentWndDLL()
{
   DebugOut("~AgentWndDLL()");
    if(m_hm){
       DebugOut("~AgentWndDLL()   m_hm");
        SETPANELPRO sp = (SETPANELPRO)GetProcAddress(m_hm,"HookPanelPro");
        if(NULL != sp){
            
            //sp(QWNDHANDLE::hWndk,(LONG)PanelWndProc);
            //sp(QWNDHANDLE::hWnd,(LONG)PanelWndProc);
            //sp(QWNDHANDLE::hWin,(LONG)PanelWndProc);

            if(QWNDHANDLE::hWin){
                if(QWNDHANDLE::OldPanelProc){
                    sp(QWNDHANDLE::hWin,
                    QWNDHANDLE::OldPanelProc);
                
                }
            QWNDHANDLE::hWin=NULL;

            }
       
            if(QWNDHANDLE::hWndk){
                if(QWNDHANDLE::OldLongWinProck){
                    sp(QWNDHANDLE::hWndk,
                        QWNDHANDLE::OldLongWinProck);
                }

                QWNDHANDLE::hWndk=NULL;
            }
            if(QWNDHANDLE::hWnd){
                if(QWNDHANDLE::OldLongWinProc){
                    sp(QWNDHANDLE::hWnd,
                        QWNDHANDLE::OldLongWinProc);
                }

                QWNDHANDLE::hWnd=NULL;
            }
        }
        typedef void(__stdcall *DestroyAWnd)(int);
        DestroyAWnd daw = (DestroyAWnd)GetProcAddress(m_hm, "DestroyAgentWnd");
        if (m_awi && daw) {
            daw((int)m_awi);
        }
        
    }
   // if(m_awi){
    //   DebugOut("~AgentWndDLL()   m_awi");
   //     delete m_awi;
   //    DebugOut("~AgentWndDLL()   m_awi After");
   // }
    DebugOut("~AgentWndDLL()  QWNDHANDLE::qwm  before");
    if(QWNDHANDLE::qwm)delete QWNDHANDLE::qwm;
    DebugOut("~AgentWndDLL()  QWNDHANDLE::qwm  After");
    //处理控件
    for(auto it : QWNDHANDLE::QWNDs){
        delete it;
    }


    if(QWNDHANDLE::wdc)ReleaseDC(0, QWNDHANDLE::wdc);
    if(m_hm){
        DebugOut("~AgentWndDLL()  FreeLibrary");
        FreeLibrary(m_hm);
        m_hm = NULL;
    }

}
AgentWndDLL * AgentWndDLL::GetInstance(const char* path)
{
    if (Instance == nullptr) 
    {
        if(NULL == path){
            DebugOut("AgentWndDLL::GetInstance: 失败，请传入DLL路径");
            return NULL;
        }
        std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
        if (Instance == nullptr)
        {
            volatile auto temp = new (std::nothrow) AgentWndDLL(path);
            Instance = temp;
            __Mangement::awpm.ptr=Instance;
            
        }
    }

    return Instance;
  
}

int AgentWndDLL::BindPanel(const char* wName)
{
#ifdef __START_TSMASTER
    if(m_hm){
        static CreaterAW caw = (CreaterAW)GetProcAddress(m_hm,"CreaterAgentWnd");
        if(NULL == caw)return 2;
        typedef BOOL __stdcall (*BINDPANEL)(AgentWndImport*,HWND , const char* , LONG );
        m_awi = caw();
        if(NULL == m_awi)return 3;
        GETPANELH gph = (GETPANELH)GetProcAddress(m_hm,"GetPanelHandle");
        if(NULL == gph)return 4;
        s32 h;
        app.get_main_window_handle(&h);
        QWNDHANDLE::hWnd = gph(h,wName,QWNDHANDLE::hWndk, QWNDHANDLE::hWin);

        if(NULL == QWNDHANDLE::hWnd){
            DebugOut("绑定panel失败5");
            return 5;
        }


        GETPANELPRO gp = (GETPANELPRO)GetProcAddress(m_hm,"GetPanelPro");
        if(NULL == gp)return 6;
        QWNDHANDLE::OldLongWinProck = gp(QWNDHANDLE::hWndk);
        QWNDHANDLE::OldLongWinProc = gp(QWNDHANDLE::hWnd);
        QWNDHANDLE::OldPanelProc = gp(QWNDHANDLE::hWin);
        

        SETPANELPRO sp = (SETPANELPRO)GetProcAddress(m_hm,"HookPanelPro");
        if(NULL == sp)return 7;
       
        sp(QWNDHANDLE::hWndk,(LONG)PanelWndProc);
        sp(QWNDHANDLE::hWnd,(LONG)PanelWndProc);
        sp(QWNDHANDLE::hWin,(LONG)PanelWndProc);
        
        return 1;
    }else return 0;
 
#else

#endif

    return 0;
}
int AgentWndDLL::BindPanel(HWND mainHwnd)
{
    if (m_hm) {
        static CreaterAW caw = (CreaterAW)GetProcAddress(m_hm, "CreaterAgentWnd");
        if (NULL == caw)return 2;
        m_awi = caw();
        if (NULL == m_awi)return 3;

        QWNDHANDLE::hWnd = (int)mainHwnd;

        GETPANELPRO gp = (GETPANELPRO)GetProcAddress(m_hm, "GetPanelPro");
        if (NULL == gp)return 6;
        QWNDHANDLE::OldLongWinProc = gp(QWNDHANDLE::hWnd);
  


        SETPANELPRO sp = (SETPANELPRO)GetProcAddress(m_hm, "HookPanelPro");
        if (NULL == sp)return 7;
        sp(QWNDHANDLE::hWnd, (LONG)WndProc);


        return 1;
    }
    else return 0;

}

QWMange* AgentWndDLL::CreateQWMange()
{
    if(QWNDHANDLE::qwm)return (QWMange*)QWNDHANDLE::qwm;

    if(m_hm){
        typedef QWND* (*CQWDM)(HDC winddc, QRect  rf);
        CQWDM cqwdm = (CQWDM)GetProcAddress(m_hm,"CreateQWMange");
        
        HWND hwnd=HWND(QWNDHANDLE::hWnd);
        QWNDHANDLE::wdc = GetDC(hwnd);
        RECT rect;
        GetWindowRect(hwnd,&rect);
        QWND*p = cqwdm(QWNDHANDLE::wdc ,QRect(0,0,rect.right-rect.left,rect.bottom-rect.top));
        QWNDHANDLE::qwm = new QWMange(QWNDHANDLE::wdc ,QRect(0,0,rect.right-rect.left,rect.bottom-rect.top));

        QWMange* pm =(QWMange*)QWNDHANDLE::qwm;
        

        pm->qwm = p;
        pm->init(m_hm);
        pm->SetHostHand(hwnd);
        return pm;
        return NULL;
    }


    return NULL;
}
#include "QFProgressBarCar.h"
#include "QFButton.h"
#include "QFLineChart.h"
#include "QFTabs.h"
QWND* AgentWndDLL::CreateQWND(const char* name,HDC dc,const QRect& rf)
{

    if(m_hm){
        typedef QWND* (*CQWND)(const char*,HDC , QRect  );
        CQWND cwnd = (CQWND)GetProcAddress(m_hm,"CreateQWND");
        if(NULL == cwnd){
            DebugOut("AgentWndDLL::CreateQWND ：由于函数 <CreateQWND> 地址找不到，创建控件失败！ ");
            return NULL;
        }
        
        HWND hwnd=HWND(QWNDHANDLE::hWnd);
        if(NULL == QWNDHANDLE::wdc)
            QWNDHANDLE::wdc = GetDC(hwnd);

        DLLImportQWND*dq = NULL;
        if ("QFButton" == std::string(name)) {
            dq = new QButton(QWNDHANDLE::wdc ,rf);

        }
        else if ("QFStaticText" == std::string(name)) {
            

        }
        else if ("QFReportForm" == std::string(name)) {
            dq = new QReportForm(QWNDHANDLE::wdc ,rf);
        }
        else if ("QFPictureBox" == std::string(name)) {
            dq = new QPictureBox(QWNDHANDLE::wdc ,rf);
        }
        else if ("QFEdit" == std::string(name)) {
            dq = new QEdit(QWNDHANDLE::wdc ,rf);
        }
        else if ("QFPanelDial" == std::string(name)) {

        }
        else if ("QFProgressBarCar" == std::string(name)) {
            dq = new QProgressBarCar(QWNDHANDLE::wdc ,rf);
        }
        else if ("QFLineChart" == std::string(name)) {
            dq = new QLineChart(QWNDHANDLE::wdc, rf);
        }
        else if ("QFTabs" == std::string(name)) {
            dq = new QTabs(QWNDHANDLE::wdc, rf);
        }

        if(NULL == dq){
            DebugOut("AgentWndDLL::CreateQWND ：创建控件失败,可能 《%s》控件不支持的类型 ",name);
            return NULL;
        }
 
        QWND*p = cwnd(name,QWNDHANDLE::wdc ,rf);
        if(NULL == p){
            DebugOut("AgentWndDLL::CreateQWND ：创建控件失败,可能 《%s》控件不存在 ",name);
            return NULL;
        }
 
        dq->qwm = p;
        dq->init(m_hm);
        QWNDHANDLE::QWNDs.insert(dq);
        return dq;
    }

    DebugOut("AgentWndDLL::CreateQWND ：由于 <QFUI> DLL的模块句柄为0，创建控件失败！ ");
    return NULL;
}


QWND* AgentWndDLL::BindQwnd(DLLImportQWND* qwnd)
{
    QWND* ret = QWNDHANDLE::qwm;
    qwnd->SetHostHand((HWND)QWNDHANDLE::hWnd);
    QWNDHANDLE::qwm=qwnd;
    return ret;


}

QBrush* AgentWndDLL::CreateSolidBrush(unsigned char A,unsigned char R,unsigned char G,unsigned char B)
{
    typedef QBrush*(*CREATESOLIDBRUSH)(unsigned char A,unsigned char R,unsigned char G,unsigned char B);
    if(m_hm){
        CREATESOLIDBRUSH cs = (CREATESOLIDBRUSH)GetProcAddress(m_hm,"?QCreateSolidBrush@@YAPAVBrush@Gdiplus@@EEEE@Z");
        if(NULL == cs){
            DebugOut("AgentWndDLL::CreateSolidBrush ：由于函数 <CreateSolidBrush> 地址找不到，创建画刷失败！ ");
            return NULL;
        }
        return cs(A,R,G,B);
    
    }
    DebugOut("AgentWndDLL::CreateSolidBrush ：由于 <QFUI> DLL的模块句柄为0，创建控件失败！ ");
    return NULL;
}
QBrush* AgentWndDLL::CreateLinearGradientBrush(float x1,float y1,unsigned char A1, unsigned char R1, unsigned char G1, unsigned char B1
, float x2, float y2, unsigned char A2, unsigned char R2, unsigned char G2, unsigned char B2)
{
    typedef QBrush*(*CREATELINEARGRADIENTBRUSH)(float x1,float y1,unsigned char A1, unsigned char R1, unsigned char G1, unsigned char B1
    , float x2, float y2, unsigned char A2, unsigned char R2, unsigned char G2, unsigned char B2);
    if(m_hm){
        CREATELINEARGRADIENTBRUSH cLs = (CREATELINEARGRADIENTBRUSH)GetProcAddress(m_hm,"?QCreateLinearGradientBrush@@YAPAVBrush@Gdiplus@@MMEEEEMMEEEE@Z");
        if(NULL == cLs){
            DebugOut("AgentWndDLL::CreateLinearGradientBrush ：由于函数 <CreateLinearGradientBrush> 地址找不到，创建画刷失败！ ");
            return NULL;
        }
        return cLs(x1,y1,A1,R1,G1,B1,x2,y2,A2,R2,G2,B2);
    
    }
    DebugOut("AgentWndDLL::CreateLinearGradientBrush ：由于 <QFUI> DLL的模块句柄为0，创建控件失败！ ");
    return NULL;
}
void AgentWndDLL::QDeleteBrush(QBrush* brush)
{
    typedef void(*DELETEBRUSH)(QBrush*);
    if(m_hm){
       DELETEBRUSH ds = (DELETEBRUSH)GetProcAddress(m_hm,"?QDeleteBrush@@YAXPAVBrush@Gdiplus@@@Z");
        if(NULL == ds){
            DebugOut("AgentWndDLL::QDeleteBrush ：由于函数 <DeleteBrush> 地址找不到，删除画刷失败！ ");
        } 
        return ds(brush);

    }
    DebugOut("AgentWndDLL::QDeleteBrush ：由于 <QFUI> DLL的模块句柄为0，删除画刷失败 ");
}

QBrush* AgentWndDLL::CreateTextureBrush(const wchar_t* path)
{
    typedef QBrush*(*CREATETEXTUREBRUSH)(const wchar_t*);
    if(m_hm){
        CREATETEXTUREBRUSH ct = (CREATETEXTUREBRUSH)GetProcAddress(m_hm,"?QCreateTextureBrush@@YAPAVBrush@Gdiplus@@PB_W@Z");
        if(NULL == ct){
            DebugOut("AgentWndDLL::CreateTextureBrush ：由于函数 <CreateTextureBrush> 地址找不到，创建画刷失败！ ");
            return NULL;
        }
        return ct(path);
    
    }
    DebugOut("AgentWndDLL::CreateTextureBrush ：由于 <QFUI> DLL的模块句柄为0，创建控件失败！ ");
    return NULL;
}
void AgentWndDLL::PreventScreenshot()
{
#ifdef __START_TSMASTER
    typedef void(*PREVENTSCREENSHOT)(HWND);
    if(m_hm){
        PREVENTSCREENSHOT ps = (PREVENTSCREENSHOT)GetProcAddress(m_hm,"PreventScreenshot");
        if(NULL == ps){
            DebugOut("AgentWndDLL::PreventScreenshot ：由于函数 <PreventScreenshot> 地址找不到，开启截图保护失败！");
            return ;
        }
        int hwnd =0;
        app.get_main_window_handle(&hwnd);
        ps(HWND(hwnd));
    
    }
    DebugOut("AgentWndDLL::PreventScreenshot ：由于 <QFUI> DLL的模块句柄为0，开启截图保护失败！");
#else
#endif
}
void AgentWndDLL::AllowScreenshot()
{
#ifdef __START_TSMASTER
    typedef void(*ALLOWSCREENSHOT)(HWND);
    if(m_hm){
        ALLOWSCREENSHOT as = (ALLOWSCREENSHOT)GetProcAddress(m_hm,"AllowScreenshot");
        if(NULL == as){
            DebugOut("AgentWndDLL::PreventScreenshot ：由于函数 <PreventScreenshot> 地址找不到，关闭截图保护失败！");
            return ;
        }
        int hwnd =0;
        app.get_main_window_handle(&hwnd);
        as(HWND(hwnd));
    
    }
    DebugOut("AgentWndDLL::PreventScreenshot ：由于 <QFUI> DLL的模块句柄为0，关闭截图保护失败！");
#else

#endif

}

