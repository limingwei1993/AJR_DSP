/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PI_Control.h"

#ifndef KCG_USER_DEFINED_INIT
void PI_Control_init(outC_PI_Control *outC)
{
  outC->rem_SC_enter_1 = kcg_false;
  outC->Command = kcg_lit_float32(0.0);
  outC->rem__L65 = kcg_lit_float32(6.0);
  outC->rem_err = kcg_lit_float32(0.);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void PI_Control_reset(outC_PI_Control *outC)
{
  outC->rem_SC_enter_1 = kcg_false;
  outC->rem__L65 = kcg_lit_float32(6.0);
  outC->rem_err = kcg_lit_float32(0.);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** "Graphical_1" {Text = "mA to psi"} */
/* PI_Control */
void PI_Control(
  /* PI_Control::slip */ kcg_float32 slip,
  /* PI_Control::Slip_opt */ kcg_float32 Slip_opt,
  /* PI_Control::SC_enter_1 */ kcg_bool SC_enter_1,
  /* PI_Control::Kp */ kcg_float32 Kp4,
  /* PI_Control::Ki */ kcg_float32 Ki3,
  /* PI_Control::Zero */ kcg_float32 Zero2,
  /* PI_Control::Hidden4 */ kcg_bool Hidden4,
  /* PI_Control::DT */ kcg_float32 DT,
  outC_PI_Control *outC)
{
  /* PI_Control */ kcg_float32 tmp;
  /* PI_Control::err */ kcg_float32 err;

  err = Slip_opt - slip;
  /* 2 */ if (outC->rem_SC_enter_1) {
    /* 1 */ if (Hidden4) {
      tmp = Zero2;
    }
    else {
      tmp = outC->rem__L65;
    }
    outC->rem__L65 = (Kp4 * (err - outC->rem_err) + Ki3 * err) * DT + /* 2 */
      LimiterF32(tmp, kcg_lit_float32(40.), kcg_lit_float32(0.));
  }
  else {
    outC->rem__L65 = kcg_lit_float32(6.0);
  }
  outC->Command = /* 1 */
    LimiterF32(outC->rem__L65, kcg_lit_float32(40.), kcg_lit_float32(0.)) *
    kcg_lit_float32(75.0);
  outC->rem_SC_enter_1 = SC_enter_1;
  outC->rem_err = err;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** PI_Control.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

