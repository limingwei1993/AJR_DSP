/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Lockwheel.h"

#ifndef KCG_USER_DEFINED_INIT
void Lockwheel_init(outC_Lockwheel *outC)
{
  outC->LDPActive_Left = kcg_true;
  outC->LDPActive_Rightt = kcg_true;
  /* 1 */ Delay_OFF_init(&outC->_2_Context_1);
  /* 2 */ Delay_OFF_init(&outC->_1_Context_2);
  /* 1 */ sigle_init(&outC->Context_1);
  /* 2 */ sigle_init(&outC->Context_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Lockwheel_reset(outC_Lockwheel *outC)
{
  /* 1 */ Delay_OFF_reset(&outC->_2_Context_1);
  /* 2 */ Delay_OFF_reset(&outC->_1_Context_2);
  /* 1 */ sigle_reset(&outC->Context_1);
  /* 2 */ sigle_reset(&outC->Context_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Lockwheel */
void Lockwheel(
  /* Lockwheel::APPData */ tINPUT_Data *APPData,
  outC_Lockwheel *outC)
{
  /* Lockwheel::_L73 */ kcg_bool _L73;
  /* Lockwheel::_L74 */ kcg_bool _L74;
  /* Lockwheel::_L75 */ kcg_bool _L75;

  _L74 = (*APPData).WOWData.WOWBK &
    ((*APPData).WheelSpeedData.LWP_RefSpeed.Value >= kcg_lit_float32(51.));
  /* 2 */
  sigle(
    (*APPData).WheelSpeedData.LWP_RefSpeed.Value,
    (*APPData).WheelSpeedData.RightWheelSpeed.Value,
    &outC->Context_2);
  _L75 = _L74 & outC->Context_2.LDPActive;
  /* 1 */
  sigle(
    (*APPData).WheelSpeedData.LWP_RefSpeed.Value,
    (*APPData).WheelSpeedData.LeftWheelSpeed.Value,
    &outC->Context_1);
  _L73 = outC->Context_1.LDPActive & _L74;
  /* 2 */ Delay_OFF((kcg_bool) !_L75, kcg_lit_int32(800), &outC->_1_Context_2);
  outC->LDPActive_Rightt = _L75 & outC->_1_Context_2.Output1;
  /* 1 */ Delay_OFF((kcg_bool) !_L73, kcg_lit_int32(800), &outC->_2_Context_1);
  outC->LDPActive_Left = outC->_2_Context_1.Output1 & _L73;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Lockwheel.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

