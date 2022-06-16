/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _AutoBrake_EnabletoDisArm_H_
#define _AutoBrake_EnabletoDisArm_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* AutoBrake_EnabletoDisArm */
extern kcg_bool AutoBrake_EnabletoDisArm(
  /* AutoBrake_EnabletoDisArm::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* AutoBrake_EnabletoDisArm::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* AutoBrake_EnabletoDisArm::BCSfaults */ kcg_bool BCSfaults,
  /* AutoBrake_EnabletoDisArm::CoilEnergized */ kcg_bool CoilEnergized,
  /* AutoBrake_EnabletoDisArm::ArmDisagree */ kcg_bool ArmDisagree);

#endif /* _AutoBrake_EnabletoDisArm_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutoBrake_EnabletoDisArm.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

