#include "QFCATLCtrl.h"

__GDefineFun_QCBC(QCBCSETFONTNAME, QCBCSetFontName);
__GDefineFun_QCBC(QCBCSETFONTSIZE, QCBCSetFontSize);
__GDefineFun_QCBC(QCBCINSERTBARCHART, QCBCInsertBarChart);
__GDefineFun_QCBC(QCBCSETBARCHART, QCBCSetBarChart);
__GDefineFun_QCBC(QCBCSETBARCHARTVALUE, QCBCSetBarChartValue);
__GDefineFun_QCBC(QCBCSETBARCHARTCOLOR, QCBCSetBarChartColor);
__GDefineFun_QCBC(QCBCSETBARCHARTTEXT, QCBCSetBarChartText);
__GDefineFun_QCBC(QCBCSETBARCHARTTEXTCOLOR, QCBCSetBarChartTextColor);
__GDefineFun_QCBC(QCBCINSERTGROUP, QCBCInsertGroup);
__GDefineFun_QCBC(QCBCREMOVEGROUP, QCBCRemoveGroup);
__GDefineFun_QCBC(QCBCREMOVEBARCHART, QCBCRemoveBarChart);
__GDefineFun_QCBC(QCBCSETSCALECOLOR, QCBCSetScaleColor);
__GDefineFun_QCBC(QCBCSETSCALEMAX, QCBCSetScaleMax);
__GDefineFun_QCBC(QCBCSETSCALEMIN, QCBCSetScaleMin);
__GDefineFun_QCBC(QCBCSETSCALEWIDTH, QCBCSetScaleWidth);
__GDefineFun_QCBC(QCBCSETSCALEHEIGHT, QCBCSetScaleHeight);
__GDefineFun_QCBC(QCBCSETBARCHARTWIDTH, QCBCSetBarChartWidth);
__GDefineFun_QCBC(QCBCSETGRIDWIDTH, QCBCSetGridWidth);
__GDefineFun_QCBC(QCBCSETLINEWIDTH, QCBCSetLineWidth);
__GDefineFun_QCBC(QCBCSETYAXISSTRWIDTH, QCBCSetYAxisStrWidth);
__GDefineFun_QCBC(QCBCCLEARBARCHART, QCBCClearBarChart);
__GDefineFun_QCBC(QCBCGETGROUPCOUNT, QCBCGetGroupCount);
__GDefineFun_QCBC(QCBCGETBARCHARTCOUNT, QCBCGetBarChartCount);

HMODULE QCATLBarChart::m_hm = NULL;
QCATLBarChart::QCATLBarChart(HDC winddc, const QRect& rf):DLLImportQWND(winddc, rf)
{

}
QCATLBarChart::~QCATLBarChart()
{

}

void QCATLBarChart::SetFontName(const wchar_t * name)
{
    return __FUNCTINNAME(SetFontName)(qwm, name);
}

int QCATLBarChart::SetBarChartValue(int grouId, int index, CBCVT v)
{
    return __FUNCTINNAME(SetBarChartValue)(qwm, grouId, index, v);
}
int QCATLBarChart::SetBarChartColor(int grouId, int index, int color)
{
    return __FUNCTINNAME(SetBarChartColor)(qwm, grouId, index, color);
}
int QCATLBarChart::SetBarChartText(int grouId, int index, const wchar_t *text)
{
    return __FUNCTINNAME(SetBarChartText)(qwm, grouId, index, text);
}
int QCATLBarChart::SetBarChartTextColor(int grouId, int index, unsigned int color)
{
    return __FUNCTINNAME(SetBarChartTextColor)(qwm, grouId, index, color);
}
int QCATLBarChart::InsertGroup(int grouId)
{
    return __FUNCTINNAME(InsertGroup)(qwm, grouId);
}
int QCATLBarChart::RemoveGroup(int grouId)
{
    return __FUNCTINNAME(RemoveGroup)(qwm, grouId);
}
int QCATLBarChart::RemoveBarChart(int grouId, int index)
{
    return __FUNCTINNAME(RemoveBarChart)(qwm, grouId, index);
}
void QCATLBarChart::SetScaleMax(float max)
{
    return __FUNCTINNAME(SetScaleMax)(qwm, max);
}
void QCATLBarChart::SetScaleMin(float min)
{
    return __FUNCTINNAME(SetScaleMin)(qwm, min);
}
void QCATLBarChart::SetScaleHeight(float height)
{
    return __FUNCTINNAME(SetScaleHeight)(qwm, height);
}
void QCATLBarChart::SetBarChartWidth(float width)
{
    return __FUNCTINNAME(SetBarChartWidth)(qwm, width);
}
void QCATLBarChart::SetGridWidth(float width)
{
    return __FUNCTINNAME(SetGridWidth)(qwm, width);
}
void QCATLBarChart::SetLineWidth(float width)
{
    return __FUNCTINNAME(SetLineWidth)(qwm, width);
}
void QCATLBarChart::SetYAxisStrWidth(float width)
{
    return __FUNCTINNAME(SetYAxisStrWidth)(qwm, width);
}
void QCATLBarChart::SetScaleWidth(float width)
{
    return __FUNCTINNAME(SetScaleWidth)(qwm, width);
}
void QCATLBarChart::SetScaleColor(unsigned int color)
{
    return __FUNCTINNAME(SetScaleColor)(qwm, color);
}
void QCATLBarChart::SetFontSize(float size)
{
    return __FUNCTINNAME(SetFontSize)(qwm, size);
}

