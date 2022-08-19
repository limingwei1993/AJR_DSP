/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "m_to_ft_unit.h"

/* unit::m_to_ft */
kcg_float32 m_to_ft_unit(/* unit::m_to_ft::Input1 */ kcg_float32 Input1)
{
  /* unit::m_to_ft::Output1 */ kcg_float32 Output1;

  Output1 = Input1 / kcg_lit_float32(0.3048);
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** m_to_ft_unit.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

