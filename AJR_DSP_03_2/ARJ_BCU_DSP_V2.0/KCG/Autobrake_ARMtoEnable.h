/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Autobrake_ARMtoEnable_H_
#define _Autobrake_ARMtoEnable_H_

#include "kcg_types.h"
#include "Counter.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Autobrake_ARMtoEnable::LandingEnable */ LandingEnable;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Autobrake_ARMtoEnable::WOW_BRK */ rem_WOW_BRK;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Counter /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Autobrake_ARMtoEnable;

/* ===========  node initialization and cycle functions  =========== */
/* Autobrake_ARMtoEnable */
extern void Autobrake_ARMtoEnable(
  /* Autobrake_ARMtoEnable::WOW_BRK */ kcg_bool WOW_BRK,
  /* Autobrake_ARMtoEnable::Wheel_speed_av */ kcg_float32 Wheel_speed_av,
  outC_Autobrake_ARMtoEnable *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Autobrake_ARMtoEnable_reset(outC_Autobrake_ARMtoEnable *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Autobrake_ARMtoEnable_init(outC_Autobrake_ARMtoEnable *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Autobrake_ARMtoEnable_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_ARMtoEnable.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

