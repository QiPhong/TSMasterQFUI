#ifndef __QFPROGRESSBARCAR_H
#define __QFPROGRESSBARCAR_H

#include "DLLImportQWND.h"

#include <functional>
class QProgressBarCar:public DLLImportQWND
{
    //C++17的新特性用不上，内敛变量
    static HMODULE m_hm ;
    static std::function<void(QWND*,double)> QFBCSetPercentage;
    static std::function<double(QWND*)> QFBCGetPercentage;
    static std::function<void(QWND*,double)> QFBCSetFontSize;
    static std::function<void(QWND*,const wchar_t*)> QFBCSetFontName;
    static std::function<void(QWND*, unsigned int)> QFBCSetFontColor;
    static std::function<void(QWND*,bool)> QFBCIsShowDec;
    static std::function<void(QWND*,QBrush*)> QFBCSetFillBrush;

    public:
    QProgressBarCar(HDC winddc,const QRect& rf);
    virtual ~QProgressBarCar();
    virtual int init(HMODULE hm);
    virtual void SetPercentage(double rat);
    virtual double GetPercentage();
    virtual void SetFontSize(double size);
    virtual void SetFontName(const wchar_t* name);
    virtual void SetFontColor(unsigned int colo);
    virtual void IsShowDec(bool isShow);
    virtual void SetFillBrush(QBrush* pBrush);
    public:

};























#endif