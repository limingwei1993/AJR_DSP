/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "equ_5.h"

/* equ_5 */
kcg_float32 equ_5(/* equ_5::Input1 */ kcg_float32 Input1)
{
  /* equ_5::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * equ_5_par_1 / equ_5_par_2 - equ_5_par_3;
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** equ_5.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

