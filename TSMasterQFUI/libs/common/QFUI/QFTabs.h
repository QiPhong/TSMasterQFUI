#pragma once
#include "DLLImportQWND.h"
#define DEF_FUN_NAME(name) QTB##name
#define DEF_FUN_NAME_STR(name) "QTB" name
#define __DefineFun(type,name) static type name
#define __GDefineFun(cname,type,name) type cname::name=NULL
#define __QDefineType(name) name##_Type
#define __MembersDef(name) __DefineFun(__QDefineType(name),name)
#define __FunTypeDef(fName) fName##_Type

typedef int (*__QWND__INT__FUN__INT)(QWND*, QWND*, int);
typedef int (*__WCHAR__WCHAR__FUN__INT)(QWND*, const wchar_t*, const wchar_t*);
typedef int (*__INT__FUN__INT)(QWND*, int);
typedef void (*__WCHAR__FUN)(QWND*, const wchar_t*);
typedef void (*__DOUBLE__FUN)(QWND*, double);
typedef void (*__ULONG__FUN)(QWND*, unsigned long);
typedef void (*__INT__WCHAR__FUN)(QWND*, int, const wchar_t*);
typedef void (*__FunTypeDef(QTBAttachCtrlToCurrentTabe))(QWND* p, QWND* );
typedef int (*__FunTypeDef(QTBGetTabeCount))(QWND* p);
typedef int (*__FunTypeDef(QTBGetTabeCtrlCount))(QWND* p,int);
typedef QWND* (*__FunTypeDef(QTBGetCtrl))(QWND* p, int, int);
typedef int (*__FunTypeDef(QTBInsertTab))(QWND* , const wchar_t* name, int index, const wchar_t* pBPath);
typedef const wchar_t* (*__FunTypeDef(QTBGetTabeBMPPath))(QWND* qt, int);
typedef const wchar_t* (*__FunTypeDef(QTBGetTabeText))(QWND* p, int);
typedef const wchar_t* (*__FunTypeDef(QTBGetCurrentTabeText))(QWND* p);
typedef const wchar_t* (*__FunTypeDef(QTBGetCurrentTabeIcoPath))(QWND* p);
typedef int (*__FunTypeDef(QTBSetCurrentTabeText))(QWND* p, const wchar_t*);
typedef int (*__FunTypeDef(QTBSetCurrentTabeIcoPath))(QWND* p, const wchar_t*);

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
	__MembersDef(QTBAttachCtrlToCurrentTabe);
	__MembersDef(QTBGetTabeCount);
	__MembersDef(QTBGetTabeCtrlCount);
	__MembersDef(QTBGetCtrl);
	__MembersDef(QTBInsertTab);
	__MembersDef(QTBGetTabeBMPPath);
	__MembersDef(QTBGetTabeText);
	__MembersDef(QTBGetCurrentTabeText);
	__MembersDef(QTBGetCurrentTabeIcoPath);
	__MembersDef(QTBSetCurrentTabeIcoPath);
	__MembersDef(QTBSetCurrentTabeText);
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
	void AttachCtrlToCurrentTabe(QWND* w);
	int GetTabeCount();
	int GetTabeCtrlCount(int index);
	QWND* GetCtrl(int ti, int index);
	int InsertTab(const wchar_t* name, int index = -1, const wchar_t* pBPath = NULL);//插入一个标签
	std::wstring GetTabeBMPPath(int index);
	std::wstring GetTabeText(int index);
	std::wstring GetCurrentTabeText();
	std::wstring GetCurrentTabeIcoPath();
	int SetCurrentTabeText(const wchar_t* txt);
	int SetCurrentTabeIcoPath(const wchar_t* path);
};

