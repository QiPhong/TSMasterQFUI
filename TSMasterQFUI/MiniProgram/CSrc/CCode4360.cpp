// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Variable Rat MSw1MC4wLCw_
// 变量文档 "Rat"
TMPVarDouble Rat;
// CODE BLOCK END Variable Rat

// CODE BLOCK BEGIN Global_Definitions 
  #include "QFUI/QFUI.h"
  #include  <cstdlib>
  #include <cmath>
  #include <fstream>
  //为了不每次都遍历控件，建立一个映射表
std::map<std::string, QPOINTER> m_mapping;
  AgentWndDLL* paw=NULL;    //窗口管理
  QWMange*  qwm  =NULL;     //窗口控件管理
  void ButtonEvent(void* sender)
  {

    log("******************:%p",sender);
  }
std::string wstring_to_string(const std::wstring& wstr) {
    if (wstr.empty()) {
        return std::string();
    }

    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
    return str;
}

#include <filesystem>
//图片路径的解析函数，负责QFUIEditor编辑的图片图标路径重定向,    
//QFUIEditor对控件的图片设定是绝对路径的，TSmaster的使用要进行相应的重定向路径
std::wstring RedirectPath(const char* fpath)
{

     std::string fph = fpath;

     std::filesystem::path path(fph);
     
//      log("filename:%s",path.filename().string().c_str());
     char* cpath;
      app.get_configuration_file_path(&cpath);
      fph =cpath;
      fph+="pic\\"+path.filename().string();  //我把它图片路径重定向到工程目录下的pic文件内
      log("fph:%s",fph.c_str());
      
     return QFUSE::stringToWString(fph);
}
//*****************************************************************************************************************控件的响应函数
int Sliding(QPOINTER ct,float v)
{
    printf("%x滑块滚动: %f \n", ct,v);
    //查找进度条
    for (auto& it : QWNDHANDLE::QWNDs) {
        if ("QFProgress1" == ((DLLImportQWND*)it)->GetQWNDName()) {   //通过控件名来检索确认控件，所以在QFUIEditor上面的控件名要设置唯一的     下同
            QProgress* p=(QProgress*)it;
            p->SetCurrentValue(v);
            break;
        }
    
    }

    return 1;
}

int SwitchStateChange(QPOINTER ct)
{
    QSwitch qs(nullptr,QRect());
    qs.qwm = (DLLImportQWND*)ct;
    printf("%x开关状态改变: %d \n", ct, qs.GetState());
    //查找滑动条
    for (auto& it : QWNDHANDLE::QWNDs) {
        if ("QFSlider1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            QSlider* p = (QSlider*)it;
            p->IsSegmentation(qs.GetState());
            break;
        }

    }


    qs.qwm = nullptr;
    return 1;
}

int ColorBoxChange(QPOINTER ct ,unsigned int color)
{
    QColorBox ctrl(nullptr, QRect());
    ctrl.qwm = (DLLImportQWND*)ct;
    QColorBox* cl[2];
    int index = 0;
    //查找两个颜色选择器
    for (auto& it : QWNDHANDLE::QWNDs) {
        if ("QFColorBox1" == ((DLLImportQWND*)it)->GetQWNDName()|| "QFColorBox2" == ((DLLImportQWND*)it)->GetQWNDName()) {
            
            cl[index++] = (QColorBox*)it;
            if (index > 1)break;
        }

    }


    printf("%x颜色框颜色改变: 0x%x \n", ct, color);
    //查找进度条
    for (auto& it : QWNDHANDLE::QWNDs) {
        if ("QFProgress1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            QProgress* p = (QProgress*)it;
            p->SetRingProgressColor(cl[0]->GetColor(), cl[1]->GetColor());
            break;
        }

    }


    ctrl.qwm = nullptr;
    return 1;
}

int SelectChange(QPOINTER ct, int index)
{
    QSelect ctrl(nullptr, QRect());
    ctrl.qwm = (DLLImportQWND*)ct;
    printf("%x选中项目:%s\n", ct, QFUSE::wstring_to_string(ctrl.GetItemText(index)).c_str());
    ctrl.qwm = nullptr;
    return 1;
}


