/*
  ******************************************************************************
  * @file    user_Main.c
  * @author  JYS
  * @version V1.0.0
  * @date    2020-06-10
  * @brief   Init
  */

#include "user_main.h"
uint8_t SDRAM_RxTx=0;       /*FPGA读写数据的标志*/
uint8_t SD_Process_Flag=0;  /*测试模式下，用于SD卡操作标志*/
uint8_t SD_Process_Mode=0;  /*测试模式下，用于SD卡读写标志*/
uint16_t File_Name=0;       /*测试模式下，用于SD卡里的文件名*/
uint16_t test_send_message_time_count=0;  /*测试模式下，用于上报采集信息的时间计数*/
uint16_t get_bench_mode_time_count=0;     /*用于判断Bench Mode的时间计数*/
void user_main(void)
{
    initialization();
    while (1)
    {
        if(SDRAM_RxTx==1) /*5ms*/
        {
            if(device_status.Work_Mode==NORMAL_MODE) /*正常运行模式*/
            {
                Data_interaction();
            }
            else /*测试模式*/
            {
                Test_Sdram_Data_Process();
                test_send_message_time_count++;
                if(test_send_message_time_count>=100) /*500ms，发送RS232数据*/
                {
                    test_send_message_time_count=0;
                    Send_Test_Message();
                }
            }
            SDRAM_RxTx=0;
        }
        if(get_bench_mode_time_count>=200)  /*1s，定时获取Banch_mode信号*/
        {
            get_bench_mode_time_count=0;
            Get_Bench_Mode();
        }
        Signal_Output_Control();    /*DSP对控制的信号进行控制*/
        SdCard_Maintenance();       /*SD卡状态维护*/
        if(SD_Process_Flag==1)      /*测试模式下，对SD卡进行处理*/
        {
            SD_Process_Flag=0;
            SD_Process(SD_Process_Mode,File_Name);
        }
    }
}

