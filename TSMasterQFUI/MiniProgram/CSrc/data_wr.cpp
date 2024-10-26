// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Variable txt_SofVerNo MiwsLA__
// 变量文档 "txt_SofVerNo"
TMPVarString txt_SofVerNo;
// CODE BLOCK END Variable txt_SofVerNo

// CODE BLOCK BEGIN Variable txt_HardVerNo MiwsLA__
// 变量文档 "txt_HardVerNo"
TMPVarString txt_HardVerNo;
// CODE BLOCK END Variable txt_HardVerNo

// CODE BLOCK BEGIN Variable txt_PRJInfo MiwsLA__
// 变量文档 "txt_PRJInfo"
TMPVarString txt_PRJInfo;
// CODE BLOCK END Variable txt_PRJInfo

// CODE BLOCK BEGIN Variable txt_BootVerNo MiwsLA__
// 变量文档 "txt_BootVerNo"
TMPVarString txt_BootVerNo;
// CODE BLOCK END Variable txt_BootVerNo

// CODE BLOCK BEGIN Variable soc_value MSw1MCws
// 变量文档 "soc_value"
TMPVarDouble soc_value;
// CODE BLOCK END Variable soc_value

// CODE BLOCK BEGIN Variable soc_type MCwxNjUsLA__
// 变量文档 "soc_type"
TMPVarInt soc_type;
// CODE BLOCK END Variable soc_type

// CODE BLOCK BEGIN Variable mes_type MCwwLCw_
// 变量文档 "mes_type"
TMPVarInt mes_type;
// CODE BLOCK END Variable mes_type

// CODE BLOCK BEGIN Variable mes_write MiwsLA__
// 变量文档 "mes_write"
TMPVarString mes_write;
// CODE BLOCK END Variable mes_write

// CODE BLOCK BEGIN Variable mes_read MiwsLA__
// 变量文档 "mes_read"
TMPVarString mes_read;
// CODE BLOCK END Variable mes_read

// CODE BLOCK BEGIN Variable relay_control_mode MCwwLCw_
// 变量文档 "relay_control_mode"
TMPVarInt relay_control_mode;
// CODE BLOCK END Variable relay_control_mode

// CODE BLOCK BEGIN Variable 当前写入成功次数 MCwwLCw_
// 变量文档 "当前写入成功次数"
TMPVarInt 当前写入成功次数;
// CODE BLOCK END Variable 当前写入成功次数

// CODE BLOCK BEGIN Variable 当前写入失败次数 MCwwLCw_
// 变量文档 "当前写入失败次数"
TMPVarInt 当前写入失败次数;
// CODE BLOCK END Variable 当前写入失败次数

// CODE BLOCK BEGIN Variable KBData Miw4MTAyMjItMDAxNDlWMS4xMTIzNDU2Nzg5MDEyMjQuMjcwNS0wLjAwMDAwMDMzMC4wMDAxNDc1ODAtMC4wMDQwMzY5OEZGLCw_
// 变量文档 "KBData"
TMPVarString KBData;
// CODE BLOCK END Variable KBData

// CODE BLOCK BEGIN Variable txtReadcheckCurrentData MiwwLCw_
// 变量文档 "txtReadcheckCurrentData"
TMPVarString txtReadcheckCurrentData;
// CODE BLOCK END Variable txtReadcheckCurrentData

// CODE BLOCK BEGIN Variable var_k1 MiwwLCw_
// 变量文档 "var_k1"
TMPVarString var_k1;
// CODE BLOCK END Variable var_k1

// CODE BLOCK BEGIN Variable var_k2 MiwwLCw_
// 变量文档 "var_k2"
TMPVarString var_k2;
// CODE BLOCK END Variable var_k2

// CODE BLOCK BEGIN Variable var_k3 MiwsLA__
// 变量文档 "var_k3"
TMPVarString var_k3;
// CODE BLOCK END Variable var_k3

// CODE BLOCK BEGIN Variable var_k4 MiwsLA__
// 变量文档 "var_k4"
TMPVarString var_k4;
// CODE BLOCK END Variable var_k4

// CODE BLOCK BEGIN Variable var_k5 MiwsLA__
// 变量文档 "var_k5"
TMPVarString var_k5;
// CODE BLOCK END Variable var_k5

// CODE BLOCK BEGIN Variable var_k6 MiwsLA__
// 变量文档 "var_k6"
TMPVarString var_k6;
// CODE BLOCK END Variable var_k6

// CODE BLOCK BEGIN Variable var_k7 MiwsLA__
// 变量文档 "var_k7"
TMPVarString var_k7;
// CODE BLOCK END Variable var_k7

// CODE BLOCK BEGIN Variable var_k8 MiwsLA__
// 变量文档 "var_k8"
TMPVarString var_k8;
// CODE BLOCK END Variable var_k8

// CODE BLOCK BEGIN Variable var_k9 MiwsLA__
// 变量文档 "var_k9"
TMPVarString var_k9;
// CODE BLOCK END Variable var_k9

// CODE BLOCK BEGIN Variable var_k10 MiwsLA__
// 变量文档 "var_k10"
TMPVarString var_k10;
// CODE BLOCK END Variable var_k10

// CODE BLOCK BEGIN Variable var_b1 MiwsLA__
// 变量文档 "var_b1"
TMPVarString var_b1;
// CODE BLOCK END Variable var_b1

// CODE BLOCK BEGIN Variable var_b2 MiwsLA__
// 变量文档 "var_b2"
TMPVarString var_b2;
// CODE BLOCK END Variable var_b2

// CODE BLOCK BEGIN Variable var_b3 MiwsLA__
// 变量文档 "var_b3"
TMPVarString var_b3;
// CODE BLOCK END Variable var_b3

// CODE BLOCK BEGIN Variable var_b4 MiwsLA__
// 变量文档 "var_b4"
TMPVarString var_b4;
// CODE BLOCK END Variable var_b4

// CODE BLOCK BEGIN Variable var_b5 MiwsLA__
// 变量文档 "var_b5"
TMPVarString var_b5;
// CODE BLOCK END Variable var_b5

// CODE BLOCK BEGIN Variable var_b6 MiwsLA__
// 变量文档 "var_b6"
TMPVarString var_b6;
// CODE BLOCK END Variable var_b6

// CODE BLOCK BEGIN Variable var_b7 MiwsLA__
// 变量文档 "var_b7"
TMPVarString var_b7;
// CODE BLOCK END Variable var_b7

// CODE BLOCK BEGIN Variable var_b8 MiwsLA__
// 变量文档 "var_b8"
TMPVarString var_b8;
// CODE BLOCK END Variable var_b8

// CODE BLOCK BEGIN Variable var_b9 MiwsLA__
// 变量文档 "var_b9"
TMPVarString var_b9;
// CODE BLOCK END Variable var_b9

// CODE BLOCK BEGIN Variable var_b10 MiwsLA__
// 变量文档 "var_b10"
TMPVarString var_b10;
// CODE BLOCK END Variable var_b10

// CODE BLOCK BEGIN Variable RABC_BT_OnClick MCwtMSy158H3seq2qLbB0LSwtMWlsLTPwrSlt6Is
// 变量文档 "RABC_BT_OnClick"
TMPVarInt RABC_BT_OnClick;
// CODE BLOCK END Variable RABC_BT_OnClick

// CODE BLOCK BEGIN Variable checkCurrentData MiwwLCw_
// 变量文档 "checkCurrentData"
TMPVarString checkCurrentData;
// CODE BLOCK END Variable checkCurrentData

// CODE BLOCK BEGIN Variable RW2_BT_ONCLICK MCwwLCw_
// 变量文档 "RW2_BT_ONCLICK"
TMPVarInt RW2_BT_ONCLICK;
// CODE BLOCK END Variable RW2_BT_ONCLICK

