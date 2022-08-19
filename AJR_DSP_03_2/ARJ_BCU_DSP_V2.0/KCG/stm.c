/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "stm.h"

#ifndef KCG_USER_DEFINED_INIT
void stm_init(outC_stm *outC)
{
  outC->OFF_State = kcg_true;
  outC->LandingDisarmedState = kcg_true;
  outC->LandingArmedState = kcg_true;
  outC->LandingApplicationState = kcg_true;
  outC->RTODisarmedState = kcg_true;
  outC->RTOEnabledState = kcg_true;
  outC->RTOApplicationState = kcg_true;
  outC->RTOArmedState = kcg_true;
  outC->LandingEnableState = kcg_true;
  outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void stm_reset(outC_stm *outC)
{
  outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* stm */
void stm(
  /* stm::LandingArmed */ kcg_bool LandingArmed,
  /* stm::LandingApplication */ kcg_bool LandingApplication,
  /* stm::LandingArmedDisarmed */ kcg_bool LandingArmedDisarmed,
  /* stm::LandingApplicationDisarmed */ kcg_bool LandingApplicationDisarmed,
  /* stm::RTOArmed */ kcg_bool RTOArmed,
  /* stm::RTOArmedDisarmed */ kcg_bool RTOArmedDisarmed,
  /* stm::RTOEnabled */ kcg_bool RTOEnabled,
  /* stm::RTOEnabledDisarmed */ kcg_bool RTOEnabledDisarmed,
  /* stm::RTOApplicationDisarmed */ kcg_bool RTOApplicationDisarmed,
  /* stm::RTOMAXApplication */ kcg_bool RTOMAXApplication,
  /* stm::RTONormalApplication */ kcg_bool RTONormalApplication,
  /* stm::LandingEnable */ kcg_bool LandingEnable,
  /* stm::LandingEnableDisarmed */ kcg_bool LandingEnableDisarmed,
  outC_stm *outC)
{
  /* stm::SM1 */ _2_SSM_ST_SM1 SM1_state_act;

  SM1_state_act = outC->SM1_state_nxt;
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_RTOArmedState_SM1 :
      outC->OFF_State = kcg_false;
      outC->RTOArmedState = kcg_true;
      if (RTOArmedDisarmed) {
        outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
      }
      else if (RTOEnabled) {
        outC->SM1_state_nxt = SSM_st_RTOEnabledState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_RTOArmedState_SM1;
      }
      break;
    case SSM_st_OFF_State_SM1 :
      outC->OFF_State = kcg_true;
      outC->LandingDisarmedState = kcg_false;
      outC->LandingArmedState = kcg_false;
      outC->LandingApplicationState = kcg_false;
      outC->RTODisarmedState = kcg_false;
      outC->RTOEnabledState = kcg_false;
      outC->RTOApplicationState = kcg_false;
      outC->RTOArmedState = kcg_false;
      outC->LandingEnableState = kcg_false;
      if (LandingArmed) {
        outC->SM1_state_nxt = SSM_st_LandingArmedState_SM1;
      }
      else if (RTOArmed) {
        outC->SM1_state_nxt = SSM_st_RTOArmedState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
      }
      break;
    case SSM_st_LandingArmedState_SM1 :
      outC->OFF_State = kcg_false;
      outC->LandingArmedState = kcg_true;
      if (LandingEnable) {
        outC->SM1_state_nxt = SSM_st_LandingEnableState_SM1;
      }
      else if (LandingArmedDisarmed) {
        outC->SM1_state_nxt = SSM_st_LandingDisarmedState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_LandingArmedState_SM1;
      }
      break;
    case SSM_st_LandingApplicationState_SM1 :
      outC->LandingApplicationState = kcg_true;
      outC->LandingEnableState = kcg_false;
      if (LandingApplicationDisarmed) {
        outC->SM1_state_nxt = SSM_st_LandingDisarmedState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_LandingApplicationState_SM1;
      }
      break;
    case SSM_st_RTOEnabledState_SM1 :
      outC->RTOEnabledState = kcg_true;
      outC->RTOArmedState = kcg_false;
      if (RTOEnabledDisarmed) {
        outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
      }
      else if (RTONormalApplication) {
        outC->SM1_state_nxt = SSM_st_RTOApplicationState_SM1;
      }
      else if (RTOMAXApplication) {
        outC->SM1_state_nxt = SSM_st_RTOApplicationState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_RTOEnabledState_SM1;
      }
      break;
    case SSM_st_RTOApplicationState_SM1 :
      outC->RTOEnabledState = kcg_false;
      outC->RTOApplicationState = kcg_true;
      if (RTOApplicationDisarmed) {
        outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_RTOApplicationState_SM1;
      }
      break;
    case SSM_st_LandingEnableState_SM1 :
      outC->LandingArmedState = kcg_false;
      outC->LandingEnableState = kcg_true;
      if (LandingEnableDisarmed) {
        outC->SM1_state_nxt = SSM_st_LandingDisarmedState_SM1;
      }
      else if (LandingApplication) {
        outC->SM1_state_nxt = SSM_st_LandingApplicationState_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_LandingEnableState_SM1;
      }
      break;
    case SSM_st_LandingDisarmedState_SM1 :
      outC->LandingDisarmedState = kcg_true;
      outC->LandingArmedState = kcg_false;
      outC->LandingApplicationState = kcg_false;
      outC->LandingEnableState = kcg_false;
      outC->SM1_state_nxt = SSM_st_OFF_State_SM1;
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** stm.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

