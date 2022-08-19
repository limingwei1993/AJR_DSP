/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _IO_Processing_H_
#define _IO_Processing_H_

#include "kcg_types.h"
#include "Pedal_Processing.h"
#include "WOW_Processing.h"
#include "Throttle_Processing.h"
#include "LGData_Processing.h"
#include "HydraulicData_Processing.h"
#include "AutoBRKData_Processing.h"
#include "Speed_Processing.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tINPUT_Data /* IO_Processing::APPData */ APPData;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_AutoBRKData_Processing /* 1 */ _1_Context_1;
  outC_Speed_Processing /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_IO_Processing;

/* ===========  node initialization and cycle functions  =========== */
/* IO_Processing */
extern void IO_Processing(
  /* IO_Processing::Input1 */ tData_to_DSP *Input1,
  outC_IO_Processing *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void IO_Processing_reset(outC_IO_Processing *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void IO_Processing_init(outC_IO_Processing *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _IO_Processing_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** IO_Processing.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

