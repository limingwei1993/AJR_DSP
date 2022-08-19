/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _AutobrakeArmedtoDisarmed_H_
#define _AutobrakeArmedtoDisarmed_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* AutobrakeArmedtoDisarmed */
extern kcg_bool AutobrakeArmedtoDisarmed(
  /* AutobrakeArmedtoDisarmed::AutoBrk_RTO */ kcg_bool AutoBrk_RTO,
  /* AutobrakeArmedtoDisarmed::AutoBrk_OFF */ kcg_bool AutoBrk_OFF,
  /* AutobrakeArmedtoDisarmed::BCSfaults */ kcg_bool BCSfaults,
  /* AutobrakeArmedtoDisarmed::Maxpedal */ kcg_float32 Maxpedal,
  /* AutobrakeArmedtoDisarmed::CoilEnergized */ kcg_bool CoilEnergized,
  /* AutobrakeArmedtoDisarmed::ArmDisagree */ kcg_bool ArmDisagree);

#endif /* _AutobrakeArmedtoDisarmed_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutobrakeArmedtoDisarmed.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

