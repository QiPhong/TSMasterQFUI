#include "DLLImportQWND.h"

HMODULE DLLImportQWND::ghm = NULL;
DRAW DLLImportQWND::draw = NULL; //绘制函数指针
MSGHANDLE DLLImportQWND::msgHandle = NULL;//消息处理指针
MOUSEMSGFUN DLLImportQWND::LButtonDownFun = NULL;
MOUSEMSGFUN DLLImportQWND::LButtonUpFun = NULL;
MOUSEMSGFUN DLLImportQWND::LButtonDBLClickFun = NULL;
MOUSEMSGFUN DLLImportQWND::RButtonDownFun = NULL;
MOUSEMSGFUN DLLImportQWND::RButtonUpFun = NULL;
MOUSEMSGFUN DLLImportQWND::RButtonDBLClickFun = NULL;
MOUSEMSGFUN DLLImportQWND::MButtonDownFun = NULL;
MOUSEMSGFUN DLLImportQWND::MButtonUpFun = NULL;
MOUSEMSGFUN DLLImportQWND::MButtonDBLClickFun = NULL;

MOUSEMSGFUN DLLImportQWND::MouseWheelFun = NULL;
MOUSEMSGFUN DLLImportQWND::MouseMoveFun = NULL;

KEYMSGFUN DLLImportQWND::KeyCharFun = NULL;
KEYMSGFUN DLLImportQWND::KeyIMECharFun = NULL;
KEYMSGFUN DLLImportQWND::KeyDownFun = NULL;
KEYMSGFUN DLLImportQWND::KeyUpFun = NULL;

ISBoolean DLLImportQWND::isVisual_FUN = NULL;
ISBoolean DLLImportQWND::isEnable_FUN = NULL;

SETHANDLE DLLImportQWND::SetHostHwnd_FUN = NULL;
QSERCURSOR DLLImportQWND::SetCursor_FUN = NULL;
QGERCURSOR DLLImportQWND::GetCursor_FUN = NULL;
VOID_QWND DLLImportQWND::LoadThisCtrlCursor_FUN = NULL;
VOID_QWND DLLImportQWND::Refresh_FUN = NULL;
VOID_QWND DLLImportQWND::Redraw_FUN = NULL;
VOID_QWND DLLImportQWND::killFocus_FUN = NULL;

RECONSTRUCT DLLImportQWND::Reconstruct_FUN = NULL;
SETLOCATION DLLImportQWND::SetLocation_FUN = NULL;
SETSIZE DLLImportQWND::SetSize_FUN = NULL;
CONTAINS DLLImportQWND::Contains_FUN = NULL;
GETRECT DLLImportQWND::GetRect_FUN = NULL;
VOID_QWND DLLImportQWND::DeleteQWMage_FUN = NULL;

SETQWNDNAME DLLImportQWND::SetQWNDName_FUN = NULL;
TRANSFERMESSAGE DLLImportQWND::TransferMessage_FUN = NULL;
GETQWNDNAME DLLImportQWND::GetQWNDName_FUN = NULL;








DLLImportQWND::DLLImportQWND(HDC winddc, const QRect& rf)
{


}


DLLImportQWND::~DLLImportQWND()
{

    if (DeleteQWMage_FUN) {
        
        DeleteQWMage_FUN(qwm);

    }
    //    if(qwm) delete qwm;
}


int DLLImportQWND::Draw(HDC sdc)                                    //绘制到指定DC
{
    // draw = (DRAW)GetProcAddress(ghm,"Draw");

    return draw(qwm, sdc);
}
void DLLImportQWND::Reconstruct(HDC sdc, const QRect& rect)                         //重新创建
{

    Reconstruct_FUN(qwm, sdc, const_cast<QRect*>(&rect));

}
void DLLImportQWND::Reconstruct(HDC sdc)                                          //重新创建
{
    //这个不要用

}
void DLLImportQWND::SetLocation(const QPoint& point)                             //设置位置
{
    SetLocation_FUN(qwm, const_cast<QPoint*>(&point));

}
void DLLImportQWND::SetSize(const QSize& size, HDC dc)                        //设置大小(会重新构建控件)
{
    SetSize_FUN(qwm, const_cast<QSize*>(&size), dc);
}

BOOL DLLImportQWND::Contains(IN INT x,
    IN INT y) const
{

    return Contains_FUN(qwm, x, y);


}
BOOL DLLImportQWND::Contains(IN const QPoint& pt) const
{

    return Contains_FUN(qwm, pt.X, pt.Y);

}
BOOL DLLImportQWND::Contains(IN QRect& rect) const
{
    //这个函数暂时不支持使用
    return 0;
}

