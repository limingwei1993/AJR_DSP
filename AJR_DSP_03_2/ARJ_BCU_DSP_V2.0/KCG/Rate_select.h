/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Rate_select_H_
#define _Rate_select_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */


/* Rate_select */
extern kcg_float32 Rate_select(
  /* Rate_select::Low */ kcg_bool Low,
  /* Rate_select::Med */ kcg_bool Med,
  /* Rate_select::Hi */ kcg_bool Hi,
  /* Rate_select::RTO */ kcg_bool RTO,
  /* Rate_select::Ref */ kcg_float32 Ref);

#endif /* _Rate_select_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Rate_select.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

