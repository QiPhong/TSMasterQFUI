#include "QFFrequentlyCtrl.h"



#ifdef __QDRAWER__


#define __FUNCTINNAME_QDW(name) QDW##name
#define __FUNCTINNAME_QDW_STR(name) "QDW" #name
#define __GDefineFun_QDW(name) __GDefineFun(QDrawer,__QDefineType(name),name)


//#define __FUNADDRESS_QDW(fn) __FUNCTINNAME_QDW(fn)=(__QDefineType(__FUNCTINNAME_QDW(fn)))pfun;

__GDefineFun_QDW(QDWSetFontName);
__GDefineFun_QDW(QDWSetFontSize);
__GDefineFun_QDW(QDWInsertDrawer);
__GDefineFun_QDW(QDWInsertSubObject);
__GDefineFun_QDW(QDWRemoveSubObject);
__GDefineFun_QDW(QDWRemoveDrawer);
__GDefineFun_QDW(QDWGetDrawerCount);
__GDefineFun_QDW(QDWGetSubObjectCount);
__GDefineFun_QDW(QDWSetDrawerName);
__GDefineFun_QDW(QDWSetDrawerFontColor);
__GDefineFun_QDW(QDWSetDrawerBKColor);
__GDefineFun_QDW(QDWOpenDrawer);
__GDefineFun_QDW(QDWCloseDrawer);
__GDefineFun_QDW(QDWSetSubObjectName);
__GDefineFun_QDW(QDWSetSubObjectFontColor);
__GDefineFun_QDW(QDWSetSubObjectBKColor);
__GDefineFun_QDW(QDWSetSelectEvent);
__GDefineFun_QDW(QDWGetSubObjectName);
__GDefineFun_QDW(QDWGetDrawerName);
HMODULE QDrawer::m_hm = NULL;

QDrawer::QDrawer(HDC winddc, const QRect& rf):DLLImportQWND(winddc,rf)
{

}
QDrawer::~QDrawer()
{

}

void QDrawer::SetFontName(const wchar_t* name)
{
	return __FUNCTINNAME_QDW(SetFontName)(qwm,name);
}

void QDrawer::SetFontSize(float size)
{
	return __FUNCTINNAME_QDW(SetFontSize)(qwm, size);
}

int QDrawer::InsertDrawer(int index)
{
	return __FUNCTINNAME_QDW(InsertDrawer)(qwm, index);
}

int QDrawer::InsertSubObject(int iDrawer, int iObj)
{
	return __FUNCTINNAME_QDW(InsertSubObject)(qwm, iDrawer, iObj);
}

int QDrawer::RemoveSubObject(int iDrawer, int iObj)
{
	return __FUNCTINNAME_QDW(RemoveSubObject)(qwm, iDrawer, iObj);
}

int QDrawer::RemoveDrawer(int index)
{
	return __FUNCTINNAME_QDW(RemoveDrawer)(qwm, index);
}

int QDrawer::GetDrawerCount()
{
	return __FUNCTINNAME_QDW(GetDrawerCount)(qwm);
}

int QDrawer::GetSubObjectCount(int index)
{
	return __FUNCTINNAME_QDW(GetSubObjectCount)(qwm, index);
}

int QDrawer::SetDrawerName(int index, const wchar_t* name)
{
	return __FUNCTINNAME_QDW(SetDrawerName)(qwm, index, name);
}

int QDrawer::SetDrawerFontColor(int index, int color)
{
	return __FUNCTINNAME_QDW(SetDrawerFontColor)(qwm, index, color);
}

int QDrawer::SetDrawerBKColor(int index, int color)
{
	return __FUNCTINNAME_QDW(SetDrawerBKColor)(qwm, index, color);
}

int QDrawer::OpenDrawer(int index)
{
	return __FUNCTINNAME_QDW(OpenDrawer)(qwm, index);
}

int QDrawer::CloseDrawer(int index)
{
	return __FUNCTINNAME_QDW(CloseDrawer)(qwm, index);
}

int QDrawer::SetSubObjectName(int iDrawer, int iObj, const wchar_t* name)
{
	return __FUNCTINNAME_QDW(SetSubObjectName)(qwm, iDrawer, iObj, name);
}

int QDrawer::SetSubObjectFontColor(int iDrawer, int iObj, int color)
{
	return __FUNCTINNAME_QDW(SetSubObjectFontColor)(qwm, iDrawer, iObj, color);
}

int QDrawer::SetSubObjectBKColor(int iDrawer, int iObj, int color)
{
	return __FUNCTINNAME_QDW(SetSubObjectBKColor)(qwm, iDrawer, iObj, color);
}

int QDrawer::SetSelectEvent(QDRAWERSELECT fun)
{
	return __FUNCTINNAME_QDW(SetSelectEvent)(qwm, fun);
}

std::wstring QDrawer::GetSubObjectName(int iDrawer, int iObj)
{
	int len=__FUNCTINNAME_QDW(GetSubObjectName)(qwm, iDrawer, iObj,NULL,0);
	std::wstring str((size_t)len+1,L'\0');
	
	__FUNCTINNAME_QDW(GetSubObjectName)(qwm, iDrawer, iObj, const_cast<wchar_t*>(str.data()), len + 1);

	return str;
}

std::wstring QDrawer::GetDrawerName(int iDrawer)
{
	int len = __FUNCTINNAME_QDW(GetDrawerName)(qwm, iDrawer, NULL, 0);
	std::wstring str((size_t)len + 1, L'\0');
	__FUNCTINNAME_QDW(GetDrawerName)(qwm, iDrawer, const_cast<wchar_t*>(str.data()), len + 1);
	return str;
}



