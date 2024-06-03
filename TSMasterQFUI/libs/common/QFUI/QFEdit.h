#ifndef __QFEDIT_H
#define __QFEDIT_H
#include <windows.h>
#include <string>
#include <locale>
#include <codecvt>
#include <chrono>
#include <thread>
#include "DLLImportQWND.h"

#define __QFEDIT_TYPEDEF
#ifdef __QFEDIT_TYPEDEF

#endif

typedef void (*QEDSETBKIMAGETRANSPARENCY)(QWND* ,unsigned char);
typedef void (*QEDLOADPICTURE)(QWND* , const wchar_t*);
typedef void (*QEDSETBKBRUSH)(QWND* , QBrush*);
typedef void (*QEDSETTEXT)(QWND*, const wchar_t*);
typedef void (*QEDSETTEXTA)(QWND*, const char*);
typedef const wchar_t* (*QEDGETTEXT)(QWND*);
typedef void (*QEDSETFONTNAME)(QWND*,const wchar_t*);
typedef void (*QEDSETFONTSIZE)(QWND*,int);
typedef void (*QEDSETFONTBRUSH)(QWND*,QBrush*);

class QEdit:public DLLImportQWND
{
    static HMODULE m_hm ;
    public:
    QEdit(HDC winddc,const QRect& rf);
    virtual ~QEdit();
    void LoadPicture(const std::wstring& path){QEDLoadPicture(qwm,path.c_str());}
    inline void SetTransparency(unsigned char apha){QEDSetBKImageTransparency(qwm,apha);}
    void SetSetBKBrush(QBrush* brush){QEDSetBKBrush(qwm,brush);}
    void SetText(const wchar_t* text){QEDSetText(qwm,text);}
    void SetText(const char* text){QEDSetTextA(qwm,text);}
    const wchar_t* GetText(){return QEDGetText(qwm);}
    void SetFontName(const wchar_t* name){QEDSetFontName(qwm,name);}
    void SetFontSize(int size){QEDSetFontSize(qwm,size);}
    void SetFontBrush(QBrush* brush){QEDSetFontBrush(qwm,brush);}

    virtual int init(HMODULE hm);


    public:
    static QEDSETBKIMAGETRANSPARENCY QEDSetBKImageTransparency;
    static QEDLOADPICTURE QEDLoadPicture;
    static QEDSETBKBRUSH QEDSetBKBrush;
    static QEDSETTEXT QEDSetText;
    static QEDSETTEXTA QEDSetTextA;
    static QEDGETTEXT QEDGetText;
    static QEDSETFONTNAME QEDSetFontName;
    static QEDSETFONTSIZE QEDSetFontSize;
    static QEDSETFONTBRUSH QEDSetFontBrush;
};
































#endif