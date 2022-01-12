/*
  ******************************************************************************
  * @file    user_Main.c
  * @author  JYS
  * @version V1.0.0
  * @date    2020-06-10
  * @brief   Init
  */

#include "user_main.h"

#include "string.h"
#include "stdio.h"
#define test_SD    0      /* 测试使用，置1后打开测试SD卡功能，置0则关闭*/
#define test_SDRAM 1      /* 测试使用，置1后打开测试与FPGA通信的功能，置0则关闭*/
#define test_DAC   0      /* 测试使用，置1后打开测试DAC功能，置0则关闭*/
#define test_RS232 0      /* 测试使用，置1后打开测试RS232功能，置0则关闭*/
#define test_SOV   0      /* 测试使用，置1后打开测试SOV功能，置0则关闭*/
#define test_ABSW  0      /* 测试使用，置1后打开测试ABSW功能，置0则关闭*/
uint8_t POWER_SOV = 0;    /* 测试使用，控制SOV参数*/
uint8_t POWER_ABSW = 1;   /* 测试使用，控制ABSW参数*/
uint8_t test_DAC_1=0;     /*测试使用，置1控制DAC1*/
uint8_t test_DAC_2=0;     /*测试使用，置1控制DAC2*/
uint16_t DAC_ValueO = 0;  /*测试使用，输出DAC1的值*/
uint16_t DAC_ValueI = 0;  /*测试使用，输出DAC1的值*/
FATFS   fs;         /*测试使用，测试SD卡*/
FIL     file;       /*测试使用，测试SD卡*/
uint8_t test_sd_read=0;/*测试使用，置1读取SD卡*/
uint8_t test_sd_write=0;/*测试使用，置1写数据到SD卡*/
uint8_t sd_write_buff[120]={0};/*测试使用，写入SD卡的数据*/
uint8_t sd_read_buff[120]={0};/*测试使用，保存从SD卡读取的数据*/
uint8_t readlen=0;/*测试使用，从SD卡读取的数据长度*/
uint8_t SDRAM_RxTx=0;     /*FPGA读写数据的标志*/

void user_main(void)
{
    initialization();
    /*************以下测试程序，SD卡**************/
#if test_SD==1
    if(f_mount(&fs,"0:",1) != FR_OK)/*用于测试SD卡，挂在文件系统*/
    {
        RS232_Send(18,"\r\nSD_CARD_LOAD_ERR\r\n");/*测试使用，SD卡挂载失败，RS232上报*/
    }
    /*************以上测试SD卡**************/
#endif
    while (1)
    {
    /*************以下测试程序，ASSW**************/
#if test_ABSW==1
        /******以下测试程序，控制ABSW*******/
        set_SOL(POWER_ABSW);
        /******以上测试程序，控制*******/
#endif
    /*************以上测试程序，ASSW**************/
    /*************以下测试程序，SOV**************/
#if test_SOV==1
        /******以下测试程序，控制SOV*******/
        set_SOV(POWER_SOV);
        /******以上测试程序，控制*******/
#endif
   /*************以上测试程序，SOV**************/
   /*************以下测试程序，SD卡**************/
#if test_SD==1
        /******以下测试程序，SD卡*******/
        if(test_sd_write==1)/*测试使用，写数据到SD卡*/
       {
          f_open (&file,  (const TCHAR *)"0:30.txt",  FA_OPEN_ALWAYS | FA_WRITE);  /*新建文件并打开*/
          for(i=0;i<100;i++)  /*给往SD卡写的数据赋值*/
          {
              if(sd_write_buff[i]<0xff)
               sd_write_buff[i]=sd_write_buff[i]+0x30;
              else
                  sd_write_buff[i]=0;
          }
          f_puts(sd_write_buff, &file); /*写数据到缓存*/
          f_sync(&file);  /*将缓存区的数据写到文件*/
          f_close (&file); /*关闭文件*/
          test_sd_write=0; /*此次写数据到SD卡结束*/
       }
        if(test_sd_read==1)/*测试使用，从SD卡读取数据*/
        {
            f_open (&file,  (const TCHAR *)"0:30.txt",FA_READ); /*打开文件*/
            f_read (&file, sd_read_buff, 100, &readlen); /*读数据*/
            f_close (&file); /*关闭文件*/
            test_sd_read=0;  /*此次读数据从SD卡结束*/
            for(i=0;i<100;i++) /*比较读写SD卡的数据*/
            {
                 if(sd_read_buff[i]!=sd_write_buff[i])  /*比较SD卡的读写是否一致，不一致上报错误信息。*/
                 {
                     RS232_Send(18,"\r\nsd_write_buff=\r\n");
                     RS232_Send(100,sd_write_buff);
                     RS232_Send(17,"\r\nsd_read_buff=\r\n");
                     RS232_Send(100,sd_read_buff);
                     i=100;
                 }
            }
        }
        /******以上测试程序，SD卡*******/
#endif
        if(SDRAM_RxTx==1) /*5ms*/
        {
            Data_interaction();
            SDRAM_RxTx=0;
        }
#if test_DAC==1
        /******以下测试程序，控制DAC*******/
        if(test_DAC_1==1) /*测试DAC1*/
        {
            DAC5689_SetVoltage_mv(DAC_O,DAC_ValueO);
        }
        if(test_DAC_2==1)/*测试DAC2*/
        {

            DAC5689_SetVoltage_mv(DAC_I,DAC_ValueI);
        }
        /******以上测试程序，控制DAC*******/
#endif
        /*************以上测试程序，DAC**************/
        /*************以下测试程序，RS232**************/
#if test_RS232==1
        /*******以下测试RS232****************8*/
        if(rs232_send_len !=rs232_recive_len)  /*RS232有接收到新的数据。将新接收的数据发送出去*/
        {

            if(rs232_recive_len>rs232_send_len)
            {
              RS232_Send(rs232_recive_len-rs232_send_len,&temp_Recive_buf[rs232_send_len]);
              rs232_send_len=rs232_recive_len;

            }
            else if(rs232_recive_len<rs232_send_len)
            {
              RS232_Send(1000-rs232_send_len,&temp_Recive_buf[rs232_send_len]);
              RS232_Send(rs232_recive_len,&temp_Recive_buf[0]);
              rs232_send_len=rs232_recive_len;
            }

        }
        /*******以上测试RS232****************8*/
#endif
        /*************以上测试程序，RS232**************/
    }
}
