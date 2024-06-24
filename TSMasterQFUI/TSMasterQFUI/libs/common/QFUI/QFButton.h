#ifndef __QFBUTTON_H
#define __QFBUTTON_H
#include "DLLImportQWND.h"
#include <windows.h>
#include <string>
#include "QFCtrlListener.H"


#define ____QFBUTTON_TYPEDEF
#ifdef ____QFBUTTON_TYPEDEF

#endif
typedef void (*__QFBSETTEXT)(QWND*,const wchar_t* );
typedef void (*__QFBSETFONTNAME)(QWND*,const wchar_t* );
typedef void (*__QFBSETFONTSIZE)(QWND*,int);
typedef void (*__QFBSETTEXTALGN)(QWND*,int);
typedef void (*__QFBSETTEXTALLGN)(QWND*,int);
typedef void (*__QFBSETCLICKEVENT)(QWND*,QFBUTTONCLICK);

class QButton:public DLLImportQWND
{
    static HMODULE m_hm ;
    static __QFBSETTEXT QFBSetText;
    static __QFBSETFONTNAME QFBSetFontName;
    static __QFBSETFONTSIZE QFBSetFontSize;
    static __QFBSETTEXTALGN QFBSetTextAlgn;
    static __QFBSETTEXTALLGN QFBSetTextAllgn;
    static __QFBSETCLICKEVENT QFBSetClickEvent;
    public:
    QButton(HDC winddc,const QRect& rf);
    virtual ~QButton();


    //按钮的属性设置
    void SetText(const wchar_t* t);
    void SetFontName(const wchar_t* name);
    void SetFontSize(INT size);
    void SetTextAlgn(unsigned int align);
    void SetTextAlgn(unsigned int align, unsigned int lalign);
    void SetTextAllgn(unsigned int lalign);
    virtual int init(HMODULE hm);
    void SetClickEvent(QFBUTTONCLICK fun);

    private:





};


#undef ____QFBUTTON_TYPEDEF
#endif