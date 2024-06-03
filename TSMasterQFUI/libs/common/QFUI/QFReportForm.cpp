#include "QFReportForm.h"
void QReportForm::IsIsDrag(bool drag)
{

    QWRFIsDrag(qwm, drag);
}
int QReportForm::InsertRecorder(const std::wstring& w, int index)
{
    return QWRFInsertRecorder(qwm, w.c_str(), index);
}
int QReportForm::RemoveRecorder(int index)
{
    return QWRFRemoveRecorder(qwm, index);

}
int QReportForm::SelectItemIndex()
{
    return QWRFSelectItemIndex(qwm);
}
int QReportForm::SetRecorderText(int iRd, int iUnit, std::wstring context)
{
    return QWRFSetRecorderText(qwm, iRd, iUnit, context.c_str());
}
int QReportForm::GetRecorderCount()const
{
    return QWRFGetRecorderCount(qwm);
}
int QReportForm::GetTitleCount()const
{
    return QWRFGetTitleCount(qwm);
}
int QReportForm::SetRecorderBK(int iRd, int iUnit, const QReportFormBrushContext& context)
{
    if (0 == context.F) {
        return QWRFSetRecorderBK(qwm, iRd, iUnit, context.A, context.R, context.G, context.B);
    }
    return QWRFSetRecorderBKEX(qwm, iRd, iUnit, context.A, context.R, context.G, context.B, context.A2, context.R2, context.G2, context.B2, context.W, context.F);
}


int QReportForm::SetTitleHeight(int h)
{
    return QWRFSetTitleHeight(qwm, h);
}

void QReportForm::InsertTitle(const std::wstring& w, INT wdth, int index)
{

    QWRFInsertTitle(qwm, w.c_str(), wdth, index);
}

QReportForm::QReportForm(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}
QReportForm::~QReportForm()
{


}

// Ù–‘…Ë÷√


void QReportForm::SetFontName(const wchar_t* name)
{
    QWRFSetFontName(qwm, name);
}
void QReportForm::SetFontSize(INT size)
{
    QWRFSetFontSize(qwm, size);
}
void QReportForm::SetTextAlgn(int align)
{
    if (align < 0 || align > 2)align = 0;
    QWRFSetTextAlgn_H(qwm, align);
}
void QReportForm::SetTextAlgn(int align, int lalign)
{
    if (align < 0 || align > 2)align = 0;
    if (lalign < 0 || lalign > 2)lalign = 0;
    QWRFSetTextAlgn_VH(qwm, align, lalign);
}
void QReportForm::SetTextAllgn(int lalign)
{
    if (lalign < 0 || lalign > 2)lalign = 0;
    QWRFSetTextAlgn_V(qwm, lalign);
}

void QReportForm::SetBKBrush(QBrush* pgb)
{
    QWRFSetBKBrush(qwm, pgb);
}
const QBrush* QReportForm::GetBKBrush()const
{
    return QWRFGetBKBrush(qwm);
}


HMODULE QReportForm::m_hm = NULL;
QWRFISDRAG_FUN QReportForm::QWRFIsDrag = NULL;
QWRFINSERTRECORDER_FUN QReportForm::QWRFInsertRecorder = NULL;
QWRFREMOVERECORDER_FUN QReportForm::QWRFRemoveRecorder = NULL;
QWRFSELECTITEMINDEX_FUN QReportForm::QWRFSelectItemIndex = NULL;
QWRFSETRECORDERTEXT_FUN QReportForm::QWRFSetRecorderText = NULL;
QWRFGETRECORDERCOUNT_FUN QReportForm::QWRFGetRecorderCount = NULL;
QWRFGETTITLECOUNT_FUN QReportForm::QWRFGetTitleCount = NULL;
QWRFSETRECORDERBK_FUN QReportForm::QWRFSetRecorderBK = NULL;
QWRFSETRECORDERBKEX_FUN QReportForm::QWRFSetRecorderBKEX = NULL;
QWRFSETFONTNAME_FUN QReportForm::QWRFSetFontName = NULL;
QWRFSETFONTSIZE_FUN QReportForm::QWRFSetFontSize = NULL;
QWRFSETTEXTALGN_FUN  QReportForm::QWRFSetTextAlgn_H = NULL;
QWRFSETTEXTALGN_FUN  QReportForm::QWRFSetTextAlgn_V = NULL;
QWRFSETTEXTALGN_VH_FUN QReportForm::QWRFSetTextAlgn_VH = NULL;
QWRFSETBKBRUSH_FUN   QReportForm::QWRFSetBKBrush = NULL;
QWRFGETBKBRUSH_FUN   QReportForm::QWRFGetBKBrush = NULL;
QWRFINSERTTITLE_FUN QReportForm::QWRFInsertTitle = NULL;
QWRFSETTITLEHEIGHT_FUN QReportForm::QWRFSetTitleHeight = NULL;





