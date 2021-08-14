
#include "stm32f47xx.h"




static void I2C_ExecuteAddrPhase(I2C_Reg_Def_t *pI2Cx,uint8_t SlaveAddr);
static  void I2C_GenerateStartCondition(I2C_Reg_Def_t *pI2Cx);



/***************     I2C SUPPORTED API*************************/

/*
 * @fn        - I2C_PeripheralControl
 * @brief     - It is used to configure clock for respective I2C(1,2,3)
 * @param[in] -    Base address of I2C peripheral,Enable or disbale macro
 * @return    -   none
 * @Note      -   none
 */
void I2C_PeripheralControl(I2C_Reg_Def_t *ptr,uint8_t EnoDi)
{
	if(EnoDi == ENABLE)
	{
		ptr->I2C_CR1 |=1<<0;
	}else
	{
		ptr->I2C_CR1 &=~(1<<0);
	}

}


/*
 * @fn        - I2C_Peripheral_ACK_Control
 * @brief     - It is used to control acking for I2C peripheral
 * @param[in] -  Base address of gpio peripheral,Enable or Disable macro
 * @return    -   none
 * @Note      -   none
 */
void I2C_Peripheral_ACK_Control(I2C_Reg_Def_t *pI2Cx,uint8_t EnoDi)
{
	//NOTE : Acknowledge Control should only be enabled after Peripheral Enable (PE=1 in CR1)
	if(EnoDi == ENABLE)
		pI2Cx->I2C_CR1 |=1<<ACK ;

	else
	{
		 pI2Cx->I2C_CR1 &=~(1<<ACK);
	}

}

/*
 * @fn        - I2C_ClearADDRFlag
 * @brief     - It is used to clear ADDR flag after address phase execute
 * @param[in] -  Base address of I2C peripheral
 * @return    -   none
 * @Note      -   none
 */
static void I2C_ClearADDRFlag(I2C_Reg_Def_t *pI2Cx)
{
	uint32_t dummyread = pI2Cx->I2C_SR1;
	dummyread = pI2Cx->I2C_SR2;
	(void)dummyread;
}


/*
 * @fn        - I2C_ExecuteAddrPhase
 * @brief     - It is used to send  7 bit slave address +  write bit  in Master mode
 * @param[in] - Base address of I2C peripheral,Slave address
 * @return    - none
 * @Note      - none
 */
static void I2C_ExecuteAddrPhase(I2C_Reg_Def_t *pI2Cx,uint8_t SlaveAddr)
{
	SlaveAddr <<=1;
	SlaveAddr &=~(1);
	pI2Cx->I2C_DR =SlaveAddr;
}


/*
 * @fn        - I2C_ExecuteAddrPhaseWrite
 * @brief     - It is used to configure clock for respective PORT(A,B,C,D,E)
 * @param[in] -  Base address of I2C peripheral,Slave address
 * @return    -   none
 * @Note      -   none
 */
static void I2C_ExecuteAddrPhaseWrite(I2C_Reg_Def_t *pI2Cx,uint8_t SlaveAddr)
{
	SlaveAddr <<=1;
	SlaveAddr |=0x1;
	pI2Cx->I2C_DR =SlaveAddr;
}


/*
 * @fn        - I2C_GenerateStartCondition
 * @brief     - It is used to generate start condition
 * @param[in] -  Base address of I2C peripheral
 * @return    -   none
 * @Note      -   none
 */
static  void I2C_GenerateStartCondition(I2C_Reg_Def_t *pI2Cx)
{
	pI2Cx->I2C_CR1 |=1<<START;
}


/*
 * @fn        - I2C_GenerateStopCondition
 * @brief     - It is used to generate stop condition
 * @param[in] -  Base address of I2C peripheral
 * @return    -   none
 * @Note      -   none
 */
static  void I2C_GenerateStopCondition(I2C_Reg_Def_t *pI2Cx)
{

	pI2Cx->I2C_CR1 |=1<<STOP;
}

/*
 * @fn        - RCC_GetPCLKValue
 * @brief     - It is used to get Peripheral clock frequency
 * @param[in] -   none
 * @return    -   none
 * @Note      -   Frequency of peripheral
 */
uint32_t RCC_GetPCLKValue(void)
{
	uint32_t AHBclk,pclk,SystemClk,APB1_PreScalar,AHB_PreScaler;
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
	APB1_PreScalar = 0;
	APB1_PreScalar |=((RCC->RCC_CFGR>>10)&0X7);
	if(APB1_PreScalar < 4)
	{
		pclk= AHBclk /1;
	}else
	{
		pclk= AHBclk /APB1_PreScalar;
	}



	return pclk;

}

