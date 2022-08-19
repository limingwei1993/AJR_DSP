/*
 * rs422.c
 *
 *  Created on: 2021年7月3日
 *      Author: 15755
 */

#include "user_main.h"
uint8_t temp_Recive_buf[10]={0}; /*保存接收到的数据*/
uint8_t rs232_recive_len=0;     /*保存接收到的数据的位置*/
/**************************
 * void RS232_Send(uint32_t length, uint8_t * data)
 * RS232 发送数据
 * length：发送数据的长度
 * *data： 发送的数据地址
 * ****************************/
void RS232_Send(uint32_t length, uint8_t * data)
{
        uint8 txdata;
        /* send the data */
        while (length > 0U)
        {
            /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
            while ((sciREG->FLR & (uint32)SCI_TX_INT) == 0U)
            {
            } /* Wait */
            /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
            txdata = *data;
            sciREG->TD = (uint32)(txdata);
            /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
            /*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Pointer increment needed" */
            data++;
            length--;
        }
}

/*******************************************************************************
Function:       // sciNotification
Description:    // UART interrupt handler
Input:          // sci : hardware UART module trigger the interrupt.
                // flags  : flags in UART module which trigger the interrupt
Output:         // none
*******************************************************************************/
void sciNotification(sciBASE_t *sci, uint32 flags)
{
    uint8_t revice_data=0;
    if (sci == sciREG)
    {
        if (flags == SCI_RX_INT)
        {
            revice_data=(uint8)(sciREG->RD & 0x000000FFU);
            if(rs232_recive_len==0 && revice_data==0xaa)
            {
                temp_Recive_buf[0]=revice_data;
                rs232_recive_len++;
            }
            else if(rs232_recive_len>0)
            {
                temp_Recive_buf[rs232_recive_len]=revice_data;
                rs232_recive_len++;
                if(rs232_recive_len>=8)
                {
                   if( CRC_AND(&temp_Recive_buf[1],5)==temp_Recive_buf[6])
                   {
                       RS232_Process(temp_Recive_buf);
                   }
                   rs232_recive_len=0;
                }
            }

        }
    }
}

/*******************************************************************************
Function:       // CRC_AND
Description:    // CRC and verification
Input:          // buff : Verified data
                // data_len  : data length
Output:         // Verification results
*******************************************************************************/
uint8_t CRC_AND(uint8_t * buff,uint16_t data_len)
{
    uint8_t data=0;
    uint16_t i=0;
    for(i=0;i<data_len;i++)
    {
        data+=buff[i];
    }
    return data;
}

extern float temp_value_right;
extern float temp_value_left;
extern unsigned short BSPI_Value_l[20];
extern unsigned short BSPI_Value_r[20];
/*******************************************************************************
Function:       // Send_Test_Message
Description:    // In test mode, the collected data is sent through the serial port
Input:          // none
Output:         // none
*******************************************************************************/
void Send_Test_Message(void)
{
   uint8_t frame_buff[100]={0};
   uint8_t i=0;
   uint8_t k=0;
   uint8_t j=0;
   uint16_t frame_len=0;
   uint16_t len=0;
   uint32_t test_bspi=0;
   uint16_t test_tem=0;
   frame_buff[frame_len++]=0xaa;
   frame_buff[frame_len++]=0x0f;
   frame_buff[frame_len++]=0;
   /**/
   frame_buff[frame_len++]=(uint16_t)(temp_value_left)&0xff;
   frame_buff[frame_len++]=((uint16_t)(temp_value_left)>>8)&0xff;
   frame_buff[frame_len++]=(uint16_t)(temp_value_right)&0xff;
   frame_buff[frame_len++]=((uint16_t)(temp_value_right)>>8)&0xff;
//   test_bspi=0;
//   for(i=0;i<PSI_LEN;i++)
//   {
//       test_bspi+=BSPI_Value_l[i];
//   }
//   test_bspi=test_bspi/PSI_LEN;
//   test_bspi=test_bspi-test_bspi/40;
//   frame_buff[frame_len++]=(uint16_t)(test_bspi)&0xff;
//   frame_buff[frame_len++]=((uint16_t)(test_bspi)>>8)&0xff;
//   test_bspi=0;
//   for(i=0;i<PSI_LEN;i++)
//   {
//      test_bspi+=BSPI_Value_r[i];
//   }
//   test_bspi=test_bspi/PSI_LEN;
//   test_bspi=test_bspi-test_bspi/40;
//   frame_buff[frame_len++]=(uint16_t)(test_bspi)&0xff;
//   frame_buff[frame_len++]=((uint16_t)(test_bspi)>>8)&0xff;

   for(k=0;k<PSI_LEN-1;++k)
   {
       for(j=0;j<PSI_LEN-k-1;++j)
       {
           if(BSPI_Value_l[j]>BSPI_Value_l[j+1])
           {
               test_tem=BSPI_Value_l[j];
               BSPI_Value_l[j]=BSPI_Value_l[j+1];
               BSPI_Value_l[j+1]=test_tem;
           }
       }
   }
   frame_buff[frame_len++]=(uint16_t)(BSPI_Value_l[PSI_LEN/2])&0xff;
   frame_buff[frame_len++]=((uint16_t)(BSPI_Value_l[PSI_LEN/2])>>8)&0xff;
   for(k=0;k<PSI_LEN-1;++k)
     {
         for(j=0;j<PSI_LEN-k-1;++j)
         {
             if(BSPI_Value_r[j]>BSPI_Value_r[j+1])
             {
                 test_tem=BSPI_Value_r[j];
                 BSPI_Value_r[j]=BSPI_Value_r[j+1];
                 BSPI_Value_r[j+1]=test_tem;
             }
         }
     }
     frame_buff[frame_len++]=(uint16_t)(BSPI_Value_r[PSI_LEN/2])&0xff;
     frame_buff[frame_len++]=((uint16_t)(BSPI_Value_r[PSI_LEN/2])>>8)&0xff;
  // frame_buff[frame_len++]=(uint16_t)(temp_value_right)&0xff;
  // frame_buff[frame_len++]=((uint16_t)(temp_value_right)>>8)&0xff;

   /**/
   for(i=4;i<14;i++) //0   //2
   {
       frame_buff[frame_len++]=(uint8_t)MCB_Data[i].value&0xff;
       frame_buff[frame_len++]=(uint8_t)(MCB_Data[i].value>>8)&0xff;
   }
   frame_buff[frame_len++]=(uint8_t)MCB_Data[14].value&0xff;
   frame_buff[frame_len++]=(uint8_t)MCB_Data[15].value&0xff;
   frame_buff[frame_len++]=(uint8_t)(MCB_Data[15].value>>8)&0xff;
   frame_buff[frame_len++]=device_status.Bench_Mode | (device_status.Master_Salve_mode<<1);
   frame_buff[2]=frame_len-3;
   len=frame_len-1;
   frame_buff[frame_len++]=CRC_AND(&frame_buff[1],len);
   frame_buff[frame_len++]=0x55;
   RS232_Send(frame_len, frame_buff);
}
