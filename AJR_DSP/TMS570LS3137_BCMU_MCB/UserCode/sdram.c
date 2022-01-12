/*
 * sdram.c
 *
 *  Created on: 2020��9��12��
 *      Author: liaot
 */

#include "sdram.h"
#include "reg_can.h"
#include "reg_mibspi.h"
SDRAM_DATA MCB_Data[DATA_LEN];/* ��������FPGA������*/
/**************************************
 * void Sdram_Init(void)
 * ��FPGAͨ�ŵĳ�ʼ��
 * ************************************/
void Sdram_Init(void)
{
    hetPORT1->DIR &= (~ 0x0555DC00);    /*INPUT--DATA:10-12 14-16 18 20 22 24 26*/
    hetPORT1->DIR |= 0x500003BF;        /*OUTPUT--ADDR:0-5  7-9 28 30*/
    gioPORTA->DIR &= (~ 0X000000E4);    /*INPUT--DATA:2 5 6 7*/
    canREG2->TIOC &=(~0x00000008);      /*can2_tx as i/o  to ADDR_A6*/
    canREG2->TIOC |= 0x00000004;        /*can2_tx output*/
    canREG2->RIOC &=(~0x0000000C);      /*can2_Rx as i/o  to DATA_A12   INPUT*/
    mibspiREG5->PC0 &=(~0x00000E01);    /*mbspi_cS as i/o  to cS;  mbspi_clkx as i/o  to clk; mbspi_SOMI as i/o  to DWE;mbspi_SIMO as i/o  to FWE;*/
    mibspiREG5->PC1 |=(0x00000A01);     /*CS��CLK��DWE output*/
    mibspiREG5->PC1 &=(~0x00000400);    /*FWE intput*/
}
/**************************************
 * void SDRAM_Set_IO_To_Read_Mode(void)
 * ��SDRAM��IO����Ϊ��ģʽ
 * ************************************/
void SDRAM_Set_IO_To_Read_Mode(void)
{
    /*��1�����   ��IO������Ϊ��ȡ����PFGA���ݵ�ģʽ*/
    hetPORT1->DIR &= (~ 0x0555DC00);    /*INPUT--DATA:10-12 14-16 18 20 22 24 26*/
    gioPORTA->DIR &= (~ 0X000000E4);    /*INPUT--DATA:2 5 6 7*/
    canREG2->RIOC &=(~0x00000004);      /*can2_Rx as i/o  to DATA_A12   INPUT*/
}
/**************************************
 * uint8_t SDRAM_Read_Data( uint8_t Addr,uint16_t *Read_data)
 * ��FPGAָ����ַ��ȡ����
 * �ɹ�����0��ʧ�ܷ���1��
 * ************************************/
