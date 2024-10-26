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
#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __QDefineType(name) name##_Type
#define __MembersDef(name) __DefineFun(__QDefineType(name),name)
#define __FunTypeDef(fName) fName##_Type
typedef int (*QEDIT_CHANGE_EVENT)(int, int, int);//参数1：自身指针；参数2：字符串指针；参数3：设置时要求调用时带的
typedef void (*QEDSETBKIMAGETRANSPARENCY)(QWND* ,unsigned char);
typedef void (*QEDLOADPICTURE)(QWND* , const wchar_t*);
typedef void (*QEDSETBKBRUSH)(QWND* , QBrush*);
typedef void (*QEDSETTEXT)(QWND*, const wchar_t*);
typedef void (*QEDSETTEXTA)(QWND*, const char*);
typedef const wchar_t* (*QEDGETTEXT)(QWND*);
typedef void (*QEDSETFONTNAME)(QWND*,const wchar_t*);
typedef void (*QEDSETFONTSIZE)(QWND*,int);
typedef void (*QEDSETFONTBRUSH)(QWND*,QBrush*);
typedef void (*__QDefineType(QEDSetChangeEvent))(QWND*, QEDIT_CHANGE_EVENT,int);

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
    void SetChangeEvent(QEDIT_CHANGE_EVENT even, int param);


    virtual int init(HMODULE hm);


    private:
    static QEDSETBKIMAGETRANSPARENCY QEDSetBKImageTransparency;
    static QEDLOADPICTURE QEDLoadPicture;
    static QEDSETBKBRUSH QEDSetBKBrush;
    static QEDSETTEXT QEDSetText;
    static QEDSETTEXTA QEDSetTextA;
    static QEDGETTEXT QEDGetText;
    static QEDSETFONTNAME QEDSetFontName;
    static QEDSETFONTSIZE QEDSetFontSize;
    static QEDSETFONTBRUSH QEDSetFontBrush;
    __MembersDef(QEDSetChangeEvent);

};
































#endif