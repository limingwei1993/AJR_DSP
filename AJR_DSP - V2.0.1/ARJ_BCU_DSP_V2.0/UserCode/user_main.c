/*
  ******************************************************************************
  * @file           ARJ_BCU_DSP
  * @department     Industry
  * @author         LMW
  * @version        V2.0.0
  * @date           2022-02-22
  * @software           Code Composer studio 10.3.0
  */

#include "user_main.h"
uint8_t SDRAM_RxTx=0;       /*FPGA读写数据的标志*/
uint8_t SD_Process_Flag=0;  /*测试模式下，用于SD卡操作标志*/
uint8_t SD_Process_Mode=0;  /*测试模式下，用于SD卡读写标志*/
uint16_t File_Name=0;       /*测试模式下，用于SD卡里的文件名*/
uint16_t test_send_message_time_count=0;  /*测试模式下，用于上报采集信息的时间计数*/
uint16_t get_bench_mode_time_count=0;     /*用于判断Bench Mode的时间计数*/
short temp_read_right=0;    /*右轮温度的ADC读取值*/
float temp_value_right=0;   /*右轮温度值*/
short temp_read_left=0;     /*左轮温度的ADC读取值*/
float temp_value_left=0;    /*左轮温度值*/
uint8_t get_temp_glag=0;    /*DSP读取温度的标志*/

uint8_t send_buff[15]={0};
extern uint32_t time_5ms_count;
void user_main(void)
{
    initialization();
    send_buff[0]='T';
    send_buff[1]='i';
    send_buff[2]='m';
    send_buff[3]='e';
    send_buff[4]=':';
    send_buff[10]='\r';
    send_buff[11]='\n';
    while (1)
    {
        Data_interaction();
        send_buff[5]=(uint8_t)(time_5ms_count/10000)+0x30;
        send_buff[6]=(uint8_t)(time_5ms_count/1000%10)+0x30;
        send_buff[7]=(uint8_t)(time_5ms_count/100%10)+0x30;
        send_buff[8]=(uint8_t)(time_5ms_count/10%10)+0x30;
        send_buff[9]=(uint8_t)(time_5ms_count%10)+0x30;
        RS232_Send(12, send_buff);
//        if(SDRAM_RxTx==1) /*5ms*/
//        {
//            SDRAM_RxTx=0;
//            if(device_status.Work_Mode==NORMAL_MODE) /*正常运行模式*/
//            {
//                Data_interaction();
//                send_buff[5]=(uint8_t)(time_5ms_count/10000)+0x30;
//                send_buff[6]=(uint8_t)(time_5ms_count/1000%10)+0x30;
//                send_buff[7]=(uint8_t)(time_5ms_count/100%10)+0x30;
//                send_buff[8]=(uint8_t)(time_5ms_count/10%10)+0x30;
//                send_buff[9]=(uint8_t)(time_5ms_count%10)+0x30;
//                RS232_Send(12, send_buff);
//            }
//            else /*测试模式*/
//            {
//                Test_Sdram_Data_Process();
//                test_send_message_time_count++;
//                if(test_send_message_time_count>=50) /*100ms，发送RS232数据*/
//                {
//                    test_send_message_time_count=0;
//                    Send_Test_Message();
//
//                }
//            }
//        }
//        if(get_temp_glag==1)
//        {
//            get_temp_glag=0;
//            temp_read_right=SpiRead_Right();
//            if(temp_read_right>=0)
//            {
//               temp_value_right=(temp_read_right>>3)*0.25;
//               if(device_status.Master_Salve_mode==1) //内轮板
//               {
//                   temp_value_right=temp_value_right*1.1016-29.48;
//
//               }
//               else   //外轮板
//               {
//                   temp_value_right=temp_value_right*1.1011-41.065;
//
//               }
//            //   temp_value_right=temp_value_right*0.9269-35.426;
//             //  temp_value_right=temp_value_right-50-(temp_value_right/100)*8+5;
//            }
//
//            temp_read_left=SpiRead_Left();
//            if(temp_read_left>=0)
//            {
//                temp_value_left=(temp_read_left>>3)*0.25;
//                if(device_status.Master_Salve_mode==1)  //内轮板
//               {
//                    temp_value_left=temp_value_left*1.0992-23.782;
//               }
//                else    //外轮板
//                {
//                   temp_value_left=temp_value_left*1.1017-35.168;
//                }
//              //  temp_value_left=temp_value_left*1.1009-52.387;
//              //  temp_value_left=temp_value_left*0.9269-35.426;
//             //   temp_value_left=temp_value_left-50-(temp_value_left/100)*8;
//            }
//        }
//        if(get_bench_mode_time_count>=200)  /*1s，定时获取Banch_mode信号*/
//        {
//            get_bench_mode_time_count=0;
//            Get_Bench_Mode();
//            Write_Coll_message_Into_SD();
//
//        }
        Signal_Output_Control();    /*DSP对控制的信号进行控制*/
        SdCard_Maintenance();       /*SD卡状态维护*/
        if(SD_Process_Flag==1)      /*测试模式下，对SD卡进行处理*/
        {
            SD_Process_Flag=0;
            SD_Process(SD_Process_Mode,File_Name);
        }
    }
}

