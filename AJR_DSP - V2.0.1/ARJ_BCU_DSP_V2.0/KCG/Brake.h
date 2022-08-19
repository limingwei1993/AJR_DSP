/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _Brake_H_
#define _Brake_H_

#include "kcg_types.h"
#include "BrakePress.h"
#include "WOW_Processing.h"
#include "BrakeSelect.h"
#include "BrakeInhibit.h"
#include "Lockwheel.h"
#include "AutoBrake.h"
#include "Brake_Skid.h"
#include "Spindown.h"
#include "TDP.h"

/* ========================  input structure  ====================== */
typedef struct { tINPUT_Data /* Brake::APPData */ APPData; } inC_Brake;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  tOutPut /* Brake::Output */ Output;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_TDP /* 1 */ _3_Context_1;
  outC_Brake_Skid /* 1 */ _2_Context_1;
  outC_AutoBrake /* 1 */ _1_Context_1;
  outC_Lockwheel /* 1 */ Context_1;
  outC_Spindown /* 2 */ Context_2;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Brake;

/* ===========  node initialization and cycle functions  =========== */
/* Brake */
extern void Brake(inC_Brake *inC, outC_Brake *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Brake_reset(outC_Brake *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Brake_init(outC_Brake *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Brake_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Brake.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

