/*
 * Device_control.c
 *
 *  Created on: 2022��1��11��
 *      Author: 15755
 */
#include "global_Init.h"
#include "reg_can.h"
#include "sdram.h"

inC_Brake test_inC;
outC_Brake test_outC;
RX_FPGA_DATA Receive_Machine_Parameters; /*��FPGA���յ��豸״̬����*/
TX_FPGA_DATA Transmit_Machine_Parameters;  /*����FPGA�����豸״̬�Ĳ���*/
/***************************
 * void set_SOV(uint8_t statue)
 * ����SOV�ź�
 * statue���źŸߵ�״̬
 * **************************/
void set_SOV(uint8_t statue)
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
 * void set_SOL(uint8_t statue)
 * ����ABSW�ź�
 * statue���źŸߵ�״̬
 * **************************/
void set_SOL(uint8_t statue)
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
 * ��ʱ����FPGA�����ݣ����ݵ�ɲ��ģ�ͣ���ɲ��ģ�Ͷ�ȡ���صĿ�����Ϣ���������ݵ�FPGA
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
    test_inC.APPData.LGData.LG_GearDown_Locked=Receive_Machine_Parameters.RX_429_Communication.LG_GearDown_Locked;
    test_inC.APPData.LGData.LandingGearExtentionandRetractionCommand=Receive_Machine_Parameters.LandingGearExtentionandRetractionCommand;
    test_inC.APPData.AutoBrakeData.AutoBRK_OFF=Receive_Machine_Parameters.AutoBRK_OFF ;
    test_inC.APPData.AutoBrakeData.AutoBRK_LOW=Receive_Machine_Parameters.AutoBRK_LOW ;
    test_inC.APPData.AutoBrakeData.AutoBRK_MED=Receive_Machine_Parameters.AutoBRK_MED ;
    test_inC.APPData.AutoBrakeData.AutoBRK_HI=Receive_Machine_Parameters.AutoBRK_HI ;
    test_inC.APPData.AutoBrakeData.AutoBRK_RTO=Receive_Machine_Parameters.AutoBRK_RTO ;
    test_inC.APPData.WheelSpeedData.LeftWheelSpeed=Receive_Machine_Parameters.LeftWheelSpeed ;
    test_inC.APPData.WheelSpeedData.RightWheelSpeed=Receive_Machine_Parameters.RightWheelSpeed ;
    test_inC.APPData.WheelSpeedData.WheelSpeed_av=Receive_Machine_Parameters.WheelSpeed_av ;
    /******���ϣ���FPGA*******/
    Brake(&test_inC, &test_outC);
    /******���£�дFPGA*******/
    Transmit_Machine_Parameters.SOV_Open=test_outC.Output.SOV_Open;
    Transmit_Machine_Parameters.BrakePressureCommand_L=test_outC.Output.BrakePressureCommand_L;
    Transmit_Machine_Parameters.BrakePressureCommand_R=test_outC.Output.BrakePressureCommand_R;
    Transmit_Machine_Parameters.CoilEnergized=test_outC.Output.BrakeAutoBKOut.CoilEnergized;
    SDRAM_Write();
}

/**************************
 * void RS232_Process(uint8_t *frame_data)
 * RS232 �������ݴ���
 * frame_data������
 * ****************************/
void RS232_Process(uint8_t *frame_data)
{

}

/**************************
 * void SD_Process(uint8_t *frame_data)
 * RS232 �������ݴ���
 * frame_data������
 * ****************************/
void SD_Process(uint8_t *frame_data)
{

}