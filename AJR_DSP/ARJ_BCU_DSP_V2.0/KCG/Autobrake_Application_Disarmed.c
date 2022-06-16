/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_Application_Disarmed.h"

/* Autobrake_Application_Disarmed */
kcg_bool Autobrake_Application_Disarmed(
  /* Autobrake_Application_Disarmed::BCSfaults */ kcg_bool BCSfaults,
  /* Autobrake_Application_Disarmed::Maxpedal */ kcg_float32 Maxpedal,
  /* Autobrake_Application_Disarmed::Idle_Position_Discrete_L */ kcg_bool Idle_Position_Discrete_L,
  /* Autobrake_Application_Disarmed::Idle_Position_Discrete_R */ kcg_bool Idle_Position_Discrete_R,
  /* Autobrake_Application_Disarmed::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* Autobrake_Application_Disarmed::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* Autobrake_Application_Disarmed::SpoilerStored_Left */ kcg_bool SpoilerStored_Left,
  /* Autobrake_Application_Disarmed::CoilEnergized */ kcg_bool CoilEnergized,
  /* Autobrake_Application_Disarmed::SpoilerStored_Right */ kcg_bool SpoilerStored_Right)
{
  /* Autobrake_Application_Disarmed::LandingApplication_Disarmed */ kcg_bool LandingApplication_Disarmed;

  LandingApplication_Disarmed = BCSfaults | (Maxpedal > PedaldisArm) |
    !Idle_Position_Discrete_L | !Idle_Position_Discrete_R | AutoBrk_OFF |
    AutoBrk_RTO | (SpoilerStored_Left & SpoilerStored_Right) | CoilEnergized;
  return LandingApplication_Disarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_Application_Disarmed.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

