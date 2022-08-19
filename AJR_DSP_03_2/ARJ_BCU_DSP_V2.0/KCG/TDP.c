/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "TDP.h"

#ifndef KCG_USER_DEFINED_INIT
void TDP_init(outC_TDP *outC)
{
  outC->TDP = kcg_true;
  /* 1 */ Delay_ON_init(&outC->Context_1);
  /* 2 */ Delay_ON_init(&outC->Context_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void TDP_reset(outC_TDP *outC)
{
  /* 1 */ Delay_ON_reset(&outC->Context_1);
  /* 2 */ Delay_ON_reset(&outC->Context_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* TDP */
void TDP(
  /* TDP::APPData */ tINPUT_Data *APPData,
  /* TDP::Spindown_out */ tBrakeIfbOut *Spindown_out,
  outC_TDP *outC)
{
  /* 2 */ Delay_ON(kcg_false, kcg_lit_int32(1100), &outC->Context_2);
  /* 1 */
  Delay_ON(
    (kcg_bool) !(*APPData).WOWData.WOWBK,
    kcg_lit_int32(1000),
    &outC->Context_1);
  outC->TDP = !((outC->Context_2.Output1 & outC->Context_1.Output1) |
      (((*APPData).WheelSpeedData.LeftWheelSpeed.Value > kcg_lit_float32(70.)) &
        ((*APPData).WheelSpeedData.RightWheelSpeed.Value > kcg_lit_float32(70.))) |
      (*Spindown_out).IFB_BrakeActivate | ((kcg_lit_float32(30.) >
          (*APPData).WheelSpeedData.LeftWheelSpeed.Value) & (kcg_lit_float32(
            30.) > (*APPData).WheelSpeedData.RightWheelSpeed.Value) &
        !(*APPData).WOWData.WOWBK));
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** TDP.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