int QCATLBarChart::InsertBarChart(int grouId, int index, CBCVT v, int color, const wchar_t * text, int tcolor)
{
    return __FUNCTINNAME(InsertBarChart)(qwm, grouId, index, v, color, text, tcolor);
}

int QCATLBarChart::SetBarChart(int grouId, int index, CBCVT v, int color, const wchar_t *text, int tcolor)
{
    return __FUNCTINNAME(SetBarChart)(qwm, grouId, index, v, color, text, tcolor);
}
void QCATLBarChart::ClearBarChart()
{

    return __FUNCTINNAME(ClearBarChart)(qwm);
}
int QCATLBarChart::GetGroupCount()
{
    return __FUNCTINNAME(GetGroupCount)(qwm);
}
int QCATLBarChart::GetBarChartCount(int gID)
{
    return __FUNCTINNAME(GetBarChartCount)(qwm, gID);
}

int QCATLBarChart::init(HMODULE hm)
{

    if (!m_hm) {
        int count = 0;
        const char* fName = __FUNCTINNAME_STR(SetFontName);
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetFontName) = (QCBCSETFONTNAME)pfun;

        fName = __FUNCTINNAME_STR(SetFontSize);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetFontSize) = (QCBCSETFONTSIZE)pfun;

        fName = __FUNCTINNAME_STR(InsertBarChart);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(InsertBarChart) = (QCBCINSERTBARCHART)pfun;

        fName = __FUNCTINNAME_STR(SetBarChart);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChart) = (__FUNCTINNAME(SETBARCHART))pfun;

        fName = __FUNCTINNAME_STR(SetBarChartValue);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChartValue) = (__FUNCTINNAME(SETBARCHARTVALUE))pfun;

        fName = __FUNCTINNAME_STR(SetBarChartColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChartColor) = (__FUNCTINNAME(SETBARCHARTCOLOR))pfun;

        fName = __FUNCTINNAME_STR(SetBarChartText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChartText) = (__FUNCTINNAME(SETBARCHARTTEXT))pfun;

        fName = __FUNCTINNAME_STR(SetBarChartTextColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChartTextColor) = (__FUNCTINNAME(SETBARCHARTTEXTCOLOR))pfun;

        fName = __FUNCTINNAME_STR(InsertGroup);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(InsertGroup) = (__FUNCTINNAME(INSERTGROUP))pfun;

        fName = __FUNCTINNAME_STR(RemoveGroup);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(RemoveGroup) = (__FUNCTINNAME(REMOVEGROUP))pfun;

        fName = __FUNCTINNAME_STR(RemoveBarChart);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(RemoveBarChart) = (__FUNCTINNAME(REMOVEBARCHART))pfun;

        fName = __FUNCTINNAME_STR(SetScaleColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetScaleColor) = (__FUNCTINNAME(SETSCALECOLOR))pfun;

        fName = __FUNCTINNAME_STR(SetScaleMax);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetScaleMax) = (__FUNCTINNAME(SETSCALEMAX))pfun;

        fName = __FUNCTINNAME_STR(SetScaleMin);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetScaleMin) = (__FUNCTINNAME(SETSCALEMIN))pfun;

        fName = __FUNCTINNAME_STR(SetScaleWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetScaleWidth) = (__FUNCTINNAME(SETSCALEWIDTH))pfun;

        fName = __FUNCTINNAME_STR(SetScaleHeight);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetScaleHeight) = (__FUNCTINNAME(SETSCALEHEIGHT))pfun;


        fName = __FUNCTINNAME_STR(SetBarChartWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetBarChartWidth) = (__FUNCTINNAME(SETBARCHARTWIDTH))pfun;

        fName = __FUNCTINNAME_STR(SetGridWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetGridWidth) = (__FUNCTINNAME(SETGRIDWIDTH))pfun;

        fName = __FUNCTINNAME_STR(SetLineWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetLineWidth) = (__FUNCTINNAME(SETLINEWIDTH))pfun;

        fName = __FUNCTINNAME_STR(SetYAxisStrWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(SetYAxisStrWidth) = (__FUNCTINNAME(SETYAXISSTRWIDTH))pfun;

        fName = __FUNCTINNAME_STR(ClearBarChart);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(ClearBarChart) = (__FUNCTINNAME(CLEARBARCHART))pfun;

        fName = __FUNCTINNAME_STR(GetGroupCount);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(GetGroupCount) = (__FUNCTINNAME(GETGROUPCOUNT))pfun;

        fName = __FUNCTINNAME_STR(GetBarChartCount);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME(GetBarChartCount) = (__FUNCTINNAME(GETBARCHARTCOUNT))pfun;



        DLLImportQWND::init(hm);
        DebugOut("QCATLBarChart :import %d function", count);
        return count;
    }
    return 0;
}




