/*
 * SD_card.c
 *
 *  Created on: 2022年1月11日
 *      Author: 15755
 */
#include "user_main.h"
FIL file;
FIL file_M;
FATFS fs;
SdCardStatus sd_card_status;/*SD卡状态*/
/**************************
 * void SdCard_Maintenance(void)
 * SD卡状态维护
 * ****************************/
void SdCard_Maintenance(void)
{
  unsigned char num_init = 10;
  FRESULT res=FR_OK;
  if(get_SD_card_online_status() == 1)
  {
    if(sd_card_status == Fatfs_Load_Success)
    {
      f_mount(0, "0:", 1); /*Unload Fatfs*/
    }
    else if(sd_card_status == File_Open_Success)
    {
      f_close(&file);
      f_mount(0, "0:", 1); /*Unload Fatfs*/
    }
    sd_card_status = NO_Card_Insert;
  }
  else
  {
    switch(sd_card_status)
    {
      case NO_Card_Insert:
        sd_card_status = Card_Insert;
        break;
      case Card_Insert:
        do
        {
          num_init--;
        }while(SD_Init() != SD_OK && num_init > 0);
        if(num_init > 0)
        {
          sd_card_status = Card_Init_Success;
        }
        break;
      case Card_Init_Success:
        do                                          /*Load  Fatfs*/
        {
          num_init--;                               /* Mount a logical drive*/
        } while (f_mount(&fs, "0:", 1) != FR_OK && num_init > 0);
        if(num_init > 0)
        {
          sd_card_status = Fatfs_Load_Success;
        }
        break;
      case Fatfs_Load_Success:
      res=f_open (&file_M,  (const TCHAR *)("0:test.txt"),  FA_OPEN_ALWAYS | FA_WRITE);  /*新建文件并打开*/
      if(res==FR_OK)
      {
          sd_card_status =File_Open_Success;
      }
      break;
      default:
        break;
    }
  }
  device_status.sd_status=sd_card_status;
}
/**************************
 * void Write_Coll_message_Into_SD(void)
 * 将采集到的数据保存到SD卡
 * ****************************/
void Write_Coll_message_Into_SD(void)
{

    char frame_buff[500]={0};
    uint32_t frame_len=0;
    uint32_t write_success_len=0;
    if(sd_card_status!=File_Open_Success)
        return;
    frame_len+=sprintf(frame_buff+frame_len,"TEMP_L:%04X  ",MCB_Data[0].value);
    frame_len+=sprintf(frame_buff+frame_len,"TEMP_R:%04X  ",MCB_Data[1].value);
    frame_len+=sprintf(frame_buff+frame_len,"BPSI_L:%04X  ",MCB_Data[2].value);
    frame_len+=sprintf(frame_buff+frame_len,"BPSI_R:%04X  ",MCB_Data[3].value);
    frame_len+=sprintf(frame_buff+frame_len,"PED_L:%04X  ",MCB_Data[4].value);
    frame_len+=sprintf(frame_buff+frame_len,"PED_R:%04X  ",MCB_Data[5].value);
    frame_len+=sprintf(frame_buff+frame_len,"CPED_L:%04X  ",MCB_Data[6].value);
    frame_len+=sprintf(frame_buff+frame_len,"CPED_R:%04X  ",MCB_Data[7].value);
    frame_len+=sprintf(frame_buff+frame_len,"ABSW:%04X  ",MCB_Data[8].value);
    frame_len+=sprintf(frame_buff+frame_len,"SOV:%04X  ",MCB_Data[9].value);
    frame_len+=sprintf(frame_buff+frame_len,"BCV_L:%04X  ",MCB_Data[10].value);
    frame_len+=sprintf(frame_buff+frame_len,"BCV_R:%04X  ",MCB_Data[11].value);
    frame_len+=sprintf(frame_buff+frame_len,"WSPE_R:%04X  ",MCB_Data[12].value);
    frame_len+=sprintf(frame_buff+frame_len,"WSPE_L:%04X  ",MCB_Data[13].value);
    frame_len+=sprintf(frame_buff+frame_len,"ABRK_OFF:%d  ",Receive_Machine_Parameters.AutoBRK_OFF.Value);
    frame_len+=sprintf(frame_buff+frame_len,"ABRK_LOW:%d  ",Receive_Machine_Parameters.AutoBRK_LOW.Value);
    frame_len+=sprintf(frame_buff+frame_len,"ABRK_MED:%d  ",Receive_Machine_Parameters.AutoBRK_MED.Value);
    frame_len+=sprintf(frame_buff+frame_len,"ABRK_HI:%d  ",Receive_Machine_Parameters.AutoBRK_HI.Value);
    frame_len+=sprintf(frame_buff+frame_len,"ABRK_RTO:%d  ",Receive_Machine_Parameters.AutoBRK_RTO.Value);
    frame_len+=sprintf(frame_buff+frame_len,"WOW:%d  ",Receive_Machine_Parameters.RightWOW);
    frame_len+=sprintf(frame_buff+frame_len,"SPOI:%d  ",Receive_Machine_Parameters.SpoilerStoredSignal_Right);
    frame_len+=sprintf(frame_buff+frame_len,"THRO:%d  ",Receive_Machine_Parameters.LeftThrottleIdle);
    frame_len+=sprintf(frame_buff+frame_len,"ABS_S:%d  ",Receive_Machine_Parameters.Inner_wheel_ABS_start_signal);
    frame_len+=sprintf(frame_buff+frame_len,"spare:%d  ",Receive_Machine_Parameters.spare);
    frame_len+=sprintf(frame_buff+frame_len,"LAD:%d  ",Receive_Machine_Parameters.LandingGearExtentionandRetractionCommand);
    frame_len+=sprintf(frame_buff+frame_len,"PING_1:%d  ",Receive_Machine_Parameters.PIN_PGR_1);
    frame_len+=sprintf(frame_buff+frame_len,"PING_2:%d  ",Receive_Machine_Parameters.PIN_PGR_2);
    frame_len+=sprintf(frame_buff+frame_len,"PBRAK:%d  ",Receive_Machine_Parameters.Parking_brake_signal);
    frame_len+=sprintf(frame_buff+frame_len,"\r\n");
    f_write(&file_M,frame_buff,frame_len,&write_success_len);
    f_sync(&file_M);
}
