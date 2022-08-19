/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "WOW_Processing.h"

/* WOW_Processing */
void WOW_Processing(
  /* WOW_Processing::InData */ tData_to_DSP *InData,
  /* WOW_Processing::WOW_Data */ tIOR_ProcessWowData *WOW_Data)
{
  /* WOW_Processing */ bool_word tmp4;
  /* WOW_Processing */ bool_word tmp3;
  /* WOW_Processing */ kcg_int8 tmp2;
  /* WOW_Processing */ kcg_int8 tmp1;
  /* WOW_Processing */ kcg_int8 tmp;
  /* WOW_Processing::zong */ kcg_bool zong;

  (*WOW_Data).LeftWOW = (*InData).In_Discrete.LeftWOW;
  (*WOW_Data).RightWOW = (*InData).In_Discrete.RightWOW;
  (*WOW_Data).zong.Valid = kcg_true;
  /* 1 */
  Int2BoolVect_digital_uint32_32((*InData).In_Computed_WOW1_Data_277, &tmp4);
  /* 2 */
  Int2BoolVect_digital_uint32_32((*InData).In_Computed_WOW2_Data_277, &tmp3);
  zong = tmp4[0] & tmp3[0];
  (*WOW_Data).zong.Value = zong;
  tmp2 = /* 1 */ BTI((*InData).In_Discrete.LeftWOW);
  tmp1 = /* 2 */ BTI((*InData).In_Discrete.RightWOW);
  tmp = /* 3 */ BTI(zong);
  /* 2 */ if (tmp2 + tmp1 + tmp >= kcg_lit_int8(2)) {
    (*WOW_Data).WOWBK = kcg_true;
  }
  else /* 1 */ if ((*InData).In_Computed_Air_Speed_206.Value >= kcg_lit_float32(
      60.)) {
    (*WOW_Data).WOWBK = kcg_false;
  }
  else {
    (*WOW_Data).WOWBK = kcg_true;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** WOW_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

