/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
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
  outC->BRAKEAuto.testData.AUTOBRKfault = kcg_true;
  outC->BRAKEAuto.testData.ARMdisagree = kcg_true;
  outC->BRAKEAuto.testData.latch = kcg_true;
  outC->BRAKEAuto.testData.unlatch = kcg_true;
  outC->BRAKEAuto.testData.maxpedal = kcg_lit_float32(0.0);
  /* 1 */ PI_Controller_init(&outC->_2_Context_1);
  /* 1 */ stm_init(&outC->_1_Context_1);
  /* 1 */ Autobrake_ARMtoEnable_init(&outC->Context_1);
  /* 4 */ Autobrake_EnaletoApplication_init(&outC->Context_4);
  outC->SM1_state_nxt = SSM_st_State1_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AutoBrake_reset(outC_AutoBrake *outC)
{
  outC->CoilEnergized = kcg_false;
  outC->ArmDisagree = kcg_false;
  /* 1 */ PI_Controller_reset(&outC->_2_Context_1);
  /* 1 */ stm_reset(&outC->_1_Context_1);
  /* 1 */ Autobrake_ARMtoEnable_reset(&outC->Context_1);
  /* 4 */ Autobrake_EnaletoApplication_reset(&outC->Context_4);
  outC->SM1_state_nxt = SSM_st_State1_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* AutoBrake */
void AutoBrake(
  /* AutoBrake::APPData */ tINPUT_Data *APPData,
  outC_AutoBrake *outC)
{
  /* AutoBrake::SM1 */ SSM_ST_SM1 SM1_state_act;
  /* AutoBrake::RTOApplicationDisarmed */ kcg_bool RTOApplicationDisarmed;
  /* AutoBrake::RTOArmedtoDisarmed */ kcg_bool RTOArmedtoDisarmed;
  /* AutoBrake::RTOMAXApplication */ kcg_bool RTOMAXApplication;
  /* AutoBrake::RTONormalApplication */ kcg_bool RTONormalApplication;
  /* AutoBrake::latch */ kcg_bool latch;
  /* AutoBrake::unlatch */ kcg_bool unlatch;
  /* AutoBrake::_L209 */ kcg_bool _L209;
  /* AutoBrake::_L244 */ kcg_bool _L244;
  /* AutoBrake::_L264 */ kcg_bool _L264;
  /* AutoBrake::_L302 */ kcg_bool _L302;

  outC->BRAKEAuto.ArmDisagree = kcg_false;
  _L302 = outC->CoilEnergized;
  _L264 = outC->ArmDisagree;
  outC->ArmDisagree = kcg_false;
  /* 2 */
  Autobrake_Application_Disarmed(
    (*APPData).AutoBrakeData.AutoBRKfault,
    kcg_false,
    (*APPData).PedalData.MaxPedal,
    (*APPData).ThrottleData.RightThrottleIdle,
    (*APPData).ThrottleData.LeftThrottleIdle,
    (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
    (*APPData).AutoBrakeData.AutoBRK_RTO.Value,
    (*APPData).Aircraft_Data.SpoilerStoredSignal_Left,
    _L302,
    (*APPData).Aircraft_Data.SpoilerStoredSignal_Right,
    (kcg_bool) !((*APPData).WOWData.LeftWOW ^ (*APPData).WOWData.RightWOW),
    &latch,
    &_L209,
    &_L244);
  /* 3 */
  RTOApplicationDisarmed_(
    (*APPData).ThrottleData.LeftThrottleIdle,
    (*APPData).ThrottleData.RightThrottleIdle,
    (*APPData).PedalData.MaxPedal,
    (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
    (*APPData).AutoBrakeData.AutoBRK_MED.Value,
    (*APPData).AutoBrakeData.AutoBRK_HI.Value,
    (*APPData).AutoBrakeData.AutoBRK_OFF.Value,
    (*APPData).AutoBrakeData.AutoBRKfault,
    (*APPData).WOWData.WOWBK,
    _L302,
    _L264,
    &RTOArmedtoDisarmed,
    &RTOApplicationDisarmed);
  unlatch = /* 3 */
    RTOArmedtoEnabled((*APPData).WheelSpeedData.LeftWheelRefSpeed.Value);
  /* 3 */
  RTOEnabledtoApplication(
    unlatch,
    (*APPData).ThrottleData.LeftThrottleIdle,
    (*APPData).ThrottleData.RightThrottleIdle,
    (*APPData).WheelSpeedData.WheelSpeed_av,
    &RTOMAXApplication,
    &RTONormalApplication);
  /* 4 */
  Autobrake_EnaletoApplication(
    (*APPData).ThrottleData.RightThrottleIdle,
    (*APPData).ThrottleData.LeftThrottleIdle,
    &outC->Context_4);
  /* 1 */
  Autobrake_ARMtoEnable(
    (*APPData).WOWData.WOWBK,
    (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value,
    &outC->Context_1);
  /* 1 */
  stm(
    /* 2 */
    OFFtoAutobrakeArmed(
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      (*APPData).AutoBrakeData.AutoBRKfault,
      (*APPData).WOWData.WOWBK),
    outC->Context_4.LandingApplication,
    latch,
    _L244,
    /* 2 */
    OFFtoRTOArmed(
      (*APPData).AutoBrakeData.AutoBRKfault,
      (*APPData).WOWData.WOWBK,
      (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value,
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value),
    RTOApplicationDisarmed,
    unlatch,
    RTOArmedtoDisarmed,
    RTOArmedtoDisarmed,
    RTOMAXApplication,
    RTONormalApplication,
    outC->Context_1.LandingEnable,
    _L209,
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
  /* 1 */
  PI_Controller(
    /* 1 */
    Rate_select(
      (*APPData).AutoBrakeData.AutoBRK_LOW.Value,
      (*APPData).AutoBrakeData.AutoBRK_MED.Value,
      (*APPData).AutoBrakeData.AutoBRK_HI.Value,
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value,
      (*APPData).WheelSpeedData.LeftWheelRefSpeed.Value),
    - (*APPData).Aircraft_Data.AircraftAcceleration_av.Value,
    Auto_KP,
    Auto_KI,
    DT,
    zero,
    MaxPressure,
    (kcg_bool) !_L209,
    &outC->_2_Context_1);
  outC->BRAKEAuto.Left_BrakePressureCommand = outC->_2_Context_1.ControlVariable;
  outC->BRAKEAuto.Right_BrakePressureCommand =
    outC->BRAKEAuto.Left_BrakePressureCommand;
  outC->BRAKEAuto.AutoBrakeActivate = _L209;
  SM1_state_act = outC->SM1_state_nxt;
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_State1_SM1 :
      outC->CoilEnergized = _L302;
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
  outC->BRAKEAuto.testData.AUTOBRKfault = (*APPData).AutoBrakeData.AutoBRKfault;
  outC->BRAKEAuto.testData.ARMdisagree = kcg_false;
  outC->BRAKEAuto.testData.maxpedal = (*APPData).PedalData.MaxPedal;
  _L244 = !(*APPData).AutoBrakeData.AutoBRKfault;
  latch = (((*APPData).AutoBrakeData.AutoBRK_HI.Value |
        (*APPData).AutoBrakeData.AutoBRK_LOW.Value |
        (*APPData).AutoBrakeData.AutoBRK_MED.Value) &
      ((*APPData).PedalData.MaxPedal < PedaldisArm) & _L244 &
      !(*APPData).WOWData.WOWBK) | (_L244 & (*APPData).WOWData.WOWBK &
      ((*APPData).WheelSpeedData.LeftWheelRefSpeed.Value < RTO_ARM) &
      (*APPData).AutoBrakeData.AutoBRK_RTO.Value);
  outC->BRAKEAuto.testData.latch = latch;
  unlatch = _L264 | outC->_1_Context_1.LandingDisarmedState |
    outC->_1_Context_1.OFF_State | outC->_1_Context_1.RTODisarmedState;
  outC->BRAKEAuto.testData.unlatch = unlatch;
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_State1_SM1 :
      if (unlatch) {
        outC->SM1_state_nxt = SSM_st_State2_SM1;
      }
      else if (latch) {
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
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

