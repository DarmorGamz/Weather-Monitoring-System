################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Core/DataQueue.c \
../Application/Core/Debug.c \
../Application/Core/Flash.c \
../Application/Core/HumiditySensor.c \
../Application/Core/TempSensor.c \
../Application/Core/Timer.c \
../Application/Core/Timestamp.c \
../Application/Core/Watchdog.c \
../Application/Core/WifiNew.c 

OBJS += \
./Application/Core/DataQueue.o \
./Application/Core/Debug.o \
./Application/Core/Flash.o \
./Application/Core/HumiditySensor.o \
./Application/Core/TempSensor.o \
./Application/Core/Timer.o \
./Application/Core/Timestamp.o \
./Application/Core/Watchdog.o \
./Application/Core/WifiNew.o 

C_DEPS += \
./Application/Core/DataQueue.d \
./Application/Core/Debug.d \
./Application/Core/Flash.d \
./Application/Core/HumiditySensor.d \
./Application/Core/TempSensor.d \
./Application/Core/Timer.d \
./Application/Core/Timestamp.d \
./Application/Core/Watchdog.d \
./Application/Core/WifiNew.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Core/%.o Application/Core/%.su Application/Core/%.cyclo: ../Application/Core/%.c Application/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Device" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Core

clean-Application-2f-Core:
	-$(RM) ./Application/Core/DataQueue.cyclo ./Application/Core/DataQueue.d ./Application/Core/DataQueue.o ./Application/Core/DataQueue.su ./Application/Core/Debug.cyclo ./Application/Core/Debug.d ./Application/Core/Debug.o ./Application/Core/Debug.su ./Application/Core/Flash.cyclo ./Application/Core/Flash.d ./Application/Core/Flash.o ./Application/Core/Flash.su ./Application/Core/HumiditySensor.cyclo ./Application/Core/HumiditySensor.d ./Application/Core/HumiditySensor.o ./Application/Core/HumiditySensor.su ./Application/Core/TempSensor.cyclo ./Application/Core/TempSensor.d ./Application/Core/TempSensor.o ./Application/Core/TempSensor.su ./Application/Core/Timer.cyclo ./Application/Core/Timer.d ./Application/Core/Timer.o ./Application/Core/Timer.su ./Application/Core/Timestamp.cyclo ./Application/Core/Timestamp.d ./Application/Core/Timestamp.o ./Application/Core/Timestamp.su ./Application/Core/Watchdog.cyclo ./Application/Core/Watchdog.d ./Application/Core/Watchdog.o ./Application/Core/Watchdog.su ./Application/Core/WifiNew.cyclo ./Application/Core/WifiNew.d ./Application/Core/WifiNew.o ./Application/Core/WifiNew.su

.PHONY: clean-Application-2f-Core

