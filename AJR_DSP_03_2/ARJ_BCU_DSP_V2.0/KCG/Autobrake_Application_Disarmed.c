/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Autobrake_Application_Disarmed.h"

/* Autobrake_Application_Disarmed */
void Autobrake_Application_Disarmed(
  /* Autobrake_Application_Disarmed::BCSfaults */ kcg_bool BCSfaults,
  /* Autobrake_Application_Disarmed::ARMdisagree */ kcg_bool ARMdisagree,
  /* Autobrake_Application_Disarmed::Maxpedal */ kcg_float32 Maxpedal,
  /* Autobrake_Application_Disarmed::Idle_Position_Discrete_L */ kcg_bool Idle_Position_Discrete_L,
  /* Autobrake_Application_Disarmed::Idle_Position_Discrete_R */ kcg_bool Idle_Position_Discrete_R,
  /* Autobrake_Application_Disarmed::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* Autobrake_Application_Disarmed::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* Autobrake_Application_Disarmed::SpoilerStored_Left */ kcg_bool SpoilerStored_Left,
  /* Autobrake_Application_Disarmed::CoilEnergized */ kcg_bool CoilEnergized,
  /* Autobrake_Application_Disarmed::SpoilerStored_Right */ kcg_bool SpoilerStored_Right,
  /* Autobrake_Application_Disarmed::WOWdisagree */ kcg_bool WOWdisagree,
  /* Autobrake_Application_Disarmed::LandingARM_Disarmed */ kcg_bool *LandingARM_Disarmed,
  /* Autobrake_Application_Disarmed::LandingEnable_Disarmed */ kcg_bool *LandingEnable_Disarmed,
  /* Autobrake_Application_Disarmed::LandingApplication_Disarmed */ kcg_bool *LandingApplication_Disarmed)
{
  /* Autobrake_Application_Disarmed::_L21 */ kcg_bool _L21;

  _L21 = !CoilEnergized | AutoBrk_OFF | AutoBrk_RTO | BCSfaults;
  *LandingEnable_Disarmed = ARMdisagree | _L21;
  *LandingARM_Disarmed = WOWdisagree | *LandingEnable_Disarmed;
  *LandingApplication_Disarmed = _L21 | (Maxpedal > PedaldisArm) |
    !Idle_Position_Discrete_L | !Idle_Position_Discrete_R |
    (SpoilerStored_Left & SpoilerStored_Right);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_Application_Disarmed.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