//示例按钮1的点击事件
void exampleBT1Onclick(void* bt)
{
     app.make_toast("示例按钮1被点击",lvlOK);

}
//示例按钮2的点击事件
void exampleBT2Onclick(void* bt)
{
     app.make_toast("示例按钮2被点击",lvlOK);

}
//示例编辑框1内容被改变的事件
int exampleEdit1OnContextChange(QPOINTER ct,int pwText,int param)
{
    //参数1为编辑框的指针
 //参数2为宽字符文本指针
 //参数3为之前设定的参数，可以不用
 
//  std::wstring wstr = (const wchar_t*) pwText;
 std::string str = wstring_to_string((const wchar_t*) pwText);
 log("示例编辑框1的内容：%s",str.c_str());
 return 1;
}
//示例报表增加一列的按钮的点击事件
void RPADDCBTOnclick(void* bt)
{
    // app.make_toast("示例报表增加一列的按钮被点击",lvlOK);
    //查找报表框的,这里可以查找一次之后全局变量保存下来，不要每次都查找，我懒得做了
    QReportForm* pr = nullptr;
    
    for(auto& it: QWNDHANDLE::QWNDs){
        //报表框的名字叫  QFReportForm_test1    我们在QFUIEditor设计的时候设置的
        if ("QFReportForm_test1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            pr = (QReportForm*)it;
        }
    }
    if(pr){
        //存在这个报表才能继续，否则崩溃
        QEdit* indexE = nullptr;//索引的输入框，名字叫  QFEdit_RP_ADDC_index
        QEdit* widthE = nullptr;//列宽度的输入框，名字叫  QFEdit_RP_ADDC_W
        QEdit* ContextE = nullptr;//列内容的输入框，名字叫  QFEdit_RP_ADDC_CONTEXT
        for(auto& it: QWNDHANDLE::QWNDs){
            if(indexE && widthE && ContextE) break;
            if("QFEdit_RP_ADDC_index" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexE = (QEdit*)it;

            }
            else if("QFEdit_RP_ADDC_W" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                widthE = (QEdit*)it;

            }else if("QFEdit_RP_ADDC_CONTEXT" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                ContextE = (QEdit*)it;

            }
        }
        if(indexE && widthE && ContextE){
            //读取索引
            std::wstring wstr = indexE->GetText();
            std::string str = wstring_to_string(wstr);

            int index = (std::strtol)(str.c_str(),nullptr,10);

            wstr = widthE->GetText();
            str = wstring_to_string(wstr);
            int w = (std::strtol)(str.c_str(),nullptr,10);

            pr->InsertTitle( ContextE->GetText(),w,index);

        }


    }




}
//示例报表移除一列的按钮的点击事件
void RPRMCBTOnclick(void* bt)
{
    // app.make_toast("示例报表移除一列的按钮被点击",lvlOK);
    QReportForm* pr = nullptr;
    
    for(auto& it: QWNDHANDLE::QWNDs){
        //报表框的名字叫  QFReportForm_test1    我们在QFUIEditor设计的时候设置的
        if ("QFReportForm_test1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            pr = (QReportForm*)it;
        }
    }
    if(pr){
        //存在这个报表才能继续，否则崩溃
        QEdit* indexE = nullptr;//索引的输入框，名字叫  QFEdit_RP_ADDC_index

        for(auto& it: QWNDHANDLE::QWNDs){
            if("QFEdit_RP_ADDC_index" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexE = (QEdit*)it;
                break;
            }

        }
        if(indexE){
            //读取索引
            std::wstring wstr = indexE->GetText();
            std::string str = wstring_to_string(wstr);

            int index = (std::strtol)(str.c_str(),nullptr,10);

// app.make_toast("RemoveRecorder",lvlOK);
            pr->RemovTitle(index);

        }


    }


}

//示例报表移除一行的按钮的点击事件
void RPRMIBTOnclick(void* bt)
{
    //  app.make_toast("示例报表移除一行的按钮被点击",lvlOK);
     QReportForm* pr = nullptr;
    
    for(auto& it: QWNDHANDLE::QWNDs){
        //报表框的名字叫  QFReportForm_test1    我们在QFUIEditor设计的时候设置的
        if ("QFReportForm_test1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            pr = (QReportForm*)it;
        }
    }
    if(pr){
        QEdit* indexE = nullptr;//索引的输入框，名字叫  QFEdit_RP_ADDC_index

        for(auto& it: QWNDHANDLE::QWNDs){
            if("QFEdit_RP_ADDI_INDEXH" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexE = (QEdit*)it;
                break;
            }

        }
        if(indexE){
            //读取索引
            std::wstring wstr = indexE->GetText();
            std::string str = wstring_to_string(wstr);

            int index = (std::strtol)(str.c_str(),nullptr,10);

            pr->RemoveRecorder(index);

        }



    }

}
 //示例报表增加一行的按钮的点击事件
