/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_ARMtoEnable.h"

#ifndef KCG_USER_DEFINED_INIT
void Autobrake_ARMtoEnable_init(outC_Autobrake_ARMtoEnable *outC)
{
  outC->LandingEnable = kcg_true;
  outC->rem_WOW_BRK = kcg_true;
  outC->init = kcg_true;
  /* 1 */ Counter_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Autobrake_ARMtoEnable_reset(outC_Autobrake_ARMtoEnable *outC)
{
  outC->init = kcg_true;
  /* 1 */ Counter_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Autobrake_ARMtoEnable */
void Autobrake_ARMtoEnable(
  /* Autobrake_ARMtoEnable::WOW_BRK */ kcg_bool WOW_BRK,
  /* Autobrake_ARMtoEnable::Wheel_speed_av */ kcg_float32 Wheel_speed_av,
  outC_Autobrake_ARMtoEnable *outC)
{
  /* Autobrake_ARMtoEnable */ kcg_bool tmp;

  /* fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp = !WOW_BRK;
  }
  else {
    tmp = !outC->rem_WOW_BRK;
  }
  /* 1 */ Counter((kcg_bool) (WOW_BRK & tmp), &outC->Context_1);
  outC->LandingEnable = (outC->Context_1.count >= kcg_lit_int32(400)) &
    (Wheel_speed_av > Brakespeed);
  outC->rem_WOW_BRK = WOW_BRK;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_ARMtoEnable.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

