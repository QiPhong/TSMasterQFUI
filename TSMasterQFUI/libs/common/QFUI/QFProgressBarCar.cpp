#include "QFProgressBarCar.h"
std::function<void(QWND*, double)> QProgressBarCar::QFBCSetPercentage;
std::function<double(QWND*)> QProgressBarCar::QFBCGetPercentage;
std::function<void(QWND*, double)> QProgressBarCar::QFBCSetFontSize;
std::function<void(QWND*, const wchar_t*)> QProgressBarCar::QFBCSetFontName;
std::function<void(QWND*,unsigned int)> QProgressBarCar::QFBCSetFontColor;
std::function<void(QWND*, bool)> QProgressBarCar::QFBCIsShowDec;
std::function<void(QWND*, QBrush*)> QProgressBarCar::QFBCSetFillBrush;
HMODULE QProgressBarCar::m_hm = NULL;
QProgressBarCar::QProgressBarCar(HDC winddc, const QRect &rf):DLLImportQWND(winddc,rf)
{

}

QProgressBarCar::~QProgressBarCar()
{
}

int QProgressBarCar::init(HMODULE hm)
{
    if(!m_hm){
        int count = 0;
        const char* fName = "QFBCSetPercentage";
        void* pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCSetPercentage = std::function<void(QWND*,double)>((void(*)(QWND*,double))pfun);

        fName = "QFBCGetPercentage";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCGetPercentage = std::function<double(QWND*)>((double(*)(QWND*))pfun);

        fName = "QFBCSetFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCSetFontSize = std::function<void(QWND*,double)>((void(*)(QWND*,double))pfun);

        fName = "QFBCSetFontName";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCSetFontName = std::function<void(QWND*,const wchar_t*)>((void(*)(QWND*,const wchar_t*))pfun);

        fName = "QFBCSetFontColor";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCSetFontColor = std::function<void(QWND*, unsigned int)>((void(*)(QWND*, unsigned int))pfun);

        fName = "QFBCIsShowDec";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCIsShowDec = std::function<void(QWND*,bool)>((void(*)(QWND*,bool))pfun);
       
        fName = "QFBCSetFillBrush";
        pfun = QEXPORTFUNC::QExportFunction(hm,fName);
        if(pfun)++count;
        QFBCSetFillBrush = std::function<void(QWND*,QBrush*)>((void(*)(QWND*,QBrush*))pfun);



        DLLImportQWND::init(hm);
        DebugOut("QProgressBarCar :import %d function",count);
        return count;
    }
    return 0;
}

void QProgressBarCar::SetPercentage(double rat)
{
    return QFBCSetPercentage(qwm,rat);
}

double QProgressBarCar::GetPercentage()
{
    return QFBCGetPercentage(qwm);
}

void QProgressBarCar::SetFontSize(double size)
{
    QFBCSetFontSize(qwm,size);

}

void QProgressBarCar::SetFontName(const wchar_t *name)
{
    QFBCSetFontName(qwm,name);
}

void QProgressBarCar::SetFontColor(unsigned int colo)
{
    QFBCSetFontColor(qwm,colo);
}

void QProgressBarCar::IsShowDec(bool isShow)
{
    QFBCIsShowDec(qwm,isShow);
}

void QProgressBarCar::SetFillBrush(QBrush *pBrush)
{
    QFBCSetFillBrush(qwm,pBrush);
}
