/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutoBrake.h"

#ifndef KCG_USER_DEFINED_INIT
void AutoBrake_init(outC_AutoBrake *outC)
{
  outC->CoilEnergized = kcg_false;
  outC->ArmDisagree = kcg_false;
  outC->BRAKEAuto.AutoBrakeActivate = kcg_true;
  outC->BRAKEAuto.Left_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->BRAKEAuto.Right_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->BRAKEAuto.ArmDisagree = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.LandingArmedState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.LandingApplicationState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.LandingEnabledState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.LandingDisArmedState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.RTOArmedState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.RTOEnabledState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.RTODisarmedState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.RTOApplicationState = kcg_true;
  outC->BRAKEAuto.AutoBrakeState.OFFState = kcg_true;
  outC->BRAKEAuto.CoilEnergized = kcg_true;
  /* 1 */ stm_init(&outC->_1_Context_1);
  /* 1 */ Autobrake_ARMtoEnable_init(&outC->Context_1);
  outC->SM1_state_nxt = SSM_st_State1_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AutoBrake_reset(outC_AutoBrake *outC)
{
  outC->CoilEnergized = kcg_false;
  outC->ArmDisagree = kcg_false;
  /* 1 */ stm_reset(&outC->_1_Context_1);
  /* 1 */ Autobrake_ARMtoEnable_reset(&outC->Context_1);
  outC->SM1_state_nxt = SSM_st_State1_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* AutoBrake */
void AutoBrake(
  /* AutoBrake::APPData */ tINPUT_Data *APPData,
  /* AutoBrake::WOWBK */ kcg_bool WOWBK,
  outC_AutoBrake *outC)
{
  /* AutoBrake */ kcg_int8 tmp5;
  /* AutoBrake */ kcg_int8 tmp4;
  /* AutoBrake */ kcg_float32 tmp3;
  /* AutoBrake */ kcg_float32 tmp2;
  /* AutoBrake */ kcg_float32 tmp1;
  /* AutoBrake */ kcg_float32 tmp;
  /* AutoBrake::SM1 */ SSM_ST_SM1 SM1_state_act;
  /* AutoBrake::ABSfault */ kcg_bool ABSfault;
  /* AutoBrake::RTOMAXApplication */ kcg_bool RTOMAXApplication;
  /* AutoBrake::_L209 */ kcg_bool _L209;
  /* AutoBrake::_L244 */ kcg_bool _L244;
  /* AutoBrake::_L264 */ kcg_bool _L264;
  /* AutoBrake::_L285 */ kcg_bool _L285;

  _L285 = outC->CoilEnergized;
  _L264 = outC->ArmDisagree;
  /* 1 */ if (_L285) {
    tmp5 = kcg_lit_int8(1);
  }
  else {
    tmp5 = kcg_lit_int8(0);
  }
  /* 1 */ if ((*APPData).AutoBrakeData.AutoBRK_RTO.Value |
    (*APPData).AutoBrakeData.AutoBRK_LOW.Value |
    (*APPData).AutoBrakeData.AutoBRK_MED.Value |
    (*APPData).AutoBrakeData.AutoBRK_HI.Value) {
    tmp4 = kcg_lit_int8(1);
  }
  else {
    tmp4 = kcg_lit_int8(0);
  }
  ABSfault = tmp5 < tmp4;
  /* 1 */
  Autobrake_ARMtoEnable(
    WOWBK,
    (*APPData).WheelSpeedData.WheelSpeed_av,
    &outC->Context_1);
  _L209 = /* 3 */ RTOArmedtoEnabled((*APPData).WheelSpeedData.WheelSpeed_av);
  /* 3 */
  RTOEnabledtoApplication(
    _L209,
    (*APPData).ThrottleData.LeftThrottleIdle,
    (*APPData).ThrottleData.RightThrottleIdle,
    (*APPData).WheelSpeedData.WheelSpeed_av,
    &RTOMAXApplication,
    &_L244);
  /* 1 */
  stm(
    /* 2 */
    OFFtoAutobrakeArmed(
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      (*APPData).PedalData.MaxPedal,
      ABSfault,
      WOWBK),
    /* 2 */
    Autobrake_EnaletoApplication(
      outC->Context_1.LandingEnable,
      (*APPData).ThrottleData.RightThrottleIdle,
      (*APPData).ThrottleData.LeftThrottleIdle),
    /* 2 */
    AutobrakeArmedtoDisarmed(
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value,
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      ABSfault,
      (*APPData).PedalData.MaxPedal,
      _L285,
      _L264),
    /* 2 */
    Autobrake_Application_Disarmed(
      ABSfault,
      (*APPData).PedalData.MaxPedal,
      (*APPData).ThrottleData.LeftThrottleIdle,
      (*APPData).ThrottleData.RightThrottleIdle,
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value,
      (*APPData).Aircraft_Data.SpoilerStoredSignal_Left,
      _L285,
      (*APPData).Aircraft_Data.SpoilerStoredSignal_Right),
    /* 2 */
    OFFtoRTOArmed(
      ABSfault,
      WOWBK,
      (*APPData).WheelSpeedData.WheelSpeed_av,
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value),
    /* 3 */
    RTOApplicationDisarmed_(
      (*APPData).ThrottleData.LeftThrottleIdle,
      (*APPData).ThrottleData.RightThrottleIdle,
      (*APPData).PedalData.MaxPedal,
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      ABSfault,
      WOWBK,
      _L285,
      _L264),
    _L209,
    /* 3 */
    RTOEnabledtoDisarmed_(
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      WOWBK,
      ABSfault,
      _L264,
      _L285),
    /* 3 */
    RTOArmedtoDisarmed_(
      ABSfault,
      WOWBK,
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      _L285,
      _L264),
    RTOMAXApplication,
    _L244,
    outC->Context_1.LandingEnable,
    /* 1 */
    AutoBrake_EnabletoDisArm(
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value,
      (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
      ABSfault,
      _L285,
      _L264),
    &outC->_1_Context_1);
  outC->BRAKEAuto.AutoBrakeState.LandingArmedState =
    outC->_1_Context_1.LandingArmedState;
  outC->BRAKEAuto.AutoBrakeState.LandingApplicationState =
    outC->_1_Context_1.LandingApplicationState;
  outC->BRAKEAuto.AutoBrakeState.LandingEnabledState =
    outC->_1_Context_1.LandingEnableState;
  outC->BRAKEAuto.AutoBrakeState.LandingDisArmedState =
    outC->_1_Context_1.LandingDisarmedState;
  outC->BRAKEAuto.AutoBrakeState.RTOArmedState = outC->_1_Context_1.RTOArmedState;
  outC->BRAKEAuto.AutoBrakeState.RTOEnabledState =
    outC->_1_Context_1.RTOEnabledState;
  outC->BRAKEAuto.AutoBrakeState.RTODisarmedState =
    outC->_1_Context_1.RTODisarmedState;
  outC->BRAKEAuto.AutoBrakeState.RTOApplicationState =
    outC->_1_Context_1.RTOApplicationState;
  outC->BRAKEAuto.AutoBrakeState.OFFState = outC->_1_Context_1.OFF_State;
  _L209 = outC->_1_Context_1.LandingApplicationState |
    outC->_1_Context_1.RTOApplicationState;
  /* 1 */ if ((*APPData).AutoBrakeData.AutoBRK_LOW.Value) {
    tmp3 = Acc_Lo;
  }
  else {
    tmp3 = zero;
  }
  /* 2 */ if ((*APPData).AutoBrakeData.AutoBRK_MED.Value) {
    tmp2 = Acc_MED;
  }
  else {
    tmp2 = zero;
  }
  /* 5 */ if ((*APPData).AutoBrakeData.AutoBRK_HI.Value |
    (*APPData).AutoBrakeData.AutoBRK_RTO.Value) {
    tmp1 = Acc_HI;
  }
  else {
    tmp1 = zero;
  }
  /* 6 */ if (_L209) {
    tmp = kcg_lit_float32(1.);
  }
  else {
    tmp = kcg_lit_float32(0.);
  }
  outC->BRAKEAuto.Left_BrakePressureCommand =
    ((*APPData).Aircraft_Data.AircraftAcceleration_Left.Value - (tmp3 + tmp2 +
        tmp1)) * tmp * kcg_lit_float32(800.);
  outC->BRAKEAuto.Right_BrakePressureCommand =
    outC->BRAKEAuto.Left_BrakePressureCommand;
  outC->BRAKEAuto.AutoBrakeActivate = _L209;
  outC->ArmDisagree = !((outC->_1_Context_1.LandingArmedState ==
        (*APPData).BCU_an.AutobrakeState.LandingArmedState) &
      (outC->_1_Context_1.LandingApplicationState ==
        (*APPData).BCU_an.AutobrakeState.LandingApplicationState) &
      (outC->_1_Context_1.LandingEnableState ==
        (*APPData).BCU_an.AutobrakeState.LandingEnabledState) &
      (outC->_1_Context_1.RTOArmedState ==
        (*APPData).BCU_an.AutobrakeState.RTOArmedState) &
      (outC->_1_Context_1.RTOEnabledState ==
        (*APPData).BCU_an.AutobrakeState.RTOEnabledState) &
      (outC->_1_Context_1.RTOApplicationState ==
        (*APPData).BCU_an.AutobrakeState.RTOApplicationState));
  outC->BRAKEAuto.ArmDisagree = outC->ArmDisagree;
  SM1_state_act = outC->SM1_state_nxt;
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_State1_SM1 :
      outC->CoilEnergized = _L285;
      break;
    case SSM_st_State2_SM1 :
      outC->CoilEnergized = kcg_false;
      break;
    case SSM_st_State3_SM1 :
      outC->CoilEnergized = kcg_true;
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
  outC->BRAKEAuto.CoilEnergized = outC->CoilEnergized;
  _L244 = !ABSfault;
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_State1_SM1 :
      if (_L264 | outC->_1_Context_1.LandingDisarmedState |
        outC->_1_Context_1.OFF_State | outC->_1_Context_1.RTODisarmedState) {
        outC->SM1_state_nxt = SSM_st_State2_SM1;
      }
      else if ((((*APPData).AutoBrakeData.AutoBRK_LOW.Value |
            (*APPData).AutoBrakeData.AutoBRK_MED.Value |
            (*APPData).AutoBrakeData.AutoBRK_HI.Value) &
          ((*APPData).PedalData.MaxPedal < PedaldisArm) & _L244 & !WOWBK) |
        (_L244 & WOWBK & ((*APPData).WheelSpeedData.WheelSpeed_av < RTO_ARM) &
          (*APPData).AutoBrakeData.AutoBRK_RTO.Value)) {
        outC->SM1_state_nxt = SSM_st_State3_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_State1_SM1;
      }
      break;
    case SSM_st_State2_SM1 :
      outC->SM1_state_nxt = SSM_st_State1_SM1;
      break;
    case SSM_st_State3_SM1 :
      outC->SM1_state_nxt = SSM_st_State1_SM1;
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutoBrake.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