int QDrawer::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QDW_STR(SetFontName);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		/*__FUNADDRESS_QDW(SetFontName);*/
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetFontName), pfun);

		 fName = __FUNCTINNAME_QDW_STR(SetFontSize);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetFontSize), pfun);

		fName = __FUNCTINNAME_QDW_STR(InsertDrawer);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(InsertDrawer), pfun);
		//QDWInsertDrawer = (QDWInsertDrawer_Type)pfun;

		fName = __FUNCTINNAME_QDW_STR(InsertSubObject);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(InsertSubObject), pfun);

		fName = __FUNCTINNAME_QDW_STR(RemoveSubObject);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(RemoveSubObject), pfun);

		fName = __FUNCTINNAME_QDW_STR(RemoveDrawer);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(RemoveDrawer), pfun);

		fName = __FUNCTINNAME_QDW_STR(GetDrawerCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(GetDrawerCount), pfun);

		fName = __FUNCTINNAME_QDW_STR(GetSubObjectCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(GetSubObjectCount), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetDrawerName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetDrawerName), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetDrawerFontColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetDrawerFontColor), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetDrawerBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetDrawerBKColor), pfun);

		fName = __FUNCTINNAME_QDW_STR(OpenDrawer);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(OpenDrawer), pfun);

		fName = __FUNCTINNAME_QDW_STR(CloseDrawer);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(CloseDrawer), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetSubObjectName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetSubObjectName), pfun);
		
		fName = __FUNCTINNAME_QDW_STR(SetSubObjectFontColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetSubObjectFontColor), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetSubObjectBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetSubObjectBKColor), pfun);

		fName = __FUNCTINNAME_QDW_STR(SetSelectEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(SetSelectEvent), pfun);

		fName = __FUNCTINNAME_QDW_STR(GetSubObjectName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(GetSubObjectName), pfun);

		fName = __FUNCTINNAME_QDW_STR(GetDrawerName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QDW(GetDrawerName), pfun);



		DLLImportQWND::init(hm);
		DebugOut("QDrawer :import %d function", count);
		return count;
	}
	return 0;
}

#endif 



#ifdef __QHOSTCTRL__
#define __FUNCTINNAME_QHC(name) QHC##name
#define __FUNCTINNAME_QHC_STR(name) "QHC" #name
#define __GDefineFun_QHC(name) __GDefineFun(QHost,__QDefineType(name),name)


//#define __FUNADDRESS_QDW(fn) __FUNCTINNAME_QDW(fn)=(__QDefineType(__FUNCTINNAME_QDW(fn)))pfun;

__GDefineFun_QHC(QHCSetParasiticCtrl);
__GDefineFun_QHC(QHCGetParasiticCtrl);
HMODULE QHost::m_hm = NULL;



QHost::QHost(HDC winddc, const QRect& rf):DLLImportQWND(winddc, rf)
{
}

QHost::~QHost()
{
}

int QHost::SetParasiticCtrl(DLLImportQWND* ctrl, QWND** oldCtrl)
{

	return __FUNCTINNAME_QHC(SetParasiticCtrl)(qwm, ctrl->qwm, oldCtrl);
}
QWND* QHost::GetParasiticCtrl()
{
	return __FUNCTINNAME_QHC(GetParasiticCtrl)(qwm);
}
int QHost::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QHC_STR(SetParasiticCtrl);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		/*__FUNADDRESS_QDW(SetFontName);*/
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHC(SetParasiticCtrl), pfun);

		fName = __FUNCTINNAME_QHC_STR(GetParasiticCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		/*__FUNADDRESS_QDW(SetFontName);*/
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHC(GetParasiticCtrl), pfun);


		DLLImportQWND::init(hm);
		DebugOut("QHost :import %d function", count);
		return count;
	}
	return 0;
}







#endif 

#ifdef __QHLAYOUT__
HMODULE QHLayout::m_hm = NULL;
#define __FUNCTINNAME_QHL(name) QHL##name
#define __FUNCTINNAME_QHL_STR(name) "QHL" #name
#define __GDefineFun_QHL(name) __GDefineFun(QHLayout,__QDefineType(name),name)
__GDefineFun_QHL(QHLInsertCtrl);
__GDefineFun_QHL(QHLRemoveCtrl);
__GDefineFun_QHL(QHLGetCtrlCount);
__GDefineFun_QHL(QHLGetCtrl);
__GDefineFun_QHL(QHLGetCtrlWeight);
QHLayout::QHLayout(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}

int QHLayout::init(HMODULE hm)
{
	if (!m_hm) {
		m_hm = hm;
		int count = 0;
		const char* fName = __FUNCTINNAME_QHL_STR(InsertCtrl);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHL(InsertCtrl), pfun);

		fName = __FUNCTINNAME_QHL_STR(RemoveCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHL(RemoveCtrl), pfun);

		fName = __FUNCTINNAME_QHL_STR(GetCtrlCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHL(GetCtrlCount), pfun);

		fName = __FUNCTINNAME_QHL_STR(GetCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHL(GetCtrl), pfun);

		fName = __FUNCTINNAME_QHL_STR(GetCtrlWeight);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QHL(GetCtrlWeight), pfun);

		DLLImportQWND::init(hm);
		DebugOut("QHLayout :import %d function", count);
		return count;
	}
	return 0;
}


