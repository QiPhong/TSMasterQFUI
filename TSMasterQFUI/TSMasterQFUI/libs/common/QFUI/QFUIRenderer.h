/*
 *============================================================================================================
 * 文件说明：       |   奇风UI绘制管理
 * ----------------+------------------------------------------------------------------------------------------
 * 创建时间：       |   2023年12月11日
 * ----------------+------------------------------------------------------------------------------------------
 * 备注：           |   负责QWMange的绘制
 * ===========================================================================================================
*/




#ifndef __QFUIRENDERER_H
#define __QFUIRENDERER_H

#define DrawCyc_us 500
#include <functional>
#include <windows.h>
#include <windowsx.h>
#include <mutex>
#include<memory>
#include "QFUIWND.h"
#include "QWMange.h"
#include "QWNDHandle.h"
#include "QFObjPtrMange.h"
#include <thread>


//用户接口
namespace QFUSE{

    /**
     * ###################################################################
     * 函数名：BindPanelWindow
     * 作用：初始化和绑定panel
     * 参数1：panel窗口的名字
     * 返回值:返回1为正常，返回0为窗口管理或者渲染器的指针为空，返回4为找不到指定名字的panel
     * ###################################################################
    */
    int BindPanelWindow(const char* panelName);
    int BindPanelWindow(HWND hwnd);
    /**
     * ###################################################################
     * 函数名：UnBindPanelWindow
     * 作用：解除绑定panel窗口
     * 返回值:返回1为正常
     * ###################################################################
    */
    void UnBindPanelWindow();
        /**
     * ###################################################################
     * 函数名：GetPanelDC
     * 作用：取得绑定的panel的DC
     * 返回值:panel的DC
     * ##################################################################
    */
    HDC GetPanelDC();
    /**
     * ###################################################################
     * 函数名：AttachCtrl
     * 作用：关联(添加)一个控件到panel中
     * 参数1： 控件指针
     * 返回值:无
     * ##################################################################
    */
    void AttachCtrl(QWND* qw);

    /**
     * ###################################################################
     * 函数名：GetQWManger
     * 作用：获取窗口管理者指针
     * ###################################################################
    */
    QWND* GetQWManger();

}

class QRenderer
{
    public:
    static QRenderer * GetInstance();
    ~QRenderer();
    int startDraw();//返回1启动成功，返回2已经启动了，返回0为其他错误,3为setWindow未调用或者窗口不存在
    void setWindow(HWND hw);
    void __del();
    inline HDC getDC(){return __dc;};
    inline void AttachCtrl(QWND* qw){pqwm->AttachCtrl(qw);}
    inline void RemoveCtrl(QWND* qw){pqwm->RemoveCtrl(qw);}
    QWMange* GetQWManger(){return pqwm;}

    private:
    static QRenderer * Instance ;
    static std::mutex m_QRMutex;
    //拷贝复制都不存在
    QRenderer(const QRenderer& aw)=delete;
    const QRenderer &operator=(const QRenderer &signal)=delete;
    QRenderer();
    QWMange* pqwm = NULL;

    //**********************************************************************************绘制线程相关
    bool __threadIsrun=false;
    std::thread __qrThread;
    void __Draw();
    //**********************************************************************************
    //**********************************************************************************绘制属性
    HWND __hwnd =NULL;//绘制窗口句柄
    HDC __dc = NULL;//输出的DC
    RECT __rect ;//初始的窗口大小
    //**********************************************************************************
    friend int QFUSE::BindPanelWindow(const char* panelName);
    friend int QFUSE::BindPanelWindow(HWND hwnd);


} ;


//******************************.CPP file***********************************************
QRenderer* QRenderer::Instance = NULL;
std::mutex QRenderer::m_QRMutex;


QRenderer::QRenderer()
{
   


}



QRenderer * QRenderer::GetInstance()
{
    if (Instance == nullptr) 
    {
        std::unique_lock<std::mutex> lock(m_QRMutex); // 加锁
        if (Instance == nullptr)
        {
            volatile auto temp = new (std::nothrow) QRenderer();
            Instance = temp;
            // __Mangement::qrpm.setMange(temp,&QRenderer::__del);
        }
    }

    return Instance;
  
}

