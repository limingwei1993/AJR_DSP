/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_bool_word
kcg_bool kcg_comp_bool_word(bool_word *kcg_c1, bool_word *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 32; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_bool_word */

#ifdef kcg_use_array_bool_3
kcg_bool kcg_comp_array_bool_3(array_bool_3 *kcg_c1, array_bool_3 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 3; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_bool_3 */

#ifdef kcg_use_bool_wordshort
kcg_bool kcg_comp_bool_wordshort(bool_wordshort *kcg_c1, bool_wordshort *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 16; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_bool_wordshort */

#ifdef kcg_use_array_float32_5
kcg_bool kcg_comp_array_float32_5(
  array_float32_5 *kcg_c1,
  array_float32_5 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 5; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_float32_5 */

#ifdef kcg_use_A429_Valid_short
kcg_bool kcg_comp_A429_Valid_short(
  A429_Valid_short *kcg_c1,
  A429_Valid_short *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->HS_Pressure == kcg_c2->HS_Pressure);
  kcg_equ = kcg_equ & (kcg_c1->Accumulator_Pressure ==
      kcg_c2->Accumulator_Pressure);
  kcg_equ = kcg_equ & (kcg_c1->TLA_Position_Left == kcg_c2->TLA_Position_Left);
  kcg_equ = kcg_equ & (kcg_c1->TLA_Position_Right == kcg_c2->TLA_Position_Right);
  kcg_equ = kcg_equ & (kcg_c1->Master_Time == kcg_c2->Master_Time);
  kcg_equ = kcg_equ & (kcg_c1->AirSpeed == kcg_c2->AirSpeed);
  kcg_equ = kcg_equ & (kcg_c1->Date_Master == kcg_c2->Date_Master);
  kcg_equ = kcg_equ & (kcg_c1->MLG_RtDownlocked == kcg_c2->MLG_RtDownlocked);
  kcg_equ = kcg_equ & (kcg_c1->MLG_LtDownlocked == kcg_c2->MLG_LtDownlocked);
  kcg_equ = kcg_equ & (kcg_c1->Computed_WOW1 == kcg_c2->Computed_WOW1);
  kcg_equ = kcg_equ & (kcg_c1->Computed_WOW2 == kcg_c2->Computed_WOW2);
  kcg_equ = kcg_equ & (kcg_c1->Acceleration_LT == kcg_c2->Acceleration_LT);
  kcg_equ = kcg_equ & (kcg_c1->Acceleration_RT == kcg_c2->Acceleration_RT);
  return kcg_equ;
}
#endif /* kcg_use_A429_Valid_short */

#ifdef kcg_use_tIOR_ProcessSpeedData
kcg_bool kcg_comp_tIOR_ProcessSpeedData(
  tIOR_ProcessSpeedData *kcg_c1,
  tIOR_ProcessSpeedData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->WheelSpeed_av == kcg_c2->WheelSpeed_av);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->LWP_RefSpeed,
      &kcg_c2->LWP_RefSpeed);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->RightWheelRefSpeed,
      &kcg_c2->RightWheelRefSpeed);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->LeftWheelRefSpeed,
      &kcg_c2->LeftWheelRefSpeed);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->RightWheelSpeed,
      &kcg_c2->RightWheelSpeed);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->LeftWheelSpeed,
      &kcg_c2->LeftWheelSpeed);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessSpeedData */

#ifdef kcg_use_tBCU_an
kcg_bool kcg_comp_tBCU_an(tBCU_an *kcg_c1, tBCU_an *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tAutobrakeState(
      &kcg_c1->AutobrakeState,
      &kcg_c2->AutobrakeState);
  return kcg_equ;
}
#endif /* kcg_use_tBCU_an */

#ifdef kcg_use_tIOR_ProcessThrottleData
kcg_bool kcg_comp_tIOR_ProcessThrottleData(
  tIOR_ProcessThrottleData *kcg_c1,
  tIOR_ProcessThrottleData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->ThrottleIdleBoth == kcg_c2->ThrottleIdleBoth);
  kcg_equ = kcg_equ & (kcg_c1->ThrottleIdleAtLeastOne ==
      kcg_c2->ThrottleIdleAtLeastOne);
  kcg_equ = kcg_equ & (kcg_c1->RightThrottleIdle == kcg_c2->RightThrottleIdle);
  kcg_equ = kcg_equ & (kcg_c1->LeftThrottleIdle == kcg_c2->LeftThrottleIdle);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessThrottleData */

