/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** Command: kcg65.exe -config S:/CR929/BrakeControlLow/SCADE_Mod/BCS_Model_V3/BCS_Brake/KCG/config.txt
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#include "stddef.h"

#define KCG_MAPW_CPY

#include "./user_macros.h"

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_float32
#define kcg_float32 kcg_float32
typedef float kcg_float32;
#endif /* kcg_float32 */

#ifndef kcg_float64
#define kcg_float64 kcg_float64
typedef double kcg_float64;
#endif /* kcg_float64 */

#ifndef kcg_size
#define kcg_size kcg_size
typedef ptrdiff_t kcg_size;
#endif /* kcg_size */

#ifndef kcg_uint64
#define kcg_uint64 kcg_uint64
typedef unsigned long long kcg_uint64;
#endif /* kcg_uint64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef unsigned long kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef unsigned short kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef unsigned char kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int64
#define kcg_int64 kcg_int64
typedef signed long long kcg_int64;
#endif /* kcg_int64 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef signed long kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef signed short kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef signed char kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_lit_float32
#define kcg_lit_float32(kcg_C1) ((kcg_float32) (kcg_C1))
#endif /* kcg_lit_float32 */

#ifndef kcg_lit_float64
#define kcg_lit_float64(kcg_C1) ((kcg_float64) (kcg_C1))
#endif /* kcg_lit_float64 */

#ifndef kcg_lit_size
#define kcg_lit_size(kcg_C1) ((kcg_size) (kcg_C1))
#endif /* kcg_lit_size */

#ifndef kcg_lit_uint64
#define kcg_lit_uint64(kcg_C1) ((kcg_uint64) (kcg_C1))
#endif /* kcg_lit_uint64 */

#ifndef kcg_lit_uint32
#define kcg_lit_uint32(kcg_C1) ((kcg_uint32) (kcg_C1))
#endif /* kcg_lit_uint32 */

#ifndef kcg_lit_uint16
#define kcg_lit_uint16(kcg_C1) ((kcg_uint16) (kcg_C1))
#endif /* kcg_lit_uint16 */

#ifndef kcg_lit_uint8
#define kcg_lit_uint8(kcg_C1) ((kcg_uint8) (kcg_C1))
#endif /* kcg_lit_uint8 */

#ifndef kcg_lit_int64
#define kcg_lit_int64(kcg_C1) ((kcg_int64) (kcg_C1))
#endif /* kcg_lit_int64 */

#ifndef kcg_lit_int32
#define kcg_lit_int32(kcg_C1) ((kcg_int32) (kcg_C1))
#endif /* kcg_lit_int32 */

#ifndef kcg_lit_int16
#define kcg_lit_int16(kcg_C1) ((kcg_int16) (kcg_C1))
#endif /* kcg_lit_int16 */

#ifndef kcg_lit_int8
#define kcg_lit_int8(kcg_C1) ((kcg_int8) (kcg_C1))
#endif /* kcg_lit_int8 */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_lnot_uint64
#define kcg_lnot_uint64(kcg_C1) ((kcg_C1) ^ 0xffffffffffffffff)
#endif /* kcg_lnot_uint64 */

#ifndef kcg_lnot_uint32
#define kcg_lnot_uint32(kcg_C1) ((kcg_C1) ^ 0xffffffff)
#endif /* kcg_lnot_uint32 */

#ifndef kcg_lnot_uint16
#define kcg_lnot_uint16(kcg_C1) ((kcg_C1) ^ 0xffff)
#endif /* kcg_lnot_uint16 */

