/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "IntegratorLimit.h"

#ifndef KCG_USER_DEFINED_INIT
void IntegratorLimit_init(outC_IntegratorLimit *outC)
{
  outC->init = kcg_true;
  outC->IntegralSignal = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void IntegratorLimit_reset(outC_IntegratorLimit *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** Library Function: IntegratorLimit */
/** At each cycle, the integral is incremented by the value of U. Output is limited to the range [LowLimit,HighLimit] */
/** Output is reset to zero at 1st cycle and when reset is true. */
/** "Graphical_1" {Text = "Trace: SRD: LLR1: Library"} */
/** "Title_1" {Title = "LLR1: Library function to perform integration on the input value, and limit the output to user defined limits"} */
/* IntegratorLimit */
void IntegratorLimit(
  /* IntegratorLimit::Signal */ kcg_float32 Signal,
  /* IntegratorLimit::Initial */ kcg_float32 Initial,
  /* IntegratorLimit::Reset */ kcg_bool Reset,
  /* IntegratorLimit::TimeCycle */ kcg_float32 TimeCycle,
  /* IntegratorLimit::LowLimit */ kcg_float32 LowLimit,
  /* IntegratorLimit::HiLimit */ kcg_float32 HiLimit,
  outC_IntegratorLimit *outC)
{
  /* IntegratorLimit::_L40 */ kcg_float32 _L40;
  /* IntegratorLimit::_L30 */ kcg_float32 _L30;

  /* 1 */ if (outC->init) {
    outC->init = kcg_false;
    _L30 = kcg_lit_float32(0.0);
  }
  else {
    _L30 = outC->IntegralSignal + Signal * TimeCycle;
  }
  /* 3 */ if (_L30 <= LowLimit) {
    _L40 = LowLimit;
  }
  else {
    _L40 = _L30;
  }
  /* 2 */ if (Reset) {
    outC->IntegralSignal = Initial;
  }
  else /* 1 */ if (_L40 >= HiLimit) {
    outC->IntegralSignal = HiLimit;
  }
  else {
    outC->IntegralSignal = _L40;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** IntegratorLimit.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

