#pragma once

#include "DLLImportQWND.h"
#define CATLBarChart_Value_Type double
#define CBCVT CATLBarChart_Value_Type
typedef  void (*QCBCSETFONTNAME)(QWND* q, const wchar_t* name);
typedef  void (*QCBCSETFONTSIZE)(QWND* q, float size);
typedef  int (*QCBCINSERTBARCHART)(QWND* q, int grouId, int index, CBCVT v, int color, const wchar_t* text, int tcolor);
typedef  int (*QCBCSETBARCHART)(QWND* q, int grouId, int index, CBCVT v, int color, const wchar_t* text, int tcolor);
typedef  int (*QCBCSETBARCHARTVALUE)(QWND* q, int grouId, int index, CBCVT v);
typedef  int (*QCBCSETBARCHARTCOLOR)(QWND* q, int grouId, int index, unsigned int color);
typedef  int (*QCBCSETBARCHARTTEXT)(QWND* q, int grouId, int index, const wchar_t* text);
typedef  int (*QCBCSETBARCHARTTEXTCOLOR)(QWND* q, int grouId, int index, unsigned int color);
typedef  int (*QCBCINSERTGROUP)(QWND* q, int grouId);
typedef  int (*QCBCREMOVEGROUP)(QWND* q, int grouId);
typedef  int (*QCBCREMOVEBARCHART)(QWND* q, int grouId, int index);
typedef  void (*QCBCSETSCALECOLOR)(QWND* q, int color);
typedef  void (*QCBCSETSCALEMAX)(QWND* q, float max);
typedef  void (*QCBCSETSCALEMIN)(QWND* q, float min);
typedef  void (*QCBCSETSCALEWIDTH)(QWND* q, float width);
typedef  void (*QCBCSETSCALEHEIGHT)(QWND* q, float height);
typedef  void (*QCBCSETBARCHARTWIDTH)(QWND* q, float width);
typedef  void (*QCBCSETGRIDWIDTH)(QWND* q, float width);
typedef  void (*QCBCSETLINEWIDTH)(QWND* q, float width);
typedef  void (*QCBCSETYAXISSTRWIDTH)(QWND* q, float width);
typedef  void (*QCBCCLEARBARCHART)(QWND* q);
typedef  int (*QCBCGETGROUPCOUNT)(QWND* q);
typedef  int (*QCBCGETBARCHARTCOUNT)(QWND* q,int);


#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __GDefineFun_QCBC(type,name) __GDefineFun(QCATLBarChart,type,name)
#define __FUNCTINNAME(name) QCBC##name
#define __FUNCTINNAME_STR(name) "QCBC" #name

class QCATLBarChart:public DLLImportQWND
{
    __DefineFun(QCBCSETFONTNAME, QCBCSetFontName);
    __DefineFun(QCBCSETFONTSIZE, QCBCSetFontSize);
    __DefineFun(QCBCINSERTBARCHART, QCBCInsertBarChart);
    __DefineFun(QCBCSETBARCHART, QCBCSetBarChart);
    __DefineFun(QCBCSETBARCHARTVALUE, QCBCSetBarChartValue);
    __DefineFun(QCBCSETBARCHARTCOLOR, QCBCSetBarChartColor);
    __DefineFun(QCBCSETBARCHARTTEXT, QCBCSetBarChartText);
    __DefineFun(QCBCSETBARCHARTTEXTCOLOR, QCBCSetBarChartTextColor);
    __DefineFun(QCBCINSERTGROUP, QCBCInsertGroup);
    __DefineFun(QCBCREMOVEGROUP, QCBCRemoveGroup);
    __DefineFun(QCBCREMOVEBARCHART, QCBCRemoveBarChart);
    __DefineFun(QCBCSETSCALECOLOR, QCBCSetScaleColor);
    __DefineFun(QCBCSETSCALEMAX, QCBCSetScaleMax);
    __DefineFun(QCBCSETSCALEMIN, QCBCSetScaleMin);
    __DefineFun(QCBCSETSCALEWIDTH, QCBCSetScaleWidth);
    __DefineFun(QCBCSETSCALEHEIGHT, QCBCSetScaleHeight);
    __DefineFun(QCBCSETBARCHARTWIDTH, QCBCSetBarChartWidth);
    __DefineFun(QCBCSETGRIDWIDTH, QCBCSetGridWidth);
    __DefineFun(QCBCSETLINEWIDTH, QCBCSetLineWidth);
    __DefineFun(QCBCSETYAXISSTRWIDTH, QCBCSetYAxisStrWidth);
    __DefineFun(QCBCCLEARBARCHART, QCBCClearBarChart);
    __DefineFun(QCBCGETGROUPCOUNT, QCBCGetGroupCount);
    __DefineFun(QCBCGETBARCHARTCOUNT, QCBCGetBarChartCount);

    static HMODULE m_hm;
    
public:
    QCATLBarChart(HDC winddc, const QRect& rf);
    virtual ~QCATLBarChart();
    void SetFontName(const wchar_t* name);
    void SetFontSize(float size);
    int InsertBarChart(int grouId, int index, CBCVT v, int color, const wchar_t* text = L"", int tcolor = 0xff000000);
    int SetBarChart(int grouId, int index, CBCVT v, int color, const wchar_t* text = L"", int tcolor = 0xff000000);
    int SetBarChartValue(int grouId, int index, CBCVT v);
    int SetBarChartColor(int grouId, int index, int color);
    int SetBarChartText(int grouId, int index, const wchar_t* text);
    int SetBarChartTextColor(int grouId, int index, unsigned int color);
    int InsertGroup(int grouId);
    int RemoveGroup(int grouId);
    int RemoveBarChart(int grouId, int index);