void RPADDIBTOnclick(void* bt)
{
      QReportForm* pr = nullptr;
    
    for(auto& it: QWNDHANDLE::QWNDs){
        //报表框的名字叫  QFReportForm_test1    我们在QFUIEditor设计的时候设置的
        if ("QFReportForm_test1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            pr = (QReportForm*)it;
        }
    }
    if(pr){
        //存在这个报表才能继续，否则崩溃
        QEdit* indexE = nullptr;
        QEdit* ContextE = nullptr;
        for(auto& it: QWNDHANDLE::QWNDs){
            if(indexE  && ContextE) break;
            if("QFEdit_RP_ADDI_INDEXH" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexE = (QEdit*)it;

            }else if("QFEdit_RP_ADDI_CONTEXT" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                ContextE = (QEdit*)it;

            }
    
        }
        if(indexE  && ContextE){
            //读取行索引
            std::wstring wstr = indexE->GetText();
            std::string str = wstring_to_string(wstr);

            int index = (std::strtol)(str.c_str(),nullptr,10);


            pr->InsertRecorder( ContextE->GetText(),index);

        }


    }

}
//示例报表更新一个细胞的按钮的点击事件
void RPUopdateIBTOnclick(void* bt)
{
    //  app.make_toast("示例报表更新内容的按钮被点击",lvlOK);
     QReportForm* pr = nullptr;
    
    for(auto& it: QWNDHANDLE::QWNDs){
        //报表框的名字叫  QFReportForm_test1    我们在QFUIEditor设计的时候设置的
        if ("QFReportForm_test1" == ((DLLImportQWND*)it)->GetQWNDName()) {
            pr = (QReportForm*)it;
        }
    }
    if(pr){
        //存在这个报表才能继续，否则崩溃
        QEdit* indexHE = nullptr;//行索引的输入框，名字叫  QFEdit_RP_ADDI_INDEXH
        QEdit* indexVE = nullptr;//列索引的输入框，名字叫  QFEdit_RP_ADDI_INDEXV
        QEdit* ContextE = nullptr;//cell内容的输入框，名字叫  QFEdit_RP_ADDI_CONTEXT
        for(auto& it: QWNDHANDLE::QWNDs){
            if(indexHE && indexVE && ContextE) break;
            if("QFEdit_RP_ADDI_INDEXH" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexHE = (QEdit*)it;

            }
            else if("QFEdit_RP_ADDI_INDEXV" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                indexVE = (QEdit*)it;

            }else if("QFEdit_RP_ADDI_CONTEXT" ==  ((DLLImportQWND*)it)->GetQWNDName()){
                ContextE = (QEdit*)it;

            }
        }
        if(indexHE && indexVE && ContextE){
            //读取索引
            std::wstring wstr = indexHE->GetText();
            std::string str = wstring_to_string(wstr);
            int index = (std::strtol)(str.c_str(),nullptr,10);

            wstr = indexVE->GetText();
            str = wstring_to_string(wstr);
            int indexh = (std::strtol)(str.c_str(),nullptr,10);

            pr->SetRecorderText(index,indexh, ContextE->GetText());

        }


    }

}
//进度条示例中的滑块滑动事件
int PROSliding(QPOINTER ct, float v)
{
    {
        auto it = m_mapping.find("QFProgressBarCar_PRO");//查找车型进度条
        if (it != m_mapping.end()) {
            QProgressBarCar* p = (QProgressBarCar*)it->second;
            p->SetPercentage(v);

        }
    }
    {
        auto it = m_mapping.find("QFProgress_PRO2");//第二个进度条
        if (it != m_mapping.end()) {
            QProgress* p = (QProgress*)it->second;
            p->SetCurrentValue(v);

        }
    }
    {
        auto it = m_mapping.find("QFProgress_PRO3");//第3个进度条
        if (it != m_mapping.end()) {
            QProgress* p = (QProgress*)it->second;
            p->SetCurrentValue(v);

        }
    }
    {
        auto it = m_mapping.find("QFProgress_PRO4");//第4个进度条
        if (it != m_mapping.end()) {
            QProgress* p = (QProgress*)it->second;
            p->SetCurrentValue(v);

        }
    }
    return 1;
}
//进度条示例中的车型进度条颜色改变
int PROCarColorBoxChange(QPOINTER ct, unsigned int color)
{
    auto it = m_mapping.find("QFProgressBarCar_PRO");//查找车型进度条
    if (it != m_mapping.end()) {
        QProgressBarCar* p = (QProgressBarCar*)it->second;
        p->SetFontColor(color);
    }
    return 1;
}
//进度条示例中的进度条2字体颜色改变
int PRO2fColorBoxChange(QPOINTER ct, unsigned int color)
{
    auto it = m_mapping.find("QFProgress_PRO2");//第二个进度条
    if (it != m_mapping.end()) {
        QProgress* p = (QProgress*)it->second;
        p->SetFontColor(color);

    }
    return 1;
}
//进度条示例中的进度条2颜色改变
int PRO2ColorBoxChange(QPOINTER ct, unsigned int color)
{
    auto it = m_mapping.find("QFProgress_PRO2");//第二个进度条
    if (it != m_mapping.end()) {
        QProgress* p = (QProgress*)it->second;
        auto itc1 = m_mapping.find("QFColorBox_PRO2_C1");
        if (itc1 != m_mapping.end()) {
            auto itc2 = m_mapping.find("QFColorBox_PRO2_C2");
            if (itc2 != m_mapping.end()) {
                QColorBox* p1 = (QColorBox*)itc1->second;
                QColorBox* p2 = (QColorBox*)itc2->second;
                p->SetRingProgressColor(p1->GetColor(), p2->GetColor());
            }
        
        }


       

    }
    return 1;
}

