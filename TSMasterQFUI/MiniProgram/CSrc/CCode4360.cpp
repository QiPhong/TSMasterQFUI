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
  #include <cmath>
  AgentWndDLL* paw=NULL;    //窗口管理
  QWMange*  qwm  =NULL;     //窗口控件管理
   QProgressBarCar* qpbc    ;
  void ButtonEvent(void* sender)
  {

    log("******************:%p",sender);
  }
// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN On_Start NewOn_Start1
// 启动事件 "NewOn_Start1"
void on_start_NewOn_Start1(void) { try { // 程序启动事件


  int ret = QFUSE::BindPanelWindow("Panel 416");
  if(1 != ret)return;
  //  GBrush* gb=QFUSE::CreateSolidBrush(0xff,0xff,0xff,0xff); //创建一个全白色画刷
  // GBrush* gb = QFUSE::CreateTextureBrush(L"C:\\Users\\Administrator\\Desktop\\Panel自定义控件\\p2.jpg");
  QWMange* pbuff = (QWMange*)QFUSE::GetQWManger(); //获取窗口管理者指针
  // ret = pbuff->SetBKBrush(gb);
  // QFUSE::QDeleteBrush(gb);//把画刷释放掉，防止泄露
  char* sc;
  app.get_configuration_file_path(&sc);
  int unicodeLen = MultiByteToWideChar(CP_ACP, 0, sc, -1, NULL, 0);
  wchar_t* unicodeString = new wchar_t[unicodeLen + 1];
  unicodeString[unicodeLen] = 0;
  MultiByteToWideChar(CP_ACP, 0, sc, -1, unicodeString, unicodeLen);

  std::wstring cfPath = unicodeString;
  delete unicodeString;

  
  
  pbuff->SetBKPicture((cfPath+L"libs\\common\\QFUI\\picture.png").c_str());
  pbuff->SetBKPictureTransparency(250);
  log("%d",ret);
  QReportForm* wnd = (QReportForm*)QFUSE::CreateQWND("QFReportForm",QRect(10,10,500,700));
  DebugOut("%s 的 指针 %p","QFReportForm",wnd);
  wnd->InsertTitle(L"唱",100,-1);
  wnd->InsertTitle(L"跳",100,-1);
  wnd->InsertTitle(L"rap",200,-1);

  wnd->InsertRecorder(L"半年");
  for(int i=0;++i<21;){
          std::wstring wstr(L"年半");
          wstr=std::to_wstring(i)+wstr;
          wnd->InsertRecorder(wstr.c_str(),-1);
  }
  for(int i=-1;++i<20;){
          wnd->SetRecorderText(i,1,L"练习生");
          wnd->SetRecorderText(i,2,L"精通");
  }
  wnd->IsIsDrag(true);    //是否可以拖动
//   QFUSE::AttachCtrl(wnd);
  //QFUSE::RemoveCtrl(wnd);
  
  
//   QPictureBox* qpb = (QPictureBox*)QFUSE::CreateQWND("QFPictureBox",GRect(700,10,400,200));
//   qpb->LoadPicture(L"F:\\Panel自定义控件\\p1.jpg");
//   //  qpb->SetTransparency(160);
//   QFUSE::AttachCtrl(qpb);

  QEdit* qed = (QEdit*)QFUSE::CreateQWND("QFEdit",QRect(10,10,400,50));
//   QFUSE::AttachCtrl(qed); 

  qpbc = (QProgressBarCar*)QFUSE::CreateQWND("QFProgressBarCar",QRect(100,60,100,50));
//   QFUSE::AttachCtrl(qpbc); 



  qpbc->SetFontSize(8);
  qpbc->IsShowDec(false);
  qpbc->SetFontColor(0x88000000);


  QBrush* gb=QFUSE::CreateLinearGradientBrush(0,0,0x80,0xff,0xff,0xff,100,0,0x90,0x80,0x80,0x80); //创建一个全白色画刷
  qpbc->SetFillBrush(gb);
  QFUSE::QDeleteBrush(gb);//把画刷释放掉，防止泄露
  // QFUSE::QPreventScreenshot();//开启截图保护
  // QFUSE::QAllowScreenshot();//关闭截图保护


  QButton* qbt = (QButton*)QFUSE::CreateQWND("QFButton",QRect(10,10,100,50));
//   QFUSE::AttachCtrl(qbt); 
  qbt->SetClickEvent(ButtonEvent);

  QButton* qbt2 = (QButton*)QFUSE::CreateQWND("QFButton",QRect(110,10,100,50));
  qbt2->SetClickEvent(ButtonEvent);
//   QFUSE::AttachCtrl(qbt2); 
  
  QLineChart* qbt3 = (QLineChart*)QFUSE::CreateQWND("QFLineChart", QRect(10, 10, 800, 600));
  std::vector<QPointF> srcPF{ {0,0},{1,0.01},{3,0.01},{5,0.05},{7,0.06},{8,0.09}
  ,{9,0.15},{10,0.08},{11,0.21},{13,0.23},{15,0.29},{16,0.12},{17,0.20}
  ,{18,0.40},{19,0.50},{20,0.60} ,{21,0.80} ,{25,1.0} };
  //加入一个随机点函数
  qbt3->AddCurve(srcPF.data(), srcPF.size(),0xffff0000,L"C1"); 
  
  //加入一个sin函数
  srcPF.clear();
  for (QREAL x = 0.0; x < 20; x += 3.14 / 8) {
    srcPF.push_back(QPointF(x, std::sin(x)));
  }
  qbt3->AddCurve(srcPF.data(), srcPF.size(),0xff000000,L"C2");
  
  

  //加入一个cons函数
  srcPF.clear();
  for (QREAL x = 0.0; x < 20; x += 3.14 / 8) {
      srcPF.push_back(QPointF(x, std::cos(x + 3.14/6)));
  }
  qbt3->AddCurve(srcPF.data(), srcPF.size(),0xff00ffaa,L"C3");
//   QFUSE::AttachCtrl(qbt3);

  QTabs* qt = (QTabs*)QFUSE::CreateQWND("QFTabs", QRect(10, 10, 800, 700));
    QFUSE::AttachCtrl(qt);
       //给标签控件添加五个标签
    for (int i = -1; ++i < 5;) {
        qt->AddTab((L"测试"+std::to_wstring(i)).c_str(), (cfPath+L"libs\\common\\QFUI\\Tabico.png").c_str());

    }
    
    //把线性图标加入第一个标签页
    qt->AttachCtrl(qbt3,0);
    //把报表控件加入第2个标签页
    qt->AttachCtrl(wnd,1);
    //把两个加入第3个标签页
    qt->AttachCtrl(qbt,2);
    qt->AttachCtrl(qbt2,2);
    //把文本输入框加入第4个标签页
    qt->AttachCtrl(qed,3);
    //把进度条控件加入第5个标签页
    qt->AttachCtrl(qpbc,4);    



} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start NewOn_Start1

// CODE BLOCK BEGIN On_Stop NewOn_Stop1
// 停止事件 "NewOn_Stop1"
void on_stop_NewOn_Stop1(void) { try { // 程序停止事件
 QFUSE::UnBindPanelWindow();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Stop NewOn_Stop1

// CODE BLOCK BEGIN On_Var_Change NewOn_Var_Change1 UmF0LC0x
// 变量变化事件 "NewOn_Var_Change1" 针对变量 "Rat" [On Written]
void on_var_change_NewOn_Var_Change1(void) { try { // 变量 = Rat
  qpbc->SetPercentage(Rat.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change NewOn_Var_Change1

// CODE BLOCK BEGIN Step_Function  NQ__
// 主step函数，执行周期 5 ms
void step(void) { try { // 周期 = 5 ms

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