// CODE BLOCK BEGIN Variable tb_DisChrgCapAh MiwsLA__
// 变量文档 "tb_DisChrgCapAh"
TMPVarString tb_DisChrgCapAh;
// CODE BLOCK END Variable tb_DisChrgCapAh

// CODE BLOCK BEGIN Variable textBox8 MiwsLA__
// 变量文档 "textBox8"
TMPVarString textBox8;
// CODE BLOCK END Variable textBox8

// CODE BLOCK BEGIN Variable textBox9 MiwsLA__
// 变量文档 "textBox9"
TMPVarString textBox9;
// CODE BLOCK END Variable textBox9

// CODE BLOCK BEGIN Variable tb_AN19 MiwsLA__
// 变量文档 "tb_AN19"
TMPVarString tb_AN19;
// CODE BLOCK END Variable tb_AN19

// CODE BLOCK BEGIN Variable textBox7 MiwsLA__
// 变量文档 "textBox7"
TMPVarString textBox7;
// CODE BLOCK END Variable textBox7

// CODE BLOCK BEGIN Variable txtbalcscQ MiwsLA__
// 变量文档 "txtbalcscQ"
TMPVarString txtbalcscQ;
// CODE BLOCK END Variable txtbalcscQ

// CODE BLOCK BEGIN Variable txtbaltime MiwsLA__
// 变量文档 "txtbaltime"
TMPVarString txtbaltime;
// CODE BLOCK END Variable txtbaltime

// CODE BLOCK BEGIN Variable txtbalcells MiwsLA__
// 变量文档 "txtbalcells"
TMPVarString txtbalcells;
// CODE BLOCK END Variable txtbalcells

// CODE BLOCK BEGIN Variable label167 MiwsLA__
// 变量文档 "label167"
TMPVarString label167;
// CODE BLOCK END Variable label167

// CODE BLOCK BEGIN Variable label_Lable_Info MiwsLA__
// 变量文档 "label_Lable_Info"
TMPVarString label_Lable_Info;
// CODE BLOCK END Variable label_Lable_Info

// CODE BLOCK BEGIN Variable label_BpsWakeupAbnFlg MiwsLA__
// 变量文档 "label_BpsWakeupAbnFlg"
TMPVarString label_BpsWakeupAbnFlg;
// CODE BLOCK END Variable label_BpsWakeupAbnFlg

// CODE BLOCK BEGIN Variable linkLabel_BpsInternalErrorFlag MiwsLA__
// 变量文档 "linkLabel_BpsInternalErrorFlag"
TMPVarString linkLabel_BpsInternalErrorFlag;
// CODE BLOCK END Variable linkLabel_BpsInternalErrorFlag

// CODE BLOCK BEGIN Variable label_BpsPressureData MiwsLA__
// 变量文档 "label_BpsPressureData"
TMPVarString label_BpsPressureData;
// CODE BLOCK END Variable label_BpsPressureData

// CODE BLOCK BEGIN Variable 周期发送 MSwwLjAsLA__
// 变量文档 "周期发送"
TMPVarDouble 周期发送;
// CODE BLOCK END Variable 周期发送

// CODE BLOCK BEGIN Variable 主正 MSwwLjAsLA__
// 变量文档 "主正"
TMPVarDouble 主正;
// CODE BLOCK END Variable 主正

// CODE BLOCK BEGIN Variable 预充 MSwwLjAsLA__
// 变量文档 "预充"
TMPVarDouble 预充;
// CODE BLOCK END Variable 预充

// CODE BLOCK BEGIN Variable 快充正 MSwwLjAsLA__
// 变量文档 "快充正"
TMPVarDouble 快充正;
// CODE BLOCK END Variable 快充正

// CODE BLOCK BEGIN Variable 主负 MSwwLjAsLA__
// 变量文档 "主负"
TMPVarDouble 主负;
// CODE BLOCK END Variable 主负

// CODE BLOCK BEGIN Variable 绝缘检测 MSwwLjAsLA__
// 变量文档 "绝缘检测"
TMPVarDouble 绝缘检测;
// CODE BLOCK END Variable 绝缘检测

// CODE BLOCK BEGIN Variable 快充负 MSwwLjAsLA__
// 变量文档 "快充负"
TMPVarDouble 快充负;
// CODE BLOCK END Variable 快充负

// CODE BLOCK BEGIN Variable 读取 MCwwLLbByKG/qrnY1rUs
// 变量文档 "读取"
TMPVarInt 读取;
// CODE BLOCK END Variable 读取

// CODE BLOCK BEGIN Variable AKH_Note MCwwLCw_
// 变量文档 "AKH_Note"
TMPVarInt AKH_Note;
// CODE BLOCK END Variable AKH_Note

// CODE BLOCK BEGIN Variable FCR_Rval MCwwLLXn1+jX6Na10aHU8cb3LA__
// 变量文档 "FCR_Rval"
TMPVarInt FCR_Rval;
// CODE BLOCK END Variable FCR_Rval

// CODE BLOCK BEGIN Variable OnSwitchBoxClick MCwwLLbB0LQytcTRodTxv6q52Cw_
// 变量文档 "OnSwitchBoxClick"
TMPVarInt OnSwitchBoxClick;
// CODE BLOCK END Variable OnSwitchBoxClick

// CODE BLOCK BEGIN Variable heatting_time MCwyMCws
// 变量文档 "heatting_time"
TMPVarInt heatting_time;
// CODE BLOCK END Variable heatting_time

// CODE BLOCK BEGIN Variable heating_timer MiwwMDowMDowMCws
// 变量文档 "heating_timer"
TMPVarString heating_timer;
// CODE BLOCK END Variable heating_timer

// CODE BLOCK BEGIN Variable RELAY_WINDOW_RELAYE_ARR Miy8zLXnxvcwMCy8zLXnxvcwMSwwK1ZBRFFvXw__
// 变量文档 "RELAY_WINDOW_RELAYE_ARR"
TMPVarString RELAY_WINDOW_RELAYE_ARR;
// CODE BLOCK END Variable RELAY_WINDOW_RELAYE_ARR

// CODE BLOCK BEGIN Variable RelayStateChange MCwwLLzMtefG99e0zKy3osn6uMSx5LvYtfe1xLXY1rcs
// 变量文档 "RelayStateChange"
TMPVarInt RelayStateChange;
// CODE BLOCK END Variable RelayStateChange

// CODE BLOCK BEGIN Variable RelayModeChange MCwwLLzMtefG98Sjyr23osn6uMSx5LvYtfe6r8r91rjV67XY1rcs
// 变量文档 "RelayModeChange"
TMPVarInt RelayModeChange;
// CODE BLOCK END Variable RelayModeChange

// CODE BLOCK BEGIN Variable ProjectPath MiyhsKGxLCw_
// 变量文档 "ProjectPath"
TMPVarString ProjectPath;
// CODE BLOCK END Variable ProjectPath

// CODE BLOCK BEGIN Variable IsLoadingPro MCwwLMrHt/HV/dTavNPU2Lmks8ws
// 变量文档 "IsLoadingPro"
TMPVarInt IsLoadingPro;
// CODE BLOCK END Variable IsLoadingPro

// CODE BLOCK BEGIN Variable RELAY_INIT MCwwLCw_
// 变量文档 "RELAY_INIT"
TMPVarInt RELAY_INIT;
// CODE BLOCK END Variable RELAY_INIT

// CODE BLOCK BEGIN Timer HighVoltOnTimer MTAw
// 定时器文档 "HighVoltOnTimer"
TMPTimerMS HighVoltOnTimer;
// CODE BLOCK END Timer HighVoltOnTimer

