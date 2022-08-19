/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "BrakePress.h"

/* BrakePress */
void BrakePress(
  /* BrakePress::APPData */ tINPUT_Data *APPData,
  /* BrakePress::BrakePdlOut */ tBrakePdlOut *BrakePdlOut)
{
  /* BrakePress::_L4 */ kcg_float32 _L4;
  /* BrakePress::_L3 */ kcg_float32 _L3;

  /* 2 */ if ((*APPData).PedalData.LeftCptPedal.Value >=
    (*APPData).PedalData.LeftPPedal.Value) {
    _L4 = (*APPData).PedalData.LeftCptPedal.Value;
  }
  else {
    _L4 = (*APPData).PedalData.LeftPPedal.Value;
  }
  /* 2 */ if ((*APPData).PedalData.RightCptPedal.Value >=
    (*APPData).PedalData.RightPPedal.Value) {
    _L3 = (*APPData).PedalData.RightCptPedal.Value;
  }
  else {
    _L3 = (*APPData).PedalData.RightPPedal.Value;
  }
  (*BrakePdlOut).PedalBrakeActivate = (_L4 > kcg_lit_float32(0.05)) & (_L3 >
      kcg_lit_float32(0.05));
  (*BrakePdlOut).LeftPDL_BrakePressureCommand = /* 1 */ PedalF(_L4);
  (*BrakePdlOut).RightPDL_BrakePressureCommand = /* 2 */ PedalF(_L3);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BrakePress.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

