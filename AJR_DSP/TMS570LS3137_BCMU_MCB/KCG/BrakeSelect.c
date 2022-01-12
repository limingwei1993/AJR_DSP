/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "BrakeSelect.h"

/* BrakeSelect */
void BrakeSelect(
  /* BrakeSelect::BrakePdlOut */ tBrakePdlOut *BrakePdlOut,
  /* BrakeSelect::BrakeIfbOut */ tBrakeIfbOut *BrakeIfbOut,
  /* BrakeSelect::BrakeAutoBKOut */ tBrakeAutoBKOut *BrakeAutoBKOut,
  /* BrakeSelect::BrakeSelectOut */ tBrakeSelectOut *BrakeSelectOut)
{
  /* BrakeSelect */ array_bool_3 tmp1;
  /* BrakeSelect */ kcg_float32 tmp;
  /* BrakeSelect::_L29 */ kcg_int16 _L29;

  (*BrakeSelectOut).SOV_Open = (*BrakePdlOut).PedalBrakeActivate |
    (*BrakeIfbOut).IFB_BrakeActivate | (*BrakeAutoBKOut).AutoBrakeActivate;
  tmp1[0] = (*BrakePdlOut).PedalBrakeActivate;
  tmp1[1] = (*BrakeIfbOut).IFB_BrakeActivate;
  tmp1[2] = (*BrakeAutoBKOut).AutoBrakeActivate;
  _L29 = /* 1 */ BoolVect2Int16_digital_3(&tmp1);
  /* 2 */ switch (_L29) {
    case kcg_lit_int16(2) :
      (*BrakeSelectOut).LeftBrakePressureCommand =
        (*BrakeIfbOut).LeftIFB_BrakePressureCommand;
      tmp = (*BrakeIfbOut).RightIFB_BrakePressureCommand;
      break;
    case kcg_lit_int16(1) :
      (*BrakeSelectOut).LeftBrakePressureCommand =
        (*BrakeAutoBKOut).Left_BrakePressureCommand;
      tmp = (*BrakeAutoBKOut).Right_BrakePressureCommand;
      break;

    default :
      (*BrakeSelectOut).LeftBrakePressureCommand =
        (*BrakePdlOut).LeftPDL_BrakePressureCommand;
      tmp = (*BrakePdlOut).RightPDL_BrakePressureCommand;
      break;
  }
  (*BrakeSelectOut).RightBrakePressureCommand = tmp;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** BrakeSelect.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

