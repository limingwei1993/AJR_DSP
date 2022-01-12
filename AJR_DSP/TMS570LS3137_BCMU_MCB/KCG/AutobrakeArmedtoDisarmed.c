/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutobrakeArmedtoDisarmed.h"

/* AutobrakeArmedtoDisarmed */
kcg_bool AutobrakeArmedtoDisarmed(
  /* AutobrakeArmedtoDisarmed::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* AutobrakeArmedtoDisarmed::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* AutobrakeArmedtoDisarmed::BCSfaults */ kcg_bool BCSfaults,
  /* AutobrakeArmedtoDisarmed::Maxpedal */ kcg_float32 Maxpedal,
  /* AutobrakeArmedtoDisarmed::CoilEnergized */ kcg_bool CoilEnergized,
  /* AutobrakeArmedtoDisarmed::ArmDisagree */ kcg_bool ArmDisagree)
{
  /* AutobrakeArmedtoDisarmed::LandingArmedDisarmed */ kcg_bool LandingArmedDisarmed;

  LandingArmedDisarmed = BCSfaults | (AutoBrk_RTO | AutoBrk_OFF) | (Maxpedal >=
      PedaldisArm) | !CoilEnergized | ArmDisagree;
  return LandingArmedDisarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutobrakeArmedtoDisarmed.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

