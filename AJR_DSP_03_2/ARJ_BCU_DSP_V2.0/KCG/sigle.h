/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _sigle_H_
#define _sigle_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* sigle::LDPActive */ LDPActive;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  _5_SSM_ST_SM1 /* sigle::SM1 */ SM1_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_sigle;

/* ===========  node initialization and cycle functions  =========== */
/* sigle */
extern void sigle(
  /* sigle::RefWheelspeed */ kcg_float32 RefWheelspeed,
  /* sigle::WheelSpeed */ kcg_float32 WheelSpeed,
  outC_sigle *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void sigle_reset(outC_sigle *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void sigle_init(outC_sigle *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _sigle_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** sigle.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

