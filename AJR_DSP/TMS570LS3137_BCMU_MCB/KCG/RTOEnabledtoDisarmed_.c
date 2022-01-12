/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RTOEnabledtoDisarmed_.h"

/* RTOEnabledtoDisarmed_ */
kcg_bool RTOEnabledtoDisarmed_(
  /* RTOEnabledtoDisarmed_::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* RTOEnabledtoDisarmed_::AutoBrk_LO */ kcg_bool AutoBrk_LO,
  /* RTOEnabledtoDisarmed_::AutoBrk_MED */ kcg_bool AutoBrk_MED,
  /* RTOEnabledtoDisarmed_::AutoBrk_HI */ kcg_bool AutoBrk_HI,
  /* RTOEnabledtoDisarmed_::WOW_BRK */ kcg_bool WOW_BRK,
  /* RTOEnabledtoDisarmed_::BCSfaults */ kcg_bool BCSfaults,
  /* RTOEnabledtoDisarmed_::ArmDisagree */ kcg_bool ArmDisagree,
  /* RTOEnabledtoDisarmed_::CoilEnergized */ kcg_bool CoilEnergized)
{
  /* RTOEnabledtoDisarmed_::RTOEnabledtoDisarmed */ kcg_bool RTOEnabledtoDisarmed;

  RTOEnabledtoDisarmed = AutoBrk_OFF | AutoBrk_LO | AutoBrk_MED | AutoBrk_HI |
    !WOW_BRK | BCSfaults | ArmDisagree | CoilEnergized;
  return RTOEnabledtoDisarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOEnabledtoDisarmed_.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