#ifndef kcg_lnot_uint8
#define kcg_lnot_uint8(kcg_C1) ((kcg_C1) ^ 0xff)
#endif /* kcg_lnot_uint8 */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* truthtables::TruthTableValues */
typedef enum kcg_tag_TruthTableValues_truthtables {
  T_truthtables,
  F_truthtables,
  X_truthtables
} TruthTableValues_truthtables;
/** "Remark_1" {Description = "后续常数项梳理，统一定义"} */
/* sigle::SM1 */
typedef enum kcg_tag__7_SSM_TR_SM1 {
  _6_SSM_TR_no_trans_SM1,
  SSM_TR_LockWheelEnable_1_SM1,
  SSM_TR_LockWheelDisable_1_SM1
} _7_SSM_TR_SM1;
/** "Remark_1" {Description = "后续常数项梳理，统一定义"} */
/* sigle::SM1 */
typedef enum kcg_tag__5_SSM_ST_SM1 {
  SSM_st_LockWheelEnable_SM1,
  SSM_st_LockWheelDisable_SM1
} _5_SSM_ST_SM1;
/* SC_LowSpeedMonitor::SM_LowSpeedMonitor */
typedef enum kcg_tag_SSM_TR_SM_LowSpeedMonitor {
  SSM_TR_no_trans_SM_LowSpeedMonitor,
  SSM_TR_StateEnabled_1_SM_LowSpeedMonitor,
  SSM_TR_StateDisabled_1_SM_LowSpeedMonitor
} SSM_TR_SM_LowSpeedMonitor;
/* SC_LowSpeedMonitor::SM_LowSpeedMonitor */
typedef enum kcg_tag_SSM_ST_SM_LowSpeedMonitor {
  SSM_st_StateEnabled_SM_LowSpeedMonitor,
  SSM_st_StateDisabled_SM_LowSpeedMonitor
} SSM_ST_SM_LowSpeedMonitor;
/* stm::SM1 */
typedef enum kcg_tag__4_SSM_TR_SM1 {
  _3_SSM_TR_no_trans_SM1,
  SSM_TR_RTOArmedState_1_SM1,
  SSM_TR_RTOArmedState_2_SM1,
  SSM_TR_OFF_State_1_SM1,
  SSM_TR_OFF_State_2_SM1,
  SSM_TR_LandingArmedState_1_SM1,
  SSM_TR_LandingArmedState_2_SM1,
  SSM_TR_LandingApplicationState_1_SM1,
  SSM_TR_RTOEnabledState_1_SM1,
  SSM_TR_RTOEnabledState_2_SM1,
  SSM_TR_RTOEnabledState_3_SM1,
  SSM_TR_RTOApplicationState_1_SM1,
  SSM_TR_LandingEnableState_1_SM1,
  SSM_TR_LandingEnableState_2_SM1,
  SSM_TR_LandingDisarmedState_1_SM1
} _4_SSM_TR_SM1;
/* stm::SM1 */
typedef enum kcg_tag__2_SSM_ST_SM1 {
  SSM_st_RTOArmedState_SM1,
  SSM_st_OFF_State_SM1,
  SSM_st_LandingArmedState_SM1,
  SSM_st_LandingApplicationState_SM1,
  SSM_st_RTOEnabledState_SM1,
  SSM_st_RTOApplicationState_SM1,
  SSM_st_LandingEnableState_SM1,
  SSM_st_LandingDisarmedState_SM1
} _2_SSM_ST_SM1;
/* AutoBrake::SM1 */
typedef enum kcg_tag_SSM_TR_SM1 {
  SSM_TR_no_trans_SM1,
  SSM_TR_State1_1_SM1,
  SSM_TR_State1_2_SM1,
  SSM_TR_State2_1_SM1,
  SSM_TR_State3_1_SM1
} SSM_TR_SM1;
/* AutoBrake::SM1 */
typedef enum kcg_tag_SSM_ST_SM1 {
  SSM_st_State1_SM1,
  SSM_st_State2_SM1,
  SSM_st_State3_SM1
} SSM_ST_SM1;
/* mathext::Type1 */
typedef kcg_int32 Type1_mathext;

/* tValidityU32 */
typedef struct kcg_tag_tValidityU32 {
  kcg_bool Valid;
  kcg_uint32 Value;
} tValidityU32;

/* tValidityS32 */
typedef struct kcg_tag_tValidityS32 {
  kcg_bool Valid;
  kcg_int32 Value;
} tValidityS32;

/* tValidityF32 */
typedef struct kcg_tag_tValidityF32 {
  kcg_bool Valid;
  kcg_float32 Value;
} tValidityF32;

/* tIOR_ProcessPedalData */
typedef struct kcg_tag_tIOR_ProcessPedalData {
  tValidityF32 LeftCptPedal;
  tValidityF32 RightCptPedal;
  tValidityF32 LeftPPedal;
  tValidityF32 RightPPedal;
  kcg_float32 MaxPedal;
} tIOR_ProcessPedalData;

/* tIOR_ProcessSpeedData */
typedef struct kcg_tag_tIOR_ProcessSpeedData {
  tValidityF32 LeftWheelSpeed;
  tValidityF32 RightWheelSpeed;
  tValidityF32 LeftWheelRefSpeed;
  tValidityF32 RightWheelRefSpeed;
  tValidityF32 LWP_RefSpeed;
  kcg_float32 WheelSpeed_av;
} tIOR_ProcessSpeedData;

/* tValidityBool */
typedef struct kcg_tag_tValidityBool {
  kcg_bool Valid;
  kcg_bool Value;
} tValidityBool;

/* tIOR_ProcessAutoFlightData */
typedef struct kcg_tag_tIOR_ProcessAutoFlightData {
  tValidityBool TOGA_Active;
} tIOR_ProcessAutoFlightData;

/* tIOR_ProcessAircraftData */
typedef struct kcg_tag_tIOR_ProcessAircraftData {
  tValidityF32 Airspeed;
  tValidityF32 AircraftAcceleration_Left;
  tValidityF32 AircraftAcceleration1_Right;
  tValidityF32 AircraftAcceleration_av;
  kcg_bool SpoilerStoredSignal_Left;
  kcg_bool SpoilerStoredSignal_Right;
  tValidityF32 AircraftGroundSpeed;
  tValidityF32 AircraftAttitude;
} tIOR_ProcessAircraftData;

/* tIOR_ProcessWowData */
typedef struct kcg_tag_tIOR_ProcessWowData {
  kcg_bool LeftWOW;
  kcg_bool RightWOW;
  tValidityBool zong;
  kcg_bool WOWBK;
} tIOR_ProcessWowData;

/* tIOR_ProcessAutobrakeData */
typedef struct kcg_tag_tIOR_ProcessAutobrakeData {
  tValidityBool AutoBRK_OFF;
  tValidityBool AutoBRK_LOW;
  tValidityBool AutoBRK_MED;
  tValidityBool AutoBRK_HI;
  tValidityBool AutoBRK_RTO;
  kcg_bool AutoBRKfault;
} tIOR_ProcessAutobrakeData;

