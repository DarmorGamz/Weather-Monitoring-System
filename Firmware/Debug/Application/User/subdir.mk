################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/driver_init.c \
../Application/User/stm_start.c 

OBJS += \
./Application/User/driver_init.o \
./Application/User/stm_start.o 

C_DEPS += \
./Application/User/driver_init.d \
./Application/User/stm_start.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Device" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/driver_init.cyclo ./Application/User/driver_init.d ./Application/User/driver_init.o ./Application/User/driver_init.su ./Application/User/stm_start.cyclo ./Application/User/stm_start.d ./Application/User/stm_start.o ./Application/User/stm_start.su

.PHONY: clean-Application-2f-User

