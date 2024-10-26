#pragma once
#include "DLLImportQWND.h"
typedef int (*__QFLCADDCURVE)(QWND*, QPointF* , int , unsigned long , const wchar_t* );
typedef void (*__QFLCCURVEINSERTPOINT)(QWND*, int , const QPointF&);
typedef void (*__INT__FUN)(QWND*, int);
typedef void (*__INT__INT__FUN)(QWND*, int, int);
typedef void (*__WCHAR_T__FUN)(QWND*, const wchar_t*);
typedef void (*__DOUBLE__FUN)(QWND*, double);
typedef void (*__DOUBLE__DOUBLE__FUN)(QWND*, double, double);
typedef void (*__LONGLONG__FUN)(QWND*, long long);
typedef int (*__WCHAR_T__INT__FUN__INT)(QWND*, const wchar_t*,int);
typedef void (*__INT__ULONG__FUN)(QWND*, int,unsigned long);
typedef void (*__INT__WCHAR_T__FUN)(QWND*, int, const wchar_t*);
typedef void (*__INT__BOOL__FUN)(QWND*, int, bool);

#define DEF_FUN_NAME(name) QFLC##name

class QLineChart :public DLLImportQWND
{
	static HMODULE m_hm;
	static __QFLCADDCURVE DEF_FUN_NAME(AddCurve);
	static __QFLCCURVEINSERTPOINT DEF_FUN_NAME(CurveInsertPoint);
    static __INT__FUN DEF_FUN_NAME(SetFontSize);
    static __INT__FUN DEF_FUN_NAME(SetTextAlgn);
    static __INT__FUN DEF_FUN_NAME(RemoveCurve);
    static __INT__INT__FUN DEF_FUN_NAME(SetTextAlgnii);
    static __INT__FUN DEF_FUN_NAME(SetTextAllgn);
    static __INT__FUN DEF_FUN_NAME(SetLegFontSize);
    static __WCHAR_T__FUN DEF_FUN_NAME(SetFontName);
    static __WCHAR_T__FUN DEF_FUN_NAME(SetLegFontName);
    static __DOUBLE__FUN DEF_FUN_NAME(SetXAxisStrHeight);
    static __DOUBLE__FUN DEF_FUN_NAME(SetYAxisStrWidth);
    static __DOUBLE__FUN DEF_FUN_NAME(SetXAxisScaleWidth);
    static __DOUBLE__FUN DEF_FUN_NAME(SetYAxisScaleWidth);
    static __DOUBLE__FUN DEF_FUN_NAME(SetLineWidth);
    static __DOUBLE__FUN DEF_FUN_NAME(SetLegWidth);
    static __DOUBLE__DOUBLE__FUN DEF_FUN_NAME(SetXAxisRange);
    static __DOUBLE__DOUBLE__FUN DEF_FUN_NAME(SetYAxisRange);
    static __LONGLONG__FUN DEF_FUN_NAME(SetAttribute);
    static __WCHAR_T__INT__FUN__INT DEF_FUN_NAME(FindCurve);
    static __INT__ULONG__FUN DEF_FUN_NAME(SetCurveColor); 
    static __INT__WCHAR_T__FUN DEF_FUN_NAME(SetCurveName);
    static __INT__BOOL__FUN DEF_FUN_NAME(SetCurveVisible);
    static __INT__FUN DEF_FUN_NAME(SetBackground);
public:
	QLineChart(HDC winddc, const QRect& rf);
	virtual ~QLineChart();
public:
	virtual int init(HMODULE hm);
	int AddCurve(QPointF* pt, int len, unsigned long color = 0xff000000, const wchar_t* name = NULL);
	void CurveInsertPoint(int index, const QPointF& pt);
    void SetFontName(const wchar_t* name);//设置坐标轴字体名称
    void SetFontSize(INT size);//设置坐标轴字体大小
    void SetTextAlgn(INT align);
    void SetTextAlgn(INT align, INT lalign);
    void SetTextAllgn(INT lalign);
    void SetLegFontName(const wchar_t* name);//设置图例字体名称
    void SetLegFontSize(INT size);//设置图例字体大小
    void SetXAxisStrHeight(double h);
    void SetYAxisStrWidth(double w);
    void SetXAxisScaleWidth(double w);
    void SetYAxisScaleWidth(double w);
    void SetLineWidth(double w);
    void SetXAxisRange(double m, double M);//设置x轴范围
    void SetYAxisRange(double m, double M);//设置y轴范围
    void SetLegWidth(double w);//设置y轴范围
    void SetAttribute(long long v);
    int FindCurve(const wchar_t* name, int start = 0);//查找曲线，名字和开始查找的索引，返回找到的索引，找不到返回-1
    void SetCurveColor(int index, unsigned long color);
    void SetCurveName(int index, const wchar_t* name);
    void SetCurveVisible(int index, bool isVisible);
    void RemoveCurve(int index);
    void SetBackground(QBrush* brush);

};

