/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SC_Function.h"

#ifndef KCG_USER_DEFINED_INIT
void SC_Function_init(outC_SC_Function *outC)
{
  outC->BrakePressureCommandAdj = kcg_lit_float32(0.0);
  /* 1 */ Blending_init(&outC->_1_Context_1);
  /* 1 */ SC_SlipControl_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void SC_Function_reset(outC_SC_Function *outC)
{
  /* 1 */ Blending_reset(&outC->_1_Context_1);
  /* 1 */ SC_SlipControl_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** BCUSW-739 */
/** BCUSW-740 */
/** "Title_1" {Title = "LLR1 : Skid Control blending to pedal pressure"} */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-738;BCUSW-739;BCUSW-740;BCUSW-741;BCUSW-742;BCUSW-743"} */
/** "Graphical_1111" {Text = "Trace: Lib: LLR1: Blending"} */
/* SC_Function */
void SC_Function(
  /* SC_Function::WheelSpeed */ kcg_float32 WheelSpeed,
  /* SC_Function::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  /* SC_Function::SC_command_enter */ kcg_bool SC_command_enter,
  /* SC_Function::BrakePressureCommand */ kcg_float32 BrakePressureCommand,
  outC_SC_Function *outC)
{
  /* 1 */
  SC_SlipControl(WheelRefSpeed, WheelSpeed, SC_command_enter, &outC->Context_1);
  /* 1 */
  Blending(
    outC->Context_1.BrakePressureCommandAdj,
    outC->Context_1.StartBlending,
    BrakePressureCommand,
    C_SC_BLENDING_RATE,
    kcg_lit_float32(0.005),
    C_SC_BLENDING_MAX_STEPS,
    &outC->_1_Context_1);
  /* 1 */ if (BrakePressureCommand <= outC->_1_Context_1.BlendedPressure) {
    outC->BrakePressureCommandAdj = BrakePressureCommand;
  }
  else {
    outC->BrakePressureCommandAdj = outC->_1_Context_1.BlendedPressure;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_Function.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

