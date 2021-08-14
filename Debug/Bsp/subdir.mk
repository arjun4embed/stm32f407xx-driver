################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsp/DS3231.c \
../Bsp/LCD.c 

OBJS += \
./Bsp/DS3231.o \
./Bsp/LCD.o 

C_DEPS += \
./Bsp/DS3231.d \
./Bsp/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/DS3231.o: ../Bsp/DS3231.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Bsp/DS3231.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Bsp/LCD.o: ../Bsp/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Bsp/LCD.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

