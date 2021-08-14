#include "stm32f47xx.h"

/*
 * @fn        -  USART_PeriClockControl
 * @brief     -  It is used configure clock for  USART peripheral
 * @param[in] -  Base address of USART peripheral,Enable or Disable macro
 * @return    -  none
 * @Note      -  none
 */

void USART_PeriClockControl(USART_Reg_Def_t *pUSARTx,uint8_t EnOrDi)
{

	if(EnOrDi == ENABLE)
	{
		if(pUSARTx == USART1)
		{
			USART1_CLK_EN();
		}
		else if(pUSARTx == USART2)
		{
			USART2_CLK_EN();
		}
		else if(pUSARTx == USART3)
		{
			USART3_CLK_EN();
		}
		else if(pUSARTx == UART4)
		{
			UART4_CLK_EN();
		}
		else if(pUSARTx == UART5)
		{
			UART5_CLK_EN() ;
		}
		else if(pUSARTx == USART6)
		{
			USART6_CLK_EN();
		}
	}

	else

	{
		if(pUSARTx == USART1)
				{
					USART1_CLK_DI();
				}
				else if(pUSARTx == USART2)
				{
					USART2_CLK_DI();
				}
				else if(pUSARTx == USART3)
				{
					USART3_CLK_DI();
				}
				else if(pUSARTx == UART4)
				{
					UART4_CLK_DI();
				}
				else if(pUSARTx == UART5)
				{
					UART5_CLK_DI() ;
				}
				else if(pUSARTx == USART6)
				{
					USART6_CLK_DI();
				}
	}
}


/*
 * @fn        -   USART_PeripheralControl
 * @brief     -  It is used   Enable or Disable peripheral
 * @param[in] -  Base address of USART peripheral,Enable or Disable macro
 * @return    -  none
 * @Note      -  none
 */

void USART_PeripheralControl(USART_Reg_Def_t *pUSARTx,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pUSARTx->USART_CR1 |=1<<USART_CR1_UE;
	}
	else
	{
		pUSARTx->USART_CR1 &=~(1<<USART_CR1_UE);

	}
}


/*
 * @fn        -   USART_Init
 * @brief     -  It is used   initialize the peripheral
 * @param[in] -  handle structure base address
 * @return    -  none
 * @Note      -  none
 */

