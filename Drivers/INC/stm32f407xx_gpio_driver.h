

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_
#include "stm32f47xx.h"
#include<stdint.h>
typedef struct          //configurable structure
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;// Possible modes @GPIO MODES
	uint8_t GPIO_PinSpeed;// Possible Speed @GPIO SPEED
	uint8_t GPIO_PinPuPdControl;//possible configuration @GPIO PUPD
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_pinAltFunMode;

}GPIO_PinConfig_t;

/*
 * @GPIO_PinNumber
 */
#define GPIO_PIN_NO0     0
#define GPIO_PIN_NO1     1
#define GPIO_PIN_NO2     2
#define GPIO_PIN_NO3     3
#define GPIO_PIN_NO4     4
#define GPIO_PIN_NO5     5
#define GPIO_PIN_NO6     6
#define GPIO_PIN_NO7     7
#define GPIO_PIN_NO8     8
#define GPIO_PIN_NO9     9
#define GPIO_PIN_NO10    10
#define GPIO_PIN_NO11    11
#define GPIO_PIN_NO12    12
#define GPIO_PIN_NO13    13
#define GPIO_PIN_NO14    14
#define GPIO_PIN_NO15    15


typedef struct                      //Handle structure
{
	Gpio_RegDef_t *pGPIOx;//This holds the base address of the gpio pport to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t ;
/*
 * @GPIO_PinMode
 */
#define GPIO_MODE_IN      0
#define GPIO_MODE_OP      1
#define GPIO_MODE_ALTFN   2
#define GPIO_MODE_ANALOG  3
#define GPIO_MODE_IT_FT   4
#define GPIO_MODE_IT_RT   5
#define GPIO_MODE_IT_RFT  6


#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1

/*
 * @GPIO_PinSpeed
 */
#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3

/*
 * @GPIO_PinPuPdControl
 */
#define GPIO_NO_PUPD       0
#define GPIO_PU            1
#define GPIO_PD            2
/*
 * @GPIO_pinAltFunMode
 */
#define ALTFN_00      0
#define ALTFN_01      1
#define ALTFN_02      2
#define ALTFN_03      3
#define ALTFN_04      4
#define ALTFN_05      5
#define ALTFN_06      6
#define ALTFN_07      7
#define ALTFN_08      8
#define ALTFN_09      9
#define ALTFN_10      10
#define ALTFN_11      11
#define ALTFN_12      12
#define ALTFN_13      13


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/
/*
 * GPIO CLK ENABLE
 */
void  GPIO_PCLKControl(Gpio_RegDef_t *pGPIOx,uint8_t EnorDi);
/*
 *  GPIO Initialize /de - Initialize
 */
void  GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void  GPIO_Denit(Gpio_RegDef_t *pGPIOx);
/*
 * GPIO READ PORT READ/WRITE
 */
uint16_t  GPIO_Read_InputPort(Gpio_RegDef_t *pGPIOx);
void  GPIO_Write_OutputPort(Gpio_RegDef_t *pGPIOx,uint32_t value);

/*
 * GPIO   PIN READ/WRITE
 */
uint8_t  GPIO_Read_InputPin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber);
void  GPIO_Write_Outputpin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
/*
 * GPIO Toggle
 */
void  GPIO_Toggle_Outputpin(Gpio_RegDef_t *pGPIOx,uint8_t PinNumber);
/*
 * GPIO IRQ HANDLE
 */



void  GPIO_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority ,uint8_t EnorDi);




#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
