#include "QFLineChart.h"
HMODULE QLineChart::m_hm =NULL;
__QFLCADDCURVE QLineChart::QFLCAddCurve = NULL;
__QFLCCURVEINSERTPOINT QLineChart::QFLCCurveInsertPoint = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(SetFontSize) = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(RemoveCurve) = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(SetTextAlgn) = NULL;
__INT__INT__FUN QLineChart::DEF_FUN_NAME(SetTextAlgnii) = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(SetTextAllgn) = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(SetLegFontSize) = NULL;
__WCHAR_T__FUN QLineChart::DEF_FUN_NAME(SetFontName) = NULL;
__WCHAR_T__FUN QLineChart::DEF_FUN_NAME(SetLegFontName) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetXAxisStrHeight) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetYAxisStrWidth) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetXAxisScaleWidth) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetYAxisScaleWidth) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetLineWidth) = NULL;
__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetLegWidth) = NULL;
__DOUBLE__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetXAxisRange) = NULL;
__DOUBLE__DOUBLE__FUN QLineChart::DEF_FUN_NAME(SetYAxisRange) = NULL;
__LONGLONG__FUN QLineChart::DEF_FUN_NAME(SetAttribute) = NULL;
__WCHAR_T__INT__FUN__INT QLineChart::DEF_FUN_NAME(FindCurve) = NULL;
__INT__ULONG__FUN QLineChart::DEF_FUN_NAME(SetCurveColor) = NULL;
__INT__WCHAR_T__FUN QLineChart::DEF_FUN_NAME(SetCurveName) = NULL;
__INT__BOOL__FUN QLineChart::DEF_FUN_NAME(SetCurveVisible) = NULL;
__INT__FUN QLineChart::DEF_FUN_NAME(SetBackground) = NULL;

QLineChart::QLineChart(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}

QLineChart::~QLineChart()
{
}

int QLineChart::init(HMODULE hm)
{
    if (!m_hm) {
        int count = 0;
        const char* fName = "QFLCAddCurve";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QFLCAddCurve = (__QFLCADDCURVE)pfun;
        fName = "QFLCCurveInsertPoint";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QFLCCurveInsertPoint = (__QFLCCURVEINSERTPOINT)pfun;

        fName = "QFLCSetXAxisStrHeight";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetXAxisStrHeight) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetYAxisStrWidth";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetYAxisStrWidth) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetXAxisScaleWidth";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetXAxisScaleWidth) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetYAxisScaleWidth";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetYAxisScaleWidth) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetLineWidth";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetLineWidth) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetXAxisRange";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetXAxisRange) = (__DOUBLE__DOUBLE__FUN)pfun;

        fName = "QFLCSetYAxisRange";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetYAxisRange) = (__DOUBLE__DOUBLE__FUN)pfun;

        fName = "QFLCSetLegWidth";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetLegWidth) = (__DOUBLE__FUN)pfun;

        fName = "QFLCSetAttribute";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetAttribute) = (__LONGLONG__FUN)pfun;

        fName = "QFLCFindCurve";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(FindCurve) = (__WCHAR_T__INT__FUN__INT)pfun;

        fName = "QFLCSetCurveColor";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetCurveColor) = (__INT__ULONG__FUN)pfun;

        fName = "QFLCSetCurveName";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetCurveName) = (__INT__WCHAR_T__FUN)pfun;

        fName = "QFLCSetFontName";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetFontName) = (__WCHAR_T__FUN)pfun;

        fName = "QFLCSetFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetFontSize) = (__INT__FUN)pfun;

        fName = "QFLCSetTextAlgn";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTextAlgn) = (__INT__FUN)pfun;

        fName = "QFLCSetTextAllgn";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTextAllgn) = (__INT__FUN)pfun;

        fName = "QFLCSetTextAlgnii";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetTextAlgnii) = (__INT__INT__FUN)pfun;

        fName = "QFLCSetLegFontName";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetLegFontName) = (__WCHAR_T__FUN)pfun;

        fName = "QFLCSetLegFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetLegFontSize) = (__INT__FUN)pfun;

        fName = "QFLCSetCurveVisible";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetCurveVisible) = (__INT__BOOL__FUN)pfun;

        fName = "QFLCRemoveCurve";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(RemoveCurve) = (__INT__FUN)pfun;

        fName = "QFLCSetBackground";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        DEF_FUN_NAME(SetBackground) = (__INT__FUN)pfun;

        DLLImportQWND::init(hm);
        DebugOut("QLineChart :import %d function", count);
        return count;
    }
    return 0;
}

