

#ifndef INC_STM32F47XX_H_
#define INC_STM32F47XX_H_
#include<stdint.h>


#define FLASH_BASEADDR    0x08000000u  //compiler consider as signed number to avoid it ul is provided
#define  SRAM_BASEADDR    0x20000000u
#define SRAM1_BASEADDR    0x20000000u
#define SRAM2_BASEADDR    0x2001C000u
#define   OTP_BASEADDR    0x1FFF7800u
#define   ROM_BASEADDR    0x1FFF0000u
#define   RCC_BASEADDR    0x40023800u

/* AHBX and APBX ADDR
 */
#define PERI_BASEADDR    0x40000000u
#define AHB1_BASEADDR    0x40020000u
#define AHB2_BASEADDR    0x50000000u
#define APB1_BASEADDR    PERI_BASEADDR
#define APB2_BASEADDR    0x40010000u

/*AHB1 peripherals
 */
#define GPIOA_BASEADDR (AHB1_BASEADDR + 0X0000)
#define GPIOB_BASEADDR (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1_BASEADDR + 0x1000)

/*APB1 peripherals
 */

#define SPI2_BASE_ADDR    (APB1_BASEADDR + 0x3800)
#define SPI3_BASE_ADDR    (APB1_BASEADDR + 0x3C00)
#define I2C1_BASEADDR    (APB1_BASEADDR + 0x5400)
#define I2C2_BASEADDR    (APB1_BASEADDR + 0x5800)
#define I2C3_BASEADDR    (APB1_BASEADDR + 0x5C00)
#define USART2_BASEADDR  (APB1_BASEADDR + 0x4400)
#define USART3_BASEADDR  (APB1_BASEADDR + 0x4800)
#define UART4_BASEADDR   (APB1_BASEADDR + 0x4C00)
#define UART5_BASEADDR   (APB1_BASEADDR + 0x5000)
#define UART7_BASEADDR   (APB1_BASEADDR + 0x7800)
#define UART8_BASEADDR   (APB1_BASEADDR + 0x7C00)



/*APB2 peripherals
 */
#define USART1_BASEADDR     (APB2_BASEADDR + 0x1000)
#define USART6_BASEADDR     (APB2_BASEADDR + 0x1400)
#define SPI1_BASE_ADDR       (APB2_BASEADDR + 0x3000)
#define SPI4_BASE_ADDR       (APB2_BASEADDR + 0x3400)
#define SPI5_BASE_ADDR       (APB2_BASEADDR + 0x5000)
#define SPI6_BASE_ADDR       (APB2_BASEADDR + 0x5400)
#define EXTI_BASEADDR       (APB2_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR     (APB2_BASEADDR + 0x3800)

/*
 */


typedef struct
{
	volatile uint32_t  RCC_CR;
	volatile uint32_t  RCC_PLLCFGR;
	volatile uint32_t  RCC_CFGR;
	volatile uint32_t  RCC_CIR;
	volatile uint32_t  RCC_AHB1RSTR;
	volatile uint32_t  RCC_AHB2RSTR;
	volatile uint32_t  RCC_AHB3RSTR;
	volatile uint32_t  Reserved1;
	volatile uint32_t  RCC_APB1RSTR;
	volatile uint32_t  RCC_APB2RSTR;
	volatile uint32_t  Reserved2;
	volatile uint32_t  Reserved3;
	volatile uint32_t  RCC_AHB1ENR;
	volatile uint32_t  RCC_AHB2ENR;
	volatile uint32_t  RCC_AHB3ENR;
	volatile uint32_t  Reserved4;
	volatile uint32_t  RCC_APB1ENR;
	volatile uint32_t  RCC_APB2ENR;
	volatile uint32_t  Reserved5;
	volatile uint32_t  Reserved6;
	volatile uint32_t  RCC_AHB1LPENR;
	volatile uint32_t  RCC_AHB2LPENR;
	volatile uint32_t  RCC_AHB3LPENR;
	volatile uint32_t  Reserved7;
	volatile uint32_t  RCC_APB1LPENR;
	volatile uint32_t  RCC_APB2LPENR;
	volatile uint32_t  Reserved8;
	volatile uint32_t  Reserved9;
	volatile uint32_t  RCC_BDCR;
	volatile uint32_t  RCC_CSR;
	volatile uint32_t  Reserved10;
	volatile uint32_t  Reserved11;
	volatile uint32_t  RCC_SSCGR;
	volatile uint32_t  RCC_PLLI2SCFGR;
	volatile uint32_t  RCC_PLLSAICFGR;
	volatile uint32_t  RCC_DCKCFGR;

}Rcc_RegDef_t;

