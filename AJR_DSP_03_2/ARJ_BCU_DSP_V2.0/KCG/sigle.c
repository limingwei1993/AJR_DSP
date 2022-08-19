/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "sigle.h"

#ifndef KCG_USER_DEFINED_INIT
void sigle_init(outC_sigle *outC)
{
  outC->LDPActive = kcg_true;
  outC->SM1_state_nxt = SSM_st_LockWheelDisable_SM1;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void sigle_reset(outC_sigle *outC)
{
  outC->SM1_state_nxt = SSM_st_LockWheelDisable_SM1;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* sigle */
void sigle(
  /* sigle::RefWheelspeed */ kcg_float32 RefWheelspeed,
  /* sigle::WheelSpeed */ kcg_float32 WheelSpeed,
  outC_sigle *outC)
{
  /* sigle::SM1 */ _5_SSM_ST_SM1 SM1_state_act;

  /* sel_SM1 */ switch (outC->SM1_state_nxt) {
    case SSM_st_LockWheelEnable_SM1 :
      if (WheelSpeed > RefWheelspeed * kcg_lit_float32(0.35)) {
        SM1_state_act = SSM_st_LockWheelDisable_SM1;
      }
      else {
        SM1_state_act = SSM_st_LockWheelEnable_SM1;
      }
      break;
    case SSM_st_LockWheelDisable_SM1 :
      if (WheelSpeed <= RefWheelspeed * kcg_lit_float32(0.3)) {
        SM1_state_act = SSM_st_LockWheelEnable_SM1;
      }
      else {
        SM1_state_act = SSM_st_LockWheelDisable_SM1;
      }
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_LockWheelEnable_SM1 :
      outC->LDPActive = kcg_true;
      outC->SM1_state_nxt = SSM_st_LockWheelEnable_SM1;
      break;
    case SSM_st_LockWheelDisable_SM1 :
      outC->LDPActive = kcg_false;
      outC->SM1_state_nxt = SSM_st_LockWheelDisable_SM1;
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** sigle.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

