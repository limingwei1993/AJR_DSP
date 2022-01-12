/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _PI_Control_H_
#define _PI_Control_H_

#include "kcg_types.h"
#include "LimiterF32.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* PI_Control::Command */ Command;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_float32 /* PI_Control::_L65 */ rem__L65;
  kcg_float32 /* PI_Control::err */ rem_err;
  kcg_bool /* PI_Control::SC_enter_1 */ rem_SC_enter_1;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_PI_Control;

/* ===========  node initialization and cycle functions  =========== */
/** "Graphical_1" {Text = "mA to psi"} */
/* PI_Control */
extern void PI_Control(
  /* PI_Control::slip */ kcg_float32 slip,
  /* PI_Control::Slip_opt */ kcg_float32 Slip_opt,
  /* PI_Control::SC_enter_1 */ kcg_bool SC_enter_1,
  /* PI_Control::Kp */ kcg_float32 Kp4,
  /* PI_Control::Ki */ kcg_float32 Ki3,
  /* PI_Control::Zero */ kcg_float32 Zero2,
  /* PI_Control::Hidden4 */ kcg_bool Hidden4,
  /* PI_Control::DT */ kcg_float32 DT,
  outC_PI_Control *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void PI_Control_reset(outC_PI_Control *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void PI_Control_init(outC_PI_Control *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _PI_Control_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** PI_Control.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

