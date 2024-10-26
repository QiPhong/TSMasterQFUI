#pragma once
#include "QFUIWND.h"
#include "QFTypes.h"
#include "QFMsg.h"
#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __QDefineType(name) name##_Type
#define __MembersDef(name) __DefineFun(__QDefineType(name),name)
#define __FunTypeDef(fName) fName##_Type
typedef PVOID(*GET3DPROCADDRESS)(const char*);
namespace QEXPORTFUNC{
    template<typename T1>
    void __FUNADDRESS(T1& t, void* pfun)
    {

        t = (T1)(pfun);
    }
    inline void* QExportFunction(HMODULE hm,const char* fName)
    {
        void* pfun = (void*)GetProcAddress(hm,fName);
        if(pfun){
            DebugOut("QExportFunction : 导入 <%s> 函数成功",fName);
        }
        else{

            DebugOut("QExportFunction : 导入 <%s> 函数失败",fName);
        }
        return pfun;
    }
    inline void* QExportFunction(GET3DPROCADDRESS pro, const char* fName)
    {
        void* pfun = (void*)pro(fName);
        if (pfun) {
            DebugOut("QExportFunction : 导入 <%s> 函数成功", fName);
        }
        else {

            DebugOut("QExportFunction : 导入 <%s> 函数失败", fName);
        }
        return pfun;
    }
}


typedef int (*DRAW)(QWND * , HDC );
typedef int (*MSGHANDLE)(QWND * , UINT , WPARAM , LPARAM );
typedef int (*MOUSEMSGFUN)(QWND * , int , int , WPARAM  );
typedef int (*KEYMSGFUN)(QWND * , WPARAM , LPARAM );
typedef void (*ISBoolean)(QWND *,bool);
typedef void (*SETHANDLE)(QWND *,HWND);
typedef HCURSOR (*QSERCURSOR)(QWND *,HCURSOR);
typedef HCURSOR (*QGERCURSOR)(QWND *);
typedef void (*VOID_QWND)(QWND *);
typedef void (*RECONSTRUCT)(QWND *,HDC,QRect*);
typedef void (*SETLOCATION)(QWND* , QPoint*);
typedef void (*SETSIZE)(QWND*, QSize*, HDC);
typedef BOOL (*CONTAINS)(QWND*,int,int);
typedef QRect (*GETRECT)(QWND*);
typedef void(*SETQWNDNAME)(QWND*,const char*);
typedef const char* (*GETQWNDNAME)(QWND*);
typedef QDWORD(*TRANSFERMESSAGE)(QWND*, QDWORD, QDWORD, QDWORD, QDWORD);

class DLLImportQWND:public QWND
{
    protected:
    static HMODULE ghm ;
    static DRAW draw ; //绘制函数指针
    static MSGHANDLE msgHandle;//消息处理指针
    static MOUSEMSGFUN LButtonDownFun;
    static MOUSEMSGFUN LButtonUpFun;
    static MOUSEMSGFUN LButtonDBLClickFun;
    static MOUSEMSGFUN RButtonDownFun;
    static MOUSEMSGFUN RButtonUpFun;
    static MOUSEMSGFUN RButtonDBLClickFun;
    static MOUSEMSGFUN MButtonDownFun;
    static MOUSEMSGFUN MButtonUpFun;
    static MOUSEMSGFUN MButtonDBLClickFun;

    static MOUSEMSGFUN MouseWheelFun;
    static MOUSEMSGFUN MouseMoveFun;

    static KEYMSGFUN KeyCharFun;
    static KEYMSGFUN KeyIMECharFun;
    static KEYMSGFUN KeyDownFun;
    static KEYMSGFUN KeyUpFun;

    static ISBoolean isVisual_FUN;
    static ISBoolean isEnable_FUN;

    static SETHANDLE SetHostHwnd_FUN;
    static QSERCURSOR SetCursor_FUN;
    static QGERCURSOR GetCursor_FUN;
    static VOID_QWND LoadThisCtrlCursor_FUN;
    static VOID_QWND Refresh_FUN;
    static VOID_QWND Redraw_FUN;
    static VOID_QWND killFocus_FUN;

