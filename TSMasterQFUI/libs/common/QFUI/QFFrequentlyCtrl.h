#pragma once
#include "DLLImportQWND.h"
#include <windows.h>
#include <string>
#include "QFbutton.h"
#include "QFUIBase.h"

#define ____EXTERN_FFUN(flag,name) flag##name
#define __EXTERN_FFUN(flag,name) ____EXTERN_FFUN(flag,name)
/**
* QDrawer 抽屉控件
* 
* 
* 
*/
//关联的事件
//项目被选择时事件函数，参数1：为选择时的项目索引；参数2：事件选择时的子项目索引
typedef int (*QDRAWERSELECT)(int, int);
typedef void (*QDWSetFontName_Type)(QWND* p, const wchar_t* name);
typedef void (*QDWSetFontSize_Type)(QWND* p, float size);
typedef int (*QDWInsertDrawer_Type)(QWND* p, int index);
typedef int (*QDWInsertSubObject_Type)(QWND* p, int iDrawer, int iObj);
typedef int (*QDWRemoveSubObject_Type)(QWND* p, int iDrawer, int iObj);
typedef int (*QDWRemoveDrawer_Type)(QWND* p, int index);
typedef int (*QDWGetDrawerCount_Type)(QWND* p);
typedef int (*QDWGetSubObjectCount_Type)(QWND* p, int index);
typedef int (*QDWSetDrawerName_Type)(QWND* p, int index, const wchar_t* name);
typedef int (*QDWSetDrawerFontColor_Type)(QWND* p, int index, int color);
typedef int (*QDWSetDrawerBKColor_Type)(QWND* p, int index, int color);
typedef int (*QDWOpenDrawer_Type)(QWND* p, int index);
typedef int (*QDWCloseDrawer_Type)(QWND* p, int index);
typedef int (*QDWSetSubObjectName_Type)(QWND* p, int iDrawer, int iObj, const wchar_t* name);
typedef int (*QDWSetSubObjectFontColor_Type)(QWND* p, int iDrawer, int iObj, int color);
typedef int (*QDWSetSubObjectBKColor_Type)(QWND* p, int iDrawer, int iObj, int color);
typedef int (*QDWSetSelectEvent_Type)(QWND* p, QDRAWERSELECT fun);
typedef int (*QDWGetSubObjectName_Type)(QWND* p, int iDrawer, int iObj, wchar_t* pName, int bl);
typedef int (*QDWGetDrawerName_Type)(QWND* p, int iDrawer, wchar_t* pName, int bl);
#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __QDefineType(name) name##_Type
#define __MembersDef(name) __DefineFun(__QDefineType(name),name)
#define __FunTypeDef(fName) fName##_Type
#define __FunTypeDef2(a) __FunTypeDef(a)

#define __QDRAWER__
class QDrawer :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QDWSetFontName);
    __MembersDef(QDWSetFontSize);
    __MembersDef(QDWInsertDrawer);
    __MembersDef(QDWInsertSubObject);
    __MembersDef(QDWRemoveSubObject);
    __MembersDef(QDWRemoveDrawer);
    __MembersDef(QDWGetDrawerCount);

    __MembersDef(QDWGetSubObjectCount);
    __MembersDef(QDWSetDrawerName);
    __MembersDef(QDWSetDrawerFontColor);
    __MembersDef(QDWSetDrawerBKColor);
    __MembersDef(QDWOpenDrawer);
    __MembersDef(QDWCloseDrawer);
    __MembersDef(QDWSetSubObjectName);

    __MembersDef(QDWSetSubObjectFontColor);
    __MembersDef(QDWSetSubObjectBKColor);
    __MembersDef(QDWSetSelectEvent);
    __MembersDef(QDWGetSubObjectName);
    __MembersDef(QDWGetDrawerName);

public:
    QDrawer(HDC winddc, const QRect& rf);
    virtual ~QDrawer();
    //用户接口
    void SetFontName(const wchar_t* name);
    void SetFontSize(float size);
    int InsertDrawer(int index);
    int InsertSubObject(int iDrawer, int iObj);
    int RemoveSubObject(int iDrawer, int iObj);
    int RemoveDrawer(int index);
    int GetDrawerCount();
    int GetSubObjectCount(int index);
    int SetDrawerName(int index, const wchar_t* name);
    int SetDrawerFontColor(int index, int color);
    int SetDrawerBKColor(int index, int color);
    int OpenDrawer(int index);
    int CloseDrawer(int index);
    int SetSubObjectName(int iDrawer, int iObj, const wchar_t* name);
    int SetSubObjectFontColor(int iDrawer, int iObj, int color);
    int SetSubObjectBKColor(int iDrawer, int iObj, int color);
    int SetSelectEvent(QDRAWERSELECT fun);

    std::wstring GetSubObjectName(int iDrawer, int iObj);
    std::wstring GetDrawerName(int iDrawer);

    virtual int init(HMODULE hm);

};




