/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "BTI.h"

/* BTI */
kcg_int8 BTI(/* BTI::Bool_value */ kcg_bool Bool_value)
{
  /* BTI::out_int8 */ kcg_int8 out_int8;

  /* 1 */ if (Bool_value) {
    out_int8 = kcg_lit_int8(1);
  }
  else {
    out_int8 = kcg_lit_int8(0);
  }
  return out_int8;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BTI.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

