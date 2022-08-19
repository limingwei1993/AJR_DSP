/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "BrakeInhibit.h"

/* BrakeInhibit */
void BrakeInhibit(
  /* BrakeInhibit::TDP */ kcg_bool TDP1,
  /* BrakeInhibit::LWP_L */ kcg_bool LWP_L,
  /* BrakeInhibit::LWP_R */ kcg_bool LWP_R,
  /* BrakeInhibit::BrakeSelectOut */ tBrakeSelectOut *BrakeSelectOut,
  /* BrakeInhibit::BrakeSkidOut */ tBrakeSkidOut *BrakeSkidOut,
  /* BrakeInhibit::BrakeInhibitOut */ tBrakeInhibitOut *BrakeInhibitOut)
{
  (*BrakeInhibitOut).SOV_Open = (*BrakeSelectOut).SOV_Open & !TDP1;
  (*BrakeInhibitOut).BrakeInhibits.TDP_BrakeInhibit = TDP1;
  (*BrakeInhibitOut).BrakeInhibits.LWP_LeftBrakeInhibit = LWP_L;
  (*BrakeInhibitOut).BrakeInhibits.LWP_RightBrakeInhibit = LWP_R;
  /* 1 */ if (TDP1 | LWP_L) {
    (*BrakeInhibitOut).LeftBrakePressureCommandAdj = kcg_lit_float32(0.0);
  }
  else {
    (*BrakeInhibitOut).LeftBrakePressureCommandAdj =
      (*BrakeSkidOut).LeftBrakePressureCommandAdj;
  }
  /* 2 */ if (TDP1 | LWP_R) {
    (*BrakeInhibitOut).RightBrakePressureCommandAdj = kcg_lit_float32(0.0);
  }
  else {
    (*BrakeInhibitOut).RightBrakePressureCommandAdj =
      (*BrakeSkidOut).RightBrakePressureCommandAdj;
  }
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BrakeInhibit.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

