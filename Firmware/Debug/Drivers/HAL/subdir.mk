################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/stm32l4xx_hal.c \
../Drivers/HAL/stm32l4xx_hal_cortex.c \
../Drivers/HAL/stm32l4xx_hal_dma.c \
../Drivers/HAL/stm32l4xx_hal_flash.c \
../Drivers/HAL/stm32l4xx_hal_flash_ex.c \
../Drivers/HAL/stm32l4xx_hal_gpio.c \
../Drivers/HAL/stm32l4xx_hal_i2c.c \
../Drivers/HAL/stm32l4xx_hal_i2c_ex.c \
../Drivers/HAL/stm32l4xx_hal_iwdg.c \
../Drivers/HAL/stm32l4xx_hal_pwr.c \
../Drivers/HAL/stm32l4xx_hal_pwr_ex.c \
../Drivers/HAL/stm32l4xx_hal_rcc.c \
../Drivers/HAL/stm32l4xx_hal_rcc_ex.c \
../Drivers/HAL/stm32l4xx_hal_rtc.c \
../Drivers/HAL/stm32l4xx_hal_rtc_ex.c \
../Drivers/HAL/stm32l4xx_hal_spi.c \
../Drivers/HAL/stm32l4xx_hal_spi_ex.c \
../Drivers/HAL/stm32l4xx_hal_sram.c \
../Drivers/HAL/stm32l4xx_hal_swpmi.c \
../Drivers/HAL/stm32l4xx_hal_tim.c \
../Drivers/HAL/stm32l4xx_hal_tim_ex.c \
../Drivers/HAL/stm32l4xx_hal_tsc.c \
../Drivers/HAL/stm32l4xx_hal_uart.c \
../Drivers/HAL/stm32l4xx_hal_uart_ex.c \
../Drivers/HAL/stm32l4xx_hal_wwdg.c 

OBJS += \
./Drivers/HAL/stm32l4xx_hal.o \
./Drivers/HAL/stm32l4xx_hal_cortex.o \
./Drivers/HAL/stm32l4xx_hal_dma.o \
./Drivers/HAL/stm32l4xx_hal_flash.o \
./Drivers/HAL/stm32l4xx_hal_flash_ex.o \
./Drivers/HAL/stm32l4xx_hal_gpio.o \
./Drivers/HAL/stm32l4xx_hal_i2c.o \
./Drivers/HAL/stm32l4xx_hal_i2c_ex.o \
./Drivers/HAL/stm32l4xx_hal_iwdg.o \
./Drivers/HAL/stm32l4xx_hal_pwr.o \
./Drivers/HAL/stm32l4xx_hal_pwr_ex.o \
./Drivers/HAL/stm32l4xx_hal_rcc.o \
./Drivers/HAL/stm32l4xx_hal_rcc_ex.o \
./Drivers/HAL/stm32l4xx_hal_rtc.o \
./Drivers/HAL/stm32l4xx_hal_rtc_ex.o \
./Drivers/HAL/stm32l4xx_hal_spi.o \
./Drivers/HAL/stm32l4xx_hal_spi_ex.o \
./Drivers/HAL/stm32l4xx_hal_sram.o \
./Drivers/HAL/stm32l4xx_hal_swpmi.o \
./Drivers/HAL/stm32l4xx_hal_tim.o \
./Drivers/HAL/stm32l4xx_hal_tim_ex.o \
./Drivers/HAL/stm32l4xx_hal_tsc.o \
./Drivers/HAL/stm32l4xx_hal_uart.o \
./Drivers/HAL/stm32l4xx_hal_uart_ex.o \
./Drivers/HAL/stm32l4xx_hal_wwdg.o 