    static RECONSTRUCT Reconstruct_FUN;
    static SETLOCATION SetLocation_FUN;
    static SETSIZE SetSize_FUN;
    static CONTAINS Contains_FUN;
    static GETRECT GetRect_FUN;
    static VOID_QWND DeleteQWMage_FUN;

    static SETQWNDNAME SetQWNDName_FUN;
    static TRANSFERMESSAGE TransferMessage_FUN;
    static GETQWNDNAME GetQWNDName_FUN;

    
    public:
    QWND* qwm=NULL;//窗口管理对象指针
    //初始化异常
    virtual int init(HMODULE hm);// 初始化DLL函数

   
    inline void LoadThisCtrlCursor();
    virtual void Refresh() {};
    DLLImportQWND(HDC winddc, const QRect& rf);
    virtual ~DLLImportQWND();
    virtual int Draw(HDC sdc = NULL);                                    //绘制到指定DC
    virtual void Reconstruct(HDC sdc, const QRect& rect);                         //重新创建
    virtual void Reconstruct(HDC sdc);                                          //重新创建
    virtual void SetLocation(const QPoint& point);                               //设置位置
    virtual void SetSize(const QSize& size, HDC dc = NULL);                         //设置大小(会重新构建控件)
    //是否包含某点
    virtual BOOL Contains(IN INT x,
        IN INT y) const;
    virtual BOOL Contains(IN const QPoint& pt) const;
    virtual BOOL Contains(IN QRect& rect) const;
    virtual void Redraw() {};

    ///////////////////////////////////////////////////////////////////////////
    //消息处理
    virtual int MsgHandle(UINT uMsg, WPARAM wParam, LPARAM lParam);//原始消息

    virtual int LButtonDown(int x, int y, WPARAM wParam);//鼠标左键按下消息，
    virtual int LButtonDBLClick(int x, int y, WPARAM wParam);//鼠标左键弹起消息，
    virtual int LButtonUp(int x, int y, WPARAM wParam);//鼠标左键双击消息，

    virtual int RButtonDown(int x, int y, WPARAM wParam);//鼠标右键按下消息，
    virtual int RButtonUp(int x, int y, WPARAM wParam);//鼠标右键弹起消息，
    virtual int RButtonDBLClick(int x, int y, WPARAM wParam);//鼠标右键双击消息，

    virtual int MButtonDown(int x, int y, WPARAM wParam);//鼠标中键按下消息，
    virtual int MButtonUp(int x, int y, WPARAM wParam);//鼠标中键弹起消息，
    virtual int MButtonDBLClick(int x, int y, WPARAM wParam);//鼠标中键双击消息，
    virtual int MouseWheel(int x, int y, WPARAM wParam);//鼠标滚轮转到

    virtual int MouseMove(int x, int y, WPARAM wParam);//鼠标移动消息

    virtual int KeyChar(WPARAM wParam, LPARAM lParam);//键盘键入一个字符
    virtual int KeyIMEChar(WPARAM wParam, LPARAM lParam);//输入法发送一个字符过来
    virtual int KeyDown(WPARAM wParam, LPARAM lParam);//键盘按下某键
    virtual int KeyUp(WPARAM wParam, LPARAM lParam);//键盘弹起某键


    ///////////////////////////////////////////////////////////////////////////
    //失去焦点
    virtual void killFocus() {};

    /*
    *传递消息
    * 返回值和参数为自定义
    * 参数一：消息ID
    * 参数二：左参数
    * 参数三：有参数
    * 参数四：附加参数
    */
    virtual  QDWORD TransferMessage(QDWORD msgID, QDWORD LParam, QDWORD RParam, QDWORD AddParam);
    void SetQWNDName(const char* name);
    std::string GetQWNDName();
    //基础属性
    virtual void SetHostHand(HWND hwnd);

    QRect GetRect();
};