#define RCC  ((Rcc_RegDef_t*)0x40023800)
#define SYSCF_CLK_EN()    RCC->RCC_APB2ENR|=1<<14

typedef struct
{
	volatile uint32_t    GPIOx_MODER;
	volatile uint32_t   GPIOx_OTYPER;
	volatile uint32_t  GPIOx_OSPEEDR;
	volatile uint32_t    GPIOx_PUPDR;
	volatile uint32_t      GPIOx_IDR;
	volatile uint32_t      GPIOx_ODR;
	volatile uint32_t    GPIOx_BSRR;
	volatile uint32_t     GPIOx_LCKR;
	volatile uint32_t     GPIOx_AFRL;
	volatile uint32_t     GPIOx_AFRH;
}Gpio_RegDef_t;
#define GPIOA  ((Gpio_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  ((Gpio_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  ((Gpio_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  ((Gpio_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  ((Gpio_RegDef_t*)GPIOE_BASEADDR)

#define GPIOAP_CLK_EN()   RCC->RCC_AHB1ENR |=1<<0
#define GPIOBP_CLK_EN()   RCC->RCC_AHB1ENR |=1<<1
#define GPIOCP_CLK_EN()   RCC->RCC_AHB1ENR |=1<<2
#define GPIODP_CLK_EN()   RCC->RCC_AHB1ENR |=1<<3
#define GPIOEP_CLK_EN()   RCC->RCC_AHB1ENR |=1<<4


#define GPIOAP_CLK_DI()   (RCC->RCC_AHB1ENR &=~(1<<0))
#define GPIOBP_CLK_DI()   (RCC->RCC_AHB1ENR &=~(1<<1))
#define GPIOCP_CLK_DI()   (RCC->RCC_AHB1ENR &=~(1<<2))
#define GPIODP_CLK_DI()   (RCC->RCC_AHB1ENR &=~(1<<3))
#define GPIOEP_CLK_DI()   (RCC->RCC_AHB1ENR &=~(1<<4))

#define GPIOA_REG_RST()   do{(RCC->RCC_AHB1RSTR |=1<<0 );( RCC->RCC_AHB1RSTR &=~(1<<0));}while(0)
#define GPIOB_REG_RST()   do{(RCC->RCC_AHB1RSTR |=1<<1 ); (RCC->RCC_AHB1RSTR &=~(1<<1));}while(0)
#define GPIOC_REG_RST()   do{(RCC->RCC_AHB1RSTR |=1<<2 ); (RCC->RCC_AHB1RSTR &=~(1<<2));}while(0)
#define GPIOD_REG_RST()   do{(RCC->RCC_AHB1RSTR |=1<<3 ); (RCC->RCC_AHB1RSTR &=~(1<<3));}while(0)
#define GPIOE_REG_RST()   do{(RCC->RCC_AHB1RSTR |=1<<4 ); (RCC->RCC_AHB1RSTR &=~(1<<4));}while(0)







/*
 * EXTI INTERRUPT STRUCTURE
 */
typedef struct
{
   uint32_t EXTI_IMR;
   uint32_t EXTI_EMR;
   uint32_t EXTI_RTSR;
   uint32_t EXTI_FTSR;
   uint32_t EXTI_SWIER;
   uint32_t EXTI_PR;

}Exti_RegDef_t;

#define EXTI        ((Exti_RegDef_t*)EXTI_BASEADDR )
typedef struct
{
	uint32_t SYSCFG_MEMRMP;
	uint32_t SYSCFG_PMC;
	uint32_t SYSCFG_EXTICR[4];
	uint32_t SYSCFG_CMPCR ;
}Syscf_Reg_Def_t;
#define SYSCF    ((Syscf_Reg_Def_t*)SYSCFG_BASEADDR)