uint8_t SDRAM_Read_Data( uint16_t Addr,uint32_t *Read_data)
{
    uint16_t time_out=100;
    *Read_data=0;
    if(Addr & 0x400 !=0)/*429����*/
    {
        /*SET-ADDR*/
        gioSetBit(hetPORT1,PIN_HET_0,GetBit(Addr,0));   /*[A0]*/
        gioSetBit(hetPORT1,PIN_HET_1,GetBit(Addr,1));   /*[A1]*/
        gioSetBit(hetPORT1,PIN_HET_2,GetBit(Addr,2));   /*[A2]*/
        gioSetBit(hetPORT1,PIN_HET_3,GetBit(Addr,3));   /*[A3]*/
        gioSetBit(hetPORT1,PIN_HET_4,GetBit(Addr,4));   /*[A4]*/
        gioSetBit(hetPORT1,PIN_HET_5,GetBit(Addr,5));   /*[A5]*/
        can2_tx_SetBit(GetBit(Addr,6));                 /*[A6]*/
        gioSetBit(hetPORT1,PIN_HET_7,GetBit(Addr,7));   /*[A7]*/
        gioSetBit(hetPORT1,PIN_HET_8,GetBit(Addr,8));   /*[A8]*/
        gioSetBit(hetPORT1,PIN_HET_9,GetBit(Addr,9));   /*[A9]*/
        gioSetBit(hetPORT1,PIN_HET_28,GetBit(Addr,10)); /*[A10]*/
        gioSetBit(hetPORT1,PIN_HET_30,GetBit(Addr,11)); /*[A11]*/
        set_sdram_clk(HIGH);  /*��ȡ���ֽ�����*/
        set_sdram_cs(HIGH);  /*����ģʽΪ��ȡ����*/
        set_sdram_DWE(HIGH); /*DSP����׼����ɣ���֪FPGA��ȡ����*/
        time_out=100;
        while(Get_sdram_FWE()==LOW && time_out) /*�ȴ�DSP����׼�����*/
        {
            time_out--;
        }
        if(time_out==0)
        {
            set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
            return 0;
        }
        /*GET-DATA*/
        *Read_data |=((gioGetBit(gioPORTA, 2)>0)  ? 0x00010000:0);
        *Read_data |=((gioGetBit(gioPORTA, 5)>0)  ? 0x00020000:0);
        *Read_data |=((gioGetBit(gioPORTA, 6)>0)  ? 0x00040000:0);
        *Read_data |=((gioGetBit(gioPORTA, 7)>0)  ? 0x00080000:0);
        *Read_data |=((gioGetBit(hetPORT1, 26)>0) ? 0x00100000:0);
        *Read_data |=((gioGetBit(hetPORT1, 24)>0) ? 0x00200000:0);
        *Read_data |=((gioGetBit(hetPORT1, 22)>0) ? 0x00400000:0);
        *Read_data |=((gioGetBit(hetPORT1, 20)>0) ? 0x00800000:0);
        *Read_data |=((gioGetBit(hetPORT1, 18)>0) ? 0x01000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 16)>0) ? 0x02000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 15)>0) ? 0x04000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 14)>0) ? 0x08000000:0);
        *Read_data |=((get_sdram_DATA_A12()>0)    ? 0x10000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 12)>0) ? 0x20000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 11)>0) ? 0x40000000:0);
        *Read_data |=((gioGetBit(hetPORT1, 10)>0) ? 0x80000000:0);
        set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
    }
    /*SET-ADDR*/
    gioSetBit(hetPORT1,PIN_HET_0,GetBit(Addr,0));   /*[A0]*/
    gioSetBit(hetPORT1,PIN_HET_1,GetBit(Addr,1));   /*[A1]*/
    gioSetBit(hetPORT1,PIN_HET_2,GetBit(Addr,2));   /*[A2]*/
    gioSetBit(hetPORT1,PIN_HET_3,GetBit(Addr,3));   /*[A3]*/
    gioSetBit(hetPORT1,PIN_HET_4,GetBit(Addr,4));   /*[A4]*/
    gioSetBit(hetPORT1,PIN_HET_5,GetBit(Addr,5));   /*[A5]*/
    can2_tx_SetBit(GetBit(Addr,6));                 /*[A6]*/
    gioSetBit(hetPORT1,PIN_HET_7,GetBit(Addr,7));   /*[A7]*/
    gioSetBit(hetPORT1,PIN_HET_8,GetBit(Addr,8));   /*[A8]*/
    gioSetBit(hetPORT1,PIN_HET_9,GetBit(Addr,9));   /*[A9]*/
    gioSetBit(hetPORT1,PIN_HET_28,GetBit(Addr,10)); /*[A10]*/
    gioSetBit(hetPORT1,PIN_HET_30,GetBit(Addr,11)); /*[A11]*/
    set_sdram_clk(LOW);  /*��ȡ���ֽ�����*/
    set_sdram_cs(HIGH);  /*����ģʽΪ��ȡ����*/
    set_sdram_DWE(HIGH); /*DSP����׼����ɣ���֪FPGA��ȡ����*/
    time_out=100;
    while(Get_sdram_FWE()==LOW && time_out) /*�ȴ�DSP����׼�����*/
    {
        time_out--;
    }
    if(time_out==0)
    {
        set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
        return 0;
    }
    /*GET-DATA*/
    *Read_data |=((gioGetBit(gioPORTA, 2)>>0)  ? 0x00000001:0);
    *Read_data |=((gioGetBit(gioPORTA, 5)>>0)  ? 0x00000002:0);
    *Read_data |=((gioGetBit(gioPORTA, 6)>>0)  ? 0x00000004:0);
    *Read_data |=((gioGetBit(gioPORTA, 7)>>0)  ? 0x00000008:0);
    *Read_data |=((gioGetBit(hetPORT1, 26)>>0) ? 0x00000010:0);
    *Read_data |=((gioGetBit(hetPORT1, 24)>>0) ? 0x00000020:0);
    *Read_data |=((gioGetBit(hetPORT1, 22)>>0) ? 0x00000040:0);
    *Read_data |=((gioGetBit(hetPORT1, 20)>>0) ? 0x00000080:0);
    *Read_data |=((gioGetBit(hetPORT1, 18)>>0) ? 0x00000100:0);
    *Read_data |=((gioGetBit(hetPORT1, 16)>>0) ? 0x00000200:0);
    *Read_data |=((gioGetBit(hetPORT1, 15)>>0) ? 0x00000400:0);
    *Read_data |=((gioGetBit(hetPORT1, 14)>>0) ? 0x00000800:0);
    *Read_data |=((get_sdram_DATA_A12()>>0)    ? 0x00001000:0);
    *Read_data |=((gioGetBit(hetPORT1, 12)>>0) ? 0x00002000:0);
    *Read_data |=((gioGetBit(hetPORT1, 11)>>0) ? 0x00004000:0);
    *Read_data |=((gioGetBit(hetPORT1, 10)>>0) ? 0x00008000:0);
    set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
    return 1;
}

