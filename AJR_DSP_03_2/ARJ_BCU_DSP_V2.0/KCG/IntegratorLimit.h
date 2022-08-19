/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _IntegratorLimit_H_
#define _IntegratorLimit_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* IntegratorLimit::IntegralSignal */ IntegralSignal;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_IntegratorLimit;

/* ===========  node initialization and cycle functions  =========== */
/** Library Function: IntegratorLimit */
/** At each cycle, the integral is incremented by the value of U. Output is limited to the range [LowLimit,HighLimit] */
/** Output is reset to zero at 1st cycle and when reset is true. */
/** "Graphical_1" {Text = "Trace: SRD: LLR1: Library"} */
/** "Title_1" {Title = "LLR1: Library function to perform integration on the input value, and limit the output to user defined limits"} */
/* IntegratorLimit */
extern void IntegratorLimit(
  /* IntegratorLimit::Signal */ kcg_float32 Signal,
  /* IntegratorLimit::Initial */ kcg_float32 Initial,
  /* IntegratorLimit::Reset */ kcg_bool Reset,
  /* IntegratorLimit::TimeCycle */ kcg_float32 TimeCycle,
  /* IntegratorLimit::LowLimit */ kcg_float32 LowLimit,
  /* IntegratorLimit::HiLimit */ kcg_float32 HiLimit,
  outC_IntegratorLimit *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void IntegratorLimit_reset(outC_IntegratorLimit *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void IntegratorLimit_init(outC_IntegratorLimit *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _IntegratorLimit_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** IntegratorLimit.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