//进度条示例中的进度条3字体颜色改变
int PRO3fColorBoxChange(QPOINTER ct, unsigned int color)
{
    auto it = m_mapping.find("QFProgress_PRO3");//第3个进度条
    if (it != m_mapping.end()) {
        QProgress* p = (QProgress*)it->second;
        p->SetFontColor(color);

    }
    auto it4 = m_mapping.find("QFProgress_PRO4");//第3个进度条
    if (it4 != m_mapping.end()) {
        QProgress* p = (QProgress*)it4->second;
        p->SetFontColor(color);

    }
    return 1;
}
//进度条示例中的进度条3、4颜色改变
int PRO3ColorBoxChange(QPOINTER ct, unsigned int color)
{
    auto it = m_mapping.find("QFProgress_PRO3");//第3个进度条
    if (it != m_mapping.end()) {
        QProgress* p = (QProgress*)it->second;
        p->SetLineTypeProgressColor(color);

    }
    auto it4 = m_mapping.find("QFProgress_PRO4");//第3个进度条
    if (it4 != m_mapping.end()) {
        QProgress* p = (QProgress*)it4->second;
        p->SetLineTypeProgressColor(color);

    }
    return 1;
}
//直线图中 “增加一点” 的按钮响应事件
void LCAddPtBTOnclick(void* bt)
{
    auto itEx = m_mapping.find("QFEdit_LCX1");//X坐标
    if (itEx != m_mapping.end()) {
        QEdit* pEx = (QEdit*)itEx->second;
        auto itEy = m_mapping.find("QFEdit_LCY1");//Y坐标
        if (itEy != m_mapping.end()) {
            QEdit* pEy = (QEdit*)itEy->second;
            auto itRF = m_mapping.find("QFReportForm_LC_RF");//表格
            if (itRF != m_mapping.end()) {
                QReportForm* pRF = (QReportForm*)itRF->second;
                if (pRF) {
                    pRF->InsertRecorder(pEx->GetText());
                    pRF->SetRecorderText(pRF->GetRecorderCount()-1,1, pEy->GetText());

                }
            }
        }
    }
}
//直线图中 “清空” 的按钮响应事件
void LCClearBTOnclick(void* bt)
{
    auto itRF = m_mapping.find("QFReportForm_LC_RF");//表格
    if (itRF != m_mapping.end()) {
        QReportForm* pRF = (QReportForm*)itRF->second;
        int count = pRF->GetRecorderCount();
        for (int i = -1; ++i < count;) {
            pRF->RemoveRecorder(0);
        }

    }

}
//直线图中 “加入曲线” 的按钮响应事件
void LCAddCurveBTOnclick(void* bt)
{
    auto itRF = m_mapping.find("QFReportForm_LC_RF");//表格
    if (itRF != m_mapping.end()) {
        QReportForm* pRF = (QReportForm*)itRF->second;
        auto itColor = m_mapping.find("QFColorBox_LC_COLOR");//颜色
        if (itColor != m_mapping.end()) {
            QColorBox* pcolor = (QColorBox*)itColor->second;
            int count = pRF->GetRecorderCount();
            if (0 < count) {
               

                QPointF* pp = new QPointF[count];
                for (int i = -1; ++i < count;) {
                    std::wstring strx = pRF->GetCellText(i,0);
                    std::wstring stry = pRF->GetCellText(i,1);
                    float x = std::strtod(QFUSE::wstring_to_string(strx).c_str(),nullptr);
                    float y = std::strtod(QFUSE::wstring_to_string(stry).c_str(), nullptr);
                    pp[i].X = x;
                    pp[i].Y = y;
                }

                auto itLC = m_mapping.find("QFLineChart_LC");//线性表
                if (itLC != m_mapping.end()) {
                    QLineChart* plc = (QLineChart*)itLC->second;
                    plc->AddCurve(pp, count, pcolor->GetColor(),L"曲线");

                }
                delete[] pp;
            
            }

        }
    }
}
//直线图中 “移除” 的按钮响应事件
void LCRmoveBTOnclick(void* bt)
{
    auto itEI = m_mapping.find("QFEdit_LC_CURVE_INDEX");
    if (itEI != m_mapping.end()) {
        QEdit* pedit = (QEdit*)itEI->second;
        int index = std::strtol(QFUSE::wstring_to_string(pedit->GetText()).c_str(),nullptr,10);
        auto itLC = m_mapping.find("QFLineChart_LC");//线性表
        if (itLC != m_mapping.end()) {
            QLineChart* plc = (QLineChart*)itLC->second;
            plc->RemoveCurve(index);
        }

    }
    
}
//直线图中 “修改” 的按钮响应事件
void LCUpDateBTOnclick(void* bt)
{
    auto itEI = m_mapping.find("QFEdit_LC_UPDATE_INDEX");
    if (itEI != m_mapping.end()) {
        QEdit* pedit = (QEdit*)itEI->second;
        int index = std::strtol(QFUSE::wstring_to_string(pedit->GetText()).c_str(), nullptr, 10);
        auto itSW = m_mapping.find("QFSwitch_LC_ISVISUAL");
        if (itSW != m_mapping.end()) {
            QSwitch* PSW = (QSwitch*)itSW->second;
            auto itLC = m_mapping.find("QFLineChart_LC");//线性表
            if (itLC != m_mapping.end()) {
                QLineChart* plc = (QLineChart*)itLC->second;
                plc->SetCurveVisible(index, PSW->GetState());
            }
        }




    }

}
//直线图中 “曲线增加一点” 的按钮响应事件
void LCCurveAddPtBTOnclick(void* bt)
{
    auto itEI = m_mapping.find("QFEdit_LC_UPDATE_INDEX");
    if (itEI != m_mapping.end()) {
        QEdit* pedit = (QEdit*)itEI->second;
        int index = std::strtol(QFUSE::wstring_to_string(pedit->GetText()).c_str(), nullptr, 10);
        auto itEX = m_mapping.find("QFEdit_LCX2");
        if (itEX != m_mapping.end()) {
            QEdit* pex = (QEdit*)itEX->second;
            auto itEY = m_mapping.find("QFEdit_LCY2");
            if (itEY != m_mapping.end()) {
                QEdit* pey = (QEdit*)itEY->second;

                float x = std::strtol(QFUSE::wstring_to_string(pex->GetText()).c_str(), nullptr, 10);
                float y = std::strtol(QFUSE::wstring_to_string(pey->GetText()).c_str(), nullptr, 10);

                auto itLC = m_mapping.find("QFLineChart_LC");//线性表
                if (itLC != m_mapping.end()) {
                    QLineChart* plc = (QLineChart*)itLC->second;
                    plc->CurveInsertPoint(index,QPointF(x,y));
                }
            }


       
        }




    }

}

