#include "QFEdit.h"
HMODULE QEdit::m_hm;
QEDSETBKIMAGETRANSPARENCY QEdit::QEDSetBKImageTransparency;
QEDLOADPICTURE QEdit::QEDLoadPicture;
QEDSETBKBRUSH QEdit::QEDSetBKBrush;
QEDSETTEXT QEdit::QEDSetText;
QEDSETTEXTA QEdit::QEDSetTextA;
QEDGETTEXT QEdit::QEDGetText;
QEDSETFONTNAME QEdit::QEDSetFontName;
QEDSETFONTSIZE QEdit::QEDSetFontSize;
QEDSETFONTBRUSH QEdit::QEDSetFontBrush;



int QEdit::init(HMODULE hm)
{

    if (!m_hm) {
        int count = 0;
        const char* fName = "QEDSetBKImageTransparency";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetBKImageTransparency = (QEDSETBKIMAGETRANSPARENCY)pfun;

        fName = "QEDLoadPicture";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDLoadPicture = (QEDLOADPICTURE)pfun;

        fName = "QEDSetBKBrush";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetBKBrush = (QEDSETBKBRUSH)pfun;

        fName = "QEDSetTextA";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetTextA = (QEDSETTEXTA)pfun;

        fName = "QEDSetFontName";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetFontName = (QEDSETFONTNAME)pfun;


        fName = "QEDSetFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetFontSize = (QEDSETFONTSIZE)pfun;

        fName = "QEDSetFontBrush";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetFontBrush = (QEDSETFONTBRUSH)pfun;



        DLLImportQWND::init(hm);
        DebugOut("QEdit : import %d function", count);
        return count;
    }

    return -1;

}
QEdit::QEdit(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}
QEdit::~QEdit()
{


}