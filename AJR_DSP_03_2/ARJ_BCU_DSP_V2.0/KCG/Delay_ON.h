/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _Delay_ON_H_
#define _Delay_ON_H_

#include "kcg_types.h"
#include "Counter.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Delay_ON::Output1 */ Output1;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Counter /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_Delay_ON;

/* ===========  node initialization and cycle functions  =========== */
/* Delay_ON */
extern void Delay_ON(
  /* Delay_ON::Input1 */ kcg_bool Input1,
  /* Delay_ON::cycles */ kcg_int32 cycles,
  outC_Delay_ON *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Delay_ON_reset(outC_Delay_ON *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Delay_ON_init(outC_Delay_ON *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Delay_ON_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Delay_ON.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

