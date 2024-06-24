#include "QFWindow.h"

const char* QFWindow::GetWindowsClass()
{

    return className.c_str();
}

const char* QFWindow::GetWindowsTitle()
{
    return Title.c_str();
}

void QFWindow::SetWindowsClass(const char* cn)
{
    className = cn;
}

void QFWindow::SetWindowsTitle(const char* t)
{
    Title = t;
}

int QFWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
