/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _PI_Controller_H_
#define _PI_Controller_H_

#include "kcg_types.h"
#include "LimiterF32.h"
#include "IntegratorLimit.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* PI_Controller::ControlVariable */ ControlVariable;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_IntegratorLimit /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_PI_Controller;

/* ===========  node initialization and cycle functions  =========== */
/** Library Function: PI_Controller */
/* PI_Controller */
extern void PI_Controller(
  /* PI_Controller::SetPoint */ kcg_float32 SetPoint,
  /* PI_Controller::ProcessVariable */ kcg_float32 ProcessVariable,
  /* PI_Controller::Kp */ kcg_float32 Kp3,
  /* PI_Controller::Ki */ kcg_float32 Ki2,
  /* PI_Controller::DeltaT */ kcg_float32 DeltaT,
  /* PI_Controller::LowLimit */ kcg_float32 LowLimit,
  /* PI_Controller::HighLimit */ kcg_float32 HighLimit,
  /* PI_Controller::Reset */ kcg_bool Reset,
  outC_PI_Controller *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void PI_Controller_reset(outC_PI_Controller *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void PI_Controller_init(outC_PI_Controller *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _PI_Controller_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** PI_Controller.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

