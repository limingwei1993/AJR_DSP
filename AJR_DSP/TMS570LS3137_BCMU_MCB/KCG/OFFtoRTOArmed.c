/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "OFFtoRTOArmed.h"

/* OFFtoRTOArmed */
kcg_bool OFFtoRTOArmed(
  /* OFFtoRTOArmed::BCSfaults */ kcg_bool BCSfaults,
  /* OFFtoRTOArmed::WOW_BRK */ kcg_bool WOW_BRK,
  /* OFFtoRTOArmed::Wheel_speed_av */ kcg_float32 Wheel_speed_av,
  /* OFFtoRTOArmed::AutoBrk_RTO */ kcg_bool AutoBrk_RTO)
{
  /* OFFtoRTOArmed::RTOArmed */ kcg_bool RTOArmed;

  RTOArmed = !BCSfaults & WOW_BRK & (Wheel_speed_av < RTO_ARM) & AutoBrk_RTO;
  return RTOArmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** OFFtoRTOArmed.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