/* tIOR_ProcessHydraulicData */
typedef struct kcg_tag_tIOR_ProcessHydraulicData {
  kcg_bool HighPressure;
} tIOR_ProcessHydraulicData;

/* tIOR_ProcessThrottleData */
typedef struct kcg_tag_tIOR_ProcessThrottleData {
  kcg_bool LeftThrottleIdle;
  kcg_bool RightThrottleIdle;
  kcg_bool ThrottleIdleAtLeastOne;
  kcg_bool ThrottleIdleBoth;
} tIOR_ProcessThrottleData;

/* tIOR_ProcessLandingGearData */
typedef struct kcg_tag_tIOR_ProcessLandingGearData {
  kcg_bool LG_GearDown_Locked;
  kcg_bool LandingGearExtentionandRetractionCommand;
} tIOR_ProcessLandingGearData;

/* tINPUT_Data */
typedef struct kcg_tag_tINPUT_Data {
  tIOR_ProcessAircraftData Aircraft_Data;
  tIOR_ProcessWowData WOWData;
  tIOR_ProcessPedalData PedalData;
  tIOR_ProcessThrottleData ThrottleData;
  tIOR_ProcessLandingGearData LGData;
  tIOR_ProcessHydraulicData HydraulicData;
  tIOR_ProcessAutobrakeData AutoBrakeData;
  tIOR_ProcessSpeedData WheelSpeedData;
} tINPUT_Data;

/* tBrakeInhibits */
typedef struct kcg_tag_tBrakeInhibits {
  kcg_bool TDP_BrakeInhibit;
  kcg_bool LWP_LeftBrakeInhibit;
  kcg_bool LWP_RightBrakeInhibit;
} tBrakeInhibits;

/* tBrakePdlOut */
typedef struct kcg_tag_tBrakePdlOut {
  kcg_float32 LeftPDL_BrakePressureCommand;
  kcg_float32 RightPDL_BrakePressureCommand;
  kcg_bool PedalBrakeActivate;
} tBrakePdlOut;

/* tBrakeSelectOut */
typedef struct kcg_tag_tBrakeSelectOut {
  kcg_bool SOV_Open;
  kcg_float32 LeftBrakePressureCommand;
  kcg_float32 RightBrakePressureCommand;
} tBrakeSelectOut;

/* tBrakeSkidOut */
typedef struct kcg_tag_tBrakeSkidOut {
  kcg_bool LeftSkidEnable;
  kcg_float32 LeftBrakePressureCommandAdj;
  kcg_float32 Ratio;
  kcg_bool RightSkidEnable;
  kcg_float32 RightBrakePressureCommandAdj;
} tBrakeSkidOut;

/* tBrakeIfbOut */
typedef struct kcg_tag_tBrakeIfbOut {
  kcg_bool IFB_BrakeActivate;
  kcg_float32 LeftIFB_BrakePressureCommand;
  kcg_float32 RightIFB_BrakePressureCommand;
} tBrakeIfbOut;

/* tBrakeInhibitOut */
typedef struct kcg_tag_tBrakeInhibitOut {
  kcg_bool SOV_Open;
  kcg_float32 LeftBrakePressureCommandAdj;
  kcg_float32 RightBrakePressureCommandAdj;
  tBrakeInhibits BrakeInhibits;
} tBrakeInhibitOut;

/* tAutobrakeState */
typedef struct kcg_tag_tAutobrakeState {
  kcg_bool LandingArmedState;
  kcg_bool LandingApplicationState;
  kcg_bool LandingEnabledState;
  kcg_bool LandingDisArmedState;
  kcg_bool RTOArmedState;
  kcg_bool RTOEnabledState;
  kcg_bool RTODisarmedState;
  kcg_bool RTOApplicationState;
  kcg_bool OFFState;
} tAutobrakeState;

/* tBCU_an */
typedef struct kcg_tag_tBCU_an { tAutobrakeState AutobrakeState; } tBCU_an;

/* bool_word */
typedef kcg_bool bool_word[32];

/* bool_wordshort */
typedef kcg_bool bool_wordshort[16];

/* HcDiscreteWord */
typedef struct kcg_tag_HcDiscreteWord {
  kcg_bool Hc_RtSpoiler_stowed;
  kcg_bool Hc_RtThrottle_idle;
  kcg_bool Hc_Parkbrakeon_OB;
  kcg_bool Hc_ABS_OB;
  kcg_bool Hc_Lt_WOW;
  kcg_bool Hc_GearHandle_OB;
  kcg_bool AutoBK_OFF_OB;
  kcg_bool AutoBK_LOW_OB;
  kcg_bool AutoBK_MED_OB;
  kcg_bool AutoBK_HI_OB;
  kcg_bool AutoBK_RTO_OB;
  kcg_bool Hc_LtSpoiler_stowed;
  kcg_bool Hc_LtThrottle_idle;
  kcg_bool Hc_Parkbrakeon_IB;
  kcg_bool Hc_ABS_IB;
  kcg_bool Hc_Rt_WOW;
  kcg_bool Hc_GearHandle_IB;
  kcg_bool AutoBK_OFF_IB;
  kcg_bool AutoBK_LOW_IB;
  kcg_bool AutoBK_MED_IB;
  kcg_bool AutoBK_HI_IB;
  kcg_bool AutoBK_RTO_IB;
} HcDiscreteWord;

