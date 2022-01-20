/*
 * sdram.h
 *
 *  Created on: 2020��9��12��
 *      Author: liaot
 */

#ifndef USERCODE_SDRAM_H_
#define USERCODE_SDRAM_H_
#include <delay.h>
/*�忨ID--Board_ID
 * ����==Inboard ==A==0x001
 * �Ӱ�==Outboard==B==0x002
 *
 * */
/*429 read ADDR*/
#define       ADDR_HYDRAULIC_SYSTEM_PRESSURE        (0x400 | (0x030) | (Board_ID <<8))                /*��Դѹ��1_60*/
#define       ADDR_ACCUMULATOR_SYSTEM_PRESSURE      (0x400 | (0x056) | (Board_ID<<8))                 /*��ѹ��ѹ��1_126*/
#define       ADDR_TLA_POSITION_LEFT                (0x400 | (0x05B) | ((Board_ID&0x001)<<8) | 0x200) /*�����Ÿ�λ��_133*/
#define       ADDR_TLA_POSITION_RIGHT               (0x400 | (0x05B) | ((Board_ID&0x001)<<8) | 0x000) /*�����Ÿ�λ��_133*/
#define       ADDR_MASTER_TIME                      (0x400 | (0x068) | (Board_ID<<8))                 /*����ʱ��_150*/
#define       ADDR_AIRSPEED                         (0x400 | (0x086) | (Board_ID<<8))                 /*Computed_Air_Speed_206--�������*/
#define       ADDR_DATE_MASTER                      (0x400 | (0x0B0) | (Board_ID<<8))                 /*��������_260*/
#define       ADDR_LG_GEARDOWN_LOCKED               (0x400 | (0x0BA) | (Board_ID<<8))                 /*Gear_Position_1_272��Bit13��--�����λ��1*/
#define       ADDR_COMPUTED_WOW_DATA1               (0x400 | (0x0BF) | (0x001<<8))                    /*������������1_277*/
#define       ADDR_COMPUTED_WOW_DATA2               (0x400 | (0x0BF) | (0x002<<8))                    /*������������2_277*/
#define       ADDR_AIRCRAFTACCELERATION_LEFT        (0x400 | (0x0D9) | (0x001<<8))                    /*Longitudinal_Acceleration_Body_Left_331--�������������ٶ�*/
#define       ADDR_AIRCRAFTACCELERATION_RIGHT       (0x400 | (0x0D9) | (0x002<<8))                    /*Longitudinal_Acceleration_Body_Right_331--�����Ҳ�������ٶ�*/
/*429 write ADDR*/
#define       ADDR_LEFT_WHEEL_SPEED                 (0x400 | (0x006) | (Board_ID<<8))                 /*--��������_006*/
#define       ADDR_RIGHT_WHEEL_SPEED                (0x400 | (0x007) | (Board_ID<<8))                 /*--��������_007*/
#define       ADDR_LEFT_BRAKE_CONTROL_VALVE_CURENT  (0x400 | (0x029) | (Board_ID<<8))                 /*--����ɲ�����Ʒ����� _051*//*�ز�*/
#define       ADDR_RIGHT_BRAKE_CONTROL_VALVE_CURENT (0x400 | (0x02A) | (Board_ID<<8))                 /*--����ɲ�����Ʒ�����_052*//*�ز�*/
#define       ADDR_LEFT_BRAKE_PRESSURE              (0x400 | (0x038) | (Board_ID<<8))                 /*����ɲ��ѹ��_070 */
#define       ADDR_RIGHT_BRAKE_PRESSURE             (0x400 | (0x039) | (Board_ID<<8))                 /*����ɲ��ѹ��_071 */
#define       ADDR_SHUTOFF_VALVE_CURRENT            (0x400 | (0x04B) | (Board_ID<<8))                 /*�жϷ��������_113 *//*�ز�*/
#define       ADDR_LEFT_BRAKE_TEMPERATURE           (0x400 | (0x04C) | (Board_ID<<8))                 /*����ɲ���¶�_114 */
#define       ADDR_RIGHT_BRAKE_TEMPERATURE          (0x400 | (0x04E) | (Board_ID<<8))                 /*����ɲ���¶�_116 */
#define       ADDR_LEFT_BRAKE_PEDAL_POSITION_PILOT    (0x400 | (0x079) | (Board_ID<<8))               /*������ŵ�_171*/
#define       ADDR_RIGHT_BRAKE_PEDAL_POSITION_PILOT   (0x400 | (0x07A) | (Board_ID<<8))               /*�����ҽŵ�_172*/
#define       ADDR_LEFT_BRAKE_PEDAL_POSITION_COPILOT  (0x400 | (0x07B) | (Board_ID<<8))               /*������ŵ�_173*/
#define       ADDR_RIGHT_BRAKE_PEDAL_POSITION_COPILOT (0x400 | (0x07C) | (Board_ID<<8))               /*�����ҽŵ�_174*/
#define       ADDR_WARNING                            (0x400 | (0x0B8) | (Board_ID<<8))               /*����_270*/
#define       ADDR_STATUS_1                           (0x400 | (0x0B9) | (Board_ID<<8))               /*״̬����#1_271*/
#define       ADDR_STATUS_2                           (0x400 | (0x0BA) | (Board_ID<<8))               /*״̬����#2_272*/
#define       ADDR_BCU_AIRCRAFT_REFERENCE_SPEED       (0x400 | (0x0C2) | (Board_ID<<8))               /*BCU�ɻ��ο��ٶ�_302*/
#define       ADDR_FAILURE_WORD_1                     (0x400 | (0x0E8) | (Board_ID<<8))               /*��������#1_350*/
#define       ADDR_FAILURE_WORD_2                     (0x400 | (0x0E9) | (Board_ID<<8))               /*��������#2_351*/
#define       ADDR_FAILURE_WORD_3                     (0x400 | (0x0EA) | (Board_ID<<8))               /*��������#3_352*/
#define       ADDR_FAILURE_WORD_4                     (0x400 | (0x0EB) | (Board_ID<<8))               /*��������#4_353*/
/*FPGA���忨�ɼ��ź�*/
#define       ADDR_INBD_LT_TEMP                                 0x001  /*�������¶� */
#define       ADDR_INBD_RT_TEMP                                 0x002  /*�������¶� */
#define       ADDR_INBD_LT_BPSI                                 0x003  /*������ɲ��ѹ�� */
#define       ADDR_INBD_RT_BPSI                                 0x004  /*������ɲ��ѹ�� */
#define       ADDR_LEFTPPEDAL                                   0x005  /*CH1_PLT_LT_LVDT_Percent--������ŵ��ź� */
#define       ADDR_RIGHTPPEDAL                                  0x006  /*CH1_PLT_RT_LVDT_Percent--�����ҽŵ��ź� */
#define       ADDR_LEFTCPEDAL                                   0x007  /*CH1_CPLT_LT_LVDT_Percent--������ŵ��ź� */
#define       ADDR_RIGHTCPEDAL                                  0x008  /*CH1_CPLT_RT_LVDT_Percent--�����ҽŵ��ź� */
#define       ADDR_INNER_WHEEL_ABS_START_SIGNAL                 0x009  /* ����ABS�����ź�*/ /*�ز�*/
#define       ADDR_INBOARD_SHUTOFF_VALVE_CURRENT                0x00A  /*�жϷ�������� *//*�ز�*/
#define       ADDR_LEFT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT     0x00B  /*--����ɲ�����Ʒ�����*//*�ز�*/
#define       ADDR_RIGHT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT    0x00C  /*--����ɲ�����Ʒ����� *//*�ز�*/
#define       ADDR_LEFTWHEELSPEED                               0x011  /*INBD_LT_WST--��������*/
#define       ADDR_RIGHTWHEELSPEED                              0x012  /*INBD_RT_WST--��������*/
#define       ADDR_AUTO_BRAKE_SW_SIGNAL                         0x013  /*�Զ�ɲ���������ź�*/
#define       ADDR_OTHER_SW_SIGNAL                              0x014  /*�����������ź�*/
/*FPGA���忨����ź�*/
#define       ADDR_TEST_DAC_BCV_LT                          0x021  /*�����ź�����ɲ�����Ʒ� */
#define       ADDR_TEST_DAC_BCV_RT                          0x022  /*�����ź�����ɲ�����Ʒ� */
#define       ADDR_TEST_DAC_CV_LT                           0x023  /*�����ź�CV�� */
#define       ADDR_TEST_DAC_CV_RT                           0x024  /*�����ź�CV�� */
#define       ADDR_TEST_DAC_WHELL_SPEED_LT                  0x025  /*�����ź��������� LT */
#define       ADDR_TEST_DAC_WHELL_SPEED_RT                  0x026  /*�����ź��������� RT */
#define       ADDR_TEST_DAC_SOV                             0x027  /*�����ź�SOV */
#define       ADDR_TEST_DAC_PLT_LT                          0x028  /*����ʻ��ŵ��ź� */
#define       ADDR_TEST_DAC_PLT_RT                          0x029  /*����ʻ�ҽŵ��ź� */
#define       ADDR_TEST_DAC_CPLT_LT                         0x02A  /*����ʻ��ŵ��ź� */
#define       ADDR_TEST_DAC_CPLT_RT                         0x02B  /*����ʻ�ҽŵ��ź� */
#define       ADDR_SPINUP_SIGNAL                            0x031  /*������ת�ź� */

