/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _SC_Function_H_
#define _SC_Function_H_

#include "kcg_types.h"
#include "Blending.h"
#include "SC_SlipControl.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* SC_Function::BrakePressureCommandAdj */ BrakePressureCommandAdj;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Blending /* 1 */ _1_Context_1;
  outC_SC_SlipControl /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_SC_Function;

/* ===========  node initialization and cycle functions  =========== */
/** BCUSW-739 */
/** BCUSW-740 */
/** "Title_1" {Title = "LLR1 : Skid Control blending to pedal pressure"} */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-738;BCUSW-739;BCUSW-740;BCUSW-741;BCUSW-742;BCUSW-743"} */
/** "Graphical_1111" {Text = "Trace: Lib: LLR1: Blending"} */
/* SC_Function */
extern void SC_Function(
  /* SC_Function::WheelSpeed */ kcg_float32 WheelSpeed,
  /* SC_Function::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  /* SC_Function::SC_command_enter */ kcg_bool SC_command_enter,
  /* SC_Function::BrakePressureCommand */ kcg_float32 BrakePressureCommand,
  outC_SC_Function *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void SC_Function_reset(outC_SC_Function *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void SC_Function_init(outC_SC_Function *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _SC_Function_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_Function.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

