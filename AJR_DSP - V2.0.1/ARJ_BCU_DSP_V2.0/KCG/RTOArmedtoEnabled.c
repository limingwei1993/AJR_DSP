/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RTOArmedtoEnabled.h"

/* RTOArmedtoEnabled */
kcg_bool RTOArmedtoEnabled(
  /* RTOArmedtoEnabled::Wheel_speed_av */ kcg_float32 Wheel_speed_av)
{
  /* RTOArmedtoEnabled::RTOEnabled */ kcg_bool RTOEnabled;

  RTOEnabled = Wheel_speed_av > Brakespeed;
  return RTOEnabled;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOArmedtoEnabled.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

