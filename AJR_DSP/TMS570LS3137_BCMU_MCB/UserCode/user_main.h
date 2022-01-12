/*
  ******************************************************************************
  * @file    user_Main.h
  * @author  JYS
  * @version V1.0.0
  * @date    2019-11-20
  * @brief   Init
  */

#ifndef __USER_MAIN_H
#define __USER_MAIN_H

#include <rs232.h>
#include "rti.h"
#include "sys_core.h"
#include "global_Init.h"
#include "reg_rti.h"
#include "reg_can.h"
#include "reg_mibspi.h"
#include "reg_spi.h"
#include "mibspi.h"
#include "Brake.h"
#include "init.h"
#include "Device_control.h"
#define MASTER 1
#define SLAVE 0
#define Master_Slave  MASTER
typedef  struct _429_DATA_RX
{
    float    Hydraulic_System_Pressure_1_60;    /*��Դѹ��1*/
    float    Accumulator_System_Pressure_1_126; /*��ѹ��ѹ��1*/
    float    TLA_Position_Left_133;             /*�����Ÿ�λ��*/
    float    TLA_Position_Right_133;            /*�����Ÿ�λ��*/
    unsigned int    Master_Time_150;                   /*����ʱ��*/
    unsigned int    Date_Master_260;                   /*��������*/
    unsigned int    Computed_WOW_Data_1_277;           /*������������1*/
    unsigned int    Computed_WOW_Data_2_277;           /*������������2*/
    tValidityF32 Airspeed;                      /*Computed_Air_Speed_206--�������*/
    tValidityF32 AircraftAcceleration_Left;     /*Longitudinal_Acceleration_Body_Left_331--�������������ٶ�*/
    tValidityF32 AircraftAcceleration1_Right;   /*Longitudinal_Acceleration_Body_Right_331--�����Ҳ�������ٶ�*/
    kcg_bool LG_GearDown_Locked;                /*Gear_Position_1_272��Bit13��--�����λ��1*/

}RX_429_DATA;
typedef  struct _429_DATA_TX
{
    float    Left_Inboard_Wheel_Speed_006;                  /*--��������*/
    float    Right_Inboard_Wheel_Speed_007;                 /*--��������*/
    float    Right_Inboard_Brake_Control_Valve_Current_052; /*--����ɲ�����Ʒ�����*//*�ز�*/
    float    Left_Inboard_Brake_Control_Valve_Current_051;  /*--����ɲ�����Ʒ����� *//*�ز�*/
    float    Left_Inboard_Brake_Pressure_070;               /*����ɲ��ѹ�� */
    float    Right_Inboard_Brake_Pressure_071;              /*����ɲ��ѹ�� */
    float    Inboard_Shutoff_Valve_Current_113;              /*�жϷ�������� *//*�ز�*/
    float    Left_Inboard_Brake_Temperature_114;            /*����ɲ���¶� */
    float    Right_Inboard_Brake_Temperature_116;           /*����ɲ���¶� */
    float    Left_Brake_Pedal_Position_Pilot_171;           /*������ŵ�*/
    float    Right_Brake_Pedal_Position_Pilot_172;          /*�����ҽŵ�*/
    float    Left_Brake_Pedal_Position_Copilot_173;         /*������ŵ�*/
    float    Right_Brake_Pedal_Position_Copilot_174;        /*�����ҽŵ�*/
    unsigned int    Warning_270;                                   /*����*/
    unsigned int    Status_Word_1__271;                            /*״̬����#1*/
    unsigned int    Status_Word_2_272;                             /*״̬����#2*/
    float    BCU_Aircraft_Reference_Speed_302;              /*BCU�ɻ��ο��ٶ�*/
    unsigned int    Failure_Word_1_350;                            /*��������#1*/
    unsigned int    Failure_Word_1_351;                            /*��������#2*/
    unsigned int    Failure_Word_1_352;                            /*��������#3*/
    unsigned int    Failure_Word_1_353;                            /*��������#4*/
}TX_429_DATA;
typedef  struct RX_FPGA_DATA
{
        float    Right_Inboard_Brake_Control_Valve_Current; /*--����ɲ�����Ʒ�����*//*�ز�*/
        float    Left_Inboard_Brake_Control_Valve_Current;  /*--����ɲ�����Ʒ����� *//*�ز�*/
        float    Inboard_Shutoff_Valve_Current;             /*�жϷ�������� *//*�ز�*/
        float    INBD_RT_BPSI;                              /*������ɲ��ѹ�� */
        float    INBD_LT_BPSI;                              /*������ɲ��ѹ�� */
        float    INBD_RT_TEMP;                              /*�������¶� */
        float    INBD_LT_TEMP;                              /*�������¶� */
        tValidityF32 LeftCptPedal;                          /*CH1_CPLT_LT_LVDT_Percent--������ŵ��ź�*/
        tValidityF32 RightCptPedal;                         /*CH1_CPLT_LT_LVDT_Percent--�����ҽŵ��ź�*/
        tValidityF32 LeftPPedal;                            /*CH1_PLT_LT_LVDT_Percent--������ŵ��ź�*/
        tValidityF32 RightPPedal;                           /*CH1_PLT_LT_LVDT_Percent--�����ҽŵ��ź�*/
        kcg_float32 MaxPedal;                               /*��*/
        bool Inner_wheel_ABS_start_signal   ;               /* ����ABS�����ź�*/ /*�ز�*/
        bool Parking_brake_signal   ;                       /*ͣ��ɲ���ź� */
        kcg_bool SpoilerStoredSignal_Left;                  /*INBD_IO_1��A22��--�������ź�*/
        kcg_bool SpoilerStoredSignal_Right;                 /*INBD_IO_1��A22��--�������ź�*/
        kcg_bool LeftWOW;                                   /*INBD_IO_1��A8��--�����ź�*/
        kcg_bool RightWOW;                                  /*INBD_IO_1��A8��--�����ź�*/
        tValidityBool zong;                                 /*INBD_IO_1��A8��--�����ź�*/
        kcg_bool NLGWOW;                                    /*��*/
        kcg_bool LeftThrottleIdle;                          /*INBD_IO_1��A20��--�����ź�*/
        kcg_bool RightThrottleIdle;                         /*INBD_IO_1��A20��--�����ź�*/
        kcg_bool ThrottleIdleAtLeastOne;                    /*INBD_IO_1��A20��--�����ź�*/
        kcg_bool ThrottleIdleBoth;                          /*INBD_IO_1��A20��--�����ź�*/
        kcg_bool LandingGearExtentionandRetractionCommand;  /*INBD_IO_1��A31��--�ֱ��ź�*/
        tValidityBool AutoBRK_OFF;                          /*INBD_ABS_SW(A16)--�Զ�ɲ�����ص�OFF��*/
        tValidityBool AutoBRK_LOW;                          /*INBD_ABS_SW(A17)--�Զ�ɲ�����ص�LOW��*/
        tValidityBool AutoBRK_MED;                          /*INBD_ABS_SW(A7)--�Զ�ɲ�����ص�MED��*/
        tValidityBool AutoBRK_HI;                           /*INBD_ABS_SW(A6)--�Զ�ɲ�����ص�HI��*/
        tValidityBool AutoBRK_RTO;                          /*INBD_ABS_SW(A15)--�Զ�ɲ�����ص�RTO��*/
        tValidityF32 LeftWheelSpeed;                        /*INBD_LT_WST--��������*/
        tValidityF32 RightWheelSpeed;                       /*INBD_RT_WST--��������*/
        kcg_float32 WheelSpeed_av;                          /*(INBD_LT_WST+INBD_RT_WST��/2*/
        bool spare ;                                        /*�����ź� */
        bool PIN_PGR_1  ;                                   /*PIN PGR 1 */
        bool PIN_PGR_2  ;                                   /*PIN PGR 2 */
        bool Work_mode  ;                                   /*ģʽ�ź� */
        bool Master_Salve  ;                                /*FPGA���ӻ�ģʽ */

        RX_429_DATA RX_429_Communication;
} RX_FPGA_DATA;
typedef  struct TX_FPGA_DATA
{
        kcg_bool SOV_Open;                      /*INBD_SOV--�����жϷ��ź� */
        kcg_float32 BrakePressureCommand_L;     /*INBD_LT_BCV--����ɲ�����Ʒ� */
        kcg_float32 BrakePressureCommand_R;     /*INBD_RT_BCV-- ����ɲ�����Ʒ�*/
        kcg_bool CoilEnergized;                 /*INBD_ABS_ARMED_EXC-- �Զ�ɲ�����ؼ���*/
        bool ARM_SIG;                           /*ARM_SIG */
        bool INBD_LT_SPINUP;                    /*������ת�ź� */
        bool INBD_RT_SPINUP;                    /* ������ת�ź�*/
        float TEST_DAC_BCV_LT;                  /*�����ź�����ɲ�����Ʒ� */
        float TEST_DAC_BCV_RT;                  /*�����ź�����ɲ�����Ʒ� */
        float TEST_DAC_CV_LT;                   /*�����ź�CV�� */
        float TEST_DAC_CV_RT;                   /*�����ź�CV�� */
        float TEST_DAC_WHELL_SPEED_LT;          /*�����ź��������� LT */
        float TEST_DAC_WHELL_SPEED_RT;          /*�����ź��������� RT */
        float TEST_DAC_SOV;                     /*�����ź�SOV */
        float TEST_DAC_PLT_LT;                  /*BRK PDL CH1 PLT LT  �ŵ��ź� */
        float TEST_DAC_PLT_RT;                  /*BRK PDL CH1 PLT RT  �ŵ��ź� */
        float TEST_DAC_CPLT_LT;                 /*BRK PDL CH1 CPLT LT  �ŵ��ź� */
        float TEST_DAC_CPLT_RT;                 /*BRK PDL CH1 CPLT RT  �ŵ��ź� */
        TX_429_DATA TX_429_Communication;
} TX_FPGA_DATA;

extern RX_FPGA_DATA Receive_Machine_Parameters; /*��FPGA���յ��豸״̬����*/
extern TX_FPGA_DATA Transmit_Machine_Parameters;  /*����FPGA�����豸״̬�Ĳ���*/
extern void user_main(void);
void SD_GPIO_Init(void);
extern uint8_t SDRAM_RxTx;
#endif /* __USER_MAIN_H */