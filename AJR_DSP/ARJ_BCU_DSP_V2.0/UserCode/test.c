/*
 * test.c
 *
 *  Created on: 2022年1月12日
 *      Author: 15755
 */

#include "user_main.h"
/**************************
 * void RS232_Process(uint8_t *frame_data)
 * RS232 数据数据处理
 * frame_data：数据
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
           respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
           respond_frame[frame_len++]=0x55;
           RS232_Send(frame_len,respond_frame);
           device_status.Work_Mode=TEST_MODE;
       break;
       case WRITE_DATA:
           if(device_status.Work_Mode==TEST_MODE)
           {
               Data_Addr=(unsigned short)(frame_data[2] | frame_data[3]<<8);
               Data_value=(unsigned int)(frame_data[4] | frame_data[5]<<8);
               Write_Data_Process(Data_Addr,Data_value);
           }
           else
           {
              respond_frame[frame_len++]=0xAA;
              respond_frame[frame_len++]=WRITE_DATA;
              respond_frame[frame_len++]=0;
              respond_frame[frame_len++]=0;
              respond_frame[frame_len++]=0;
              respond_frame[frame_len++]=0;
              respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
              respond_frame[frame_len++]=0x55;
              RS232_Send(frame_len,respond_frame);
           }
       break;
       case READ_DATA:
           if(device_status.Work_Mode==TEST_MODE)
           {
               Data_Addr=(unsigned short)(frame_data[2] | frame_data[3]<<8);
               Data_value=(unsigned int)(frame_data[4] | frame_data[5]<<8);
               Read_Data_Process(Data_Addr,Data_value);
           }
           else
          {
             respond_frame[frame_len++]=0xAA;
             respond_frame[frame_len++]=READ_DATA;
             respond_frame[frame_len++]=0;
             respond_frame[frame_len++]=0;
             respond_frame[frame_len++]=0;
             respond_frame[frame_len++]=0;
             respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
             respond_frame[frame_len++]=0x55;
             RS232_Send(frame_len,respond_frame);
          }
       break;
       case QUIT_DBUG:
              respond_frame[frame_len++]=0xAA;
              respond_frame[frame_len++]=QUIT_DBUG;
              respond_frame[frame_len++]=0x00;
              respond_frame[frame_len++]=0x00;
              respond_frame[frame_len++]=0x00;
              respond_frame[frame_len++]=0x00;
              respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
              respond_frame[frame_len++]=0x55;
              RS232_Send(frame_len,respond_frame);
              device_status.Work_Mode=NORMAL_MODE;
      break;
   }
}

/**************************
 * void Write_Data_Process(uint16_t Addr,uint16_t value)
 * RS232 写数据指令处理
 * Addr：数据地址
 * value：数据值
 * ****************************/
void Write_Data_Process(uint16_t Addr,uint16_t value)
{
    unsigned char i=0;
    unsigned char respond_frame[20]={0};
    unsigned char frame_len=0;
    for(i=0;i<Device_DATA_LEN;i++)
    {
        if(MCB_Data[i].Addr==(Addr&0x0fff))
        {
            if(Addr==0x46)
            {
                SD_Process_Flag=1;
                File_Name=value;
                SD_Process_Mode=SD_WRITE;
            }
            else
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
                respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
                respond_frame[frame_len++]=0x55;
                RS232_Send(frame_len,respond_frame);
            }
            break;
        }
    }
}

/**************************
 * void Read_Data_Process(uint16_t Addr,uint16_t value)
 * RS232 读数据指令处理
 * Addr：数据地址
 * value：数据值
 * ****************************/
void Read_Data_Process(uint16_t Addr,uint16_t value)
{
    unsigned char i=0;
    unsigned char respond_frame[20]={0};
    unsigned char frame_len=0;
    for(i=0;i<Device_DATA_LEN;i++)
    {
        if(MCB_Data[i].Addr==(Addr&0x0fff))
        {
            if(Addr==0x46)
            {
                SD_Process_Flag=1;
                File_Name=value;
                SD_Process_Mode=SD_READ;
            }
            else
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
                respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
                respond_frame[frame_len++]=0x55;
                RS232_Send(frame_len,respond_frame);
            }
            break;
        }
    }
}

