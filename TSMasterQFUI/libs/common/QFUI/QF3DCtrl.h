#pragma once
#include "DLLImportQWND.h"
class Q3DCtrl :public DLLImportQWND
{
public:
    Q3DCtrl(HDC winddc, const QRect& rf);
    virtual ~Q3DCtrl();


};

typedef bool (*DEFINEDOMAIN)(float, float);
typedef int (*DEFINEDOMAINYVALUE)(float, float*);
typedef int (*DEFINEDOMAINXVALUE)(float, float*);
typedef bool (*GETZVALUE)(float, float, float*);

typedef int (*QG3DADDCURVE)(QWND*, float*, float* ,DEFINEDOMAIN, DEFINEDOMAINYVALUE, DEFINEDOMAINXVALUE, GETZVALUE,int, int);
typedef void (*QG3DSETVISUALHEIGH)(QWND*, float);
typedef void (*QG3DISVISIVALAXIS)(QWND*, bool);


class QGraph3D :public DLLImportQWND
{
    static HMODULE m_hm;
    static QG3DADDCURVE QG3DAddCurve;
    static QG3DSETVISUALHEIGH QG3DSetVisualHeigh;
    static QG3DISVISIVALAXIS QG3DIsVisivalAxis;
public:
    QGraph3D(HDC winddc, const QRect& rf);
    virtual ~QGraph3D();
    virtual int init(HMODULE hm);
    int AddCurve(float* xRange, float* yRange,
        DEFINEDOMAIN dd, DEFINEDOMAINYVALUE ddy, DEFINEDOMAINXVALUE ddx, GETZVALUE getZ,
        int numVerticesX, int numVerticesY);
    void SetVisualHeigh(float height);
    void IsVisivalAxis(bool isVisival);
};



