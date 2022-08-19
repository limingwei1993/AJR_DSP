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

extern short temp_value_right;
extern short temp_value_left;
/*******************************************************************************
Function:       // Send_Test_Message
Description:    // In test mode, the collected data is sent through the serial port
Input:          // none
Output:         // none
*******************************************************************************/
void Send_Test_Message(void)
{
   uint8_t frame_buff[200]={0};
   uint8_t i=0;
   uint16_t frame_len=0;
   uint16_t len=0;
   frame_buff[frame_len++]=0xaa;
   frame_buff[frame_len++]=0x0f;
   frame_buff[frame_len++]=0;
   /**/
   frame_buff[frame_len++]=(uint16_t)(temp_value_left)&0xff;
   frame_buff[frame_len++]=((uint16_t)(temp_value_left)>>8)&0xff;
   frame_buff[frame_len++]=(uint16_t)(temp_value_right)&0xff;
   frame_buff[frame_len++]=((uint16_t)(temp_value_right)>>8)&0xff;
   /**/
   for(i=2;i<14;i++) //0   //2
   {
       frame_buff[frame_len++]=(uint8_t)MCB_Data[i].value&0xff;
       frame_buff[frame_len++]=(uint8_t)(MCB_Data[i].value>>8)&0xff;
   }
   frame_buff[frame_len++]=(uint8_t)MCB_Data[14].value&0xff;
   frame_buff[frame_len++]=(uint8_t)MCB_Data[15].value&0xff;
   frame_buff[frame_len++]=(uint8_t)(MCB_Data[15].value>>8)&0xff;
   frame_buff[frame_len++]=device_status.Bench_Mode | (device_status.Master_Salve_mode<<1);
   /*New_add_start*/
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_L)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_L)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_L)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_L)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_R)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_R)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_R)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.BrakePressureCommand_R)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftPDL_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftPDL_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftPDL_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftPDL_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightPDL_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightPDL_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightPDL_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightPDL_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftBrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftBrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftBrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftBrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightBrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightBrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightBrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightBrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftIFB_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftIFB_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftIFB_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.LeftIFB_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightIFB_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightIFB_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightIFB_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.RightIFB_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Left_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Left_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Left_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Left_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Right_BrakePressureCommand)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Right_BrakePressureCommand)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Right_BrakePressureCommand)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.Right_BrakePressureCommand)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.maxpedal)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.maxpedal)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.maxpedal)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(Transmit_Machine_Parameters.maxpedal)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.LeftBrakePressureCommandAdj)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.LeftBrakePressureCommandAdj)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.LeftBrakePressureCommandAdj)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.LeftBrakePressureCommandAdj)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.RightBrakePressureCommandAdj)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.RightBrakePressureCommandAdj)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.RightBrakePressureCommandAdj)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.RightBrakePressureCommandAdj)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.Ratio)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.Ratio)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.Ratio)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.BrakeSkidOut.Ratio)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelSpeed.Value)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelSpeed.Value)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelSpeed.Value)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelSpeed.Value)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelSpeed.Value)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelSpeed.Value)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelSpeed.Value)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelSpeed.Value)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelRefSpeed.Value)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelRefSpeed.Value)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelRefSpeed.Value)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LeftWheelRefSpeed.Value)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelRefSpeed.Value)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelRefSpeed.Value)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelRefSpeed.Value)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.RightWheelRefSpeed.Value)>>24)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LWP_RefSpeed.Value)>>0)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LWP_RefSpeed.Value)>>8)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LWP_RefSpeed.Value)>>16)&0xff;
   frame_buff[frame_len++]=((uint32_t)(test_outC.Output.speed.LWP_RefSpeed.Value)>>24)&0xff;
   frame_buff[frame_len++]=Transmit_Machine_Parameters.SOV_Open | (Transmit_Machine_Parameters.CoilEnergized<<1) | (Transmit_Machine_Parameters.LandingArmedState<<2) | \
           (Transmit_Machine_Parameters.LandingApplicationState<<3) | (Transmit_Machine_Parameters.LandingEnabledState<<4) | (Transmit_Machine_Parameters.LandingDisArmedState<<5) | \
           (Transmit_Machine_Parameters.RTOArmedState<<6) | (Transmit_Machine_Parameters.RTOEnabledState<<7);
   frame_buff[frame_len++]=Transmit_Machine_Parameters.RTODisarmedState | (Transmit_Machine_Parameters.RTOApplicationState<<1) | (Transmit_Machine_Parameters.OFFState<<2) | \
             (Transmit_Machine_Parameters.AUTOBRKfault<<3) | (Transmit_Machine_Parameters.ARMdisagree<<4) | (Transmit_Machine_Parameters.latch<<5) | \
             (Transmit_Machine_Parameters.unlatch<<6) | (Transmit_Machine_Parameters.WOWBK<<7);
   frame_buff[frame_len++]=Transmit_Machine_Parameters.WOW429 | (Transmit_Machine_Parameters.TDP_BrakeInhibit<<1) | (Transmit_Machine_Parameters.LWP_LeftBrakeInhibit<<2) | \
                (Transmit_Machine_Parameters.LWP_RightBrakeInhibit<<3) | (test_outC.Output.BrakeSkidOut.LeftSkidEnable<<4) | (test_outC.Output.BrakeSkidOut.RightSkidEnable<<5);
   /*New_add_end*/
   frame_buff[2]=frame_len-3;
   len=frame_len-1;
   frame_buff[frame_len++]=CRC_AND(&frame_buff[1],len);
   frame_buff[frame_len++]=0x55;
   RS232_Send(frame_len, frame_buff);
}
