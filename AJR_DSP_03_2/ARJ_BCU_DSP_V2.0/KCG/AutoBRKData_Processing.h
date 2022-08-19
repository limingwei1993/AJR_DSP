/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _AutoBRKData_Processing_H_
#define _AutoBRKData_Processing_H_

#include "kcg_types.h"
#include "BTI.h"
#include "Delay_OFF.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tIOR_ProcessAutobrakeData /* AutoBRKData_Processing::AutoBRKswitch */ AutoBRKswitch;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Delay_OFF /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_AutoBRKData_Processing;

/* ===========  node initialization and cycle functions  =========== */
/* AutoBRKData_Processing */
extern void AutoBRKData_Processing(
  /* AutoBRKData_Processing::Input1 */ tData_to_DSP *Input1,
  outC_AutoBRKData_Processing *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void AutoBRKData_Processing_reset(outC_AutoBRKData_Processing *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void AutoBRKData_Processing_init(outC_AutoBRKData_Processing *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _AutoBRKData_Processing_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutoBRKData_Processing.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

