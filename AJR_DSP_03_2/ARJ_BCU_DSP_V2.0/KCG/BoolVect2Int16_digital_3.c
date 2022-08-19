/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "BoolVect2Int16_digital_3.h"

/* digital::BoolVect2Int16 */
kcg_int16 BoolVect2Int16_digital_3(
  /* digital::BoolVect2Int16::BV */ array_bool_3 *BV)
{
  kcg_size i;
  /* digital::BoolVect2Int16::Out */ kcg_int16 Out;

  Out = kcg_lit_int16(0);
  for (i = 0; i < 3; i++) {
    /* 2 */ if ((*BV)[i]) {
      Out = kcg_lit_int16(1) + Out * kcg_lit_int16(2);
    }
    else {
      Out = kcg_lit_int16(0) + Out * kcg_lit_int16(2);
    }
  }
  return Out;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BoolVect2Int16_digital_3.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