C_DEPS += \
./Drivers/HAL/stm32l4xx_hal.d \
./Drivers/HAL/stm32l4xx_hal_cortex.d \
./Drivers/HAL/stm32l4xx_hal_dma.d \
./Drivers/HAL/stm32l4xx_hal_flash.d \
./Drivers/HAL/stm32l4xx_hal_flash_ex.d \
./Drivers/HAL/stm32l4xx_hal_gpio.d \
./Drivers/HAL/stm32l4xx_hal_i2c.d \
./Drivers/HAL/stm32l4xx_hal_i2c_ex.d \
./Drivers/HAL/stm32l4xx_hal_iwdg.d \
./Drivers/HAL/stm32l4xx_hal_pwr.d \
./Drivers/HAL/stm32l4xx_hal_pwr_ex.d \
./Drivers/HAL/stm32l4xx_hal_rcc.d \
./Drivers/HAL/stm32l4xx_hal_rcc_ex.d \
./Drivers/HAL/stm32l4xx_hal_rtc.d \
./Drivers/HAL/stm32l4xx_hal_rtc_ex.d \
./Drivers/HAL/stm32l4xx_hal_spi.d \
./Drivers/HAL/stm32l4xx_hal_spi_ex.d \
./Drivers/HAL/stm32l4xx_hal_sram.d \
./Drivers/HAL/stm32l4xx_hal_swpmi.d \
./Drivers/HAL/stm32l4xx_hal_tim.d \
./Drivers/HAL/stm32l4xx_hal_tim_ex.d \
./Drivers/HAL/stm32l4xx_hal_tsc.d \
./Drivers/HAL/stm32l4xx_hal_uart.d \
./Drivers/HAL/stm32l4xx_hal_uart_ex.d \
./Drivers/HAL/stm32l4xx_hal_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/%.o Drivers/HAL/%.su Drivers/HAL/%.cyclo: ../Drivers/HAL/%.c Drivers/HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Inc" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS/Device" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/App" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/Core" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/User" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Application/WIFI" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/B-L475E-IOT01" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/Common" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/BSP/Components/hts221" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/CMSIS" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL" -I"C:/Darmor/School/Network Enabled Hardware/IoT-Weather-Monitoring-System/Firmware/Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-HAL