void USART_Init(USART_Handle_t *pUSARTHandle)
{
	 USART_PeriClockControl(pUSARTHandle->pUSARTx,ENABLE);

			/***************************Configuring CR1 Register **********************/
	uint32_t tempreg =0;
         //Configuring USART Mode
		if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
		{
			tempreg|= (1 << USART_CR1_RE);
		}
		else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
		{
			tempreg|= (1 << USART_CR1_TE);

		}
		else if (pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX)
		{
			tempreg|= (1 << USART_CR1_RE);
			tempreg|= (1 << USART_CR1_TE);
		}
			tempreg |= pUSARTHandle->USART_Config.USART_WordLength <<pUSARTHandle->pUSARTx->USART_CR1 ;



	  // Configuring Wordlength
	  if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLENGTH_8bits)
		{
		  tempreg |= pUSARTHandle->pUSARTx->USART_CR1 & (~(1<<USART_CR1_M));

		}
	  else if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLENGTH_9bits)
	   {
		  tempreg |= pUSARTHandle->pUSARTx->USART_CR1 |(1<<USART_CR1_M);
	   }
	  pUSARTHandle->pUSARTx->USART_CR1 |=tempreg;

	  /*******Configuring CR2 Register *******/

	  // Configuring Parity Control
		if ( pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
		{

			tempreg |= ( 1 << USART_CR1_PCE);



		}else if (pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD )
		{

		    tempreg |= ( 1 << USART_CR1_PCE);


		    tempreg |= ( 1 << USART_CR1_PS);

		}
		pUSARTHandle->pUSARTx->USART_CR1 |=tempreg;



		tempreg=0;
      // 	Configuring No Of Stop bits

		tempreg |= pUSARTHandle->USART_Config.USART_NoOfStopbits << USART_CR2_STOP;


		pUSARTHandle->pUSARTx->USART_CR2|= tempreg;



		tempreg=0;
		  /*******Configuring CR2 Register *******/

		//Configuring Hardware flow control

		if ( pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
		{

			tempreg |= ( 1 << USART_CR3_CTSE);


		}else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
		{

			tempreg |= (1<<USART_CR3_RTSE);

		}else if (pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
		{
			tempreg |= (1<<USART_CR3_CTSE);
			tempreg |= (1<<USART_CR3_RTSE);
		}


		pUSARTHandle->pUSARTx->USART_CR3 = tempreg;


		USART_SetBaudRate(pUSARTHandle->pUSARTx, pUSARTHandle->USART_Config.USART_Baud);


}


/*
 * @fn        -   USART_DeInit
 * @brief     -  It is used  reset peripheral
 * @param[in] -  Base address of USART peripheral
 * @return    -  none
 * @Note      -  none
 */

void USART_DeInit(USART_Reg_Def_t*pUSARTx)
{

			if(pUSARTx == USART1)
			{
				USART1_RST() ;
			}
			else if(pUSARTx == USART2)
			{
				USART2_RST();
			}
			else if(pUSARTx == USART3)
			{
				USART3_RST();
			}
			else if(pUSARTx == UART4)
			{
				UART4_RST();
			}
			else if(pUSARTx == UART5)
			{
				UART5_RST();
			}
			else if(pUSARTx == USART6)
			{
				USART6_RST() ;
			}



}



/*
 * @fn        -  USART_GetFlagStatus
 * @brief     -  It is used   check usart flag
 * @param[in] -  Base address of USART peripheral,flag
 * @return    -  bit status
 * @Note      -  none
 */
uint8_t USART_GetFlagStatus(USART_Reg_Def_t *pUSARTx,uint8_t StatusFlagName)
{
	if(pUSARTx->USART_SR & StatusFlagName)
	 	{
	 		return FLAG_SET;
	 	}

	 	return FLAG_RESET;
}



/*
 * @fn        -    USART_SendData
 * @brief     -  It is used   send data through peripheral
 * @param[in] -  Address of handle structure ,base address of data buffer ,length of data
 * @return    -  none
 * @Note      -  none
 */
void USART_SendData(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len)
{

	uint16_t *pdata;

	while(Len>0)
	{

		while(!  USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TXE));

         //Check for word length given by Application code
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLENGTH_9bits)
		{
			//If the word length is 9bits 2 bytes data is fetched
			pdata = (uint16_t*) pTxBuffer;
			pUSARTHandle->pUSARTx->USART_DR = (*pdata & (uint16_t)0x01FF);

			//Check parity control configuration from Application code
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				// parity bit is disabled,9bit user data is sent
				pTxBuffer +=2;
				Len -=2;

			}
			else
			{
				//Parity bit is enabled,9th bit is added by hardware by checking parity configuration
				pTxBuffer++;
				Len --;
			}
		}
		if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
					{
						//No parity is used , so all 8bits will be of user data

						//read 8 bits from DR
			          pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer  & (uint8_t)0xFF);


						pTxBuffer++;
						Len--;
					}

					else
					{
						//parity is enabled then 7th bit is replaced by Hardware
						pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer  & (uint8_t)0x7F);


												pTxBuffer++;
												Len--;

					}

}

	while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TC));
}


/*
 * @fn        -  USART_ReceiveData
 * @brief     -  It is used   receive data through peripheral
 * @param[in] -  Address of handle structure ,base address of data buffer ,lentgh of data
 * @return    -  none
 * @Note      -  none
 */