/*
 * @fn        - GPIO_PCLKControl
 * @brief     - It is used to configure clock for respective PORT(A,B,C,D,E)
 * @param[in] -  Base address of gpio peripheral
 * @return    -   none
 * @Note      -   none
 */
void  I2C_PCLKControl(I2C_Reg_Def_t *pI2Cx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pI2Cx == I2C1)
		{
			I2C1_CLK_EN();

		}
		else if(pI2Cx == I2C2)
		{
			I2C2_CLK_EN();

		}
		else if(pI2Cx == I2C3)
		{
			I2C3_CLK_EN();
		}
	}
	else
	{

		if(pI2Cx == I2C1)
		{
		  I2C1_CLK_DI();

		}
		else if(pI2Cx == I2C2)
		{
		  I2C2_CLK_DI();

	    }
		else if(pI2Cx == I2C3)
		{
		  I2C3_CLK_DI();

		}
	}
}

/*
 * @fn        -  I2C_Init
 * @brief     - It is used to initialize I2C peripheral
 * @param[in] -  I2C Handle structure
 * @return    -   none
 * @Note      -   none
 */
void  I2C_Init(I2C_handle_t *pI2CHandle)
{

	uint32_t tempreg;
	//1.Peripheral Clock Enable
	I2C_PCLKControl(pI2CHandle->pI2Cx,ENABLE);

	//2.Configure FREQ Bits in I2C_CR2 Register
	tempreg = ((RCC_GetPCLKValue())/1000000);

	pI2CHandle->pI2Cx->I2C_CR2 |=(tempreg<<0);

	//3.Configure own address for device in slave mode

	tempreg=((pI2CHandle->I2C_Config.I2C_DEVICEAddress)<<1);
	pI2CHandle->pI2Cx->I2C_OAR1 |=tempreg;
	//NOTE: Should always be kept at 1 by software.
	pI2CHandle->pI2Cx->I2C_OAR1 |=1<<14;

	//4.Configure CCR Bits in I2C_CCR register
	uint16_t ccr_value=0;
	tempreg=0;
	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <=I2C_SCL_SPEED_SM )
	{
         //Mode Standard Mode
		ccr_value = ((RCC_GetPCLKValue())/(2*pI2CHandle->I2C_Config.I2C_SCLSpeed));

		tempreg =(ccr_value & 0xfff);
	}else
	{
		//Mode Fast Mode
		tempreg |=(1<<15);

		tempreg |=((pI2CHandle->I2C_Config.I2C_FMDutyCycle )<<14);

		if(pI2CHandle->I2C_Config.I2C_FMDutyCycle == I2C_SCL_SPEED_FM2K)
		{
			ccr_value = ((RCC_GetPCLKValue())/(3*pI2CHandle->I2C_Config.I2C_SCLSpeed));
		}
		else
		{
			ccr_value = ((RCC_GetPCLKValue())/(25*pI2CHandle->I2C_Config.I2C_SCLSpeed));
			tempreg |=ccr_value;
		}

	}

	pI2CHandle->pI2Cx->I2C_CCR=tempreg;

	//5. Configure Trise bit in I2C_TRISE Register

	if(pI2CHandle->I2C_Config.I2C_SCLSpeed <=I2C_SCL_SPEED_SM )
	{

		tempreg =(RCC_GetPCLKValue()/1000000u)+1;

	}
	else
	{

		tempreg = ((RCC_GetPCLKValue()*300)/1000000000u)+1;

	}
	pI2CHandle->pI2Cx->I2C_TRISE =(tempreg & 0x3F);


}


/*
 * @fn        -  I2C_Denit
 * @brief     -  It is used to reset i2c peripheral
 * @param[in] -  Base address of I2C peripheral
 * @return    -   none
 * @Note      -   none
 */
void  I2C_Denit(I2C_handle_t *pI2CHandle)
{
     if(pI2CHandle->pI2Cx == I2C1)
     {
    	 I2C1_CLK_RST();
     }else if(pI2CHandle->pI2Cx == I2C2)
     {
    	 I2C1_CLK_RST();
     }else if(pI2CHandle->pI2Cx == I2C3)
     {
    	 I2C1_CLK_RST();
     }

}


