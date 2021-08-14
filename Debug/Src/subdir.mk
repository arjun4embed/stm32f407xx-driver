################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/clock.c \
../Src/clock_menu_manager.c \
../Src/keypad.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/clock.o \
./Src/clock_menu_manager.o \
./Src/keypad.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/clock.d \
./Src/clock_menu_manager.d \
./Src/keypad.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/clock.o: ../Src/clock.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/clock.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/clock_menu_manager.o: ../Src/clock_menu_manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/clock_menu_manager.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/keypad.o: ../Src/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/keypad.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

