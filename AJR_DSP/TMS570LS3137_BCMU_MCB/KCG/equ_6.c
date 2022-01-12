/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "equ_6.h"

/* equ_6 */
kcg_float32 equ_6(/* equ_6::Input1 */ kcg_float32 Input1)
{
  /* equ_6::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * equ_6_par_1 / equ_6_par_2 - equ_6_par_3 / equ_6_par_4;
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** equ_6.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

