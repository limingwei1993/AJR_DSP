/*
 * SD_card.h
 *
 *  Created on: 2022Äê1ÔÂ11ÈÕ
 *      Author: 15755
 */

#ifndef USERCODE_SD_CARD_H_
#define USERCODE_SD_CARD_H_
#include "ff.h"

extern FIL file;
extern FATFS fs;
extern SdCardStatus sd_card_status;


void SdCard_Maintenance(void);
void Write_Coll_message_Into_SD(void);
#endif /* USERCODE_SD_CARD_H_ */
