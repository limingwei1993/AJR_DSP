/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Int2BoolVectElt_digital_uint32.h"

/* digital::Int2BoolVectElt */
void Int2BoolVectElt_digital_uint32(
  /* digital::Int2BoolVectElt::Acc */ kcg_uint32 Acc,
  /* digital::Int2BoolVectElt::AccOut */ kcg_uint32 *AccOut,
  /* digital::Int2BoolVectElt::bi */ kcg_bool *bi)
{
  *bi = Acc % kcg_lit_uint32(2) == kcg_lit_uint32(1);
  *AccOut = Acc / kcg_lit_uint32(2);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Int2BoolVectElt_digital_uint32.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

