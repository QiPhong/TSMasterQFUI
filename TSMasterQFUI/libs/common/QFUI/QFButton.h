#ifndef __QFBUTTON_H
#define __QFBUTTON_H
#include "DLLImportQWND.h"
#include <windows.h>
#include <string>
#include "QFCtrlListener.H"


#define ____QFBUTTON_TYPEDEF
#ifdef ____QFBUTTON_TYPEDEF
#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __QDefineType(name) name##_Type
#define __MembersDef(name) __DefineFun(__QDefineType(name),name)
#define __FunTypeDef(fName) fName##_Type
#endif
typedef void (*__QFBSETTEXT)(QWND*,const wchar_t* );
typedef void (*__QFBSETFONTNAME)(QWND*,const wchar_t* );
typedef void (*__QFBSETFONTSIZE)(QWND*,int);
typedef void (*__QFBSETTEXTALGN)(QWND*,int);
typedef void (*__QFBSETTEXTALLGN)(QWND*,int);
typedef void (*__QFBSETCLICKEVENT)(QWND*,QFBUTTONCLICK);

typedef const wchar_t* (*__FunTypeDef(QFBGetText))(QWND*);

class QButton:public DLLImportQWND
{
    static HMODULE m_hm ;
    static __QFBSETTEXT QFBSetText;
    static __QFBSETFONTNAME QFBSetFontName;
    static __QFBSETFONTSIZE QFBSetFontSize;
    static __QFBSETTEXTALGN QFBSetTextAlgn;
    static __QFBSETTEXTALLGN QFBSetTextAllgn;
    static __QFBSETCLICKEVENT QFBSetClickEvent;
    __MembersDef(QFBGetText);

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
    std::wstring GetText();
    private:





};


#undef ____QFBUTTON_TYPEDEF
#endif