/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_EnaletoApplication.h"

#ifndef KCG_USER_DEFINED_INIT
void Autobrake_EnaletoApplication_init(outC_Autobrake_EnaletoApplication *outC)
{
  outC->LandingApplication = kcg_true;
  /* 1 */ Delay_ON_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Autobrake_EnaletoApplication_reset(outC_Autobrake_EnaletoApplication *outC)
{
  /* 1 */ Delay_ON_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Autobrake_EnaletoApplication */
void Autobrake_EnaletoApplication(
  /* Autobrake_EnaletoApplication::Idle_Position_Discrete_R */ kcg_bool Idle_Position_Discrete_R,
  /* Autobrake_EnaletoApplication::dle_Position_Discrete_L */ kcg_bool dle_Position_Discrete_L,
  outC_Autobrake_EnaletoApplication *outC)
{
  /* 1 */
  Delay_ON(
    (kcg_bool) !(Idle_Position_Discrete_R & dle_Position_Discrete_L),
    kcg_lit_int32(600),
    &outC->Context_1);
  outC->LandingApplication = outC->Context_1.Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_EnaletoApplication.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