int QHLayout::InsertCtrl(DLLImportQWND* ctrl, unsigned int weight, int index)
{
	return  __FUNCTINNAME_QHL(InsertCtrl)(qwm, ctrl->qwm, weight, index);
}

int QHLayout::RemoveCtrl(int index)
{
	return  __FUNCTINNAME_QHL(RemoveCtrl)(qwm, index);
}

int QHLayout::GetCtrlCount()
{



	return  __FUNCTINNAME_QHL(GetCtrlCount)(qwm);
}
QWND* QHLayout::GetCtrl(int index)
{

	return __FUNCTINNAME_QHL(GetCtrl)(qwm, index);
}
unsigned int QHLayout::GetCtrlWeight(int index)
{
	return __FUNCTINNAME_QHL(GetCtrlWeight)(qwm, index);
}
#endif // __QHLAYOUT__



#ifdef __QVLAYOUT__
HMODULE QVLayout::m_hm = NULL;
#define __FUNCTINNAME_QVL(name) QVL##name
#define __FUNCTINNAME_QVL_STR(name) "QVL" #name
#define __GDefineFun_QVL(name) __GDefineFun(QVLayout,__QDefineType(name),name)
__GDefineFun_QVL(QVLInsertCtrl);
__GDefineFun_QVL(QVLRemoveCtrl);
__GDefineFun_QVL(QVLGetCtrlCount);
__GDefineFun_QVL(QVLGetCtrl); 
__GDefineFun_QVL(QVLGetCtrlWeight);
QVLayout::QVLayout(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}

int QVLayout::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QVL_STR(InsertCtrl);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QVL(InsertCtrl), pfun);

		fName = __FUNCTINNAME_QVL_STR(RemoveCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QVL(RemoveCtrl), pfun);

		fName = __FUNCTINNAME_QVL_STR(GetCtrlCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QVL(GetCtrlCount), pfun);

		fName = __FUNCTINNAME_QVL_STR(GetCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QVL(GetCtrl), pfun);

		fName = __FUNCTINNAME_QVL_STR(GetCtrlWeight);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QVL(GetCtrlWeight), pfun);

		DLLImportQWND::init(hm);
		DebugOut("QVLayout :import %d function", count);
		m_hm = hm;
		return count;
	}
	return 0;
}
int QVLayout::InsertCtrl(DLLImportQWND* ctrl, unsigned int weight, int index)
{
	return  __FUNCTINNAME_QVL(InsertCtrl)(qwm, ctrl->qwm, weight, index);
}

int QVLayout::RemoveCtrl(int index)
{
	return  __FUNCTINNAME_QVL(RemoveCtrl)(qwm, index);
}

int QVLayout::GetCtrlCount()
{
	return  __FUNCTINNAME_QVL(GetCtrlCount)(qwm);
}

QWND* QVLayout::GetCtrl(int index)
{
	return __FUNCTINNAME_QVL(GetCtrl)(qwm, index);
}


unsigned int QVLayout::GetCtrlWeight(int index)
{
	return __FUNCTINNAME_QVL(GetCtrlWeight)(qwm, index);
}






#endif // __QHLAYOUT__
#ifdef __QTLAYOUT__
HMODULE QTLayout::m_hm = NULL;
#define __FUNCTINNAME_QTL(name) QTL##name
#define __FUNCTINNAME_QTL_STR(name) "QTL" #name
#define __GDefineFun_QTL(name) __GDefineFun(QTLayout,__QDefineType(name),name)
__GDefineFun_QTL(QTLSetCtrl);
__GDefineFun_QTL(QTLRemoveCtrl);
__GDefineFun_QTL(QTLGetCtrl);
QTLayout::QTLayout(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}

int QTLayout::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QTL_STR(SetCtrl);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTL(SetCtrl), pfun);

		fName = __FUNCTINNAME_QTL_STR(RemoveCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTL(RemoveCtrl), pfun);

		fName = __FUNCTINNAME_QTL_STR(GetCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QTL(GetCtrl), pfun);

		
		DLLImportQWND::init(hm);
		DebugOut("QVLayout :import %d function", count);
		m_hm = hm;
		return count;
	}
	return 0;
}

int QTLayout::SetCtrl(QWND* ctrl)
{
	return __FUNCTINNAME_QTL(SetCtrl)(qwm, ctrl);
}

int QTLayout::RemoveCtrl()
{
	return __FUNCTINNAME_QTL(RemoveCtrl)(qwm);
}

QWND* QTLayout::GetCtrl()
{
	return __FUNCTINNAME_QTL(GetCtrl)(qwm);
}

#endif // __QTLAYOUT__



#ifdef __QSTATICTEXT__
HMODULE QStaticText::m_hm = NULL;
#define __FUNCTINNAME_QSTT(name) QSTT##name
#define __FUNCTINNAME_QSTT_STR(name) "QSTT" #name
#define __GDefineFun_QSTT(name) __GDefineFun(QStaticText,__QDefineType(name),name)
__GDefineFun_QSTT(QSTTSetText);
__GDefineFun_QSTT(QSTTSetFontName);
__GDefineFun_QSTT(QSTTSetFontSize);
__GDefineFun_QSTT(QSTTSetFontColor);
__GDefineFun_QSTT(QSTTSetBKColor);
__GDefineFun_QSTT(QSTTGetText);


QStaticText::QStaticText(HDC winddc, const QRect& rf):DLLImportQWND(winddc, rf)
{


}

