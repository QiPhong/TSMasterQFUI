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
#include "QFProgressBarCar.h"
#include "QFButton.h"
#include "QFLineChart.h"
#include "QFTabs.h"
#include "QF3DCtrl.h"
#include "QFCATLCtrl.h"
#include "QFFrequentlyCtrl.h"

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


namespace QWNDHANDLE{
    extern LONG OldLongWinProck;
    extern LONG OldLongWinProc;
    extern LONG OldPanelProc;
    extern int hWndk;  
    extern int hWnd;   
    extern int hWin;   

    extern bool isEraseBK;
    extern bool isDefaultPaintBK;
    extern HDC wdc;
    extern DLLImportQWND* qwm;
    extern std::set<QWND*> QWNDs;      //保存创建的控件


}

LRESULT PanelWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

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

    extern __AgentWndPtrMangement<AgentWndDLL> awpm;

}

QPOINTER FindEventFun(const char* name);
int RegEventFun(const char* name, QPOINTER fun);


#define REGEVENTFUN(fun) RegEventFun(#fun,QPOINTER(fun))