#include "QFButton.h"
HMODULE QButton::m_hm = NULL;
__QFBSETFONTNAME QButton::QFBSetFontName = NULL;
__QFBSETFONTSIZE QButton::QFBSetFontSize = NULL;
__QFBSETTEXTALGN QButton::QFBSetTextAlgn = NULL;
__QFBSETTEXTALLGN QButton::QFBSetTextAllgn = NULL;
__QFBSETCLICKEVENT QButton::QFBSetClickEvent = NULL;
__QFBSETTEXT QButton::QFBSetText = NULL;
QButton::QButton(HDC winddc,const QRect& rf):DLLImportQWND(winddc,rf)
{

}
QButton::~QButton()
{


}
                                  

void QButton::SetText(const wchar_t* t)
{
    QFBSetText(qwm,t);
}
void QButton::SetFontName(const wchar_t* name)
{
    QFBSetFontName(qwm,name);
}
void QButton::SetFontSize(INT size)
{
    QFBSetFontSize(qwm,size);
}
void QButton::SetTextAlgn(unsigned int align)
{
    QFBSetTextAlgn(qwm,align);
}
void QButton::SetTextAlgn(unsigned int align, unsigned int lalign)
{
    QFBSetTextAlgn(qwm,align);
    QFBSetTextAllgn(qwm,lalign);
}
void QButton::SetTextAllgn(unsigned int lalign)
{
    QFBSetTextAllgn(qwm,lalign);
}

int QButton::init(HMODULE hm)
{

   if(!m_hm){
        int count = 0;
        const char* fName = "QFBSetFontName";
        void* pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBSetFontName = (__QFBSETFONTNAME)pfun;

        fName = "QFBSetFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBSetFontSize = (__QFBSETFONTSIZE)pfun;

        fName = "QFBSetTextAlgn";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBSetTextAlgn = (__QFBSETTEXTALGN)pfun;

        fName = "QFBSetTextAllgn";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBSetTextAllgn = (__QFBSETTEXTALLGN)pfun;

        fName = "QFBSetClickEvent";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBSetClickEvent = (__QFBSETCLICKEVENT)pfun;



        DLLImportQWND::init(hm);
        DebugOut("QButton :import %d function",count);
        return count;
    }
    return 0;
}

void QButton::SetClickEvent(QFBUTTONCLICK fun)
{
    QFBSetClickEvent(qwm,fun);
}