__GDefineFun_QCTC(QCTCSETFONTNAME, QCTCSetFontName);
__GDefineFun_QCTC(QCTCSETFONTSIZE, QCTCSetFontSize);
__GDefineFun_QCTC(QCTCSETUNITFONTSIZE, QCTCSetUnitFontSize);
__GDefineFun_QCTC(QCTCSETUNITWIDTH, QCTCSetUnitWidth);
__GDefineFun_QCTC(QCTCSETUNITINTERVALWIDTH, QCTCSetUnitIntervalWidth);
__GDefineFun_QCTC(QCTCSETALIGNWIDTH, QCTCSetAlignWidth);
__GDefineFun_QCTC(QCTCINSERTGROUP, QCTCInsertGroup);
__GDefineFun_QCTC(QCTCREMOVEGROUP, QCTCRemoveGroup);
__GDefineFun_QCTC(QCTCINSERTUNIT, QCTCInsertUnit);
__GDefineFun_QCTC(QCTCREMOVEUNIT, QCTCRemoveUnit);
__GDefineFun_QCTC(QCTCSETUNIT, QCTCSetUnit);
__GDefineFun_QCTC(QCTCSETUNITCOLOR, QCTCSetUnitColor);
__GDefineFun_QCTC(QCTCSETUNITTEXT, QCTCSetUnitText);
__GDefineFun_QCTC(QCTCSETUNITTEXTCOLOR, QCTCSetUnitTextColor);
__GDefineFun_QCTC(QCTCSETGROUPLINECOUNT, QCTCSetGroupLineCount);
__GDefineFun_QCTC(QCTCSETGROUPNAME, QCTCSetGroupName);

