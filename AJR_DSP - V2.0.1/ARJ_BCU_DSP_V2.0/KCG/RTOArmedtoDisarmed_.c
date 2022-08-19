/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RTOArmedtoDisarmed_.h"

/* RTOArmedtoDisarmed_ */
kcg_bool RTOArmedtoDisarmed_(
  /* RTOArmedtoDisarmed_::BCSfaults */ kcg_bool BCSfaults,
  /* RTOArmedtoDisarmed_::WOW_BRK */ kcg_bool WOW_BRK,
  /* RTOArmedtoDisarmed_::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* RTOArmedtoDisarmed_::AutoBrk_LO */ kcg_bool AutoBrk_LO,
  /* RTOArmedtoDisarmed_::AutoBrk_MED */ kcg_bool AutoBrk_MED,
  /* RTOArmedtoDisarmed_::AutoBrk_HI */ kcg_bool AutoBrk_HI,
  /* RTOArmedtoDisarmed_::CoilEnergized */ kcg_bool CoilEnergized,
  /* RTOArmedtoDisarmed_::ArmDisagree */ kcg_bool ArmDisagree)
{
  /* RTOArmedtoDisarmed_::RTOArmedtoDisarmed */ kcg_bool RTOArmedtoDisarmed;

  RTOArmedtoDisarmed = BCSfaults | !WOW_BRK | AutoBrk_OFF | AutoBrk_LO |
    AutoBrk_HI | AutoBrk_MED | !CoilEnergized | ArmDisagree;
  return RTOArmedtoDisarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOArmedtoDisarmed_.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

