/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RTOEnabledtoApplication.h"

/* RTOEnabledtoApplication */
void RTOEnabledtoApplication(
  /* RTOEnabledtoApplication::RTOEnabled */ kcg_bool RTOEnabled,
  /* RTOEnabledtoApplication::Idel_Position_Discrete_L */ kcg_bool Idel_Position_Discrete_L,
  /* RTOEnabledtoApplication::Idel_Position_Discrete_R */ kcg_bool Idel_Position_Discrete_R,
  /* RTOEnabledtoApplication::Wheel_speed_av */ kcg_float32 Wheel_speed_av,
  /* RTOEnabledtoApplication::RTOMAXApplication */ kcg_bool *RTOMAXApplication,
  /* RTOEnabledtoApplication::RTONormalApplication */ kcg_bool *RTONormalApplication)
{
  /* RTOEnabledtoApplication::_L7 */ kcg_bool _L7;

  _L7 = RTOEnabled & (Idel_Position_Discrete_L & Idel_Position_Discrete_R);
  *RTONormalApplication = _L7 & (Wheel_speed_av <= RTO);
  *RTOMAXApplication = _L7 & (Wheel_speed_av > RTO);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOEnabledtoApplication.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

