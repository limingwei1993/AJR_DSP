/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _Spindown_H_
#define _Spindown_H_

#include "kcg_types.h"
#include "LimiterF32.h"
#include "Counter.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tBrakeIfbOut /* Spindown::BrakeIfbOut */ BrakeIfbOut;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Spindown::_L16 */ rem__L16;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Counter /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Spindown;

/* ===========  node initialization and cycle functions  =========== */
/* Spindown */
extern void Spindown(
  /* Spindown::WOWBK */ kcg_bool WOWBK,
  /* Spindown::APPData */ tINPUT_Data *APPData,
  outC_Spindown *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Spindown_reset(outC_Spindown *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Spindown_init(outC_Spindown *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Spindown_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Spindown.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