/*DSPֱ��������룬��ַ���ڲ���ʹ��*/
#define     ADDR_BrakePressureCommand_L              0x41  /*����ɲ�����Ʒ�*/
#define     ADDR_BrakePressureCommand_R              0x42  /*����ɲ�����Ʒ�*/
#define     ADDR_CoilEnergized                       0x43  /*�Զ�ɲ�����ؼ���*/
#define     ADDR_SOV_Open                            0x44  /*SOV*/
#define     ADDR_SD_CARD                             0x46  /*SD��*/
#define     ADDR_BEANCH_MODE                         0x47  /*BEANCH MODE*/
#define     ADDR_DSP_MODE                            0x48  /*DSP���ӻ�ģʽ*/

#define  DATA_LEN    (130)
#define  SDRAM_TIME_OUT    (30)
typedef  struct SDRAM_DATA_t
{
    unsigned short Addr;
    unsigned int value;
}SDRAM_DATA;
typedef enum
{
    OUTBOARD = 0x000,
    INBOARD=0x001,
}BOARD_TYPE;
typedef enum
{
    HIGH = 1,
    LOW=0,
}IO_LINE_STATUS;
extern SDRAM_DATA MCB_Data[DATA_LEN];/* ��������FPGA������*/
void Sdram_Init(void);
void SDRAM_Read(void);
void SDRAM_Write(void);


uint8_t GetBit(unsigned int data, unsigned int index);
uint8_t SDRAM_Write_Data(uint16_t Addr, uint32_t Data);
uint8_t SDRAM_Read_Data(uint16_t Addr,uint32_t *Read_data);
void set_sdram_clk(uint8_t statue);  /*�ߵ�λ*/
uint8_t Get_sdram_FWE(void);
void set_sdram_DWE(uint8_t statue);
void set_sdram_cs(uint8_t statue);   /*��д���߶�����д*/
void can2_tx_SetBit(uint8_t statue);
uint16_t get_sdram_DATA_A12( void);
void set_sdram_DATA_A12(uint8_t statue);
void set_sdram_cs(uint8_t statue);
void SDRAM_Set_IO_To_Write_Mode(void);
void SDRAM_Set_IO_To_Read_Mode(void);
unsigned char Get_Odd_value(unsigned int data);
#endif /* USERCODE_SDRAM_H_ */
