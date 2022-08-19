/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "LimiterF32.h"

/* LimiterF32 */
kcg_float32 LimiterF32(
  /* LimiterF32::Input1 */ kcg_float32 Input1,
  /* LimiterF32::HighLimit */ kcg_float32 HighLimit,
  /* LimiterF32::LowLimit */ kcg_float32 LowLimit)
{
  /* LimiterF32::Output1 */ kcg_float32 Output1;

  /* 1 */ if (Input1 >= HighLimit) {
    Output1 = HighLimit;
  }
  else /* 2 */ if (Input1 <= LowLimit) {
    Output1 = LowLimit;
  }
  else {
    Output1 = Input1;
  }
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** LimiterF32.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