int DLLImportQWND::MsgHandle(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    return msgHandle(qwm, uMsg, wParam, lParam);
}

int DLLImportQWND::LButtonDown(int x, int y, WPARAM wParam)
{

    return LButtonDownFun(qwm, x, y, wParam);
}
int DLLImportQWND::LButtonDBLClick(int x, int y, WPARAM wParam)
{

    return LButtonDBLClickFun(qwm, x, y, wParam);
}
int DLLImportQWND::LButtonUp(int x, int y, WPARAM wParam)
{


    return LButtonUpFun(qwm, x, y, wParam);
}

int DLLImportQWND::RButtonDown(int x, int y, WPARAM wParam)
{


    return RButtonDownFun(qwm, x, y, wParam);
}
int DLLImportQWND::RButtonUp(int x, int y, WPARAM wParam)
{


    return RButtonUpFun(qwm, x, y, wParam);
}
int DLLImportQWND::RButtonDBLClick(int x, int y, WPARAM wParam)
{


    return RButtonDBLClickFun(qwm, x, y, wParam);
}

int DLLImportQWND::MButtonDown(int x, int y, WPARAM wParam)
{


    return MButtonDownFun(qwm, x, y, wParam);
}
int DLLImportQWND::MButtonUp(int x, int y, WPARAM wParam)
{


    return MButtonUpFun(qwm, x, y, wParam);
}
int DLLImportQWND::MButtonDBLClick(int x, int y, WPARAM wParam)
{


    return MButtonDBLClickFun(qwm, x, y, wParam);
}
int DLLImportQWND::MouseWheel(int x, int y, WPARAM wParam)
{

    return MouseWheelFun(qwm, x, y, wParam);
}


int DLLImportQWND::MouseMove(int x, int y, WPARAM wParam)
{


    return MouseMoveFun(qwm, x, y, wParam);
}

int DLLImportQWND::KeyChar(WPARAM wParam, LPARAM lParam)
{


    return KeyCharFun(qwm, wParam, lParam);
}
int DLLImportQWND::KeyIMEChar(WPARAM wParam, LPARAM lParam)
{

    return KeyIMECharFun(qwm, wParam, lParam);
}
int DLLImportQWND::KeyDown(WPARAM wParam, LPARAM lParam)
{


    return KeyDownFun(qwm, wParam, lParam);
}
int DLLImportQWND::KeyUp(WPARAM wParam, LPARAM lParam)
{


    return KeyUpFun(qwm, wParam, lParam);
}
QRect DLLImportQWND::GetRect()
{

    return GetRect_FUN(qwm);
}

inline void DLLImportQWND::LoadThisCtrlCursor()
{

    LoadThisCtrlCursor_FUN(qwm);
}
QDWORD DLLImportQWND::TransferMessage(QDWORD msgID, QDWORD LParam, QDWORD RParam, QDWORD AddParam)
{
    return TransferMessage_FUN(qwm, msgID, LParam, RParam, AddParam);
}
void DLLImportQWND::SetQWNDName(const char* name)
{
    return SetQWNDName_FUN(qwm, name);
}

std::string DLLImportQWND::GetQWNDName()
{
    return std::string(GetQWNDName_FUN(qwm));
}
void  DLLImportQWND::SetHostHand(HWND hwnd)
{
    SetHostHwnd_FUN(qwm, hwnd);
}



