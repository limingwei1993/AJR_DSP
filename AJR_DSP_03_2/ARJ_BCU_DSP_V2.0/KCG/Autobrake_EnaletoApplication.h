/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Autobrake_EnaletoApplication_H_
#define _Autobrake_EnaletoApplication_H_

#include "kcg_types.h"
#include "Delay_ON.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Autobrake_EnaletoApplication::LandingApplication */ LandingApplication;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Delay_ON /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Autobrake_EnaletoApplication;

/* ===========  node initialization and cycle functions  =========== */
/* Autobrake_EnaletoApplication */
extern void Autobrake_EnaletoApplication(
  /* Autobrake_EnaletoApplication::Idle_Position_Discrete_R */ kcg_bool Idle_Position_Discrete_R,
  /* Autobrake_EnaletoApplication::dle_Position_Discrete_L */ kcg_bool dle_Position_Discrete_L,
  outC_Autobrake_EnaletoApplication *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Autobrake_EnaletoApplication_reset(
  outC_Autobrake_EnaletoApplication *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Autobrake_EnaletoApplication_init(
  outC_Autobrake_EnaletoApplication *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Autobrake_EnaletoApplication_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Autobrake_EnaletoApplication.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

