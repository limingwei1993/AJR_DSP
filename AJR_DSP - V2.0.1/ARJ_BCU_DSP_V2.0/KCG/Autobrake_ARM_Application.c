/* $******* SCADE Suite KCG 32-bit 6.6.1 beta (build i1) ********
** Command: kcg661.exe -config D:/Software/professional/ANSYS Inc/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-09-18T10:46:44
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_ARM_Application.h"

/* Autobrake_ARM_Application/ */
void Autobrake_ARM_Application(
  /* WOW_BRK/, _L1/ */
  kcg_bool WOW_BRK,
  /* Idle_Position_Discrete_R/, _L3/ */
  kcg_bool Idle_Position_Discrete_R,
  /* _L4/, dle_Position_Discrete_L/ */
  kcg_bool dle_Position_Discrete_L,
  /* WOW_NLG_HARD/, _L5/ */
  kcg_bool WOW_NLG_HARD,
  /* Wheel_speed_av/, _L6/ */
  kcg_float32 Wheel_speed_av,
  outC_Autobrake_ARM_Application *outC)
{
  kcg_bool tmp;

  /* _L14= */
  if (outC->init) {
    outC->init = kcg_false;
    tmp = !WOW_BRK;
  }
  else {
    tmp = !outC->mem_WOW_BRK;
  }
  /* _L10=(Counter#1)/ */
  Counter((kcg_bool) (WOW_BRK & tmp), &outC->Context_Counter_1);
  outC->LandingApplication = (outC->Context_Counter_1.count >= kcg_lit_int32(
        400)) & Idle_Position_Discrete_R & dle_Position_Discrete_L &
    WOW_NLG_HARD & (Wheel_speed_av > Brakespeed);
  outC->mem_WOW_BRK = WOW_BRK;
}

#ifndef KCG_USER_DEFINED_INIT
void Autobrake_ARM_Application_init(outC_Autobrake_ARM_Application *outC)
{
  outC->LandingApplication = kcg_true;
  outC->mem_WOW_BRK = kcg_true;
  outC->init = kcg_true;
  /* _L10=(Counter#1)/ */ Counter_init(&outC->Context_Counter_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Autobrake_ARM_Application_reset(outC_Autobrake_ARM_Application *outC)
{
  outC->init = kcg_true;
  /* _L10=(Counter#1)/ */ Counter_reset(&outC->Context_Counter_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $******* SCADE Suite KCG 32-bit 6.6.1 beta (build i1) ********
** Autobrake_ARM_Application.c
** Generation date: 2021-09-18T10:46:44
*************************************************************$ */

