/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _Brake_Skid_H_
#define _Brake_Skid_H_

#include "kcg_types.h"
#include "SC_Wheel.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tBrakeSkidOut /* Brake_Skid::BrakeSkid */ BrakeSkid;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_SC_Wheel /* 2 */ Context_2;
  outC_SC_Wheel /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Brake_Skid;

/* ===========  node initialization and cycle functions  =========== */
/* Brake_Skid */
extern void Brake_Skid(
  /* Brake_Skid::APPData */ tINPUT_Data *APPData,
  /* Brake_Skid::WOWBK */ kcg_bool WOWBK,
  /* Brake_Skid::BrakeSelectOut */ tBrakeSelectOut *BrakeSelectOut,
  outC_Brake_Skid *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Brake_Skid_reset(outC_Brake_Skid *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Brake_Skid_init(outC_Brake_Skid *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Brake_Skid_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Brake_Skid.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

