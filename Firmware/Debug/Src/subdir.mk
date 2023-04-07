################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32l4xx_it.c \
../Src/system_stm32l4xx.c 

OBJS += \
./Src/main.o \
./Src/stm32l4xx_it.o \
./Src/system_stm32l4xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32l4xx_it.d \
./Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/STM32L4xx_HAL_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32l4xx_it.cyclo ./Src/stm32l4xx_it.d ./Src/stm32l4xx_it.o ./Src/stm32l4xx_it.su ./Src/system_stm32l4xx.cyclo ./Src/system_stm32l4xx.d ./Src/system_stm32l4xx.o ./Src/system_stm32l4xx.su

.PHONY: clean-Src