#define __QHOSTCTRL__
typedef int (*QHCSetParasiticCtrl_Type)(QWND* p, QWND* ctrl, QWND** oldCtrl);
typedef QWND* (*__FunTypeDef(QHCGetParasiticCtrl))(QWND* p);

class QHost :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QHCSetParasiticCtrl);
    __MembersDef(QHCGetParasiticCtrl);

public:
    QHost(HDC winddc, const QRect& rf);
    virtual ~QHost();
    int SetParasiticCtrl(DLLImportQWND* ctrl, QWND** oldCtrl = nullptr);
    QWND* GetParasiticCtrl();
    int init(HMODULE hm);
    //返回-1 为控件不能直接为宿主控件

};

#define __QHLAYOUT__
typedef int (*QHLInsertCtrl_Type)(QWND* , QWND* , unsigned int , int );
typedef int (*QHLRemoveCtrl_Type)(QWND*, int);
typedef int (*QHLGetCtrlCount_Type)(QWND*);
typedef QWND* (*__FunTypeDef(QHLGetCtrl))(QWND* p,  int index);
typedef unsigned int (*__FunTypeDef(QHLGetCtrlWeight))(QWND* p, int index);
class QHLayout :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QHLInsertCtrl);
    __MembersDef(QHLRemoveCtrl);
    __MembersDef(QHLGetCtrlCount);
    __MembersDef(QHLGetCtrl);
    __MembersDef(QHLGetCtrlWeight);

public:
    QHLayout(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    int InsertCtrl(DLLImportQWND* ctrl, unsigned int weight = 0, int index = -1);//插入控件：weight：控件比例权重；index：插入的位置：-1为尾插
    int RemoveCtrl(int index);//移除控件
    int GetCtrlCount();//取控件数
    QWND* GetCtrl(int index);
    unsigned int GetCtrlWeight(int index);
};
#define __QVLAYOUT__
typedef int (*QVLInsertCtrl_Type)(QWND*, QWND*, unsigned int, int);
typedef int (*QVLRemoveCtrl_Type)(QWND*, int);
typedef int (*QVLGetCtrlCount_Type)(QWND*);
typedef QWND* (*__FunTypeDef(QVLGetCtrl))(QWND* p, int index);
typedef unsigned int (*__FunTypeDef(QVLGetCtrlWeight))(QWND* p, int index);
class QVLayout :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QVLInsertCtrl);
    __MembersDef(QVLRemoveCtrl);
    __MembersDef(QVLGetCtrlCount);
    __MembersDef(QVLGetCtrl);
    __MembersDef(QVLGetCtrlWeight);
public:
    QVLayout(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    int InsertCtrl(DLLImportQWND* ctrl, unsigned int weight = 0, int index = -1);//插入控件：weight：控件比例权重；index：插入的位置：-1为尾插
    int RemoveCtrl(int index);//移除控件
    int GetCtrlCount();//取控件数
    QWND* GetCtrl(int index);
    unsigned int GetCtrlWeight(int index);
};
#define __QTLAYOUT__
typedef int (*__FunTypeDef(QTLSetCtrl))(QWND*, QWND*);
typedef int (*__FunTypeDef(QTLRemoveCtrl))(QWND*);
typedef QWND* (*__FunTypeDef(QTLGetCtrl))(QWND*);

class QTLayout :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QTLSetCtrl);
    __MembersDef(QTLRemoveCtrl);
    __MembersDef(QTLGetCtrl);

public:
    QTLayout(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    int SetCtrl(QWND* ctrl);//插入控件：weight：控件比例权重；
    int RemoveCtrl();//移除控件
    QWND* GetCtrl();
};



#define __QSTATICTEXT__
typedef void (*QSTTSetText_Type)(QWND* p, const wchar_t* t);
typedef void (*QSTTSetFontName_Type)(QWND* p, const wchar_t* t);
typedef void (*QSTTSetFontSize_Type)(QWND* p, double);
typedef void (*QSTTSetFontColor_Type)(QWND* p, unsigned int);
typedef void (*QSTTSetBKColor_Type)(QWND* p, unsigned int);
typedef const wchar_t* (*__FunTypeDef(QSTTGetText))(QWND* p);

