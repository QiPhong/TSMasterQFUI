#pragma once
#include "DLLImportQWND.h"
#define DEF_FUN_NAME(name) QTB##name
#define DEF_FUN_NAME_STR(name) "QTB" name
typedef int (*__QWND__INT__FUN__INT)(QWND*, QWND*, int);
typedef int (*__WCHAR__WCHAR__FUN__INT)(QWND*, const wchar_t*, const wchar_t*);
typedef int (*__INT__FUN__INT)(QWND*, int);
typedef void (*__WCHAR__FUN)(QWND*, const wchar_t*);
typedef void (*__DOUBLE__FUN)(QWND*, double);
typedef void (*__ULONG__FUN)(QWND*, unsigned long);
typedef void (*__INT__WCHAR__FUN)(QWND*, int, const wchar_t*);

class QTabs :public DLLImportQWND
{
	static HMODULE m_hm;
	static __QWND__INT__FUN__INT DEF_FUN_NAME(AttachCtrl);
	static __WCHAR__WCHAR__FUN__INT DEF_FUN_NAME(AddTab);
	static __QWND__INT__FUN__INT DEF_FUN_NAME(RemoveCtrl);
	static __INT__FUN__INT DEF_FUN_NAME(RemoveTab);
	static __INT__FUN__INT DEF_FUN_NAME(SetBKBrush);
	static __WCHAR__FUN DEF_FUN_NAME(SetFontName);
	static __DOUBLE__FUN DEF_FUN_NAME(SetFontSize);
	static __ULONG__FUN DEF_FUN_NAME(SetFontColor);
	static __ULONG__FUN DEF_FUN_NAME(SetTabBKColor);
	static __INT__WCHAR__FUN DEF_FUN_NAME(SetTabIco);
	static __INT__WCHAR__FUN DEF_FUN_NAME(SetTabName);

public:
	QTabs(HDC winddc, const QRect& rf);
	virtual ~QTabs();
public:
	int AttachCtrl(DLLImportQWND* w, int index);
	int RemoveCtrl(DLLImportQWND* w, int index);       //移除一个控件
	int init(HMODULE hm);
	int AddTab(const wchar_t* name, const wchar_t* pBPath = NULL);//增加一个标签
	int RemoveTab(int index);//移除一个标签
	int SetBKBrush(QBrush* brush);
	void SetFontName(const wchar_t* name);//设置字体名称
	void SetFontSize(double size);//设置字体大小
	void SetFontColor(unsigned long color);//设置字体颜色
	void SetTabIco(int index, const wchar_t* path);
	void SetTabName(int index, const wchar_t* name);
	void SetTabBKColor(unsigned long color);

};

