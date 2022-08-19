/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "LGData_Processing.h"

/* LGData_Processing */
void LGData_Processing(
  /* LGData_Processing::Input1 */ tData_to_DSP *Input1,
  /* LGData_Processing::LGData */ tIOR_ProcessLandingGearData *LGData)
{
  (*LGData).LG_GearDown_Locked = (*Input1).In_MLG_LtDownlocked &
    (*Input1).In_MLG_RtDownlocked;
  (*LGData).LandingGearExtentionandRetractionCommand =
    (*Input1).In_Discrete.GearHandle;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** LGData_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