/* A429_Valid_short */
typedef struct kcg_tag_A429_Valid_short {
  kcg_bool Acceleration_RT;
  kcg_bool Acceleration_LT;
  kcg_bool Computed_WOW2;
  kcg_bool Computed_WOW1;
  kcg_bool MLG_LtDownlocked;
  kcg_bool MLG_RtDownlocked;
  kcg_bool Date_Master;
  kcg_bool AirSpeed;
  kcg_bool Master_Time;
  kcg_bool TLA_Position_Right;
  kcg_bool TLA_Position_Left;
  kcg_bool Accumulator_Pressure;
  kcg_bool HS_Pressure;
} A429_Valid_short;

/* tIn_Discrete */
typedef struct kcg_tag_tIn_Discrete {
  kcg_bool SpoilerStoredSignal_Left;
  kcg_bool SpoilerStoredSignal_Right;
  kcg_bool LeftWOW;
  kcg_bool RightWOW;
  kcg_bool LeftThrottleIdle;
  kcg_bool RightThrottleIdle;
  kcg_bool ThrottleIdleAtLeastOne;
  kcg_bool ThrottleIdleBoth;
  tValidityBool AutoBRK_OFF;
  tValidityBool AutoBRK_LOW;
  tValidityBool AutoBRK_MED;
  tValidityBool AutoBRK_HI;
  tValidityBool AutoBRK_RTO;
  kcg_bool GearHandle;
  kcg_bool Inner_wheel_ABS_start_signal;
  kcg_bool Parking_brake_signal;
  kcg_bool spare;
  kcg_bool PIN_PGR_1;
  kcg_bool PIN_PGR_2;
} tIn_Discrete;

/* tData_to_DSP */
typedef struct kcg_tag_tData_to_DSP {
  tIn_Discrete In_Discrete;
  tValidityF32 In_HcLeftWheelAngularSpeed;
  tValidityF32 In_HcRightWheelAngularSpeed;
  kcg_float32 In_HcLeftBrakePressure;
  kcg_float32 In_HcRightBrakePressure;
  kcg_float32 In_HcLeftBrakeTemperature;
  kcg_float32 In_HcRightBrakeTemperature;
  tValidityF32 In_PLT_LT_LVDT_Percent;
  tValidityF32 In_PLT_RT_LVDT_Percent;
  tValidityF32 In_CPLT_LT_LVDT_Percent;
  tValidityF32 In_CPLT_RT_LVDT_Percent;
  kcg_float32 In_Right_BCV_Current;
  kcg_float32 In_Left_BCV_Current;
  kcg_float32 In_SOV_Current;
  kcg_float32 In_Hydraulic_System_Pressure_60;
  kcg_float32 In_Accumulator_Pressure_126;
  kcg_float32 In_TLA_Position_Left_133;
  kcg_float32 In_TLA_Position_Right_133;
  kcg_uint32 In_Master_Time_150;
  tValidityF32 In_Computed_Air_Speed_206;
  kcg_uint32 In_Date_Master_260;
  kcg_bool In_MLG_RtDownlocked;
  kcg_bool In_MLG_LtDownlocked;
  kcg_uint32 In_Computed_WOW1_Data_277;
  kcg_uint32 In_Computed_WOW2_Data_277;
  tValidityF32 _1_In_Longitudinal_Acceleration_Body_Left_331;
  tValidityF32 In_Longitudinal_Acceleration_Body_Right_331;
} tData_to_DSP;

/* tTestData */
typedef struct kcg_tag_tTestData {
  kcg_bool AUTOBRKfault;
  kcg_bool ARMdisagree;
  kcg_bool latch;
  kcg_bool unlatch;
  kcg_float32 maxpedal;
} tTestData;

/* tBrakeAutoBKOut */
typedef struct kcg_tag_tBrakeAutoBKOut {
  kcg_bool AutoBrakeActivate;
  kcg_float32 Left_BrakePressureCommand;
  kcg_float32 Right_BrakePressureCommand;
  kcg_bool ArmDisagree;
  tAutobrakeState AutoBrakeState;
  kcg_bool CoilEnergized;
  tTestData testData;
} tBrakeAutoBKOut;

/* tOutPut */
typedef struct kcg_tag_tOutPut {
  kcg_bool SOV_Open;
  kcg_float32 BrakePressureCommand_L;
  kcg_float32 BrakePressureCommand_R;
  tBrakeAutoBKOut BrakeAutoBKOut;
  tBrakeIfbOut BrakeIfbOut;
  tBrakeInhibitOut BrakeInhibitOut;
  tBrakePdlOut BrakePdlOut;
  tBrakeSelectOut BrakeSelectOut;
  tBrakeSkidOut BrakeSkidOut;
  kcg_bool WOWBK;
  kcg_bool WOW429;
  tIOR_ProcessSpeedData speed;
} tOutPut;

