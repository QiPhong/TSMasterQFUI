#include "QF3DCtrl.h"

Q3DCtrl::Q3DCtrl(HDC winddc, const QRect& rf):DLLImportQWND(winddc, rf)
{

}

Q3DCtrl::~Q3DCtrl()
{
}
HMODULE QGraph3D::m_hm = NULL;
QG3DADDCURVE QGraph3D::QG3DAddCurve =NULL;
QGraph3D::QGraph3D(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}
QGraph3D::~QGraph3D()
{

}
int QGraph3D::AddCurve(float* xRange, float* yRange,
    DEFINEDOMAIN dd, DEFINEDOMAINYVALUE ddy, DEFINEDOMAINXVALUE ddx, GETZVALUE getZ,
    int numVerticesX, int numVerticesY)
{

    return QG3DAddCurve(qwm, xRange, yRange, dd, ddy, ddx, getZ, numVerticesX, numVerticesY);
}

int QGraph3D::init(HMODULE hm)
{
    if (!m_hm) {

        GET3DPROCADDRESS getps = (GET3DPROCADDRESS)QEXPORTFUNC::QExportFunction(hm, "Get3DProcAddress");
        if (getps) {
            int count = 0;
            const char* fName = "QG3DAddCurve";
            void* pfun = QEXPORTFUNC::QExportFunction(getps, fName);
            if (pfun)++count;
            QG3DAddCurve = (QG3DADDCURVE)pfun;

            return count;
        }
    }
    return 0;
}