#ifdef kcg_use_tBrakeSelectOut
kcg_bool kcg_comp_tBrakeSelectOut(
  tBrakeSelectOut *kcg_c1,
  tBrakeSelectOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->RightBrakePressureCommand ==
      kcg_c2->RightBrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->LeftBrakePressureCommand ==
      kcg_c2->LeftBrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->SOV_Open == kcg_c2->SOV_Open);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeSelectOut */

#ifdef kcg_use_tTestData
kcg_bool kcg_comp_tTestData(tTestData *kcg_c1, tTestData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->maxpedal == kcg_c2->maxpedal);
  kcg_equ = kcg_equ & (kcg_c1->unlatch == kcg_c2->unlatch);
  kcg_equ = kcg_equ & (kcg_c1->latch == kcg_c2->latch);
  kcg_equ = kcg_equ & (kcg_c1->ARMdisagree == kcg_c2->ARMdisagree);
  kcg_equ = kcg_equ & (kcg_c1->AUTOBRKfault == kcg_c2->AUTOBRKfault);
  return kcg_equ;
}
#endif /* kcg_use_tTestData */

#ifdef kcg_use_tBrakeSkidOut
kcg_bool kcg_comp_tBrakeSkidOut(tBrakeSkidOut *kcg_c1, tBrakeSkidOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->RightBrakePressureCommandAdj ==
      kcg_c2->RightBrakePressureCommandAdj);
  kcg_equ = kcg_equ & (kcg_c1->RightSkidEnable == kcg_c2->RightSkidEnable);
  kcg_equ = kcg_equ & (kcg_c1->Ratio == kcg_c2->Ratio);
  kcg_equ = kcg_equ & (kcg_c1->LeftBrakePressureCommandAdj ==
      kcg_c2->LeftBrakePressureCommandAdj);
  kcg_equ = kcg_equ & (kcg_c1->LeftSkidEnable == kcg_c2->LeftSkidEnable);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeSkidOut */

#ifdef kcg_use_tBrakeAutoBKOut
kcg_bool kcg_comp_tBrakeAutoBKOut(
  tBrakeAutoBKOut *kcg_c1,
  tBrakeAutoBKOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tTestData(&kcg_c1->testData, &kcg_c2->testData);
  kcg_equ = kcg_equ & (kcg_c1->CoilEnergized == kcg_c2->CoilEnergized);
  kcg_equ = kcg_equ & kcg_comp_tAutobrakeState(
      &kcg_c1->AutoBrakeState,
      &kcg_c2->AutoBrakeState);
  kcg_equ = kcg_equ & (kcg_c1->ArmDisagree == kcg_c2->ArmDisagree);
  kcg_equ = kcg_equ & (kcg_c1->Right_BrakePressureCommand ==
      kcg_c2->Right_BrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->Left_BrakePressureCommand ==
      kcg_c2->Left_BrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->AutoBrakeActivate == kcg_c2->AutoBrakeActivate);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeAutoBKOut */

#ifdef kcg_use_tData_to_DSP
kcg_bool kcg_comp_tData_to_DSP(tData_to_DSP *kcg_c1, tData_to_DSP *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_Longitudinal_Acceleration_Body_Right_331,
      &kcg_c2->In_Longitudinal_Acceleration_Body_Right_331);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->_1_In_Longitudinal_Acceleration_Body_Left_331,
      &kcg_c2->_1_In_Longitudinal_Acceleration_Body_Left_331);
  kcg_equ = kcg_equ & (kcg_c1->In_Computed_WOW2_Data_277 ==
      kcg_c2->In_Computed_WOW2_Data_277);
  kcg_equ = kcg_equ & (kcg_c1->In_Computed_WOW1_Data_277 ==
      kcg_c2->In_Computed_WOW1_Data_277);
  kcg_equ = kcg_equ & (kcg_c1->In_MLG_LtDownlocked ==
      kcg_c2->In_MLG_LtDownlocked);
  kcg_equ = kcg_equ & (kcg_c1->In_MLG_RtDownlocked ==
      kcg_c2->In_MLG_RtDownlocked);
  kcg_equ = kcg_equ & (kcg_c1->In_Date_Master_260 == kcg_c2->In_Date_Master_260);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_Computed_Air_Speed_206,
      &kcg_c2->In_Computed_Air_Speed_206);
  kcg_equ = kcg_equ & (kcg_c1->In_Master_Time_150 == kcg_c2->In_Master_Time_150);
  kcg_equ = kcg_equ & (kcg_c1->In_TLA_Position_Right_133 ==
      kcg_c2->In_TLA_Position_Right_133);
  kcg_equ = kcg_equ & (kcg_c1->In_TLA_Position_Left_133 ==
      kcg_c2->In_TLA_Position_Left_133);
  kcg_equ = kcg_equ & (kcg_c1->In_Accumulator_Pressure_126 ==
      kcg_c2->In_Accumulator_Pressure_126);
  kcg_equ = kcg_equ & (kcg_c1->In_Hydraulic_System_Pressure_60 ==
      kcg_c2->In_Hydraulic_System_Pressure_60);
  kcg_equ = kcg_equ & (kcg_c1->In_SOV_Current == kcg_c2->In_SOV_Current);
  kcg_equ = kcg_equ & (kcg_c1->In_Left_BCV_Current ==
      kcg_c2->In_Left_BCV_Current);
  kcg_equ = kcg_equ & (kcg_c1->In_Right_BCV_Current ==
      kcg_c2->In_Right_BCV_Current);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_CPLT_RT_LVDT_Percent,
      &kcg_c2->In_CPLT_RT_LVDT_Percent);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_CPLT_LT_LVDT_Percent,
      &kcg_c2->In_CPLT_LT_LVDT_Percent);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_PLT_RT_LVDT_Percent,
      &kcg_c2->In_PLT_RT_LVDT_Percent);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_PLT_LT_LVDT_Percent,
      &kcg_c2->In_PLT_LT_LVDT_Percent);
  kcg_equ = kcg_equ & (kcg_c1->In_HcRightBrakeTemperature ==
      kcg_c2->In_HcRightBrakeTemperature);
  kcg_equ = kcg_equ & (kcg_c1->In_HcLeftBrakeTemperature ==
      kcg_c2->In_HcLeftBrakeTemperature);
  kcg_equ = kcg_equ & (kcg_c1->In_HcRightBrakePressure ==
      kcg_c2->In_HcRightBrakePressure);
  kcg_equ = kcg_equ & (kcg_c1->In_HcLeftBrakePressure ==
      kcg_c2->In_HcLeftBrakePressure);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_HcRightWheelAngularSpeed,
      &kcg_c2->In_HcRightWheelAngularSpeed);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->In_HcLeftWheelAngularSpeed,
      &kcg_c2->In_HcLeftWheelAngularSpeed);
  kcg_equ = kcg_equ & kcg_comp_tIn_Discrete(
      &kcg_c1->In_Discrete,
      &kcg_c2->In_Discrete);
  return kcg_equ;
}
#endif /* kcg_use_tData_to_DSP */

#ifdef kcg_use_tBrakePdlOut
kcg_bool kcg_comp_tBrakePdlOut(tBrakePdlOut *kcg_c1, tBrakePdlOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->PedalBrakeActivate == kcg_c2->PedalBrakeActivate);
  kcg_equ = kcg_equ & (kcg_c1->RightPDL_BrakePressureCommand ==
      kcg_c2->RightPDL_BrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->LeftPDL_BrakePressureCommand ==
      kcg_c2->LeftPDL_BrakePressureCommand);
  return kcg_equ;
}
#endif /* kcg_use_tBrakePdlOut */

#ifdef kcg_use_tValidityF32
kcg_bool kcg_comp_tValidityF32(tValidityF32 *kcg_c1, tValidityF32 *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->Value == kcg_c2->Value);
  kcg_equ = kcg_equ & (kcg_c1->Valid == kcg_c2->Valid);
  return kcg_equ;
}
#endif /* kcg_use_tValidityF32 */

