/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Max3_math_float32.h"

/* math::Max3 */
kcg_float32 Max3_math_float32(
  /* math::Max3::I1 */ kcg_float32 I1,
  /* math::Max3::I2 */ kcg_float32 I2,
  /* math::Max3::I3 */ kcg_float32 I3)
{
  /* math::Max3::Ma3_Output */ kcg_float32 Ma3_Output;

  /* 5 */ if ((I1 >= I2) & (I1 >= I3)) {
    Ma3_Output = I1;
  }
  else /* 8 */ if (I2 >= I3) {
    Ma3_Output = I2;
  }
  else {
    Ma3_Output = I3;
  }
  return Ma3_Output;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Max3_math_float32.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

