################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_EEPROM.c \
../HAL/Key_pad.c \
../HAL/LCD.c 

OBJS += \
./HAL/I2C_EEPROM.o \
./HAL/Key_pad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/I2C_EEPROM.d \
./HAL/Key_pad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_EEPROM.o: ../HAL/I2C_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL" -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL/includes" -I../Inc -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Key_pad.o: ../HAL/Key_pad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL" -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL/includes" -I../Inc -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Key_pad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL" -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/HAL/includes" -I../Inc -I"C:/Users/Acer/STM32CubeIDE/workspace_1.4.0/Unit7_lesson3_lab/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

