/*
 * rs422.h
 *
 *  Created on: 2021��7��3��
 *      Author: 15755
 */

#ifndef USERCODE_RS232_H_
#define USERCODE_RS232_H_

#include"stdint.h"

extern uint8_t temp_Recive_buf[10];
extern uint8_t rs232_recive_len;
void RS232Init(void);
void RS232_Send(uint32_t length, uint8_t * data);
uint8_t CRC_AND(uint8_t * buff,uint16_t data_len);
#endif /* USERCODE_RS232_H_ */
