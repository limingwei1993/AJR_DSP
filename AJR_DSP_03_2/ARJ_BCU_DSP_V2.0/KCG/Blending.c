/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Blending.h"

#ifndef KCG_USER_DEFINED_INIT
void Blending_init(outC_Blending *outC)
{
  outC->BlendingDone = kcg_true;
  outC->BlendedPressure = kcg_lit_float32(0.0);
  outC->_L53 = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Blending_reset(outC_Blending *outC)
{
  outC->_L53 = kcg_lit_float32(0.0);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** Library Function: Blending */
/** "Graphical_2" {Text = "Calculate the following: 1. The absolute blend range. 2. The blend rate per cycle. 3. Total number of cycles required. 4. Limit max duration and prevent divide by zero. 5. The change in input signal per step."} */
/** "Graphical_1" {Text = "Blends the output "BlendedPressure" from "Pressure" to "TargetPressure". Generates two ramps   - Ramp 1 from 0 to 1 in steps of "BlendRate", the destination pressure is multiplied by this ramp.   - Ramp 2 from 1 to 0 in steps of "BlendRate", the initial pressure is multiplied by this ramp. The resulting two values are added to calculate the blended pressure."} */
/** "Graphical_111" {Text = "Trace: LIB: LLR1: LimiterUnSymmetrical_float32;Abs"} */
/** "Graphical_11" {Text = "Trace: SRD: LLR1: Library"} */
/** "Title_1" {Title = "LLR1: Library function to blend from one pressure value to another value"} */
/* Blending */
void Blending(
  /* Blending::Pressure */ kcg_float32 Pressure,
  /* Blending::BlendToTarget */ kcg_bool BlendToTarget,
  /* Blending::TargetPressure */ kcg_float32 TargetPressure,
  /* Blending::BlendRatePerSec */ kcg_float32 BlendRatePerSec,
  /* Blending::TimeCycle */ kcg_float32 TimeCycle,
  /* Blending::MaxSteps */ kcg_float32 MaxSteps,
  outC_Blending *outC)
{
  /* Blending */ kcg_float32 tmp;
  /* Blending::BlendStep */ kcg_float32 BlendStep;

  BlendStep = Pressure - TargetPressure;
  /* 2 */ if (kcg_lit_float32(0.) <= BlendStep) {
    tmp = BlendStep;
  }
  else {
    tmp = - BlendStep;
  }
  BlendStep = kcg_lit_float32(1.0) / /* 1 */
    LimiterF32(
      tmp / (BlendRatePerSec * TimeCycle),
      kcg_lit_float32(1.),
      MaxSteps);
  /* ck_BlendToTarget */ if (BlendToTarget) {
    tmp = BlendStep + outC->_L53;
  }
  else {
    tmp = kcg_lit_float32(0.0);
  }
  outC->_L53 = /* 3 */
    LimiterF32(tmp, kcg_lit_float32(0.0), kcg_lit_float32(1.0));
  tmp = kcg_lit_float32(1.0) - outC->_L53;
  outC->BlendingDone = !(tmp > BlendStep / kcg_lit_float32(2.0));
  outC->BlendedPressure = Pressure * tmp + outC->_L53 * TargetPressure;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Blending.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