/* tBRAKE_Auto */
typedef struct kcg_tag_tBRAKE_Auto {
  kcg_float32 AutoBrakeCommand_L;
  kcg_float32 AutoBrakeCommand_R;
  kcg_bool AutoBrakeEnable;
} tBRAKE_Auto;

typedef kcg_bool array_bool_3[3];

typedef kcg_float32 array_float32_5[5];

#ifndef kcg_copy_A429_Valid_short
#define kcg_copy_A429_Valid_short(kcg_C1, kcg_C2)                             \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (A429_Valid_short)))
#endif /* kcg_copy_A429_Valid_short */

#ifndef kcg_copy_tIOR_ProcessSpeedData
#define kcg_copy_tIOR_ProcessSpeedData(kcg_C1, kcg_C2)                        \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessSpeedData)))
#endif /* kcg_copy_tIOR_ProcessSpeedData */

#ifndef kcg_copy_tBCU_an
#define kcg_copy_tBCU_an(kcg_C1, kcg_C2)                                      \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBCU_an)))
#endif /* kcg_copy_tBCU_an */

#ifndef kcg_copy_tIOR_ProcessThrottleData
#define kcg_copy_tIOR_ProcessThrottleData(kcg_C1, kcg_C2)                     \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessThrottleData)))
#endif /* kcg_copy_tIOR_ProcessThrottleData */

#ifndef kcg_copy_tBrakeSelectOut
#define kcg_copy_tBrakeSelectOut(kcg_C1, kcg_C2)                              \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeSelectOut)))
#endif /* kcg_copy_tBrakeSelectOut */

#ifndef kcg_copy_tTestData
#define kcg_copy_tTestData(kcg_C1, kcg_C2)                                    \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tTestData)))
#endif /* kcg_copy_tTestData */

#ifndef kcg_copy_tBrakeSkidOut
#define kcg_copy_tBrakeSkidOut(kcg_C1, kcg_C2)                                \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeSkidOut)))
#endif /* kcg_copy_tBrakeSkidOut */

#ifndef kcg_copy_tBrakeAutoBKOut
#define kcg_copy_tBrakeAutoBKOut(kcg_C1, kcg_C2)                              \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeAutoBKOut)))
#endif /* kcg_copy_tBrakeAutoBKOut */

#ifndef kcg_copy_tData_to_DSP
#define kcg_copy_tData_to_DSP(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tData_to_DSP)))
#endif /* kcg_copy_tData_to_DSP */

#ifndef kcg_copy_tBrakePdlOut
#define kcg_copy_tBrakePdlOut(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakePdlOut)))
#endif /* kcg_copy_tBrakePdlOut */

#ifndef kcg_copy_tValidityF32
#define kcg_copy_tValidityF32(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tValidityF32)))
#endif /* kcg_copy_tValidityF32 */

#ifndef kcg_copy_tAutobrakeState
#define kcg_copy_tAutobrakeState(kcg_C1, kcg_C2)                              \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tAutobrakeState)))
#endif /* kcg_copy_tAutobrakeState */

#ifndef kcg_copy_tBrakeInhibits
#define kcg_copy_tBrakeInhibits(kcg_C1, kcg_C2)                               \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeInhibits)))
#endif /* kcg_copy_tBrakeInhibits */

#ifndef kcg_copy_tIOR_ProcessAutoFlightData
#define kcg_copy_tIOR_ProcessAutoFlightData(kcg_C1, kcg_C2)                   \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessAutoFlightData)))
#endif /* kcg_copy_tIOR_ProcessAutoFlightData */

#ifndef kcg_copy_tIOR_ProcessAutobrakeData
#define kcg_copy_tIOR_ProcessAutobrakeData(kcg_C1, kcg_C2)                    \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessAutobrakeData)))
#endif /* kcg_copy_tIOR_ProcessAutobrakeData */

#ifndef kcg_copy_tBrakeIfbOut
#define kcg_copy_tBrakeIfbOut(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeIfbOut)))
#endif /* kcg_copy_tBrakeIfbOut */

#ifndef kcg_copy_tValidityS32
#define kcg_copy_tValidityS32(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tValidityS32)))
#endif /* kcg_copy_tValidityS32 */

#ifndef kcg_copy_tINPUT_Data
#define kcg_copy_tINPUT_Data(kcg_C1, kcg_C2)                                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tINPUT_Data)))
#endif /* kcg_copy_tINPUT_Data */

#ifndef kcg_copy_tBrakeInhibitOut
#define kcg_copy_tBrakeInhibitOut(kcg_C1, kcg_C2)                             \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBrakeInhibitOut)))
#endif /* kcg_copy_tBrakeInhibitOut */

#ifndef kcg_copy_tIOR_ProcessLandingGearData
#define kcg_copy_tIOR_ProcessLandingGearData(kcg_C1, kcg_C2)                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessLandingGearData)))
#endif /* kcg_copy_tIOR_ProcessLandingGearData */

#ifndef kcg_copy_tValidityU32
#define kcg_copy_tValidityU32(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tValidityU32)))
#endif /* kcg_copy_tValidityU32 */

#ifndef kcg_copy_tValidityBool
#define kcg_copy_tValidityBool(kcg_C1, kcg_C2)                                \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tValidityBool)))
#endif /* kcg_copy_tValidityBool */

