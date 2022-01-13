/*
 * test.c
 *
 *  Created on: 2022��1��12��
 *      Author: 15755
 */

#include "user_main.h"
/**************************
 * void RS232_Process(uint8_t *frame_data)
 * RS232 �������ݴ���
 * frame_data������
 * ****************************/
void RS232_Process(uint8_t *frame_data)
{
   unsigned char respond_frame[20]={0};
   unsigned char frame_len=0;
   unsigned short Data_Addr=0;
   unsigned short Data_value=0;
   switch(frame_data[1])
   {
       case ENTER_DBUG:
           respond_frame[frame_len++]=0xAA;
           respond_frame[frame_len++]=ENTER_DBUG;
           respond_frame[frame_len++]=0x00;
           respond_frame[frame_len++]=0x00;
           respond_frame[frame_len++]=0x00;
           respond_frame[frame_len++]=0x00;
           respond_frame[frame_len++]=CRC_AND(respond_frame,frame_len);
           respond_frame[frame_len++]=0x55;
           RS232_Send(frame_len,respond_frame);
           device_status.Work_Mode=TEST_MODE;
       break;
       case WRITE_DATA:
           Data_Addr=(unsigned short)(frame_data[2] | frame_data[3]<<8);
           Data_value=(unsigned int)(frame_data[4] | frame_data[5]<<8);
           Write_Data_Process(Data_Addr,Data_value);
       break;
       case READ_DATA:
           Data_Addr=(unsigned short)(frame_data[2] | frame_data[3]<<8);
           Data_value=(unsigned int)(frame_data[4] | frame_data[5]<<8);
           Read_Data_Process(Data_Addr,Data_value);
       break;
       case QUIT_DBUG:
          respond_frame[frame_len++]=0xAA;
          respond_frame[frame_len++]=ENTER_DBUG;
          respond_frame[frame_len++]=0x00;
          respond_frame[frame_len++]=0x00;
          respond_frame[frame_len++]=0x00;
          respond_frame[frame_len++]=0x00;
          respond_frame[frame_len++]=CRC_AND(respond_frame,frame_len);
          respond_frame[frame_len++]=0x55;
          RS232_Send(frame_len,respond_frame);
          device_status.Work_Mode=NORMAL_MODE;
      break;
   }
}
/**************************
 * void Write_Data_Process(uint16_t Addr,uint16_t value)
 * RS232 д����ָ���
 * Addr�����ݵ�ַ
 * value������ֵ
 * ****************************/
void Write_Data_Process(uint16_t Addr,uint16_t value)
{
    unsigned char i=0;
    unsigned char respond_frame[20]={0};
    unsigned char frame_len=0;
    unsigned char read_data=0;
    for(i=0;i<Device_DATA_LEN;i++)
    {
        if(MCB_Data[i].Addr==(Addr&0x0fff))
        {
            respond_frame[frame_len++]=0xAA;
            respond_frame[frame_len++]=WRITE_DATA;
            respond_frame[frame_len++]=(unsigned char)((Addr>>0)&0xff);
            respond_frame[frame_len++]=(unsigned char)((Addr>>8)&0xff);
            if(((Addr>>12) &0x0001)==1)
            {
                MCB_Data[i].value &=0x0000ffff;
                MCB_Data[i].value |=((value<<16)&0xffff0000);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>16)&0xff);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>24)&0xff);
            }
            else
            {
                MCB_Data[i].value &=0xffff0000;
                MCB_Data[i].value |=((value<<0)&0x0000ffff);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>0)&0xff);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>8)&0xff);
            }
            if(Addr==0x46)
            {
                SD_Process(SD_WRITE,value,&read_data);
            }
            respond_frame[frame_len++]=CRC_AND(respond_frame,frame_len);
            respond_frame[frame_len++]=0x55;
            RS232_Send(frame_len,respond_frame);
            break;
        }
    }
}
/**************************
 * void Read_Data_Process(uint16_t Addr,uint16_t value)
 * RS232 ������ָ���
 * Addr�����ݵ�ַ
 * value������ֵ
 * ****************************/
