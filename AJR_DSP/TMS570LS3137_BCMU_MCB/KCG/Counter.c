/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Counter.h"

#ifndef KCG_USER_DEFINED_INIT
void Counter_init(outC_Counter *outC)
{
  outC->init = kcg_true;
  outC->count = kcg_lit_int32(0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Counter_reset(outC_Counter *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Counter */
void Counter(/* Counter::Reset */ kcg_bool Reset, outC_Counter *outC)
{
  /* 1 */ if (Reset) {
    outC->count = kcg_lit_int32(0) + kcg_lit_int32(1);
  }
  else /* fby_1_init_1 */ if (outC->init) {
    outC->count = kcg_lit_int32(0) + kcg_lit_int32(1);
  }
  else {
    outC->count = outC->count + kcg_lit_int32(1);
  }
  outC->init = kcg_false;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Counter.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

