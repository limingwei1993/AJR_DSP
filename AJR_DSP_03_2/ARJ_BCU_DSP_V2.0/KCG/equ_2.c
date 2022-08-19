/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "equ_2.h"

/* equ_2 */
kcg_float32 equ_2(/* equ_2::Input1 */ kcg_float32 Input1)
{
  /* equ_2::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * equ_2_par_1 / equ_2_par_2 - equ_2_par_3;
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** equ_2.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

