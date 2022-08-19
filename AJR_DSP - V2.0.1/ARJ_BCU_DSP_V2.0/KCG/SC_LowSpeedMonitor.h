/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _SC_LowSpeedMonitor_H_
#define _SC_LowSpeedMonitor_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* SC_LowSpeedMonitor::SkidEnable */ SkidEnable;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* ----------------------- local memories  ------------------------- */
  SSM_ST_SM_LowSpeedMonitor /* SC_LowSpeedMonitor::SM_LowSpeedMonitor */ SM_LowSpeedMonitor_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_SC_LowSpeedMonitor;

/* ===========  node initialization and cycle functions  =========== */
/** BCUSW-739 */
/** BCUSW-740 */
/** "Graphical_111" {Text = "Trace: SRD: LLR1 : BCUSW-739;BCUSW-740"} */
/** "Title_1" {Title = "LLR1 : Skid Control low speed monitor"} */
/* SC_LowSpeedMonitor */
extern void SC_LowSpeedMonitor(
  /* SC_LowSpeedMonitor::WheelRefSpeed */ kcg_float32 WheelRefSpeed,
  outC_SC_LowSpeedMonitor *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void SC_LowSpeedMonitor_reset(outC_SC_LowSpeedMonitor *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void SC_LowSpeedMonitor_init(outC_SC_LowSpeedMonitor *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _SC_LowSpeedMonitor_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_LowSpeedMonitor.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