// CODE BLOCK BEGIN Timer HighVoltOffTimer MTAw
// 定时器文档 "HighVoltOffTimer"
TMPTimerMS HighVoltOffTimer;
// CODE BLOCK END Timer HighVoltOffTimer

// CODE BLOCK BEGIN Timer timerHardWakeupTest MTAw
// 定时器文档 "timerHardWakeupTest"
TMPTimerMS timerHardWakeupTest;
// CODE BLOCK END Timer timerHardWakeupTest

// CODE BLOCK BEGIN Timer HeattingTimer MTAwMA__
// 定时器文档 "HeattingTimer"
TMPTimerMS HeattingTimer;
// CODE BLOCK END Timer HeattingTimer

// CODE BLOCK BEGIN Timer GraphUpdateTimer NTAw
// 定时器文档 "GraphUpdateTimer"
TMPTimerMS GraphUpdateTimer;
// CODE BLOCK END Timer GraphUpdateTimer

// CODE BLOCK BEGIN Global_Definitions 
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <math.h>
#include <thread>
#include <map>
#include <vector>
#include <malloc.h>
#include "ctm_string.h"
#include "common.h"
#include "scan.h"
#include "crc.h"
#include "graphic.h"
#include "project.h"

#include "RABCRW.h"
#include "DataRWPage.h"
#include "ReadWrite2.h"
#include "TSQFRelay.h"
#include "TSUDSReadList.h"


using namespace std;
using namespace common;
using namespace scan;

const u32 P2U_DB_ID = 0x1E0; //应用报文ID
const u32 RLY_DB_ID = 0x1E1; //应用报文ID
const u32 CAL_DB_ID = 0x1E2; //应用报文ID
const u32 U2P_DB_ID = 0x7FE;//应用报文ID
const u32 BPS_DB_ID = 0x310;//应用报文ID
const u32 CRRU_CALIBRA_ID = 0x111; //应用报文ID
const u32 P2U_ABC = 0x342;//电流校准功能写指令ID                                         
const u32 U2P_ABC = 0x352;//电流校准功能报文回读
const u32 U2P_FAULT_ID = 0xB1;

const u8 ReadGBCodeID = 0xB3;//国标码读取ID
const u8 ReadPackSNID = 0xB6;//PackSN读取ID
const u8 ReadBarcodeID = 0xB1;//Barcode读取ID
const u8 ReadBarcodeDateID = 0xB2;//BarcodeDate读取ID
const u8 ReadPNID = 0xB4;//PN读取ID
const u8 ReadECUDeliveryAssemblyPart = 0xB7;
const u8 ReadECUCoreAssemblyPartNumber = 0xB8;
const u8 ReadPrimaryBootloaderSoft = 0xB9;
const u8 ReadPrimaryBootloaderDiagDatabase = 0xC1;

const u8 WriteGBCodeID = 0x3B;//国标码写入ID
const u8 WritePackSNID = 0x6B;//PackSN写入ID
const u8 WriteECUDeliveryAssemblyPart = 0x7B;
const u8 WriteECUCoreAssemblyPartNumber = 0x8B;
const u8 WritePrimaryBootloaderSoft = 0x9B;
const u8 WritePrimaryBootloaderDiagDatabase = 0x1C;

map<s32, u8> mesReadMap;
map<s32, u8> mesWriteMap;
unique_ptr<TemperatureGraph> temp_graph;
unique_ptr<VoltageGraph> volt_graph;
unique_ptr<project::CATLProject> p;
vector<vector<common::SignalDef>> v_csc_v_defs;
vector<vector<common::SignalDef>> v_csc_t_defs;
bool isForceMode = false;
bool IsProtect = false;
bool IsCommonForceMode = false; //一般强控模式

void init_pn_map(){
     mesReadMap[0] = ReadGBCodeID;
     mesReadMap[1] = ReadPackSNID;
     mesReadMap[2] = ReadBarcodeID;
     mesReadMap[3] = ReadBarcodeDateID;
     mesReadMap[4] = ReadPNID;
     mesReadMap[5] = ReadECUDeliveryAssemblyPart;
     mesReadMap[6] = ReadECUCoreAssemblyPartNumber;
     mesReadMap[7] = ReadPrimaryBootloaderSoft;
     mesReadMap[8] = ReadPrimaryBootloaderDiagDatabase;
     
     mesWriteMap[0] = WriteGBCodeID;
     mesWriteMap[1] = WritePackSNID;
     mesWriteMap[5] = WriteECUDeliveryAssemblyPart;
     mesWriteMap[6] = WriteECUCoreAssemblyPartNumber;
     mesWriteMap[7] = WritePrimaryBootloaderSoft;
     mesWriteMap[8] = WritePrimaryBootloaderDiagDatabase;
}

map<s32, shared_ptr<RelayService>> relay_map;
vector<string> RelayService::relays;
int rcm_pv = 0;

//RelayService(string name, const u32 id, const u8 relay_id)
void init_realy_map(){
//      rtlSignalComparer.ClearAllSignalsFromPanel("继电器状态");
//     
//      relay_map[0xD1] = make_shared<RelayService>("主正继电器", RLY_DB_ID, 0xD1, 0xC8, 22);
//      relay_map[0xD2] = make_shared<RelayService>("主负继电器", RLY_DB_ID, 0xD2, 0xC8, 20);
//      relay_map[0xD3] = make_shared<RelayService>("充正继电器", RLY_DB_ID, 0xD3, 0xC8, 23);
//      relay_map[0xD4] = make_shared<RelayService>("充负控制继电器", RLY_DB_ID, 0xD4, 0xC8, 19);
//      relay_map[0xD5] = make_shared<RelayService>("预充继电器", RLY_DB_ID, 0xD5, 0xC8, 21);
//      relay_map[0xD6] = make_shared<RelayService>("慢充正继电器", RLY_DB_ID, 0xD6, 0xC8, 18);
//      relay_map[0xD7] = make_shared<RelayService>("加热正继电器", RLY_DB_ID, 0xD7, 0xC8, 17);
//      relay_map[0xD8] = make_shared<RelayService>("加热负继电器", RLY_DB_ID, 0xD8, 0xC8, 16);
//      relay_map[0xD9] = make_shared<RelayService>("慢充负继电器", RLY_DB_ID, 0xD9, 0xC8, 14);
//      relay_map[0xDA] = make_shared<RelayService>("慢充预充继电器", RLY_DB_ID, 0xDA, 0xC8, 14);
//      relay_map[0xDB] = make_shared<RelayService>("AUX3继电器", RLY_DB_ID, 0xDB, 0xC8, 24);
//      relay_map[0xDC] = make_shared<RelayService>("AUX2继电器", RLY_DB_ID, 0xDC, 0xC8, 25);
//      relay_map[0xDD] = make_shared<RelayService>("AUX1继电器", RLY_DB_ID, 0xDD, 0xC8, 26);
//      relay_map[0xDE] = make_shared<RelayService>("充正预充继电器", RLY_DB_ID, 0xDE, 0x7FF, 15);
//      relay_map[0xA5] = make_shared<RelayService>("预留继电器1", RLY_DB_ID, 0xA5, 0x7FF, 51);
//      relay_map[0xA4] = make_shared<RelayService>("预留继电器2", RLY_DB_ID, 0xA4, 0x7FF, 13);
//      relay_map[0xA2] = make_shared<RelayService>("水泵继电器", RLY_DB_ID, 0xA2, 0x7FF, 49);
//      
//      Sleep(100); //需要等待一会，否则比较模块无法刷新
//      for(auto it : RelayService::relays){
//             rtlSignalComparer.AddSystemVarToPanel("继电器状态", it.c_str());
//      }
}

u8 high_volt_counter = 0;
u32 hv_timeout_counter = 0;

