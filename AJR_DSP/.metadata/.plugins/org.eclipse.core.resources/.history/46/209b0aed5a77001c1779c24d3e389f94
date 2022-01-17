/*
  ******************************************************************************
  * @file    dac5689.c
  * @author  LI
  * @version V1.0.0
  * @date    2022-1-17
  */
#include "user_main.h"
unsigned char InputBuf[10]={0x00,0x00,0x00};
unsigned char OutputBuf[10]={0x00,0x00,0x00};
/*******************************
 * void DAC5689_Init(void)
 * DAC5689模块初始化。
 ******************************/
void DAC5689_Init(void)
{
    spiInit();
    gioSetBit(spiPORT1,SPI_PIN_CS2,0);//RESET_L;
    delay_us(20);
    gioSetBit(spiPORT1,SPI_PIN_CS2,1);//RESET_H;
    delay_us(100);
}
/*******************************
 * void WriteData(unsigned int commandmode, unsigned int DACselect, unsigned int Data)
 * 写数据
 * commandmode：通信模式
 * DACselect： DAC选择
 * Data:数据
 ******************************/
void WriteData(unsigned int commandmode, unsigned int DACselect, unsigned int Data)
{
    int RegisterData = 0x000000;
    RegisterData = commandmode + DACselect + Data;  //Merging the data recieved into a single register
    WriteRegister(RegisterData);

}
/*******************************
 * void WriteRegister(unsigned long int WriteData)
 * 写数据寄存器
 * WriteData:数据
 ******************************/
void WriteRegister(unsigned long int WriteData)
{
    unsigned char Byte;
    for(Byte=0;Byte < NO_OF_BYTES;Byte++)
    {
        *(OutputBuf + Byte) = (WriteData>>(((NO_OF_BYTES-1)-Byte)*8)); //Writing the data to be written to 8 bit Output Buffer
        *(InputBuf + Byte) = 0x00;
    }
    SpiReadWrite( InputBuf, OutputBuf, NO_OF_BYTES); //Writes data to the specified register
}
/*******************************
 * void SpiReadWrite(unsigned char *InBuf, unsigned char *OutBuf, unsigned char NoOfBytes)
 * SPI读写
 * *InBuf: 输入数据地址
 * *OutBuf： 输出数据地址
 * NoOfBytes ：个数
 ******************************/
void SpiReadWrite(unsigned char *InBuf, unsigned char *OutBuf, unsigned char NoOfBytes)
{
    int i,j;
    unsigned int TempInput = 0x00;
    unsigned int TempOutput = 0x00;
    unsigned int ReceivedBit = 0x00;
    gioSetBit(spiPORT1,SPI_PIN_ENA,0);//SYNC_L;
    delay_us(50);
    for(i=0; i< NoOfBytes; i++)
    {
        TempOutput = *OutBuf;
        for(j=0; j<8; j++)
        {
            /***********WRITE DATA**************/
            gioSetBit(spiPORT1,SPI_PIN_CLK,1);//SPI1_CLK_H;
            delay_us(50);
            if(0x80==(TempOutput & 0x80))
            {
                gioSetBit(spiPORT1,SPI_PIN_SIMO,1);//SPI1_MOSI_H;
            }
            else
            {
                gioSetBit(spiPORT1,SPI_PIN_SIMO,0);//SPI1_MOSI_L;
            }
            TempOutput<<=1;
            delay_us(50);
            /*********WRITE DATA ENDS*********/
            /*********READ DATA***************/
            gioSetBit(spiPORT1,SPI_PIN_CLK,0);//SPI1_CLK_L;
            delay_us(50);
            TempInput<<=1;
            ReceivedBit = gioGetBit(spiPORT1,SPI_PIN_SOMI);//SPI1_MISO
            if(0x1==ReceivedBit)
            {
                TempInput |= 1;
            }
            /************READ DATA ENDS***********/
        }
        *InBuf = TempInput;
        OutBuf++;
        InBuf++;
    }
    gioSetBit(spiPORT1,SPI_PIN_ENA,1);/*SYNC_H*/;
    delay_us(50);
}
/*******************************
 * void DAC5689_SetVoltage_mv(unsigned int DACselect, unsigned int Voltage)
 * 输出DAC值。
 * DACselect:   DAC_A | DAC_B
 * Voltage:     0  ~ 5000mV
 *
 ******************************/
void DAC5689_SetVoltage_mv(unsigned int DACselect, unsigned int Voltage)
{
    if(Voltage >5000)
        Voltage = 5000;
    unsigned int V =(unsigned int)(Voltage*65535 / 5000) ;
    WriteData(REG_WRITE_UPDATE_DAC_CHANNEL, DACselect,V);
    delay_ns(100);
}

