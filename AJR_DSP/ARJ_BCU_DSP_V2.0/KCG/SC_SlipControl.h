/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _SC_SlipControl_H_
#define _SC_SlipControl_H_

#include "kcg_types.h"
#include "SC_LowSpeedMonitor.h"
#include "PI_Control.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* SC_SlipControl::BrakePressureCommandAdj */ BrakePressureCommandAdj;
  kcg_bool /* SC_SlipControl::StartBlending */ StartBlending;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_PI_Control /* 1 */ _1_Context_1;
  outC_SC_LowSpeedMonitor /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_SC_SlipControl;

/* ===========  node initialization and cycle functions  =========== */
/** "Remark_1" {Description = "版权声明 本文己兄泄逃梅苫邢拊鹑喂镜纳桃得孛埽淳泄逃梅苫邢拊鹑喂九迹?不可将本文蓟蚱渲胁糠指从』蛞玫狡渌募中，用于制造或其他目的。"} */
/** "Graphical_1" {Text = "版权声明 本文己兄泄逃梅苫邢拊鹑喂镜纳桃得孛埽淳泄逃梅苫邢拊鹑喂九迹?不可将本文蓟蚱渲胁糠指从』蛞玫狡渌募中，用于制造或其他目的。 "} */
/* SC_SlipControl */
extern void SC_SlipControl(
  /* SC_SlipControl::Speedref */ kcg_float32 Speedref,
  /* SC_SlipControl::Wheelspeed */ kcg_float32 Wheelspeed,
  /* SC_SlipControl::SC_enter */ kcg_bool SC_enter,
  outC_SC_SlipControl *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void SC_SlipControl_reset(outC_SC_SlipControl *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void SC_SlipControl_init(outC_SC_SlipControl *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _SC_SlipControl_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_SlipControl.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

