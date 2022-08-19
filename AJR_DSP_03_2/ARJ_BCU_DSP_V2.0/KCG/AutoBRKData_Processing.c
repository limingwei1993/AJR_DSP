/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "AutoBRKData_Processing.h"

#ifndef KCG_USER_DEFINED_INIT
void AutoBRKData_Processing_init(outC_AutoBRKData_Processing *outC)
{
  outC->AutoBRKswitch.AutoBRK_OFF.Valid = kcg_true;
  outC->AutoBRKswitch.AutoBRK_OFF.Value = kcg_true;
  outC->AutoBRKswitch.AutoBRK_LOW.Valid = kcg_true;
  outC->AutoBRKswitch.AutoBRK_LOW.Value = kcg_true;
  outC->AutoBRKswitch.AutoBRK_MED.Valid = kcg_true;
  outC->AutoBRKswitch.AutoBRK_MED.Value = kcg_true;
  outC->AutoBRKswitch.AutoBRK_HI.Valid = kcg_true;
  outC->AutoBRKswitch.AutoBRK_HI.Value = kcg_true;
  outC->AutoBRKswitch.AutoBRK_RTO.Valid = kcg_true;
  outC->AutoBRKswitch.AutoBRK_RTO.Value = kcg_true;
  outC->AutoBRKswitch.AutoBRKfault = kcg_true;
  /* 1 */ Delay_OFF_init(&outC->Context_1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AutoBRKData_Processing_reset(outC_AutoBRKData_Processing *outC)
{
  /* 1 */ Delay_OFF_reset(&outC->Context_1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* AutoBRKData_Processing */
void AutoBRKData_Processing(
  /* AutoBRKData_Processing::Input1 */ tData_to_DSP *Input1,
  outC_AutoBRKData_Processing *outC)
{
  kcg_copy_tValidityBool(
    &outC->AutoBRKswitch.AutoBRK_OFF,
    &(*Input1).In_Discrete.AutoBRK_OFF);
  kcg_copy_tValidityBool(
    &outC->AutoBRKswitch.AutoBRK_LOW,
    &(*Input1).In_Discrete.AutoBRK_LOW);
  kcg_copy_tValidityBool(
    &outC->AutoBRKswitch.AutoBRK_MED,
    &(*Input1).In_Discrete.AutoBRK_MED);
  kcg_copy_tValidityBool(
    &outC->AutoBRKswitch.AutoBRK_HI,
    &(*Input1).In_Discrete.AutoBRK_HI);
  kcg_copy_tValidityBool(
    &outC->AutoBRKswitch.AutoBRK_RTO,
    &(*Input1).In_Discrete.AutoBRK_RTO);
  /* 1 */
  Delay_OFF(
    (kcg_bool)
      (/* 1 */ BTI((*Input1).In_Discrete.AutoBRK_HI.Value) + /* 2 */
        BTI((*Input1).In_Discrete.AutoBRK_LOW.Value) + /* 3 */
        BTI((*Input1).In_Discrete.AutoBRK_MED.Value) + /* 4 */
        BTI((*Input1).In_Discrete.AutoBRK_OFF.Value) + /* 5 */
        BTI((*Input1).In_Discrete.AutoBRK_RTO.Value) == kcg_lit_int8(1)),
    kcg_lit_int32(40),
    &outC->Context_1);
  outC->AutoBRKswitch.AutoBRKfault = !((*Input1).In_Discrete.AutoBRK_HI.Valid &
      (*Input1).In_Discrete.AutoBRK_LOW.Valid &
      (*Input1).In_Discrete.AutoBRK_MED.Valid &
      (*Input1).In_Discrete.AutoBRK_OFF.Valid &
      (*Input1).In_Discrete.AutoBRK_RTO.Valid & outC->Context_1.Output1);
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** AutoBRKData_Processing.c
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

