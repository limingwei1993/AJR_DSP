/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Autobrake_Application_Disarmed_H_
#define _Autobrake_Application_Disarmed_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* Autobrake_Application_Disarmed */
extern void Autobrake_Application_Disarmed(
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
  /* Autobrake_Application_Disarmed::LandingApplication_Disarmed */ kcg_bool *LandingApplication_Disarmed);

#endif /* _Autobrake_Application_Disarmed_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_Application_Disarmed.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

