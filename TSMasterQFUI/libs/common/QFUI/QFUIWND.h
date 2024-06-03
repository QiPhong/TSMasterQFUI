#pragma once

#include <Windows.h>
#include<windowsx.h>

#include "QFtypes.h"



#include <thread>
#include<algorithm>

#include <string>



/**
 * ==============================================================================================================================
 * 奇风窗口和控件的基类
 * 创建时间：2023年11月13日
 *S
 *
 *
 *
 *
 * ==============================================================================================================================
*/



#if 1 //是否debug输出
#define DebugOut(...) printf(__VA_ARGS__)
#else
#define DebugOut(...) 
#endif



class QWND
{
protected:
public:
    inline HCURSOR SetCursor(HCURSOR hc);
    inline HCURSOR GetCursor();
    inline void LoadThisCtrlCursor();
    virtual void Refresh() {};


    /**
     * 第一个参数，要展示的dc。如果想展示在窗口上则是改窗口的dc，如果是内存dc也可
     * 第二个参数，这个控件或者窗口要展示的大小或者位置
    */

    /**
     * 参数一，要展示的dc。如果想展示在窗口上则是改窗口的dc，如果是内存dc也可
     * 参数二，展示位置x坐标
     * 参数三，展示位置y坐标
     * 参数四，展示宽度
     * 参数五，展示高度
    */



    virtual int Draw(HDC sdc = NULL)=0;                                    //绘制到指定DC
    virtual void Reconstruct(HDC sdc, const QRect& rect)=0;                         //重新创建
    virtual void Reconstruct(HDC sdc)=0;                                          //重新创建
    virtual void SetLocation(const QPoint& point)=0;                               //设置位置
    virtual void SetSize(const QSize& size, HDC dc = NULL)=0;                         //设置大小(会重新构建控件)
    //是否包含某点
    virtual BOOL Contains(IN INT x,IN INT y)const=0 ;
    virtual BOOL Contains(IN const QPoint& pt) const=0;
    virtual BOOL Contains(IN QRect& rect)const=0 ;
    virtual void Redraw() {};

    ///////////////////////////////////////////////////////////////////////////
    //消息处理
        //鼠标左右键回复控制,
#define QFUI_CTRL_CAPTURE_MOUSE 1 //在鼠标按下的事件返回这个值能捕获鼠标，前提是没有控件在捕获
#define QFUI_CTRL_ACQUIRE_KEYBOARD 2 //在鼠标按下的事件返回这个值能获得键盘焦点



    virtual int MsgHandle(UINT uMsg, WPARAM wParam, LPARAM lParam)=0;//原始消息

    virtual int LButtonDown(int x, int y, WPARAM wParam)=0;//鼠标左键按下消息，
    virtual int LButtonDBLClick(int x, int y, WPARAM wParam)=0;//鼠标左键弹起消息，
    virtual int LButtonUp(int x, int y, WPARAM wParam)=0;//鼠标左键双击消息，

    virtual int RButtonDown(int x, int y, WPARAM wParam)=0;//鼠标右键按下消息，
    virtual int RButtonUp(int x, int y, WPARAM wParam)=0;//鼠标右键弹起消息，
    virtual int RButtonDBLClick(int x, int y, WPARAM wParam)=0;//鼠标右键双击消息，

    virtual int MButtonDown(int x, int y, WPARAM wParam)=0;//鼠标中键按下消息，
    virtual int MButtonUp(int x, int y, WPARAM wParam)=0;//鼠标中键弹起消息，
    virtual int MButtonDBLClick(int x, int y, WPARAM wParam)=0;//鼠标中键双击消息，
    virtual int MouseWheel(int x, int y, WPARAM wParam)=0;//鼠标滚轮转到

    virtual int MouseMove(int x, int y, WPARAM wParam)=0;//鼠标移动消息

    virtual int KeyChar(WPARAM wParam, LPARAM lParam)=0;//键盘键入一个字符
    virtual int KeyIMEChar(WPARAM wParam, LPARAM lParam)=0;//输入法发送一个字符过来
    virtual int KeyDown(WPARAM wParam, LPARAM lParam)=0;//键盘按下某键
    virtual int KeyUp(WPARAM wParam, LPARAM lParam)=0;//键盘弹起某键


    ///////////////////////////////////////////////////////////////////////////
    //失去焦点
    virtual void killFocus() {};


    QRect GetRect();

private:
    //创建自己的DC
    inline HDC QCreateDC(HDC winddc);
    //释放DC
    inline void ReleaseDC();



};


    