/*
 * @fn        - I2C_MasterSendData
 * @brief     - It is used to send data when device in master mode
 * @param[in] -  Base address of I2C peripheral,address of transmit buffer ,length of data ,address of slave,repeat start condition
 * @return    -   none
 * @Note      -   none
 */
 void  I2C_MasterSendData(I2C_Reg_Def_t *pI2Cx,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr)
{
	//1.Generate start condition

	I2C_GenerateStartCondition(pI2Cx);

	//2.confirm that start generation is complete by checking the SB flag in the 2C_SR1 Register
   // Note : unitil  SR bit is cleared the SCL will be streched (Pull to Low)

	while(!(I2C_GetFlagStatus(pI2Cx,I2C_FLAG_SB)));


	//3. Send slave address followed by R/W bit =0

	I2C_ExecuteAddrPhase(pI2Cx,SlaveAddr);

	//4.Check address phase is completed by checking ADDR =1

	while(!(I2C_GetFlagStatus(pI2Cx,I2C_FLAG_ADDR)));

	//5. Clear Flag by reading sr1,sr2 registers

	I2C_ClearADDRFlag(pI2Cx);

    //6.Send data until length becomes zero

	while(Len>0)
	{
	while(!(I2C_GetFlagStatus(pI2Cx,I2C_FLAG_TXE)));
	pI2Cx->I2C_DR = *pTxBuffer;
	pTxBuffer++;
	Len --;

	}

	//7.When length becomes zero ,wait for TXE=1,BTF=1 before generating stop condition

	while(!(I2C_GetFlagStatus(pI2Cx,I2C_FLAG_TXE)));//Checking TXE is empty
	while(!(I2C_GetFlagStatus(pI2Cx,I2C_FLAG_BTF)));//Checking BTF is Set

	//8.Stop condition is generated ,after that automaticaally BTF will be cleared
    // NOTE: STOP Condition is created only when Sr == 0
	if(Sr == 0)
	{
	I2C_GenerateStopCondition(pI2Cx);
	}





}


 /*
  * @fn        - I2C_GetFlagStatus
  * @brief     - It is used check flag status
  * @param[in] -  Base address of I2C peripheral
  * @return    -   Flag status
  * @Note      -   none
  */
 uint8_t I2C_GetFlagStatus(I2C_Reg_Def_t *pI2Cx,uint8_t FlagName)
 {
 	if(pI2Cx->I2C_SR1 &FlagName)
 	{
 		return FLAG_SET;
 	}

 	return FLAG_RESET;

 }


 /*
  * @fn        - GPIO_PCLKControl
  * @brief     - It is used to configure clock for respective PORT(A,B,C,D,E)
  * @param[in] -  Base address of gpio peripheral
  * @return    -   none
  * @Note      -   none
  */
void  I2C_RecieveData(I2C_handle_t *pI2CHandle,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr)
{
	I2C_GenerateStartCondition(pI2CHandle->pI2Cx);
	//2.confirm that start generation is complete by checking the SB flag in the 2C_SR1 Register
	// Note : unitil  SR bit is cleared the SCL will be streched (Pull to Low)
    while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_SB)));//Here checking for status clears the SR register
		//3. Send slave address followed by R/W bit =0

    I2C_ExecuteAddrPhaseWrite(pI2CHandle->pI2Cx,SlaveAddr);
		while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx,I2C_FLAG_ADDR)));
		if (Len == 1)//ONLY FOR 1BYTE DATA RECEPTION
				{
		         	I2C_Peripheral_ACK_Control(pI2CHandle->pI2Cx,DISABLE);

		         	I2C_ClearADDRFlag(pI2CHandle->pI2Cx);


		         	while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_RXNE)));
		         	if(Sr == 0)
		         		I2C_GenerateStopCondition(pI2CHandle->pI2Cx);

		         	*pTxBuffer=(pI2CHandle->pI2Cx->I2C_DR) ;

			        return;

				}

		if(Len >1)
		{
			I2C_ClearADDRFlag(pI2CHandle->pI2Cx);

			for(uint32_t i=Len ;i >0;i++)
			{

				while(!(I2C_GetFlagStatus(pI2CHandle->pI2Cx, I2C_FLAG_RXNE)));


				if(i == 2)
				{
					I2C_Peripheral_ACK_Control(pI2CHandle->pI2Cx,DISABLE);
                     if(Sr == 1)
                    	 I2C_GenerateStopCondition(pI2CHandle->pI2Cx);


				}

			}

			*pTxBuffer = pI2CHandle->pI2Cx->I2C_DR;

			pTxBuffer++;


		}


		if(pI2CHandle->I2C_Config.I2C_ACKControl == ENABLE)
		{
			I2C_Peripheral_ACK_Control(pI2CHandle->pI2Cx,ENABLE);
		}
}
