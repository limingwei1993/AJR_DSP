/* $******* SCADE Suite KCG 32-bit 6.6.1 beta (build i1) ********
** Command: kcg661.exe -config D:/Software/professional/ANSYS Inc/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-09-18T10:46:44
*************************************************************$ */
#ifndef _Autobrake_ARM_Application_H_
#define _Autobrake_ARM_Application_H_

#include "kcg_types.h"
#include "Counter.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* LandingApplication/, _L9/ */ LandingApplication;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* WOW_BRK/, _L1/ */ mem_WOW_BRK;
  kcg_bool init;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Counter /* _L10=(Counter#1)/ */ Context_Counter_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Autobrake_ARM_Application;

/* ===========  node initialization and cycle functions  =========== */
/* Autobrake_ARM_Application/ */
extern void Autobrake_ARM_Application(
  /* WOW_BRK/, _L1/ */
  kcg_bool WOW_BRK,
  /* Idle_Position_Discrete_R/, _L3/ */
  kcg_bool Idle_Position_Discrete_R,
  /* _L4/, dle_Position_Discrete_L/ */
  kcg_bool dle_Position_Discrete_L,
  /* WOW_NLG_HARD/, _L5/ */
  kcg_bool WOW_NLG_HARD,
  /* Wheel_speed_av/, _L6/ */
  kcg_float32 Wheel_speed_av,
  outC_Autobrake_ARM_Application *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Autobrake_ARM_Application_reset(
  outC_Autobrake_ARM_Application *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Autobrake_ARM_Application_init(
  outC_Autobrake_ARM_Application *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _Autobrake_ARM_Application_H_ */
/* $******* SCADE Suite KCG 32-bit 6.6.1 beta (build i1) ********
** Autobrake_ARM_Application.h
** Generation date: 2021-09-18T10:46:44
*************************************************************$ */

