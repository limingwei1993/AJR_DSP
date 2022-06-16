/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _OFFtoAutobrakeArmed_H_
#define _OFFtoAutobrakeArmed_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* OFFtoAutobrakeArmed */
extern kcg_bool OFFtoAutobrakeArmed(
  /* OFFtoAutobrakeArmed::AutoBrk_LO */ kcg_bool AutoBrk_LO,
  /* OFFtoAutobrakeArmed::AutoBrk_MED */ kcg_bool AutoBrk_MED,
  /* OFFtoAutobrakeArmed::AutoBrk_HI */ kcg_bool AutoBrk_HI,
  /* OFFtoAutobrakeArmed::Maxpedal */ kcg_float32 Maxpedal,
  /* OFFtoAutobrakeArmed::BCSfaults */ kcg_bool BCSfaults,
  /* OFFtoAutobrakeArmed::WOW_BRK */ kcg_bool WOW_BRK);

#endif /* _OFFtoAutobrakeArmed_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** OFFtoAutobrakeArmed.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

