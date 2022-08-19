/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _SC_Wheel_H_
#define _SC_Wheel_H_

#include "kcg_types.h"
#include "SC_Function.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* SC_Wheel::SkidEnable */ SkidEnable;
  kcg_float32 /* SC_Wheel::BrakePressureCommandAdj */ BrakePressureCommandAdj;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_SC_Function /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_SC_Wheel;

/* ===========  node initialization and cycle functions  =========== */
/** BCUSW-735 */
/** BCUSW-737 */
/** BCUSW-774 */
/** BCUSW-775 */
/** "Title_1" {Title = "LLR1 : Skid Control wheel function"} */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-735;BCUSW-739;BCUSW-774;BCUSW-775"} */
/* SC_Wheel */
extern void SC_Wheel(
  /* SC_Wheel::WOWBK */ kcg_bool WOWBK,
  /* SC_Wheel::WheelSpeed */ tValidityF32 *WheelSpeed,
  /* SC_Wheel::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  /* SC_Wheel::BrakePressureCommand */ kcg_float32 BrakePressureCommand,
  outC_SC_Wheel *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void SC_Wheel_reset(outC_SC_Wheel *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void SC_Wheel_init(outC_SC_Wheel *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _SC_Wheel_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_Wheel.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

