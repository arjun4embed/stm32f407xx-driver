################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SRC/\ stm32f407xx_gpio_driver.c \
../Drivers/SRC/stm32f407xx_i2c_driver.c \
../Drivers/SRC/stm32f407xx_rcc.c \
../Drivers/SRC/stm32f407xx_spi_driver.c \
../Drivers/SRC/stm32f407xx_usart_driver.c 

OBJS += \
./Drivers/SRC/\ stm32f407xx_gpio_driver.o \
./Drivers/SRC/stm32f407xx_i2c_driver.o \
./Drivers/SRC/stm32f407xx_rcc.o \
./Drivers/SRC/stm32f407xx_spi_driver.o \
./Drivers/SRC/stm32f407xx_usart_driver.o 

C_DEPS += \
./Drivers/SRC/\ stm32f407xx_gpio_driver.d \
./Drivers/SRC/stm32f407xx_i2c_driver.d \
./Drivers/SRC/stm32f407xx_rcc.d \
./Drivers/SRC/stm32f407xx_spi_driver.d \
./Drivers/SRC/stm32f407xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SRC/\ stm32f407xx_gpio_driver.o: ../Drivers/SRC/\ stm32f407xx_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/SRC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/ stm32f407xx_gpio_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/SRC/stm32f407xx_i2c_driver.o: ../Drivers/SRC/stm32f407xx_i2c_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/stm32f407xx_i2c_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/SRC/stm32f407xx_rcc.o: ../Drivers/SRC/stm32f407xx_rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/stm32f407xx_rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/SRC/stm32f407xx_spi_driver.o: ../Drivers/SRC/stm32f407xx_spi_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/stm32f407xx_spi_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/SRC/stm32f407xx_usart_driver.o: ../Drivers/SRC/stm32f407xx_usart_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Src" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Inc" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Drivers/INC" -I"C:/Users/ARJUNPUDU/Desktop/EMBEDED SYSTEM/ARM/course_1/printf/stm32f4xx_Drivers/Bsp" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/stm32f407xx_usart_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