int QStaticText::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QSTT_STR(SetText);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(SetText), pfun);

		fName = __FUNCTINNAME_QSTT_STR(SetFontName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(SetFontName), pfun);

		fName = __FUNCTINNAME_QSTT_STR(SetFontSize);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(SetFontSize), pfun);

		fName = __FUNCTINNAME_QSTT_STR(SetFontColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(SetFontColor), pfun);

		fName = __FUNCTINNAME_QSTT_STR(SetBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(SetBKColor), pfun);

		fName = __FUNCTINNAME_QSTT_STR(GetText);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSTT(GetText), pfun);

		DLLImportQWND::init(hm);
		DebugOut("QStaticText :import %d function", count);
		m_hm = hm;
		return count;
	}
	return 0;
}

void QStaticText::SetText(const wchar_t* t)
{
	return  __FUNCTINNAME_QSTT(SetText)(qwm,t);
}

void QStaticText::SetFontName(const wchar_t* t)
{
	return  __FUNCTINNAME_QSTT(SetFontName)(qwm, t);
}

void QStaticText::SetFontSize(double size)
{
	return  __FUNCTINNAME_QSTT(SetFontSize)(qwm, size);
}

void QStaticText::SetFontColor(unsigned int color)
{
	return  __FUNCTINNAME_QSTT(SetFontColor)(qwm, color);
}

void QStaticText::SetBKColor(unsigned int color)
{
	return  __FUNCTINNAME_QSTT(SetBKColor)(qwm, color);
}

std::wstring QStaticText::GetText()
{
	return std::wstring(__FUNCTINNAME_QSTT(GetText)(qwm));
}



#endif // __QSTATICTEXT__


#ifdef __QCTRLTOOLBOX__
HMODULE QCtrlToolbox::m_hm = NULL;
#define __FUNCTINNAME_QCTB(name) QCTB##name
#define __FUNCTINNAME_QCTB_STR(name) "QCTB" #name
#define __GDefineFun_QCTB(name) __GDefineFun(QCtrlToolbox,__QDefineType(name),name)
__GDefineFun_QCTB(QCTBInsertCtrl);
__GDefineFun_QCTB(QCTBRemoveCtrl);
__GDefineFun_QCTB(QCTBGetCtrlCount);
__GDefineFun_QCTB(QCTBInsertAttributeCtrl);
__GDefineFun_QCTB(QCTBRemoveAttributeCtrl);
__GDefineFun_QCTB(QCTBClearAttributeCtrl);
__GDefineFun_QCTB(QCTBSetFileButtonEvent);
QCtrlToolbox::QCtrlToolbox(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{



}
int QCtrlToolbox::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QCTB_STR(InsertCtrl);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(InsertCtrl), pfun);

		fName = __FUNCTINNAME_QCTB_STR(RemoveCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(RemoveCtrl), pfun);

		fName = __FUNCTINNAME_QCTB_STR(GetCtrlCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(GetCtrlCount), pfun);


		fName = __FUNCTINNAME_QCTB_STR(InsertAttributeCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(InsertAttributeCtrl), pfun);


		fName = __FUNCTINNAME_QCTB_STR(RemoveAttributeCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(RemoveAttributeCtrl), pfun);


		fName = __FUNCTINNAME_QCTB_STR(ClearAttributeCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(ClearAttributeCtrl), pfun);

		fName = __FUNCTINNAME_QCTB_STR(SetFileButtonEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QCTB(SetFileButtonEvent), pfun);

		DLLImportQWND::init(hm);
		DebugOut("QCtrlToolbox :import %d function", count);
		m_hm = hm;
		return count;
	}



	return 0;
}
int QCtrlToolbox::InsertCtrl(DLLImportQWND* ctrl, unsigned int weight, int index)
{
	return __FUNCTINNAME_QCTB(InsertCtrl)(qwm, ctrl->qwm, weight, index);
}
int QCtrlToolbox::RemoveCtrl(int index)
{
	return __FUNCTINNAME_QCTB(RemoveCtrl)(qwm,  index);
}
int QCtrlToolbox::GetCtrlCount()
{
	return __FUNCTINNAME_QCTB(GetCtrlCount)(qwm);
}
int QCtrlToolbox::InsertAttributeCtrl(DLLImportQWND* w, int index)
{
	return __FUNCTINNAME_QCTB(InsertAttributeCtrl)(qwm, w->qwm, index);
}
int QCtrlToolbox::RemoveAttributeCtrl(int index)
{
	return __FUNCTINNAME_QCTB(RemoveAttributeCtrl)(qwm, index);
}
void QCtrlToolbox::ClearAttributeCtrl()
{
	return __FUNCTINNAME_QCTB(ClearAttributeCtrl)(qwm);
}
void QCtrlToolbox::SetFileButtonEvent(QFBUTTONCLICK en, int index)
{
	return __FUNCTINNAME_QCTB(SetFileButtonEvent)(qwm, en, index);
}
#endif

#ifdef __QEDITORWIN__

HMODULE QEditorWin::m_hm = NULL;
#define __FUNCTINNAME_QEW(name) QEW##name
#define __FUNCTINNAME_QEW_STR(name) "QEW" #name
#define __GDefineFun_QEW(name) __GDefineFun(QEditorWin,__QDefineType(name),name)
__GDefineFun_QEW(QEWSetLButtonEvent);
__GDefineFun_QEW(QEWAttachCtrl);
__GDefineFun_QEW(QEWRemoveCtrl);
__GDefineFun_QEW(QEWSetPlaceCtrlEvent);
__GDefineFun_QEW(QEWSetDeleteCtrlEvent);
__GDefineFun_QEW(QEWSetSelectCtrlEvent);
QEditorWin::QEditorWin(HDC winddc, const QRect& rf) :DLLImportQWND(winddc, rf)
{

}

