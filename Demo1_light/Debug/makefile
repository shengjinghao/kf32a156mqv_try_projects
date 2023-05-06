################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include _config/subdir.mk
-include subdir.mk
-include objects.mk

-include $(C_DEPS)

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJCOPY_TARGET += \
Demo1.s19 \

OBJDUMP_LIST += \
Demo1.lst \


LD_SRCS =D:/KungFu32_/ChipONCC32/ccr1_issue/scripting/KF32A156MQV.ld

EXECUTABLES	= Demo1.elf
# 所有目标
all: Demo1.elf secondary-outputs

# 工具调用
Demo1.elf: $(OBJS) $(USER_RELS) $(LD_SRCS)
	@echo 'Building target: $@'
#	@echo 'Invoking: ChipON Linker'
	@kf32-ld $(OBJS) $(USER_RELS) $(LIBS) -L"D:/KungFu32_/ChipONCC32/ccr1_issue/lib" -L"D:\KungFu32\workspace32\Demo1" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv2 -T"D:/KungFu32_/ChipONCC32/ccr1_issue/scripting/KF32A156MQV.ld" --kf32-autoihex --kf32-arch=kf32r --kf32-nodisassemble --with-checksum-fill=0xFF --gc-sections -o  "Demo1.elf" -Map "Demo1.map"
	@echo 'Finished building target: $@'
#	@echo ' '

Demo1.s19: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjCopy'
	@kf32-objcopy -O srec "Demo1.elf"   "Demo1.s19"
	@echo 'Finished building: $@'
#	@echo ' '

Demo1.lst: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjDump'
	@kf32-objdump -S -l --section=.text --section=.data --section=.bss --kf32-arch=kf32r "Demo1.elf"   > "Demo1.lst"
	@echo 'Finished building: $@'
#	@echo ' '

# 其他目标
clean:
	-$(RM)  $(OBJS) $(EXECUTABLES) $(C_DEPS) Demo1.elf '$(basename $(OBJDUMP_LIST)).lst' '$(basename $(OBJCOPY_TARGET)).hex'   '$(basename $(OBJCOPY_TARGET)).bin'  '$(basename $(OBJCOPY_TARGET)).s19' '$(basename $(OBJCOPY_TARGET)).map'
#	-@echo ' '

secondary-outputs: Demo1.lst Demo1.s19

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