int DLLImportQWND::init(HMODULE hm)
{
    DLLImportQWND::ghm = hm;
    if (NULL != hm) {
        int count = 0;
        draw = (DRAW)GetProcAddress(hm, "Draw");
        if (draw)++count;
        msgHandle = (MSGHANDLE)GetProcAddress(hm, "MsgHandle");
        if (msgHandle)++count;
        LButtonDownFun = (MOUSEMSGFUN)GetProcAddress(hm, "LButtonDown");
        if (LButtonDownFun)++count;
        LButtonUpFun = (MOUSEMSGFUN)GetProcAddress(hm, "LButtonUp");
        if (LButtonUpFun)++count;
        LButtonDBLClickFun = (MOUSEMSGFUN)GetProcAddress(hm, "LButtonDBLClick");
        if (LButtonDBLClickFun)++count;

        RButtonDownFun = (MOUSEMSGFUN)GetProcAddress(hm, "RButtonDown");
        if (RButtonDownFun)++count;
        RButtonUpFun = (MOUSEMSGFUN)GetProcAddress(hm, "RButtonUp");
        if (RButtonUpFun)++count;
        RButtonDBLClickFun = (MOUSEMSGFUN)GetProcAddress(hm, "RButtonDBLClick");
        if (RButtonDBLClickFun)++count;

        MButtonDownFun = (MOUSEMSGFUN)GetProcAddress(hm, "MButtonDown");
        if (MButtonDownFun)++count;
        MButtonUpFun = (MOUSEMSGFUN)GetProcAddress(hm, "MButtonUp");
        if (MButtonUpFun)++count;
        MButtonDBLClickFun = (MOUSEMSGFUN)GetProcAddress(hm, "MButtonDBLClick");
        if (MButtonDBLClickFun)++count;

        MouseWheelFun = (MOUSEMSGFUN)GetProcAddress(hm, "MouseWheel");
        if (MouseWheelFun)++count;
        MouseMoveFun = (MOUSEMSGFUN)GetProcAddress(hm, "MouseMove");
        if (MouseMoveFun)++count;

        KeyCharFun = (KEYMSGFUN)GetProcAddress(hm, "KeyChar");
        if (KeyCharFun)++count;
        KeyIMECharFun = (KEYMSGFUN)GetProcAddress(hm, "KeyIMEChar");
        if (KeyIMECharFun)++count;
        KeyDownFun = (KEYMSGFUN)GetProcAddress(hm, "KeyDown");
        if (KeyDownFun)++count;
        KeyUpFun = (KEYMSGFUN)GetProcAddress(hm, "KeyUp");
        if (KeyUpFun)++count;
        void* pfun = (void*)GetProcAddress(hm, "IsVisual");
        if (pfun)++count;
        isVisual_FUN = (ISBoolean)pfun;

        pfun = (void*)GetProcAddress(hm, "IsEnable");
        if (pfun)++count;
        isEnable_FUN = (ISBoolean)pfun;

        pfun = (void*)GetProcAddress(hm, "SetHostHwnd");
        if (pfun)++count;
        SetHostHwnd_FUN = (SETHANDLE)pfun;

        pfun = (void*)GetProcAddress(hm, "QWDSetCursor");
        if (pfun)++count;
        SetCursor_FUN = (QSERCURSOR)pfun;

        pfun = (void*)GetProcAddress(hm, "QWDGetCursor");
        if (pfun)++count;
        GetCursor_FUN = (QGERCURSOR)pfun;

        pfun = (void*)GetProcAddress(hm, "LoadThisCtrlCursor");
        if (pfun)++count;
        LoadThisCtrlCursor_FUN = (VOID_QWND)pfun;

        pfun = (void*)GetProcAddress(hm, "Refresh");
        if (pfun)++count;
        Refresh_FUN = (VOID_QWND)pfun;

        pfun = (void*)GetProcAddress(hm, "killFocus");
        if (pfun)++count;
        killFocus_FUN = (VOID_QWND)pfun;

        pfun = (void*)GetProcAddress(hm, "Reconstruct");
        if (pfun)++count;
        Reconstruct_FUN = (RECONSTRUCT)pfun;

        pfun = (void*)GetProcAddress(hm, "SetLocation");
        if (pfun)++count;
        SetLocation_FUN = (SETLOCATION)pfun;

        pfun = (void*)GetProcAddress(hm, "SetSize");
        if (pfun)++count;
        SetSize_FUN = (SETSIZE)pfun;

        pfun = (void*)GetProcAddress(hm, "Contains");
        if (pfun)++count;
        Contains_FUN = (CONTAINS)pfun;

        pfun = (void*)GetProcAddress(hm, "GetRect");
        if (pfun)++count;
        GetRect_FUN = (GETRECT)pfun;

        pfun = (void*)GetProcAddress(hm, "DeleteQWMange");
        if (pfun)++count;
        DeleteQWMage_FUN = (VOID_QWND)pfun;

        pfun = (void*)GetProcAddress(hm, "SetQWNDName");
        if (pfun)++count;
        SetQWNDName_FUN = (SETQWNDNAME)pfun;

        pfun = (void*)GetProcAddress(hm, "TransferMessage");
        if (pfun)++count;
        TransferMessage_FUN = (TRANSFERMESSAGE)pfun;

        pfun = (void*)GetProcAddress(hm, "GetQWNDName");
        if (pfun)++count;
        GetQWNDName_FUN = (GETQWNDNAME)pfun;




        //DebugOut("%d", 1);
        //DebugOut("DLLImportQWND: 总共导入了 %d 个函数",count);
        DebugOut("DLLImportQWND:import %d function", count);
        return count;
    }

    return -1;

}