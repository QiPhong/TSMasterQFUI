#include "QFXmlRelolver.h"
#include <windows.h>
#include "QFTypes.h"





namespace QFUSE
{
	PICPATHCONVERTOR g_picPathCtor = nullptr;
	std::wstring stringToWString(const std::string& str) {
		// 计算转换所需的缓冲区大小
		int size_needed = MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.size()), NULL, 0);
		std::wstring wstr(size_needed, 0);

		// 执行转换
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.size()), &wstr[0], size_needed);

		return wstr;
	}
	std::string wstring_to_string(const std::wstring& wstr) {
		if (wstr.empty()) {
			return std::string();
		}

		int size_needed = WideCharToMultiByte(CP_ACP, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string str(size_needed, 0);
		WideCharToMultiByte(CP_ACP, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
		return str;
	}
	//std::map<std::string, int> g_connectFun;
	

	//取函数地址
	void* GetEventFun(const char* name)
	{
		/*std::string fn(name);
		auto it = g_connectFun.find(fn);
		if (it == g_connectFun.end())return nullptr;


		return (void*)it->second;*/
		//return nullptr;
		return (void*)FindEventFun(name);
	}
	QRect XML2Rect(const std::string& data) {
		QRect rect;
		std::regex pattern(R"(\((\d+),(\d+),(\d+),(\d+)\))");
		std::smatch matches;
		int ci[4];
		if (std::regex_match(data, matches, pattern)) {
			if (matches.size() == 5) { // matches[0] is the whole match, matches[1] to matches[4] are the groups
				for (size_t i = 1; i < matches.size(); ++i) {
					ci[i - 1] = std::stoi(matches[i].str());
				}
			}
		}
		rect.X = ci[0];
		rect.Y = ci[1];
		rect.Width = ci[2];
		rect.Height = ci[3];
		return rect;
	}
	QPointF XML2Point(const std::string& data) {
		QPointF point;
		// 定义正则表达式模式，匹配整数或小数形式的坐标点
		std::regex pattern(R"(\(\s*([-+]?\d*\.?\d+)\s*,\s*([-+]?\d*\.?\d+)\s*\))");

		// 定义一个smatch对象用于存储匹配结果
		std::smatch match;

		// 查找第一个匹配项
		if (std::regex_search(data, match, pattern)) {

			// 提取并输出x和y的值
			point.X = std::stod(match[1].str());
			point.Y = std::stod(match[2].str());

		}
		return point;
	}

	void* XMLCreateButton(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建按钮代码
		QButton* qct = (QButton*)QFUSE::CreateQWND("QFButton", rect);
		if (!qct)return qct;


		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给按钮设置名称
				qct->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//添加给按钮设置文本
				qct->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("onClick" == na) {
				qct->SetClickEvent(QFBUTTONCLICK(GetEventFun(attr->Value())));
			}
			else if ("fontName" == na) {
				qct->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				qct->SetFontSize(std::stoi(attr->Value()));
			}

			attr = attr->Next();
		}

		return qct;//返回按钮指针
	}
	void* XMLCreateButton2(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建按钮代码
		QButton2* qct = (QButton2*)QFUSE::CreateQWND("QFPButton", rect);
		if (!qct)return qct;


		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给按钮设置名称
				qct->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//添加给按钮设置文本
				qct->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("onClick" == na) {
				qct->SetClickEvent(QFBUTTONCLICK(GetEventFun(attr->Value())));
			}
			else if ("fontName" == na) {
				qct->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				qct->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				qct->SetFontColor(color);

			}
			else if ("bkColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				qct->SetBKColor(color);

			}
			attr = attr->Next();
		}

		return qct;//返回按钮指针
	}
	void* XMLCreateEdit(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建编辑框代码
		QEdit* ctrl = (QEdit*)QFUSE::CreateQWND("QFEdit", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//添加给编辑框设置文本
				ctrl->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("TextChange" == na) {
				ctrl->SetChangeEvent(QEDIT_CHANGE_EVENT(GetEventFun(attr->Value())),0);
		
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateReportForm(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建报表代码
		QReportForm* ctrl = (QReportForm*)QFUSE::CreateQWND("QFReportForm", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("IsDrag" == na) {
				std::string str(attr->Value());
				std::transform(str.begin(), str.end(), str.begin(),
					[](unsigned char c) { return std::tolower(c);
					});
				if ("true" == str) {
					ctrl->IsIsDrag(true);
				}
				else {
					ctrl->IsIsDrag(false);
				}
			}
			else if ("TitleHeight" == na) {
				ctrl->SetTitleHeight(std::stoi(attr->Value()));
			}

			attr = attr->Next();
		}
		//表项设置
		tinyxml2::XMLElement* FTitle = ele->FirstChildElement("FTitle");
		if (FTitle) {
			for (tinyxml2::XMLElement* child = FTitle->FirstChildElement("FItem"); child != nullptr; child = child->NextSiblingElement("FItem")) {

				const tinyxml2::XMLAttribute* name = child->FindAttribute("text");
				const tinyxml2::XMLAttribute* width = child->FindAttribute("width");
				if (name && width) {
					//用宽度和文本插入一个表项
					ctrl->InsertTitle(stringToWString(name->Value()), std::stoi(width->Value()));
				}
			}

		}



		return ctrl;//返回按钮指针
	}
	void* XMLCreatePictureBox(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建图片框代码
		QPictureBox* ctrl = (QPictureBox*)QFUSE::CreateQWND("QFPictureBox", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("path" == na) {
				//添加给图片框加载图片，按路径加载
				std::string spath(attr->Value());
				std::wstring path = stringToWString(spath);

				if (g_picPathCtor) {
					path = g_picPathCtor(spath.c_str());
				}
				ctrl->LoadPicture(path);
			}
			else if ("Transparency" == na) {
				unsigned char tp = 255 * std::stod(attr->Value());
				//ctrl->SetTransparency(tp);
				ctrl->SetTransparency(tp);
			}

			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateProgressBarCar(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建车型进度条代码
		QProgressBarCar* ctrl = (QProgressBarCar*)QFUSE::CreateQWND("QFProgressBarCar", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("posit" == na) {
				//添加给车型进度条设置进度
				ctrl->SetPercentage(std::stod(attr->Value()));
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateLineChart(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建线性图表代码
		QLineChart* ctrl = (QLineChart*)QFUSE::CreateQWND("QFLineChart", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("legfontName" == na) {
				ctrl->SetLegFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("legfontSize" == na) {
				ctrl->SetLegFontSize(std::stoi(attr->Value()));
			}
			else if ("XAxisStrHeight" == na) {
				ctrl->SetXAxisStrHeight(std::stod(attr->Value()));
			}
			else if ("YAxisStrWidth" == na) {
				ctrl->SetYAxisStrWidth(std::stod(attr->Value()));
			}
			else if ("XAxisScaleWidth" == na) {
				ctrl->SetXAxisScaleWidth(std::stod(attr->Value()));
			}
			else if ("YAxisScaleWidth" == na) {
				ctrl->SetYAxisScaleWidth(std::stod(attr->Value()));
			}
			else if ("LineWidth" == na) {
				ctrl->SetLineWidth(std::stod(attr->Value()));
			}
			else if ("XAxisRange" == na) {
				QPointF point = XML2Point(attr->Value());
				ctrl->SetXAxisRange(point.X, point.Y);
			}
			else if ("YAxisRange" == na) {
				QPointF point = XML2Point(attr->Value());
				ctrl->SetYAxisRange(point.X, point.Y);
			}
			else if ("LegWidth" == na) {
				ctrl->SetLegWidth(std::stod(attr->Value()));
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateTable(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建多页标签代码
		QTabs* ctrl = (QTabs*)QFUSE::CreateQWND("QFTabs", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			attr = attr->Next();
		}
		//标签内容
		tinyxml2::XMLElement* Tables = ele->FirstChildElement("Tables");
		if (Tables) {
			int index = 0;
			for (tinyxml2::XMLElement* child = Tables->FirstChildElement("Table"); child != nullptr; child = child->NextSiblingElement("Table"), ++index) {

				const tinyxml2::XMLAttribute* text = child->FindAttribute("text");
				if (text) {
					//插入一个标签
					//是否有图标
					const tinyxml2::XMLAttribute* ico = child->FindAttribute("ico");
					if (ico) {
						std::string spath(ico->Value());
						std::wstring path = stringToWString(spath);

						if (g_picPathCtor) {
							path = g_picPathCtor(spath.c_str());
						}
						//插入一个标签(带图标的)
						ctrl->AddTab(stringToWString(text->Value()).c_str(), path.c_str());

					}
					else {
						ctrl->AddTab(stringToWString(text->Value()).c_str());
					}
					//查看有没有附加控件
					for (tinyxml2::XMLElement* childCtrl = child->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
						//返回创建一个控件
						DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl);
						//如果控件指针不为空，则加入当前标签
						if (p) {
							ctrl->AttachCtrl(p, index);
						}

					}

				}





			}

		}


		return ctrl;//返回按钮指针
	}
	void* XMLCreateCATLBarChart(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QCATLBarChart* ctrl = (QCATLBarChart*)QFUSE::CreateQWND("QFCATLBarChart", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("ScaleColor" == na) {
				ctrl->SetScaleColor(std::stoi(attr->Value()));
			}
			else if ("ScaleMax" == na) {
				ctrl->SetScaleMax(std::stof(attr->Value()));
			}
			else if ("ScaleMin" == na) {
				ctrl->SetScaleMin(std::stof(attr->Value()));
			}
			else if ("ScaleWidth" == na) {
				ctrl->SetScaleWidth(std::stof(attr->Value()));
			}
			else if ("ScaleHeight" == na) {
				ctrl->SetScaleHeight(std::stof(attr->Value()));
			}
			else if ("BarChartWidth" == na) {
				ctrl->SetBarChartWidth(std::stof(attr->Value()));
			}
			else if ("GridWidth" == na) {
				ctrl->SetGridWidth(std::stof(attr->Value()));
			}
			else if ("LineWidth" == na) {
				ctrl->SetLineWidth(std::stof(attr->Value()));
			}
			else if ("YAxisStrWidth" == na) {
				ctrl->SetYAxisStrWidth(std::stof(attr->Value()));
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateCATLTempeChart(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QCATLTempeChart* ctrl = (QCATLTempeChart*)QFUSE::CreateQWND("QFCATLTempeChart", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("UnitWidth" == na) {
				ctrl->SetUnitWidth(std::stod(attr->Value()));
			}
			else if ("UnitFontSize" == na) {
				ctrl->SetUnitFontSize(std::stod(attr->Value()));
			}
			else if ("UnitIntervalWidth" == na) {
				ctrl->SetUnitIntervalWidth(std::stod(attr->Value()));
			}
			else if ("AlignWidth" == na) {
				ctrl->SetAlignWidth(std::stod(attr->Value()));
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateDrawer(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QDrawer* ctrl = (QDrawer*)QFUSE::CreateQWND("QFDrawer", rect);
		if (!ctrl)return ctrl;

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("onSelected" == na) {
				ctrl->SetSelectEvent(QDRAWERSELECT(GetEventFun(attr->Value())));
			}
			attr = attr->Next();
		}
		//项目内容
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			int index = 0;
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("Category"); child != nullptr; child = child->NextSiblingElement("Category"), ++index) {
				ctrl->InsertDrawer(-1);
				int id = ctrl->GetDrawerCount()-1;
				const tinyxml2::XMLAttribute* name = child->FindAttribute("name");
				if (name) {
					std::string v(name->Value());
					ctrl->SetDrawerName(id, stringToWString(v).c_str());
				}
				for (tinyxml2::XMLElement* Subkey = child->FirstChildElement("Subkey"); Subkey != nullptr; Subkey = Subkey->NextSiblingElement("Subkey")) {
				
					const tinyxml2::XMLAttribute* nm = Subkey->FindAttribute("name");
					if (nm) {
						std::string text = nm->Value();

						ctrl->InsertSubObject(id, -1);
						int sid = ctrl->GetSubObjectCount(id) - 1;
						ctrl->SetSubObjectName(id, sid, stringToWString(text).c_str());

					}
				
				
				
				}

			}

		}



		return ctrl;//返回按钮指针
	}

	void* XMLCreateHLayout(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建水平布局器代码
		QHLayout* ctrl = (QHLayout*)QFUSE::CreateQWND("QFHLayout", rect);
		if (!ctrl)return ctrl;



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}

			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {
				unsigned int weight = 0;
				auto cattri = childCtrl->FindAttribute("weight");
				if (cattri) {
					weight = std::strtoul(cattri->Value(), nullptr, 10);
				}
				ctrl->InsertCtrl(p, weight);

			}

		}


		return ctrl;//返回按钮指针
	}

	void* XMLCreateVLayout(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建垂直布局器代码
		QVLayout* ctrl = (QVLayout*)QFUSE::CreateQWND("QFVLayout", rect);
		if (!ctrl)return ctrl;
		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}

			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {
				unsigned int weight = 0;
				auto cattri = childCtrl->FindAttribute("weight");
				if (cattri) {
					weight = std::strtoul(cattri->Value(), nullptr, 10);
				}
				ctrl->InsertCtrl(p, weight);
			}


		}


		return ctrl;//返回按钮指针
	}
	void* XMLCreateTLayout(tinyxml2::XMLElement* ele)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建垂直布局器代码
		QTLayout* ctrl = (QTLayout*)QFUSE::CreateQWND("QFTLayout", rect);
		if (!ctrl)return ctrl;
		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}

			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {


				ctrl->SetCtrl(p->qwm);
			}


		}


		return ctrl;//返回按钮指针
	}

	void* XMLCreateStaticText(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QStaticText* ctrl = (QStaticText*)QFUSE::CreateQWND("QFStaticText", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//设置静态文本的文本
				ctrl->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			else if ("backgroundColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetBKColor(color);
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	void* XMLCreateSlider(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QSlider* ctrl = (QSlider*)QFUSE::CreateQWND("QFSlider", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Direction" == na) {
				//设置静态文本的文本
				ctrl->SetDirection(std::strtol(attr->Value(), nullptr, 10));
			}
			else if ("IsSegmentation" == na) {
				if ("true" == value) {
					ctrl->IsSegmentation(true);
				}
				else {
					ctrl->IsSegmentation(false);
				}

			}
			else if ("RailColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);

				ctrl->SetRailColor(color);
			}
			else if ("RailRatio" == na) {
				double rat = std::strtod(attr->Value(), nullptr);
				ctrl->SetRailRatio(rat);
			}
			else if ("backgroundColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetColor(color);
			}
			else if ("maxValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetMaxValue(v);
			}
			else if ("minValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetMinValue(v);
			}
			else if ("currentValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetCurrentValue(v);
			}
			else if ("ValueChangeEvent" == na) {
				//添加数值改变函数回调函数
				ctrl->SetValueChangeEvent((QSLIDER_VALUE_CHANGE)GetEventFun(attr->Value()));
			}
			attr = attr->Next();
		}
		const tinyxml2::XMLAttribute* currentValue = ele->FindAttribute("currentValue");
		if (currentValue) {
			double v = std::strtod(currentValue->Value(), nullptr);
			ctrl->SetCurrentValue(v);
		
		}

		//分段值
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("SegmValue"); child != nullptr; child = child->NextSiblingElement("SegmValue")) {

				const tinyxml2::XMLAttribute* value = child->FindAttribute("value");

				if (value) {
					//加入一个分段
					ctrl->AddSegmVuale(std::strtod(value->Value(), nullptr));
				}
			}

		}


		return ctrl;//返回按钮指针
	}
	void* XMLCreateSwitch(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QSwitch* ctrl = (QSwitch*)QFUSE::CreateQWND("QFSwitch", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("IsMutex" == na) {
				if ("true") {
					ctrl->IsMutex(true);
				}
				else {
					ctrl->IsMutex(false);
				}

			}
			else if ("State" == na) {
				if ("true") {
					ctrl->SetState(true);
				}
				else {
					ctrl->SetState(false);
				}
			}
			else if ("StateChangeEvent" == na) {
				//添加转态变动
				ctrl->SetStateChangeEvent((QSWITCH_STATE_CHANGE)GetEventFun(attr->Value()));
			}

			attr = attr->Next();
		}
		
		return ctrl;//返回按钮指针
	}
	void* XMLCreateProgress(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QProgress* ctrl = (QProgress*)QFUSE::CreateQWND("QFProgress", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();
		unsigned int c1 = 0, c2 = 0;
		int rcCount = 0;
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("CurrentValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetCurrentValue(v);
			}
			else if ("DecimalPlaces" == na) {

				unsigned char v = std::strtoul(attr->Value(), nullptr, 10);
				ctrl->SetDecimalPlaces(v);
			}
			else if ("Direction" == na) {
				unsigned char v = std::strtoul(attr->Value(), nullptr, 10);
				ctrl->SetDirection(v);
			}
			else if ("FontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			else if ("LineTypeColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetLineTypeProgressColor(color);
			}
			else if ("RingTypeColor1" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				c1 = std::strtoul(attr->Value(), nullptr, para);
				++rcCount;
				if (rcCount > 1)
					ctrl->SetRingProgressColor(c1, c2);
			}
			else if ("RingTypeColor2" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				c2 = std::strtoul(attr->Value(), nullptr, para);
				++rcCount;
				if (rcCount > 1)
					ctrl->SetRingProgressColor(c1, c2);
			}
			else if ("FontName" == na) {

				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("FontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
			else if ("RingProgressThickness" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetRingProgressThickness(v);
			}
			else if ("Type" == na) {
				unsigned int v = std::strtoul(attr->Value(), nullptr, 10);
				ctrl->SetStyle(v);
			}
			attr = attr->Next();
		}
	
		return ctrl;//返回按钮指针
	}
	void* XMLCreateColorBox(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QColorBox* ctrl = (QColorBox*)QFUSE::CreateQWND("QFColorBox", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {

				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("fontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
			else if ("ColorChangeEvent" == na) {
				ctrl->SetColorChangeEvent((QCOLORBOX_CHANGE)GetEventFun(attr->Value()));
				
			}
			attr = attr->Next();
		}
		return ctrl;//返回按钮指针
	}
	void* XMLCreateSelect(tinyxml2::XMLElement* ele)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//添加一个创建控件代码
		QSelect* ctrl = (QSelect*)QFUSE::CreateQWND("QFSelect", rect);
		if (!ctrl)return ctrl;


		attr = ele->FirstAttribute();
		//项目
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("Item"); child != nullptr; child = child->NextSiblingElement("Item")) {
				const tinyxml2::XMLAttribute* value = child->FindAttribute("value");
				if (value) {
					ctrl->InsertItem(stringToWString(std::string(value->Value())).c_str());
					const tinyxml2::XMLAttribute* fcolor1 = child->FindAttribute("fcolor1");
					const tinyxml2::XMLAttribute* fcolorD = child->FindAttribute("fcolorD");
					const tinyxml2::XMLAttribute* fcolor2 = child->FindAttribute("fcolor2");
					const tinyxml2::XMLAttribute* colorD = child->FindAttribute("colorD");
					const tinyxml2::XMLAttribute* color1 = child->FindAttribute("color1");
					const tinyxml2::XMLAttribute* color2 = child->FindAttribute("color2");
					unsigned char d = std::strtoul(colorD->Value(), nullptr, 10);
					int para = 10;
					if ('x' == std::tolower(color1->Value()[1]))para = 16;
					unsigned int c1 = std::strtoul(color1->Value(), nullptr, para);
					para = 10;
					if ('x' == std::tolower(color2->Value()[1]))para = 16;
					unsigned int c2 = std::strtoul(color2->Value(), nullptr, para);
					ctrl->SetItemBKColor(-1,  c1, c2, d);

					d = std::strtoul(fcolorD->Value(), nullptr, 10);
					para = 10;
					if ('x' == std::tolower(fcolor1->Value()[1]))para = 16;
					c1 = std::strtoul(fcolor1->Value(), nullptr, para);
					para = 10;
					if ('x' == std::tolower(fcolor2->Value()[1]))para = 16;
					c2 = std::strtoul(fcolor2->Value(), nullptr, para);

					ctrl->SetItemFontColor(-1,  c1, c2, d);

				}
			}

		}
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {

				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("fontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
			else if ("CurrentItem" == na) {
				int v = std::strtol(attr->Value(), nullptr, 10);
				ctrl->SetCurrentItem(v);
			}
			else if ("FontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);;
				ctrl->SetFontColor(color);
			}
			else if ("ItemFontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetItemFontSize(v);
			}
			else if ("ItemHeight" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetItemHeight(v);
			}
			else if ("PopDialogHeight" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetPopDialogHeight(v);
			}
			else if ("PopDialogWidth" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetPopDialogWidth(v);
			}
			else if ("SelectChangeEvent" == na) {
				//添加转态变动
				ctrl->SetSelectChangeEvent((QSELECT_SELECTCHANGE)GetEventFun(attr->Value()));
			}
			attr = attr->Next();
		}

		return ctrl;//返回按钮指针
	}
	
	void* AnalUI(tinyxml2::XMLElement* ele)
	{
		std::string na = ele->Name();
		if ("QFButton" == na) {
			return XMLCreateButton(ele);

		}
		else if ("QFPButton" == na) {
			return XMLCreateButton2(ele);

		}
		else if ("QFEdit" == na) {
			return XMLCreateEdit(ele);

		}
		else if ("QFReportForm" == na) {
			return XMLCreateReportForm(ele);
		}
		else if ("QFPictureBox" == na) {

			return XMLCreatePictureBox(ele);
		}
		else if ("QFProgressBarCar" == na) {

			return XMLCreateProgressBarCar(ele);
		}
		else if ("QFLineChart" == na) {

			return XMLCreateLineChart(ele);
		}
		else if ("QFTabs" == na) {

			return XMLCreateTable(ele);
		}
		else if ("QFCATLBarChart" == na) {

			return XMLCreateCATLBarChart(ele);
		}
		else if ("QFCATLTempeChart" == na) {

			return XMLCreateCATLTempeChart(ele);
		}
		else if ("QFDrawer" == na) {

			return XMLCreateDrawer(ele);
		}
		else if ("QFHLayout" == na) {

			return XMLCreateHLayout(ele);
		}
		else if ("QFVLayout" == na) {

			return XMLCreateVLayout(ele);
		}
		else if ("QFTLayout" == na) {

			return XMLCreateTLayout(ele);
		}
		else if ("QFStaticText" == na) {

			return XMLCreateStaticText(ele);
		}
		else if ("QFSlider" == na) {

			return XMLCreateSlider(ele);
		}
		else if ("QFSwitch" == na) {

			return XMLCreateSwitch(ele);
		}
		else if ("QFProgress" == na) {

			return XMLCreateProgress(ele);
		}
		else if ("QFColorBox" == na) {

			return XMLCreateColorBox(ele);
		}
		else if ("QFSelect" == na) {

			return XMLCreateSelect(ele);
		}
		return nullptr;
	}
	void ExplainXML(const char* xmlText)
	{
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError result = xmlDoc.Parse(xmlText);
		if (result != tinyxml2::XML_SUCCESS) {
			DebugOut("解析QFUI的XML失败，请确认传入的XML内容是否正确！");
			return ;
		}
		// 获取根元素
		tinyxml2::XMLElement* root = xmlDoc.RootElement();
		if (root == nullptr) {
			DebugOut("解析QFUI的XML失败，找不到跟节点 《QWMange》");
			return ;
		}
		//判断root的name是否为QWMange
		std::string Rname = root->Name();
		if ("QWMange" != Rname) {
			DebugOut("解析QFUI的XML失败，根节点名称错误 \"%s\"", Rname.c_str());
			return ;
		}
		tinyxml2::XMLElement* ele = root->FirstChildElement();
		while (ele) {
			QWND* p = (QWND*)AnalUI(ele);
			if (p) {
				QFUSE::AttachCtrl(p);
			}
			ele = ele->NextSiblingElement();
		}

	}

	void SetPicPathConvertor(PICPATHCONVERTOR fun)
	{
		g_picPathCtor = fun;
	}


};
namespace QFUSE_EW
{
	



	std::wstring stringToWString(const std::string& str) {
		// 计算转换所需的缓冲区大小
		int size_needed = MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.size()), NULL, 0);
		std::wstring wstr(size_needed, 0);

		// 执行转换
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.size()), &wstr[0], size_needed);

		return wstr;
	}
	std::string wstring_to_string(const std::wstring& wstr) {
		if (wstr.empty()) {
			return std::string();
		}

		int size_needed = WideCharToMultiByte(CP_ACP, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string str(size_needed, 0);
		WideCharToMultiByte(CP_ACP, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
		return str;
	}

	std::map<int, CtrlAttribute> g_allCtrl;
	void* AnalUI(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	QRect XML2Rect(const std::string& data);
	QPointF XML2Point(const std::string& data);
	void* XMLCreateButton(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateButton2(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateEdit(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateReportForm(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreatePictureBox(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateProgressBarCar(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateLineChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateTable(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateCATLBarChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateCATLTempeChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateDrawer(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateHLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateVLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateTLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* XMLCreateStaticText(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	void* AnalUI(tinyxml2::XMLElement* ele, DLLImportQWND* parent);
	
	QRect XML2Rect(const std::string& data) {
		QRect rect;
		std::regex pattern(R"(\((\d+),(\d+),(\d+),(\d+)\))");
		std::smatch matches;
		int ci[4];
		if (std::regex_match(data, matches, pattern)) {
			if (matches.size() == 5) { // matches[0] is the whole match, matches[1] to matches[4] are the groups
				for (size_t i = 1; i < matches.size(); ++i) {
					ci[i - 1] = std::stoi(matches[i].str());
				}
			}
		}
		rect.X = ci[0];
		rect.Y = ci[1];
		rect.Width = ci[2];
		rect.Height = ci[3];
		return rect;
	}
	QPointF XML2Point(const std::string& data) {
		QPointF point;
		// 定义正则表达式模式，匹配整数或小数形式的坐标点
		std::regex pattern(R"(\(\s*([-+]?\d*\.?\d+)\s*,\s*([-+]?\d*\.?\d+)\s*\))");

		// 定义一个smatch对象用于存储匹配结果
		std::smatch match;

		// 查找第一个匹配项
		if (std::regex_search(data, match, pattern)) {

			// 提取并输出x和y的值
			point.X = std::stod(match[1].str());
			point.Y = std::stod(match[2].str());

		}
		return point;
	}

	void* XMLCreateButton(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());

		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateButton 创建host失败");
			return nullptr;
		}
		//添加一个创建按钮代码
		QButton* qct = (QButton*)QFUSE::CreateQWND("QFButton", rect);
		if (!qct) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateButton 创建button失败");
			return nullptr;
		}
		host->SetParasiticCtrl(qct);//把按钮寄宿到host上

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给按钮设置名称
				qct->SetQWNDName(attr->Value());
		
			}
			else if ("Text" == na) {
				//添加给按钮设置文本
				qct->SetText(stringToWString(attr->Value()).c_str());
			
			}
			else if ("onClick" == na) {
				//qct->SetClickEvent(QFBUTTONCLICK(GetEventFun(attr->Value())));
				
			}
			else if ("fontName" == na) {
				qct->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				qct->SetFontSize(std::stoi(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(qct->qwm), { "QFButton",host,parent }));


		//把空壳按钮去掉
		qct->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(qct);//从控件集合摘除这个控件的记录
		delete qct;//销毁这个空壳


		return host;//返回按钮宿主的指针
	}
	void* XMLCreateButton2(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());

		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateButton 创建host失败");
			return nullptr;
		}
		//添加一个创建按钮代码
		QButton2* qct = (QButton2*)QFUSE::CreateQWND("QFPButton", rect);
		if (!qct) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateButton 创建button失败");
			return nullptr;
		}
		host->SetParasiticCtrl(qct);//把按钮寄宿到host上

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给按钮设置名称
				qct->SetQWNDName(attr->Value());

			}
			else if ("Text" == na) {
				//添加给按钮设置文本
				qct->SetText(stringToWString(attr->Value()).c_str());

			}
			else if ("onClick" == na) {
				//qct->SetClickEvent(QFBUTTONCLICK(GetEventFun(attr->Value())));

			}
			else if ("fontName" == na) {
				qct->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				qct->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				qct->SetFontColor(color);

			}
			else if ("bkColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				qct->SetBKColor(color);

			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(qct->qwm), { "QFPButton",host,parent }));


		//把空壳按钮去掉
		qct->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(qct);//从控件集合摘除这个控件的记录
		delete qct;//销毁这个空壳


		return host;//返回按钮宿主的指针
	}
	void* XMLCreateEdit(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateEdit 创建host失败");
			return nullptr;
		}
		//添加一个创建编辑框代码
		QEdit* ctrl = (QEdit*)QFUSE::CreateQWND("QFEdit", rect);
		if (!ctrl){
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateEdit 创建edit失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上


		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//添加给编辑框设置文本
				ctrl->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFEdit",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateReportForm(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateReportForm 创建host失败");
			return nullptr;
		}
		//添加一个创建报表代码
		QReportForm* ctrl = (QReportForm*)QFUSE::CreateQWND("QFReportForm", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateReportForm 创建ReportForm失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上




		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("IsDrag" == na) {
				std::string str(attr->Value());
				std::transform(str.begin(), str.end(), str.begin(),
					[](unsigned char c) { return std::tolower(c);
					});
				if ("true" == str) {
					ctrl->IsIsDrag(true);
				}
				else {
					ctrl->IsIsDrag(false);
				}
			}
			else if ("TitleHeight" == na) {
				ctrl->SetTitleHeight(std::stoi(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		//表项设置
		tinyxml2::XMLElement* FTitle = ele->FirstChildElement("FTitle");
		if (FTitle) {
			for (tinyxml2::XMLElement* child = FTitle->FirstChildElement("FItem"); child != nullptr; child = child->NextSiblingElement("FItem")) {

				const tinyxml2::XMLAttribute* name = child->FindAttribute("text");
				const tinyxml2::XMLAttribute* width = child->FindAttribute("width");
				if (name && width) {
					//用宽度和文本插入一个表项
					ctrl->InsertTitle(stringToWString(name->Value()), std::stoi(width->Value()));
				}
			}

		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFReportForm",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreatePictureBox(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreatePictureBox 创建host失败");
			return nullptr;
		}
		//添加一个创建图片框代码
		QPictureBox* ctrl = (QPictureBox*)QFUSE::CreateQWND("QFPictureBox", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreatePictureBox 创建QPictureBox失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("path" == na) {
				//添加给图片框加载图片，按路径加载
				std::wstring path = stringToWString(attr->Value());

				ctrl->LoadPicture(path);
			}
			else if ("Transparency" == na) {
				unsigned char tp = 255 * std::stod(attr->Value());
				//ctrl->SetTransparency(tp);
				ctrl->SetTransparency(tp);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFPictureBox",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateProgressBarCar(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateProgressBarCar 创建host失败");
			return nullptr;
		}
		//添加一个创建车型进度条代码
		QProgressBarCar* ctrl = (QProgressBarCar*)QFUSE::CreateQWND("QFProgressBarCar", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateProgressBarCar 创建QProgressBarCar失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("posit" == na) {
				//添加给车型进度条设置进度
				ctrl->SetPercentage(std::stod(attr->Value()));
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFProgressBarCar",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateLineChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateLineChart 创建host失败");
			return nullptr;
		}
		//添加一个创建线性图表代码
		QLineChart* ctrl = (QLineChart*)QFUSE::CreateQWND("QFLineChart", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateLineChart 创建QLineChart失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stoi(attr->Value()));
			}
			else if ("legfontName" == na) {
				ctrl->SetLegFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("legfontSize" == na) {
				ctrl->SetLegFontSize(std::stoi(attr->Value()));
			}
			else if ("XAxisStrHeight" == na) {
				ctrl->SetXAxisStrHeight(std::stod(attr->Value()));
			}
			else if ("YAxisStrWidth" == na) {
				ctrl->SetYAxisStrWidth(std::stod(attr->Value()));
			}
			else if ("XAxisScaleWidth" == na) {
				ctrl->SetXAxisScaleWidth(std::stod(attr->Value()));
			}
			else if ("YAxisScaleWidth" == na) {
				ctrl->SetYAxisScaleWidth(std::stod(attr->Value()));
			}
			else if ("LineWidth" == na) {
				ctrl->SetLineWidth(std::stod(attr->Value()));
			}
			else if ("XAxisRange" == na) {
				QPointF point = XML2Point(attr->Value());
				ctrl->SetXAxisRange(point.X, point.Y);
			}
			else if ("YAxisRange" == na) {
				QPointF point = XML2Point(attr->Value());
				ctrl->SetYAxisRange(point.X, point.Y);
			}
			else if ("LegWidth" == na) {
				ctrl->SetLegWidth(std::stod(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFLineChart",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateTable(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateTable 创建host失败");
			return nullptr;
		}
		//添加一个创建多页标签代码
		QTabs* ctrl = (QTabs*)QFUSE::CreateQWND("QFTabs", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateTable 创建QTabs失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		//标签内容
		tinyxml2::XMLElement* Tables = ele->FirstChildElement("Tables");
		if (Tables) {
			int index = 0;
			for (tinyxml2::XMLElement* child = Tables->FirstChildElement("Table"); child != nullptr; child = child->NextSiblingElement("Table"), ++index) {

				const tinyxml2::XMLAttribute* text = child->FindAttribute("text");
				if (text) {
					//插入一个标签
					//是否有图标
					const tinyxml2::XMLAttribute* ico = child->FindAttribute("ico");
					if (ico) {
						//插入一个标签(带图标的)
						std::wstring path = stringToWString(ico->Value());
						ctrl->AddTab(stringToWString(text->Value()).c_str(), path.c_str());
					}
					else {
						ctrl->AddTab(stringToWString(text->Value()).c_str());
					}
					//查看有没有附加控件
					for (tinyxml2::XMLElement* childCtrl = child->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
						//返回创建一个控件
						DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl,(DLLImportQWND*)ctrl->qwm);
						//如果控件指针不为空，则加入当前标签
						if (p) {
							ctrl->AttachCtrl(p, index);
						}

					}

				}





			}

		}

		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFTabs",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateCATLBarChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateCATLBarChart 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QCATLBarChart* ctrl = (QCATLBarChart*)QFUSE::CreateQWND("QFCATLBarChart", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateCATLBarChart 创建QFCATLBarChart失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("ScaleColor" == na) {
				ctrl->SetScaleColor(std::stoi(attr->Value()));
			}
			else if ("ScaleMax" == na) {
				ctrl->SetScaleMax(std::stof(attr->Value()));
			}
			else if ("ScaleMin" == na) {
				ctrl->SetScaleMin(std::stof(attr->Value()));
			}
			else if ("ScaleWidth" == na) {
				ctrl->SetScaleWidth(std::stof(attr->Value()));
			}
			else if ("ScaleHeight" == na) {
				ctrl->SetScaleHeight(std::stof(attr->Value()));
			}
			else if ("BarChartWidth" == na) {
				ctrl->SetBarChartWidth(std::stof(attr->Value()));
			}
			else if ("GridWidth" == na) {
				ctrl->SetGridWidth(std::stof(attr->Value()));
			}
			else if ("LineWidth" == na) {
				ctrl->SetLineWidth(std::stof(attr->Value()));
			}
			else if ("YAxisStrWidth" == na) {
				ctrl->SetYAxisStrWidth(std::stof(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}

		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateCATLTempeChart(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateCATLTempeChart 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QCATLTempeChart* ctrl = (QCATLTempeChart*)QFUSE::CreateQWND("QFCATLTempeChart", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateCATLTempeChart 创建QFCATLTempeChart失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("UnitWidth" == na) {
				ctrl->SetUnitWidth(std::stod(attr->Value()));
			}
			else if ("UnitFontSize" == na) {
				ctrl->SetUnitFontSize(std::stod(attr->Value()));
			}
			else if ("UnitIntervalWidth" == na) {
				ctrl->SetUnitIntervalWidth(std::stod(attr->Value()));
			}
			else if ("AlignWidth" == na) {
				ctrl->SetAlignWidth(std::stod(attr->Value()));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFCATLTempeChart",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateDrawer(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateDrawer 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QDrawer* ctrl = (QDrawer*)QFUSE::CreateQWND("QFDrawer", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateDrawer 创建QFDrawer失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("onSelected" == na) {
				//ctrl->SetSelectEvent(QDRAWERSELECT(GetEventFun(attr->Value())));
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
	
		}
		//项目内容
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			int index = 0;
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("Category"); child != nullptr; child = child->NextSiblingElement("Category"), ++index) {
				ctrl->InsertDrawer(-1);
				int id = ctrl->GetDrawerCount() - 1;
				const tinyxml2::XMLAttribute* name = child->FindAttribute("name");
				if (name) {
					std::string v(name->Value());
					ctrl->SetDrawerName(id, stringToWString(v).c_str());
				}
				for (tinyxml2::XMLElement* Subkey = child->FirstChildElement("Subkey"); Subkey != nullptr; Subkey = Subkey->NextSiblingElement("Subkey")) {

					const tinyxml2::XMLAttribute* nm = Subkey->FindAttribute("name");
					if (nm) {
						std::string text = nm->Value();

						ctrl->InsertSubObject(id, -1);
						int sid = ctrl->GetSubObjectCount(id) - 1;
						ctrl->SetSubObjectName(id, sid, stringToWString(text).c_str());

					}



				}

			}
		}



		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFDrawer",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateHLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateProgressBarCar 创建host失败");
			return nullptr;
		}
		//添加一个创建水平布局器代码
		QHLayout* ctrl = (QHLayout*)QFUSE::CreateQWND("QFHLayout", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateHLayout 创建QFHLayout失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上



		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl,(DLLImportQWND*)ctrl->qwm);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {
				unsigned int weight = 0;
				auto cattri = childCtrl->FindAttribute("weight");
				if (cattri) {
					weight = std::strtoul(cattri->Value(), nullptr, 10);
				}
				ctrl->InsertCtrl(p, weight);

			}

		}

		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFHLayout",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateVLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateProgressBarCar 创建host失败");
			return nullptr;
		}
		//添加一个创建垂直布局器代码
		QVLayout* ctrl = (QVLayout*)QFUSE::CreateQWND("QFVLayout", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateVLayout 创建QFVLayout失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上
		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());

			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl, (DLLImportQWND*)ctrl->qwm);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {
				unsigned int weight = 0;
				auto cattri = childCtrl->FindAttribute("weight");
				if (cattri) {
					weight = std::strtoul(cattri->Value(), nullptr, 10);
				}
				ctrl->InsertCtrl(p, weight);
			}


		}

		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFVLayout",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateTLayout(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateTLayout 创建host失败");
			return nullptr;
		}
		//添加一个创建垂直布局器代码
		QTLayout* ctrl = (QTLayout*)QFUSE::CreateQWND("QFTLayout", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateTLayout 创建QFTLayout失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);//把按钮寄宿到host上
		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}

		//查看有没有附加控件
		for (tinyxml2::XMLElement* childCtrl = ele->FirstChildElement(); childCtrl != nullptr; childCtrl = childCtrl->NextSiblingElement()) {
			//返回创建一个控件
			DLLImportQWND* p = (DLLImportQWND*)AnalUI(childCtrl, (DLLImportQWND*)ctrl->qwm);
			//如果控件指针不为空，则加入一个控件到这个布局器
			if (p) {


				ctrl->SetCtrl(p->qwm);
			}


		}

		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFTLayout",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateStaticText(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateStaticText 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QStaticText* ctrl = (QStaticText*)QFUSE::CreateQWND("QFStaticText", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateStaticText 创建QFStaticText失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Text" == na) {
				//设置静态文本的文本
				ctrl->SetText(stringToWString(attr->Value()).c_str());
			}
			else if ("fontName" == na) {
				ctrl->SetFontName(stringToWString(attr->Value()).c_str());
			}
			else if ("fontSize" == na) {
				ctrl->SetFontSize(std::stod(attr->Value()));
			}
			else if ("fontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			else if ("backgroundColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetBKColor(color);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFStaticText",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateSlider(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateSlider 创建host失败");
			return nullptr;
		}
		
		//添加一个创建控件代码
		QSlider* ctrl = (QSlider*)QFUSE::CreateQWND("QFSlider", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateSlider 创建QSlider失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("Direction" == na) {
				//设置静态文本的文本
				ctrl->SetDirection(std::strtol(attr->Value(),nullptr,10));
			}
			else if ("IsSegmentation" == na) {
				if ("true" == value) {
					ctrl->IsSegmentation(true);
				}
				else {
					ctrl->IsSegmentation(false);
				}
		
			}
			else if ("RailColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);

				ctrl->SetRailColor(color);
			}
			else if ("RailRatio" == na) {
				double rat = std::strtod(attr->Value(),nullptr);
				ctrl->SetRailRatio(rat);
			}
			else if ("backgroundColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetColor(color);
			}
			else if ("maxValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetMaxValue(v);
			}
			else if ("minValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetMaxValue(v);
			}
			else if ("currentValue" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetMaxValue(v);
			}
			else if ("ValueChangeEvent" == na) {
				//添加数值改变函数回调函数
			
			}

			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		//分段值
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("SegmValue"); child != nullptr; child = child->NextSiblingElement("SegmValue")) {

				const tinyxml2::XMLAttribute* value = child->FindAttribute("value");
			
				if (value) {
					//加入一个分段
					ctrl->AddSegmVuale(std::strtod(value->Value(),nullptr));
				}
			}

		}




		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFSlider",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateSwitch(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateSwitch 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QSwitch* ctrl = (QSwitch*)QFUSE::CreateQWND("QFSwitch", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateSwitch 创建QFSwitch失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();

		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("IsMutex" == na) {
				if ("true") {
					ctrl->IsMutex(true);
				}
				else {
					ctrl->IsMutex(false);
				}
				
			}
			else if ("State" == na) {
				if ("true") {
					ctrl->SetState(true);
				}
				else {
					ctrl->SetState(false);
				}
			}
			else if ("StateChangeEvent" == na) {
				//添加转态变动
			}

			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFSwitch",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateProgress(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateProgress 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QProgress* ctrl = (QProgress*)QFUSE::CreateQWND("QFProgress", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateProgress 创建QFProgress失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();
		unsigned int c1 = 0,c2=0;
		int rcCount = 0;
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("CurrentValue" == na) {
				double v = std::strtod(attr->Value(),nullptr);
				ctrl->SetCurrentValue(v);
			}
			else if ("DecimalPlaces" == na) {
				
				unsigned char v = std::strtoul(attr->Value(), nullptr,10);
				ctrl->SetDecimalPlaces(v);
			}
			else if ("Direction" == na) {
				unsigned char v = std::strtoul(attr->Value(), nullptr, 10);
				ctrl->SetDirection(v);
			}
			else if ("FontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetFontColor(color);
			}
			else if ("LineTypeColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);
				ctrl->SetLineTypeProgressColor(color);
			}
			else if ("RingTypeColor1" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				c1 = std::strtoul(attr->Value(), nullptr, para);
				++rcCount;
				if(rcCount>1)
				ctrl->SetRingProgressColor(c1, c2);
			}
			else if ("RingTypeColor2" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				c2 = std::strtoul(attr->Value(), nullptr, para);
				++rcCount;
				if (rcCount > 1)
					ctrl->SetRingProgressColor(c1, c2);
			}
			else if ("FontName" == na) {
				
				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("FontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
			else if ("RingProgressThickness" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetRingProgressThickness(v);
			}
			else if ("Type" == na) {
				unsigned int v = std::strtoul(attr->Value(), nullptr,10);
				ctrl->SetStyle(v);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFProgress",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateColorBox(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateColorBox 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QColorBox* ctrl = (QColorBox*)QFUSE::CreateQWND("QFColorBox", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateColorBox 创建QFColorBox失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();
		unsigned int c1 = 0, c2 = 0;
		int rcCount = 0;
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {

				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("fontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
	
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFColorBox",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	void* XMLCreateSelect(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{
		const tinyxml2::XMLAttribute* attr = ele->FindAttribute("Rect");
		if (!attr) {
			return nullptr;
		}
		std::string xml(attr->Value());
		QRect rect = XML2Rect(xml);
		//先创建QHost
		QHost* host = (QHost*)QFUSE::CreateQWND("QFHostCtrl", rect);
		if (!host) {
			DebugOut("QFUSE_EW::XMLCreateColorBox 创建host失败");
			return nullptr;
		}
		//添加一个创建控件代码
		QSelect* ctrl = (QSelect*)QFUSE::CreateQWND("QFSelect", rect);
		if (!ctrl) {
			QWNDHANDLE::QWNDs.erase(host);//从控件集合摘除这个控件的记录
			delete host;
			DebugOut("QFUSE_EW::XMLCreateColorBox 创建QFSelect失败");
			return nullptr;
		}
		host->SetParasiticCtrl(ctrl);

		attr = ele->FirstAttribute();
		unsigned int c1 = 0, c2 = 0;
		int rcCount = 0;
		//项目
		tinyxml2::XMLElement* Items = ele->FirstChildElement("Items");
		if (Items) {
			for (tinyxml2::XMLElement* child = Items->FirstChildElement("Item"); child != nullptr; child = child->NextSiblingElement("Item")) {
				const tinyxml2::XMLAttribute* value = child->FindAttribute("value");
				if (value) {
					ctrl->InsertItem(stringToWString(std::string(value->Value())).c_str());
					const tinyxml2::XMLAttribute* fcolor1 = child->FindAttribute("fcolor1");
					const tinyxml2::XMLAttribute* fcolorD = child->FindAttribute("fcolorD");
					const tinyxml2::XMLAttribute* fcolor2 = child->FindAttribute("fcolor2");
					const tinyxml2::XMLAttribute* colorD = child->FindAttribute("colorD");
					const tinyxml2::XMLAttribute* color1 = child->FindAttribute("color1");
					const tinyxml2::XMLAttribute* color2 = child->FindAttribute("color2");
					unsigned char d = std::strtoul(colorD->Value(), nullptr, 10);
					int para = 10;
					if ('x' == std::tolower(color1->Value()[1]))para = 16;
					unsigned int c1 = std::strtoul(color1->Value(), nullptr, para);
					para = 10;
					if ('x' == std::tolower(color2->Value()[1]))para = 16;
					unsigned int c2 = std::strtoul(color2->Value(), nullptr, para);
					ctrl->SetItemBKColor(-1, c1, c2, d);

					d = std::strtoul(fcolorD->Value(), nullptr, 10);
					para = 10;
					if ('x' == std::tolower(fcolor1->Value()[1]))para = 16;
					c1 = std::strtoul(fcolor1->Value(), nullptr, para);
					para = 10;
					if ('x' == std::tolower(fcolor2->Value()[1]))para = 16;
					c2 = std::strtoul(fcolor2->Value(), nullptr, para);

					ctrl->SetItemFontColor(-1, c1, c2, d);

				}
			}

		}
		while (attr) {
			std::string na = attr->Name();
			std::string value = attr->Value();
			if ("name" == na) {
				//添加给控件设置名称
				ctrl->SetQWNDName(attr->Value());
			}
			else if ("fontName" == na) {

				ctrl->SetFontName(stringToWString(value).c_str());
			}
			else if ("fontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetFontSize(v);
			}
			else if ("CurrentItem" == na) {
				int v = std::strtol(attr->Value(), nullptr,10);
				ctrl->SetCurrentItem(v);
			}
			else if ("FontColor" == na) {
				int para = 10;
				if ('x' == std::tolower(attr->Value()[1]))para = 16;
				unsigned long color = std::strtoul(attr->Value(), nullptr, para);;
				ctrl->SetCurrentItem(color);
			}
			else if ("ItemFontSize" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetItemFontSize(v);
			}
			else if ("ItemHeight" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetItemHeight(v);
			}
			else if ("PopDialogHeight" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetPopDialogHeight(v);
			}
			else if ("PopDialogWidth" == na) {
				double v = std::strtod(attr->Value(), nullptr);
				ctrl->SetPopDialogWidth(v);
			}
			host->TransferMessage(QM_HOSTCTRL_INSERT_PAIR, DWORD(na.c_str()), DWORD(attr->Value()), 0);//把名称记录到host上
			attr = attr->Next();
		}
		



		g_allCtrl.insert(std::pair<int, CtrlAttribute>(int(ctrl->qwm), { "QFSelect",host,parent }));
		//把空壳控件去掉
		ctrl->qwm = nullptr;
		QWNDHANDLE::QWNDs.erase(ctrl);//从控件集合摘除这个控件的记录
		delete ctrl;//销毁这个空壳
		return host;//返回按钮指针
	}
	
	void* AnalUI(tinyxml2::XMLElement* ele, DLLImportQWND* parent)
	{

		std::string na = ele->Name();
		if ("QFButton" == na) {
			return XMLCreateButton(ele, parent);

		}
		else if ("QFPButton" == na) {
			return XMLCreateButton2(ele, parent);

		}
		else if ("QFEdit" == na) {
			return XMLCreateEdit(ele, parent);

		}
		else if ("QFReportForm" == na) {
			return XMLCreateReportForm(ele, parent);
		}
		else if ("QFPictureBox" == na) {

			return XMLCreatePictureBox(ele, parent);
		}
		else if ("QFProgressBarCar" == na) {

			return XMLCreateProgressBarCar(ele, parent);
		}
		else if ("QFLineChart" == na) {

			return XMLCreateLineChart(ele, parent);
		}
		else if ("QFTabs" == na) {

			return XMLCreateTable(ele, parent);
		}
		else if ("QFCATLBarChart" == na) {

			return XMLCreateCATLBarChart(ele, parent);
		}
		else if ("QFDrawer" == na) {

			return XMLCreateDrawer(ele, parent);
		}
		else if ("QFHLayout" == na) {

			return XMLCreateHLayout(ele, parent);
		}
		else if ("QFVLayout" == na) {

			return XMLCreateVLayout(ele, parent);
		}
		else if ("QFTLayout" == na) {

			return XMLCreateTLayout(ele, parent);
		}
		else if ("QFStaticText" == na) {

			return XMLCreateStaticText(ele, parent);
		}
		else if ("QFSlider" == na) {

			return XMLCreateSlider(ele, parent);
		}
		else if ("QFSwitch" == na) {

			return XMLCreateSwitch(ele, parent);
		}
		else if ("QFProgress" == na) {

			return XMLCreateProgress(ele, parent);
		}
		else if ("QFColorBox" == na) {

			return XMLCreateColorBox(ele, parent);
		}
		else if ("QFSelect" == na) {

			return XMLCreateSelect(ele, parent);
		}
		return nullptr;
	}
	void ExplainXML(const char* xmlText, DLLImportQWND* parent)
	{
		tinyxml2::XMLDocument xmlDoc;
		tinyxml2::XMLError result = xmlDoc.Parse(xmlText);
		if (result != tinyxml2::XML_SUCCESS) {
			DebugOut("解析QFUI的XML失败，请确认传入的XML内容是否正确！");
			return;
		}
		// 获取根元素
		tinyxml2::XMLElement* root = xmlDoc.RootElement();
		if (root == nullptr) {
			DebugOut("解析QFUI的XML失败，找不到跟节点 《QWMange》");
			return;
		}
		//判断root的name是否为QWMange
		std::string Rname = root->Name();
		
		const tinyxml2::XMLAttribute* attr = root->FindAttribute("Rect");
		std::string xml(attr->Value());
		QRect rt = XML2Rect(xml);
		parent->Reconstruct(nullptr, rt);
	
		if ("QWMange" != Rname) {
			DebugOut("解析QFUI的XML失败，根节点名称错误 \"%s\"", Rname.c_str());
			return;
		}
		tinyxml2::XMLElement* ele = root->FirstChildElement();
		//DLLImportQWND* parent = (DLLImportQWND*)QFUSE::GetQWManger();
		while (ele) {
			QWND* p = (QWND*)AnalUI(ele, (DLLImportQWND*) parent->qwm);

			if (p) {
				QEditorWin* qew = (QEditorWin*)parent;
				qew->AttachCtrl((DLLImportQWND*)p);
			}
			ele = ele->NextSiblingElement();
		}

	}
	

};