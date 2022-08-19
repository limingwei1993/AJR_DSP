/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Pedal_Processing.h"

/* Pedal_Processing */
void Pedal_Processing(
  /* Pedal_Processing::Input1 */ tData_to_DSP *Input1,
  /* Pedal_Processing::PedalData */ tIOR_ProcessPedalData *PedalData)
{
  /* Pedal_Processing::_L21 */ kcg_float32 _L21;

  kcg_copy_tValidityF32(
    &(*PedalData).LeftCptPedal,
    &(*Input1).In_CPLT_LT_LVDT_Percent);
  kcg_copy_tValidityF32(
    &(*PedalData).RightCptPedal,
    &(*Input1).In_CPLT_RT_LVDT_Percent);
  kcg_copy_tValidityF32(
    &(*PedalData).LeftPPedal,
    &(*Input1).In_PLT_LT_LVDT_Percent);
  kcg_copy_tValidityF32(
    &(*PedalData).RightPPedal,
    &(*Input1).In_PLT_RT_LVDT_Percent);
  _L21 = /* 1 */
    Max3_math_float32(
      (*Input1).In_CPLT_LT_LVDT_Percent.Value,
      (*Input1).In_CPLT_RT_LVDT_Percent.Value,
      (*Input1).In_PLT_LT_LVDT_Percent.Value);
  /* 2 */ if (_L21 >= (*Input1).In_PLT_RT_LVDT_Percent.Value) {
    (*PedalData).MaxPedal = _L21;
  }
  else {
    (*PedalData).MaxPedal = (*Input1).In_PLT_RT_LVDT_Percent.Value;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Pedal_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