int QEditorWin::init(HMODULE hm)
{
	if (!m_hm) {
		int count = 0;
		const char* fName = __FUNCTINNAME_QEW_STR(SetLButtonEvent);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(SetLButtonEvent), pfun);

		fName = __FUNCTINNAME_QEW_STR(AttachCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(AttachCtrl), pfun);

		fName = __FUNCTINNAME_QEW_STR(RemoveCtrl);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(RemoveCtrl), pfun);

		fName = __FUNCTINNAME_QEW_STR(SetPlaceCtrlEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(SetPlaceCtrlEvent), pfun);

		fName = __FUNCTINNAME_QEW_STR(SetDeleteCtrlEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(SetDeleteCtrlEvent), pfun);

		fName = __FUNCTINNAME_QEW_STR(SetSelectCtrlEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QEW(SetSelectCtrlEvent), pfun);

		DLLImportQWND::init(hm);
		DebugOut("QEditorWin :import %d function", count);
		m_hm = hm;
		return count;
	}
	return 0;
}
int QEditorWin::SetLButtonEvent(QEDITORWIN_LBDOWN ent)
{
	return __FUNCTINNAME_QEW(SetLButtonEvent)(qwm, ent);
}
void QEditorWin::AttachCtrl(DLLImportQWND* w)
{
	return __FUNCTINNAME_QEW(AttachCtrl)(qwm, w->qwm);
}
void QEditorWin::RemoveCtrl(DLLImportQWND* w)
{
	return __FUNCTINNAME_QEW(RemoveCtrl)(qwm, w->qwm);
}
int QEditorWin::SetPlaceCtrlEvent(QEDITORWIN_PLACE_CTRL ent)
{
	return __FUNCTINNAME_QEW(SetPlaceCtrlEvent)(qwm, ent);
}
int QEditorWin::SetDeleteCtrlEvent(QEDITORWIN_DELETE_CTRL ent)
{
	return __FUNCTINNAME_QEW(SetDeleteCtrlEvent)(qwm, ent);
}
int QEditorWin::SetSelectCtrlEvent(QEDITORWIN_SELECT_CTRL ent)
{
	return __FUNCTINNAME_QEW(SetSelectCtrlEvent)(qwm, ent);
}
#endif

#ifdef __QSWITCH__
HMODULE QSwitch::m_hm = NULL;
#define __FUNCTINNAME_QSW(name) QSW##name
#define __FUNCTINNAME_QSW_STR(name) "QSW" #name
#define __GDefineFun_QSW(name) __GDefineFun(QSwitch,__QDefineType(name),name)
__GDefineFun_QSW(__EXTERN_FFUN(QSW, SetStateChangeEvent));
__GDefineFun_QSW(__EXTERN_FFUN(QSW, GetState));
__GDefineFun_QSW(__EXTERN_FFUN(QSW, SetState));
__GDefineFun_QSW(__EXTERN_FFUN(QSW, IsMutex));
QSwitch::QSwitch(HDC winddc, const QRect& rf) :QCtrlBaseD2DIPD(winddc, rf)
{

}

int QSwitch::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
	
		const char* fName = __FUNCTINNAME_QSW_STR(SetStateChangeEvent);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSW(SetStateChangeEvent), pfun);

		fName = __FUNCTINNAME_QSW_STR(GetState);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSW(GetState), pfun);

		fName = __FUNCTINNAME_QSW_STR(SetState);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSW(SetState), pfun);

		fName = __FUNCTINNAME_QSW_STR(IsMutex);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSW(IsMutex), pfun);

		DebugOut("QSwitch :import %d function", count);
		m_hm = hm;

	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}

int QSwitch::SetStateChangeEvent(QSWITCH_STATE_CHANGE ev)
{
	return __FUNCTINNAME_QSW(SetStateChangeEvent)(qwm, ev);
}

int QSwitch::GetState() const
{
	return __FUNCTINNAME_QSW(GetState)(qwm);
}

void QSwitch::SetState(int state)
{
	return __FUNCTINNAME_QSW(SetState)(qwm, state);
}

void QSwitch::IsMutex(bool im)
{
	return __FUNCTINNAME_QSW(IsMutex)(qwm, im);
}

#endif

#ifdef __QBUTTON__
HMODULE QButton2::m_hm = NULL;
#define __FUNCTINNAME_QB2(name) QB2##name
#define __FUNCTINNAME_QB2_STR(name) "QBT2" #name
#define __GDefineFun_QPB(name) __GDefineFun(QButton2,__QDefineType(name),name)
__GDefineFun_QPB(__EXTERN_FFUN_QB2(GetText));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetText));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetClickEvent));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetMargin));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetBKColor));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetPicType));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(LoadPicture));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(GetPicturePath));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetXRadius));
__GDefineFun_QPB(__EXTERN_FFUN_QB2(SetYRadius));


QButton2::QButton2(HDC winddc, const QRect& rf): QCtrlBaseD2DIPD(winddc, rf)
{
}

std::wstring QButton2::GetText()
{
	return std::wstring(__FUNCTINNAME_QB2(GetText)(qwm));
}

void QButton2::SetText(const wchar_t* t)
{
	return __FUNCTINNAME_QB2(SetText)(qwm,t);
}

void QButton2::SetClickEvent(QFBUTTONCLICK fun)
{
	return __FUNCTINNAME_QB2(SetClickEvent)(qwm, fun);
}

