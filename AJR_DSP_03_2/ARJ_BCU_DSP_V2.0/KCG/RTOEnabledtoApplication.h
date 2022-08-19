/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _RTOEnabledtoApplication_H_
#define _RTOEnabledtoApplication_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* RTOEnabledtoApplication */
extern void RTOEnabledtoApplication(
  /* RTOEnabledtoApplication::RTOEnabled */ kcg_bool RTOEnabled,
  /* RTOEnabledtoApplication::Idel_Position_Discrete_L */ kcg_bool Idel_Position_Discrete_L,
  /* RTOEnabledtoApplication::Idel_Position_Discrete_R */ kcg_bool Idel_Position_Discrete_R,
  /* RTOEnabledtoApplication::Wheel_speed_av */ kcg_float32 Wheel_speed_av,
  /* RTOEnabledtoApplication::RTOMAXApplication */ kcg_bool *RTOMAXApplication,
  /* RTOEnabledtoApplication::RTONormalApplication */ kcg_bool *RTONormalApplication);

#endif /* _RTOEnabledtoApplication_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOEnabledtoApplication.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

