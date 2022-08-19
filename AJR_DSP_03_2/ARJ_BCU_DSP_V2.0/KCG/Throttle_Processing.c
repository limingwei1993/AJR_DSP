/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Throttle_Processing.h"

/* Throttle_Processing */
void Throttle_Processing(
  /* Throttle_Processing::Input1 */ tData_to_DSP *Input1,
  /* Throttle_Processing::ThrottleData */ tIOR_ProcessThrottleData *ThrottleData)
{
  (*ThrottleData).LeftThrottleIdle = (*Input1).In_Discrete.LeftThrottleIdle;
  (*ThrottleData).RightThrottleIdle = (*Input1).In_Discrete.RightThrottleIdle;
  (*ThrottleData).ThrottleIdleAtLeastOne =
    (*Input1).In_Discrete.ThrottleIdleAtLeastOne;
  (*ThrottleData).ThrottleIdleBoth = (*Input1).In_Discrete.ThrottleIdleBoth;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Throttle_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

