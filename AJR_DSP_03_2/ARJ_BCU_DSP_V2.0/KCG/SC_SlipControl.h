/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
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
/** "Remark_1" {Description = "版权声明 本文件含有中国商用飞机有限责任公司的商业秘密，未经中国商用飞机有限责任公司批准， 不可将本文件或其中部分复印或引用到其他文件中，用于制造或其他目的。"} */
/** "Graphical_1" {Text = "版权声明 本文件含有中国商用飞机有限责任公司的商业秘密，未经中国商用飞机有限责任公司批准， 不可将本文件或其中部分复印或引用到其他文件中，用于制造或其他目的。 "} */
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
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