string cusCheckSoftVer = "";
double temp_value = -30;
int heattime = 20;
int heatcounter = 1200;

string second_to_str(int second) {
    int h = second / 3600;
    int m = (second % 3600) / 60;
    int s = second % 3600 % 60;
    char time[10] = {0};
    sprintf(time, "%02d:%02d:%02d", h, m, s);
    string timeStr = string(time);
    return timeStr;
}

void ProjectUpdate() {
    GraphUpdateTimer.stop();
    p->load_csc_signal_defines(v_csc_v_defs, v_csc_t_defs);
    app.set_system_var_int32("VoltNum", p->m_csc_volt_num);//设置csc电压个数                                        
    app.set_system_var_int32("TempNum", p->m_csc_temp_num);//设置csc温度个数
    RELAY_INIT.set(1);
    
    temp_graph = make_unique<TemperatureGraph>(p->m_csc_num, p->m_csc_temp_num);
    volt_graph = make_unique<VoltageGraph>(p->m_csc_num, p->m_csc_volt_num);
    temp_graph->SetTempWarningLimit(100);
    //volt_graph -> SetVolValue(13, 19, 32767);
    ProjectPath.set("");
    std::string Directory=   p->ts_project + "Configuration\\" + p->loaded_project;
        //  UDS读取列表加载
       ProjectPath.set(Directory.c_str());
       g_tqd=CATL::LoadDiagConfig(Directory);
       CATL::showlist(g_tqd);
       UUDSTEST(g_tqd);
       //UpdateUDSListSystemVar(tqd);
        //读入继电器配置
    //log("++++++++++++++++++++++%s",Directory.c_str());
  
     std::vector<CATL::Relay> cg=CATL::GetRelayConfigFormXML(Directory);
//std::vector<CATL::Relay> cg;
    std::string relayName="";
    std::map<std::string,CATL::Relay>& grm=CATL::gRelayMap;
    //切换项目关闭所有继电器
    for(auto ele : grm){
        CATL::RelayStateChange(ele.first.c_str(),0);
    
    }
    grm.clear();
    std::vector<std::string> nameArr;
    for(int i=-1;++i<cg.size();){
            std::string name= cg[i].Name;
            auto it =grm.find(name);
            if(it !=grm.end()){
                  for(int j=0;++j<0xffffffff;){
                          std::string name1=name+std::to_string(j);
                          auto it =grm.find(name1);
                          if(it ==grm.end()){
                                name=  name1;
                                break;
                          }
                  }
            }
            
               app.create_system_var(name.c_str(),svtInt32,"0","继电器状态 的变量信号");
//                rtlSignalComparer.AddSystemVarToPanel("继电器状态",name.c_str());
              
               grm[name]   =cg[i];
               nameArr.push_back(name);
               if("" == relayName){
                   relayName=name;
               }
               else{
                     relayName+=","+name;
               }
    }
    rtlSignalComparer.ClearAllSignalsFromPanel("继电器状态");   //清空    继电器状态 窗口继电器
    
    std::thread t([](std::vector<std::string> nameArr){ 
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        for(auto it : nameArr){
                 rtlSignalComparer.AddSystemVarToPanel("继电器状态",it.c_str());
                 }
    },
    nameArr);
    t.detach();
  
    
//     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    RELAY_WINDOW_RELAYE_ARR.set(relayName.c_str());
    int h_ini;
    if(0 == app.ini_create((p->ts_project + "Configuration\\项目配置.cfg").c_str(), &h_ini)) {
                app.ini_write_string(h_ini,"setting", "LoadedProject", p->loaded_project.c_str());
                app.ini_close(h_ini);
    }


    //************************************************************
    GraphUpdateTimer.start();
}

void OnProjectChanged(const char* project, int param) {  //项目对象发生改变

    if(p->loaded_project == string(project)) return;
    p->loaded_project = string(project);
    p->m_project_n = p->ts_project + "Configuration\\" + p->loaded_project;
    
    ProjectUpdate();
}
// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN Documentation  WVhCd0xuQmhibVZzWDNObGRGOWxibUZpYkdVb0tXRndjQzV3WVc1bGJGOXpaWFJmWlc1aFlteGxLQ2tOQ2dfXw__
// CODE BLOCK END Documentation 

// GEN BLOCK BEGIN Custom_Function
s32 read_ver_info(const double flag);
s32 write_soc(const double flag);
s32 read_soc(const double flag);
s32 write_pack_message(const u32 AId, const u8 writeId, u8* packMes, const s32 len, const s32 limitLength);
s32 write_general_mes(const double A1);
s32 ForceModeMsgBox(void);
s32 control_relay(const double AId);
s32 execute_command(const double value);
s32 HighVoltTest(const double A1);
s32 stop_all_timer(void);
s32 tabpage_change(const double page);
s32 write_RABC(const double A1);
s32 set_heatting_time(const double Aq);
// GEN BLOCK END Custom_Function

