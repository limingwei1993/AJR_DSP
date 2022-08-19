/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutoBrake_EnabletoDisArm.h"

/* AutoBrake_EnabletoDisArm */
kcg_bool AutoBrake_EnabletoDisArm(
  /* AutoBrake_EnabletoDisArm::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* AutoBrake_EnabletoDisArm::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* AutoBrake_EnabletoDisArm::BCSfaults */ kcg_bool BCSfaults,
  /* AutoBrake_EnabletoDisArm::CoilEnergized */ kcg_bool CoilEnergized,
  /* AutoBrake_EnabletoDisArm::ArmDisagree */ kcg_bool ArmDisagree)
{
  /* AutoBrake_EnabletoDisArm::LandingEnabledDisarmed */ kcg_bool LandingEnabledDisarmed;

  LandingEnabledDisarmed = !CoilEnergized | AutoBrk_RTO | AutoBrk_OFF |
    BCSfaults | ArmDisagree;
  return LandingEnabledDisarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutoBrake_EnabletoDisArm.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