int QReportForm::init(HMODULE hm)
{
    if (!m_hm) {
        int count = 0;
        const char* fName = "QWRFIsDrag";
        void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFIsDrag = (QWRFISDRAG_FUN)pfun;

        fName = "QWRFInsertRecorder";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFInsertRecorder = (QWRFINSERTRECORDER_FUN)pfun;

        fName = "QWRFRemoveRecorder";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFRemoveRecorder = (QWRFREMOVERECORDER_FUN)pfun;

        fName = "QWRFSelectItemIndex";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSelectItemIndex = (QWRFSELECTITEMINDEX_FUN)pfun;

        fName = "QWRFSetRecorderText";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetRecorderText = (QWRFSETRECORDERTEXT_FUN)pfun;

        fName = "QWRFGetRecorderCount";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFGetRecorderCount = (QWRFGETRECORDERCOUNT_FUN)pfun;

        fName = "QWRFGetTitleCount";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFGetTitleCount = (QWRFGETTITLECOUNT_FUN)pfun;

        fName = "?QWRFSetRecorderBK@@YAHPAVQReportForm@@HHEEEE@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetRecorderBK = (QWRFSETRECORDERBK_FUN)pfun;

        fName = "?QWRFSetRecorderBK@@YAHPAVQReportForm@@HHEEEEEEEEHH@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetRecorderBKEX = (QWRFSETRECORDERBKEX_FUN)pfun;

        fName = "QWRFSetFontName";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetFontName = (QWRFSETFONTNAME_FUN)pfun;

        fName = "QWRFSetFontSize";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetFontSize = (QWRFSETFONTSIZE_FUN)pfun;

        fName = "?QWRFSetTextAlgn@@YAXPAVQReportForm@@H@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetTextAlgn_H = (QWRFSETTEXTALGN_FUN)pfun;

        fName = "?QWRFSetTextVAlgn@@YAXPAVQReportForm@@H@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetTextAlgn_V = (QWRFSETTEXTALGN_FUN)pfun;

        fName = "?QWRFSetTextAlgn@@YAXPAVQReportForm@@HH@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetTextAlgn_VH = (QWRFSETTEXTALGN_VH_FUN)pfun;

        fName = "?QWRFSetBKBrush@@YAXPAVQReportForm@@PAVBrush@Gdiplus@@@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetBKBrush = (QWRFSETBKBRUSH_FUN)pfun;

        fName = "?QWRFGetBKBrush@@YAPAVBrush@Gdiplus@@PAVQReportForm@@@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFGetBKBrush = (QWRFGETBKBRUSH_FUN)pfun;

        fName = "?QWRFInsertTitle@@YAXPAVQReportForm@@PB_WHH@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFInsertTitle = (QWRFINSERTTITLE_FUN)pfun;

        fName = "?QWRFSetTitleHeight@@YAHPAVQReportForm@@H@Z";
        pfun = QEXPORTFUNC::QExportFunction(hm, fName);
        if (pfun)++count;
        QWRFSetTitleHeight = (QWRFSETTITLEHEIGHT_FUN)pfun;



        DLLImportQWND::init(hm);
        DebugOut("QReportForm :import %d function", count);
        return count;
    }

    return -1;
}