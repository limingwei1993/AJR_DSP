/*
 * SD_card.c
 *
 *  Created on: 2022��1��11��
 *      Author: 15755
 */
#include "user_main.h"
FIL file;
FIL file_M;
FATFS fs;
SdCardStatus sd_card_status;/*SD��״̬*/
/**************************
 * void SdCard_Maintenance(void)
 * SD��״̬ά��
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
      res=f_open (&file_M,  (const TCHAR *)("0:test.txt"),  FA_OPEN_ALWAYS | FA_WRITE);  /*�½��ļ�����*/
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
 * ���ɼ��������ݱ��浽SD��
 * ****************************/
void Write_Coll_message_Into_SD(void)
{

        char frame_buff[1000]={0};
        char title_buff1[]={"�¶����¶��ң�ѹ����ѹ���ң�������ŵţ������ҽŵţ�������ŵţ������ҽŵţ�ABS�زɣ�SOV�زɣ�ɲ������زɣ�ɲ�����һزɣ������������ң�ɲ������-OFF��ɲ������-LOW��ɲ������-MED��ɲ������-HI��ɲ������-RTO�����أ������壺���ţ�ABS�����У�����ܣ�PING1��PING2��ͣ��ɲ����"};
        char title_buff2[]={"��Դ����ѹ���������Ÿˣ������Ÿˣ����٣������1�������2����������1����������2�������ٶȣ��Ҳ���ٶȣ�"};
        uint32_t frame_len=0;
        uint32_t title_len=0;
        uint32_t write_success_len=0;
        if(sd_card_status!=File_Open_Success)  //�ж��ļ��Ƿ�򿪣����˲�д������
            return;
        //�¶���
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_TEMP/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_TEMP/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_TEMP/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_TEMP%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_LT_TEMP*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_LT_TEMP*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //�¶���
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_TEMP/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_TEMP/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_TEMP/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_TEMP%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_RT_TEMP*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_RT_TEMP*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //ѹ����
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_BPSI/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_BPSI/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_BPSI/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_LT_BPSI%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_LT_BPSI*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_LT_BPSI*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //ѹ����
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_BPSI/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_BPSI/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_BPSI/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.INBD_RT_BPSI%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_RT_BPSI*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.INBD_RT_BPSI*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        // ������ŵ�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftPPedal.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftPPedal.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftPPedal.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftPPedal.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftPPedal.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        // �����ҽŵ�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightPPedal.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightPPedal.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightPPedal.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightPPedal.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightPPedal.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        // ������ŵ�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftCptPedal.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftCptPedal.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftCptPedal.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftCptPedal.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftCptPedal.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        // �����ҽŵ�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightCptPedal.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightCptPedal.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightCptPedal.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightCptPedal.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightCptPedal.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //ABS�ز�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Inner_wheel_ABS_Valve_Current*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //SOV�ز�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //ɲ������ز�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //ɲ�����һز�
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //������
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftWheelSpeed.Value/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftWheelSpeed.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftWheelSpeed.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.LeftWheelSpeed.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftWheelSpeed.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.LeftWheelSpeed.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        //������
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightWheelSpeed.Value/1000+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightWheelSpeed.Value/100%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightWheelSpeed.Value/10%10+0x30;
        frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RightWheelSpeed.Value%10+0x30;
        frame_buff[frame_len++]='.';
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightWheelSpeed.Value*10)%10+0x30;
        frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RightWheelSpeed.Value*100)%10+0x30;
        frame_buff[frame_len++]=' ';
        // ɲ������-OFF
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.AutoBRK_OFF.Value%10+0x30;
        frame_buff[frame_len++]=' ';
        // ɲ������-LOW
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.AutoBRK_LOW.Value%10+0x30;
        frame_buff[frame_len++]=' ';
        // ɲ������-MED
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.AutoBRK_MED.Value%10+0x30;
        frame_buff[frame_len++]=' ';
        // ɲ������-HI
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=title_buff1[title_len++];
        frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.AutoBRK_HI.Value%10+0x30;
        frame_buff[frame_len++]=' ';
        // ɲ������-RTO
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.AutoBRK_RTO.Value%10+0x30;
       frame_buff[frame_len++]=' ';
       //���أ�
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.LeftWOW%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����壺
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.SpoilerStoredSignal_Left%10+0x30;
       frame_buff[frame_len++]=' ';
       //���ţ�
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.LeftThrottleIdle%10+0x30;
       frame_buff[frame_len++]=' ';
       //ABS��
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.Inner_wheel_ABS_start_signal%10+0x30;
       frame_buff[frame_len++]=' ';
       //���У�
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.spare%10+0x30;
       frame_buff[frame_len++]=' ';
       //����ܣ�
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.LandingGearExtentionandRetractionCommand%10+0x30;
       frame_buff[frame_len++]=' ';
       //PING1:
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.PIN_PGR_1%10+0x30;
       frame_buff[frame_len++]=' ';
       //PING2:
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.PIN_PGR_2%10+0x30;
       frame_buff[frame_len++]=' ';
       //ͣ��ɲ����
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=title_buff1[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.Parking_brake_signal%10+0x30;
       frame_buff[frame_len++]=' ';
       //��Դ��
       title_len=0;
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //��ѹ����
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����Ÿˣ�
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����Ÿˣ�
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //���٣�
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����1��
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.RX_429_Communication.In_MLG_LtDownlocked%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����2��
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.RX_429_Communication.In_MLG_RtDownlocked%10+0x30;
       frame_buff[frame_len++]=' ';
       //��������1����������2
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_1_277%10+0x30;
       frame_buff[frame_len++]=' ';
       //��������2
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint8_t)Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_2_277%10+0x30;
       frame_buff[frame_len++]=' ';
       //�����ٶȣ�
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value*100)%10+0x30;
       frame_buff[frame_len++]=' ';
       //�Ҳ���ٶȣ�
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=title_buff2[title_len++];
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value/1000+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value/100%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value/10%10+0x30;
       frame_buff[frame_len++]=(uint32_t)Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value%10+0x30;
       frame_buff[frame_len++]='.';
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value*10)%10+0x30;
       frame_buff[frame_len++]=(uint32_t)(Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value*100)%10+0x30;
       frame_buff[frame_len++]='\r';
       frame_buff[frame_len++]='\n';
       f_write(&file_M,frame_buff,frame_len,&write_success_len);  //д���ݵ�������
       f_sync(&file_M);   //ˢ�»�������������������д��SD����
}
