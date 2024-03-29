/*
 * Device_control.c
 *
 *  Created on: 2022年1月11日
 *      Author: 15755
 */
#include "user_main.h"


inC_Brake test_inC;
outC_Brake test_outC;
RX_FPGA_DATA Receive_Machine_Parameters; /*从FPGA接收的设备状态参数*/
TX_FPGA_DATA Transmit_Machine_Parameters;  /*发往FPGA控制设备状态的参数*/
Device_status_d device_status;
/***************************
 * void set_SOV(uint8_t statue)
 * 设置SOV信号
 * statue：信号高低状态
 * **************************/
void Set_SOV(uint8_t statue)
{
   if(statue==0)
    {
       canREG1->TIOC &=(~0x00000002);
    }
    else
    {
       canREG1->TIOC |=0x00000002;
    }
}

/***************************
 * void set_ABSW(uint8_t statue)
 * 设置ABSW信号
 * statue：信号高低状态
 * **************************/
void Set_ABSW(uint8_t statue)
{
   if(statue==0)
    {
       canREG3->TIOC &=(~0x00000002);
    }
    else
    {
       canREG3->TIOC |=0x00000002;
    }
}

/***************************
 * void Data_interaction(void)
 * 定时接收FPGA的数据，传递到刹车模型，从刹车模型读取返回的控制信息，发送数据到FPGA
 *
 * **************************/
void Data_interaction(void)
{
    SDRAM_Read();
    test_inC.APPData.Aircraft_Data.Airspeed=Receive_Machine_Parameters.RX_429_Communication.Airspeed;
    test_inC.APPData.Aircraft_Data.AircraftAcceleration_Left=Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left;
    test_inC.APPData.Aircraft_Data.AircraftAcceleration1_Right=Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right;
    test_inC.APPData.Aircraft_Data.SpoilerStoredSignal_Left=Receive_Machine_Parameters.SpoilerStoredSignal_Left;
    test_inC.APPData.Aircraft_Data.SpoilerStoredSignal_Right=Receive_Machine_Parameters.SpoilerStoredSignal_Right;
    test_inC.APPData.WOWData.LeftWOW=Receive_Machine_Parameters.LeftWOW;
    test_inC.APPData.WOWData.RightWOW=Receive_Machine_Parameters.RightWOW;
    test_inC.APPData.WOWData.zong=Receive_Machine_Parameters.zong;
    test_inC.APPData.WOWData.NLGWOW=Receive_Machine_Parameters.NLGWOW;
    test_inC.APPData.PedalData.LeftCptPedal= Receive_Machine_Parameters.LeftCptPedal;
    test_inC.APPData.PedalData.RightCptPedal=Receive_Machine_Parameters.RightCptPedal ;
    test_inC.APPData.PedalData.LeftPPedal=Receive_Machine_Parameters.LeftPPedal ;
    test_inC.APPData.PedalData.RightPPedal=Receive_Machine_Parameters.RightPPedal ;
    test_inC.APPData.PedalData.MaxPedal=Receive_Machine_Parameters.MaxPedal ;
    test_inC.APPData.ThrottleData.LeftThrottleIdle=Receive_Machine_Parameters.LeftThrottleIdle ;
    test_inC.APPData.ThrottleData.RightThrottleIdle=Receive_Machine_Parameters.RightThrottleIdle ;
    test_inC.APPData.ThrottleData.ThrottleIdleAtLeastOne=Receive_Machine_Parameters.ThrottleIdleAtLeastOne ;
    test_inC.APPData.ThrottleData.ThrottleIdleBoth=Receive_Machine_Parameters.ThrottleIdleBoth ;
    test_inC.APPData.LGData.LG_GearDown_Locked=Receive_Machine_Parameters.RX_429_Communication.In_MLG_LtDownlocked  | Receive_Machine_Parameters.RX_429_Communication.In_MLG_RtDownlocked ;
    test_inC.APPData.LGData.LandingGearExtentionandRetractionCommand=Receive_Machine_Parameters.LandingGearExtentionandRetractionCommand;
    test_inC.APPData.AutoBrakeData.AutoBRK_OFF=Receive_Machine_Parameters.AutoBRK_OFF ;
    test_inC.APPData.AutoBrakeData.AutoBRK_LOW=Receive_Machine_Parameters.AutoBRK_LOW ;
    test_inC.APPData.AutoBrakeData.AutoBRK_MED=Receive_Machine_Parameters.AutoBRK_MED ;
    test_inC.APPData.AutoBrakeData.AutoBRK_HI=Receive_Machine_Parameters.AutoBRK_HI ;
    test_inC.APPData.AutoBrakeData.AutoBRK_RTO=Receive_Machine_Parameters.AutoBRK_RTO ;
    test_inC.APPData.WheelSpeedData.LeftWheelSpeed=Receive_Machine_Parameters.LeftWheelSpeed ;
    test_inC.APPData.WheelSpeedData.RightWheelSpeed=Receive_Machine_Parameters.RightWheelSpeed ;
    test_inC.APPData.WheelSpeedData.WheelSpeed_av=Receive_Machine_Parameters.WheelSpeed_av ;
    /******以上，读FPGA*******/
    Brake(&test_inC, &test_outC);
    /******以下，写FPGA*******/
    Transmit_Machine_Parameters.SOV_Open=test_outC.Output.SOV_Open;
    Transmit_Machine_Parameters.BrakePressureCommand_L=test_outC.Output.BrakePressureCommand_L;
    Transmit_Machine_Parameters.BrakePressureCommand_R=test_outC.Output.BrakePressureCommand_R;
    Transmit_Machine_Parameters.CoilEnergized=test_outC.Output.BrakeAutoBKOut.CoilEnergized;
    Transmit_Data_Process();
    SDRAM_Write();
}