#ifdef kcg_use_tAutobrakeState
kcg_bool kcg_comp_tAutobrakeState(
  tAutobrakeState *kcg_c1,
  tAutobrakeState *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->OFFState == kcg_c2->OFFState);
  kcg_equ = kcg_equ & (kcg_c1->RTOApplicationState ==
      kcg_c2->RTOApplicationState);
  kcg_equ = kcg_equ & (kcg_c1->RTODisarmedState == kcg_c2->RTODisarmedState);
  kcg_equ = kcg_equ & (kcg_c1->RTOEnabledState == kcg_c2->RTOEnabledState);
  kcg_equ = kcg_equ & (kcg_c1->RTOArmedState == kcg_c2->RTOArmedState);
  kcg_equ = kcg_equ & (kcg_c1->LandingDisArmedState ==
      kcg_c2->LandingDisArmedState);
  kcg_equ = kcg_equ & (kcg_c1->LandingEnabledState ==
      kcg_c2->LandingEnabledState);
  kcg_equ = kcg_equ & (kcg_c1->LandingApplicationState ==
      kcg_c2->LandingApplicationState);
  kcg_equ = kcg_equ & (kcg_c1->LandingArmedState == kcg_c2->LandingArmedState);
  return kcg_equ;
}
#endif /* kcg_use_tAutobrakeState */

#ifdef kcg_use_tBrakeInhibits
kcg_bool kcg_comp_tBrakeInhibits(tBrakeInhibits *kcg_c1, tBrakeInhibits *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->LWP_RightBrakeInhibit ==
      kcg_c2->LWP_RightBrakeInhibit);
  kcg_equ = kcg_equ & (kcg_c1->LWP_LeftBrakeInhibit ==
      kcg_c2->LWP_LeftBrakeInhibit);
  kcg_equ = kcg_equ & (kcg_c1->TDP_BrakeInhibit == kcg_c2->TDP_BrakeInhibit);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeInhibits */

#ifdef kcg_use_tIOR_ProcessAutoFlightData
kcg_bool kcg_comp_tIOR_ProcessAutoFlightData(
  tIOR_ProcessAutoFlightData *kcg_c1,
  tIOR_ProcessAutoFlightData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->TOGA_Active,
      &kcg_c2->TOGA_Active);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessAutoFlightData */

#ifdef kcg_use_tIOR_ProcessAutobrakeData
kcg_bool kcg_comp_tIOR_ProcessAutobrakeData(
  tIOR_ProcessAutobrakeData *kcg_c1,
  tIOR_ProcessAutobrakeData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->AutoBRKfault == kcg_c2->AutoBRKfault);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_RTO,
      &kcg_c2->AutoBRK_RTO);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_HI,
      &kcg_c2->AutoBRK_HI);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_MED,
      &kcg_c2->AutoBRK_MED);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_LOW,
      &kcg_c2->AutoBRK_LOW);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_OFF,
      &kcg_c2->AutoBRK_OFF);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessAutobrakeData */

#ifdef kcg_use_tBrakeIfbOut
kcg_bool kcg_comp_tBrakeIfbOut(tBrakeIfbOut *kcg_c1, tBrakeIfbOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->RightIFB_BrakePressureCommand ==
      kcg_c2->RightIFB_BrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->LeftIFB_BrakePressureCommand ==
      kcg_c2->LeftIFB_BrakePressureCommand);
  kcg_equ = kcg_equ & (kcg_c1->IFB_BrakeActivate == kcg_c2->IFB_BrakeActivate);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeIfbOut */

#ifdef kcg_use_tValidityS32
kcg_bool kcg_comp_tValidityS32(tValidityS32 *kcg_c1, tValidityS32 *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->Value == kcg_c2->Value);
  kcg_equ = kcg_equ & (kcg_c1->Valid == kcg_c2->Valid);
  return kcg_equ;
}
#endif /* kcg_use_tValidityS32 */