/**************************************
 * void SDRAM_Read(void)
 * ��FPGA��ȡ��������
 * ************************************/
void SDRAM_Read(void)
{
    unsigned char i=0;
    /*��ȡ����,FGPA�ɼ������ݺ�429�����Լ��԰�����*/
    for(i=0;i<SDRAM_READ_DATA_LEN;i++)
    {
         SDRAM_Read_Data(MCB_Data[i].Addr,&MCB_Data[i].value);
    }
    /*���½���FPGA��ȡ�������ݸ�ֵ���豸��״̬����*/
    for(i=0;i<SDRAM_READ_DATA_LEN;i++)
    {
        switch(MCB_Data[i].Addr)
        {
            case ADDR_INBD_LT_TEMP:
            {
                Receive_Machine_Parameters.INBD_LT_TEMP=MCB_Data[i].value;
            }
            break;
            case ADDR_INBD_RT_TEMP:
            {
                Receive_Machine_Parameters.INBD_RT_TEMP=MCB_Data[i].value;
            }
            break;
            case ADDR_INBD_LT_BPSI:
            {
                Receive_Machine_Parameters.INBD_LT_BPSI=MCB_Data[i].value;
            }
            break;
            case ADDR_INBD_RT_BPSI:
            {
                Receive_Machine_Parameters.INBD_RT_BPSI=MCB_Data[i].value;
            }
            break;
            case ADDR_LEFTPPEDAL:
            {
                Receive_Machine_Parameters.LeftPPedal.Value=MCB_Data[i].value;
            }
            break;
            case ADDR_RIGHTPPEDAL:
            {
                Receive_Machine_Parameters.RightPPedal.Value=MCB_Data[i].value;
            }
            break;
            case ADDR_LEFTCPEDAL:
            {
                Receive_Machine_Parameters.LeftCptPedal.Value=MCB_Data[i].value;
            }
            break;
            case ADDR_RIGHTCPEDAL:
            {
               Receive_Machine_Parameters.RightCptPedal.Value=MCB_Data[i].value;
            }
            break;
            case ADDR_INNER_WHEEL_ABS_START_SIGNAL:
            {
              // Receive_Machine_Parameters.=MCB_Data[i].value;
            }
            break;
            case ADDR_INBOARD_SHUTOFF_VALVE_CURRENT:
            {
               Receive_Machine_Parameters.Inboard_Shutoff_Valve_Current=MCB_Data[i].value;
            }
            break;
            case ADDR_LEFT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT:
            {
               Receive_Machine_Parameters.Left_Inboard_Brake_Control_Valve_Current=MCB_Data[i].value;
            }
            break;
            case ADDR_RIGHT_INBOARD_BRAKE_CONTROL_VALVE_CURRENT:
            {
               Receive_Machine_Parameters.Right_Inboard_Brake_Control_Valve_Current=MCB_Data[i].value;
            }
            break;
            case ADDR_LEFTWHEELSPEED:
            {
               Receive_Machine_Parameters.LeftWheelSpeed.Value=MCB_Data[i].value;
               Receive_Machine_Parameters.WheelSpeed_av=(Receive_Machine_Parameters.RightWheelSpeed.Value+Receive_Machine_Parameters.LeftWheelSpeed.Value)/2;
            }
            break;
            case ADDR_RIGHTWHEELSPEED:
            {
               Receive_Machine_Parameters.RightWheelSpeed.Value=MCB_Data[i].value;
               Receive_Machine_Parameters.WheelSpeed_av=(Receive_Machine_Parameters.RightWheelSpeed.Value+Receive_Machine_Parameters.LeftWheelSpeed.Value)/2;
            }
            break;
            case ADDR_AUTO_BRAKE_SW_SIGNAL:
            {
              Receive_Machine_Parameters.AutoBRK_OFF.Value=(MCB_Data[i].value >> 0) &0x01;
              Receive_Machine_Parameters.AutoBRK_LOW.Value=(MCB_Data[i].value >> 1) &0x01;
              Receive_Machine_Parameters.AutoBRK_MED.Value=(MCB_Data[i].value >> 2) &0x01;
              Receive_Machine_Parameters.AutoBRK_HI.Value=(MCB_Data[i].value >> 3) &0x01;
              Receive_Machine_Parameters.AutoBRK_RTO.Value=(MCB_Data[i].value >> 4) &0x01;
            }
            break;
            case ADDR_OTHER_SW_SIGNAL:
           {
               Receive_Machine_Parameters.RightWOW=Receive_Machine_Parameters.LeftWOW=(MCB_Data[i].value >> 0) &0x01;
               Receive_Machine_Parameters.SpoilerStoredSignal_Right=Receive_Machine_Parameters.SpoilerStoredSignal_Left=(MCB_Data[i].value >> 1) &0x01;
               Receive_Machine_Parameters.LeftThrottleIdle=Receive_Machine_Parameters.RightThrottleIdle=(MCB_Data[i].value >> 2) &0x01;
               Receive_Machine_Parameters.Inner_wheel_ABS_start_signal=(MCB_Data[i].value >> 3) &0x01;
               Receive_Machine_Parameters.Work_mode=(MCB_Data[i].value >> 4) &0x01;
               Receive_Machine_Parameters.spare=(MCB_Data[i].value >> 5) &0x01;
               Receive_Machine_Parameters.LandingGearExtentionandRetractionCommand=(MCB_Data[i].value >> 6) &0x01;
               Receive_Machine_Parameters.PIN_PGR_1=(MCB_Data[i].value >> 7) &0x01;
               Receive_Machine_Parameters.PIN_PGR_2=(MCB_Data[i].value >> 8) &0x01;
               Receive_Machine_Parameters.Parking_brake_signal=(MCB_Data[i].value >> 9) &0x01;
               Receive_Machine_Parameters.Master_Salve=(MCB_Data[i].value >> 4) &0x01;
           }
           break;
           default:
           {
               if(MCB_Data[i].Addr==ADDR_HYDRAULIC_SYSTEM_PRESSURE)
              {
                  Receive_Machine_Parameters.RX_429_Communication.Hydraulic_System_Pressure_1_60=(MCB_Data[i].value>>16)&0xfff;
              }
              else if(MCB_Data[i].Addr==ADDR_ACCUMULATOR_SYSTEM_PRESSURE)
              {
                 Receive_Machine_Parameters.RX_429_Communication.Accumulator_System_Pressure_1_126=(MCB_Data[i].value>>16)&0xfff;
              }
              else if(MCB_Data[i].Addr==ADDR_TLA_POSITION_LEFT)
              {
                  Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Left_133=((MCB_Data[i].value>>16)&0xfff)*0.00390652;
              }
              else if(MCB_Data[i].Addr==ADDR_TLA_POSITION_RIGHT)
              {
                  Receive_Machine_Parameters.RX_429_Communication.TLA_Position_Right_133=((MCB_Data[i].value>>16)&0xfff)*0.00390652;
              }
              else if(MCB_Data[i].Addr==ADDR_MASTER_TIME)
             {
                Receive_Machine_Parameters.RX_429_Communication.Master_Time_150=(MCB_Data[i].value>>11)&0x1ffff;
             }
             else if(MCB_Data[i].Addr==ADDR_AIRSPEED)
             {
                 Receive_Machine_Parameters.RX_429_Communication.Airspeed.Value=((MCB_Data[i].value>>14)&0x2fff)*0.0625;
             }
             else if(MCB_Data[i].Addr==ADDR_DATE_MASTER)
             {
                 Receive_Machine_Parameters.RX_429_Communication.Date_Master_260=(MCB_Data[i].value>>10)&0x7ffff;
             }
             else if(MCB_Data[i].Addr==ADDR_LG_GEARDOWN_LOCKED)
             {
               Receive_Machine_Parameters.RX_429_Communication.LG_GearDown_Locked=(MCB_Data[i].value>>10)&0x3ffff;
             }
             else if(MCB_Data[i].Addr==ADDR_COMPUTED_WOW_DATA1)
             {
                  Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_1_277=(MCB_Data[i].value>>10)&0xf;
             }
             else if(MCB_Data[i].Addr==ADDR_COMPUTED_WOW_DATA2)
             {
                Receive_Machine_Parameters.RX_429_Communication.Computed_WOW_Data_2_277=(MCB_Data[i].value>>10)&0xf;
             }
             else if(MCB_Data[i].Addr==ADDR_AIRCRAFTACCELERATION_LEFT)
             {
               Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration_Left.Value=((MCB_Data[i].value>>13)&0x7fff)*0.00012;
             }
             else if(MCB_Data[i].Addr==ADDR_AIRCRAFTACCELERATION_RIGHT)
             {
               Receive_Machine_Parameters.RX_429_Communication.AircraftAcceleration1_Right.Value=((MCB_Data[i].value>>13)&0x7fff)*0.00012;
             }
           }
           break;
           }
    }
}
/**************************************
 * void SDRAM_Set_IO_To_Write_Mode(void)
 * ��SDRAM��IO����Ϊдģʽ
 * ************************************/
