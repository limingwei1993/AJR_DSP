/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RTOApplicationDisarmed_.h"

/* RTOApplicationDisarmed_ */
kcg_bool RTOApplicationDisarmed_(
  /* RTOApplicationDisarmed_::Idel_Position_Discrete_L */ kcg_bool Idel_Position_Discrete_L,
  /* RTOApplicationDisarmed_::Idel_Position_Discrete_R */ kcg_bool Idel_Position_Discrete_R,
  /* RTOApplicationDisarmed_::Maxpedal */ kcg_float32 Maxpedal,
  /* RTOApplicationDisarmed_::AutoBrk_LO */ kcg_bool AutoBrk_LO,
  /* RTOApplicationDisarmed_::AutoBrk_MED */ kcg_bool AutoBrk_MED,
  /* RTOApplicationDisarmed_::AutoBrk_HI */ kcg_bool AutoBrk_HI,
  /* RTOApplicationDisarmed_::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* RTOApplicationDisarmed_::BCSfaults */ kcg_bool BCSfaults,
  /* RTOApplicationDisarmed_::WOWBRK */ kcg_bool WOWBRK,
  /* RTOApplicationDisarmed_::CoilEnergized */ kcg_bool CoilEnergized,
  /* RTOApplicationDisarmed_::ArmDisagree */ kcg_bool ArmDisagree)
{
  /* RTOApplicationDisarmed_::RTOApplicationDisarmed */ kcg_bool RTOApplicationDisarmed;

  RTOApplicationDisarmed = !Idel_Position_Discrete_L |
    !Idel_Position_Discrete_R | (Maxpedal > Pedal_RTO) | AutoBrk_LO |
    AutoBrk_MED | AutoBrk_HI | AutoBrk_OFF | BCSfaults | WOWBRK |
    CoilEnergized | ArmDisagree;
  return RTOApplicationDisarmed;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** RTOApplicationDisarmed_.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

