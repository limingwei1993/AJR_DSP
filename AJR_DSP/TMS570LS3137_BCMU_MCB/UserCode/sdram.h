/*
 * sdram.h
 *
 *  Created on: 2020年9月12日
 *      Author: liaot
 */

#ifndef USERCODE_SDRAM_H_
#define USERCODE_SDRAM_H_
#include <delay.h>
/*板卡ID--Board_ID
 * 主板==Inboard ==A==0x001
 * 从板==Outboard==B==0x002
 *
 * */
/*429 read ADDR*/
#define       ADDR_HYDRAULIC_SYSTEM_PRESSURE        (0x400 | (0x030) | (Board_ID <<8))                /*油源压力1_60*/
#define       ADDR_ACCUMULATOR_SYSTEM_PRESSURE      (0x400 | (0x056) | (Board_ID<<8))                 /*蓄压器压力1_126*/
#define       ADDR_TLA_POSITION_LEFT                (0x400 | (0x05B) | ((Board_ID&0x001)<<8) | 0x200) /*左油门杆位置_133*/
#define       ADDR_TLA_POSITION_RIGHT               (0x400 | (0x05B) | ((Board_ID&0x001)<<8) | 0x000) /*右油门杆位置_133*/
#define       ADDR_MASTER_TIME                      (0x400 | (0x068) | (Board_ID<<8))                 /*主机时间_150*/
#define       ADDR_AIRSPEED                         (0x400 | (0x086) | (Board_ID<<8))                 /*Computed_Air_Speed_206--计算空速*/
#define       ADDR_DATE_MASTER                      (0x400 | (0x0B0) | (Board_ID<<8))                 /*主机日期_260*/
#define       ADDR_LG_GEARDOWN_LOCKED               (0x400 | (0x0BA) | (Board_ID<<8))                 /*Gear_Position_1_272（Bit13）--起落架位置1*/
#define       ADDR_COMPUTED_WOW_DATA1               (0x400 | (0x0BF) | (0x001<<8))                    /*计算轮载数据1_277*/
#define       ADDR_COMPUTED_WOW_DATA2               (0x400 | (0x0BF) | (0x002<<8))                    /*计算轮载数据2_277*/
#define       ADDR_AIRCRAFTACCELERATION_LEFT        (0x400 | (0x0D9) | (0x001<<8))                    /*Longitudinal_Acceleration_Body_Left_331--机体左侧纵向加速度*/
#define       ADDR_AIRCRAFTACCELERATION_RIGHT       (0x400 | (0x0D9) | (0x002<<8))                    /*Longitudinal_Acceleration_Body_Right_331--机体右侧纵向加速度*/
/*429 write ADDR*/
#define       ADDR_LEFT_WHEEL_SPEED                 (0x400 | (0x006) | (Board_ID<<8))                 /*--左轮轮速_006*/
#define       ADDR_RIGHT_WHEEL_SPEED                (0x400 | (0x007) | (Board_ID<<8))                 /*--右轮轮速_007*/
#define       ADDR_LEFT_BRAKE_CONTROL_VALVE_CURENT  (0x400 | (0x029) | (Board_ID<<8))                 /*--左轮刹车控制阀电流 _051*//*回采*/
#define       ADDR_RIGHT_BRAKE_CONTROL_VALVE_CURENT (0x400 | (0x02A) | (Board_ID<<8))                 /*--右轮刹车控制阀电流_052*//*回采*/
#define       ADDR_LEFT_BRAKE_PRESSURE              (0x400 | (0x038) | (Board_ID<<8))                 /*左轮刹车压力_070 */
#define       ADDR_RIGHT_BRAKE_PRESSURE             (0x400 | (0x039) | (Board_ID<<8))                 /*右轮刹车压力_071 */
#define       ADDR_SHUTOFF_VALVE_CURRENT            (0x400 | (0x04B) | (Board_ID<<8))                 /*切断阀电流检测_113 *//*回采*/
#define       ADDR_LEFT_BRAKE_TEMPERATURE           (0x400 | (0x04C) | (Board_ID<<8))                 /*左轮刹车温度_114 */
#define       ADDR_RIGHT_BRAKE_TEMPERATURE          (0x400 | (0x04E) | (Board_ID<<8))                 /*右轮刹车温度_116 */
#define       ADDR_LEFT_BRAKE_PEDAL_POSITION_PILOT    (0x400 | (0x079) | (Board_ID<<8))               /*主驾左脚蹬_171*/
#define       ADDR_RIGHT_BRAKE_PEDAL_POSITION_PILOT   (0x400 | (0x07A) | (Board_ID<<8))               /*主驾右脚蹬_172*/
#define       ADDR_LEFT_BRAKE_PEDAL_POSITION_COPILOT  (0x400 | (0x07B) | (Board_ID<<8))               /*副驾左脚蹬_173*/
#define       ADDR_RIGHT_BRAKE_PEDAL_POSITION_COPILOT (0x400 | (0x07C) | (Board_ID<<8))               /*副驾右脚蹬_174*/
#define       ADDR_WARNING                            (0x400 | (0x0B8) | (Board_ID<<8))               /*警告_270*/
#define       ADDR_STATUS_1                           (0x400 | (0x0B9) | (Board_ID<<8))               /*状态文字#1_271*/
#define       ADDR_STATUS_2                           (0x400 | (0x0BA) | (Board_ID<<8))               /*状态文字#2_272*/
#define       ADDR_BCU_AIRCRAFT_REFERENCE_SPEED       (0x400 | (0x0C2) | (Board_ID<<8))               /*BCU飞机参考速度_302*/
#define       ADDR_FAILURE_WORD_1                     (0x400 | (0x0E8) | (Board_ID<<8))               /*故障文字#1_350*/
#define       ADDR_FAILURE_WORD_2                     (0x400 | (0x0E9) | (Board_ID<<8))               /*故障文字#2_351*/
#define       ADDR_FAILURE_WORD_3                     (0x400 | (0x0EA) | (Board_ID<<8))               /*故障文字#3_352*/
#define       ADDR_FAILURE_WORD_4                     (0x400 | (0x0EB) | (Board_ID<<8))               /*故障文字#4_353*/
/*FPGA本板卡采集信号*/
#define       ADDR_INBD_LT_TEMP                                 0x001  /*左内轮温度 */
#define       ADDR_INBD_RT_TEMP                                 0x002  /*右内轮温度 */
#define       ADDR_INBD_LT_BPSI                                 0x003  /*左内轮刹车压力 */
#define       ADDR_INBD_RT_BPSI                                 0x004  /*右内轮刹车压力 */
#define       ADDR_LEFTPPEDAL                                   0x005  /*CH1_PLT_LT_LVDT_Percent--主驾左脚蹬信号 */
#define       ADDR_RIGHTPPEDAL                                  0x006  /*CH1_PLT_RT_LVDT_Percent--主驾右脚蹬信号 */
#define       ADDR_LEFTCPEDAL                                   0x007  /*CH1_CPLT_LT_LVDT_Percent--副驾左脚蹬信号 */
#define       ADDR_RIGHTCPEDAL                                  0x008  /*CH1_CPLT_RT_LVDT_Percent--副驾右脚蹬信号 */
#define       ADDR_INNER_WHEEL_ABS_START_SIGNAL                 0x009  /* 内轮ABS启动信号*/ /*回采*/
#define       ADDR_INBOARD_SHUTOFF_VALVE_CURRENT                0x00A  /*切断阀电流检测 *//*回采*/
#define       ADDR_LEFT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT     0x00B  /*--右轮刹车控制阀电流*//*回采*/
#define       ADDR_RIGHT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT    0x00C  /*--左轮刹车控制阀电流 *//*回采*/
#define       ADDR_LEFTWHEELSPEED                               0x011  /*INBD_LT_WST--左轮轮速*/
#define       ADDR_RIGHTWHEELSPEED                              0x012  /*INBD_RT_WST--右轮轮速*/
#define       ADDR_AUTO_BRAKE_SW_SIGNAL                         0x013  /*自动刹车开关量信号*/
#define       ADDR_OTHER_SW_SIGNAL                              0x014  /*其它开关量信号*/
/*FPGA本板卡输出信号*/
#define       ADDR_TEST_DAC_BCV_LT                          0x021  /*测试信号左轮刹车控制阀 */
#define       ADDR_TEST_DAC_BCV_RT                          0x022  /*测试信号右轮刹车控制阀 */
#define       ADDR_TEST_DAC_CV_LT                           0x023  /*测试信号CV左 */
#define       ADDR_TEST_DAC_CV_RT                           0x024  /*测试信号CV右 */
#define       ADDR_TEST_DAC_WHELL_SPEED_LT                  0x025  /*测试信号内轮轮速 LT */
#define       ADDR_TEST_DAC_WHELL_SPEED_RT                  0x026  /*测试信号内轮轮速 RT */
#define       ADDR_TEST_DAC_SOV                             0x027  /*测试信号SOV */
#define       ADDR_TEST_DAC_PLT_LT                          0x028  /*主驾驶左脚蹬信号 */
#define       ADDR_TEST_DAC_PLT_RT                          0x029  /*主驾驶右脚蹬信号 */
#define       ADDR_TEST_DAC_CPLT_LT                         0x02A  /*副驾驶左脚蹬信号 */
#define       ADDR_TEST_DAC_CPLT_RT                         0x02B  /*副驾驶右脚蹬信号 */
#define       ADDR_SPINUP_SIGNAL                            0x031  /*轮速启转信号 */