void QRenderer::__del()
{

    __threadIsrun =false;

    DebugOut("void QRenderer::__del()");
    if(__qrThread.joinable())
        __qrThread.join();
    // if(pqwm->qwm)
    //     delete pqwm->qwm;
   
    DebugOut("void QRenderer::__del() delete pqwm;");
    ReleaseDC(0, __dc);


}

QRenderer::~QRenderer()
{
    // __del();
    
}
int QRenderer::startDraw()
{
    if(!pqwm)return 3;
    if(__threadIsrun)return 2;
    __threadIsrun = true;
    std::thread t(&QRenderer::__Draw,this);
    
    __qrThread = std::move(t);

    return 1;

}

void QRenderer::__Draw()
{
    
    while(__threadIsrun){
        pqwm->Draw(__dc);
        std::this_thread::sleep_for(std::chrono::microseconds(DrawCyc_us));
        
    }
    
   
}

void QRenderer::setWindow(HWND hw)
{
    
    __hwnd = hw;
    __dc = GetDC(hw);
    GetWindowRect(hw,&__rect);

    if(__threadIsrun)return;
    if(pqwm) delete pqwm;
    int width = __rect.right-__rect.left;
    int height = __rect.bottom - __rect.top;

    pqwm = new QWMange(__dc,QRect(0,0,width,height));


}

namespace QFUSE{

    /**
     * ###################################################################
     * 函数名：BindPanelWindow
     * 作用：初始化和绑定panel
     * 参数1：panel窗口的名字
     * 返回值:返回1为正常，返回0为窗口管理或者渲染器的指针为空，返回4为找不到指定名字的panel
     * ###################################################################
    */
    int BindPanelWindow(const char* panelName)
    {
#ifdef __START_TSMASTER



        char* pPath=NULL;
        app.get_configuration_file_path(&pPath);
        std::string strPath(pPath);
        strPath+="libs\\common\\QFUI\\QWNDHandle.dll";
        #ifdef __QFUIDLL_PATH
        // strPath="C:\\Users\\Administrator\\Desktop\\QFUI\\Release\\QWNDHandle.dll";
            strPath = __QFUIDLL_PATH;
        #endif
        AgentWndDLL* p=  AgentWndDLL::GetInstance(strPath.c_str());

        if(p){
       
            
            QRenderer * pqr =QRenderer::GetInstance();
            if(pqr){
                // app.ui_show_window(const_cast<char*>(panelName), true);
                
                int res=p->BindPanel(panelName);
                if(5 == res &&  NULL != QWNDHANDLE::hWin){
                    app.ui_show_window(const_cast<char*>(panelName), true);
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                    res=p->BindPanel(panelName);
                    // std::this_thread::sleep_for(std::chrono::microseconds(3000));
                    app.ui_show_window(const_cast<char*>(panelName), false);

                }
                
                if(1 == res){    
                    HWND hwnd= HWND(QWNDHANDLE::hWnd);
                    if(NULL == hwnd){
                        return 5;
                    }  
                        
                    pqr->setWindow(hwnd);
                    pqr->pqwm = p->CreateQWMange();
                    p->BindQwnd(pqr->pqwm);
                    int ret = pqr->startDraw();
                    return ret;
                }
                else return 4;
            }else return 0;

        }
        else return 0;
#endif 
        return 0;
    }

    int BindPanelWindow(HWND hwnd)
    {



        std::string strPath = "QWNDHandle.dll";
#ifdef __QFUIDLL_PATH
        // strPath="C:\\Users\\Administrator\\Desktop\\QFUI\\Release\\QWNDHandle.dll";
        strPath = __QFUIDLL_PATH;
#endif
        AgentWndDLL* p = AgentWndDLL::GetInstance(strPath.c_str());

        if (p) {

            QRenderer* pqr = QRenderer::GetInstance();
            if (pqr) {
                // app.ui_show_window(const_cast<char*>(panelName), true);

                int res = p->BindPanel(hwnd);


                if (1 == res) {

                    pqr->setWindow(hwnd);
                    pqr->pqwm = p->CreateQWMange();
                    
                    p->BindQwnd(pqr->pqwm);
                    int ret = pqr->startDraw();
                    return ret;
                }
                else return 4;
            }
            else return 0;

        }
        else return 0;

        return 0;
    }



