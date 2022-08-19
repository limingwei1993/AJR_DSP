/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "HydraulicData_Processing.h"

/* HydraulicData_Processing */
void HydraulicData_Processing(
  /* HydraulicData_Processing::Input1 */ tData_to_DSP *Input1,
  /* HydraulicData_Processing::Output1 */ tIOR_ProcessHydraulicData *Output1)
{
  (*Output1).HighPressure = (*Input1).In_Hydraulic_System_Pressure_60 >=
    kcg_lit_float32(2500.);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** HydraulicData_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