class QStaticText :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QSTTSetText);
    __MembersDef(QSTTSetFontName);
    __MembersDef(QSTTSetFontSize);
    __MembersDef(QSTTSetFontColor);
    __MembersDef(QSTTSetBKColor);
    __MembersDef(QSTTGetText);

public:
    QStaticText(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    void SetText(const wchar_t* t);
    void SetFontName(const wchar_t* t);
    void SetFontSize(double size);
    void SetFontColor(unsigned int color);
    void SetBKColor(unsigned int color);
    std::wstring GetText();

};


#define __QCTRLTOOLBOX__
typedef int (*QCTBInsertCtrl_Type)(QWND*, QWND*, unsigned int, int);
typedef int (*QCTBRemoveCtrl_Type)(QWND*, int);
typedef int (*QCTBGetCtrlCount_Type)(QWND*);
typedef int (*__FunTypeDef(QCTBInsertAttributeCtrl))(QWND* p, QWND* w, int index);
typedef int (*__FunTypeDef(QCTBRemoveAttributeCtrl))(QWND* p, int index);
typedef void (*__FunTypeDef(QCTBClearAttributeCtrl))(QWND* p);
typedef void (*__FunTypeDef(QCTBSetFileButtonEvent))(QWND* p, QFBUTTONCLICK en, int index);

class QCtrlToolbox :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QCTBInsertCtrl);
    __MembersDef(QCTBRemoveCtrl);
    __MembersDef(QCTBGetCtrlCount);
    __MembersDef(QCTBInsertAttributeCtrl);
    __MembersDef(QCTBRemoveAttributeCtrl);
    __MembersDef(QCTBClearAttributeCtrl);
    __MembersDef(QCTBSetFileButtonEvent);

public:
    QCtrlToolbox(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    int InsertCtrl(DLLImportQWND* ctrl, unsigned int weight = 0, int index = -1);//插入控件：weight：控件比例权重；index：插入的位置：-1为尾插
    int RemoveCtrl(int index);//移除控件
    int GetCtrlCount();//取控件数
    int InsertAttributeCtrl(DLLImportQWND* w, int index = -1);       //关联一个属性控件
    int RemoveAttributeCtrl(int index);       //移除一个属性控件
    void ClearAttributeCtrl();       //移除一个属性控件
    void SetFileButtonEvent(QFBUTTONCLICK en, int index = 0);
};


#define __QEDITORWIN__
typedef int (*QEDITORWIN_LBDOWN)(int, int, int);
typedef int (*QEDITORWIN_PLACE_CTRL)(int, int, int, int, int);
typedef void (*QEDITORWIN_DELETE_CTRL)(int);
typedef void (*QEDITORWIN_SELECT_CTRL)(int);
typedef int (*QEWSetLButtonEvent_Type)(QWND*, QEDITORWIN_LBDOWN);
typedef void (*QEWAttachCtrl_Type)(QWND*, QWND*);
typedef void (*QEWRemoveCtrl_Type)(QWND*, QWND*);
typedef int (*QEWSetPlaceCtrlEvent_Type)(QWND*, QEDITORWIN_PLACE_CTRL);
typedef int (*__FunTypeDef(QEWSetDeleteCtrlEvent))(QWND* p, QEDITORWIN_DELETE_CTRL);
typedef int (*__FunTypeDef(QEWSetSelectCtrlEvent))(QWND* p, QEDITORWIN_DELETE_CTRL);

class QEditorWin :public DLLImportQWND
{
    static HMODULE m_hm;
    __MembersDef(QEWSetLButtonEvent);
    __MembersDef(QEWAttachCtrl);
    __MembersDef(QEWRemoveCtrl);
    __MembersDef(QEWSetPlaceCtrlEvent);
    __MembersDef(QEWSetDeleteCtrlEvent);
    __MembersDef(QEWSetSelectCtrlEvent);
public:
    QEditorWin(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    int SetLButtonEvent(QEDITORWIN_LBDOWN ent);
    void AttachCtrl(DLLImportQWND* w);       //关联一个控件
    void RemoveCtrl(DLLImportQWND* w);       //移除一个控件
    int SetPlaceCtrlEvent(QEDITORWIN_PLACE_CTRL ent);
    int SetDeleteCtrlEvent(QEDITORWIN_DELETE_CTRL ent);
    int SetSelectCtrlEvent(QEDITORWIN_SELECT_CTRL ent);
};

#define __QSWITCH__
typedef int (*QSWITCH_STATE_CHANGE)(int);
typedef int (*__FunTypeDef2(__EXTERN_FFUN(QSW, SetStateChangeEvent)))(QWND* p, QSWITCH_STATE_CHANGE ev);
typedef int (*__FunTypeDef2(__EXTERN_FFUN(QSW, GetState)))(QWND* p);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(QSW, SetState)))(QWND* p,int);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(QSW, IsMutex)))(QWND* p, bool);

