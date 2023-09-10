################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.c 

OBJS += \
./Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.o 

C_DEPS += \
./Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.o: ../Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/KeyPad_Driver" -I../Inc -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/LCD_Driver" -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32f103c6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