float QButton2::SetMargin(float margin)
{
	return __FUNCTINNAME_QB2(SetMargin)(qwm, margin);
}

unsigned int QButton2::SetBKColor(unsigned int color)
{
	return __FUNCTINNAME_QB2(SetBKColor)(qwm, color);
}

unsigned char QButton2::SetPicType(unsigned char type)
{
	return __FUNCTINNAME_QB2(SetPicType)(qwm, type);
}

int QButton2::LoadPicture(const wchar_t* path)
{
	return __FUNCTINNAME_QB2(LoadPicture)(qwm, path);
}

std::wstring QButton2::GetPicturePath() const
{
	return std::wstring(__FUNCTINNAME_QB2(GetPicturePath)(qwm));
}

float QButton2::SetXRadius(float rx)
{
	return __FUNCTINNAME_QB2(SetXRadius)(qwm, rx);
}

float QButton2::SetYRadius(float ry)
{
	return __FUNCTINNAME_QB2(SetYRadius)(qwm, ry);
}
int QButton2::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
	
		const char* fName = __FUNCTINNAME_QB2_STR(GetText);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(GetText), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetText);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetText), pfun);

		fName = __FUNCTINNAME_QB2_STR(LoadPicture);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(LoadPicture), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetClickEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetClickEvent), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetMargin);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetMargin), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetBKColor), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetPicType);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetPicType), pfun);

		fName = __FUNCTINNAME_QB2_STR(GetPicturePath);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(GetPicturePath), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetXRadius);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetXRadius), pfun);

		fName = __FUNCTINNAME_QB2_STR(SetYRadius);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QB2(SetYRadius), pfun);


	
		DebugOut("QButton2 :import %d function", count);
		m_hm = hm;
	
	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}
#endif // DEBUG

#ifdef __QSLIDER__
#define __QFLAG QSL
#define __FUNCTINNAME_QSL(name) QSL##name
#define __FUNCTINNAME_QSL_STR(name) "QSL" #name
#define __GDefineFun_QSL(name) __GDefineFun(QSlider,__QDefineType(name),name)
HMODULE QSlider::m_hm;
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetMinValue));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetMaxValue));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetCurrentValue));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetRailColor));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetRailRatio));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, IsSegmentation));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, ClearSegmArr));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, AddSegmVuale));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, RemoveSegmVuale));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetDirection));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetValueChangeEvent));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, SetColor));
__GDefineFun_QSL(__EXTERN_FFUN(__QFLAG, GetSegmValue));
QSlider::QSlider(HDC winddc, const QRect& rf):QCtrlBaseD2DIPD(winddc, rf)
{
}

int QSlider::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
		const char* fName = __FUNCTINNAME_QSL_STR(SetMinValue);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetMinValue), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetMaxValue);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetMaxValue), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetCurrentValue);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetCurrentValue), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetRailColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetRailColor), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetRailRatio);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetRailRatio), pfun);

		fName = __FUNCTINNAME_QSL_STR(IsSegmentation);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(IsSegmentation), pfun);

		fName = __FUNCTINNAME_QSL_STR(ClearSegmArr);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(ClearSegmArr), pfun);

		fName = __FUNCTINNAME_QSL_STR(AddSegmVuale);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(AddSegmVuale), pfun);

		fName = __FUNCTINNAME_QSL_STR(RemoveSegmVuale);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(RemoveSegmVuale), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetDirection);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetDirection), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetValueChangeEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetValueChangeEvent), pfun);

		fName = __FUNCTINNAME_QSL_STR(SetColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(SetColor), pfun);

		fName = __FUNCTINNAME_QSL_STR(GetSegmValue);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME_QSL(GetSegmValue), pfun);

		DebugOut("QSlider :import %d function", count);
		m_hm = hm;

	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}

void QSlider::SetMinValue(float v)
{
	return __FUNCTINNAME_QSL(SetMinValue)(qwm,v);
}

void QSlider::SetMaxValue(float v)
{
	return __FUNCTINNAME_QSL(SetMaxValue)(qwm, v);
}

void QSlider::SetCurrentValue(float v)
{
	return __FUNCTINNAME_QSL(SetCurrentValue)(qwm, v);
}

unsigned int QSlider::SetRailColor(unsigned int color)
{
	return __FUNCTINNAME_QSL(SetRailColor)(qwm, color);
}

float QSlider::SetRailRatio(float ato)
{
	return __FUNCTINNAME_QSL(SetRailRatio)(qwm, ato);
}

void QSlider::IsSegmentation(bool b)
{
	return __FUNCTINNAME_QSL(IsSegmentation)(qwm, b);
}

int QSlider::ClearSegmArr()
{
	return __FUNCTINNAME_QSL(ClearSegmArr)(qwm);
}

int QSlider::AddSegmVuale(float v)
{
	return __FUNCTINNAME_QSL(AddSegmVuale)(qwm,v);
}

int QSlider::RemoveSegmVuale(float v)
{
	return __FUNCTINNAME_QSL(RemoveSegmVuale)(qwm, v);
}

void QSlider::SetDirection(unsigned char d)
{
	return __FUNCTINNAME_QSL(SetDirection)(qwm, d);
}

QDWORD QSlider::SetValueChangeEvent(QSLIDER_VALUE_CHANGE ev)
{
	return __FUNCTINNAME_QSL(SetValueChangeEvent)(qwm,ev);
}

unsigned int QSlider::SetColor(unsigned int color)
{

	return __FUNCTINNAME_QSL(SetColor)(qwm, color);
}

