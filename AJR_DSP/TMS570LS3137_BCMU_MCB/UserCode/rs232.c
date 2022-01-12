/*
 * rs422.c
 *
 *  Created on: 2021��7��3��
 *      Author: 15755
 */

#include "sci.h"
#include "rs232.h"
#include "Device_control.h"
uint8_t temp_Recive_buf[10]={0}; /*������յ�������*/
uint8_t rs232_recive_len=0; /*������յ������ݵ�λ��*/
/**************************
 * void RS232_Send(uint32_t length, uint8_t * data)
 * RS232 ��������
 * length���������ݵĳ���
 * *data�� ���͵����ݵ�ַ
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
                temp_Recive_buf[0]=revice_data;
                rs232_recive_len++;
                if(rs232_recive_len>=8)
                {
                   if( CRC_AND(temp_Recive_buf,6)==temp_Recive_buf[7])
                   {
                       RS232_Process(temp_Recive_buf);
                   }
                   rs232_recive_len=0;
                }
            }

        }
        else if (flags == SCI_TX_INT)
        {
        }
        else
        {
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