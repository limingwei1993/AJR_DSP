/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "g_to_mps2_unit.h"

/* unit::g_to_mps2 */
kcg_float32 g_to_mps2_unit(/* unit::g_to_mps2::Input1 */ kcg_float32 Input1)
{
  /* unit::g_to_mps2::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * kcg_lit_float32(9.81);
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** g_to_mps2_unit.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

