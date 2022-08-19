/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PI_Controller.h"

#ifndef KCG_USER_DEFINED_INIT
void PI_Controller_init(outC_PI_Controller *outC)
{
  outC->ControlVariable = kcg_lit_float32(0.0);
  /* 1 */ IntegratorLimit_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void PI_Controller_reset(outC_PI_Controller *outC)
{
  /* 1 */ IntegratorLimit_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** Library Function: PI_Controller */
/* PI_Controller */
void PI_Controller(
  /* PI_Controller::SetPoint */ kcg_float32 SetPoint,
  /* PI_Controller::ProcessVariable */ kcg_float32 ProcessVariable,
  /* PI_Controller::Kp */ kcg_float32 Kp3,
  /* PI_Controller::Ki */ kcg_float32 Ki2,
  /* PI_Controller::DeltaT */ kcg_float32 DeltaT,
  /* PI_Controller::LowLimit */ kcg_float32 LowLimit,
  /* PI_Controller::HighLimit */ kcg_float32 HighLimit,
  /* PI_Controller::Reset */ kcg_bool Reset,
  outC_PI_Controller *outC)
{
  /* PI_Controller */ kcg_float32 tmp;
  /* PI_Controller::_L17 */ kcg_float32 _L17;

  _L17 = SetPoint - ProcessVariable;
  /* 1 */
  IntegratorLimit(
    _L17 * Ki2,
    kcg_lit_float32(0.0),
    Reset,
    DeltaT,
    LowLimit,
    HighLimit,
    &outC->Context_1);
  /* 1 */ if (Reset) {
    tmp = kcg_lit_float32(0.0);
  }
  else {
    tmp = _L17 * Kp3 + outC->Context_1.IntegralSignal;
  }
  outC->ControlVariable = /* 1 */
    LimiterF32(tmp, kcg_lit_float32(0.), kcg_lit_float32(3000.));
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** PI_Controller.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

