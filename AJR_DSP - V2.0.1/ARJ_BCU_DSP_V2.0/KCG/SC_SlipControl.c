/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SC_SlipControl.h"

#ifndef KCG_USER_DEFINED_INIT
void SC_SlipControl_init(outC_SC_SlipControl *outC)
{
  outC->StartBlending = kcg_true;
  /* 1 */ PI_Control_init(&outC->_1_Context_1);
  /* 1 */ SC_LowSpeedMonitor_init(&outC->Context_1);
  outC->BrakePressureCommandAdj = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void SC_SlipControl_reset(outC_SC_SlipControl *outC)
{
  /* 1 */ PI_Control_reset(&outC->_1_Context_1);
  /* 1 */ SC_LowSpeedMonitor_reset(&outC->Context_1);
  outC->BrakePressureCommandAdj = kcg_lit_float32(0.0);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/** "Remark_1" {Description = "版权声明 本文己兄泄逃梅苫邢拊鹑喂镜纳桃得孛埽淳泄逃梅苫邢拊鹑喂九迹?不可将本文蓟蚱渲胁糠指从』蛞玫狡渌募中，用于制造或其他目的。"} */
/** "Graphical_1" {Text = "版权声明 本文己兄泄逃梅苫邢拊鹑喂镜纳桃得孛埽淳泄逃梅苫邢拊鹑喂九迹?不可将本文蓟蚱渲胁糠指从』蛞玫狡渌募中，用于制造或其他目的。 "} */
/* SC_SlipControl */
void SC_SlipControl(
  /* SC_SlipControl::Speedref */ kcg_float32 Speedref,
  /* SC_SlipControl::Wheelspeed */ kcg_float32 Wheelspeed,
  /* SC_SlipControl::SC_enter */ kcg_bool SC_enter,
  outC_SC_SlipControl *outC)
{
  /* SC_SlipControl */ kcg_float32 tmp;
  /* SC_SlipControl::Ref_new */ kcg_float32 Ref_new;
  /* SC_SlipControl::_L14 */ kcg_float32 _L14;

  /* 2 */ if (Speedref >= Wheelspeed) {
    Ref_new = Speedref;
  }
  else {
    Ref_new = Wheelspeed;
  }
  /* 1 */ SC_LowSpeedMonitor(Ref_new, &outC->Context_1);
  outC->StartBlending = !outC->Context_1.SkidEnable;
  _L14 = Ref_new - Wheelspeed;
  /* 1 */ if (outC->Context_1.SkidEnable) {
    tmp = Ref_new;
  }
  else {
    tmp = kcg_lit_float32(1.0);
  }
  /* 1 */
  PI_Control(
    _L14 / tmp,
    Slip_ini,
    SC_enter,
    Ki1,
    Kp1,
    Zero,
    (kcg_bool) (_L14 >= huashui),
    DT_T,
    &outC->_1_Context_1);
  /* 2 */ if (outC->Context_1.SkidEnable) {
    outC->BrakePressureCommandAdj = outC->_1_Context_1.Command;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** SC_SlipControl.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

