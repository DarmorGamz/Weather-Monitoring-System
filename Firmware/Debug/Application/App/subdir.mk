################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/App/AplusAPP.c 

OBJS += \
./Application/App/AplusAPP.o 

C_DEPS += \
./Application/App/AplusAPP.d 


# Each subdirectory must supply rules for building sources it contributes
Application/App/%.o Application/App/%.su Application/App/%.cyclo: ../Application/App/%.c Application/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Device" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-App

clean-Application-2f-App:
	-$(RM) ./Application/App/AplusAPP.cyclo ./Application/App/AplusAPP.d ./Application/App/AplusAPP.o ./Application/App/AplusAPP.su

.PHONY: clean-Application-2f-App

