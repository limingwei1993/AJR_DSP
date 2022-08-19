/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _TDP_H_
#define _TDP_H_

#include "kcg_types.h"
#include "Delay_ON.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* TDP::TDP */ TDP;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Delay_ON /* 1 */ Context_1;
  outC_Delay_ON /* 2 */ Context_2;
  /* ----------------- no clocks of observable data ------------------ */
} outC_TDP;

/* ===========  node initialization and cycle functions  =========== */
/* TDP */
extern void TDP(
  /* TDP::APPData */ tINPUT_Data *APPData,
  /* TDP::Spindown_out */ tBrakeIfbOut *Spindown_out,
  outC_TDP *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void TDP_reset(outC_TDP *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void TDP_init(outC_TDP *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _TDP_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** TDP.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

