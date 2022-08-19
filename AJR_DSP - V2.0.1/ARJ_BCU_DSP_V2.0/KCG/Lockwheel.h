/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _Lockwheel_H_
#define _Lockwheel_H_

#include "kcg_types.h"
#include "sigle.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Lockwheel::LDPActive_Left */ LDPActive_Left;
  kcg_bool /* Lockwheel::LDPActive_Rightt */ LDPActive_Rightt;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_sigle /* 1 */ Context_1;
  outC_sigle /* 2 */ Context_2;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Lockwheel;

/* ===========  node initialization and cycle functions  =========== */
/* Lockwheel */
extern void Lockwheel(
  /* Lockwheel::APPData */ tINPUT_Data *APPData,
  outC_Lockwheel *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Lockwheel_reset(outC_Lockwheel *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Lockwheel_init(outC_Lockwheel *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Lockwheel_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Lockwheel.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

