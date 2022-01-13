#ifndef __GLOBAL_INIT_H_
#define __GLOBAL_INIT_H_

#include "sys_common.h"

/* These types must be 16-bit, 32-bit or larger integer */
typedef int             INT;
typedef unsigned int    UINT;

/* These types must be 8-bit integer */
typedef signed char     CHAR;
typedef unsigned char   UCHAR;
typedef unsigned char   BYTE;

/* These types must be 16-bit integer */
typedef short           SHORT;
typedef unsigned short  USHORT;
typedef unsigned short  WORD;

/* These types must be 32-bit integer */
typedef long            LONG;
typedef unsigned long   ULONG;

typedef uint16_t        WCHAR;  /* 16-bit unsigned integer */
typedef uint32_t        DWORD;  /* 32-bit unsigned integer */
typedef uint64_t        QWORD;  /* 64-bit unsigned integer */

/* Boolean type */
typedef bool BOOL;

enum eCtlCmd
{
    Clear_ZeroScale   = 0x05000000,//Clear to zero scale
    Clear_MidScale    = 0x05000001,//Clear to mid scale
    Clear_FullScale   = 0x05000020,//Clear to full-scale
    Vref2_5_PowerUp   = 0x090A0000,//Internal Reference always powered on
    Vref2_5_PowerDown = 0x09000000,//Internal Reference always powered down
    Reset_Software    = 0x07000000,//Software reset
};

/*static uint16_t SndCmd[9]={
                        0x0300,  //Write to input register - DAC Channel A
                        0x0310,  //Write to input register - DAC Channel B
                        0x0320,  //Write to input register - DAC Channel C
                        0x0330,  //Write to input register - DAC Channel D
                        0x0340,  //Write to input register - DAC Channel E
                        0x0350,  //Write to input register - DAC Channel F
                        0x0360,  //Write to input register - DAC Channel G
                        0x0370,  //Write to input register - DAC Channel H
                        0x03F0,};//Write to input register - DAC Channel Cycle read A-H*/

enum CHANNEL
{
    CHANNELA    = 0x0300,
    CHANNELB    = 0x0310,
    CHANNELC    = 0x0320,
    CHANNELD    = 0x0330,
    CHANNELfull = 0x03F0,
};


/*=========================== sys_H ================================*/
#include "het.h"
#include "gio.h"
#include "spi.h"
#include "sci.h"
#include "het.h"
#include "rti.h"
#include "pinmux.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*============================ user_H ==============================*/
#include "user_main.h"
#include "sdcard.h"
#include "ff.h"
#include "ffconf.h"
#include "diskio.h"
#include "sdram.h"
#include <rs232.h>
#include "dac5689.h"
extern void delay_ns(uint32_t ns);
extern void delay_ms(uint32_t ms);
extern void delay_us(uint32_t us);

#endif /* __GLOBAL_INIT_H_ */