clean-Drivers-2f-HAL:
	-$(RM) ./Drivers/HAL/stm32l4xx_hal.cyclo ./Drivers/HAL/stm32l4xx_hal.d ./Drivers/HAL/stm32l4xx_hal.o ./Drivers/HAL/stm32l4xx_hal.su ./Drivers/HAL/stm32l4xx_hal_cortex.cyclo ./Drivers/HAL/stm32l4xx_hal_cortex.d ./Drivers/HAL/stm32l4xx_hal_cortex.o ./Drivers/HAL/stm32l4xx_hal_cortex.su ./Drivers/HAL/stm32l4xx_hal_dma.cyclo ./Drivers/HAL/stm32l4xx_hal_dma.d ./Drivers/HAL/stm32l4xx_hal_dma.o ./Drivers/HAL/stm32l4xx_hal_dma.su ./Drivers/HAL/stm32l4xx_hal_flash.cyclo ./Drivers/HAL/stm32l4xx_hal_flash.d ./Drivers/HAL/stm32l4xx_hal_flash.o ./Drivers/HAL/stm32l4xx_hal_flash.su ./Drivers/HAL/stm32l4xx_hal_flash_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_flash_ex.d ./Drivers/HAL/stm32l4xx_hal_flash_ex.o ./Drivers/HAL/stm32l4xx_hal_flash_ex.su ./Drivers/HAL/stm32l4xx_hal_gpio.cyclo ./Drivers/HAL/stm32l4xx_hal_gpio.d ./Drivers/HAL/stm32l4xx_hal_gpio.o ./Drivers/HAL/stm32l4xx_hal_gpio.su ./Drivers/HAL/stm32l4xx_hal_i2c.cyclo ./Drivers/HAL/stm32l4xx_hal_i2c.d ./Drivers/HAL/stm32l4xx_hal_i2c.o ./Drivers/HAL/stm32l4xx_hal_i2c.su ./Drivers/HAL/stm32l4xx_hal_i2c_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_i2c_ex.d ./Drivers/HAL/stm32l4xx_hal_i2c_ex.o ./Drivers/HAL/stm32l4xx_hal_i2c_ex.su ./Drivers/HAL/stm32l4xx_hal_iwdg.cyclo ./Drivers/HAL/stm32l4xx_hal_iwdg.d ./Drivers/HAL/stm32l4xx_hal_iwdg.o ./Drivers/HAL/stm32l4xx_hal_iwdg.su ./Drivers/HAL/stm32l4xx_hal_pwr.cyclo ./Drivers/HAL/stm32l4xx_hal_pwr.d ./Drivers/HAL/stm32l4xx_hal_pwr.o ./Drivers/HAL/stm32l4xx_hal_pwr.su ./Drivers/HAL/stm32l4xx_hal_pwr_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_pwr_ex.d ./Drivers/HAL/stm32l4xx_hal_pwr_ex.o ./Drivers/HAL/stm32l4xx_hal_pwr_ex.su ./Drivers/HAL/stm32l4xx_hal_rcc.cyclo ./Drivers/HAL/stm32l4xx_hal_rcc.d ./Drivers/HAL/stm32l4xx_hal_rcc.o ./Drivers/HAL/stm32l4xx_hal_rcc.su ./Drivers/HAL/stm32l4xx_hal_rcc_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_rcc_ex.d ./Drivers/HAL/stm32l4xx_hal_rcc_ex.o ./Drivers/HAL/stm32l4xx_hal_rcc_ex.su ./Drivers/HAL/stm32l4xx_hal_rtc.cyclo ./Drivers/HAL/stm32l4xx_hal_rtc.d ./Drivers/HAL/stm32l4xx_hal_rtc.o ./Drivers/HAL/stm32l4xx_hal_rtc.su ./Drivers/HAL/stm32l4xx_hal_rtc_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_rtc_ex.d ./Drivers/HAL/stm32l4xx_hal_rtc_ex.o ./Drivers/HAL/stm32l4xx_hal_rtc_ex.su ./Drivers/HAL/stm32l4xx_hal_spi.cyclo ./Drivers/HAL/stm32l4xx_hal_spi.d ./Drivers/HAL/stm32l4xx_hal_spi.o ./Drivers/HAL/stm32l4xx_hal_spi.su ./Drivers/HAL/stm32l4xx_hal_spi_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_spi_ex.d ./Drivers/HAL/stm32l4xx_hal_spi_ex.o ./Drivers/HAL/stm32l4xx_hal_spi_ex.su ./Drivers/HAL/stm32l4xx_hal_sram.cyclo ./Drivers/HAL/stm32l4xx_hal_sram.d ./Drivers/HAL/stm32l4xx_hal_sram.o ./Drivers/HAL/stm32l4xx_hal_sram.su ./Drivers/HAL/stm32l4xx_hal_swpmi.cyclo ./Drivers/HAL/stm32l4xx_hal_swpmi.d ./Drivers/HAL/stm32l4xx_hal_swpmi.o ./Drivers/HAL/stm32l4xx_hal_swpmi.su ./Drivers/HAL/stm32l4xx_hal_tim.cyclo ./Drivers/HAL/stm32l4xx_hal_tim.d ./Drivers/HAL/stm32l4xx_hal_tim.o ./Drivers/HAL/stm32l4xx_hal_tim.su ./Drivers/HAL/stm32l4xx_hal_tim_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_tim_ex.d ./Drivers/HAL/stm32l4xx_hal_tim_ex.o ./Drivers/HAL/stm32l4xx_hal_tim_ex.su ./Drivers/HAL/stm32l4xx_hal_tsc.cyclo ./Drivers/HAL/stm32l4xx_hal_tsc.d ./Drivers/HAL/stm32l4xx_hal_tsc.o ./Drivers/HAL/stm32l4xx_hal_tsc.su ./Drivers/HAL/stm32l4xx_hal_uart.cyclo ./Drivers/HAL/stm32l4xx_hal_uart.d ./Drivers/HAL/stm32l4xx_hal_uart.o ./Drivers/HAL/stm32l4xx_hal_uart.su ./Drivers/HAL/stm32l4xx_hal_uart_ex.cyclo ./Drivers/HAL/stm32l4xx_hal_uart_ex.d ./Drivers/HAL/stm32l4xx_hal_uart_ex.o ./Drivers/HAL/stm32l4xx_hal_uart_ex.su ./Drivers/HAL/stm32l4xx_hal_wwdg.cyclo ./Drivers/HAL/stm32l4xx_hal_wwdg.d ./Drivers/HAL/stm32l4xx_hal_wwdg.o ./Drivers/HAL/stm32l4xx_hal_wwdg.su

.PHONY: clean-Drivers-2f-HAL