#define GPIO_BASEADDR__TO_PORTCODE(x)       (x==GPIOA)?0:(x==GPIOB)?1:(x==GPIOC)?2:(x==GPIOD)?3:(x==GPIOE)?4:255
#define IRQ_NO_EXTI0         6
#define IRQ_NO_EXTI1         7
#define IRQ_NO_EXTI2         8
#define IRQ_NO_EXTI3         9
#define IRQ_NO_EXTI4         10
#define IRQ_NO_EXTI9_5       23
#define IRQ_NO_EXTI15_10     40

#define IRQ_PRIORITY_00     0
#define IRQ_PRIORITY_01     1
#define IRQ_PRIORITY_02     2
#define IRQ_PRIORITY_03     3
#define IRQ_PRIORITY_04     4
#define IRQ_PRIORITY_05     5
#define IRQ_PRIORITY_06     6
#define IRQ_PRIORITY_07     7
#define IRQ_PRIORITY_08     8
#define IRQ_PRIORITY_09     9
#define IRQ_PRIORITY_10     10
#define IRQ_PRIORITY_11     11
#define IRQ_PRIORITY_12     12
#define IRQ_PRIORITY_13     13
#define IRQ_PRIORITY_14     14
#define IRQ_PRIORITY_15     15




/*
 * Processor specific NVIC REGISTER
 */
#define NVIC_ISER_BASE_ADDR     0xE000E100u



typedef struct
{
	uint32_t     NVIC_ISER[8];
	uint32_t     NVIC_ICER[8];
	uint32_t     NVIC_ISPR[8];
	uint32_t     NVIC_ICPR[8];
	uint32_t     NVIC_IABR[8];
	uint32_t     NVIC_IPR [60];
	uint32_t     STIR;
}NVIC_Reg_Def_t;

#define NVIC_CFG     ((NVIC_Reg_Def_t*) NVIC_ISER_BASE_ADDR)

typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI_Reg_Def_t;


#define SPI1             (SPI_Reg_Def_t *) SPI1_BASE_ADDR
#define SPI2             (SPI_Reg_Def_t *) SPI2_BASE_ADDR
#define SPI3             (SPI_Reg_Def_t *) SPI3_BASE_ADDR


#define SPI1_CLK_EN()     RCC->RCC_APB2ENR |=1<<12
#define SPI2_CLK_EN()     RCC->RCC_APB1ENR |=1<<14
#define SPI3_CLK_EN()     RCC->RCC_APB1ENR |=1<<15
#define SPI4_CLK_EN()     RCC->RCC_APB2ENR |=1<<13

#define SPI1_CLK_DI()     (RCC->RCC_APB2ENR &=~(1<<12))
#define SPI2_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<14))
#define SPI3_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<15))
#define SPI4_CLK_DI()     (RCC->RCC_APB2ENR &=~(1<<13))



#define SPI1_RST()    do{(RCC->RCC_APB2RSTR |=12<<0 );( RCC->RCC_APB2RSTR &=~(1<<0));}while(0)
#define SPI2_RST()    do{(RCC->RCC_APB1RSTR |=14<<0 );( RCC->RCC_APB1RSTR &=~(14<<0));}while(0)
#define SPI3_RST()    do{(RCC->RCC_APB1RSTR |=15<<0 );( RCC->RCC_APB1RSTR &=~(15<<0));}while(0)



typedef struct
{
	volatile uint32_t I2C_CR1;
	volatile uint32_t I2C_CR2;
	volatile uint32_t I2C_OAR1;
	volatile uint32_t I2C_OAR2;
	volatile uint32_t I2C_DR;
	volatile uint32_t I2C_SR1;
	volatile uint32_t I2C_SR2;
	volatile uint32_t I2C_CCR;
	volatile uint32_t I2C_TRISE;
	volatile uint32_t I2C_FLTR;
}I2C_Reg_Def_t;

#define I2C1_BASE_ADDR    0x40005400UL
#define I2C2_BASE_ADDR    0x40005800UL
#define I2C3_BASE_ADDR    0x40005C00UL

#define I2C1       (I2C_Reg_Def_t *) I2C1_BASE_ADDR
#define I2C2       (I2C_Reg_Def_t *) I2C2_BASE_ADDR
#define I2C3       (I2C_Reg_Def_t *) I2C3_BASE_ADDR