/*DSP直接输出输入，地址用于测试使用*/
#define     ADDR_BrakePressureCommand_L              0x41  /*左轮刹车控制阀*/
#define     ADDR_BrakePressureCommand_R              0x42  /*右轮刹车控制阀*/
#define     ADDR_CoilEnergized                       0x43  /*自动刹车开关激励*/
#define     ADDR_SOV_Open                            0x44  /*SOV*/
#define     ADDR_SD_CARD                             0x46  /*SD卡*/
#define     ADDR_BEANCH_MODE                         0x47  /*BEANCH MODE*/
#define     ADDR_DSP_MODE                            0x48  /*DSP主从机模式*/

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
extern SDRAM_DATA MCB_Data[DATA_LEN];/* 接收来自FPGA的数据*/
void Sdram_Init(void);
void SDRAM_Read(void);
void SDRAM_Write(void);


uint8_t GetBit(unsigned int data, unsigned int index);
uint8_t SDRAM_Write_Data(uint16_t Addr, uint32_t Data);
uint8_t SDRAM_Read_Data(uint16_t Addr,uint32_t *Read_data);
void set_sdram_clk(uint8_t statue);  /*高低位*/
uint8_t Get_sdram_FWE(void);
void set_sdram_DWE(uint8_t statue);
void set_sdram_cs(uint8_t statue);   /*读写，高读，低写*/
void can2_tx_SetBit(uint8_t statue);
uint16_t get_sdram_DATA_A12( void);
void set_sdram_DATA_A12(uint8_t statue);
void set_sdram_cs(uint8_t statue);
void SDRAM_Set_IO_To_Write_Mode(void);
void SDRAM_Set_IO_To_Read_Mode(void);
unsigned char Get_Odd_value(unsigned int data);
#endif /* USERCODE_SDRAM_H_ */
