/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _BrakeInhibit_H_
#define _BrakeInhibit_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* BrakeInhibit */
extern void BrakeInhibit(
  /* BrakeInhibit::TDP */ kcg_bool TDP1,
  /* BrakeInhibit::LWP_L */ kcg_bool LWP_L,
  /* BrakeInhibit::LWP_R */ kcg_bool LWP_R,
  /* BrakeInhibit::BrakeSelectOut */ tBrakeSelectOut *BrakeSelectOut,
  /* BrakeInhibit::BrakeSkidOut */ tBrakeSkidOut *BrakeSkidOut,
  /* BrakeInhibit::BrakeInhibitOut */ tBrakeInhibitOut *BrakeInhibitOut);

#endif /* _BrakeInhibit_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BrakeInhibit.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

