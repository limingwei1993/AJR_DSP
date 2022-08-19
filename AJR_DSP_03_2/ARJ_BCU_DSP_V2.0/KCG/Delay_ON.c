/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Delay_ON.h"

#ifndef KCG_USER_DEFINED_INIT
void Delay_ON_init(outC_Delay_ON *outC)
{
  outC->Output1 = kcg_true;
  /* 1 */ Counter_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Delay_ON_reset(outC_Delay_ON *outC)
{
  /* 1 */ Counter_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Delay_ON */
void Delay_ON(
  /* Delay_ON::Input1 */ kcg_bool Input1,
  /* Delay_ON::cycles */ kcg_int32 cycles,
  outC_Delay_ON *outC)
{
  /* 1 */ Counter(Input1, &outC->Context_1);
  outC->Output1 = outC->Context_1.count >= cycles;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Delay_ON.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

