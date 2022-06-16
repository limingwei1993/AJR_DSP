/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V1/BCS_Brake/KCG/config.txt
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */
#ifndef _KCG_CONSTS_H_
#define _KCG_CONSTS_H_

#include "kcg_types.h"

/* zero_ */
#define zero_ (kcg_lit_int64(0))

/* Tol_R */
#define Tol_R (kcg_lit_float32(0.01))

/* Tol_LM */
#define Tol_LM (kcg_lit_float32(0.01))

/* Tol_L */
#define Tol_L (kcg_lit_float32(0.01))

/* Tol__ */
#define Tol__ (kcg_lit_float32(0.00001))

/* Slip_min */
#define Slip_min (kcg_lit_float32(0.06))

/* Sl_P */
#define Sl_P (kcg_lit_float32(0.06))

/* Sl_m */
#define Sl_m (kcg_lit_float32(0.02))

/* one_ */
#define one_ (kcg_lit_int64(1))

/* MaxPressure */
#define MaxPressure (kcg_lit_float32(3000.0))

/* Log_Sl_P */
#define Log_Sl_P (kcg_lit_float32(-2.8134))

/* Log_Sl_m */
#define Log_Sl_m (kcg_lit_float32(-3.9120))

/* Kp */
#define Kp (kcg_lit_float32(7000.0))

/* Ki */
#define Ki (kcg_lit_float32(1000.0))

/* Gain_Kp */
#define Gain_Kp (kcg_lit_float32(6.0))

/* Gain_Ki */
#define Gain_Ki (kcg_lit_float32(0.6))

/* DT_R */
#define DT_R (kcg_lit_float32(0.001))

/* DT_L */
#define DT_L (kcg_lit_float32(0.001))

/* C_SKID_Y_PSI */
extern const array_float32_5 C_SKID_Y_PSI;

/* C_SKID_X_MPA */
extern const array_float32_5 C_SKID_X_MPA;

/* C_SC_BLENDING_RATE */
#define C_SC_BLENDING_RATE (kcg_lit_float32(1500.0))

/* C_SC_BLENDING_MAX_STEPS */
#define C_SC_BLENDING_MAX_STEPS (kcg_lit_float32(600.))

/* brakecmd */
#define brakecmd (kcg_lit_float32(500.0))

/* percent1 */
#define percent1 (kcg_lit_float32(0.51))

/* outputpressure1 */
#define outputpressure1 (kcg_lit_float32(0.0))

/* outputpressure2 */
#define outputpressure2 (kcg_lit_float32(1500.))

/* Constant3 */
#define Constant3 (kcg_lit_int8(2))

/* Constant5 */
#define Constant5 (kcg_lit_int8(1))

/* Constant6 */
#define Constant6 (kcg_lit_int8(20))

/* Constant1 */
#define Constant1 (kcg_lit_float32(0.0))

/* Tol_R1 */
#define Tol_R1 (kcg_lit_float32(0.01))

/* Tol_LM1 */
#define Tol_LM1 (kcg_lit_float32(0.01))

/* Tol_L1 */
#define Tol_L1 (kcg_lit_float32(0.01))

/* Tol__1 */
#define Tol__1 (kcg_lit_float32(0.00001))

/* Slip_min1 */
#define Slip_min1 (kcg_lit_float32(0.06))

/* Slip_ini1 */
#define Slip_ini1 (kcg_lit_float32(0.10))

/* Sl_P1 */
#define Sl_P1 (kcg_lit_float32(0.06))

/* Sl_m1 */
#define Sl_m1 (kcg_lit_float32(0.02))

/* MaxPressure1 */
#define MaxPressure1 (kcg_lit_float32(3000.0))

/* Log_Sl_P1 */
#define Log_Sl_P1 (kcg_lit_float32(-2.8134))

/* Log_Sl_m1 */
#define Log_Sl_m1 (kcg_lit_float32(-3.9120))

/* huashui1 */
#define huashui1 (kcg_lit_float32(15.4333))

/* Gain_Kp1 */
#define Gain_Kp1 (kcg_lit_float32(6.0))

/* Gain_Ki1 */
#define Gain_Ki1 (kcg_lit_float32(0.6))

/* DT_T1 */
#define DT_T1 (kcg_lit_float32(0.015))

/* DT_R1 */
#define DT_R1 (kcg_lit_float32(0.001))

/* DT_L1 */
#define DT_L1 (kcg_lit_float32(0.001))

/* C_SKID_Y_PSI1 */
extern const array_float32_5 C_SKID_Y_PSI1;

/* C_SKID_X_MPA1 */
extern const array_float32_5 C_SKID_X_MPA1;

/* C_SC_BLENDING_RATE1 */
#define C_SC_BLENDING_RATE1 (kcg_lit_float32(1500.0))

