################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/main.c \
../Application/stm32l4xx_it.c \
../Application/syscalls.c \
../Application/system_stm32l4xx.c 

OBJS += \
./Application/main.o \
./Application/stm32l4xx_it.o \
./Application/syscalls.o \
./Application/system_stm32l4xx.o 

C_DEPS += \
./Application/main.d \
./Application/stm32l4xx_it.d \
./Application/syscalls.d \
./Application/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Device" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/main.cyclo ./Application/main.d ./Application/main.o ./Application/main.su ./Application/stm32l4xx_it.cyclo ./Application/stm32l4xx_it.d ./Application/stm32l4xx_it.o ./Application/stm32l4xx_it.su ./Application/syscalls.cyclo ./Application/syscalls.d ./Application/syscalls.o ./Application/syscalls.su ./Application/system_stm32l4xx.cyclo ./Application/system_stm32l4xx.d ./Application/system_stm32l4xx.o ./Application/system_stm32l4xx.su

.PHONY: clean-Application

