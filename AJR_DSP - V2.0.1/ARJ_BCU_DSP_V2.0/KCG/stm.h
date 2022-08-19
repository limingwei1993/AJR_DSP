/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _stm_H_
#define _stm_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* stm::OFF_State */ OFF_State;
  kcg_bool /* stm::LandingDisarmedState */ LandingDisarmedState;
  kcg_bool /* stm::LandingArmedState */ LandingArmedState;
  kcg_bool /* stm::LandingApplicationState */ LandingApplicationState;
  kcg_bool /* stm::RTODisarmedState */ RTODisarmedState;
  kcg_bool /* stm::RTOEnabledState */ RTOEnabledState;
  kcg_bool /* stm::RTOApplicationState */ RTOApplicationState;
  kcg_bool /* stm::RTOArmedState */ RTOArmedState;
  kcg_bool /* stm::LandingEnableState */ LandingEnableState;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  _2_SSM_ST_SM1 /* stm::SM1 */ SM1_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_stm;

/* ===========  node initialization and cycle functions  =========== */
/* stm */
extern void stm(
  /* stm::LandingArmed */ kcg_bool LandingArmed,
  /* stm::LandingApplication */ kcg_bool LandingApplication,
  /* stm::LandingArmedDisarmed */ kcg_bool LandingArmedDisarmed,
  /* stm::LandingApplicationDisarmed */ kcg_bool LandingApplicationDisarmed,
  /* stm::RTOArmed */ kcg_bool RTOArmed,
  /* stm::RTOArmedDisarmed */ kcg_bool RTOArmedDisarmed,
  /* stm::RTOEnabled */ kcg_bool RTOEnabled,
  /* stm::RTOEnabledDisarmed */ kcg_bool RTOEnabledDisarmed,
  /* stm::RTOApplicationDisarmed */ kcg_bool RTOApplicationDisarmed,
  /* stm::RTOMAXApplication */ kcg_bool RTOMAXApplication,
  /* stm::RTONormalApplication */ kcg_bool RTONormalApplication,
  /* stm::LandingEnable */ kcg_bool LandingEnable,
  /* stm::LandingEnableDisarmed */ kcg_bool LandingEnableDisarmed,
  outC_stm *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void stm_reset(outC_stm *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void stm_init(outC_stm *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _stm_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** stm.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

