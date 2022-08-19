/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Lockwheel.h"

#ifndef KCG_USER_DEFINED_INIT
void Lockwheel_init(outC_Lockwheel *outC)
{
  outC->LDPActive_Left = kcg_true;
  outC->LDPActive_Rightt = kcg_true;
  /* 1 */ sigle_init(&outC->Context_1);
  /* 2 */ sigle_init(&outC->Context_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Lockwheel_reset(outC_Lockwheel *outC)
{
  /* 1 */ sigle_reset(&outC->Context_1);
  /* 2 */ sigle_reset(&outC->Context_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Lockwheel */
void Lockwheel(
  /* Lockwheel::APPData */ tINPUT_Data *APPData,
  outC_Lockwheel *outC)
{
  /* Lockwheel */ kcg_float32 tmp;
  /* Lockwheel::_L4 */ kcg_bool _L4;

  /* 2 */ if ((*APPData).WheelSpeedData.RightWheelRefSpeed.Value >=
    (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value) {
    tmp = (*APPData).WheelSpeedData.RightWheelRefSpeed.Value;
  }
  else {
    tmp = (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value;
  }
  _L4 = tmp >= reference_wheel_speed;
  /* 2 */
  sigle(
    (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value,
    (*APPData).WheelSpeedData.RightWheelSpeed.Value,
    &outC->Context_2);
  outC->LDPActive_Rightt = _L4 & outC->Context_2.LDPActive;
  /* 1 */
  sigle(
    (*APPData).WheelSpeedData.RightWheelRefSpeed.Value,
    (*APPData).WheelSpeedData.LeftWheelSpeed.Value,
    &outC->Context_1);
  outC->LDPActive_Left = _L4 & outC->Context_1.LDPActive;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Lockwheel.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