void SDRAM_Set_IO_To_Write_Mode(void)
{
      /*��1�������IO������Ϊ�������ݵ�PFGA��ģʽ*/
      hetPORT1->DIR |=  0x0555DC00;      /*0NPUT--DATA:10-12 14-16 18 20 22 24 26*/
      gioPORTA->DIR |=  0X000000E4;      /*0NPUT--DATA:2 5 6 7*/
      canREG2->RIOC |=  0x00000004;        /*can2_Rx  0NPUT*/
}
/**************************************
 * void SDRAM_Write_Data(uint8_t Addr, uint16_t Data)
 * �������ݵ�FPGAָ����ַ
 *  �ɹ�����0��ʧ�ܷ���1��
 * ************************************/
uint8_t SDRAM_Write_Data(uint16_t Addr, uint32_t Data)
{
    uint16_t time_out=100;
    if(Addr & 0x400 !=0)/*429����*/
    {
        /*SET-ADDR*/
        gioSetBit(hetPORT1,PIN_HET_0,GetBit(Addr,0));   /*[A0]*/
        gioSetBit(hetPORT1,PIN_HET_1,GetBit(Addr,1));   /*[A1]*/
        gioSetBit(hetPORT1,PIN_HET_2,GetBit(Addr,2));   /*[A2]*/
        gioSetBit(hetPORT1,PIN_HET_3,GetBit(Addr,3));   /*[A3]*/
        gioSetBit(hetPORT1,PIN_HET_4,GetBit(Addr,4));   /*[A4]*/
        gioSetBit(hetPORT1,PIN_HET_5,GetBit(Addr,5));   /*[A5]*/
        can2_tx_SetBit(GetBit(Addr,6));                 /*[A6]*/
        gioSetBit(hetPORT1,PIN_HET_7,GetBit(Addr,7));   /*[A7]*/
        gioSetBit(hetPORT1,PIN_HET_8,GetBit(Addr,8));   /*[A8]*/
        gioSetBit(hetPORT1,PIN_HET_9,GetBit(Addr,9));   /*[A9]*/
        gioSetBit(hetPORT1,PIN_HET_28,GetBit(Addr,10)); /*[A10]*/
        gioSetBit(hetPORT1,PIN_HET_30,GetBit(Addr,11)); /*[A11]*/
        /*SET-DATA*/
        /*DSP����������д����*/
        gioSetBit(gioPORTA,2,GetBit(Data,16));           /*[D0]*/
        gioSetBit(gioPORTA,5,GetBit(Data,17));           /*[D1]*/
        gioSetBit(gioPORTA,6,GetBit(Data,18));           /*[D2]*/
        gioSetBit(gioPORTA,7,GetBit(Data,19));           /*[D3]*/
        gioSetBit(hetPORT1,PIN_HET_26,GetBit(Data,20));  /*[D4]*/
        gioSetBit(hetPORT1,PIN_HET_24,GetBit(Data,21));  /*[D5]*/
        gioSetBit(hetPORT1,PIN_HET_22,GetBit(Data,22));  /*[D6]*/
        gioSetBit(hetPORT1,PIN_HET_20,GetBit(Data,23));  /*[D7]*/
        gioSetBit(hetPORT1,PIN_HET_18,GetBit(Data,24));  /*[D8]*/
        gioSetBit(hetPORT1,PIN_HET_16,GetBit(Data,25));  /*[D9]*/
        gioSetBit(hetPORT1,PIN_HET_15,GetBit(Data,26)); /*[D10]*/
        gioSetBit(hetPORT1,PIN_HET_14,GetBit(Data,27)); /*[D11]*/
        set_sdram_DATA_A12(GetBit(Data,28));            /*[D12]*/
        gioSetBit(hetPORT1,PIN_HET_12,GetBit(Data,29)); /*[D13]*/
        gioSetBit(hetPORT1,PIN_HET_11,GetBit(Data,30)); /*[D14]*/
        gioSetBit(hetPORT1,PIN_HET_10,GetBit(Data,31)); /*[D15]*/
        set_sdram_clk(HIGH);  /*��ȡ���ֽ�����*/
        set_sdram_cs(LOW);  /*����ģʽΪ��ȡ����*/
        set_sdram_DWE(HIGH); /*DSP����׼����ɣ���֪FPGA��ȡ����*/
        time_out=100;
        while(Get_sdram_FWE()==LOW && time_out) /*�ȴ�DSP����׼�����*/
        {
            time_out--;
        }
        if(time_out==0)
        {
            set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
            return 0;
        }
        set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
    }
    /*SET-ADDR*/
    gioSetBit(hetPORT1,PIN_HET_0,GetBit(Addr,0));   /*[A0]*/
    gioSetBit(hetPORT1,PIN_HET_1,GetBit(Addr,1));   /*[A1]*/
    gioSetBit(hetPORT1,PIN_HET_2,GetBit(Addr,2));   /*[A2]*/
    gioSetBit(hetPORT1,PIN_HET_3,GetBit(Addr,3));   /*[A3]*/
    gioSetBit(hetPORT1,PIN_HET_4,GetBit(Addr,4));   /*[A4]*/
    gioSetBit(hetPORT1,PIN_HET_5,GetBit(Addr,5));   /*[A5]*/
    can2_tx_SetBit(GetBit(Addr,6));                 /*[A6]*/
    gioSetBit(hetPORT1,PIN_HET_7,GetBit(Addr,7));   /*[A7]*/
    gioSetBit(hetPORT1,PIN_HET_8,GetBit(Addr,8));   /*[A8]*/
    gioSetBit(hetPORT1,PIN_HET_9,GetBit(Addr,9));   /*[A9]*/
    gioSetBit(hetPORT1,PIN_HET_28,GetBit(Addr,10)); /*[A10]*/
    gioSetBit(hetPORT1,PIN_HET_30,GetBit(Addr,11)); /*[A11]*/
    /*SET-DATA*/
    /*DSP����������д����*/
    gioSetBit(gioPORTA,2,GetBit(Data,0));           /*[D0]*/
    gioSetBit(gioPORTA,5,GetBit(Data,1));           /*[D1]*/
    gioSetBit(gioPORTA,6,GetBit(Data,2));           /*[D2]*/
    gioSetBit(gioPORTA,7,GetBit(Data,3));           /*[D3]*/
    gioSetBit(hetPORT1,PIN_HET_26,GetBit(Data,4));  /*[D4]*/
    gioSetBit(hetPORT1,PIN_HET_24,GetBit(Data,5));  /*[D5]*/
    gioSetBit(hetPORT1,PIN_HET_22,GetBit(Data,6));  /*[D6]*/
    gioSetBit(hetPORT1,PIN_HET_20,GetBit(Data,7));  /*[D7]*/
    gioSetBit(hetPORT1,PIN_HET_18,GetBit(Data,8));  /*[D8]*/
    gioSetBit(hetPORT1,PIN_HET_16,GetBit(Data,9));  /*[D9]*/
    gioSetBit(hetPORT1,PIN_HET_15,GetBit(Data,10)); /*[D10]*/
    gioSetBit(hetPORT1,PIN_HET_14,GetBit(Data,11)); /*[D11]*/
    set_sdram_DATA_A12(GetBit(Data,12));            /*[D12]*/
    gioSetBit(hetPORT1,PIN_HET_12,GetBit(Data,13)); /*[D13]*/
    gioSetBit(hetPORT1,PIN_HET_11,GetBit(Data,14)); /*[D14]*/
    gioSetBit(hetPORT1,PIN_HET_10,GetBit(Data,15)); /*[D15]*/
    set_sdram_clk(LOW);  /*��ȡ���ֽ�����*/
    set_sdram_cs(LOW);  /*����ģʽΪ��ȡ����*/
    set_sdram_DWE(HIGH); /*DSP����׼����ɣ���֪FPGA��ȡ����*/
    time_out=100;
    while(Get_sdram_FWE()==LOW && time_out) /*�ȴ�DSP����׼�����*/
    {
        time_out--;
    }
    if(time_out==0)
    {
        set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
        return 0;
    }
    set_sdram_DWE(LOW); /*DSP��ȡ������ɣ���֪FPGA��ȡ�������*/
    return 1;
}