#ifdef kcg_use_tINPUT_Data
kcg_bool kcg_comp_tINPUT_Data(tINPUT_Data *kcg_c1, tINPUT_Data *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessSpeedData(
      &kcg_c1->WheelSpeedData,
      &kcg_c2->WheelSpeedData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessAutobrakeData(
      &kcg_c1->AutoBrakeData,
      &kcg_c2->AutoBrakeData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessHydraulicData(
      &kcg_c1->HydraulicData,
      &kcg_c2->HydraulicData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessLandingGearData(
      &kcg_c1->LGData,
      &kcg_c2->LGData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessThrottleData(
      &kcg_c1->ThrottleData,
      &kcg_c2->ThrottleData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessPedalData(
      &kcg_c1->PedalData,
      &kcg_c2->PedalData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessWowData(
      &kcg_c1->WOWData,
      &kcg_c2->WOWData);
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessAircraftData(
      &kcg_c1->Aircraft_Data,
      &kcg_c2->Aircraft_Data);
  return kcg_equ;
}
#endif /* kcg_use_tINPUT_Data */

#ifdef kcg_use_tBrakeInhibitOut
kcg_bool kcg_comp_tBrakeInhibitOut(
  tBrakeInhibitOut *kcg_c1,
  tBrakeInhibitOut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tBrakeInhibits(
      &kcg_c1->BrakeInhibits,
      &kcg_c2->BrakeInhibits);
  kcg_equ = kcg_equ & (kcg_c1->RightBrakePressureCommandAdj ==
      kcg_c2->RightBrakePressureCommandAdj);
  kcg_equ = kcg_equ & (kcg_c1->LeftBrakePressureCommandAdj ==
      kcg_c2->LeftBrakePressureCommandAdj);
  kcg_equ = kcg_equ & (kcg_c1->SOV_Open == kcg_c2->SOV_Open);
  return kcg_equ;
}
#endif /* kcg_use_tBrakeInhibitOut */

#ifdef kcg_use_tIOR_ProcessLandingGearData
kcg_bool kcg_comp_tIOR_ProcessLandingGearData(
  tIOR_ProcessLandingGearData *kcg_c1,
  tIOR_ProcessLandingGearData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->LandingGearExtentionandRetractionCommand ==
      kcg_c2->LandingGearExtentionandRetractionCommand);
  kcg_equ = kcg_equ & (kcg_c1->LG_GearDown_Locked == kcg_c2->LG_GearDown_Locked);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessLandingGearData */

#ifdef kcg_use_tValidityU32
kcg_bool kcg_comp_tValidityU32(tValidityU32 *kcg_c1, tValidityU32 *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->Value == kcg_c2->Value);
  kcg_equ = kcg_equ & (kcg_c1->Valid == kcg_c2->Valid);
  return kcg_equ;
}
#endif /* kcg_use_tValidityU32 */

#ifdef kcg_use_tValidityBool
kcg_bool kcg_comp_tValidityBool(tValidityBool *kcg_c1, tValidityBool *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->Value == kcg_c2->Value);
  kcg_equ = kcg_equ & (kcg_c1->Valid == kcg_c2->Valid);
  return kcg_equ;
}
#endif /* kcg_use_tValidityBool */

#ifdef kcg_use_tBRAKE_Auto
kcg_bool kcg_comp_tBRAKE_Auto(tBRAKE_Auto *kcg_c1, tBRAKE_Auto *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->AutoBrakeEnable == kcg_c2->AutoBrakeEnable);
  kcg_equ = kcg_equ & (kcg_c1->AutoBrakeCommand_R == kcg_c2->AutoBrakeCommand_R);
  kcg_equ = kcg_equ & (kcg_c1->AutoBrakeCommand_L == kcg_c2->AutoBrakeCommand_L);
  return kcg_equ;
}
#endif /* kcg_use_tBRAKE_Auto */

#ifdef kcg_use_tOutPut
kcg_bool kcg_comp_tOutPut(tOutPut *kcg_c1, tOutPut *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tIOR_ProcessSpeedData(
      &kcg_c1->speed,
      &kcg_c2->speed);
  kcg_equ = kcg_equ & (kcg_c1->WOW429 == kcg_c2->WOW429);
  kcg_equ = kcg_equ & (kcg_c1->WOWBK == kcg_c2->WOWBK);
  kcg_equ = kcg_equ & kcg_comp_tBrakeSkidOut(
      &kcg_c1->BrakeSkidOut,
      &kcg_c2->BrakeSkidOut);
  kcg_equ = kcg_equ & kcg_comp_tBrakeSelectOut(
      &kcg_c1->BrakeSelectOut,
      &kcg_c2->BrakeSelectOut);
  kcg_equ = kcg_equ & kcg_comp_tBrakePdlOut(
      &kcg_c1->BrakePdlOut,
      &kcg_c2->BrakePdlOut);
  kcg_equ = kcg_equ & kcg_comp_tBrakeInhibitOut(
      &kcg_c1->BrakeInhibitOut,
      &kcg_c2->BrakeInhibitOut);
  kcg_equ = kcg_equ & kcg_comp_tBrakeIfbOut(
      &kcg_c1->BrakeIfbOut,
      &kcg_c2->BrakeIfbOut);
  kcg_equ = kcg_equ & kcg_comp_tBrakeAutoBKOut(
      &kcg_c1->BrakeAutoBKOut,
      &kcg_c2->BrakeAutoBKOut);
  kcg_equ = kcg_equ & (kcg_c1->BrakePressureCommand_R ==
      kcg_c2->BrakePressureCommand_R);
  kcg_equ = kcg_equ & (kcg_c1->BrakePressureCommand_L ==
      kcg_c2->BrakePressureCommand_L);
  kcg_equ = kcg_equ & (kcg_c1->SOV_Open == kcg_c2->SOV_Open);
  return kcg_equ;
}
#endif /* kcg_use_tOutPut */

#ifdef kcg_use_tIOR_ProcessAircraftData
kcg_bool kcg_comp_tIOR_ProcessAircraftData(
  tIOR_ProcessAircraftData *kcg_c1,
  tIOR_ProcessAircraftData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->AircraftAttitude,
      &kcg_c2->AircraftAttitude);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->AircraftGroundSpeed,
      &kcg_c2->AircraftGroundSpeed);
  kcg_equ = kcg_equ & (kcg_c1->SpoilerStoredSignal_Right ==
      kcg_c2->SpoilerStoredSignal_Right);
  kcg_equ = kcg_equ & (kcg_c1->SpoilerStoredSignal_Left ==
      kcg_c2->SpoilerStoredSignal_Left);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->AircraftAcceleration_av,
      &kcg_c2->AircraftAcceleration_av);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->AircraftAcceleration1_Right,
      &kcg_c2->AircraftAcceleration1_Right);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->AircraftAcceleration_Left,
      &kcg_c2->AircraftAcceleration_Left);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(&kcg_c1->Airspeed, &kcg_c2->Airspeed);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessAircraftData */

