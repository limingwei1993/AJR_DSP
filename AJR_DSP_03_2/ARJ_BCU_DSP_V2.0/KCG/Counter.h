/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Counter_H_
#define _Counter_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_int32 /* Counter::count */ count;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_int32 /* Counter::_L3 */ _L3;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Counter;

/* ===========  node initialization and cycle functions  =========== */
/* Counter */
extern void Counter(/* Counter::Reset */ kcg_bool Reset, outC_Counter *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Counter_reset(outC_Counter *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Counter_init(outC_Counter *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Counter_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Counter.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