int QSlider::GetSegmValue(float* arr, int bufL)
{
	return __FUNCTINNAME_QSL(GetSegmValue)(qwm, arr,bufL);
}



#endif // __QSLIDER__
#ifdef __QPROGRESS__

#define __QFLAG QPRO
#define __FUNCTINNAME(name) QPRO##name
#define __FUNCTINNAME_STR(name) "QPRO" #name
#define __GDefineFun_NM(name) __GDefineFun(QProgress,__QDefineType(name),name)
HMODULE QProgress::m_hm;
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetDirection));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetStyle));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetCurrentValue));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetLineTypeProgressColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetDecimalPlaces));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetRingProgressColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetRingProgressThickness));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetStyle));
QProgress::QProgress(HDC winddc, const QRect& rf):QCtrlBaseD2DIPD(winddc, rf)
{
}

int QProgress::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
		const char* fName = __FUNCTINNAME_STR(SetDirection);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetDirection), pfun);

		fName = __FUNCTINNAME_STR(GetStyle);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetStyle), pfun);

		fName = __FUNCTINNAME_STR(SetStyle);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetStyle), pfun);

		fName = __FUNCTINNAME_STR(SetCurrentValue);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetCurrentValue), pfun);
	
		fName = __FUNCTINNAME_STR(SetLineTypeProgressColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetLineTypeProgressColor), pfun);

		fName = __FUNCTINNAME_STR(SetDecimalPlaces);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetDecimalPlaces), pfun);

		fName = __FUNCTINNAME_STR(SetRingProgressColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetRingProgressColor), pfun);

		fName = __FUNCTINNAME_STR(SetRingProgressThickness);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetRingProgressThickness), pfun);

		DebugOut("QProgress :import %d function", count);
		m_hm = hm;

	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}

void QProgress::SetDirection(unsigned char d)
{
	return __FUNCTINNAME(SetDirection)(qwm, d);
}

void QProgress::SetStyle(unsigned int style)
{
	return __FUNCTINNAME(SetStyle)(qwm, style);
}

void QProgress::SetCurrentValue(float v)
{
	return __FUNCTINNAME(SetCurrentValue)(qwm, v);
}

void QProgress::SetLineTypeProgressColor(unsigned int color)
{
	return __FUNCTINNAME(SetLineTypeProgressColor)(qwm, color);
}

void QProgress::SetDecimalPlaces(unsigned char dp)
{
	return __FUNCTINNAME(SetDecimalPlaces)(qwm, dp);
}

void QProgress::SetRingProgressColor(unsigned int color1, unsigned int color2)
{
	return __FUNCTINNAME(SetRingProgressColor)(qwm, color1, color2);
}

void QProgress::SetRingProgressThickness(float thickness)
{
	return __FUNCTINNAME(SetRingProgressThickness)(qwm, thickness);
}

unsigned int QProgress::GetStyle()
{
	return __FUNCTINNAME(GetStyle)(qwm);
}

#endif // __QPROGRESS__
#ifdef __QCOLORBOX__
#define __QFLAG QCOLORB
#define __FUNCTINNAME(name) QCOLORB##name
#define __FUNCTINNAME_STR(name) "QCOLORB"#name
#define __GDefineFun_NM(name) __GDefineFun(QColorBox,__QDefineType(name),name)
HMODULE QColorBox::m_hm = nullptr;
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetColorChangeEvent));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth));

QColorBox::QColorBox(HDC winddc, const QRect& rf):QCtrlBaseD2DIPD(winddc, rf)
{

}

int QColorBox::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
		const char* fName = __FUNCTINNAME_STR(GetColor);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetColor), pfun);

		fName = __FUNCTINNAME_STR(SetColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetColor), pfun);

		fName = __FUNCTINNAME_STR(SetColorChangeEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetColorChangeEvent), pfun);

		fName = __FUNCTINNAME_STR(SetPopDialogHeight);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetPopDialogHeight), pfun);

		fName = __FUNCTINNAME_STR(SetPopDialogWidth);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetPopDialogWidth), pfun);

		DebugOut("QColorBox :import %d function", count);
		m_hm = hm;

	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}

unsigned int QColorBox::GetColor()
{
	return __FUNCTINNAME(GetColor)(qwm);
}

unsigned int QColorBox::SetColor(unsigned int color)
{
	return __FUNCTINNAME(SetColor)(qwm,color);
}

QCOLORBOX_CHANGE QColorBox::SetColorChangeEvent(QCOLORBOX_CHANGE ev)
{
	return __FUNCTINNAME(SetColorChangeEvent)(qwm, ev);
}

void QColorBox::SetPopDialogHeight(int h)
{
	return __FUNCTINNAME(SetPopDialogHeight)(qwm, h);
}

void QColorBox::SetPopDialogWidth(int w)
{
	return __FUNCTINNAME(SetPopDialogWidth)(qwm, w);
}



#endif // __QCOLORBOX__

#ifdef __QSELECT__
#define __QFLAG QSELECT
#define __FUNCTINNAME(name) QSELECT##name
#define __FUNCTINNAME_STR(name) "QSELECT"#name
#define __GDefineFun_NM(name) __GDefineFun(QSelect,__QDefineType(name),name)

