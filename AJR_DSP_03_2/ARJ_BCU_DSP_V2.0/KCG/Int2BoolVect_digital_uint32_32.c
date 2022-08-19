/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Int2BoolVect_digital_uint32_32.h"

/* digital::Int2BoolVect */
void Int2BoolVect_digital_uint32_32(
  /* digital::Int2BoolVect::In */ kcg_uint32 In,
  /* digital::Int2BoolVect::BV */ bool_word *BV)
{
  /* digital::Int2BoolVect */ kcg_uint32 acc;
  kcg_size i;
  /* digital::Int2BoolVect::_L4 */ bool_word _L4;
  /* digital::Int2BoolVect::Acc */ kcg_uint32 Acc;

  Acc = In;
  for (i = 0; i < 32; i++) {
    acc = Acc;
    /* 1 */ Int2BoolVectElt_digital_uint32(acc, &Acc, &_L4[i]);
  }
  for (i = 0; i < 32; i++) {
    (*BV)[i] = _L4[31 - i];
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Int2BoolVect_digital_uint32_32.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

