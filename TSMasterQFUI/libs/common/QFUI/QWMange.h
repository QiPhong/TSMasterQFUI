#ifndef __QWMANGE_H
#define __QWMANGE_H

#include "DLLImportQWND.h"
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "QFCtrlListener.h"





class QWMangeListener
{
protected:


public:
    QLSizeChangeListener* __sizeChangeListen = NULL;//改变前的
    QLSizeChangeListener* __sizeChangedListen = NULL;//改变之后的



};
struct QFMSG {
    QFMSG()
    {

    }
    QFMSG(HWND h, UINT m, WPARAM w, LPARAM l)
    {
        hwnd = h;
        msg = m;
        wParam = w;
        lParam = l;
    }
    HWND hwnd = HWND(0);
    UINT msg;
    WPARAM wParam;
    LPARAM lParam;


};
#define __QWMANGE_MSG_MAX   32

typedef void (*ADD_AND_DELETECTRL)(QWND*,QWND*);
typedef QBrush* (*GETBKBRUSH)(QWND*);
typedef QLSizeChangeListener* (*SETSIZECHANGELISTEN)(QWND*,QLSizeChangeListener*);
typedef int (*SETBKQWMBRUSH)(QWND*,QBrush*);
typedef int (*QWMSETBKIMAGE)(QWND*,wchar_t*);
typedef void (*QWMSETTRANSPARENCY)(QWND*,unsigned char);
typedef void (*QWMCLEARBKIMAGE)(QWND*);



class QWMange :public DLLImportQWND
{
    private:
    static HMODULE m_hm;
    static ADD_AND_DELETECTRL AttachCtrl_FUN;
    static ADD_AND_DELETECTRL RemoveCtrl_FUN;
    static GETBKBRUSH GetBKBrush_FUN;
    static SETSIZECHANGELISTEN SetSizeChangeListen_FUN; 
    static SETSIZECHANGELISTEN SetSizeChangedListen_FUN; 
    static SETBKQWMBRUSH SetBKBrush_FUN;
    static QWMSETBKIMAGE QWMSetBKImage;
    static QWMSETTRANSPARENCY QWMSetTransparency;
    static QWMCLEARBKIMAGE QWMClearBKImage;



    public:
    QWMange(HDC winddc, const QRect& rf):DLLImportQWND(winddc,rf){}
    public:
        void AttachCtrl(QWND* w){AttachCtrl_FUN(qwm,w);}       //关联一个控件
        void RemoveCtrl(QWND* w){RemoveCtrl_FUN(qwm,w);}      //移除一个控件
        QBrush* GetBKBrush(){return GetBKBrush_FUN(qwm);}
        int SetBKBrush(QBrush* brush){return SetBKBrush_FUN(qwm,brush);};

        QLSizeChangeListener* SetSizeChangeListen(QLSizeChangeListener* listen){return SetSizeChangeListen_FUN(qwm,listen);}        //设置窗口大小发生改变之前的监听器
        QLSizeChangeListener* SetSizeChangedListen(QLSizeChangeListener* listen){return SetSizeChangedListen_FUN(qwm,listen);}         //设置窗口大小发生改变之后的监听器
        virtual int init(HMODULE hm);
        int SetBKPicture(const wchar_t* path){ return QWMSetBKImage(qwm,const_cast<wchar_t*>(path));};//设置背景图片
        void SetBKPictureTransparency(unsigned char apha){ return QWMSetTransparency(qwm,apha);};//设置背景图片的
        void ClearBKPicture(){ return QWMClearBKImage(qwm);};//清除背景图片
};











#endif