/*
 * SD_card.c
 *
 *  Created on: 2022��1��11��
 *      Author: 15755
 */
#include "ff.h"
FIL file;
FATFS fs;
SdCardStatus sd_card_status;
void SdCardProcess(void)
{
  unsigned char num_init = 10;
  if(get_SD_card_online_status() == 1)
  {
    if(sd_card_status == Fatfs_Load_Success)
    {
      f_mount(0, "0:", 1); /*Unload Fatfs*/
    }
    else if(sd_card_status == File_Open_Success)
    {
      f_close(&file);
      f_mount(0, "0:", 1); /*Unload Fatfs*/
    }
    sd_card_status = NO_Card_Insert;
  }
  else
  {
    switch(sd_card_status)
    {
      case NO_Card_Insert:
        sd_card_status = Card_Insert;
        break;
      case Card_Insert:
        do
        {
          num_init--;
        }while(SD_Init() != SD_OK && num_init > 0);
        if(num_init > 0)
        {
          sd_card_status = Card_Init_Success;
        }
        break;
      case Card_Init_Success:
        do                                          /*Load  Fatfs*/
        {
          num_init--;                               /* Mount a logical drive*/
        } while (f_mount(&fs, "0:", 1) != FR_OK && num_init > 0);
        if(num_init > 0)
        {
          sd_card_status = Fatfs_Load_Success;
        }
        break;
      default:
        break;
    }
  }
}