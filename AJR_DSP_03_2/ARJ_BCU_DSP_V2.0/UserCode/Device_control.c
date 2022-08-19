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
    test_inC.Input.In_Discrete.SpoilerStoredSignal_Left=Receive_Machine_Parameters.SpoilerStoredSignal_Left;
    test_inC.Input.In_Discrete.SpoilerStoredSignal_Right=Receive_Machine_Parameters.SpoilerStoredSignal_Right;
    test_inC.Input.In_Discrete.LeftWOW=Receive_Machine_Parameters.LeftWOW;
    test_inC.Input.In_Discrete.RightWOW=Receive_Machine_Parameters.RightWOW;
    test_inC.Input.In_Discrete.LeftThrottleIdle=Receive_Machine_Parameters.LeftThrottleIdle;
    test_inC.Input.In_Discrete.RightThrottleIdle=Receive_Machine_Parameters.RightThrottleIdle;
    test_inC.Input.In_Discrete.ThrottleIdleAtLeastOne=Receive_Machine_Parameters.ThrottleIdleAtLeastOne;
    test_inC.Input.In_Discrete.ThrottleIdleBoth=Receive_Machine_Parameters.ThrottleIdleBoth;
    test_inC.Input.In_Discrete.AutoBRK_OFF=Receive_Machine_Parameters.AutoBRK_OFF;
    test_inC.Input.In_Discrete.AutoBRK_LOW=Receive_Machine_Parameters.AutoBRK_LOW;
    test_inC.Input.In_Discrete.AutoBRK_MED=Receive_Machine_Parameters.AutoBRK_MED ;
    test_inC.Input.In_Discrete.AutoBRK_HI=Receive_Machine_Parameters.AutoBRK_HI;
    test_inC.Input.In_Discrete.AutoBRK_RTO=Receive_Machine_Parameters.AutoBRK_RTO ;
    test_inC.Input.In_Discrete.Inner_wheel_ABS_start_signal=Receive_Machine_Parameters.Inner_wheel_ABS_start_signal ;
    test_inC.Input.In_Discrete.Parking_brake_signal=Receive_Machine_Parameters.Parking_brake_signal ;
    test_inC.Input.In_Discrete.spare=Receive_Machine_Parameters.spare ;
    test_inC.Input.In_Discrete.PIN_PGR_1=Receive_Machine_Parameters.PIN_PGR_1 ;
    test_inC.Input.In_Discrete.PIN_PGR_2=Receive_Machine_Parameters.PIN_PGR_2 ;
    test_inC.Input.In_HcLeftWheelAngularSpeed=Receive_Machine_Parameters.LeftWheelSpeed;
    test_inC.Input.In_HcRightWheelAngularSpeed=Receive_Machine_Parameters.RightWheelSpeed;
    test_inC.Input.In_HcLeftBrakePressure=Receive_Machine_Parameters.INBD_LT_BPSI;
    test_inC.Input.In_HcRightBrakePressure=Receive_Machine_Parameters.INBD_RT_BPSI ;
    test_inC.Input.In_HcLeftBrakeTemperature=Receive_Machine_Parameters.INBD_LT_TEMP ;
    test_inC.Input.In_HcRightBrakeTemperature=Receive_Machine_Parameters.INBD_RT_TEMP ;
    test_inC.Input.In_PLT_LT_LVDT_Percent=Receive_Machine_Parameters.LeftPPedal ;
    test_inC.Input.In_PLT_RT_LVDT_Percent=Receive_Machine_Parameters.RightPPedal ;
    test_inC.Input.In_CPLT_LT_LVDT_Percent=Receive_Machine_Parameters.LeftCptPedal ;
    test_inC.Input.In_CPLT_RT_LVDT_Percent=Receive_Machine_Parameters.RightCptPedal ;
    test_inC.Input.In_Right_BCV_Current=Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current ;
    test_inC.Input.In_Left_BCV_Current=Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current ;
    test_inC.Input.In_SOV_Current=Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current ;
    test_inC.Input.In_Hydraulic_System_Pressure_60=Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60 ;
    test_inC.Input.In_Accumulator_Pressure_126=Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126 ;
    test_inC.Input.In_TLA_Position_Left_133=Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133 ;
    test_inC.Input.In_TLA_Position_Right_133=Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133 ;
    test_inC.Input.In_Master_Time_150=Receive_Machine_Parameters.RX_429_Communication.Master_Time_150 ;
    test_inC.Input.In_Computed_Air_Speed_206=Receive_Machine_Parameters.RX_429_Communication.Airspeed;
    test_inC.Input.In_Date_Master_260=Receive_Machine_Parameters.RX_429_Communication.Date_Master_260 ;
    test_inC.Input.In_MLG_RtDownlocked=Receive_Machine_Parameters.RX_429_Communication.In_MLG_RtDownlocked ;
    test_inC.Input.In_MLG_LtDownlocked=Receive_Machine_Parameters.RX_429_Communication.In_MLG_LtDownlocked ;
    test_inC.Input.In_Computed_WOW1_Data_277=Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_1_277;
    test_inC.Input.In_Computed_WOW2_Data_277=Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_2_277;
    test_inC.Input._1_In_Longitudinal_Acceleration_Body_Left_331=Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left;
    test_inC.Input.In_Longitudinal_Acceleration_Body_Right_331=Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right;
     /******以上，读FPGA*******/
    Brake(&test_inC, &test_outC);
    /******以下，写FPGA*******/
   Transmit_Machine_Parameters.SOV_Open=test_outC.Output.SOV_Open;
   Transmit_Machine_Parameters.BrakePressureCommand_L=test_outC.Output.BrakePressureCommand_L;
   Transmit_Machine_Parameters.BrakePressureCommand_R=test_outC.Output.BrakePressureCommand_R;
   Transmit_Machine_Parameters.CoilEnergized=test_outC.Output.BrakeAutoBKOut.CoilEnergized;
   Transmit_Machine_Parameters.LeftPDL_BrakePressureCommand=test_outC.Output.BrakePdlOut.LeftPDL_BrakePressureCommand;
   Transmit_Machine_Parameters.RightPDL_BrakePressureCommand=test_outC.Output.BrakePdlOut.RightPDL_BrakePressureCommand;/*脚蹬的指令*/
   Transmit_Machine_Parameters.LeftBrakePressureCommand=test_outC.Output.BrakeSelectOut.LeftBrakePressureCommand;/*BrakeSelectOut-- 选择后的指令*/
   Transmit_Machine_Parameters.RightBrakePressureCommand=test_outC.Output.BrakeSelectOut.RightBrakePressureCommand;/*BrakeSelectOut-- 选择后的指令*/
   Transmit_Machine_Parameters.LeftIFB_BrakePressureCommand=test_outC.Output.BrakeIfbOut.LeftIFB_BrakePressureCommand;/*止转指令*/
   Transmit_Machine_Parameters.RightIFB_BrakePressureCommand=test_outC.Output.BrakeIfbOut.RightIFB_BrakePressureCommand;/*止转指令*/
   Transmit_Machine_Parameters.Left_BrakePressureCommand=test_outC.Output.BrakeAutoBKOut.Left_BrakePressureCommand;/*自动刹车指令*/
   Transmit_Machine_Parameters.Right_BrakePressureCommand=test_outC.Output.BrakeAutoBKOut.Right_BrakePressureCommand;/*自动刹车指令*/
   Transmit_Machine_Parameters.LandingArmedState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.LandingArmedState;/*自动刹车状态*/
   Transmit_Machine_Parameters.LandingApplicationState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.LandingApplicationState;/*自动刹车状态*/
   Transmit_Machine_Parameters.LandingEnabledState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.LandingEnabledState;/*自动刹车状态*/
   Transmit_Machine_Parameters.LandingDisArmedState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.LandingDisArmedState;/*自动刹车状态*/
   Transmit_Machine_Parameters.RTOArmedState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.RTOArmedState;/*自动刹车状态*/
   Transmit_Machine_Parameters.RTOEnabledState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.RTOEnabledState;/*自动刹车状态*/
   Transmit_Machine_Parameters.RTODisarmedState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.RTODisarmedState;/*自动刹车状态*/
   Transmit_Machine_Parameters.RTOApplicationState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.RTOApplicationState;/*自动刹车状态*/
   Transmit_Machine_Parameters.OFFState=test_outC.Output.BrakeAutoBKOut.AutoBrakeState.OFFState;/*自动刹车状态*/
   Transmit_Machine_Parameters.AUTOBRKfault=test_outC.Output.BrakeAutoBKOut.testData.AUTOBRKfault;/*自动刹车中间信号*/
   Transmit_Machine_Parameters.ARMdisagree=test_outC.Output.BrakeAutoBKOut.testData.ARMdisagree;/*自动刹车中间信号*/
   Transmit_Machine_Parameters.latch=test_outC.Output.BrakeAutoBKOut.testData.latch;/*自动刹车中间信号*/
   Transmit_Machine_Parameters.unlatch=test_outC.Output.BrakeAutoBKOut.testData.unlatch;/*自动刹车中间信号*/
   Transmit_Machine_Parameters.maxpedal=test_outC.Output.BrakeAutoBKOut.testData.maxpedal;/*自动刹车中间信号*/
   Transmit_Machine_Parameters.WOWBK=test_outC.Output.WOWBK;/*刹车系统WOW判断的信号*/
   Transmit_Machine_Parameters.WOW429=test_outC.Output.WOW429;/*刹车系统WOW判断的信号*/
   Transmit_Machine_Parameters.TDP_BrakeInhibit=test_outC.Output.BrakeInhibitOut.BrakeInhibits.TDP_BrakeInhibit;/*刹车系统抑制信号*/
   Transmit_Machine_Parameters.LWP_LeftBrakeInhibit=test_outC.Output.BrakeInhibitOut.BrakeInhibits.LWP_LeftBrakeInhibit;/*刹车系统抑制信号*/
   Transmit_Machine_Parameters.LWP_RightBrakeInhibit=test_outC.Output.BrakeInhibitOut.BrakeInhibits.LWP_RightBrakeInhibit;/*刹车系统抑制信号*/
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
    Transmit_Machine_Parameters.TX_429_Communication.Status_Word_1__271=Transmit_Machine_Parameters.LandingArmedState | (Transmit_Machine_Parameters.LandingApplicationState)<<1 | (Transmit_Machine_Parameters.LandingEnabledState)<<2 | \
             (Transmit_Machine_Parameters.LandingDisArmedState)<<3 | (Transmit_Machine_Parameters.RTOArmedState)<<4 | (Transmit_Machine_Parameters.RTOEnabledState)<<5 | (Transmit_Machine_Parameters.RTODisarmedState)<<6 | \
             (Transmit_Machine_Parameters.RTOApplicationState)<<7 | (Transmit_Machine_Parameters.OFFState)<<8;
    Transmit_Machine_Parameters.TX_429_Communication.Status_Word_2_272=0;
    Transmit_Machine_Parameters.TX_429_Communication.BCU_Aircraft_Reference_Speed_302=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_350=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_351=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_352=0;
    Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_353=0;
}
