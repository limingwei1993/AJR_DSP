/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Acc_average.h"

/* Acc_average */
void Acc_average(
  /* Acc_average::Value_right */ kcg_float32 Value_right,
  /* Acc_average::Value_left */ kcg_float32 Value_left,
  /* Acc_average::Valid_right */ kcg_bool Valid_right,
  /* Acc_average::Valid_left */ kcg_bool Valid_left,
  /* Acc_average::Acc_av */ tValidityF32 *Acc_av)
{
  /* Acc_average */ kcg_float32 tmp3;
  /* Acc_average */ kcg_float32 tmp2;
  /* Acc_average */ kcg_float32 tmp1;
  /* Acc_average */ kcg_float32 tmp;
  /* Acc_average::_L7 */ kcg_float32 _L7;

  (*Acc_av).Valid = Valid_left | Valid_right;
  /* 14 */ if (Valid_right) {
    tmp = kcg_lit_float32(1.0);
    tmp1 = Value_right;
  }
  else {
    tmp = kcg_lit_float32(0.0);
    tmp1 = kcg_lit_float32(0.0);
  }
  /* 13 */ if (Valid_left) {
    tmp3 = kcg_lit_float32(1.0);
    tmp2 = Value_left;
  }
  else {
    tmp3 = kcg_lit_float32(0.0);
    tmp2 = kcg_lit_float32(0.0);
  }
  _L7 = tmp3 + tmp;
  /* 15 */ if (_L7 < kcg_lit_float32(1.0)) {
    tmp = kcg_lit_float32(1.0);
  }
  else {
    tmp = _L7;
  }
  (*Acc_av).Value = (tmp2 + tmp1) / tmp;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Acc_average.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