/**************************************
 * void SDRAM_Write(void)
 * �����������ݵ�FPGA
 * ************************************/
void SDRAM_Write(void)
{
    unsigned short i=0;
    /*�������豸�Ĳ����������͵�FPGA������*/
    for(i=SDRAM_READ_DATA_LEN;i<(SDRAM_WRITE_DATA_LEN+SDRAM_READ_DATA_LEN);i++)
    {
         switch(MCB_Data[i].Addr)
         {
             case ADDR_TEST_DAC_BCV_LT:
             {
                 MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_BCV_LT;
             }
             break;
             case ADDR_TEST_DAC_BCV_RT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_BCV_RT;
              }
              break;
             case ADDR_TEST_DAC_CV_LT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_CV_LT;
              }
              break;
             case ADDR_TEST_DAC_CV_RT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_CV_RT;
              }
              break;
             case ADDR_TEST_DAC_WHELL_SPEED_LT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_WHELL_SPEED_LT;
              }
              break;
             case ADDR_TEST_DAC_WHELL_SPEED_RT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_WHELL_SPEED_RT;
              }
              break;
             case ADDR_TEST_DAC_SOV:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_SOV;
              }
              break;
             case ADDR_TEST_DAC_PLT_LT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_PLT_LT;
              }
              break;
             case ADDR_TEST_DAC_PLT_RT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_PLT_RT;
              }
              break;
             case ADDR_TEST_DAC_CPLT_LT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_CPLT_LT;
              }
              break;
             case ADDR_TEST_DAC_CPLT_RT:
              {
                  MCB_Data[i].value=Transmit_Machine_Parameters.TEST_DAC_CPLT_RT;
              }
              break;
             case ADDR_SPINUP_SIGNAL:
            {
               MCB_Data[i].value=(Transmit_Machine_Parameters.INBD_LT_SPINUP>0 ? 0x01:0x00)| (Transmit_Machine_Parameters.INBD_RT_SPINUP>0 ? 0x02:0x00);
            }
            break;
            default:
            {
                 MCB_Data[i].value &=0x600003ff;
                 if( MCB_Data[i].Addr==ADDR_LEFT_WHEEL_SPEED)
                 {
                    MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Wheel_Speed_006/0.125)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_WHEEL_SPEED)
                 {
                     MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Wheel_Speed_007/0.125)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_LEFT_BRAKE_CONTROL_VALVE_CURENT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Control_Valve_Current_051/0.1)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_BRAKE_CONTROL_VALVE_CURENT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Control_Valve_Current_052/0.1)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_LEFT_BRAKE_PRESSURE)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Pressure_070)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_BRAKE_PRESSURE)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Pressure_071)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_SHUTOFF_VALVE_CURRENT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Inboard_Shutoff_Valve_Current_113)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_LEFT_BRAKE_TEMPERATURE)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Inboard_Brake_Temperature_114)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_BRAKE_TEMPERATURE)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Inboard_Brake_Temperature_116)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_LEFT_BRAKE_PEDAL_POSITION_PILOT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Brake_Pedal_Position_Pilot_171/0.01)&0xff)<<20;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_BRAKE_PEDAL_POSITION_PILOT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Brake_Pedal_Position_Pilot_172/0.01)&0xff)<<20;
                 }
                 else if( MCB_Data[i].Addr==ADDR_LEFT_BRAKE_PEDAL_POSITION_COPILOT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Left_Brake_Pedal_Position_Copilot_173/0.01)&0xff)<<20;
                 }
                 else if( MCB_Data[i].Addr==ADDR_RIGHT_BRAKE_PEDAL_POSITION_COPILOT)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.Right_Brake_Pedal_Position_Copilot_174/0.01)&0xff)<<20;
                 }
                 else if( MCB_Data[i].Addr==ADDR_WARNING)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Warning_270&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_STATUS_1)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Status_Word_1__271&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_STATUS_2)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Status_Word_2_272&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_BCU_AIRCRAFT_REFERENCE_SPEED)
                 {
                   MCB_Data[i].value |=((unsigned int)(Transmit_Machine_Parameters.TX_429_Communication.BCU_Aircraft_Reference_Speed_302/0.125)&0xfff)<<16;
                 }
                 else if( MCB_Data[i].Addr==ADDR_FAILURE_WORD_1)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_350&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_FAILURE_WORD_2)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_351&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_FAILURE_WORD_3)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_352&0x7ffff)<<10;
                 }
                 else if( MCB_Data[i].Addr==ADDR_FAILURE_WORD_4)
                 {
                   MCB_Data[i].value |=(Transmit_Machine_Parameters.TX_429_Communication.Failure_Word_1_353&0x7ffff)<<10;
                 }
                 MCB_Data[i].value |=(Get_Odd_value(MCB_Data[i].value)<<31);
            }
            break;

         }
    }
      /*���͵�ַ0x40--0x60������*/
    for(i=SDRAM_READ_DATA_LEN;i<(SDRAM_WRITE_DATA_LEN+SDRAM_READ_DATA_LEN);i++)
     {
        SDRAM_Write_Data(MCB_Data[i].Addr,MCB_Data[i].value);
     }
}

