/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Speed_Processing_H_
#define _Speed_Processing_H_

#include "kcg_types.h"
#include "g_to_mps2_unit.h"
#include "m_to_ft_unit.h"
#include "Acc_average.h"
#include "HzTOradpersec.h"
#include "Ref_cal.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tIOR_ProcessAircraftData /* Speed_Processing::Aircraft_Data */ Aircraft_Data;
  tIOR_ProcessSpeedData /* Speed_Processing::WheelSpeedData */ WheelSpeedData;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Ref_cal /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Speed_Processing;

/* ===========  node initialization and cycle functions  =========== */
/* Speed_Processing */
extern void Speed_Processing(
  /* Speed_Processing::In */ tData_to_DSP *In,
  /* Speed_Processing::WOWData */ tIOR_ProcessWowData *WOWData,
  outC_Speed_Processing *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Speed_Processing_reset(outC_Speed_Processing *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Speed_Processing_init(outC_Speed_Processing *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Speed_Processing_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Speed_Processing.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

