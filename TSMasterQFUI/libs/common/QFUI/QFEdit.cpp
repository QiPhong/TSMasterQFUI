#include "QFEdit.h"
#define __FUNCTINNAME_QED(name) QED##name
#define __FUNCTINNAME_QED_STR(name) "QED" #name
#define __GDefineFun_QED(name) __GDefineFun(QEdit,__QDefineType(name),name)
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
__GDefineFun_QED(QEDSetChangeEvent);


void QEdit::SetChangeEvent(QEDIT_CHANGE_EVENT even, int param)
{
    return __FUNCTINNAME_QED(SetChangeEvent)(qwm,even,param);
}

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

        fName = "QEDSetText";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEDSetText = (QEDSETTEXT)pfun;

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

        fName = __FUNCTINNAME_QED_STR(GetText);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QED(GetText), pfun);

        fName = __FUNCTINNAME_QED_STR(SetChangeEvent);
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QED(SetChangeEvent), pfun);


        m_hm = hm;
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