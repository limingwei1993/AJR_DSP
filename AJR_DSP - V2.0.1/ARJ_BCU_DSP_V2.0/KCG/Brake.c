/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Brake.h"

#ifndef KCG_USER_DEFINED_INIT
void Brake_init(outC_Brake *outC)
{
  outC->Output.SOV_Open = kcg_true;
  outC->Output.BrakePressureCommand_L = kcg_lit_float32(0.0);
  outC->Output.BrakePressureCommand_R = kcg_lit_float32(0.0);
  outC->Output.BrakeAutoBKOut.AutoBrakeActivate = kcg_true;
  outC->Output.BrakeAutoBKOut.Left_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeAutoBKOut.Right_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeAutoBKOut.ArmDisagree = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.LandingArmedState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.LandingApplicationState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.LandingEnabledState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.LandingDisArmedState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.RTOArmedState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.RTOEnabledState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.RTODisarmedState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.RTOApplicationState = kcg_true;
  outC->Output.BrakeAutoBKOut.AutoBrakeState.OFFState = kcg_true;
  outC->Output.BrakeAutoBKOut.CoilEnergized = kcg_true;
  outC->Output.BrakeIfbOut.IFB_BrakeActivate = kcg_true;
  outC->Output.BrakeIfbOut.LeftIFB_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeIfbOut.RightIFB_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeInhibitOut.SOV_Open = kcg_true;
  outC->Output.BrakeInhibitOut.LeftBrakePressureCommandAdj = kcg_lit_float32(0.0);
  outC->Output.BrakeInhibitOut.RightBrakePressureCommandAdj = kcg_lit_float32(
      0.0);
  outC->Output.BrakeInhibitOut.BrakeInhibits.TDP_BrakeInhibit = kcg_true;
  outC->Output.BrakeInhibitOut.BrakeInhibits.LWP_LeftBrakeInhibit = kcg_true;
  outC->Output.BrakeInhibitOut.BrakeInhibits.LWP_RightBrakeInhibit = kcg_true;
  outC->Output.BrakePdlOut.LeftPDL_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakePdlOut.RightPDL_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakePdlOut.PedalBrakeActivate = kcg_true;
  outC->Output.BrakeSelectOut.SOV_Open = kcg_true;
  outC->Output.BrakeSelectOut.LeftBrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeSelectOut.RightBrakePressureCommand = kcg_lit_float32(0.0);
  outC->Output.BrakeSkidOut.LeftSkidEnable = kcg_true;
  outC->Output.BrakeSkidOut.LeftBrakePressureCommandAdj = kcg_lit_float32(0.0);
  outC->Output.BrakeSkidOut.Ratio = kcg_lit_float32(0.0);
  outC->Output.BrakeSkidOut.RightSkidEnable = kcg_true;
  outC->Output.BrakeSkidOut.RightBrakePressureCommandAdj = kcg_lit_float32(0.0);
  /* 1 */ TDP_init(&outC->_3_Context_1);
  /* 1 */ Brake_Skid_init(&outC->_2_Context_1);
  /* 1 */ AutoBrake_init(&outC->_1_Context_1);
  /* 1 */ Lockwheel_init(&outC->Context_1);
  /* 2 */ Spindown_init(&outC->Context_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Brake_reset(outC_Brake *outC)
{
  /* 1 */ TDP_reset(&outC->_3_Context_1);
  /* 1 */ Brake_Skid_reset(&outC->_2_Context_1);
  /* 1 */ AutoBrake_reset(&outC->_1_Context_1);
  /* 1 */ Lockwheel_reset(&outC->Context_1);
  /* 2 */ Spindown_reset(&outC->Context_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Brake */
void Brake(inC_Brake *inC, outC_Brake *outC)
{
  /* Brake::WOWBK */ kcg_bool WOWBK;
  /* Brake::BrakeSelectOut */ tBrakeSelectOut BrakeSelectOut;
  /* Brake::BrakeSkidOut */ tBrakeSkidOut BrakeSkidOut;
  /* Brake::BrakeInhibitOut */ tBrakeInhibitOut BrakeInhibitOut;
  /* Brake::BrakePdlOut */ tBrakePdlOut BrakePdlOut;
  /* Brake::BrakeAutoBKOut */ tBrakeAutoBKOut BrakeAutoBKOut;
  /* Brake::BrakeIfbOut */ tBrakeIfbOut BrakeIfbOut;
  /* Brake::_L5 */ kcg_bool _L5;
  /* Brake::_L4 */ kcg_bool _L4;

  WOWBK = /* 1 */ WOW_Processing(&inC->APPData);
  /* 2 */ Spindown(WOWBK, &inC->APPData, &outC->Context_2);
  kcg_copy_tBrakeIfbOut(&BrakeIfbOut, &outC->Context_2.BrakeIfbOut);
  kcg_copy_tBrakeIfbOut(&outC->Output.BrakeIfbOut, &BrakeIfbOut);
  /* 1 */ Lockwheel(&inC->APPData, &outC->Context_1);
  _L4 = outC->Context_1.LDPActive_Left;
  _L5 = outC->Context_1.LDPActive_Rightt;
  /* 3 */ BrakePress(&inC->APPData, &BrakePdlOut);
  kcg_copy_tBrakePdlOut(&outC->Output.BrakePdlOut, &BrakePdlOut);
  /* 1 */ AutoBrake(&inC->APPData, WOWBK, &outC->_1_Context_1);
  kcg_copy_tBrakeAutoBKOut(&BrakeAutoBKOut, &outC->_1_Context_1.BRAKEAuto);
  kcg_copy_tBrakeAutoBKOut(&outC->Output.BrakeAutoBKOut, &BrakeAutoBKOut);
  /* 1 */
  BrakeSelect(&BrakePdlOut, &BrakeIfbOut, &BrakeAutoBKOut, &BrakeSelectOut);
  kcg_copy_tBrakeSelectOut(&outC->Output.BrakeSelectOut, &BrakeSelectOut);
  /* 1 */ Brake_Skid(&inC->APPData, WOWBK, &BrakeSelectOut, &outC->_2_Context_1);
  kcg_copy_tBrakeSkidOut(&BrakeSkidOut, &outC->_2_Context_1.BrakeSkid);
  kcg_copy_tBrakeSkidOut(&outC->Output.BrakeSkidOut, &BrakeSkidOut);
  /* 1 */ TDP(&inC->APPData, WOWBK, &outC->_3_Context_1);
  /* 1 */
  BrakeInhibit(
    outC->_3_Context_1.TDP,
    _L4,
    _L5,
    &BrakeSelectOut,
    &BrakeSkidOut,
    &BrakeInhibitOut);
  outC->Output.SOV_Open = BrakeInhibitOut.SOV_Open;
  outC->Output.BrakePressureCommand_L =
    BrakeInhibitOut.LeftBrakePressureCommandAdj;
  outC->Output.BrakePressureCommand_R =
    BrakeInhibitOut.RightBrakePressureCommandAdj;
  kcg_copy_tBrakeInhibitOut(&outC->Output.BrakeInhibitOut, &BrakeInhibitOut);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Brake.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