#ifndef kcg_copy_tBRAKE_Auto
#define kcg_copy_tBRAKE_Auto(kcg_C1, kcg_C2)                                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tBRAKE_Auto)))
#endif /* kcg_copy_tBRAKE_Auto */

#ifndef kcg_copy_tOutPut
#define kcg_copy_tOutPut(kcg_C1, kcg_C2)                                      \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tOutPut)))
#endif /* kcg_copy_tOutPut */

#ifndef kcg_copy_tIOR_ProcessAircraftData
#define kcg_copy_tIOR_ProcessAircraftData(kcg_C1, kcg_C2)                     \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessAircraftData)))
#endif /* kcg_copy_tIOR_ProcessAircraftData */

#ifndef kcg_copy_tIn_Discrete
#define kcg_copy_tIn_Discrete(kcg_C1, kcg_C2)                                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIn_Discrete)))
#endif /* kcg_copy_tIn_Discrete */

#ifndef kcg_copy_tIOR_ProcessHydraulicData
#define kcg_copy_tIOR_ProcessHydraulicData(kcg_C1, kcg_C2)                    \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessHydraulicData)))
#endif /* kcg_copy_tIOR_ProcessHydraulicData */

#ifndef kcg_copy_HcDiscreteWord
#define kcg_copy_HcDiscreteWord(kcg_C1, kcg_C2)                               \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (HcDiscreteWord)))
#endif /* kcg_copy_HcDiscreteWord */

#ifndef kcg_copy_tIOR_ProcessPedalData
#define kcg_copy_tIOR_ProcessPedalData(kcg_C1, kcg_C2)                        \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessPedalData)))
#endif /* kcg_copy_tIOR_ProcessPedalData */

#ifndef kcg_copy_tIOR_ProcessWowData
#define kcg_copy_tIOR_ProcessWowData(kcg_C1, kcg_C2)                          \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (tIOR_ProcessWowData)))
#endif /* kcg_copy_tIOR_ProcessWowData */

#ifndef kcg_copy_bool_word
#define kcg_copy_bool_word(kcg_C1, kcg_C2)                                    \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (bool_word)))
#endif /* kcg_copy_bool_word */

#ifndef kcg_copy_array_bool_3
#define kcg_copy_array_bool_3(kcg_C1, kcg_C2)                                 \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_bool_3)))
#endif /* kcg_copy_array_bool_3 */

#ifndef kcg_copy_bool_wordshort
#define kcg_copy_bool_wordshort(kcg_C1, kcg_C2)                               \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (bool_wordshort)))
#endif /* kcg_copy_bool_wordshort */

#ifndef kcg_copy_array_float32_5
#define kcg_copy_array_float32_5(kcg_C1, kcg_C2)                              \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_float32_5)))
#endif /* kcg_copy_array_float32_5 */

#ifdef kcg_use_A429_Valid_short
#ifndef kcg_comp_A429_Valid_short
extern kcg_bool kcg_comp_A429_Valid_short(
  A429_Valid_short *kcg_c1,
  A429_Valid_short *kcg_c2);
#endif /* kcg_comp_A429_Valid_short */
#endif /* kcg_use_A429_Valid_short */

