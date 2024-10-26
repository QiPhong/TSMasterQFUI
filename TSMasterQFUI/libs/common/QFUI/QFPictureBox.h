#ifndef __QFPICTUREBOX_H
#define __QFPICTUREBOX_H
#include "DLLImportQWND.h"
typedef void (*QPBLOADPICTURE)(QWND*,const wchar_t* );
typedef void (*QPBSETTRANSPARENCY)(QWND*,unsigned char);


class QPictureBox:public DLLImportQWND
{

    static HMODULE m_hm ;
    public:
    QPictureBox(HDC winddc,const QRect& rf);
    virtual ~QPictureBox();
    void LoadPicture(const std::wstring& path);
    void SetTransparency(unsigned char apha);
    virtual int init(HMODULE hm);


    public:
    static QPBLOADPICTURE QPBLoadPicture;
    static QPBSETTRANSPARENCY QPBSetTransparency;
};















#endif