class QSwitch :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN(QSW, SetStateChangeEvent));
    __MembersDef(__EXTERN_FFUN(QSW, GetState));
    __MembersDef(__EXTERN_FFUN(QSW, SetState));
    __MembersDef(__EXTERN_FFUN(QSW, IsMutex));

public:
    QSwitch(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    //设置状态改变时的回调函数
    //typedef int (*QSWITCH_STATE_CHANGE)(int);
    int SetStateChangeEvent(QSWITCH_STATE_CHANGE ev);
    //获得当前状态：0为未选中；1为选中
    int GetState()const;
    //设置当前的状态：0为未选中；1为选中
    void SetState(int state);
    //是否互斥
    //如果真则在同一个分组内的QSwitch只能同时选中一个
    void IsMutex(bool im);
};

#define __QSLIDER__
typedef int (*QSLIDER_VALUE_CHANGE)(int, float);
#define __QFLAG QSL
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetMinValue)))(QWND* p, float);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetMaxValue)))(QWND* p, float);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetCurrentValue)))(QWND* p, float);
typedef unsigned int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetRailColor)))(QWND* p, unsigned int);
typedef float (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetRailRatio)))(QWND* p, float);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, IsSegmentation)))(QWND* p, bool);
typedef int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, ClearSegmArr)))(QWND* p);
typedef int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, AddSegmVuale)))(QWND* p,float);
typedef int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, RemoveSegmVuale)))(QWND* p, float);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetDirection)))(QWND* p,unsigned char);
typedef QDWORD (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetValueChangeEvent)))(QWND* p, QSLIDER_VALUE_CHANGE);
typedef unsigned int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetColor)))(QWND* p, unsigned int);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetSegmValue)))(QWND* p, float* ,int);

class QSlider :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetMinValue));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetMaxValue));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetCurrentValue));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetRailColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetRailRatio));
    __MembersDef(__EXTERN_FFUN(__QFLAG, IsSegmentation));
    __MembersDef(__EXTERN_FFUN(__QFLAG, ClearSegmArr));
    __MembersDef(__EXTERN_FFUN(__QFLAG, AddSegmVuale));
    __MembersDef(__EXTERN_FFUN(__QFLAG, RemoveSegmVuale));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetDirection));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetValueChangeEvent));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetSegmValue));

public:
    QSlider(HDC winddc, const QRect& rf);
    int init(HMODULE hm);

    //设置滑块的最小值
    void SetMinValue(float v);
    //设置滑块的最大值
    void SetMaxValue(float v);
    //设置滑块的当前值
    void SetCurrentValue(float v);
    //设置滑块的轨道颜色
    unsigned int SetRailColor(unsigned int color);
    //设置滑块的轨道比例
    float SetRailRatio(float ato);
    //是否分段
    void IsSegmentation(bool b);
    //清空分段数组
    int ClearSegmArr();
    //增加分段值
    int AddSegmVuale(float v);
    //移除分段值
    int RemoveSegmVuale(float v);
    //设置方向：0为水平，1为垂直
    void SetDirection(unsigned char d);
    //设置滑动回调函数
    //typedef int (*QSLIDER_VALUE_CHANGE)(int, float);
    QDWORD SetValueChangeEvent(QSLIDER_VALUE_CHANGE ev);
    //设置颜色
    unsigned int SetColor(unsigned int color);
    //获得当前分段值
    //参数1：存储分段值的数组指针
    //参数2：空间长度
    //返回值：当前控件分段值的总数
    int GetSegmValue(float* arr, int bufL);
};


#define __QPROGRESS__

#define __QFLAG QPRO
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetDirection)))(QWND* p, unsigned char);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetStyle)))(QWND* p, unsigned int);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetCurrentValue)))(QWND* p,float);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetLineTypeProgressColor)))(QWND* p, unsigned int);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetDecimalPlaces)))(QWND* p, unsigned char);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetRingProgressColor)))(QWND* p, unsigned int, unsigned int);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetRingProgressThickness)))(QWND* p, float);
typedef unsigned int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetStyle)))(QWND* p);