#ifdef kcg_use_tIOR_ProcessSpeedData
#ifndef kcg_comp_tIOR_ProcessSpeedData
extern kcg_bool kcg_comp_tIOR_ProcessSpeedData(
  tIOR_ProcessSpeedData *kcg_c1,
  tIOR_ProcessSpeedData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessSpeedData */
#endif /* kcg_use_tIOR_ProcessSpeedData */

#ifdef kcg_use_tBCU_an
#ifndef kcg_comp_tBCU_an
extern kcg_bool kcg_comp_tBCU_an(tBCU_an *kcg_c1, tBCU_an *kcg_c2);
#endif /* kcg_comp_tBCU_an */
#endif /* kcg_use_tBCU_an */

#ifdef kcg_use_tIOR_ProcessThrottleData
#ifndef kcg_comp_tIOR_ProcessThrottleData
extern kcg_bool kcg_comp_tIOR_ProcessThrottleData(
  tIOR_ProcessThrottleData *kcg_c1,
  tIOR_ProcessThrottleData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessThrottleData */
#endif /* kcg_use_tIOR_ProcessThrottleData */

#ifdef kcg_use_tBrakeSelectOut
#ifndef kcg_comp_tBrakeSelectOut
extern kcg_bool kcg_comp_tBrakeSelectOut(
  tBrakeSelectOut *kcg_c1,
  tBrakeSelectOut *kcg_c2);
#endif /* kcg_comp_tBrakeSelectOut */
#endif /* kcg_use_tBrakeSelectOut */

#ifdef kcg_use_tTestData
#ifndef kcg_comp_tTestData
extern kcg_bool kcg_comp_tTestData(tTestData *kcg_c1, tTestData *kcg_c2);
#endif /* kcg_comp_tTestData */
#endif /* kcg_use_tTestData */

#ifdef kcg_use_tBrakeSkidOut
#ifndef kcg_comp_tBrakeSkidOut
extern kcg_bool kcg_comp_tBrakeSkidOut(
  tBrakeSkidOut *kcg_c1,
  tBrakeSkidOut *kcg_c2);
#endif /* kcg_comp_tBrakeSkidOut */
#endif /* kcg_use_tBrakeSkidOut */

#ifdef kcg_use_tBrakeAutoBKOut
#ifndef kcg_comp_tBrakeAutoBKOut
extern kcg_bool kcg_comp_tBrakeAutoBKOut(
  tBrakeAutoBKOut *kcg_c1,
  tBrakeAutoBKOut *kcg_c2);
#endif /* kcg_comp_tBrakeAutoBKOut */
#endif /* kcg_use_tBrakeAutoBKOut */

#ifdef kcg_use_tData_to_DSP
#ifndef kcg_comp_tData_to_DSP
extern kcg_bool kcg_comp_tData_to_DSP(
  tData_to_DSP *kcg_c1,
  tData_to_DSP *kcg_c2);
#endif /* kcg_comp_tData_to_DSP */
#endif /* kcg_use_tData_to_DSP */

#ifdef kcg_use_tBrakePdlOut
#ifndef kcg_comp_tBrakePdlOut
extern kcg_bool kcg_comp_tBrakePdlOut(
  tBrakePdlOut *kcg_c1,
  tBrakePdlOut *kcg_c2);
#endif /* kcg_comp_tBrakePdlOut */
#endif /* kcg_use_tBrakePdlOut */

#ifdef kcg_use_tValidityF32
#ifndef kcg_comp_tValidityF32
extern kcg_bool kcg_comp_tValidityF32(
  tValidityF32 *kcg_c1,
  tValidityF32 *kcg_c2);
#endif /* kcg_comp_tValidityF32 */
#endif /* kcg_use_tValidityF32 */

#ifdef kcg_use_tAutobrakeState
#ifndef kcg_comp_tAutobrakeState
extern kcg_bool kcg_comp_tAutobrakeState(
  tAutobrakeState *kcg_c1,
  tAutobrakeState *kcg_c2);
#endif /* kcg_comp_tAutobrakeState */
#endif /* kcg_use_tAutobrakeState */

#ifdef kcg_use_tBrakeInhibits
#ifndef kcg_comp_tBrakeInhibits
extern kcg_bool kcg_comp_tBrakeInhibits(
  tBrakeInhibits *kcg_c1,
  tBrakeInhibits *kcg_c2);
#endif /* kcg_comp_tBrakeInhibits */
#endif /* kcg_use_tBrakeInhibits */

#ifdef kcg_use_tIOR_ProcessAutoFlightData
#ifndef kcg_comp_tIOR_ProcessAutoFlightData
extern kcg_bool kcg_comp_tIOR_ProcessAutoFlightData(
  tIOR_ProcessAutoFlightData *kcg_c1,
  tIOR_ProcessAutoFlightData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessAutoFlightData */
#endif /* kcg_use_tIOR_ProcessAutoFlightData */

#ifdef kcg_use_tIOR_ProcessAutobrakeData
#ifndef kcg_comp_tIOR_ProcessAutobrakeData
extern kcg_bool kcg_comp_tIOR_ProcessAutobrakeData(
  tIOR_ProcessAutobrakeData *kcg_c1,
  tIOR_ProcessAutobrakeData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessAutobrakeData */
#endif /* kcg_use_tIOR_ProcessAutobrakeData */

#ifdef kcg_use_tBrakeIfbOut
#ifndef kcg_comp_tBrakeIfbOut
extern kcg_bool kcg_comp_tBrakeIfbOut(
  tBrakeIfbOut *kcg_c1,
  tBrakeIfbOut *kcg_c2);
#endif /* kcg_comp_tBrakeIfbOut */
#endif /* kcg_use_tBrakeIfbOut */

#ifdef kcg_use_tValidityS32
#ifndef kcg_comp_tValidityS32
extern kcg_bool kcg_comp_tValidityS32(
  tValidityS32 *kcg_c1,
  tValidityS32 *kcg_c2);
#endif /* kcg_comp_tValidityS32 */
#endif /* kcg_use_tValidityS32 */

#ifdef kcg_use_tINPUT_Data
#ifndef kcg_comp_tINPUT_Data
extern kcg_bool kcg_comp_tINPUT_Data(tINPUT_Data *kcg_c1, tINPUT_Data *kcg_c2);
#endif /* kcg_comp_tINPUT_Data */
#endif /* kcg_use_tINPUT_Data */

#ifdef kcg_use_tBrakeInhibitOut
#ifndef kcg_comp_tBrakeInhibitOut
extern kcg_bool kcg_comp_tBrakeInhibitOut(
  tBrakeInhibitOut *kcg_c1,
  tBrakeInhibitOut *kcg_c2);
#endif /* kcg_comp_tBrakeInhibitOut */
#endif /* kcg_use_tBrakeInhibitOut */

#ifdef kcg_use_tIOR_ProcessLandingGearData
#ifndef kcg_comp_tIOR_ProcessLandingGearData
extern kcg_bool kcg_comp_tIOR_ProcessLandingGearData(
  tIOR_ProcessLandingGearData *kcg_c1,
  tIOR_ProcessLandingGearData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessLandingGearData */
#endif /* kcg_use_tIOR_ProcessLandingGearData */

#ifdef kcg_use_tValidityU32
#ifndef kcg_comp_tValidityU32
extern kcg_bool kcg_comp_tValidityU32(
  tValidityU32 *kcg_c1,
  tValidityU32 *kcg_c2);
#endif /* kcg_comp_tValidityU32 */
#endif /* kcg_use_tValidityU32 */

#ifdef kcg_use_tValidityBool
#ifndef kcg_comp_tValidityBool
extern kcg_bool kcg_comp_tValidityBool(
  tValidityBool *kcg_c1,
  tValidityBool *kcg_c2);
#endif /* kcg_comp_tValidityBool */
#endif /* kcg_use_tValidityBool */

#ifdef kcg_use_tBRAKE_Auto
#ifndef kcg_comp_tBRAKE_Auto
extern kcg_bool kcg_comp_tBRAKE_Auto(tBRAKE_Auto *kcg_c1, tBRAKE_Auto *kcg_c2);
#endif /* kcg_comp_tBRAKE_Auto */
#endif /* kcg_use_tBRAKE_Auto */

#ifdef kcg_use_tOutPut
#ifndef kcg_comp_tOutPut
extern kcg_bool kcg_comp_tOutPut(tOutPut *kcg_c1, tOutPut *kcg_c2);
#endif /* kcg_comp_tOutPut */
#endif /* kcg_use_tOutPut */

#ifdef kcg_use_tIOR_ProcessAircraftData
#ifndef kcg_comp_tIOR_ProcessAircraftData
extern kcg_bool kcg_comp_tIOR_ProcessAircraftData(
  tIOR_ProcessAircraftData *kcg_c1,
  tIOR_ProcessAircraftData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessAircraftData */
#endif /* kcg_use_tIOR_ProcessAircraftData */

#ifdef kcg_use_tIn_Discrete
#ifndef kcg_comp_tIn_Discrete
extern kcg_bool kcg_comp_tIn_Discrete(
  tIn_Discrete *kcg_c1,
  tIn_Discrete *kcg_c2);
#endif /* kcg_comp_tIn_Discrete */
#endif /* kcg_use_tIn_Discrete */

#ifdef kcg_use_tIOR_ProcessHydraulicData
#ifndef kcg_comp_tIOR_ProcessHydraulicData
extern kcg_bool kcg_comp_tIOR_ProcessHydraulicData(
  tIOR_ProcessHydraulicData *kcg_c1,
  tIOR_ProcessHydraulicData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessHydraulicData */
#endif /* kcg_use_tIOR_ProcessHydraulicData */

#ifdef kcg_use_HcDiscreteWord
#ifndef kcg_comp_HcDiscreteWord
extern kcg_bool kcg_comp_HcDiscreteWord(
  HcDiscreteWord *kcg_c1,
  HcDiscreteWord *kcg_c2);
#endif /* kcg_comp_HcDiscreteWord */
#endif /* kcg_use_HcDiscreteWord */

#ifdef kcg_use_tIOR_ProcessPedalData
#ifndef kcg_comp_tIOR_ProcessPedalData
extern kcg_bool kcg_comp_tIOR_ProcessPedalData(
  tIOR_ProcessPedalData *kcg_c1,
  tIOR_ProcessPedalData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessPedalData */
#endif /* kcg_use_tIOR_ProcessPedalData */

#ifdef kcg_use_tIOR_ProcessWowData
#ifndef kcg_comp_tIOR_ProcessWowData
extern kcg_bool kcg_comp_tIOR_ProcessWowData(
  tIOR_ProcessWowData *kcg_c1,
  tIOR_ProcessWowData *kcg_c2);
#endif /* kcg_comp_tIOR_ProcessWowData */
#endif /* kcg_use_tIOR_ProcessWowData */

#ifdef kcg_use_bool_word
#ifndef kcg_comp_bool_word
extern kcg_bool kcg_comp_bool_word(bool_word *kcg_c1, bool_word *kcg_c2);
#endif /* kcg_comp_bool_word */
#endif /* kcg_use_bool_word */

#ifdef kcg_use_array_bool_3
#ifndef kcg_comp_array_bool_3
extern kcg_bool kcg_comp_array_bool_3(
  array_bool_3 *kcg_c1,
  array_bool_3 *kcg_c2);
#endif /* kcg_comp_array_bool_3 */
#endif /* kcg_use_array_bool_3 */

#ifdef kcg_use_bool_wordshort
#ifndef kcg_comp_bool_wordshort
extern kcg_bool kcg_comp_bool_wordshort(
  bool_wordshort *kcg_c1,
  bool_wordshort *kcg_c2);
#endif /* kcg_comp_bool_wordshort */
#endif /* kcg_use_bool_wordshort */

#ifdef kcg_use_array_float32_5
#ifndef kcg_comp_array_float32_5
extern kcg_bool kcg_comp_array_float32_5(
  array_float32_5 *kcg_c1,
  array_float32_5 *kcg_c2);
#endif /* kcg_comp_array_float32_5 */
#endif /* kcg_use_array_float32_5 */

#endif /* _KCG_TYPES_H_ */
/* $********** SCADE Suite KCG 64-bit 6.5 (build i12) ***********
** kcg_types.h
** Generation date: 2022-08-11T09:49:10
*************************************************************$ */

