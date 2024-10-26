#include "QFTabs.h"
#define __FUNCTINNAME_QTB(name) QTB##name
#define __FUNCTINNAME_QTB_STR(name) "QTB" #name
#define __GDefineFun_QTB(name) __GDefineFun(QTabs,__QDefineType(name),name)
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
__GDefineFun_QTB(QTBAttachCtrlToCurrentTabe);
__GDefineFun_QTB(QTBGetTabeCount);
__GDefineFun_QTB(QTBGetTabeCtrlCount);
__GDefineFun_QTB(QTBGetCtrl);
__GDefineFun_QTB(QTBInsertTab);
__GDefineFun_QTB(QTBGetTabeBMPPath);
__GDefineFun_QTB(QTBGetTabeText);
__GDefineFun_QTB(QTBGetCurrentTabeText);
__GDefineFun_QTB(QTBGetCurrentTabeIcoPath);
__GDefineFun_QTB(QTBSetCurrentTabeIcoPath);
__GDefineFun_QTB(QTBSetCurrentTabeText);
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
        m_hm = hm;
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

        fName = __FUNCTINNAME_QTB_STR(AttachCtrlToCurrentTabe);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(AttachCtrlToCurrentTabe), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetTabeCount);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetTabeCount), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetTabeCtrlCount);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetTabeCtrlCount), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetCtrl);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetCtrl), pfun);

        fName = __FUNCTINNAME_QTB_STR(InsertTab);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(InsertTab), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetTabeBMPPath);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetTabeBMPPath), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetTabeText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetTabeText), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetCurrentTabeText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetCurrentTabeText), pfun);

        fName = __FUNCTINNAME_QTB_STR(GetCurrentTabeIcoPath);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(GetCurrentTabeIcoPath), pfun);

        fName = __FUNCTINNAME_QTB_STR(SetCurrentTabeText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(SetCurrentTabeText), pfun);

        fName = __FUNCTINNAME_QTB_STR(SetCurrentTabeIcoPath);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTB(SetCurrentTabeIcoPath), pfun);


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

void QTabs::AttachCtrlToCurrentTabe(QWND* w)
{
    return __FUNCTINNAME_QTB(AttachCtrlToCurrentTabe)(qwm,w);
}

int QTabs::GetTabeCount()
{
    return __FUNCTINNAME_QTB(GetTabeCount)(qwm);
}

int QTabs::GetTabeCtrlCount(int index)
{
    return __FUNCTINNAME_QTB(GetTabeCtrlCount)(qwm, index);
}

QWND* QTabs::GetCtrl(int ti, int index)
{
    return __FUNCTINNAME_QTB(GetCtrl)(qwm, ti, index);
}

int QTabs::InsertTab(const wchar_t* name, int index, const wchar_t* pBPath)
{
    return __FUNCTINNAME_QTB(InsertTab)(qwm, name, index, pBPath);
}

std::wstring QTabs::GetTabeBMPPath(int index)
{
    return std::wstring(__FUNCTINNAME_QTB(GetTabeBMPPath)(qwm, index));
}

std::wstring QTabs::GetTabeText(int index)
{
    return std::wstring(__FUNCTINNAME_QTB(GetTabeText)(qwm, index));
}

std::wstring QTabs::GetCurrentTabeText()
{
    return std::wstring(__FUNCTINNAME_QTB(GetCurrentTabeText)(qwm));
}

std::wstring QTabs::GetCurrentTabeIcoPath()
{
    return std::wstring(__FUNCTINNAME_QTB(GetCurrentTabeIcoPath)(qwm));
}

int QTabs::SetCurrentTabeText(const wchar_t* txt)
{
    return __FUNCTINNAME_QTB(SetCurrentTabeText)(qwm, txt);
}

int QTabs::SetCurrentTabeIcoPath(const wchar_t* path)
{
    return __FUNCTINNAME_QTB(SetCurrentTabeIcoPath)(qwm, path);
}