void USART_ReceiveData(USART_Handle_t  *pUSARTx, uint8_t *pRxBuffer, uint32_t Len)
{

	  while(Len>0)
		{
			//Checking for rxne buffer
			while(!  USART_GetFlagStatus(pUSARTx->pUSARTx,USART_FLAG_RXNE));

			//Checking Word size
			if(pUSARTx->USART_Config.USART_WordLength == USART_WORDLENGTH_9bits)
			{
				//Receiving 9 bits
				if(pUSARTx->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
				{
					// Reading 9 bit data by masking 0x01FF
					*((uint16_t*) pRxBuffer) = (pUSARTx->pUSARTx->USART_DR  & (uint16_t)0x01FF);


					pRxBuffer+=2;
				}
				else
				{
					//8 bit data is extracted
					 *pRxBuffer = (pUSARTx->pUSARTx->USART_DR  & (uint8_t)0xFF);
					 pRxBuffer++;
				}
			}
			else
			{
				//8 bit data recieved
				if(pUSARTx->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
				{
					//No parity ,so all 8 bit is data
					 *pRxBuffer = (uint8_t) (pUSARTx->pUSARTx->USART_DR  & (uint8_t)0xFF);
				}

				else
				{
					//Parity enabled,7Bit data +1 Bit parity
					 *pRxBuffer = (uint8_t) (pUSARTx->pUSARTx->USART_DR  & (uint8_t)0x7F);

				}


				pRxBuffer++;
				Len--;
			}
		}


}


/*
 * @fn        -  USART_SetBaudRate
 * @brief     -  It is used   to set baud rate for UART peripheral
 * @param[in] -  Base address of USART peripheral ,baud rate
 * @return    -  none
 * @Note      -  none
 */
void USART_SetBaudRate(USART_Reg_Def_t *pUSARTx, uint32_t BaudRate)
{


	uint32_t PCLKx;

	uint32_t usartdiv;


	uint32_t Mantissa,Fraction;

  uint32_t tempreg=0;

  //If USART1 OR USART6 is selected by the application code then get APB2 Peripheral clock
  if(pUSARTx == USART1 || pUSARTx == USART6)
  {
	   //USART1 and USART6 are hanging on APB2 bus
	   PCLKx = GetCLKValue(APB2_CLK);
  }
  //If USART2,USART3,UART4,UART5 is selected by the application code then get APB1 Peripheral clock
  else
  {
	   PCLKx = GetCLKValue(APB1_CLK);
  }

  //Check for OVER8 configuration bit
  if(pUSARTx->USART_CR1 & (1 << USART_CR1_OVER8))
  {
	  //If OVER8 == 1,over sampling by 8
	   usartdiv = ((25 * PCLKx) / (2 *BaudRate));
  }else
  {
	  //If OVER8 == 1,over sampling by 16
	  usartdiv = ((25 * PCLKx) / (4 *BaudRate));
  }


  Mantissa = usartdiv/100;


  tempreg |= Mantissa << 4;


  Fraction = (usartdiv - (Mantissa * 100));


  if(pUSARTx->USART_CR1 & ( 1 << USART_CR1_OVER8))
   {
	  //OVER8 = 1 , over sampling by 8
	  Fraction = ((( Fraction * 8)+ 50) / 100)& ((uint8_t)0x07);

   }else
   {
	   //over sampling by 16
	   Fraction = ((( Fraction * 16)+ 50) / 100) & ((uint8_t)0x0F);

   }


  tempreg |= Fraction;

  pUSARTx->USART_BRR = tempreg;
}


/*
 * @fn        -   USART_IRQConfig
 * @brief     -  It is used   Enable/Disable peripheral interrupt  with interrupt priority configuration
 * @param[in] -  Peripheral IRQ number , priority ,Enable or Disable macro
 * @return    -  none
 * @Note      -  none
 */


void  USART_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority ,uint8_t EnorDi)
    {
   	 if(EnorDi == ENABLE)
   	 {
   		 NVIC_CFG->NVIC_ISER[IRQNumber/32] |=1<<(IRQNumber%32);
   		 NVIC_CFG->NVIC_ISPR[IRQNumber/4]  |=IRQPriority <<((IRQNumber%4)+4);
   	 }
   	 else if(EnorDi == DISABLE)
   	 {
   		 NVIC_CFG->NVIC_ISER[IRQNumber/32] &=~(1<<(IRQNumber%32));

   	 }


    }
