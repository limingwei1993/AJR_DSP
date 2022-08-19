/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ft_to_m_unit.h"

/* unit::ft_to_m */
kcg_float32 ft_to_m_unit(/* unit::ft_to_m::Input1 */ kcg_float32 Input1)
{
  /* unit::ft_to_m::Output1 */ kcg_float32 Output1;

  Output1 = Input1 * kcg_lit_float32(0.3048);
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** ft_to_m_unit.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