    /**
     * ###################################################################
     * 函数名：UnBindPanelWindow
     * 作用：解除绑定panel窗口
     * 返回值:返回1为正常
     * ###################################################################
    */

    void UnBindPanelWindow()
    {
      
        QRenderer * pqr =QRenderer::GetInstance();

        if(pqr){
            pqr->__del();
        }
	
#ifndef __START_TSMASTER
        __Mangement::awpm.~__AgentWndPtrMangement();

#endif

    }

    /**
     * ###################################################################
     * 函数名：GetPanelDC
     * 作用：取得绑定的panel的DC
     * 返回值:panel的DC
     * ##################################################################
    */
    HDC GetPanelDC()
    {
        QRenderer * pqr =QRenderer::GetInstance();
        if(pqr){
            return pqr->getDC();
        }
        return NULL;
    }

    /**
     * ###################################################################
     * 函数名：AttachCtrl
     * 作用：关联(添加)一个控件到panel中
     * 参数1： 控件指针
     * 返回值:无
     * ##################################################################
    */
    void AttachCtrl(QWND* qw)
    {
        DLLImportQWND* diq = (DLLImportQWND*)qw;
        QRenderer * pqr =QRenderer::GetInstance();
        if(pqr){
            pqr->AttachCtrl(diq->qwm);
        }
    }
    /**
     * ###################################################################
     * 函数名：RemoveCtrl
     * 作用：从到panel中取消关联(移除)一个控件
     * 参数1： 控件指针
     * 返回值:无
     * ##################################################################
    */
    void RemoveCtrl(QWND* qw)
    {
        DLLImportQWND* diq = (DLLImportQWND*)qw;
        QRenderer * pqr =QRenderer::GetInstance();
        if(pqr){
            pqr->RemoveCtrl(diq->qwm);
        }
    }


    QWND* CreateQWND(const char* name,const QRect& rf)
    {
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            QRenderer * pqr =QRenderer::GetInstance();
            HDC dc =NULL;
            if(pqr){
                dc = pqr->getDC();
            }
            if(NULL == dc){
                DebugOut("QFUSE::CreateQWND,失败，因为窗口上下文场景指针为空");
                return NULL;
            }
            return p->CreateQWND(name,dc,rf);
        }


        return NULL;
    }

    QWND* GetQWManger()
    {
        QRenderer * pqr =QRenderer::GetInstance();
        if(pqr){
            return pqr->GetQWManger();
        }
        return NULL;

    }

    QBrush*CreateSolidBrush(unsigned char A,unsigned char R,unsigned char G,unsigned char B)
    {
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            return p->CreateSolidBrush(A,R,G,B);
        }
        return NULL;
    }
    QBrush*CreateTextureBrush(const wchar_t* path)
    {
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            return p->CreateTextureBrush(path);
        }
        return NULL;
    }
    QBrush*CreateLinearGradientBrush(float x1,float y1,unsigned char A1, unsigned char R1, unsigned char G1, unsigned char B1
    , float x2, float y2, unsigned char A2, unsigned char R2, unsigned char G2, unsigned char B2)
    {
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            return p->CreateLinearGradientBrush(x1,y1,A1,R1,G1,B1,x2,y2,A2,R2,G2,B2);
        }
        return NULL;
    }

    void QDeleteBrush(QBrush* brush)
    {
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            p->QDeleteBrush(brush);
        }

    }

    void QPreventScreenshot(){
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            p->PreventScreenshot();
        }

    }
    void QAllowScreenshot(){
        AgentWndDLL* p=  AgentWndDLL::GetInstance();
        if(p){
            p->AllowScreenshot();
        }

    }
}






































#endif