/***************************
 * void Signal_Output_Control(void)
 *DSP对输出信号进行控制
 * **************************/
void Signal_Output_Control(void)
{
    if(Transmit_Machine_Parameters.SOV_Open!=device_status.SOV_Status)
    {
        device_status.SOV_Status=Transmit_Machine_Parameters.SOV_Open;
        Set_SOV(device_status.SOV_Status);
    }
    if(Transmit_Machine_Parameters.CoilEnergized!=device_status.ABSW_Status)
    {
        device_status.ABSW_Status=Transmit_Machine_Parameters.CoilEnergized;
        Set_ABSW(device_status.ABSW_Status);
    }
    if(Transmit_Machine_Parameters.BrakePressureCommand_L!=device_status.BrakePressureCommand_L)
    {
        device_status.BrakePressureCommand_L=Transmit_Machine_Parameters.BrakePressureCommand_L;
        DAC5689_SetVoltage_mv(DAC_L,device_status.BrakePressureCommand_L);
    }
    if(Transmit_Machine_Parameters.BrakePressureCommand_R!=device_status.BrakePressureCommand_R)
    {
        device_status.BrakePressureCommand_R=Transmit_Machine_Parameters.BrakePressureCommand_R;
        DAC5689_SetVoltage_mv(DAC_R,device_status.BrakePressureCommand_R);
    }
}

/***************************
 * void Transmit_Data_Process(void)
 * 对传输的数据进行赋值
 * **************************/
void Transmit_Data_Process(void)
{
    Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Wheel_Speed_006=Receive_Machine_Parameters.LeftWheelSpeed.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Wheel_Speed_007=Receive_Machine_Parameters.RightWheelSpeed.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Control_Valve_Current_052=Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current;
    Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Control_Valve_Current_051=Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current;
    Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Pressure_070=Receive_Machine_Parameters.INBD_LT_TEMP;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Pressure_071=Receive_Machine_Parameters.INBD_RT_BPSI;
    Transmit_Machine_Parameters.TX_429_Communication.Inboard_Shutoff_Valve_Current_113=Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current;
    Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Temperature_114=Receive_Machine_Parameters.INBD_LT_TEMP;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Temperature_116=Receive_Machine_Parameters.INBD_RT_TEMP;
    Transmit_Machine_Parameters.TX_429_Communication.Left_Brake_Pedal_Position_Pilot_171=Receive_Machine_Parameters.LeftPPedal.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Brake_Pedal_Position_Pilot_172=Receive_Machine_Parameters.RightPPedal.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Left_Brake_Pedal_Position_Copilot_173=Receive_Machine_Parameters.LeftCptPedal.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Right_Brake_Pedal_Position_Copilot_174=Receive_Machine_Parameters.RightCptPedal.Value;
    Transmit_Machine_Parameters.TX_429_Communication.Warning_270=0;
    Transmit_Machine_Parameters.TX_429_Communication.Status_Word_1__271=0;
    Transmit_Machine_Parameters.TX_429_Communication.Status_Word_2_272=0;
    Transmit_Machine_Parameters.TX_429_Communication.BCU_Aircraft_Reference_Speed_302=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_350=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_351=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_352=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_353=0;
}
