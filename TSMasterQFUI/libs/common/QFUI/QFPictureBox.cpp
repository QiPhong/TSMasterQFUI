#include "QFPictureBox.h"
HMODULE QPictureBox::m_hm = NULL;
QPBLOADPICTURE QPictureBox::QPBLoadPicture = NULL;
QPBSETTRANSPARENCY QPictureBox::QPBSetTransparency = NULL;









void QPictureBox::LoadPicture(const std::wstring& path)
{
    QPBLoadPicture(qwm, path.c_str());
}
 void QPictureBox::SetTransparency(unsigned char apha)
{
    QPBSetTransparency(qwm, apha);

}

QPictureBox::QPictureBox(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{


}

QPictureBox::~QPictureBox()
{


}
int QPictureBox::init(HMODULE hm)
{

    if (!m_hm) {
        int count = 0;
        const char* fName = "QPBLoadPicture";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QPBLoadPicture = (QPBLOADPICTURE)pfun;

        fName = "QPBSetTransparency";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QPBSetTransparency = (QPBSETTRANSPARENCY)pfun;





        DLLImportQWND::init(hm);
        DebugOut("QPictureBox : import %d function", count);
        return count;
    }

    return -1;

}










