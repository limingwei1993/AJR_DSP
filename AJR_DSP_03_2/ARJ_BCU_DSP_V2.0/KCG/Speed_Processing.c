/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Speed_Processing.h"

#ifndef KCG_USER_DEFINED_INIT
void Speed_Processing_init(outC_Speed_Processing *outC)
{
  outC->WheelSpeedData.LeftWheelSpeed.Valid = kcg_true;
  outC->WheelSpeedData.LeftWheelSpeed.Value = kcg_lit_float32(0.0);
  outC->WheelSpeedData.RightWheelSpeed.Valid = kcg_true;
  outC->WheelSpeedData.RightWheelSpeed.Value = kcg_lit_float32(0.0);
  outC->WheelSpeedData.LeftWheelRefSpeed.Valid = kcg_true;
  outC->WheelSpeedData.LeftWheelRefSpeed.Value = kcg_lit_float32(0.0);
  outC->WheelSpeedData.RightWheelRefSpeed.Valid = kcg_true;
  outC->WheelSpeedData.RightWheelRefSpeed.Value = kcg_lit_float32(0.0);
  outC->WheelSpeedData.LWP_RefSpeed.Valid = kcg_true;
  outC->WheelSpeedData.LWP_RefSpeed.Value = kcg_lit_float32(0.0);
  outC->WheelSpeedData.WheelSpeed_av = kcg_lit_float32(0.0);
  outC->Aircraft_Data.Airspeed.Valid = kcg_true;
  outC->Aircraft_Data.Airspeed.Value = kcg_lit_float32(0.0);
  outC->Aircraft_Data.AircraftAcceleration_Left.Valid = kcg_true;
  outC->Aircraft_Data.AircraftAcceleration_Left.Value = kcg_lit_float32(0.0);
  outC->Aircraft_Data.AircraftAcceleration1_Right.Valid = kcg_true;
  outC->Aircraft_Data.AircraftAcceleration1_Right.Value = kcg_lit_float32(0.0);
  outC->Aircraft_Data.AircraftAcceleration_av.Valid = kcg_true;
  outC->Aircraft_Data.AircraftAcceleration_av.Value = kcg_lit_float32(0.0);
  outC->Aircraft_Data.SpoilerStoredSignal_Left = kcg_true;
  outC->Aircraft_Data.SpoilerStoredSignal_Right = kcg_true;
  outC->Aircraft_Data.AircraftGroundSpeed.Valid = kcg_true;
  outC->Aircraft_Data.AircraftGroundSpeed.Value = kcg_lit_float32(0.0);
  outC->Aircraft_Data.AircraftAttitude.Valid = kcg_true;
  outC->Aircraft_Data.AircraftAttitude.Value = kcg_lit_float32(0.0);
  /* 1 */ Ref_cal_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Speed_Processing_reset(outC_Speed_Processing *outC)
{
  /* 1 */ Ref_cal_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Speed_Processing */
void Speed_Processing(
  /* Speed_Processing::In */ tData_to_DSP *In,
  /* Speed_Processing::WOWData */ tIOR_ProcessWowData *WOWData,
  outC_Speed_Processing *outC)
{
  /* Speed_Processing */ kcg_float32 tmp1;
  /* Speed_Processing */ kcg_float32 tmp;
  /* Speed_Processing::AccAv */ tValidityF32 AccAv;
  /* Speed_Processing::RefSpeed */ tValidityF32 RefSpeed;
  /* Speed_Processing::_L27 */ kcg_float32 _L27;
  /* Speed_Processing::_L31 */ kcg_float32 _L31;

  outC->Aircraft_Data.AircraftGroundSpeed.Valid = kcg_false;
  outC->Aircraft_Data.AircraftGroundSpeed.Value = kcg_lit_float32(0.0);
  kcg_copy_tValidityF32(
    &outC->Aircraft_Data.AircraftAttitude,
    &outC->Aircraft_Data.AircraftGroundSpeed);
  kcg_copy_tValidityF32(
    &outC->Aircraft_Data.Airspeed,
    &(*In).In_Computed_Air_Speed_206);
  kcg_copy_tValidityF32(
    &outC->Aircraft_Data.AircraftAcceleration_Left,
    &(*In)._1_In_Longitudinal_Acceleration_Body_Left_331);
  kcg_copy_tValidityF32(
    &outC->Aircraft_Data.AircraftAcceleration1_Right,
    &(*In).In_Longitudinal_Acceleration_Body_Right_331);
  outC->Aircraft_Data.SpoilerStoredSignal_Left =
    (*In).In_Discrete.SpoilerStoredSignal_Left;
  outC->Aircraft_Data.SpoilerStoredSignal_Right =
    (*In).In_Discrete.SpoilerStoredSignal_Right;
  RefSpeed.Valid = kcg_true;
  _L27 = /* 1 */ HzTOradpersec((*In).In_HcLeftWheelAngularSpeed.Value) *
    kcg_lit_float32(2.0);
  _L31 = kcg_lit_float32(2.0) * /* 2 */
    HzTOradpersec((*In).In_HcRightWheelAngularSpeed.Value);
  outC->WheelSpeedData.WheelSpeed_av = (_L27 + _L31) / kcg_lit_float32(2.0);
  tmp = /* 1 */
    m_to_ft_unit(
      /* 1 */
      g_to_mps2_unit((*In).In_Longitudinal_Acceleration_Body_Right_331.Value));
  tmp1 = /* 2 */
    m_to_ft_unit(
      /* 2 */
      g_to_mps2_unit(
        (*In)._1_In_Longitudinal_Acceleration_Body_Left_331.Value));
  /* 1 */
  Acc_average(
    tmp,
    tmp1,
    (*In).In_Longitudinal_Acceleration_Body_Right_331.Valid,
    (*In)._1_In_Longitudinal_Acceleration_Body_Left_331.Valid,
    &AccAv);
  kcg_copy_tValidityF32(&outC->Aircraft_Data.AircraftAcceleration_av, &AccAv);
  /* 2 */ if (_L27 >= _L31) {
    tmp1 = _L27;
  }
  else {
    tmp1 = _L31;
  }
  /* 1 */ if (AccAv.Valid) {
    tmp = AccAv.Value;
  }
  else {
    tmp = - kcg_lit_float32(25.);
  }
  /* 1 */ Ref_cal(tmp1, tmp, (*WOWData).WOWBK, &outC->Context_1);
  RefSpeed.Value = outC->Context_1.refspeed;
  kcg_copy_tValidityF32(&outC->WheelSpeedData.RightWheelRefSpeed, &RefSpeed);
  kcg_copy_tValidityF32(
    &outC->WheelSpeedData.LWP_RefSpeed,
    &outC->WheelSpeedData.RightWheelRefSpeed);
  outC->WheelSpeedData.LeftWheelSpeed.Valid =
    (*In).In_HcLeftWheelAngularSpeed.Valid;
  outC->WheelSpeedData.LeftWheelSpeed.Value = _L27;
  outC->WheelSpeedData.RightWheelSpeed.Valid =
    (*In).In_HcRightWheelAngularSpeed.Valid;
  outC->WheelSpeedData.RightWheelSpeed.Value = _L31;
  kcg_copy_tValidityF32(&outC->WheelSpeedData.LeftWheelRefSpeed, &RefSpeed);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Speed_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

