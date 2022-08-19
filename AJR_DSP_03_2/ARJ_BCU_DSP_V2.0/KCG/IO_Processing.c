/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "IO_Processing.h"

#ifndef KCG_USER_DEFINED_INIT
void IO_Processing_init(outC_IO_Processing *outC)
{
  outC->APPData.Aircraft_Data.Airspeed.Valid = kcg_true;
  outC->APPData.Aircraft_Data.Airspeed.Value = kcg_lit_float32(0.0);
  outC->APPData.Aircraft_Data.AircraftAcceleration_Left.Valid = kcg_true;
  outC->APPData.Aircraft_Data.AircraftAcceleration_Left.Value = kcg_lit_float32(
      0.0);
  outC->APPData.Aircraft_Data.AircraftAcceleration1_Right.Valid = kcg_true;
  outC->APPData.Aircraft_Data.AircraftAcceleration1_Right.Value =
    kcg_lit_float32(0.0);
  outC->APPData.Aircraft_Data.AircraftAcceleration_av.Valid = kcg_true;
  outC->APPData.Aircraft_Data.AircraftAcceleration_av.Value = kcg_lit_float32(
      0.0);
  outC->APPData.Aircraft_Data.SpoilerStoredSignal_Left = kcg_true;
  outC->APPData.Aircraft_Data.SpoilerStoredSignal_Right = kcg_true;
  outC->APPData.Aircraft_Data.AircraftGroundSpeed.Valid = kcg_true;
  outC->APPData.Aircraft_Data.AircraftGroundSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.Aircraft_Data.AircraftAttitude.Valid = kcg_true;
  outC->APPData.Aircraft_Data.AircraftAttitude.Value = kcg_lit_float32(0.0);
  outC->APPData.WOWData.LeftWOW = kcg_true;
  outC->APPData.WOWData.RightWOW = kcg_true;
  outC->APPData.WOWData.zong.Valid = kcg_true;
  outC->APPData.WOWData.zong.Value = kcg_true;
  outC->APPData.WOWData.WOWBK = kcg_true;
  outC->APPData.PedalData.LeftCptPedal.Valid = kcg_true;
  outC->APPData.PedalData.LeftCptPedal.Value = kcg_lit_float32(0.0);
  outC->APPData.PedalData.RightCptPedal.Valid = kcg_true;
  outC->APPData.PedalData.RightCptPedal.Value = kcg_lit_float32(0.0);
  outC->APPData.PedalData.LeftPPedal.Valid = kcg_true;
  outC->APPData.PedalData.LeftPPedal.Value = kcg_lit_float32(0.0);
  outC->APPData.PedalData.RightPPedal.Valid = kcg_true;
  outC->APPData.PedalData.RightPPedal.Value = kcg_lit_float32(0.0);
  outC->APPData.PedalData.MaxPedal = kcg_lit_float32(0.0);
  outC->APPData.ThrottleData.LeftThrottleIdle = kcg_true;
  outC->APPData.ThrottleData.RightThrottleIdle = kcg_true;
  outC->APPData.ThrottleData.ThrottleIdleAtLeastOne = kcg_true;
  outC->APPData.ThrottleData.ThrottleIdleBoth = kcg_true;
  outC->APPData.LGData.LG_GearDown_Locked = kcg_true;
  outC->APPData.LGData.LandingGearExtentionandRetractionCommand = kcg_true;
  outC->APPData.HydraulicData.HighPressure = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_OFF.Valid = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_OFF.Value = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_LOW.Valid = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_LOW.Value = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_MED.Valid = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_MED.Value = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_HI.Valid = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_HI.Value = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_RTO.Valid = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRK_RTO.Value = kcg_true;
  outC->APPData.AutoBrakeData.AutoBRKfault = kcg_true;
  outC->APPData.WheelSpeedData.LeftWheelSpeed.Valid = kcg_true;
  outC->APPData.WheelSpeedData.LeftWheelSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.WheelSpeedData.RightWheelSpeed.Valid = kcg_true;
  outC->APPData.WheelSpeedData.RightWheelSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.WheelSpeedData.LeftWheelRefSpeed.Valid = kcg_true;
  outC->APPData.WheelSpeedData.LeftWheelRefSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.WheelSpeedData.RightWheelRefSpeed.Valid = kcg_true;
  outC->APPData.WheelSpeedData.RightWheelRefSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.WheelSpeedData.LWP_RefSpeed.Valid = kcg_true;
  outC->APPData.WheelSpeedData.LWP_RefSpeed.Value = kcg_lit_float32(0.0);
  outC->APPData.WheelSpeedData.WheelSpeed_av = kcg_lit_float32(0.0);
  /* 1 */ AutoBRKData_Processing_init(&outC->_1_Context_1);
  /* 1 */ Speed_Processing_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void IO_Processing_reset(outC_IO_Processing *outC)
{
  /* 1 */ AutoBRKData_Processing_reset(&outC->_1_Context_1);
  /* 1 */ Speed_Processing_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* IO_Processing */
void IO_Processing(
  /* IO_Processing::Input1 */ tData_to_DSP *Input1,
  outC_IO_Processing *outC)
{
  /* IO_Processing::WOWData */ tIOR_ProcessWowData WOWData;

  /* 1 */ WOW_Processing(Input1, &WOWData);
  kcg_copy_tIOR_ProcessWowData(&outC->APPData.WOWData, &WOWData);
  /* 1 */ Speed_Processing(Input1, &WOWData, &outC->Context_1);
  kcg_copy_tIOR_ProcessAircraftData(
    &outC->APPData.Aircraft_Data,
    &outC->Context_1.Aircraft_Data);
  kcg_copy_tIOR_ProcessSpeedData(
    &outC->APPData.WheelSpeedData,
    &outC->Context_1.WheelSpeedData);
  /* 1 */ Pedal_Processing(Input1, &outC->APPData.PedalData);
  /* 1 */ Throttle_Processing(Input1, &outC->APPData.ThrottleData);
  /* 1 */ LGData_Processing(Input1, &outC->APPData.LGData);
  /* 1 */ HydraulicData_Processing(Input1, &outC->APPData.HydraulicData);
  /* 1 */ AutoBRKData_Processing(Input1, &outC->_1_Context_1);
  kcg_copy_tIOR_ProcessAutobrakeData(
    &outC->APPData.AutoBrakeData,
    &outC->_1_Context_1.AutoBRKswitch);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** IO_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

