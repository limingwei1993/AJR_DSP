/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Ref_cal_H_
#define _Ref_cal_H_

#include "kcg_types.h"
#include "m_to_kt_unit.h"
#include "ft_to_m_unit.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* Ref_cal::refspeed */ refspeed;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_float32 /* Ref_cal::_L9 */ _L9;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Ref_cal;

/* ===========  node initialization and cycle functions  =========== */
/* Ref_cal */
extern void Ref_cal(
  /* Ref_cal::Wheelspeed */ kcg_float32 Wheelspeed,
  /* Ref_cal::acc */ kcg_float32 acc,
  /* Ref_cal::WOW */ kcg_bool WOW,
  outC_Ref_cal *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Ref_cal_reset(outC_Ref_cal *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Ref_cal_init(outC_Ref_cal *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Ref_cal_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Ref_cal.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