class QProgress :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetDirection));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetStyle));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetCurrentValue));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetLineTypeProgressColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetDecimalPlaces));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetRingProgressColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetRingProgressThickness));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetStyle));
public:
    QProgress(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
    //设置进度条方向
    void SetDirection(unsigned char d);
    //设置进度条样式
    void SetStyle(unsigned int style);
    //设置当前值
    void SetCurrentValue(float v);
    //设置线型进度条的颜色
    void SetLineTypeProgressColor(unsigned int color);
    //设置小数显示的位数
    void SetDecimalPlaces(unsigned char dp);
    //设置环形进度条的颜色
    void SetRingProgressColor(unsigned int color1, unsigned int color2);
    //设置圆环宽度
    void SetRingProgressThickness(float thickness);
    //获得进度条样式
    unsigned int GetStyle();
};


//按钮2
#define __QBUTTON__
#define __EXTERN_FFUN_QB2(name) QB2##name
#define __FunTypeDef_QB2(fName) fName##_Type
//typedef const wchar_t* (*__FunTypeDef(__EXTERN_FFUN(QB2,GetText)))(QWND* p);
typedef const wchar_t* (*__FunTypeDef2(__EXTERN_FFUN_QB2(GetText)))(QWND* p);
typedef void (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetText)))(QWND* p,const wchar_t*);
typedef void (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetClickEvent)))(QWND* p, QFBUTTONCLICK);
typedef float (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetMargin)))(QWND* p, float);
typedef unsigned int (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetBKColor)))(QWND* p, unsigned int);
typedef unsigned char (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetPicType)))(QWND* p, unsigned char);
typedef int (*__FunTypeDef2(__EXTERN_FFUN_QB2(LoadPicture)))(QWND* p, const wchar_t*);
typedef const wchar_t* (*__FunTypeDef2(__EXTERN_FFUN_QB2(GetPicturePath)))(QWND* p);
typedef float (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetXRadius)))(QWND* p, float);
typedef float (*__FunTypeDef2(__EXTERN_FFUN_QB2(SetYRadius)))(QWND* p, float);
class QButton2 :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN_QB2(GetText));
    __MembersDef(__EXTERN_FFUN_QB2(SetText));
    __MembersDef(__EXTERN_FFUN_QB2(SetClickEvent));
    __MembersDef(__EXTERN_FFUN_QB2(SetMargin));
    __MembersDef(__EXTERN_FFUN_QB2(SetBKColor));
    __MembersDef(__EXTERN_FFUN_QB2(SetPicType));
    __MembersDef(__EXTERN_FFUN_QB2(LoadPicture));
    __MembersDef(__EXTERN_FFUN_QB2(GetPicturePath));
    __MembersDef(__EXTERN_FFUN_QB2(SetXRadius));
    __MembersDef(__EXTERN_FFUN_QB2(SetYRadius));
public:
    QButton2(HDC winddc, const QRect& rf);
    //用户接口
    std::wstring GetText();
    void SetText(const wchar_t* t);
    void SetClickEvent(QFBUTTONCLICK fun);
    float SetMargin(float margin);
    unsigned int SetBKColor(unsigned int color);
    unsigned char SetPicType(unsigned char type);
    int LoadPicture(const wchar_t* path);
    std::wstring GetPicturePath()const;
    float SetXRadius(float rx);
    float SetYRadius(float ry);

    int init(HMODULE hm);
};


//颜色调节框
#define __QCOLORBOX__
#define __QFLAG QCOLORB
typedef int (*QCOLORBOX_CHANGE)(QPOINTER, unsigned int);
typedef unsigned int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetColor)))(QWND* p);
typedef unsigned int (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetColor)))(QWND* p, unsigned int);
typedef QCOLORBOX_CHANGE (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetColorChangeEvent)))(QWND* p, QCOLORBOX_CHANGE);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight)))(QWND* p, int);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth)))(QWND* p, int);
class QColorBox :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetColorChangeEvent));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth));
public:
    QColorBox(HDC winddc, const QRect& rf);
    int init(HMODULE hm);

public:
    //用户接口
    //取当前颜色
    unsigned int GetColor();
    //设置当前颜色，返回设置前的颜色
    unsigned int SetColor(unsigned int color);
    //设置颜色改变时触发的事件函数
    QCOLORBOX_CHANGE SetColorChangeEvent(QCOLORBOX_CHANGE ev);
    //设置弹框的高度
    void SetPopDialogHeight(int h);
    //设置弹框的宽度
    void SetPopDialogWidth(int w);
};

