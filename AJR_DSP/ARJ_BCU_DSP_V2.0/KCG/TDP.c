/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "TDP.h"

#ifndef KCG_USER_DEFINED_INIT
void TDP_init(outC_TDP *outC)
{
  outC->TDP = kcg_true;
  outC->rem__L11 = kcg_true;
  outC->rem_WOWBK = kcg_true;
  outC->init = kcg_true;
  /* 2 */ Counter_init(&outC->Context_2);
  /* 1 */ Counter_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void TDP_reset(outC_TDP *outC)
{
  outC->init = kcg_true;
  /* 2 */ Counter_reset(&outC->Context_2);
  /* 1 */ Counter_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* TDP */
void TDP(
  /* TDP::APPData */ tINPUT_Data *APPData,
  /* TDP::WOWBK */ kcg_bool WOWBK,
  outC_TDP *outC)
{
  /* TDP */ kcg_bool tmp1;
  /* TDP */ kcg_bool tmp;
  /* TDP::_L11 */ kcg_bool _L11;

  _L11 = (*APPData).WheelSpeedData.WheelSpeed_av > kcg_lit_float32(50.);
  /* fby_1_init_2 */ if (outC->init) {
    tmp1 = !WOWBK;
    outC->init = kcg_false;
    tmp = !_L11;
  }
  else {
    tmp1 = !outC->rem_WOWBK;
    tmp = !outC->rem__L11;
  }
  /* 1 */ Counter((kcg_bool) (WOWBK & tmp1), &outC->Context_1);
  /* 2 */ Counter((kcg_bool) (_L11 & tmp), &outC->Context_2);
  outC->TDP = !((WOWBK & (outC->Context_1.count > kcg_lit_int32(600))) | (_L11 &
        (outC->Context_2.count > kcg_lit_int32(200))));
  outC->rem_WOWBK = WOWBK;
  outC->rem__L11 = _L11;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** TDP.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

