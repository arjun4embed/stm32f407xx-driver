
#include "stm32f47xx.h"

#include "stm32f407xx_rcc.h"


uint32_t GetCLKValue(uint8_t clock)
{
	uint32_t AHBclk,pclk,SystemClk,APB_PreScalar,AHB_PreScaler;
	uint32_t System_clock_switch_status =( RCC->RCC_CFGR>>2) &0X3;
	if(System_clock_switch_status == 0)
	{
		//NOTE : Internal RC oscillator in STM32F407G is 16MHZ
		SystemClk = 16000000ul;
	}else if(System_clock_switch_status == 0)
	{ //NOTE : External Crystal on  STM32F407G  Board is 8MHZ
		SystemClk = 8000000ul;
	}else if(System_clock_switch_status == 0)
	{
		 //PLL WILL BE IMPLEMENTED LATER
	}
	AHB_PreScaler =(( RCC->RCC_CFGR>>4)&0XF);
	if(AHB_PreScaler <8)
	{
		 AHBclk = SystemClk/1;
	}else
	{
		AHBclk =SystemClk/AHB_PreScaler;
	}
	if(clock == processor_clock)
	{
		return AHBclk;
	}
	APB_PreScalar = 0;
	if(clock == APB1_CLK)
	{
		APB_PreScalar |=((RCC->RCC_CFGR>>10)&0X7);
	}
	else
	{
		APB_PreScalar |=((RCC->RCC_CFGR>>13)&0X7);
	}

	if(APB_PreScalar < 4)
	{
		pclk= AHBclk /1;
	}else
	{
		pclk= AHBclk /APB_PreScalar;
	}



	return pclk;

}