//宁德柱状图所有按钮的响应事件
void CATLBCBTOnclick(void* bt)
{
    //下面是不安全的写法，如果控件不存在就崩溃了！！！！！！！！！！！！！！！！！！！！！！！！！！

    //插入一组按钮
    void* insGBT = nullptr;
    //移除一组按钮
    void* rmGBT = nullptr;
    //插入数据按钮
    void* insDBT = nullptr;
    //移除数据按钮
    void* rmDBT = nullptr;
    //修改数据按钮
    void* UpDateDBT = nullptr;
    //修改柱体颜色按钮
    void* UpDateColorBT = nullptr;
    //修改标记字符按钮
    void* UpDateStrBT = nullptr;
    //修改标记字符颜色按钮
    void* UpDateStrCBT = nullptr;

    //组ID1
    QEdit* GID1 = (QEdit*)(m_mapping["QFEdit_CATLBC_GID1"]);
    //组ID2
    QEdit* GID2 = (QEdit*)(m_mapping["QFEdit_CATLBC_GID2"]);
    //柱ID1
    QEdit* BCID1 = (QEdit*)(m_mapping["QFEdit_CATLBC_BCID"]);
    //数据
    QEdit* EDATA = (QEdit*)(m_mapping["QFEdit_CATLBC_DATA"]);
    //标识
    QEdit* EStr = (QEdit*)(m_mapping["QFEdit_CATLBC_STR"]);

    //柱体颜色
    QColorBox* BCc = (QColorBox*)(m_mapping["QFColorBox_CATLBC_BCC"]);
    //字符颜色
    QColorBox* Fc = (QColorBox*)(m_mapping["QFColorBox_CATLBC_FC"]);



    insGBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_INSG"]))->qwm;
    rmGBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_RMG"]))->qwm;
    insDBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_INSD"]))->qwm;
    rmDBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_RMD"]))->qwm;
    UpDateDBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_UpDateD"]))->qwm;
    UpDateColorBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_UpDateBCC"]))->qwm;
    UpDateStrBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_UpDateSTR"]))->qwm;
    UpDateStrCBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLBC_UpDateSTRC"]))->qwm;


    QCATLBarChart* bc = (QCATLBarChart*)(m_mapping["QFCATLBarChart_CATLBC"]);

    int id1 = std::strtol(QFUSE::wstring_to_string(GID1->GetText()).c_str(),nullptr,10);
    int id2 = std::strtol(QFUSE::wstring_to_string(GID2->GetText()).c_str(), nullptr, 10);
    int bcid1 = std::strtol(QFUSE::wstring_to_string(BCID1->GetText()).c_str(), nullptr, 10);
    double v = std::strtod(QFUSE::wstring_to_string(EDATA->GetText()).c_str(), nullptr);
    unsigned int bcc = BCc->GetColor();
    unsigned int fc = Fc->GetColor();
    std::wstring str = EStr->GetText();
    if (insGBT == bt) {
        //    
        bc->InsertGroup(id1);
    
    }
    else if (rmGBT == bt) {
        bc->RemoveGroup(id1);
    
    }
    else if (insDBT == bt) {
        bc->InsertBarChart(id2, bcid1, v, bcc, str.c_str(), fc);
    }
    else if (rmDBT == bt) {
        bc->RemoveBarChart(id2, bcid1);
    
    }
    else if (UpDateDBT == bt) {
        bc->SetBarChartValue(id2, bcid1,v);

    }
    else if (UpDateColorBT == bt) {
        bc->SetBarChartColor(id2, bcid1, bcc);

    }
    else if (UpDateStrBT == bt) {
        bc->SetBarChartText(id2, bcid1, str.c_str());

    }
    else if (UpDateStrCBT == bt) {
        bc->SetBarChartTextColor(id2, bcid1, fc);

    }


}
//宁德温度图表所有按钮的响应事件
void CATLPBTOnclick(void* bt)
{
    //插入一组按钮
    void* insGBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_INSG"]))->qwm;
    //移除一组按钮
    void* rmGBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_RMG"]))->qwm;
    //插入一单元按钮
    void* insUBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_INSU"]))->qwm;
    //移除一单元按钮
    void* rmUBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_RMU"]))->qwm;
    //修改单元颜色按钮
    void* uducBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_UDC"]))->qwm;
    //修改单元字符按钮
    void* udusBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_UDS"]))->qwm;
    //修改单元字符颜色按钮
    void* uduscBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_UDSC"]))->qwm;
    //修改单元一行个数
    void* uduLCBT = (void*)((QButton2*)(m_mapping["QFPButton_CATLP_UDLC"]))->qwm;

    //组ID1
    QEdit* GID1 = (QEdit*)(m_mapping["QFEdit1_CATLP_G1"]);
    //组ID2
    QEdit* GID2 = (QEdit*)(m_mapping["QFEdit1_CATLP_G2"]);
    //组ID3
    QEdit* GID3 = (QEdit*)(m_mapping["QFEdit1_CATLP_G3"]);
    //单元ID
    QEdit* UID = (QEdit*)(m_mapping["QFEdit1_CATLP_U1"]);
    //单元字符
    QEdit* US = (QEdit*)(m_mapping["QFEdit1_CATLP_STR"]);
    //一行单元个数
    QEdit* LC = (QEdit*)(m_mapping["QFEdit1_CATLP_LCOUNT"]);

    //
    QColorBox* color = (QColorBox*)(m_mapping["QFColorBox_CATLP_C"]);
    //字符颜色
    QColorBox* fcolor = (QColorBox*)(m_mapping["QFColorBox_CATLP_FC"]);

    QCATLTempeChart* TC = (QCATLTempeChart*)(m_mapping["QFCATLTempeChart_CATLP"]);


    int id1 = std::strtol(QFUSE::wstring_to_string(GID1->GetText()).c_str(), nullptr, 10);
    int id2 = std::strtol(QFUSE::wstring_to_string(GID2->GetText()).c_str(), nullptr, 10);
    int id3 = std::strtol(QFUSE::wstring_to_string(GID3->GetText()).c_str(), nullptr, 10);

    int uid1 = std::strtol(QFUSE::wstring_to_string(UID->GetText()).c_str(), nullptr, 10);
    int lc = std::strtol(QFUSE::wstring_to_string(LC->GetText()).c_str(), nullptr, 10);
    
    std::wstring wstr = US->GetText();

    if (insGBT == bt) {
        TC->InsertGroup(id1);
    }
    else if (rmGBT == bt) {
        TC->RemoveGroup(id1);
    
    }
    else if (insUBT == bt) {
        TC->InsertUnit(id2, uid1, color->GetColor(), wstr.c_str(), fcolor->GetColor());
    }
    else if (rmUBT == bt) {
        TC->RemoveUnit(id2, uid1);
    
    }
    else if (uducBT == bt) {
       
        TC->SetUnitColor(id2, uid1, color->GetColor());
    }
    else if (udusBT == bt) {
        TC->SetUnitText(id2, uid1, wstr.c_str());
    
    }
    else if (uduscBT == bt) {
        TC->SetUnitTextColor(id2, uid1, fcolor->GetColor());
    
    }
    else if (uduLCBT == bt) {
        TC->SetGroupLineCount(id3, lc);

    }


}
//抽屉控件页所有按钮事件
void DrawerBTOnclick(void* bt)
{
    void* addG = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_ADDG"]))->qwm;
    void* rmG = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_RMG"]))->qwm;
    void* udG = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_UDG"]))->qwm;

    void* addI = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_ADDI"]))->qwm;
    void* rmI = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_RMI"]))->qwm;
    void* udI = (void*)((QButton2*)(m_mapping["QFPButton_DRAW_UDI"]))->qwm;


    //组ID1
    QEdit* GID1 = (QEdit*)(m_mapping["QFEdit_DRAW_GID"]);
    //项目ID1
    QEdit* IID1 = (QEdit*)(m_mapping["QFEdit_ITEM_GID"]);
    //内容
    QEdit* CT1 = (QEdit*)(m_mapping["QFEdit_DRAW_CONTEXT"]);

    int gid1 = std::strtol(QFUSE::wstring_to_string(GID1->GetText()).c_str(), nullptr, 10);
    int iid1 = std::strtol(QFUSE::wstring_to_string(IID1->GetText()).c_str(), nullptr, 10);

    QDrawer* pdra = (QDrawer*)(m_mapping["QFDrawer_DRAW"]);

    if (addG == bt) {
        
        pdra->InsertDrawer(gid1);
    }
    else if (rmG == bt) {
        pdra->RemoveDrawer(gid1);
    
    }
    else if (udG == bt) {
        pdra->SetDrawerName(gid1, CT1->GetText());
    }
    else if (addI == bt) {
        pdra->InsertSubObject(gid1, iid1);
    }
    else if (rmI == bt) {
        pdra->RemoveSubObject(gid1, iid1);
    }
    else if (udI == bt) {
        pdra->SetSubObjectName(gid1, iid1, CT1->GetText());
    }
}