HMODULE QCATLTempeChart::m_hm = NULL;
QCATLTempeChart::QCATLTempeChart(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{
    
}

QCATLTempeChart::~QCATLTempeChart()
{
}

int QCATLTempeChart::init(HMODULE hm)
{
    if (!m_hm) {
        int count = 0;
        const char* fName = __FUNCTINNAME_QCTC_STR(SetFontName);
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetFontName) = (__FUNCTINNAME_QCTC(SETFONTNAME))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetFontSize);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetFontSize) = (__FUNCTINNAME_QCTC(SETFONTSIZE))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitFontSize);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitFontSize) = (__FUNCTINNAME_QCTC(SETUNITFONTSIZE))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitWidth) = (__FUNCTINNAME_QCTC(SETUNITWIDTH))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitIntervalWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitIntervalWidth) = (__FUNCTINNAME_QCTC(SETUNITINTERVALWIDTH))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetAlignWidth);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetAlignWidth) = (__FUNCTINNAME_QCTC(SETALIGNWIDTH))pfun;

        fName = __FUNCTINNAME_QCTC_STR(InsertGroup);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(InsertGroup) = (__FUNCTINNAME_QCTC(INSERTGROUP))pfun;

        fName = __FUNCTINNAME_QCTC_STR(RemoveGroup);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(RemoveGroup) = (__FUNCTINNAME_QCTC(REMOVEGROUP))pfun;

        fName = __FUNCTINNAME_QCTC_STR(InsertUnit);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(InsertUnit) = (__FUNCTINNAME_QCTC(INSERTUNIT))pfun;

        fName = __FUNCTINNAME_QCTC_STR(RemoveUnit);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(RemoveUnit) = (__FUNCTINNAME_QCTC(REMOVEUNIT))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnit);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnit) = (__FUNCTINNAME_QCTC(SETUNIT))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitColor) = (__FUNCTINNAME_QCTC(SETUNITCOLOR))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitText) = (__FUNCTINNAME_QCTC(SETUNITTEXT))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetUnitTextColor);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetUnitTextColor) = (__FUNCTINNAME_QCTC(SETUNITTEXTCOLOR))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetGroupLineCount);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetGroupLineCount) = (__FUNCTINNAME_QCTC(SETGROUPLINECOUNT))pfun;

        fName = __FUNCTINNAME_QCTC_STR(SetGroupName);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        __FUNCTINNAME_QCTC(SetGroupName) = (__FUNCTINNAME_QCTC(SETGROUPNAME))pfun;



        DLLImportQWND::init(hm);
        DebugOut("QCATLTempeChart :import %d function", count);
        return count;
    }

    return 0;
}

void QCATLTempeChart::SetFontName(const wchar_t* name)
{
    return __FUNCTINNAME_QCTC(SetFontName)(qwm, name);
}

void QCATLTempeChart::SetFontSize(float size)
{
    return __FUNCTINNAME_QCTC(SetFontSize)(qwm, size);
}

void QCATLTempeChart::SetUnitFontSize(float size)
{
    return __FUNCTINNAME_QCTC(SetUnitFontSize)(qwm, size);
}

void QCATLTempeChart::SetUnitWidth(float w)
{
    return __FUNCTINNAME_QCTC(SetUnitWidth)(qwm, w);
}

void QCATLTempeChart::SetUnitIntervalWidth(float w)
{
    return __FUNCTINNAME_QCTC(SetUnitIntervalWidth)(qwm, w);
}

void QCATLTempeChart::SetAlignWidth(float w)
{
    return __FUNCTINNAME_QCTC(SetAlignWidth)(qwm, w);
}

int QCATLTempeChart::InsertGroup(int gID)
{
    return __FUNCTINNAME_QCTC(InsertGroup)(qwm, gID);
}

int QCATLTempeChart::RemoveGroup(int gID)
{
    return __FUNCTINNAME_QCTC(RemoveGroup)(qwm, gID);
}

int QCATLTempeChart::InsertUnit(int gID, int uID, int color, const wchar_t* text, int tcolor)
{
    return __FUNCTINNAME_QCTC(InsertUnit)(qwm, gID, uID, color, text, tcolor);
}

int QCATLTempeChart::RemoveUnit(int gID, int uID)
{
    return __FUNCTINNAME_QCTC(RemoveUnit)(qwm, gID, uID);
}

int QCATLTempeChart::SetUnit(int gID, int uID, int color, const wchar_t* text, int tcolor)
{
    return __FUNCTINNAME_QCTC(SetUnit)(qwm, gID, uID, color, text, tcolor);
}

int QCATLTempeChart::SetUnitColor(int gID, int uID, int color)
{
    return __FUNCTINNAME_QCTC(SetUnitColor)(qwm, gID, uID, color);
}

int QCATLTempeChart::SetUnitText(int gID, int uID, const wchar_t* text)
{
    return __FUNCTINNAME_QCTC(SetUnitText)(qwm, gID, uID, text);
}


int QCATLTempeChart::SetUnitTextColor(int gID, int uID, int color)
{
    return __FUNCTINNAME_QCTC(SetUnitTextColor)(qwm, gID, uID, color);
}

int QCATLTempeChart::SetGroupLineCount(int gID, int count)
{
    return __FUNCTINNAME_QCTC(SetGroupLineCount)(qwm, gID, count);
}

int QCATLTempeChart::SetGroupName(int gID, const wchar_t* name)
{
    return __FUNCTINNAME_QCTC(SetGroupName)(qwm, gID, name);
}
