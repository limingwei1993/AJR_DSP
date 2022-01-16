/*
 * test.h
 *
 *  Created on: 2022Äê1ÔÂ12ÈÕ
 *      Author: 15755
 */

#ifndef USERCODE_TEST_H_
#define USERCODE_TEST_H_
#define ENTER_DBUG   0X00
#define WRITE_DATA   0X01
#define READ_DATA    0X02
#define QUIT_DBUG    0XFF
#define SD_TEST_LEN   1279
#define SD_WRITE     1
#define SD_READ      0
void Write_Data_Process(uint16_t Addr,uint16_t value);
void Read_Data_Process(uint16_t Addr,uint16_t value);
void SD_Process(uint8_t Read_Write,uint16_t value);
void RS232_Process(uint8_t *frame_data);
void Test_Sdram_Data_Process(void);
void TEST_SDRAM_Write(void);
#endif /* USERCODE_TEST_H_ */
