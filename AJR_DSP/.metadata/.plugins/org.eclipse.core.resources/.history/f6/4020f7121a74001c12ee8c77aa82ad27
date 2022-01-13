/*
  ******************************************************************************
  * @file    user_Main.c
  * @author  JYS
  * @version V1.0.0
  * @date    2020-06-10
  * @brief   Init
  */

#include "user_main.h"
uint8_t SDRAM_RxTx=0;     /*FPGA读写数据的标志*/
void user_main(void)
{
    initialization();
    while (1)
    {
        if(SDRAM_RxTx==1) /*5ms*/
        {
            if(device_status.Work_Mode==NORMAL_MODE)
            {
                Data_interaction();
            }
            else
            {
                Test_Sdram_Data_Process();
            }
            SDRAM_RxTx=0;
        }
        Signal_Output_Control();
    }
}

