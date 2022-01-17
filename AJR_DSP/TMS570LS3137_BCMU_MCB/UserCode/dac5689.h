/*
  ******************************************************************************
  * @file    dac5689.h
  * @author  Liaot
  * @version V1.0.0
  * @date    2020-06-10
  */
#ifndef __DAC5689_H_
#define __DAC5689_H_
#include "delay.h"
#include "spi.h"

#define REG_WRITE_TO_INPUTREG               0x100000    //Command 1: Write to input register n (LDAC dependent)
#define REG_UPDATE_DACREG_WITH_INPUTREG     0x200000    //Command 2: Update DAC register with Input register
#define REG_WRITE_UPDATE_DAC_CHANNEL        0x300000    //Command 3: Write and update DAC channel n
#define REG_POWERDOWN_UP                    0x400000    //Command 4: Powerdown/Powerup DAC
#define REG_HARDWARE_LDAC_MASK              0x500000    //Command 5: Hardware LDAC mask register
#define REG_SOFTWARE_RESET                  0x600000    //Command 6: Software reset(Power-on Reset)
#define REG_INTERNAL_REFERENCE              0x700000    //Command 7: Internal Reference Setup register
#define REG_DCEN                            0x800000    //Command 8: Setup DCEN register(Daisy Chain Enable)
#define REG_READBACK                        0x900000    //Command 9: Setup readback register(Readback enable)

//DAC SELECTION ADDRESS BITS
#define DAC_R   0x010000    // Selects DAC A
#define DAC_L   0x080000    // Selects DAC B
#define DAC_ALL 0x090000    // Selects DAC A and DAC B

//Daisy Chain Enable REGISTER
#define DAISY_STANDALONE    0X000000    //Standalone mode
#define DAISY_DCEN_MODE     0X000001    //Daisy Chain mode

//INTERNAL REFERENCE
#define INTREF_ON    0X000000     // Turns Internal Reference ON
#define INTREF_OFF   0X000001     // Turns Internal Reference OFF

//LDAC MASK REGISTER(for software purpose only)
#define LDAC_RESPOND_DACA_DACB           0X000000  //Responds to LDAC pin of both DAC A and DAC B
#define LDAC_IGNORE_DACA_RESPOND_DACB    0X000001  //Ignores LDAC pin of DAC A and responds to DAC B
#define LDAC_RESPOND_DACA_IGNORE_DACB    0X000008  //Responds to LDAC pin of DAC A and ignores to DAC B
#define LDAC_IGNORE_DACA_DACB            0X000009  //Ignores the transitions in LDAC pin of both DAC A and DAC B

//POWERDOWN REGISTER
#define PD_DACA_NORMALMODE     0X00000C   //Puts DAC A in normal mode
#define PD_DACA_1K_TO_GND      0X00000D   //Puts DAC A in powerdown mode: 1k to GND
#define PD_DACA_100K_TO_GND    0X00000E   //Puts DAC A in powerdown mode: 100k to GND
#define PD_DACA_THREE_STATE    0X00000F   //Puts DAC A in powerdown mode: Three state

#define PD_DACB_NORMALMODE     0X000030   //Puts DAC B in normal mode
#define PD_DACB_1K_TO_GND      0X000070   //Puts DAC B in powerdown mode: 1k to GND
#define PD_DACB_100K_TO_GND    0X0000B0   //Puts DAC B in powerdown mode: 100k to GND
#define PD_DACB_THREE_STATE    0X0000F0   //Puts DAC B in powerdown mode: Three state

#define NO_OF_BYTES 0x03 //Size of Register in Bytes

extern void DAC5689_Init(void);
extern void WriteData(unsigned int commandmode, unsigned int DACselect, unsigned int Data);
extern void WriteRegister(unsigned long int WriteData);
extern void SpiReadWrite(unsigned char *InBuf, unsigned char *OutBuf, unsigned char NoOfBytes);
extern void UpdateDacReg(unsigned int DACselect);
extern void DAC5689_SetVoltage_mv(unsigned int DACselect, unsigned int Voltage);

#endif /* __GLOBAL_INIT_H_ */


