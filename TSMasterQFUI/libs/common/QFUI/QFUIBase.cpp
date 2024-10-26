#include "QFUIBase.h"
#define __FUNCTINNAME(name)QFUIB##name
#define __FUNCTINNAME_STR(name) "QFUIB" #name
#define __GDefineFun_(name) __GDefineFun(QFUIBase,__QDefineType(name),name)
HMODULE QFUIBase::m_hm = NULL;
__GDefineFun_(QFUIBRecordAttribute);
__GDefineFun_(QFUIBFindAttribute);
__GDefineFun_(QFUIBRemoveAttribute);
QFUIBase::QFUIBase(HDC winddc, const QRect& rf):DLLImportQWND(winddc, rf)
{

}

int QFUIBase::init(HMODULE hm)
{
    if (!m_hm) {
        int count = 0;
        const char* fName = __FUNCTINNAME_STR(RecordAttribute);
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(RecordAttribute), pfun);

        fName = __FUNCTINNAME_STR(FindAttribute);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(FindAttribute), pfun);

        fName = __FUNCTINNAME_STR(RecordAttribute);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(RecordAttribute), pfun);

        m_hm = hm;
        DLLImportQWND::init(hm);
        DebugOut("QFUIBase :import %d function", count);
        return count;
    }
    return 0;
}

int QFUIBase::RecordAttribute(long long key, long long value)
{
    return __FUNCTINNAME(RecordAttribute)(qwm,key,value);
}

int QFUIBase::FindAttribute(long long key, long long* pvalue)
{
    return __FUNCTINNAME(FindAttribute)(qwm, key, pvalue);
}

int QFUIBase::RemoveAttribute(long long key)
{
    return __FUNCTINNAME(RemoveAttribute)(qwm, key);
    
}



#define __FUNCTINNAME(name)QCBDD##name
#define __FUNCTINNAME_STR(name) "QCBDD" #name
#define __GDefineFun_(name) __GDefineFun(QCtrlBaseD2DIPD,__QDefineType(name),name)
HMODULE QCtrlBaseD2DIPD::m_hm = NULL;



__GDefineFun_(__EXTERN_FFUN(QCBDD, SetFontSize));
__GDefineFun_(__EXTERN_FFUN(QCBDD, SetFontName));
__GDefineFun_(__EXTERN_FFUN(QCBDD, SetFontColor));


QCtrlBaseD2DIPD::QCtrlBaseD2DIPD(HDC winddc, const QRect& rf):QFUIBase(winddc, rf)
{
}

int QCtrlBaseD2DIPD::init(HMODULE hm)
{
    int count = 0;
    if (!m_hm) {
   
        const char* fName = __FUNCTINNAME_STR(SetFontSize);
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetFontSize), pfun);

        fName = __FUNCTINNAME_STR(SetFontName);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetFontName), pfun);

        fName = __FUNCTINNAME_STR(SetFontColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetFontColor), pfun);

        m_hm = hm;
     
        DebugOut("QCtrlBaseD2DIPD :import %d function", count);
        
    }
    QFUIBase::init(hm);
    return count;
}

void QCtrlBaseD2DIPD::SetFontName(const wchar_t* t)
{
    return __FUNCTINNAME(SetFontName)(qwm, t);
}

void QCtrlBaseD2DIPD::SetFontSize(double size)
{
    return __FUNCTINNAME(SetFontSize)(qwm, size);
}

void QCtrlBaseD2DIPD::SetFontColor(unsigned int color)
{
    return __FUNCTINNAME(SetFontColor)(qwm, color);
}
