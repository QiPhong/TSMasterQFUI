#pragma once
#include <string>
#include <windows.h>
class QFWindow
{
	std::string className = "QFWindow";
	std::string Title = "ʾ��չʾ";

public:
	const char* GetWindowsClass();
	const char* GetWindowsTitle();
	void SetWindowsClass(const char* cn);
	void SetWindowsTitle(const char* t);

	int WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};

