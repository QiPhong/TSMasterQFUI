#include "QWMange.h"
HMODULE  QWMange::m_hm = NULL;
ADD_AND_DELETECTRL  QWMange::AttachCtrl_FUN = NULL;
ADD_AND_DELETECTRL  QWMange::RemoveCtrl_FUN = NULL;
GETBKBRUSH  QWMange::GetBKBrush_FUN = NULL;
SETSIZECHANGELISTEN  QWMange::SetSizeChangeListen_FUN = NULL;
SETSIZECHANGELISTEN  QWMange::SetSizeChangedListen_FUN = NULL;
SETBKQWMBRUSH QWMange::SetBKBrush_FUN = NULL;
QWMSETBKIMAGE QWMange::QWMSetBKImage = NULL;
QWMSETTRANSPARENCY QWMange::QWMSetTransparency = NULL;
QWMCLEARBKIMAGE QWMange::QWMClearBKImage = NULL;


int QWMange::init(HMODULE hm)
{

    if (!m_hm) {
        int count = 0;
        m_hm = hm;
        const char* fName = "QWMAttachCtrl";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        AttachCtrl_FUN = (ADD_AND_DELETECTRL)pfun;

        fName = "QWMRemoveCtrl";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        RemoveCtrl_FUN = (ADD_AND_DELETECTRL)pfun;

        fName = "QWMGetBKBrush";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        GetBKBrush_FUN = (GETBKBRUSH)pfun;

        fName = "QWMSetSizeChangeListen";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        SetSizeChangeListen_FUN = (SETSIZECHANGELISTEN)pfun;
        fName = "QWMSetSizeChangedListen";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        SetSizeChangedListen_FUN = (SETSIZECHANGELISTEN)pfun;

        fName = "QWMSetBKBrush";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        SetBKBrush_FUN = (SETBKQWMBRUSH)pfun;

        //…Ë÷√±≥æ∞Õº∆¨≤ø∑÷*********************************************
        fName = "QWMSetBKImage";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWMSetBKImage = (QWMSETBKIMAGE)pfun;

        fName = "QWMSetTransparency";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWMSetTransparency = (QWMSETTRANSPARENCY)pfun;

        fName = "QWMClearBKImage";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWMClearBKImage = (QWMCLEARBKIMAGE)pfun;
        //**********************************************************


        DebugOut("QWMange : import %d function", count);
        DLLImportQWND::init(hm);
        return count;
    }

    return -1;
}
