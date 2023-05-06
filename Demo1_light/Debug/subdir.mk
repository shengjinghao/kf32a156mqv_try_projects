################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kf_it.c \
../main.c 

OBJS += \
./kf_it.o \
./main.o 

C_DEPS += \
./kf_it.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: ChipON C Compiler'
	@mkdir -p "_static_code_analysis"
	@kf32-gcc  -MMD -I"D:\KungFu32\workspace32\Demo1" -I"D:/KungFu32_/ChipONCC32/include" -I"D:/KungFu32_/ChipONCC32/include/Sys" -save-temps -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -c -funsigned-char -fsigned-bitfields -Wa,--kf32-arch=kf32r,-I"D:/KungFu32_/ChipONCC32/include" -ffunction-sections -fdata-sections -D"KF32A156MQV" -D"__DEBUG__" -Wno-packed-bitfield-compat -std=gnu99 -gstabs+ -O0 $< -o "$@"
	@echo 'Finished building: $<'

