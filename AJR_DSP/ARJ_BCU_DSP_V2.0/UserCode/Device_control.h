/*
 * Device_control.h
 *
 *  Created on: 2022Äê1ÔÂ11ÈÕ
 *      Author: 15755
 */

#ifndef USERCODE_DEVICE_CONTROL_H_
#define USERCODE_DEVICE_CONTROL_H_
typedef enum
{
    NORMAL_MODE = 0x000,
    TEST_MODE=0x001,
}WORK_MODE;
typedef  struct Device_status_s
{
    unsigned char Master_Salve_mode;
    unsigned char Bench_Mode;
    unsigned char SOV_Status;
    unsigned char ABSW_Status;
    unsigned int BrakePressureCommand_L;
    unsigned int BrakePressureCommand_R;
    unsigned char Work_Mode;
    SdCardStatus sd_status;
}Device_status_d;

extern Device_status_d device_status;
void Set_ABSW(uint8_t statue);
void Set_SOV(uint8_t statue);
void Data_interaction(void);
void Signal_Output_Control(void);
void Transmit_Data_Process(void);
#endif /* USERCODE_DEVICE_CONTROL_H_ */