#ifdef kcg_use_tIn_Discrete
kcg_bool kcg_comp_tIn_Discrete(tIn_Discrete *kcg_c1, tIn_Discrete *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->PIN_PGR_2 == kcg_c2->PIN_PGR_2);
  kcg_equ = kcg_equ & (kcg_c1->PIN_PGR_1 == kcg_c2->PIN_PGR_1);
  kcg_equ = kcg_equ & (kcg_c1->spare == kcg_c2->spare);
  kcg_equ = kcg_equ & (kcg_c1->Parking_brake_signal ==
      kcg_c2->Parking_brake_signal);
  kcg_equ = kcg_equ & (kcg_c1->Inner_wheel_ABS_start_signal ==
      kcg_c2->Inner_wheel_ABS_start_signal);
  kcg_equ = kcg_equ & (kcg_c1->GearHandle == kcg_c2->GearHandle);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_RTO,
      &kcg_c2->AutoBRK_RTO);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_HI,
      &kcg_c2->AutoBRK_HI);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_MED,
      &kcg_c2->AutoBRK_MED);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_LOW,
      &kcg_c2->AutoBRK_LOW);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(
      &kcg_c1->AutoBRK_OFF,
      &kcg_c2->AutoBRK_OFF);
  kcg_equ = kcg_equ & (kcg_c1->ThrottleIdleBoth == kcg_c2->ThrottleIdleBoth);
  kcg_equ = kcg_equ & (kcg_c1->ThrottleIdleAtLeastOne ==
      kcg_c2->ThrottleIdleAtLeastOne);
  kcg_equ = kcg_equ & (kcg_c1->RightThrottleIdle == kcg_c2->RightThrottleIdle);
  kcg_equ = kcg_equ & (kcg_c1->LeftThrottleIdle == kcg_c2->LeftThrottleIdle);
  kcg_equ = kcg_equ & (kcg_c1->RightWOW == kcg_c2->RightWOW);
  kcg_equ = kcg_equ & (kcg_c1->LeftWOW == kcg_c2->LeftWOW);
  kcg_equ = kcg_equ & (kcg_c1->SpoilerStoredSignal_Right ==
      kcg_c2->SpoilerStoredSignal_Right);
  kcg_equ = kcg_equ & (kcg_c1->SpoilerStoredSignal_Left ==
      kcg_c2->SpoilerStoredSignal_Left);
  return kcg_equ;
}
#endif /* kcg_use_tIn_Discrete */

