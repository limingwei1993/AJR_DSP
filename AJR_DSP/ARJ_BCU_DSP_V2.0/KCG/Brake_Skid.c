/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Brake_Skid.h"

#ifndef KCG_USER_DEFINED_INIT
void Brake_Skid_init(outC_Brake_Skid *outC)
{
  outC->BrakeSkid.LeftSkidEnable = kcg_true;
  outC->BrakeSkid.LeftBrakePressureCommandAdj = kcg_lit_float32(0.0);
  outC->BrakeSkid.Ratio = kcg_lit_float32(0.0);
  outC->BrakeSkid.RightSkidEnable = kcg_true;
  outC->BrakeSkid.RightBrakePressureCommandAdj = kcg_lit_float32(0.0);
  /* 2 */ SC_Wheel_init(&outC->Context_2);
  /* 1 */ SC_Wheel_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Brake_Skid_reset(outC_Brake_Skid *outC)
{
  /* 2 */ SC_Wheel_reset(&outC->Context_2);
  /* 1 */ SC_Wheel_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Brake_Skid */
void Brake_Skid(
  /* Brake_Skid::APPData */ tINPUT_Data *APPData,
  /* Brake_Skid::WOWBK */ kcg_bool WOWBK,
  /* Brake_Skid::BrakeSelectOut */ tBrakeSelectOut *BrakeSelectOut,
  outC_Brake_Skid *outC)
{
  outC->BrakeSkid.Ratio = Zero1;
  /* 1 */
  SC_Wheel(
    WOWBK,
    &(*APPData).WheelSpeedData.LeftWheelSpeed,
    &(*APPData).WheelSpeedData.LeftWheelRefSpeed,
    (*BrakeSelectOut).LeftBrakePressureCommand,
    &outC->Context_1);
  outC->BrakeSkid.LeftSkidEnable = outC->Context_1.SkidEnable;
  outC->BrakeSkid.LeftBrakePressureCommandAdj =
    outC->Context_1.BrakePressureCommandAdj;
  /* 2 */
  SC_Wheel(
    WOWBK,
    &(*APPData).WheelSpeedData.RightWheelSpeed,
    &(*APPData).WheelSpeedData.RightWheelRefSpeed,
    (*BrakeSelectOut).RightBrakePressureCommand,
    &outC->Context_2);
  outC->BrakeSkid.RightSkidEnable = outC->Context_2.SkidEnable;
  outC->BrakeSkid.RightBrakePressureCommandAdj =
    outC->Context_2.BrakePressureCommandAdj;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Brake_Skid.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

