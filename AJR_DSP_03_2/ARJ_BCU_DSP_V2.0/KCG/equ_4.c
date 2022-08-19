/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "equ_4.h"

/* equ_4 */
kcg_float32 equ_4(/* equ_4::Input1 */ kcg_float32 Input1)
{
  /* equ_4::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * equ_4_par_1 / equ_4_par_2 - equ_4_par_3 / equ_4_par_4;
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** equ_4.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

