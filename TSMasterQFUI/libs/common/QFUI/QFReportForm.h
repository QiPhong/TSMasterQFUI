
#ifndef __QFREPORTFORM_H
#define __QFREPORTFORM_H
#include "DLLImportQWND.h"
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <iterator> 


class QReportFormBrushContext
{
    public:
    unsigned char A = 0xff;
	unsigned char R = 0xC0;
	unsigned char G = 0xC0;
	unsigned char B = 0xC0;
	unsigned char A2 = 0;
	unsigned char R2 = 0;
	unsigned char G2 = 0;
	unsigned char B2 = 0;
    INT W = 80;  //矩形宽度
	int F = 0;//上边定义的值
};

typedef void (*QWRFSETFONTNAME_FUN)(QWND*, const wchar_t*);
typedef void (*QWRFSETFONTSIZE_FUN)(QWND*, int);
typedef void (*QWRFSETTEXTALGN_FUN)(QWND*, int);
typedef void (*QWRFSETTEXTALGN_VH_FUN)(QWND*, int,int);

typedef void (*QWRFSETBKBRUSH_FUN)(QWND*, QBrush*);
typedef QBrush* (*QWRFGETBKBRUSH_FUN)(QWND*);
typedef void (*QWRFINSERTTITLE_FUN)(QWND*, const wchar_t*,int,int);
typedef int (*QWRFSETTITLEHEIGHT_FUN)(QWND*,int );

typedef int (*QWRFSETRECORDERBKEX_FUN)(QWND*,int,int   //线性渐变背景
,unsigned char,unsigned char,unsigned char,unsigned char    //颜色1
,unsigned char,unsigned char,unsigned char,unsigned char    //颜色2
,int,int);                                                  //宽度和方向
typedef int (*QWRFSETRECORDERBK_FUN)(QWND*,int,int,unsigned char,unsigned char,unsigned char,unsigned char);//单色背景

typedef int (*QWRFGETTITLECOUNT_FUN)(QWND*);
typedef int (*QWRFGETRECORDERCOUNT_FUN)(QWND*);
typedef int (*QWRFSETRECORDERTEXT_FUN)(QWND*,int,int,const wchar_t*);
typedef int (*QWRFSELECTITEMINDEX_FUN)(QWND*);
typedef int (*QWRFREMOVERECORDER_FUN)(QWND*,int);
typedef int (*QWRFINSERTRECORDER_FUN)(QWND*,const wchar_t*,int);
typedef void (*QWRFISDRAG_FUN)(QWND*,bool);
typedef const wchar_t* (*__FunTypeDef(QWRFGetTitleText))(QWND* , int );
typedef int (*__FunTypeDef(QWRFGetTitleWidth))(QWND*, int);
typedef int (*__FunTypeDef(QWRFRemovTitle))(QWND*, int);
typedef int (*__FunTypeDef(QWRFSetTitle))(QWND*, const wchar_t* , INT , int );

typedef const wchar_t* (*__FunTypeDef(QWRFGetCellText))(QWND*, int, int);


class QReportForm:public DLLImportQWND
{
   
    static HMODULE m_hm;
    static QWRFISDRAG_FUN QWRFIsDrag;
    static QWRFINSERTRECORDER_FUN QWRFInsertRecorder;
    static QWRFREMOVERECORDER_FUN QWRFRemoveRecorder;
    static QWRFSELECTITEMINDEX_FUN QWRFSelectItemIndex;
    static QWRFSETRECORDERTEXT_FUN QWRFSetRecorderText;
    static QWRFGETRECORDERCOUNT_FUN QWRFGetRecorderCount;
    static QWRFGETTITLECOUNT_FUN QWRFGetTitleCount;
    static QWRFSETRECORDERBK_FUN QWRFSetRecorderBK;
    static QWRFSETRECORDERBKEX_FUN QWRFSetRecorderBKEX;
    static QWRFSETFONTNAME_FUN QWRFSetFontName;
    static QWRFSETFONTSIZE_FUN QWRFSetFontSize;
    static QWRFSETTEXTALGN_FUN  QWRFSetTextAlgn_H;
    static QWRFSETTEXTALGN_FUN  QWRFSetTextAlgn_V;
    static QWRFSETTEXTALGN_VH_FUN QWRFSetTextAlgn_VH;
    static QWRFSETBKBRUSH_FUN   QWRFSetBKBrush;
    static QWRFGETBKBRUSH_FUN   QWRFGetBKBrush;
    static QWRFINSERTTITLE_FUN QWRFInsertTitle;
    static QWRFSETTITLEHEIGHT_FUN QWRFSetTitleHeight;

    __MembersDef(QWRFGetTitleText);
    __MembersDef(QWRFGetTitleWidth);
    __MembersDef(QWRFRemovTitle);
    __MembersDef(QWRFSetTitle);
    __MembersDef(QWRFGetCellText);

public:
    int InsertRecorder(const std::wstring& w=L"",int index=-1);//插入索引0为插入到最前面，超出记录最大数无效
    int RemoveRecorder(int index);
    int SelectItemIndex();
    /**
     * ============================================================================
     * 函数名：SetRecorderText
     * 作用：设置项目文本
     * 参数1：行索引
     * 参数2：列索引
     * 参数3：欲设置的文本
     * 返回值：返回1正常，其他为失败代码
     * ============================================================================
    */
    int SetRecorderText(int iRd,int iUnit,std::wstring context);
    int GetRecorderCount()const;                                                             //获取记录总数
    int GetTitleCount()const;                                                                //获取字段总数
    /**
     * ============================================================================
     * SetRecorderBK
     * 作用：设置项目的背景
     * 参数1：行索引
     * 参数2：列索引，-1为整行设置一直画刷
     * 参数3：欲设置的背景画刷
     * 返回值：返回1正常，其他为失败代码
     * ============================================================================
    */
    int SetRecorderBK(int iRd,int iUnit,const QReportFormBrushContext& context);



    QReportForm(HDC winddc,const QRect& rf);
    virtual ~QReportForm();

    //属性设置
    void SetFontName(const wchar_t* name);
    void SetFontSize(INT size);
    void SetTextAlgn(int align);
    void SetTextAlgn(int align,int lalign);
    void SetTextAllgn(int lalign);
    void SetBKBrush(QBrush* pgb);
    const QBrush* GetBKBrush()const;

    void InsertTitle(const std::wstring& w=L"",INT wdth=80,int index=-1);

    int SetTitleHeight(int h);

    virtual int init(HMODULE hm);
    void IsIsDrag(bool drag);
    std::wstring GetTitleText(int index); //获取字段文本
    int GetTitleWidth(int index);//获取字段宽度
    int RemovTitle(int index);
    int SetTitle(const std::wstring& w, INT wdth, int index);
    const wchar_t* GetCellText(int iRd, int iUnit);
};

/*
    StringAlignmentNear   = 0,
    StringAlignmentCenter = 1,
    StringAlignmentFar    = 2
*/
#define QReportFormAlgn_Normal 0
#define QReportFormAlgn_Center 1
#define QReportFormAlgn_Far 2




























#undef __QFREPORTFORM_TYPEDEF

#endif
