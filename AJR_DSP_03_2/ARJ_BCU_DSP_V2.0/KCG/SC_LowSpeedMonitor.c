/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SC_LowSpeedMonitor.h"

#ifndef KCG_USER_DEFINED_INIT
void SC_LowSpeedMonitor_init(outC_SC_LowSpeedMonitor *outC)
{
  outC->SkidEnable = kcg_true;
  outC->SM_LowSpeedMonitor_state_nxt = SSM_st_StateDisabled_SM_LowSpeedMonitor;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void SC_LowSpeedMonitor_reset(outC_SC_LowSpeedMonitor *outC)
{
  outC->SM_LowSpeedMonitor_state_nxt = SSM_st_StateDisabled_SM_LowSpeedMonitor;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** BCUSW-739 */
/** BCUSW-740 */
/** "Title_1" {Title = "LLR1 : Skid Control low speed monitor"} */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-739;BCUSW-740"} */
/* SC_LowSpeedMonitor */
void SC_LowSpeedMonitor(
  /* SC_LowSpeedMonitor::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  outC_SC_LowSpeedMonitor *outC)
{
  /* SC_LowSpeedMonitor::SM_LowSpeedMonitor */ SSM_ST_SM_LowSpeedMonitor SM_LowSpeedMonitor_state_act;

  /* sel_SM_LowSpeedMonitor */ switch (outC->SM_LowSpeedMonitor_state_nxt) {
    case SSM_st_StateEnabled_SM_LowSpeedMonitor :
      if (WheelRefSpeed < kcg_lit_float32(5.556)) {
        SM_LowSpeedMonitor_state_act = SSM_st_StateDisabled_SM_LowSpeedMonitor;
      }
      else {
        SM_LowSpeedMonitor_state_act = SSM_st_StateEnabled_SM_LowSpeedMonitor;
      }
      break;
    case SSM_st_StateDisabled_SM_LowSpeedMonitor :
      if (WheelRefSpeed >= kcg_lit_float32(8.333)) {
        SM_LowSpeedMonitor_state_act = SSM_st_StateEnabled_SM_LowSpeedMonitor;
      }
      else {
        SM_LowSpeedMonitor_state_act = SSM_st_StateDisabled_SM_LowSpeedMonitor;
      }
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
  /* act_SM_LowSpeedMonitor */ switch (SM_LowSpeedMonitor_state_act) {
    case SSM_st_StateEnabled_SM_LowSpeedMonitor :
      outC->SkidEnable = kcg_true;
      outC->SM_LowSpeedMonitor_state_nxt = SSM_st_StateEnabled_SM_LowSpeedMonitor;
      break;
    case SSM_st_StateDisabled_SM_LowSpeedMonitor :
      outC->SkidEnable = kcg_false;
      outC->SM_LowSpeedMonitor_state_nxt = SSM_st_StateDisabled_SM_LowSpeedMonitor;
      break;

    default :
      /* this default branch is unreachable */
      break;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_LowSpeedMonitor.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