#ifdef kcg_use_tIOR_ProcessHydraulicData
kcg_bool kcg_comp_tIOR_ProcessHydraulicData(
  tIOR_ProcessHydraulicData *kcg_c1,
  tIOR_ProcessHydraulicData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->HighPressure == kcg_c2->HighPressure);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessHydraulicData */

#ifdef kcg_use_HcDiscreteWord
kcg_bool kcg_comp_HcDiscreteWord(HcDiscreteWord *kcg_c1, HcDiscreteWord *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_RTO_IB == kcg_c2->AutoBK_RTO_IB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_HI_IB == kcg_c2->AutoBK_HI_IB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_MED_IB == kcg_c2->AutoBK_MED_IB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_LOW_IB == kcg_c2->AutoBK_LOW_IB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_OFF_IB == kcg_c2->AutoBK_OFF_IB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_GearHandle_IB == kcg_c2->Hc_GearHandle_IB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_Rt_WOW == kcg_c2->Hc_Rt_WOW);
  kcg_equ = kcg_equ & (kcg_c1->Hc_ABS_IB == kcg_c2->Hc_ABS_IB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_Parkbrakeon_IB == kcg_c2->Hc_Parkbrakeon_IB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_LtThrottle_idle == kcg_c2->Hc_LtThrottle_idle);
  kcg_equ = kcg_equ & (kcg_c1->Hc_LtSpoiler_stowed ==
      kcg_c2->Hc_LtSpoiler_stowed);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_RTO_OB == kcg_c2->AutoBK_RTO_OB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_HI_OB == kcg_c2->AutoBK_HI_OB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_MED_OB == kcg_c2->AutoBK_MED_OB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_LOW_OB == kcg_c2->AutoBK_LOW_OB);
  kcg_equ = kcg_equ & (kcg_c1->AutoBK_OFF_OB == kcg_c2->AutoBK_OFF_OB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_GearHandle_OB == kcg_c2->Hc_GearHandle_OB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_Lt_WOW == kcg_c2->Hc_Lt_WOW);
  kcg_equ = kcg_equ & (kcg_c1->Hc_ABS_OB == kcg_c2->Hc_ABS_OB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_Parkbrakeon_OB == kcg_c2->Hc_Parkbrakeon_OB);
  kcg_equ = kcg_equ & (kcg_c1->Hc_RtThrottle_idle == kcg_c2->Hc_RtThrottle_idle);
  kcg_equ = kcg_equ & (kcg_c1->Hc_RtSpoiler_stowed ==
      kcg_c2->Hc_RtSpoiler_stowed);
  return kcg_equ;
}
#endif /* kcg_use_HcDiscreteWord */

#ifdef kcg_use_tIOR_ProcessPedalData
kcg_bool kcg_comp_tIOR_ProcessPedalData(
  tIOR_ProcessPedalData *kcg_c1,
  tIOR_ProcessPedalData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->MaxPedal == kcg_c2->MaxPedal);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->RightPPedal,
      &kcg_c2->RightPPedal);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->LeftPPedal,
      &kcg_c2->LeftPPedal);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->RightCptPedal,
      &kcg_c2->RightCptPedal);
  kcg_equ = kcg_equ & kcg_comp_tValidityF32(
      &kcg_c1->LeftCptPedal,
      &kcg_c2->LeftCptPedal);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessPedalData */

#ifdef kcg_use_tIOR_ProcessWowData
kcg_bool kcg_comp_tIOR_ProcessWowData(
  tIOR_ProcessWowData *kcg_c1,
  tIOR_ProcessWowData *kcg_c2)
{
  kcg_bool kcg_equ;

  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & (kcg_c1->WOWBK == kcg_c2->WOWBK);
  kcg_equ = kcg_equ & kcg_comp_tValidityBool(&kcg_c1->zong, &kcg_c2->zong);
  kcg_equ = kcg_equ & (kcg_c1->RightWOW == kcg_c2->RightWOW);
  kcg_equ = kcg_equ & (kcg_c1->LeftWOW == kcg_c2->LeftWOW);
  return kcg_equ;
}
#endif /* kcg_use_tIOR_ProcessWowData */

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** kcg_types.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