int QLineChart::AddCurve(QPointF* pt, int len, unsigned long color, const wchar_t* name)
{
    return QFLCAddCurve(qwm, pt,len, color, name);
}

void QLineChart::CurveInsertPoint(int index, const QPointF& pt)
{
    QFLCCurveInsertPoint(qwm,index,pt);
}

void QLineChart::SetFontName(const wchar_t *name)
{
    return DEF_FUN_NAME(SetFontName)(qwm, name);
}

void QLineChart::SetFontSize(INT size)
{
    return DEF_FUN_NAME(SetFontSize)(qwm, size);
}

void QLineChart::SetTextAlgn(INT align)
{
    return DEF_FUN_NAME(SetTextAlgn)(qwm, align);
}

void QLineChart::SetTextAlgn(INT align, INT lalign)
{
    return DEF_FUN_NAME(SetTextAlgnii)(qwm, align, lalign);
}

void QLineChart::SetTextAllgn(INT lalign)
{
    return DEF_FUN_NAME(SetTextAllgn)(qwm,lalign);
}

void QLineChart::SetLegFontName(const wchar_t *name)
{
    return DEF_FUN_NAME(SetLegFontName)(qwm, name);
}

void QLineChart::SetLegFontSize(INT size)
{
    return DEF_FUN_NAME(SetLegFontSize)(qwm, size);
}

void QLineChart::SetXAxisStrHeight(double h)
{
    return DEF_FUN_NAME(SetXAxisStrHeight)(qwm, h);
}

void QLineChart::SetYAxisStrWidth(double w)
{
    return DEF_FUN_NAME(SetYAxisStrWidth)(qwm, w);
}

void QLineChart::SetXAxisScaleWidth(double w)
{
    return DEF_FUN_NAME(SetXAxisScaleWidth)(qwm, w);
}

void QLineChart::SetYAxisScaleWidth(double w)
{
    return DEF_FUN_NAME(SetYAxisScaleWidth)(qwm, w);
}

void QLineChart::SetLineWidth(double w)
{
    return DEF_FUN_NAME(SetLineWidth)(qwm, w);
}

void QLineChart::SetXAxisRange(double m, double M)
{
    return DEF_FUN_NAME(SetXAxisRange)(qwm, m,M);
}

void QLineChart::SetYAxisRange(double m, double M)
{
    return DEF_FUN_NAME(SetYAxisRange)(qwm, m, M);
}

void QLineChart::SetLegWidth(double w)
{
    return DEF_FUN_NAME(SetLegWidth)(qwm, w);
}

void QLineChart::SetAttribute(long long v)
{
    return DEF_FUN_NAME(SetAttribute)(qwm, v);
}

int QLineChart::FindCurve(const wchar_t *name, int start)
{
    return DEF_FUN_NAME(FindCurve)(qwm, name, start);
}

void QLineChart::SetCurveColor(int index, unsigned long color)
{
    return DEF_FUN_NAME(SetCurveColor)(qwm, index, color);
}

void QLineChart::SetCurveName(int index, const wchar_t *name)
{
    return DEF_FUN_NAME(SetCurveName)(qwm, index, name);
}
void QLineChart::SetCurveVisible(int index, bool isVisible)
{
    return DEF_FUN_NAME(SetCurveVisible)(qwm, index, isVisible);
}
void  QLineChart::RemoveCurve(int index)
{
    return DEF_FUN_NAME(RemoveCurve)(qwm, index);

}
void QLineChart::SetBackground(QBrush* brush)
{
    return DEF_FUN_NAME(SetBackground)(qwm, (int)brush);
}
