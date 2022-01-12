/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SC_Function.h"

#ifndef KCG_USER_DEFINED_INIT
void SC_Function_init(outC_SC_Function *outC)
{
  outC->BrakePressureCommandAdj = kcg_lit_float32(0.0);
  /* 1 */ SC_SlipControl_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void SC_Function_reset(outC_SC_Function *outC)
{
  /* 1 */ SC_SlipControl_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** BCUSW-739 */
/** BCUSW-740 */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-738;BCUSW-739;BCUSW-740;BCUSW-741;BCUSW-742;BCUSW-743"} */
/** "Graphical_1111" {Text = "Trace: Lib: LLR1: Blending"} */
/** "Title_1" {Title = "LLR1 : Skid Control blending to pedal pressure"} */
/* SC_Function */
void SC_Function(
  /* SC_Function::WheelSpeed */ kcg_float32 WheelSpeed,
  /* SC_Function::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  /* SC_Function::SC_command_enter */ kcg_bool SC_command_enter,
  outC_SC_Function *outC)
{
  /* 1 */
  SC_SlipControl(WheelRefSpeed, WheelSpeed, SC_command_enter, &outC->Context_1);
  outC->BrakePressureCommandAdj = outC->Context_1.BrakePressureCommandAdj;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_Function.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

