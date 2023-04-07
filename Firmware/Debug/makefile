################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Drivers/HAL/subdir.mk
-include Drivers/BSP/Components/hts221/subdir.mk
-include Drivers/BSP/B-L475E-IOT01/subdir.mk
-include Application/WIFI/subdir.mk
-include Application/User/subdir.mk
-include Application/Core/subdir.mk
-include Application/App/subdir.mk
-include Application/subdir.mk
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


BUILD_ARTIFACT_NAME := Iot-Weather-Monitoring_System
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Iot-Weather-Monitoring_System.elf \

MAP_FILES += \
Iot-Weather-Monitoring_System.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Iot-Weather-Monitoring_System.list \


# All Target
all: main-build

# Main-build Target
main-build: Iot-Weather-Monitoring_System.elf secondary-outputs

# Tool invocations
Iot-Weather-Monitoring_System.elf Iot-Weather-Monitoring_System.map: $(OBJS) $(USER_OBJS) C:\Darmor\School\Network\ Enabled\ Hardware\IoT-Weather-Monitoring-System\Firmware\Linker\STM32L475VGTx_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Iot-Weather-Monitoring_System.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Darmor\School\Network Enabled Hardware\IoT-Weather-Monitoring-System\Firmware\Linker\STM32L475VGTx_FLASH.ld" --specs=nosys.specs -Wl,-Map="Iot-Weather-Monitoring_System.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Iot-Weather-Monitoring_System.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Iot-Weather-Monitoring_System.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Iot-Weather-Monitoring_System.elf Iot-Weather-Monitoring_System.list Iot-Weather-Monitoring_System.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
