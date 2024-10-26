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
     * 函数名：RemoveCtrl
     * 作用：从到panel中取消关联(移除)一个控件
     * 参数1： 控件指针
     * 返回值:无
     * ##################################################################
    */
    void RemoveCtrl(QWND* qw);


    QWND* CreateQWND(const char* name,const QRect& rf);

    QWND* GetQWManger();

    QBrush*CreateSolidBrush(unsigned char A,unsigned char R,unsigned char G,unsigned char B);
    QBrush*CreateTextureBrush(const wchar_t* path);
    QBrush*CreateLinearGradientBrush(float x1,float y1,unsigned char A1, unsigned char R1, unsigned char G1, unsigned char B1
    , float x2, float y2, unsigned char A2, unsigned char R2, unsigned char G2, unsigned char B2);
    void QDeleteBrush(QBrush* brush);

    void QPreventScreenshot();
    void QAllowScreenshot();
    
     /**
     * ###################################################################
     * 函数名：GainLifeCyclePower
     * 作用：接管控件的生命周期，接管之后不需要是请进行delete，否则内存泄漏
     * 参数1： 控件指针
     * 返回值:无
     * ##################################################################
    */
    void GainLifeCyclePower(QWND* qw);

    /**
    * ###################################################################
    * 函数名：FindCtrl
    * 作用：查找指定名称的第一个控件
    * 参数1： 要查找的控件名称
    * 返回值:返回控件指针
    * ##################################################################
    */
    QWND* FindCtrl(const char* name);
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











































#endif