################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MS5837-30BA.c \
../Src/gpio.c \
../Src/i2c.c \
../Src/main.c \
../Src/mpu6500.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/sys.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/usart.c 

OBJS += \
./Src/MS5837-30BA.o \
./Src/gpio.o \
./Src/i2c.o \
./Src/main.o \
./Src/mpu6500.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/sys.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/usart.o 

C_DEPS += \
./Src/MS5837-30BA.d \
./Src/gpio.d \
./Src/i2c.d \
./Src/main.d \
./Src/mpu6500.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/sys.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"D:/Accce_Press/Acce_Press_F4/Inc" -I"D:/Accce_Press/Acce_Press_F4/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Accce_Press/Acce_Press_F4/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Accce_Press/Acce_Press_F4/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Accce_Press/Acce_Press_F4/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