// CODE BLOCK BEGIN On_CAN_Rx can_ch1_tbRtext MCwtMSwyODg_
// CAN报文接收事件 "can_ch1_tbRtext" 针对标识符 = 0x120
void on_can_rx_can_ch1_tbRtext(const TCAN* ACAN) { try {  // 针对标识符 = 0x120

  const u8* msg = ACAN->FData;
  if(01 !=ACAN->FIdxChn)return;
  
  
  
  //更新程序变量内容，定义在RABCRW.h 里面  ,g_abcRW
  double aa=(msg[1] << 8) + msg[0];
  std::ostringstream ss;
  ss<<fixed<<setprecision(10)<<aa;
  SYSTEM_CBCT::g_abcRW.tbRtext= ss.str();
















} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_CAN_Rx can_ch1_tbRtext

// CODE BLOCK BEGIN On_CAN_FD_Rx On_U2P_DB_ID_Rx LTEsLTEsMjA0Ng__
// CAN报文接收事件 "On_U2P_DB_ID_Rx" 针对标识符 = 0x7FE (FD)
void on_canfd_rx_On_U2P_DB_ID_Rx(const TCANFD* ACANFD) { try {  // 针对标识符 = 0x7FE (FD)
// if (ACANFD->FIdxChn != CH1) return; // if you want to filter channel
log("!!!!!!!!!!!!!!!");
u8 flag = ACANFD->FData[0];
const u8* data = ACANFD->FData;

if(flag == 0xC9){//软件版本号
    string soft_no = to_ascii(data, 3, 5);
    log(soft_no.c_str());
    if(soft_no.length() >= 16){
        soft_no = soft_no.substr(0, 16);
    }
    char* tmp_str = txt_SofVerNo.get();
    string verStr;
    if(tmp_str == NULL)
        verStr = soft_no;
    else
        verStr = string(tmp_str) + soft_no;
       
        log("%s",verStr.c_str()); 
        
    txt_SofVerNo.set(verStr.c_str());//显示到panel界面
}
else if(flag == 0xCC){//硬件版本号
    string hard_no = to_ascii(data, 3, 5);
    if(hard_no.length() >= 16){
        hard_no = hard_no.substr(0, 16);
    }
    char* tmp_str = txt_HardVerNo.get();
    string verStr;
    if(tmp_str == NULL)
        verStr = hard_no;
    else
        verStr = string(tmp_str) + hard_no;
    txt_HardVerNo.set(verStr.c_str());//显示到panel界面
}
else if(flag == 0xCB){//RPJ信息
    string rpj_info = to_ascii(data, 3, 5);
    if(rpj_info.length() >= 16){
        rpj_info = rpj_info.substr(0, 16);
    }
    char* tmp_str = txt_PRJInfo.get();
    string verStr;
    if(tmp_str == NULL)
        verStr = rpj_info;
    else
        verStr = string(tmp_str) + rpj_info;
    txt_PRJInfo.set(verStr.c_str());//显示到panel界面
}
else if(flag == 0xB0){//Boot版本号
    string boot_no = to_ascii(data, 3, 5);
    if(boot_no.length() >= 16){
        boot_no = boot_no.substr(0, 16);
    }
    char* tmp_str = txt_BootVerNo.get();
    string verStr;
    if(tmp_str == NULL)
        verStr = boot_no;
    else
        verStr = string(tmp_str) + boot_no;
    
    txt_BootVerNo.set(verStr.c_str());//显示到panel界面
}
else if(flag == 0xA5 || flag == 0xA6 || flag == 0xA7 || flag == 0xA9 || flag == 0xAB || flag == 0xAC){//SOC
    double soc_data = (data[1] * 256 + data[2]) * pow(2, -9);
    soc_value.set(soc_data);//显示到panel界面
}
else if(flag == 0xAA){
    double soc_data = (data[1] * 256 + data[2]) * pow(2, -4);
    soc_value.set(soc_data);//显示到panel界面
}
else if(flag == ReadGBCodeID || flag == ReadPackSNID || flag == ReadBarcodeID || flag == ReadBarcodeDateID || 
             flag == ReadPNID || flag == ReadECUDeliveryAssemblyPart || flag == ReadPrimaryBootloaderSoft || flag == ReadPrimaryBootloaderDiagDatabase){
    string info = to_ascii(data, 3, 5);
    char* tmp_str = mes_read.get();
    string verStr;
    if(tmp_str == NULL)
        verStr = info;
    else
        verStr = string(tmp_str) + info;
    //mes_read.set("");
    mes_read.set(verStr.c_str());//显示到panel界面
}





} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_CAN_FD_Rx On_U2P_DB_ID_Rx

// CODE BLOCK BEGIN On_CAN_FD_Rx NewOn_CAN_FD_Rx2 LTEsLTEsLTE_
// CAN报文接收事件 "NewOn_CAN_FD_Rx2" 针对标识符 = 任意 (FD)
void on_canfd_rx_NewOn_CAN_FD_Rx2(const TCANFD* ACANFD) { try {  // 针对标识符 = 任意 (FD)

///继电器状态读取
for(auto it : relay_map){ 
    auto relay = it.second;     
    if(ACANFD -> FIdentifier != relay -> feedback_id){ //当Id与设置的id相同时获取继电器状态
         continue;
    }
    relay -> get_relay_status(ACANFD -> FData);
}
//CSC_V 电压图表的值设置
for(int i = 0; i < p -> m_csc_num; i++) {
    for(int j = 0; j < p -> m_csc_volt_num; j++) {
        if(v_csc_v_defs[i][j].id != ACANFD -> FIdentifier) continue;
        
        double value = com.get_can_signal_value(&v_csc_v_defs[i][j].signal, const_cast<u8*>(ACANFD -> FData)); 
        value = value == 65535.0 ? 0 : value;
        volt_graph -> SetVolValue(i, j, value);
    }
}
//CSC_T 温度图表的值设置
for(int i = 0; i < p -> m_csc_num; i++) {
    for(int j = 0; j < p -> m_csc_temp_num; j++) {
        if(v_csc_t_defs[i][j].id != ACANFD -> FIdentifier) continue;
        double value = com.get_can_signal_value(&v_csc_t_defs[i][j].signal, const_cast<u8*>(ACANFD -> FData));
        
        temp_graph -> SetTempValue(i, j, value);
    }
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_CAN_FD_Rx NewOn_CAN_FD_Rx2

// CODE BLOCK BEGIN On_CAN_FD_Rx On_CAN_Rx7FA LTEsLTEsMjA0Mg__
// CAN报文接收事件 "On_CAN_Rx7FA" 针对标识符 = 0x7FA (FD)
void on_canfd_rx_On_CAN_Rx7FA(const TCANFD* ACANFD) { try {  // 针对标识符 = 0x7FA (FD)
// if (ACANFD->FIdxChn != CH1) return; // if you want to filter channel
const u8* data = ACANFD->FData;

if(data[1] == 0x04 && data[2] == 0x00){
    cusCheckSoftVer = to_ascii(data, 3, 5);
}
else if(data[1] == 0x04 && data[2] != 0x00){
    cusCheckSoftVer += to_ascii(data, 3, 5); 
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_CAN_FD_Rx On_CAN_Rx7FA

// CODE BLOCK BEGIN On_Var_Change On_relay_control_mode cmVsYXlfY29udHJvbF9tb2RlLDA_
// 变量变化事件 "On_relay_control_mode" 针对变量 "relay_control_mode" [On Change]
void on_var_change_On_relay_control_mode(void) { try { // 变量 = relay_control_mode
int mode = relay_control_mode.get();

if(mode == rcm_pv) return;

int result = MessageBox(NULL, "模式切换会切断强控继电器，是否切换？", "提示", MB_YESNO);

if(result != IDYES){
    relay_control_mode.set(rcm_pv);
    return;
}
if((mode == 1 && rcm_pv != 2) || (mode == 2 && rcm_pv != 1)){
    char password[128];
    app.prompt_user_input_string("请输入密码", password, 128);
    //log(password);
    string passwordStr = string(password);
    trim(passwordStr);
    if(passwordStr != "TVC"){
        relay_control_mode.set(rcm_pv);
        MessageBox(NULL, "密码错误", "提示", MB_OK);
        return;
    }
}

if(mode == 0){ //非强制模式
    u8 data[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 0x00, 0x00};
    transmit_can_data(0, RLY_DB_ID, data, 8, false);
    app.panel_set_enable("数据读写", "RelayGroupBox", false);
    IsCommonForceMode = false;
}
else if(mode == 1){ //一般强制模式
    u8 data[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 0x00, 0x00};
    transmit_can_data(0, RLY_DB_ID, data, 8, false);
    
    Sleep(1000);
    data[4] = 0x01;
    transmit_can_data(0, RLY_DB_ID, data, 8, false);
    IsCommonForceMode = true;
    
    app.panel_set_enable("数据读写", "RelayGroupBox", true);  
}
else if(mode == 2){ //特殊强制模式
    u8 data[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 0x00, 0x00};
    transmit_can_data(0, RLY_DB_ID, data, 8, false);
    
    Sleep(1000);
    data[4] = 0x02;
    transmit_can_data(0, RLY_DB_ID, data, 8, false);
    IsCommonForceMode = false;
    
    app.panel_set_enable("数据读写", "RelayGroupBox", true);  
}
rcm_pv = mode;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change On_relay_control_mode

// CODE BLOCK BEGIN On_Var_Change On_RABC_BT_OnClick UkFCQ19CVF9PbkNsaWNrLC0x
// 变量变化事件 "On_RABC_BT_OnClick" 针对变量 "RABC_BT_OnClick" [On Written]
void on_var_change_On_RABC_BT_OnClick(void) { try { // 变量 = RABC_BT_OnClick
  int index=RABC_BT_OnClick.get();

  SYSTEM_CBCT::g_ui_abcPG.OnButtonClick(index); //对接读写相关按钮按下触发的事件：在DateRWPage.h文件中

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change On_RABC_BT_OnClick

// CODE BLOCK BEGIN On_Var_Change On_RW2_BT_ONCLICK UlcyX0JUX09OQ0xJQ0ssLTE_
// 变量变化事件 "On_RW2_BT_ONCLICK" 针对变量 "RW2_BT_ONCLICK" [On Written]
void on_var_change_On_RW2_BT_ONCLICK(void) { try { // 变量 = RW2_BT_ONCLICK
 int index=RW2_BT_ONCLICK.get();
 SYSTEM_CBCT::g_ui_abcPG.OnButtonClick_rw2(index);//按钮响应事件在UsrButton.h里面改，增加按钮在DataRWPage.h里面增加

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change On_RW2_BT_ONCLICK

// CODE BLOCK BEGIN On_Var_Change OnCYCSend 1tzG2reiy80sLTE_
// 变量变化事件 "OnCYCSend" 针对变量 "周期发送" [On Written]
void on_var_change_OnCYCSend(void) { try { // 变量 = 周期发送
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(周期发送.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnCYCSend

// CODE BLOCK BEGIN On_Var_Change OnMP 1vfV/SwtMQ__
// 变量变化事件 "OnMP" 针对变量 "主正" [On Written]
void on_var_change_OnMP(void) { try { // 变量 = 主正
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(主正.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnMP

// CODE BLOCK BEGIN On_Var_Change OnDP v+yz5NX9LC0x
// 变量变化事件 "OnDP" 针对变量 "快充正" [On Written]
void on_var_change_OnDP(void) { try { // 变量 = 快充正
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(快充正.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnDP

// CODE BLOCK BEGIN On_Var_Change OnMNP 1ve4uiwtMQ__
// 变量变化事件 "OnMNP" 针对变量 "主负" [On Written]
void on_var_change_OnMNP(void) { try { // 变量 = 主负
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(主负.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnMNP

// CODE BLOCK BEGIN On_Var_Change OnISO vvjUtbzssuIsLTE_
// 变量变化事件 "OnISO" 针对变量 "绝缘检测" [On Written]
void on_var_change_OnISO(void) { try { // 变量 = 绝缘检测
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(绝缘检测.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnISO

// CODE BLOCK BEGIN On_Var_Change OnDNP v+yz5Li6LC0x
// 变量变化事件 "OnDNP" 针对变量 "快充负" [On Written]
void on_var_change_OnDNP(void) { try { // 变量 = 快充负
//SYSTEM_CBCT::g_ui_abcPG.CheckChange(快充负.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnDNP

// CODE BLOCK BEGIN On_Var_Change OnRP 1KSz5CwtMQ__
// 变量变化事件 "OnRP" 针对变量 "预充" [On Written]
void on_var_change_OnRP(void) { try { // 变量 = 预充

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change OnRP

// CODE BLOCK BEGIN On_Var_Change On_SwitchBoxClick T25Td2l0Y2hCb3hDbGljaywtMQ__
// 变量变化事件 "On_SwitchBoxClick" 针对变量 "OnSwitchBoxClick" [On Written]
void on_var_change_On_SwitchBoxClick(void) { try { // 变量 = OnSwitchBoxClick

 //这个一般不用修改，添加开关时选择调用API，data_wr_SwichBox_click即可，记得修改开关的左右值为唯一的    
 //到UserSwitchBox.h  添加你的开关响应，
 //TS_UI_MANAG::RABCPAGE::RABCPAGE()加载响应方法
SYSTEM_CBCT::g_ui_abcPG.CheckChange(OnSwitchBoxClick.get());
//log("OnSwitchBoxClick:%d",OnSwitchBoxClick.get());

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change On_SwitchBoxClick

// CODE BLOCK BEGIN On_Var_Change On_ErrWarningOfRelay RXJyV2FybmluZ09mUmVsYXksLTE_
// 变量变化事件 "On_ErrWarningOfRelay" 针对变量 "ErrWarningOfRelay" [On Written]
void on_var_change_On_ErrWarningOfRelay(void) { try { // 变量 = ErrWarningOfRelay
int flag = 0;
app.get_system_var_int32("ErrWarningOfRelay", &flag);

if(flag > 0) {
    thread td([=]() {
       IsProtect = true;
       app.wait(2000, "");
       u8 data[8] = {0x55, 0xaa, 0x00, 0x00, 0x00, 0xaa, 0x55, 0x00};
       transmit_can_data(0, RLY_DB_ID, data, 8, false);
       app.wait(100, "");
       u8 data1[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xDF, 0x00, 0x00};
       transmit_can_data(0, RLY_DB_ID, data1, 8, false);
       IsCommonForceMode = false;
       IsProtect = false;
    });
    td.detach();
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Var_Change On_ErrWarningOfRelay

// CODE BLOCK BEGIN On_Timer HighVoltOnTimer SGlnaFZvbHRPblRpbWVy
// 定时器触发事件 "HighVoltOnTimer" for Timer HighVoltOnTimer
void on_timer_HighVoltOnTimer(void) { try { // 定时器 = HighVoltOnTimer
u8 count = 0;
if (high_volt_counter > 15)
{
     high_volt_counter = 0;
}
count = (u8)(high_volt_counter << 4);
u8 tmp[8] = { 0x00, 0x00, 0x02, 00, 00, 0x00, count, 0x00 };
high_volt_counter++;
u8 checksum = 0;
//byte[] tmp = new byte[8] { 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x00 };
u8 tmp1[8];
for (int i = 0; i < 8; i++)
{
     tmp1[i] = tmp[7 - i];
}
checksum = CRC8::crc8_chk_value(tmp1, 8);
tmp[7] = checksum;
SCANService ss(CRRU_CALIBRA_ID);
ss.Execute(tmp);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer HighVoltOnTimer

// CODE BLOCK BEGIN On_Timer HighVoltOffTimer SGlnaFZvbHRPZmZUaW1lcg__
// 定时器触发事件 "HighVoltOffTimer" for Timer HighVoltOffTimer
void on_timer_HighVoltOffTimer(void) { try { // 定时器 = HighVoltOffTimer
u8 count = 0;
if (high_volt_counter > 15)
{
     high_volt_counter = 0;
}
count = (u8)(high_volt_counter << 4);
u8 tmp[8] = { 0x00, 0x00, 0x06, 00, 00, 0x00, count, 0x00 };
high_volt_counter++;
u8 checksum = 0;
//byte[] tmp = new byte[8] { 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x00 };
u8 tmp1[8];
for (int i = 0; i < 8; i++)
{
     tmp1[i] = tmp[7 - i];
}
checksum = CRC8::crc8_chk_value(tmp1, 8);
tmp[7] = checksum;
SCANService ss(CRRU_CALIBRA_ID);
ss.Execute(tmp);

hv_timeout_counter++;

if(hv_timeout_counter > 600){
     HighVoltOffTimer.stop();
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer HighVoltOffTimer

// CODE BLOCK BEGIN On_Timer timerHardWakeupTest_Event dGltZXJIYXJkV2FrZXVwVGVzdA__
// 定时器触发事件 "timerHardWakeupTest_Event" for Timer timerHardWakeupTest
void on_timer_timerHardWakeupTest_Event(void) { try { // 定时器 = timerHardWakeupTest
TS_UI_MANAG::timerHardWakeupTest_Tick();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer timerHardWakeupTest_Event

// CODE BLOCK BEGIN On_Timer HeattingCounter SGVhdHRpbmdUaW1lcg__
// 定时器触发事件 "HeattingCounter" for Timer HeattingTimer
void on_timer_HeattingCounter(void) { try { // 定时器 = HeattingTimer
heatcounter--;
string time = second_to_str(heatcounter);
heating_timer.set(time.c_str());
if(heatcounter == 0) {
    heatcounter = heattime * 60;
    auto pos = relay_map.find(216);
    auto neg = relay_map.find(217);
    pos -> second -> close_relay();
    neg -> second -> close_relay();
    MessageBox(NULL, "加热完成，若要重新加热，请关闭后重新闭合继电器", "提示", MB_OK);
    HeattingTimer.stop();
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer HeattingCounter

// CODE BLOCK BEGIN On_Timer UpdateUITrigger R3JhcGhVcGRhdGVUaW1lcg__
// 定时器触发事件 "UpdateUITrigger" for Timer GraphUpdateTimer
void on_timer_UpdateUITrigger(void) { try { // 定时器 = GraphUpdateTimer
// for(int i = 0; i < 15; i++) {
//     for(int j = 0; j < 12; j++) {
//         int value = rand() % 100;
//         //int value = 100;
//         temp_graph -> SetTempValue(i, j, value);
//     }
// }
// //temp_graph -> SetTempValue(0, 1, 12);
// //temp_graph -> UpdateGraph();
// 
// for(int i = 0; i < 15; i++) {
//     for(int j = 0; j < 20; j++) {
//         int value = rand() % 65535;
//         //int value = 100;
//         volt_graph -> SetVolValue(i, j, value);
//     }
// }
temp_graph -> UpdateGraph();
volt_graph -> UpdateGraph();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer UpdateUITrigger

// CODE BLOCK BEGIN On_Start NewOn_Start1
// 启动事件 "NewOn_Start1"
void on_start_NewOn_Start1(void) { try { // 程序启动事件
init_pn_map();
init_realy_map();
RelayService("主正继电器", RLY_DB_ID, 0xD1, 0xC8, 22);
rcm_pv = relay_control_mode.get();


/************************************初始化项目配置*********************************************/
p = make_unique<project::CATLProject>();
p->SetProjectChangedCallback(OnProjectChanged, 0);
ProjectUpdate();
/////////////////////////////更改一些编辑框的背景颜色/////////////////////////////////////////

for(int i=-1;++i<10;) {
        std::string cname="InputOutputBox";
        cname+=std::to_string(i+13);        
        app.panel_set_bkgd_color(PANEL_DATAWR_NAME,cname.c_str(),0x10fe0000);
}
for(int i=-1;++i<10;) {
        std::string cname="InputOutputBox";
        cname+=std::to_string(i+23);        
        app.panel_set_bkgd_color(PANEL_DATAWR_NAME,cname.c_str(),0x10000ef0);
}
    //10FEEEAA
 app.panel_set_bkgd_color(PANEL_DATAWR_NAME,"checkCurrentData",0x10FEEEAA);


 for(int i=32;++i<45;) {
        std::string cname="InputOutputBox";
        cname+=std::to_string(i);        
        app.panel_set_bkgd_color(PANEL_DATAWR_NAME,cname.c_str(),0x10a01ef0);
}
//log("id:%d", v_csc_v_defs[1][2].id);

////////////////////////////////////////////////////////////////////////////////////////////
/*********************************写入继电器状态发生改变回调************************************************/
RelayStateChange.set((int) CATL::RelayStateChange);

///////////////////////////////////////////////////////////////////////////////////////////
/*********************************写入继电器状态模式发生改变回调************************************************/
RelayModeChange.set((int) CATL::RelayModeChange);
 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start NewOn_Start1

// CODE BLOCK BEGIN On_Stop NewOn_Stop1
// 停止事件 "NewOn_Stop1"
void on_stop_NewOn_Stop1(void) { try { // 程序停止事件
stop_all_timer();
//关闭程序关闭所有继电器
    for(auto ele : CATL::gRelayMap){
        CATL::RelayStateChange(ele.first.c_str(),0);
    
    }

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Stop NewOn_Stop1

// CODE BLOCK BEGIN On_Shortcut temp_test NjU_
// 按键事件 "temp_test" 快捷键 = A
void on_shortcut_temp_test(const s32 AShortcut) { try { // 按键事件 = A
temp_graph -> SetTempValue(0, 2, 101);
temp_graph -> SetTempValue(0, 3, 0);
temp_value++;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Shortcut temp_test

// CODE BLOCK BEGIN Custom_Function read_ver_info Y29uc3QgZG91YmxlIGZsYWc_
// 自定义函数 "read_ver_info"
s32 read_ver_info(const double flag) { try { // 自定义函数: 
u8 queryFlag = static_cast<u8>(flag);//将double类型转化为byte

u8 data[8] = {queryFlag, 0, 0, 0, 0, 0, 0, 0};

transmit_can_data(0, P2U_DB_ID, data, 8, false);

switch(queryFlag){
    case 201:
         txt_SofVerNo.set("");
         break;
    case 204:
         txt_HardVerNo.set("");
         break;
    case 203:
         txt_PRJInfo.set("");
         break;
    case 176:
         txt_BootVerNo.set("");
    default:
         break;
}
/*
for(int i = 0; i < 3; i++){
    char* vet_tmp_str = txt_SofVerNo.get();
    if(vet_tmp_str == NULL || vet_tmp_str == "") vet_tmp_str = "";
    txt_SofVerNo.set((string(vet_tmp_str) + to_string(i)).c_str());//显示到panel界面
}*/
return 0;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function read_ver_info

// CODE BLOCK BEGIN Custom_Function write_soc Y29uc3QgZG91YmxlIGZsYWc_
// 自定义函数 "write_soc"
s32 write_soc(const double flag) { try { // 自定义函数: 
u8 send_data;
double soc = soc_value.get();// soc值
send_data = static_cast<u8>(soc);

u8 data0 = static_cast<u8>(soc * 10 / 256);//high
u8 data1 = static_cast<u8>(soc * 10);      //low

if(soc_type.get() == 0){
    MessageBox(NULL, "请选择SOC类型", "提示", MB_OK);
    return 0;
}

if(send_data < 0 || send_data > 100){
    MessageBox(NULL, "请输入正确的SOC值[0~100%]", "提示", MB_OK);
    return 0;
}
else{
    u8 soc_flag = soc_type.get() - 0x50;//获取soc类型
    u8 data[8] = {soc_flag, data0, data1, 0, 0, 0, 0, 0};
    
    transmit_can_data(0, P2U_DB_ID, data, 8, false);
    return 1;
}     

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function write_soc

// CODE BLOCK BEGIN Custom_Function read_soc Y29uc3QgZG91YmxlIGZsYWc_
// 自定义函数 "read_soc"
s32 read_soc(const double flag) { try { // 自定义函数: 
if(soc_type.get() == 0){
    MessageBox(NULL, "请选择SOC类型", "提示", MB_OK);
    return 0;
}

u8 soc_flag = soc_type.get();//获取soc类型
u8 data[8] = {soc_flag, 0, 0, 0, 0, 0, 0, 0};
transmit_can_data(0, P2U_DB_ID, data, 8, false);
return 1;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function read_soc

// CODE BLOCK BEGIN Custom_Function write_pack_message Y29uc3QgdTMyIEFJZCwgY29uc3QgdTggd3JpdGVJZCwgdTgqIHBhY2tNZXMsIGNvbnN0IHMzMiBsZW4sIGNvbnN0IHMzMiBsaW1pdExlbmd0aA__
// 自定义函数 "write_pack_message"
s32 write_pack_message(const u32 AId, const u8 writeId, u8* packMes, const s32 len, const s32 limitLength) { try { // 自定义函数: 
u8 TotalFrame = (u8)((limitLength % 5) == 0 ? limitLength / 5 : ((limitLength / 5) + 1));
u8* senddata = new u8[TotalFrame * 5];

//s32 len = len_of_array(packMes);

//log("%d", len);

for (int i = 0; i < TotalFrame * 5; i++){
   if (i < len){
       senddata[i] = packMes[i];
   }
   else{
       senddata[i] = 0xFF;
   }
}

for(s32 i = 0; i < TotalFrame; i++){
    u8 tmp[8] = { writeId, TotalFrame, (u8)(i + 1), senddata[0 + i * 5], senddata[1 + i * 5], senddata[2 + i * 5], senddata[3 + i * 5], senddata[4 + i * 5] };
    transmit_can_data(0, AId, tmp, 8, false);
    Sleep(100);
}
delete[] senddata;
return 1;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function write_pack_message

// CODE BLOCK BEGIN Custom_Function write_general_mes Y29uc3QgZG91YmxlIEEx
// 自定义函数 "write_general_mes"
s32 write_general_mes(const double A1) { try { // 自定义函数: 
s32 flag = static_cast<s32>(A1);       //写入还是读取
s32 type = mes_type.get();             //读写类型

if(flag == 1){            //写入
    char* mesStr = mes_write.get();
    if(mesStr == NULL || mesStr == ""){
        MessageBox(NULL, "写入数据不许为空", "提示", MB_OK);
        return 0;
    }
    string mes =  trim(string(mesStr));
    //trim(mes);
    if(mes.empty()){
        MessageBox(NULL, "写入数据不许为空", "提示", MB_OK);
        return 0;
    }
    else{
        if(mesWriteMap.find(type) == mesWriteMap.end()){
             MessageBox(NULL, "该类型不支持写入", "提示", MB_OK);
             return 0;
        }
        else{
             string s(mes);
             s32 len = strlen(mes.c_str());
             u8* packData = const_cast<u8*>((const u8*)mes.data());
             //u8* packData = to_byteArray(mes);
             const u8 writeId =  mesWriteMap.find(type) -> second;
             write_pack_message(P2U_DB_ID, writeId, packData, len, 12);
             //delete[] packData;  //由于toByteArray函数返回的是new的数组，所以必须释放
             return 1;
        }
    }
}
else if(flag == 2){            //读取
     mes_read.set("");
    const u8 ReadId =  mesReadMap.find(type) -> second;
    
    if(type < 5){
        u8 data[8] = {ReadId,0x00,0x00,0x00, 0x00,0x00,0x00,0x00};
        transmit_can_data(0, P2U_DB_ID, data, 8, false);
    }
    else{
        u8 data[8] = {ReadId,0x01,0x01,0xFF,0xFF,0xFF,0xFF,0xFF};
        transmit_can_data(0, P2U_DB_ID, data, 8, false);
    }
    
    return 1;
}
return 0;





} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function write_general_mes

// CODE BLOCK BEGIN Custom_Function ForceModeMsgBox dm9pZA__
// 自定义函数 "ForceModeMsgBox"
s32 ForceModeMsgBox(void) { try { // 自定义函数: 
if(isForceMode){
     return 0;
}
else{
     MessageBox(NULL, "已进入强制模式", "提示", MB_OK);
     return 1;
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function ForceModeMsgBox

// CODE BLOCK BEGIN Custom_Function control_relay Y29uc3QgZG91YmxlIEFJZA__
// 自定义函数 "control_relay"
s32 control_relay(const double AId) { try { // 自定义函数: 
if(IsProtect) return -1;

u32 flag = static_cast<u32>(AId);

u32 id = flag / 2;
u32 is_open = flag % 2;

auto it = relay_map.find(id); //从字典中获取对应的继电器服务

if(it == relay_map.end()){
     MessageBox(NULL, "不支持当前继电器", "提示", MB_OK);
     return 0;
}

shared_ptr<RelayService> relay = it -> second;
relay -> control_relay(is_open);  //是否打开继电器
//log(relay -> Name.c_str());
if(relay -> Name == "加热正继电器" || relay -> Name == "加热负继电器") {
     
     if(is_open == 1) {
        app.make_toast("加热开始......", lvlOK);
        HeattingTimer.start();
     }
     else {
        HeattingTimer.stop();
     }
}
return 0;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function control_relay

// CODE BLOCK BEGIN Custom_Function execute_command Y29uc3QgZG91YmxlIHZhbHVl
// 自定义函数 "execute_command"
s32 execute_command(const double value) { try { // 自定义函数: 
u16 AValue = static_cast<u16>(value);

u8 control_id = (AValue & 0xFF00) >> 8;  //功能id
u8 control_value = AValue & 0xFF;        //功能值

u8 flag1 = 0x55;
u8 flag2 = 0xAA;

unique_ptr<SCANService> command;

if(AValue == 0xB101){
     flag1 = 0x00;   //byte1 
     flag2 = 0x00;   //byte2  
}

command = make_unique<SControlService>(RLY_DB_ID, flag1, flag2, control_id, control_value); //初始化scan服务对象

command -> Execute(); //执行scan服务

return 1;


} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function execute_command

// CODE BLOCK BEGIN Custom_Function HighVoltTest Y29uc3QgZG91YmxlIEEx
// 自定义函数 "HighVoltTest"
s32 HighVoltTest(const double A1) { try { // 自定义函数: 
if(A1 == 1){
    HighVoltOnTimer.start();
}
else{
    HighVoltOnTimer.stop();
    HighVoltOffTimer.start(); 
}
return 1;    

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function HighVoltTest

// CODE BLOCK BEGIN Custom_Function stop_all_timer dm9pZA__
// 自定义函数 "stop_all_timer"
s32 stop_all_timer(void) { try { // 自定义函数: 
HighVoltOnTimer.stop();
HighVoltOffTimer.stop();
return 0;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function stop_all_timer

// CODE BLOCK BEGIN Custom_Function tabpage_change Y29uc3QgZG91YmxlIHBhZ2U_
// 自定义函数 "tabpage_change"
s32 tabpage_change(const double page) { try { // 自定义函数: 
s32 page_index = static_cast<s32>(page);
log("%d", page_index);
char* page_name;
switch(page_index){
     case 1:
          page_name = "数据读写";
          break;
     case 2:
          page_name = "UDS诊断";
          break;
     case 3:
          page_name = "DTC故障检测";
          break;
     case 4:
          page_name = "报文监控";
          break;
     default:
          page_name = "数据读写";
          break;             
}
log(page_name);
app.ui_show_page_by_name(page_name);
return 1;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function tabpage_change

// CODE BLOCK BEGIN Custom_Function write_RABC Y29uc3QgZG91YmxlIEEx
// 自定义函数 "write_RABC"
s32 write_RABC(const double A1) { try { // 自定义函数: 
cusCheckSoftVer = "";

u8 pack_data[20] = {0};
//write_pack_message(CAL_DB_ID, 0x52, pack_data, 20);  //获取版本号

if(KBData.get() == NULL){
    MessageBox(NULL, "条码不能为空", "错误", MB_OK);
    return 0;
}
string kbStr = trim(string(KBData.get()));

if(kbStr.length() != 70){
    MessageBox(NULL, "条码长度错误", "错误", MB_OK);
    return 0;
}
u8 writeKBSendData[] = { 0x57, 0x52, 0x49, 0x54, 0x45, 0x52, 0x53, 0x4F };
//u8* barcodeCRC = 

return 0;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function write_RABC

// CODE BLOCK BEGIN Custom_Function set_heatting_time Y29uc3QgZG91YmxlIEFx
// 自定义函数 "set_heatting_time"
s32 set_heatting_time(const double Aq) { try { // 自定义函数: 
char password[128];
app.prompt_user_input_string("请输入密码", password, 128);
string passwordStr = string(password);
passwordStr = trim(passwordStr);
if(passwordStr != "BMS2020") {
    MessageBox(NULL, "密码错误\r\n请联系CATL BMS部门工程师获取密码\r\n邮箱:ChenCJ@catbattery.com\r\n手机:13685080159", "提示", MB_OK);
    return 1;
}

heattime = heatting_time.get();
heatcounter = heattime * 60;
app.make_toast("设置成功", lvlOK);
return 0;

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); return(IDX_ERR_MP_CODE_CRASH); }}
// CODE BLOCK END Custom_Function set_heatting_time

// CODE BLOCK BEGIN Step_Function  MTAwMA__
// 主step函数，执行周期 1000 ms
void step(void) { try { // 周期 = 1000 ms

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