/*********************************
 * uint8_t GetBit(int data, int index)
 * �õ����ݵ�nλ��ֵ
 * ********************************/
uint8_t GetBit(int data, int index)
{
    return ((data & (1 << index)) > 0) ? 1: 0;
}
/***************************
 *void set_sdram_clk(uint8_t statue)
 * ����Clk�ź�(F2-HL)��1--���ֽڣ�0--���ֽڣ�
 * statue���źŸߵ�״̬
 * **************************/
void set_sdram_clk(uint8_t statue)
{
    if(statue==1)
    {
        mibspiREG5->PC3 |=0x00000200;
    }
    else
    {
        mibspiREG5->PC3 &=(~0x00000200);
    }
}

/***************************
 * uint8_t Get_sdram_FWE()
 * ��ȡFWE�ź�(FPGA_DR)
 * statue���źŸߵ�״̬
 * **************************/
uint8_t Get_sdram_FWE(void)
{
    uint16_t recv=0;
    recv=(uint16_t)((mibspiREG5->PC2) &0x00000400);
    return recv;
}
/***************************
 * uint16_t set_sdram_cs( void)
 * ����CS�ź�(RW)��1--����0--д��
 * ���أ��źŸߵ�״̬
 * **************************/
void set_sdram_cs(uint8_t statue)
{
    if(statue==1)
    {
        mibspiREG5->PC3 |=0x00000001;
    }
    else
    {
        mibspiREG5->PC3 &=(~0x00000001);
    }
}
/***************************
 * uint16_t set_sdram_DWE( void)
 * ����DWE�ź�(DSP_DR)
 * ���أ��źŸߵ�״̬
 * **************************/
