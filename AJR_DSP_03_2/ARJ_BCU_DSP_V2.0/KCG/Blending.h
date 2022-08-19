/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Blending_H_
#define _Blending_H_

#include "kcg_types.h"
#include "LimiterF32.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* Blending::BlendedPressure */ BlendedPressure;
  kcg_bool /* Blending::BlendingDone */ BlendingDone;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_float32 /* Blending::_L53 */ _L53;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Blending;

/* ===========  node initialization and cycle functions  =========== */
/** Library Function: Blending */
/** "Graphical_2" {Text = "Calculate the following: 1. The absolute blend range. 2. The blend rate per cycle. 3. Total number of cycles required. 4. Limit max duration and prevent divide by zero. 5. The change in input signal per step."} */
/** "Graphical_1" {Text = "Blends the output "BlendedPressure" from "Pressure" to "TargetPressure". Generates two ramps   - Ramp 1 from 0 to 1 in steps of "BlendRate", the destination pressure is multiplied by this ramp.   - Ramp 2 from 1 to 0 in steps of "BlendRate", the initial pressure is multiplied by this ramp. The resulting two values are added to calculate the blended pressure."} */
/** "Graphical_111" {Text = "Trace: LIB: LLR1: LimiterUnSymmetrical_float32;Abs"} */
/** "Graphical_11" {Text = "Trace: SRD: LLR1: Library"} */
/** "Title_1" {Title = "LLR1: Library function to blend from one pressure value to another value"} */
/* Blending */
extern void Blending(
  /* Blending::Pressure */ kcg_float32 Pressure,
  /* Blending::BlendToTarget */ kcg_bool BlendToTarget,
  /* Blending::TargetPressure */ kcg_float32 TargetPressure,
  /* Blending::BlendRatePerSec */ kcg_float32 BlendRatePerSec,
  /* Blending::TimeCycle */ kcg_float32 TimeCycle,
  /* Blending::MaxSteps */ kcg_float32 MaxSteps,
  outC_Blending *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Blending_reset(outC_Blending *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Blending_init(outC_Blending *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Blending_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Blending.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