HMODULE QSelect::m_hm = nullptr;
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetPopDialogHeight));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetPopDialogWidth));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, InsertItem));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, RemoveItem));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetButtonRatio));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetItemHeight));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetItemFontName));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetItemFontSize));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetSelectedText));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetItemText));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetItemBKColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetItemFontColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetSelectChangeEvent));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetItemCount));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, SetCurrentItem));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetIndex));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetItemFontColor));
__GDefineFun_NM(__EXTERN_FFUN(__QFLAG, GetItemBKColor));
QSelect::QSelect(HDC winddc, const QRect& rf):QCtrlBaseD2DIPD(winddc, rf)
{
}

int QSelect::init(HMODULE hm)
{
	int count = 0;
	if (!m_hm) {
		const char* fName = __FUNCTINNAME_STR(SetPopDialogHeight);
		void* pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetPopDialogHeight), pfun);

		fName = __FUNCTINNAME_STR(GetItemFontColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetItemFontColor), pfun);

		fName = __FUNCTINNAME_STR(GetItemBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetItemBKColor), pfun);

		fName = __FUNCTINNAME_STR(GetIndex);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetIndex), pfun);

		fName = __FUNCTINNAME_STR(SetPopDialogWidth);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetPopDialogWidth), pfun);

		fName = __FUNCTINNAME_STR(InsertItem);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(InsertItem), pfun);

		fName = __FUNCTINNAME_STR(RemoveItem);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(RemoveItem), pfun);

		fName = __FUNCTINNAME_STR(SetButtonRatio);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetButtonRatio), pfun);

		fName = __FUNCTINNAME_STR(SetItemHeight);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetItemHeight), pfun);

		fName = __FUNCTINNAME_STR(SetItemFontName);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetItemFontName), pfun);

		fName = __FUNCTINNAME_STR(SetItemFontSize);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetItemFontSize), pfun);

		fName = __FUNCTINNAME_STR(GetSelectedText);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetSelectedText), pfun);

		fName = __FUNCTINNAME_STR(GetItemText);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetItemText), pfun);

		fName = __FUNCTINNAME_STR(SetItemBKColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetItemBKColor), pfun);

		fName = __FUNCTINNAME_STR(SetItemFontColor);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetItemFontColor), pfun);

		fName = __FUNCTINNAME_STR(SetSelectChangeEvent);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetSelectChangeEvent), pfun);

		fName = __FUNCTINNAME_STR(GetItemCount);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(GetItemCount), pfun);

		fName = __FUNCTINNAME_STR(SetCurrentItem);
		pfun = QEXPORTFUNC::QExportFunction(hm, fName);
		if (pfun)++count;
		QEXPORTFUNC::__FUNADDRESS(__FUNCTINNAME(SetCurrentItem), pfun);

		DebugOut("QSelect :import %d function", count);
		m_hm = hm;

	}
	QCtrlBaseD2DIPD::init(hm);
	return count;
}

void QSelect::SetPopDialogHeight(int h)
{
	return __FUNCTINNAME(SetPopDialogHeight)(qwm, h);
}

void QSelect::SetPopDialogWidth(int w)
{
	return __FUNCTINNAME(SetPopDialogWidth)(qwm, w);
}

int QSelect::InsertItem(const wchar_t* text, int index)
{
	return __FUNCTINNAME(InsertItem)(qwm, text, index);
}

int QSelect::RemoveItem(int index)
{
	return __FUNCTINNAME(RemoveItem)(qwm, index);
}

void QSelect::SetButtonRatio(float rat)
{
	return __FUNCTINNAME(SetButtonRatio)(qwm, rat);
}

void QSelect::SetItemHeight(float h)
{
	return __FUNCTINNAME(SetItemHeight)(qwm, h);
}

void QSelect::SetItemFontName(const wchar_t* nm)
{
	return __FUNCTINNAME(SetItemFontName)(qwm, nm);
}

void QSelect::SetItemFontSize(float size)
{
	return __FUNCTINNAME(SetItemFontSize)(qwm, size);
}

std::wstring QSelect::GetSelectedText()
{
	return std::wstring(__FUNCTINNAME(GetSelectedText)(qwm));
}

std::wstring QSelect::GetItemText(int index)
{
	return std::wstring(__FUNCTINNAME(GetItemText)(qwm, index));
}

void QSelect::SetItemBKColor(int index, unsigned int c1, unsigned int c2, unsigned char d)
{
	return __FUNCTINNAME(SetItemBKColor)(qwm, index,c1,c2,d);
}

void QSelect::SetItemFontColor(int index, unsigned int c1, unsigned int c2, unsigned char d)
{
	return __FUNCTINNAME(SetItemFontColor)(qwm, index, c1, c2, d);
}

QSELECT_SELECTCHANGE QSelect::SetSelectChangeEvent(QSELECT_SELECTCHANGE ev)
{
	return __FUNCTINNAME(SetSelectChangeEvent)(qwm, ev);
}

size_t QSelect::GetItemCount()
{
	return __FUNCTINNAME(GetItemCount)(qwm);
}

int QSelect::SetCurrentItem(int index)
{
	return __FUNCTINNAME(SetCurrentItem)(qwm, index);
}

int QSelect::GetIndex()
{
	return __FUNCTINNAME(GetIndex)(qwm);
}

int QSelect::GetItemFontColor(int index, unsigned char* dire, unsigned int* pc1, unsigned int* pc2)
{
	return __FUNCTINNAME(GetItemFontColor)(qwm,index, dire, pc1, pc2);
}

int QSelect::GetItemBKColor(int index, unsigned char* dire, unsigned int* pc1, unsigned int* pc2)
{
	return __FUNCTINNAME(GetItemBKColor)(qwm, index, dire, pc1, pc2);
}






#endif // __QSELECT__