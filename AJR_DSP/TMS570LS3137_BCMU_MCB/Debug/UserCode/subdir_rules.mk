################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
UserCode/%.obj: ../UserCode/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/KCG" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/SdCard" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/UserCode" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/hal" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/hal/include" --include_path="C:/Users/15755/Desktop/AJR_DSP/TMS570LS3137_BCMU_MCB/hal/source" --include_path="C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="UserCode/$(basename $(<F)).d_raw" --obj_directory="UserCode" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


