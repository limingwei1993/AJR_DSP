/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "HzTOradpersec.h"

/* HzTOradpersec */
kcg_float32 HzTOradpersec(/* HzTOradpersec::Hz */ kcg_float32 Hz)
{
  /* HzTOradpersec::Output1 */ kcg_float32 Output1;

  Output1 = Hz * HzTOrad;
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** HzTOradpersec.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

