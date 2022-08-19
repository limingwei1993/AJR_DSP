/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "WOW_Processing.h"

/* WOW_Processing */
kcg_bool WOW_Processing(/* WOW_Processing::APPData */ tINPUT_Data *APPData)
{
  /* WOW_Processing */ kcg_int8 tmp2;
  /* WOW_Processing */ kcg_int8 tmp1;
  /* WOW_Processing */ kcg_int8 tmp;
  /* WOW_Processing::WOW_BK */ kcg_bool WOW_BK;

  tmp2 = /* 1 */ BTI((*APPData).WOWData.LeftWOW);
  tmp1 = /* 2 */ BTI((*APPData).WOWData.RightWOW);
  tmp = /* 3 */ BTI((*APPData).WOWData.zong.Value);
  /* 2 */ if (tmp2 + tmp1 + tmp >= kcg_lit_int8(2)) {
    WOW_BK = kcg_true;
  }
  else /* 1 */ if ((*APPData).Aircraft_Data.Airspeed.Value >= kcg_lit_float32(
      60.)) {
    WOW_BK = kcg_false;
  }
  else {
    WOW_BK = kcg_true;
  }
  return WOW_BK;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** WOW_Processing.c
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

