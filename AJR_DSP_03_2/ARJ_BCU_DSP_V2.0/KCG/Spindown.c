/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Spindown.h"

#ifndef KCG_USER_DEFINED_INIT
void Spindown_init(outC_Spindown *outC)
{
  outC->rem__L16 = kcg_true;
  outC->init = kcg_true;
  outC->BrakeIfbOut.IFB_BrakeActivate = kcg_true;
  outC->BrakeIfbOut.LeftIFB_BrakePressureCommand = kcg_lit_float32(0.0);
  outC->BrakeIfbOut.RightIFB_BrakePressureCommand = kcg_lit_float32(0.0);
  /* 1 */ Counter_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Spindown_reset(outC_Spindown *outC)
{
  outC->init = kcg_true;
  /* 1 */ Counter_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Spindown */
void Spindown(/* Spindown::APPData */ tINPUT_Data *APPData, outC_Spindown *outC)
{
  /* Spindown */ kcg_bool tmp1;
  /* Spindown */ kcg_float32 tmp;
  /* Spindown::_L16 */ kcg_bool _L16;

  _L16 = (*APPData).LGData.LandingGearExtentionandRetractionCommand &
    !(*APPData).WOWData.WOWBK;
  /* fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp1 = !_L16;
  }
  else {
    tmp1 = !outC->rem__L16;
  }
  /* 1 */ Counter((kcg_bool) (_L16 & tmp1), &outC->Context_1);
  /* 2 */ if (_L16 & !(*APPData).LGData.LG_GearDown_Locked) {
    tmp = k;
  }
  else {
    tmp = kcg_lit_float32(0.);
  }
  outC->BrakeIfbOut.LeftIFB_BrakePressureCommand = /* 1 */
    LimiterF32(
      /* 1 */(kcg_float32) outC->Context_1.count * tmp,
      highlimit,
      lowlimit);
  outC->BrakeIfbOut.RightIFB_BrakePressureCommand =
    outC->BrakeIfbOut.LeftIFB_BrakePressureCommand;
  outC->BrakeIfbOut.IFB_BrakeActivate = _L16 & (N >= outC->Context_1.count);
  outC->rem__L16 = _L16;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Spindown.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

