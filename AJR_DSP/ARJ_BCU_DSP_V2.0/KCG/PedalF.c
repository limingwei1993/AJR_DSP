/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "PedalF.h"

/* PedalF */
kcg_float32 PedalF(/* PedalF::Input1 */ kcg_float32 Input1)
{
  /* PedalF::IfBlock1::else */ kcg_bool _5_else_clock_IfBlock1;
  /* PedalF::IfBlock1::else::else::else */ kcg_bool _3_else_clock_IfBlock1;
  /* PedalF::IfBlock1::else::else::else::else::else */ kcg_bool _1_else_clock_IfBlock1;
  /* PedalF::IfBlock1::else::else::else::else::else::else */ kcg_bool else_clock_IfBlock1;
  /* PedalF::IfBlock1::else::else::else::else */ kcg_bool _2_else_clock_IfBlock1;
  /* PedalF::IfBlock1::else::else */ kcg_bool _4_else_clock_IfBlock1;
  /* PedalF::Local2 */ kcg_bool Local2;
  /* PedalF::Output1 */ kcg_float32 Output1;

  Local2 = (Input1 >= PedalDisplacementPercent_1) & (Input1 <
      PedalDisplacementPercent_2);
  /* ck_Local2 */ if (Local2) {
    Output1 = equ_1_par_1;
  }
  else {
    _5_else_clock_IfBlock1 = (Input1 >= PedalDisplacementPercent_2) & (Input1 <
        PedalDisplacementPercent_3);
    /* ck_anon_activ */ if (_5_else_clock_IfBlock1) {
      Output1 = /* 1 */ equ_2(Input1);
    }
    else {
      _4_else_clock_IfBlock1 = (Input1 >= PedalDisplacementPercent_3) &
        (Input1 < PedalDisplacementPercent_4);
      /* ck_anon_activ */ if (_4_else_clock_IfBlock1) {
        Output1 = /* 1 */ equ_3(Input1);
      }
      else {
        _3_else_clock_IfBlock1 = (Input1 >= PedalDisplacementPercent_4) &
          (Input1 < PedalDisplacementPercent_5);
        /* ck_anon_activ */ if (_3_else_clock_IfBlock1) {
          Output1 = /* 1 */ equ_4(Input1);
        }
        else {
          _2_else_clock_IfBlock1 = (Input1 >= PedalDisplacementPercent_5) &
            (Input1 < PedalDisplacementPercent_6);
          /* ck_anon_activ */ if (_2_else_clock_IfBlock1) {
            Output1 = /* 1 */ equ_5(Input1);
          }
          else {
            _1_else_clock_IfBlock1 = (Input1 >= PedalDisplacementPercent_6) &
              (Input1 < PedalDisplacementPercent_7);
            /* ck_anon_activ */ if (_1_else_clock_IfBlock1) {
              Output1 = /* 1 */ equ_6(Input1);
            }
            else {
              else_clock_IfBlock1 = Input1 < PedalDisplacementPercent_1;
              /* ck_anon_activ */ if (else_clock_IfBlock1) {
                Output1 = Error;
              }
              else {
                Output1 = equ_7_par_1;
              }
            }
          }
        }
      }
    }
  }
  return Output1;
}

/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** PedalF.c
** Generation date: 2021-12-14T16:08:38
*************************************************************$ */