void set_sdram_DWE(uint8_t statue)
{
    if(statue==1)
    {
        mibspiREG5->PC3 |=0x00000800;
    }
    else
    {
        mibspiREG5->PC3 &=(~0x00000800);
    }
}
/***************************
 * uint16_t get_sdram_DATA_A12( void)
 * ��ȡ������ 12�ź�״̬
 * ���أ��źŸߵ�״̬
 * **************************/
uint16_t get_sdram_DATA_A12( void)
{
   uint16_t recv=0;
   recv=(uint16_t)((canREG2->RIOC) &0x00000001);
   return recv;
}

/***************************
 * void set_sdram_DATA_A12(uint8_t statue)
 * ���������� 12�ź�
 * statue���źŸߵ�״̬
 * **************************/
void set_sdram_DATA_A12(uint8_t statue)
{
    if(statue==0)
    {
       canREG2->RIOC &=(~0x00000002);
    }
    else
    {
        canREG2->RIOC |=0x00000002;
    }
}
/***************************
 * void can2_tx_SetBit(uint8_t statue)
 * ����CAN2 Tx�ź�
 * statue���źŸߵ�״̬
 * **************************/
void can2_tx_SetBit(uint8_t statue)
{
   if(statue==0)
    {
       canREG2->TIOC &=(~0x00000002);
    }
    else
    {
        canREG2->TIOC |=0x00000002;
    }
}


unsigned char Get_Odd_value(unsigned int data)
{
    unsigned char i=0;
    unsigned char num=0;
    for(i=0;i<31;i++)
    {
        if(((data>>i)&0x0001)==0x0001)
        {
            num++;
        }
    }
    if(num%2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}