/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Rate_select.h"

/* Rate_select */
kcg_float32 Rate_select(
  /* Rate_select::Low */ kcg_bool Low,
  /* Rate_select::Med */ kcg_bool Med,
  /* Rate_select::Hi */ kcg_bool Hi,
  /* Rate_select::RTO */ kcg_bool RTO,
  /* Rate_select::Ref */ kcg_float32 Ref)
{
  /* Rate_select::Output1 */ kcg_float32 Output1;

  /* ck_Low */ if (Low) {
    Output1 = Acc_Lo;
  }
  else /* ck_anon_activ */ if (Med) {
    Output1 = Acc_MED;
  }
  else /* ck_anon_activ */ if (Hi) {
    Output1 = Acc_HI;
  }
  else /* ck_anon_activ */ if (RTO) {
    /* 1 */ if (Ref > RTO_H) {
      Output1 = kcg_lit_float32(20.0);
    }
    else {
      Output1 = Acc_MED;
    }
  }
  else {
    Output1 = kcg_lit_float32(0.0);
  }
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Rate_select.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