void Read_Data_Process(uint16_t Addr,uint16_t value)
{
    unsigned char i=0;
    unsigned char respond_frame[20]={0};
    unsigned char frame_len=0;
    unsigned char read_data=0;
    for(i=0;i<Device_DATA_LEN;i++)
    {
        if(MCB_Data[i].Addr==(Addr&0x0fff))
        {
            respond_frame[frame_len++]=0xAA;
            respond_frame[frame_len++]=READ_DATA;
            respond_frame[frame_len++]=(unsigned char)((Addr>>0)&0xff);
            respond_frame[frame_len++]=(unsigned char)((Addr>>8)&0xff);
            if(((Addr>>12) &0x0001)==1)
            {
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>16)&0xff);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>24)&0xff);
            }
            else
            {
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>0)&0xff);
                respond_frame[frame_len++]=(unsigned char)((MCB_Data[i].value>>8)&0xff);
            }
            if(Addr==0x46)
            {
                SD_Process(READ_DATA,value,&read_data);
                frame_len-=2;
                respond_frame[frame_len++]=read_data;
                respond_frame[frame_len++]=0;
            }
            respond_frame[frame_len++]=CRC_AND(respond_frame,frame_len);
            respond_frame[frame_len++]=0x55;
            RS232_Send(frame_len,respond_frame);
            break;
        }
    }
}
/**************************
 * void SD_Process(uint8_t Read_Write,uint16_t value,uint8_t * readdata)
 * RS232 ����RS232ָ���SD���ж�д���������ڲ���
 * Read_Write��������д��
 * value�������ֵ���ļ�����
 * readdata�������ȡ��ֵ
 * ****************************/
void SD_Process(uint8_t Read_Write,uint16_t value,uint8_t * readdata)
{
    static char dir[30] = {0};
    char test_buff[SD_TEST_LEN] = {0};
    unsigned char temp =0;
    unsigned int write_success_len =0;
    unsigned short i=0;
    if(sd_card_status!=Fatfs_Load_Success)
       return;
    if(Read_Write==SD_WRITE)
    {
        for(i=0;i<SD_TEST_LEN;i++)
        {
            test_buff[i]=temp++;
        }
        sprintf(dir,"0:%d",value);
        f_open (&file,  (const TCHAR *)dir,  FA_OPEN_ALWAYS | FA_WRITE);  /*�½��ļ�����*/
        f_write(&file,test_buff,SD_TEST_LEN,&write_success_len);
        f_sync(&file);
        f_close(&file);
        *readdata=0;
    }
    else if(Read_Write==SD_READ)
    {
        for(i=0;i<SD_TEST_LEN;i++)
        {
            test_buff[i]=0;
        }
        sprintf(dir,"0:%d",value);
        f_open (&file,  (const TCHAR *)dir,  FA_READ);  /*�½��ļ�����*/
        f_gets(test_buff,10,&file_past_err);
        f_close(&file);
        *readdata=test_buff[0];
    }

}

/**************************
 * void Test_Sdram_Data_Process(void)
 * ����ģʽ��DSP��FPGA�������ݽ���
 * ****************************/
void Test_Sdram_Data_Process(void)
{
    unsigned short i=0;
    for(i=Device_DATA_LEN-7;i<Device_DATA_LEN;i++)
    {
        if(MCB_Data[i].Addr==ADDR_SOV_Open)
        {
            if(Transmit_Machine_Parameters.SOV_Open!=MCB_Data[i].value)
            {
                Transmit_Machine_Parameters.SOV_Open=MCB_Data[i].value;
            }
        }
        if(MCB_Data[i].Addr==ADDR_CoilEnergized)
        {
            if(Transmit_Machine_Parameters.CoilEnergized!=MCB_Data[i].value)
            {
                Transmit_Machine_Parameters.CoilEnergized=MCB_Data[i].value;
            }
        }
        if(MCB_Data[i].Addr==ADDR_BrakePressureCommand_L)
        {
            if(Transmit_Machine_Parameters.BrakePressureCommand_L!=MCB_Data[i].value)
            {
                Transmit_Machine_Parameters.BrakePressureCommand_L=MCB_Data[i].value;
            }
        }
        if(MCB_Data[i].Addr==ADDR_BrakePressureCommand_R)
        {
            if(Transmit_Machine_Parameters.BrakePressureCommand_R!=MCB_Data[i].value)
            {
                Transmit_Machine_Parameters.BrakePressureCommand_R=MCB_Data[i].value;
            }
        }
    }
    SDRAM_Read();
    SDRAM_Write();
}