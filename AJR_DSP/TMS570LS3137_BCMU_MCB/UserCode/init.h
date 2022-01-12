/*
 * init.h
 *
 *  Created on: 2022��1��5��
 *      Author: 15755
 */

#ifndef USERCODE_INIT_H_
#define USERCODE_INIT_H_

extern unsigned short Board_ID;
extern unsigned short SDRAM_READ_DATA_LEN;
extern unsigned short SDRAM_WRITE_DATA_LEN;


void initialization(void);
void device_status_init(void);
void SD_GPIO_Init(void);
#endif /* USERCODE_INIT_H_ */