/**************************
 * void SD_Process(uint8_t Read_Write,uint16_t value,uint8_t * readdata)
 * RS232 根据RS232指令对SD进行读写处理。用于测试
 * Read_Write：读或是写。
 * value：传入的值（文件名）
 * readdata：保存读取的值
 * ****************************/
void SD_Process(uint8_t Read_Write,uint16_t value)
{
    static char dir[30] = {0};
    char test_buff[SD_TEST_LEN] = {0};
    unsigned char temp =1;
    unsigned int write_success_len =0;
    unsigned short i=0;
    unsigned char respond_frame[20]={0};
    unsigned char frame_len=0;
    FRESULT res=FR_OK;
    if(sd_card_status!=Fatfs_Load_Success)
       return;
    if(Read_Write==SD_WRITE)
    {
        for(i=0;i<SD_TEST_LEN;i++)
        {
            test_buff[i]=temp++;
        }
        sprintf(dir,"0:%d.txt",value);
        res=f_open (&file,  (const TCHAR *)dir,  FA_OPEN_ALWAYS | FA_WRITE);  /*新建文件并打开*/
        if(res==FR_OK)
        {
            f_write(&file,test_buff,SD_TEST_LEN,&write_success_len);
            f_sync(&file);
            f_close(&file);
        }
        else
        {
            return;
        }
        respond_frame[frame_len++]=0xAA;
        respond_frame[frame_len++]=WRITE_DATA;
        respond_frame[frame_len++]=(unsigned char)((ADDR_SD_CARD>>0)&0xff);
        respond_frame[frame_len++]=(unsigned char)((ADDR_SD_CARD>>8)&0xff);
        respond_frame[frame_len++]=(unsigned char)((value>>0)&0xff);
        respond_frame[frame_len++]=(unsigned char)((value>>8)&0xff);
        respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
        respond_frame[frame_len++]=0x55;
        RS232_Send(frame_len,respond_frame);
    }
    else if(Read_Write==SD_READ)
    {
        for(i=0;i<SD_TEST_LEN;i++)
        {
            test_buff[i]=0;
        }
        sprintf(dir,"0:%d.txt",value);
        f_open (&file,  (const TCHAR *)dir, FA_READ);  /*新建文件并打开*/
        if(res==FR_OK)
        {
            f_gets(test_buff,10,&file);
            f_close(&file);
        }
        else
        {
            return;
        }
        respond_frame[frame_len++]=0xAA;
        respond_frame[frame_len++]=READ_DATA;
        respond_frame[frame_len++]=(unsigned char)((ADDR_SD_CARD>>0)&0xff);
        respond_frame[frame_len++]=(unsigned char)((ADDR_SD_CARD>>8)&0xff);
        respond_frame[frame_len++]=(unsigned char)((test_buff[0]>>0)&0xff);
        respond_frame[frame_len++]=(unsigned char)((test_buff[0]>>8)&0xff);
        respond_frame[frame_len++]=CRC_AND(&respond_frame[1],frame_len-1);
        respond_frame[frame_len++]=0x55;
        RS232_Send(frame_len,respond_frame);
    }
}


/**************************************
 * void TEST_SDRAM_Write(void)
 * 发送所有数据到FPGA--测试使用
 * ************************************/
void TEST_SDRAM_Write(void)
{
    unsigned short i=0;
    SDRAM_Set_IO_To_Write_Mode();
    /*发送地址0x40--0x60的数据*/
    for(i=SDRAM_READ_DATA_LEN;i<(SDRAM_WRITE_DATA_LEN+SDRAM_READ_DATA_LEN);i++)
    {
        SDRAM_Write_Data(MCB_Data[i].Addr,MCB_Data[i].value);
    }
}

/**************************
 * void Test_Sdram_Data_Process(void)
 * 测试模式下DSP与FPGA进行数据交互
 * ****************************/
void Test_Sdram_Data_Process(void)
{
    unsigned short i=0;
    for(i=Device_DATA_LEN-7;i<Device_DATA_LEN;i++)  /*根据RS232接收的数据，修改控制DSP输出的参数*/
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
    TEST_SDRAM_Write();
}