#define I2C1_CLK_EN()     RCC->RCC_APB1ENR |=1<<21
#define I2C2_CLK_EN()     RCC->RCC_APB1ENR |=1<<22
#define I2C3_CLK_EN()     RCC->RCC_APB1ENR |=1<<23

#define I2C1_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<21))
#define I2C2_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<22))
#define I2C3_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<23))

#define I2C1_CLK_RST()    do{(RCC->RCC_APB1RSTR |=21<<0 );( RCC->RCC_APB1RSTR &=~(21<<0));}while(0)
#define I2C2_CLK_RST()    do{(RCC->RCC_APB1RSTR |=22<<0 );( RCC->RCC_APB1RSTR &=~(22<<0));}while(0)
#define I2C3_CLK_RST()    do{(RCC->RCC_APB1RSTR |=23<<0 );( RCC->RCC_APB1RSTR &=~(23<<0));}while(0)




typedef struct
{

	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GTPR;

}USART_Reg_Def_t;
#define USART1     (USART_Reg_Def_t*) USART1_BASEADDR
#define USART2     (USART_Reg_Def_t*) USART2_BASEADDR
#define USART3     (USART_Reg_Def_t*) USART3_BASEADDR
#define UART4     (USART_Reg_Def_t*) UART4_BASEADDR
#define UART5     (USART_Reg_Def_t*) UART5_BASEADDR
#define USART6     (USART_Reg_Def_t*) USART6_BASEADDR


#define USART1_CLK_EN()    RCC->RCC_APB2ENR |=1<<4
#define USART2_CLK_EN()    RCC->RCC_APB1ENR |=1<<17
#define USART3_CLK_EN()    RCC->RCC_APB1ENR |=1<<18
#define UART4_CLK_EN()     RCC->RCC_APB1ENR |=1<<19
#define UART5_CLK_EN()     RCC->RCC_APB1ENR |=1<<20
#define USART6_CLK_EN()    RCC->RCC_APB2ENR |=1<<5

#define USART1_CLK_DI()    (RCC->RCC_APB2ENR &=~(1<<4))
#define USART2_CLK_DI()    (RCC->RCC_APB1ENR &=~(1<<17))
#define USART3_CLK_DI()    (RCC->RCC_APB1ENR &=~(1<<18))
#define UART4_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<19))
#define UART5_CLK_DI()     (RCC->RCC_APB1ENR &=~(1<<20))
#define USART6_CLK_DI()    (RCC->RCC_APB2ENR &=~(1<<5))



#define USART1_RST()      do{(RCC->RCC_APB1RSTR |=4<<0 );( RCC->RCC_APB1RSTR &=~(4<<0));}while(0)
#define USART2_RST()      do{(RCC->RCC_APB2RSTR |=17<<0 );( RCC->RCC_APB1RSTR &=~(17<<0));}while(0)
#define USART3_RST()      do{(RCC->RCC_APB2RSTR |=18<<0 );( RCC->RCC_APB1RSTR &=~(18<<0));}while(0)
#define UART4_RST()       do{(RCC->RCC_APB2RSTR |=19<<0 );( RCC->RCC_APB1RSTR &=~(19<<0));}while(0)
#define UART5_RST()       do{(RCC->RCC_APB2RSTR |=20<<0 );( RCC->RCC_APB1RSTR &=~(20<<0));}while(0)
#define USART6_RST()      do{(RCC->RCC_APB1RSTR |=5<<0 );( RCC->RCC_APB1RSTR &=~(5<<0));}while(0)

/*
 * SYSTICK MACROS
 */
#define SYSTICK_COUNTFLAG    16
#define SYSTICK_CLKSOURCE    2
#define SYSTICK_TICKINT      1
#define SYSTICK_ENABLE       0
/*
 * Generic macros
 */
#define ENABLE    1
#define DISABLE   0
#define SET       1
#define RESET     0
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET
#define FLAG_RESET       RESET
#define FLAG_SET         SET

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx_i2c_driver.h"
#include  "stm32f407xx_usart_driver.h"
#include  "stm32f407xx_rcc.h"


#endif /* INC_STM32F47XX_H_ */
