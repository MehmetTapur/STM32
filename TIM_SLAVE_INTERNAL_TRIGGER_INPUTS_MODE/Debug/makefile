################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.list \

OBJCOPY_BIN += \
TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.bin \


# All Target
all: main-build

# Main-build Target
main-build: TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.elf secondary-outputs

# Tool invocations
TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.elf: $(OBJS) $(USER_OBJS) D:\workspace_1.7.0\TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\workspace_1.7.0\TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.list"
	@echo 'Finished building: $@'
	@echo ' '

TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SIZE_OUTPUT)$(OBJDUMP_LIST)$(EXECUTABLES)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(OBJCOPY_BIN) TIM_SLAVE_INTERNAL_TRIGGER_INPUTS_MODE.elf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
