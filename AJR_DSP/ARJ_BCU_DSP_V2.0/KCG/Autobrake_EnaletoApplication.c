/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_EnaletoApplication.h"

/* Autobrake_EnaletoApplication */
kcg_bool Autobrake_EnaletoApplication(
  /* Autobrake_EnaletoApplication::LandingEnable */ kcg_bool LandingEnable,
  /* Autobrake_EnaletoApplication::Idle_Position_Discrete_R */ kcg_bool Idle_Position_Discrete_R,
  /* Autobrake_EnaletoApplication::dle_Position_Discrete_L */ kcg_bool dle_Position_Discrete_L)
{
  /* Autobrake_EnaletoApplication::LandingApplication */ kcg_bool LandingApplication;

  LandingApplication = LandingEnable & Idle_Position_Discrete_R &
    dle_Position_Discrete_L;
  return LandingApplication;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_EnaletoApplication.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