    void SetScaleColor(unsigned int color);
    void SetScaleMax(float max);
    void SetScaleMin(float min);
    void SetScaleWidth(float width);
    void SetScaleHeight(float height);
    void SetBarChartWidth(float width);
    void SetGridWidth(float width);
    void SetLineWidth(float width);
    void SetYAxisStrWidth(float width);
    virtual int init(HMODULE hm);
    void ClearBarChart();
    int GetGroupCount();
    int GetBarChartCount(int gID);
};
#define __GDefineFun_QCTC(type,name) __GDefineFun(QCATLTempeChart,type,name)
#define __FUNCTINNAME_QCTC(name) QCTC##name
#define __FUNCTINNAME_QCTC_STR(name) "QCTC" #name

typedef void (*QCTCSETFONTNAME)(QWND* p, const wchar_t* name);
typedef void (*QCTCSETFONTSIZE)(QWND* p, float size);
typedef void (*QCTCSETUNITFONTSIZE)(QWND* p, float size);
typedef void (*QCTCSETUNITWIDTH)(QWND* p, float w);
typedef void (*QCTCSETUNITINTERVALWIDTH)(QWND* p, float w);
typedef void (*QCTCSETALIGNWIDTH)(QWND* p, float w);
typedef int (*QCTCINSERTGROUP)(QWND* p, int gID);
typedef int (*QCTCREMOVEGROUP)(QWND* p, int gID);
typedef int (*QCTCINSERTUNIT)(QWND* p, int gID, int uID, int color, const wchar_t* text, int tcolor);
typedef int (*QCTCREMOVEUNIT)(QWND* p, int gID, int uID);

typedef int (*QCTCSETUNIT)(QWND* p, int gID, int uID, int color, const wchar_t* text, int tcolor);

typedef int (*QCTCSETUNITCOLOR)(QWND* p, int gID, int uID, int color);

typedef int (*QCTCSETUNITTEXT)(QWND* p, int gID, int uID, const wchar_t* text);

typedef int (*QCTCSETUNITTEXTCOLOR)(QWND* p, int gID, int uID, int color);

typedef int (*QCTCSETGROUPLINECOUNT)(QWND* p, int gID, int count);

typedef int (*QCTCSETGROUPNAME)(QWND* p, int gID, const wchar_t* name);
class QCATLTempeChart :public DLLImportQWND
{
   static HMODULE m_hm;
   __DefineFun(QCTCSETFONTNAME, QCTCSetFontName);
   __DefineFun(QCTCSETFONTSIZE, QCTCSetFontSize);
   __DefineFun(QCTCSETUNITFONTSIZE, QCTCSetUnitFontSize);
   __DefineFun(QCTCSETUNITWIDTH, QCTCSetUnitWidth);
   __DefineFun(QCTCSETUNITINTERVALWIDTH, QCTCSetUnitIntervalWidth);
   __DefineFun(QCTCSETALIGNWIDTH, QCTCSetAlignWidth);
   __DefineFun(QCTCINSERTGROUP, QCTCInsertGroup);
   __DefineFun(QCTCREMOVEGROUP, QCTCRemoveGroup);
   __DefineFun(QCTCINSERTUNIT, QCTCInsertUnit);
   __DefineFun(QCTCREMOVEUNIT, QCTCRemoveUnit);
   __DefineFun(QCTCSETUNIT, QCTCSetUnit);
   __DefineFun(QCTCSETUNITCOLOR, QCTCSetUnitColor);
   __DefineFun(QCTCSETUNITTEXT, QCTCSetUnitText);
   __DefineFun(QCTCSETUNITTEXTCOLOR, QCTCSetUnitTextColor);
   __DefineFun(QCTCSETGROUPLINECOUNT, QCTCSetGroupLineCount);
   __DefineFun(QCTCSETGROUPNAME, QCTCSetGroupName);
public:
    QCATLTempeChart(HDC winddc, const QRect& rf);
    virtual ~QCATLTempeChart();
    virtual int init(HMODULE hm);
    //用户使用接口

    void SetFontName(const wchar_t* name);
    void SetFontSize(float size);
    void SetUnitFontSize(float size);
    void SetUnitWidth(float w);
    void SetUnitIntervalWidth(float w);
    void SetAlignWidth(float w);
    int InsertGroup(int gID);
    int RemoveGroup(int gID);
    int InsertUnit(int gID, int uID, int color, const wchar_t* text = L"", int tcolor = 0xff000000);
    int RemoveUnit(int gID, int uID);

    int SetUnit(int gID, int uID, int color, const wchar_t* text = L"", int tcolor = 0xff000000);

    int SetUnitColor(int gID, int uID, int color);

    int SetUnitText(int gID, int uID, const wchar_t* text);

  

    int SetUnitTextColor(int gID, int uID, int color);

    int SetGroupLineCount(int gID, int count);
    int SetGroupName(int gID, const wchar_t* name);
};