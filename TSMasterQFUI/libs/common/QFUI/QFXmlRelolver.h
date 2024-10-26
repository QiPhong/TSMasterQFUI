#pragma once
#include <format>
#include "tinyxml2.h"
#include <string>
#include <regex>
#include <map>
#include "QFUI.h"
typedef std::wstring(*PICPATHCONVERTOR)(const char*);
namespace QFUSE 
{
	//extern std::map<std::string, int> g_connectFun;
	extern PICPATHCONVERTOR g_picPathCtor;
	void ExplainXML(const char* xmlText);
	void SetPicPathConvertor(PICPATHCONVERTOR fun);
	void* AnalUI(tinyxml2::XMLElement* ele);
	QRect XML2Rect(const std::string& data);
	QPointF XML2Point(const std::string& data);
	void* XMLCreateButton(tinyxml2::XMLElement* ele);
	void* XMLCreateEdit(tinyxml2::XMLElement* ele);
	void* XMLCreateReportForm(tinyxml2::XMLElement* ele);
	void* XMLCreatePictureBox(tinyxml2::XMLElement* ele);
	void* XMLCreateProgressBarCar(tinyxml2::XMLElement* ele);
	void* XMLCreateLineChart(tinyxml2::XMLElement* ele);
	void* XMLCreateTable(tinyxml2::XMLElement* ele);
	void* XMLCreateCATLBarChart(tinyxml2::XMLElement* ele);
	void* XMLCreateCATLTempeChart(tinyxml2::XMLElement* ele);
	void* XMLCreateDrawer(tinyxml2::XMLElement* ele);
	void* XMLCreateHLayout(tinyxml2::XMLElement* ele);
	void* XMLCreateVLayout(tinyxml2::XMLElement* ele);
	void* XMLCreateTLayout(tinyxml2::XMLElement* ele);
	void* XMLCreateStaticText(tinyxml2::XMLElement* ele);
	void* AnalUI(tinyxml2::XMLElement* ele);
	std::wstring stringToWString(const std::string& str);
	std::string wstring_to_string(const std::wstring& wstr);
};

namespace QFUSE_EW
{
	struct CtrlAttribute 
	{
		std::string createT;
		QHost* qhp = nullptr;
		DLLImportQWND* parent = nullptr;

	};
	extern std::map<int, CtrlAttribute> g_allCtrl;
	void ExplainXML(const char* xmlText, DLLImportQWND* parent);

};