//注册函数
void ReFun()
{
    REGEVENTFUN(PROSliding);
    REGEVENTFUN(PROCarColorBoxChange);
    REGEVENTFUN(PRO2fColorBoxChange);
    REGEVENTFUN(PRO2ColorBoxChange);
    REGEVENTFUN(PRO3fColorBoxChange);
    REGEVENTFUN(PRO3ColorBoxChange);

    REGEVENTFUN(LCAddPtBTOnclick);
    REGEVENTFUN(LCClearBTOnclick);
    REGEVENTFUN(LCAddCurveBTOnclick);
    REGEVENTFUN(LCRmoveBTOnclick);
    REGEVENTFUN(LCUpDateBTOnclick);
    REGEVENTFUN(LCCurveAddPtBTOnclick);
    REGEVENTFUN(CATLBCBTOnclick);
    REGEVENTFUN(CATLPBTOnclick);
    REGEVENTFUN(DrawerBTOnclick);
}

void UpDateCtrlMap()
{
    for (const auto& it : QWNDHANDLE::QWNDs) {
        std::string name = ((DLLImportQWND*)it)->GetQWNDName();
        if ("" != name) {
            m_mapping[name] = (QPOINTER)it;
        }
    }

}









// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN On_Start NewOn_Start1
// 启动事件 "NewOn_Start1"
void on_start_NewOn_Start1(void) { try { // 程序启动事件
  int ret = QFUSE::BindPanelWindow("Panel 416");//先绑定panel,填写panel面板的名称
  printf("%d",ret);
  if(1 != ret)return;

  QWMange* pbuff = (QWMange*)QFUSE::GetQWManger(); //获取窗口管理者指针
  char* sc;
  app.get_configuration_file_path(&sc);
  std::string strPath =  sc;
  
  ////////////////////////////////////////////////////////////////////////    多字节转宽字节例子
  int unicodeLen = MultiByteToWideChar(CP_ACP, 0, sc, -1, NULL, 0);
  wchar_t* unicodeString = new wchar_t[unicodeLen + 1];
  unicodeString[unicodeLen] = 0;
  MultiByteToWideChar(CP_ACP, 0, sc, -1, unicodeString, unicodeLen);

  std::wstring cfPath = unicodeString;
  delete unicodeString;
////////////////////////////////////////////////////////////////////////
  
  
  pbuff->SetBKPicture((cfPath+L"libs\\common\\QFUI\\picture.png").c_str());//设置panel背景图片
  pbuff->SetBKPictureTransparency(250);//设置背景图片透明度
  
  
  
  //读取UI设计QFUIEditor设计的UI文件，这里不做封装，留给你们自由的进行文件加密和解密
 	std::ifstream file((strPath+"test.xml").c_str(), std::ios::in | std::ios::binary);

	if (!file) {

		return ;
	}
	// 获取文件的大小
	file.seekg(0, std::ios::end);
	std::streampos size = file.tellg();
	file.seekg(0, std::ios::beg);

	// 读取文件内容到字符串中
	std::string content(size, ' ');
	file.read(&content[0], size);
  file.close();
 
 //**********************************************************************************
 //注册控件的事件响应函数
 //可以注册很多，每个控件使用一个也可
/**
*  响应函数的格式
*  按钮的： typedef void(*QFBUTTONCLICK)(void*);     即无返回值，一个参数void* （控件的指针）
*   编辑框的： typedef int (*QEDIT_CHANGE_EVENT)(int, int, int);//参数1：自身指针；参数2：字符串指针；参数3：设置时要求调用时带的
*   抽屉控件的：typedef int (*QDRAWERSELECT)(int, int); //参数1：分组索引；参数2：分组内被选中的索引
*  Switch的：typedef int (*QSWITCH_STATE_CHANGE)(int); //参数1：控件指针
*  滑块的：typedef int (*QSLIDER_VALUE_CHANGE)(int, float);//参数1：控件指针；参数2：当前滑块的值
*   颜色调节框的：typedef int (*QCOLORBOX_CHANGE)(QPOINTER, unsigned int);//参数1：控件指针；参数2：颜色值，ARGB
*    下拉选择框：typedef int (*QSELECT_SELECTCHANGE)(QPOINTER, int);//参数1：控件指针；参数2：被选中的项目索引
*
*/

/*
*    示例
*全局定义里面定义了 int Sliding(QPOINTER ct,float v) 函数，给滑块控件使用     对应  typedef int (*QSLIDER_VALUE_CHANGE)(int, float);
*全局定义里面定义了 int SwitchStateChange(QPOINTER ct) 函数，给开关控件使用     对应  typedef int (*QSWITCH_STATE_CHANGE)(int);
*全局定义里面定义了 int ColorBoxChange(QPOINTER ct ,unsigned int color) 函数，给颜色选择控件使用     对应  typedef int (*QCOLORBOX_CHANGE)(QPOINTER, unsigned int);
* 全局定义里面定义了 int SelectChange(QPOINTER ct, int index) 函数，给选择控件使用     对应  ：typedef int (*QSELECT_SELECTCHANGE)(QPOINTER, int);
*
*
*
*/
 
 REGEVENTFUN(Sliding);//注册函数，括号里面参数就是什么定义的函数名
 REGEVENTFUN(SwitchStateChange);
 REGEVENTFUN(ColorBoxChange);
 REGEVENTFUN(SelectChange);
 REGEVENTFUN(exampleBT1Onclick);//注册示例按钮1的点击事件
 REGEVENTFUN(exampleBT2Onclick); //注册示例按钮2的点击事件
 REGEVENTFUN(exampleEdit1OnContextChange);//注册示例编辑框1的内容改变事件
 REGEVENTFUN(RPADDCBTOnclick);//注册报表示例增加一列的按钮事件
 REGEVENTFUN(RPRMCBTOnclick);//注册报表示例移除一列的按钮事件
 REGEVENTFUN(RPADDIBTOnclick);//注册报表示例增加一行的按钮事件
 REGEVENTFUN(RPRMIBTOnclick);//注册报表示例移除一行的按钮事件 
REGEVENTFUN(RPUopdateIBTOnclick);//注册报表示例更新的按钮事件 
  ReFun();//太多函数注册了，写道全局定义的函数里面
 
 
 
 
 /*
 *  在  QFUIEditor 上对需要的函数进行设置事件响应函数
 *
 *   例如 选择控件(QSelect) 在属性里面的 “选中项目事件”填写 “SelectChange” （这个函数一定要上面注册过的），运行程序的时候项目被选中就会调用 “SelectChange” 函数
 *
 *
 *
 *
 *
 *
 */
 
 
  //*********************************************************************************
 
 
 
 //设置重定向路径
 QFUSE::SetPicPathConvertor(RedirectPath);
 log("************************************************************************************");

 //你只需要把文件内容完整交给我就行了，如有加密请解密后给我
QFUSE::ExplainXML(content.c_str());
UpDateCtrlMap();//把控件加入map方便查找


} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start NewOn_Start1

// CODE BLOCK BEGIN On_Stop NewOn_Stop1
// 停止事件 "NewOn_Stop1"
void on_stop_NewOn_Stop1(void) { try { // 程序停止事件


 
 
 
 QFUSE::UnBindPanelWindow();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Stop NewOn_Stop1

// CODE BLOCK BEGIN Step_Function  NQ__
// 主step函数，执行周期 5 ms
void step(void) { try { // 周期 = 5 ms

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

