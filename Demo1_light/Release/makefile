################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include _config/subdir.mk
-include subdir.mk
-include objects.mk

-include $(C_DEPS)

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJCOPY_TARGET += \
Demo1_light.s19 \

OBJDUMP_LIST += \
Demo1_light.lst \


LD_SRCS =D:/KungFu32_/ChipONCC32/ccr1_issue/scripting/KF32A156MQV.ld

EXECUTABLES	= Demo1_light.elf
# 所有目标
all: Demo1_light.elf secondary-outputs

# 工具调用
Demo1_light.elf: $(OBJS) $(USER_RELS) $(LD_SRCS)
	@echo 'Building target: $@'
#	@echo 'Invoking: ChipON Linker'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"D:/KungFu32_/ChipONCC32/ccr1_issue/lib" -L"D:\KungFu32\workspace32\Demo1_light" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv2 -T"D:/KungFu32_/ChipONCC32/ccr1_issue/scripting/KF32A156MQV.ld" --kf32-autoihex --kf32-arch=kf32r --kf32-nodisassemble --with-checksum-fill=0xFF --gc-sections -o  "Demo1_light.elf" -Map "Demo1_light.map"
	@echo 'Finished building target: $@'
#	@echo ' '

Demo1_light.s19: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjCopy'
	@kf32-objcopy -O srec "Demo1_light.elf"   "Demo1_light.s19"
	@echo 'Finished building: $@'
#	@echo ' '

Demo1_light.lst: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjDump'
	@kf32-objdump -S -l --section=.text --section=.data --section=.bss --kf32-arch=kf32r "Demo1_light.elf"   > "Demo1_light.lst"
	@echo 'Finished building: $@'
#	@echo ' '

# 其他目标
clean:
	-$(RM)  $(OBJS) $(EXECUTABLES) $(C_DEPS) Demo1_light.elf '$(basename $(OBJDUMP_LIST)).lst' '$(basename $(OBJCOPY_TARGET)).hex'   '$(basename $(OBJCOPY_TARGET)).bin'  '$(basename $(OBJCOPY_TARGET)).s19' '$(basename $(OBJCOPY_TARGET)).map'
#	-@echo ' '

secondary-outputs: Demo1_light.lst Demo1_light.s19

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
