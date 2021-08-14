

#ifndef INC_STM32_F407XX_RCC_H_
#define INC_STM32_F407XX_RCC_H_


#define APB1_CLK         0
#define APB2_CLK         1
#define processor_clock  2
#define AHB1             3
#define AHB2             4


uint32_t GetCLKValue(uint8_t clock_source);

#endif /* INC_STM32_F407XX_RCC_H_ */