//下拉列表框
#define __QSELECT__
#define __QFLAG QSELECT
typedef int (*QSELECT_SELECTCHANGE)(QPOINTER, int);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight)))(QWND* p, int);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth)))(QWND* p, int);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, InsertItem)))(QWND* p, const wchar_t*, int);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, RemoveItem)))(QWND* p,int);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetButtonRatio)))(QWND* p, float);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetItemHeight)))(QWND* p, float);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetItemFontName)))(QWND* p, const wchar_t*);
typedef void(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetItemFontSize)))(QWND* p, float);
typedef const wchar_t* (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetSelectedText)))(QWND* p);
typedef const wchar_t* (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetItemText)))(QWND* p, int);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetItemBKColor)))(QWND* p, int, unsigned int, unsigned int, unsigned char);
typedef void (*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetItemFontColor)))(QWND* p, int, unsigned int, unsigned int, unsigned char);
typedef QSELECT_SELECTCHANGE(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetSelectChangeEvent)))(QWND* p, QSELECT_SELECTCHANGE);
typedef size_t(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetItemCount)))(QWND* p);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, SetCurrentItem)))(QWND* p,int);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetIndex)))(QWND* p);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetItemFontColor)))(QWND* p, int, unsigned char*, unsigned int*, unsigned int*);
typedef int(*__FunTypeDef2(__EXTERN_FFUN(__QFLAG, GetItemBKColor)))(QWND* p, int, unsigned char*, unsigned int*, unsigned int*);

class QSelect :public QCtrlBaseD2DIPD
{
    static HMODULE m_hm;
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth));
    __MembersDef(__EXTERN_FFUN(__QFLAG, InsertItem));
    __MembersDef(__EXTERN_FFUN(__QFLAG, RemoveItem));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetButtonRatio));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetItemHeight));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetItemFontName));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetItemFontSize));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetSelectedText));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetItemText));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetItemBKColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetItemFontColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetSelectChangeEvent));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetItemCount));
    __MembersDef(__EXTERN_FFUN(__QFLAG, SetCurrentItem));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetIndex));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetItemFontColor));
    __MembersDef(__EXTERN_FFUN(__QFLAG, GetItemBKColor));

public:
    QSelect(HDC winddc, const QRect& rf);
    int init(HMODULE hm);
public:
    //设置弹框高度
    void SetPopDialogHeight(int h);
    //设置弹框宽度
    void SetPopDialogWidth(int w);
    //插入一个项目：项目文本和插入的位置
    int InsertItem(const wchar_t* text, int index = -1);
    //移除一个项目：移除的位置
    int RemoveItem(int index);
    //设置下拉按钮的宽度比例，调整比率可能让三角形改变大小，一般用不到
    void SetButtonRatio(float rat);
    //设置项目高度
    void SetItemHeight(float h);
    //设置项目字体名称
    void SetItemFontName(const wchar_t* nm);
    //设置项目字体大小
    void SetItemFontSize(float size);
    //获取选中的项目文本
    std::wstring GetSelectedText();
    //获取项目文本
    std::wstring GetItemText(int index);
    //设置指定项目背景颜色：支持线性渐变
    //颜色1和2
    //d为0水平渐变，1为垂直渐变
    void SetItemBKColor(int index, unsigned int c1, unsigned int c2, unsigned char d = 0);
    //设置指定项目字体颜色
    //颜色1和2
    //d为0水平渐变，1为垂直渐变
    void SetItemFontColor(int index, unsigned int c1, unsigned int c2, unsigned char d = 0);
    //设置项目被选择时回调函数
    QSELECT_SELECTCHANGE SetSelectChangeEvent(QSELECT_SELECTCHANGE ev);
    //获取项目数
    size_t GetItemCount();
    //设置当前选中项目
    int SetCurrentItem(int index);
    //获取当前选项索引
    int GetIndex();
    //获取Item字体颜色
    //参数1：索引
    //参数2：保存方向的指针
    //参数3和4：保存颜色的指针
    int GetItemFontColor(int index, unsigned char* dire, unsigned int* pc1, unsigned int* pc2);
    //获取Item背景颜色
    //参数1：索引
    //参数2：保存方向的指针
    //参数3和4：保存颜色的指针
    int GetItemBKColor(int index, unsigned char* dire, unsigned int* pc1, unsigned int* pc2);
};