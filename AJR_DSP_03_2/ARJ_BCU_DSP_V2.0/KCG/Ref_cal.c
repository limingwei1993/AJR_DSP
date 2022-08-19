/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Ref_cal.h"

#ifndef KCG_USER_DEFINED_INIT
void Ref_cal_init(outC_Ref_cal *outC)
{
  outC->refspeed = kcg_lit_float32(0.0);
  outC->_L9 = kcg_lit_float32(0.);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Ref_cal_reset(outC_Ref_cal *outC)
{
  outC->_L9 = kcg_lit_float32(0.);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Ref_cal */
void Ref_cal(
  /* Ref_cal::Wheelspeed */ kcg_float32 Wheelspeed,
  /* Ref_cal::acc */ kcg_float32 acc,
  /* Ref_cal::WOW */ kcg_bool WOW,
  outC_Ref_cal *outC)
{
  /* Ref_cal */ kcg_float32 tmp1;
  /* Ref_cal */ kcg_float32 tmp;

  /* 6 */ if (acc > kcg_lit_float32(0.0)) {
    tmp1 = kcg_lit_float32(0.0);
  }
  else {
    tmp1 = acc;
  }
  /* 5 */ if (Wheelspeed > outC->_L9) {
    tmp = Wheelspeed;
  }
  else {
    tmp = outC->_L9;
  }
  outC->_L9 = tmp1 * kcg_lit_float32(0.005) + tmp;
  /* 4 */ if (WOW) {
    tmp = outC->_L9;
  }
  else {
    tmp = kcg_lit_float32(0.0);
  }
  outC->refspeed = /* 1 */ m_to_kt_unit(/* 1 */ ft_to_m_unit(tmp));
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Ref_cal.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

