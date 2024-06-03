#include "QFTabs.h"
__QWND__INT__FUN__INT QTabs::DEF_FUN_NAME(AttachCtrl) = NULL;
HMODULE QTabs::m_hm = NULL;
__WCHAR__WCHAR__FUN__INT QTabs::DEF_FUN_NAME(AddTab) = NULL;
__QWND__INT__FUN__INT  QTabs::DEF_FUN_NAME(RemoveCtrl);
__INT__FUN__INT  QTabs::DEF_FUN_NAME(RemoveTab);
__INT__FUN__INT  QTabs::DEF_FUN_NAME(SetBKBrush);
__WCHAR__FUN  QTabs::DEF_FUN_NAME(SetFontName);
__DOUBLE__FUN  QTabs::DEF_FUN_NAME(SetFontSize);
__ULONG__FUN  QTabs::DEF_FUN_NAME(SetFontColor);
__ULONG__FUN  QTabs::DEF_FUN_NAME(SetTabBKColor);
__INT__WCHAR__FUN  QTabs::DEF_FUN_NAME(SetTabIco);
__INT__WCHAR__FUN  QTabs::DEF_FUN_NAME(SetTabName);


QTabs::QTabs(HDC winddc, const QRect& rf):DLLImportQWND(winddc,rf)
{

}

QTabs::~QTabs()
{
}
int QTabs::AttachCtrl(DLLImportQWND* w, int index)
{

	return DEF_FUN_NAME(AttachCtrl)(qwm,w->qwm,index);
}
int QTabs::RemoveCtrl(DLLImportQWND* w, int index)
{

    return DEF_FUN_NAME(RemoveCtrl)(qwm, w->qwm, index);
}
int QTabs::init(HMODULE hm)
{
    if (!m_hm) {
        int count = 0;
        const char* fName = "QTBAttachCtrl";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(AttachCtrl) = (__QWND__INT__FUN__INT)pfun;
        
        fName = "QTBAddTab";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(AddTab) = (__WCHAR__WCHAR__FUN__INT)pfun;

        fName = DEF_FUN_NAME_STR("RemoveTab");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(RemoveTab) = (__INT__FUN__INT)pfun;

        fName = DEF_FUN_NAME_STR("SetBKBrush");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetBKBrush) = (__INT__FUN__INT)pfun;

        fName = DEF_FUN_NAME_STR("SetFontName");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetFontName) = (__WCHAR__FUN)pfun;

        fName = DEF_FUN_NAME_STR("SetFontSize");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetFontSize) = (__DOUBLE__FUN)pfun;

        fName = DEF_FUN_NAME_STR("SetFontColor");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetFontColor) = (__ULONG__FUN)pfun;

        fName = DEF_FUN_NAME_STR("SetTabBKColor");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTabBKColor) = (__ULONG__FUN)pfun;

        fName = DEF_FUN_NAME_STR("SetTabIco");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTabIco) = (__INT__WCHAR__FUN)pfun;

        fName = DEF_FUN_NAME_STR("SetTabName");
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTabName) = (__INT__WCHAR__FUN)pfun;

        DLLImportQWND::init(hm);
        DebugOut("QLineChart :import %d function", count);
        return count;
    }
    return 0;
}


int QTabs::AddTab(const wchar_t* name, const wchar_t* pBPath)
{

    return DEF_FUN_NAME(AddTab)(qwm,name, pBPath);
}
int QTabs::RemoveTab(int index)
{

    return DEF_FUN_NAME(RemoveTab)(qwm, index);
}

int QTabs::SetBKBrush(QBrush* brush)
{
    return DEF_FUN_NAME(SetBKBrush)(qwm, (int)brush);
}

void QTabs::SetFontName(const wchar_t* name)
{
    return DEF_FUN_NAME(SetFontName)(qwm, name);
}

void QTabs::SetFontSize(double size)
{
    return DEF_FUN_NAME(SetFontSize)(qwm, size);
}

void QTabs::SetFontColor(unsigned long color)
{
    return DEF_FUN_NAME(SetFontColor)(qwm, color);
}

void QTabs::SetTabIco(int index, const wchar_t* path)
{
    return DEF_FUN_NAME(SetTabIco)(qwm, index, path);
}

void QTabs::SetTabName(int index, const wchar_t* name)
{
    return DEF_FUN_NAME(SetTabName)(qwm, index, name);
}

void QTabs::SetTabBKColor(unsigned long color)
{
    return DEF_FUN_NAME(SetTabBKColor)(qwm, color);
}