/* C_SC_BLENDING_MAX_STEPS1 */
#define C_SC_BLENDING_MAX_STEPS1 (kcg_lit_float32(600.))

/* reference_wheel_speed */
#define reference_wheel_speed (kcg_lit_float32(30.))

/* equ_6_par_3 */
#define equ_6_par_3 (kcg_lit_float32(66000.))

/* equ_6_par_2 */
#define equ_6_par_2 (kcg_lit_float32(31.))

/* equ_6_par_1 */
#define equ_6_par_1 (kcg_lit_float32(1590.))

/* equ_6_par_4 */
#define equ_6_par_4 (kcg_lit_float32(31.))

/* equ_5_par_3 */
#define equ_5_par_3 (kcg_lit_float32(825.))

/* equ_5_par_2 */
#define equ_5_par_2 (kcg_lit_float32(23.))

/* equ_5_par_1 */
#define equ_5_par_1 (kcg_lit_float32(745.))

/* equ_4_par_4 */
#define equ_4_par_4 (kcg_lit_float32(5.))

/* equ_4_par_3 */
#define equ_4_par_3 (kcg_lit_float32(907.))

/* equ_4_par_2 */
#define equ_4_par_2 (kcg_lit_float32(5.))

/* equ_4_par_1 */
#define equ_4_par_1 (kcg_lit_float32(92.))

/* equ_3_par_4 */
#define equ_3_par_4 (kcg_lit_float32(8.))

/* equ_3_par_3 */
#define equ_3_par_3 (kcg_lit_float32(205.))

/* equ_3_par_2 */
#define equ_3_par_2 (kcg_lit_float32(16.))

/* equ_3_par_1 */
#define equ_3_par_1 (kcg_lit_float32(167.))

/* equ_2_par_3 */
#define equ_2_par_3 (kcg_lit_float32(205.))

/* equ_2_par_2 */
#define equ_2_par_2 (kcg_lit_float32(2.))

/* equ_2_par_1 */
#define equ_2_par_1 (kcg_lit_float32(67.))

/* PedalDisplacementPercent_7 */
#define PedalDisplacementPercent_7 (kcg_lit_float32(100.))

/* PedalDisplacementPercent_6 */
#define PedalDisplacementPercent_6 (kcg_lit_float32(69.))

/* PedalDisplacementPercent_5 */
#define PedalDisplacementPercent_5 (kcg_lit_float32(46.))

/* PedalDisplacementPercent_4 */
#define PedalDisplacementPercent_4 (kcg_lit_float32(26.))

/* PedalDisplacementPercent_3 */
#define PedalDisplacementPercent_3 (kcg_lit_float32(10.))

/* PedalDisplacementPercent_2 */
#define PedalDisplacementPercent_2 (kcg_lit_float32(8.0))

/* PedalDisplacementPercent_1 */
#define PedalDisplacementPercent_1 (kcg_lit_float32(0.0))

/* equ_7_par_1 */
#define equ_7_par_1 (kcg_lit_float32(3000.))

/* equ_1_par_1 */
#define equ_1_par_1 (kcg_lit_float32(63.))

/* Error */
#define Error (kcg_lit_float32(-1.))

/* Acc_Lo */
#define Acc_Lo (kcg_lit_float32(5.0))

/* Acc_MED */
#define Acc_MED (kcg_lit_float32(9.0))

/* Acc_HI */
#define Acc_HI (kcg_lit_float32(20.))

/* zero */
#define zero (kcg_lit_float32(0.0))

/* PedaldisArm */
#define PedaldisArm (kcg_lit_float32(0.2))

/* RTO_ARM */
#define RTO_ARM (kcg_lit_float32(10.))

/* Pedal_RTO */
#define Pedal_RTO (kcg_lit_float32(0.8))

/* RTO */
#define RTO (kcg_lit_float32(70.))

/* Brakespeed */
#define Brakespeed (kcg_lit_float32(60.0))

/* Zero */
#define Zero (kcg_lit_float32(0.0))

/* Slip_ini */
#define Slip_ini (kcg_lit_float32(0.10))

/* huashui */
#define huashui (kcg_lit_float32(15.4333))

/* DT_T */
#define DT_T (kcg_lit_float32(0.015))

/* Kp1 */
#define Kp1 (kcg_lit_float32(7000.0))

/* Ki1 */
#define Ki1 (kcg_lit_float32(1000.0))

/* Zero1 */
#define Zero1 (kcg_lit_float32(0.0))

/* N */
#define N (kcg_lit_int32(1000))

/* lowlimit */
#define lowlimit (kcg_lit_float32(0.))

/* highlimit */
#define highlimit (kcg_lit_float32(1500.))

/* k */
#define k (kcg_lit_float32(5.))

#endif /* _KCG_CONSTS_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** kcg_consts.h
** Generation date: 2021-12-14T16:08:37
*************************************************************$ */

