#include "stm32f407xx_spi_driver.h"
#include "stm32f47xx.h"

/*
 * @fn        - SPI_GetFlagStatus
 * @brief     - It is used to get status of various SPI flag
 * @param[in] -  Base address of gpio peripheral,flag name
 * @return    -   none
 * @Note      -   Flag status
 */
uint8_t SPI_GetFlagStatus(SPI_Reg_Def_t *pSpix,uint8_t FlagName)
{
	if(pSpix->SPI_SR &FlagName)
	{
		return FLAG_SET;
	}

	return FLAG_RESET;

}

/*
 * @fn        - SPI_PCLKControl
 * @brief     - It is used to configure clock for SPI peripheral
 * @param[in] -  Base address of SPI peripheral , Enable or disable macro
 * @return    -   none
 * @Note      -   none
 */

void  SPI_PCLKControl(SPI_Reg_Def_t *pSpix,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSpix == SPI1 )
		{
			SPI1_CLK_EN();
		}
		else if(pSpix == SPI2)
		{
			SPI2_CLK_EN();
		}
		else if(pSpix == SPI3)
		{
					SPI3_CLK_EN();
		}

	}
	else
	{
		if(pSpix == SPI1 )
		{
		 SPI1_CLK_DI();
		}
		else if(pSpix == SPI2)
		{
		  SPI2_CLK_DI();
		}
		else if(pSpix == SPI3)
		{
		  SPI3_CLK_DI();
		}

	}
}

/*
 * @fn        - SPI_Init
 * @brief     - It is used to initialize SPI peripheral
 * @param[in] -  Base address of SPI peripheral
 * @return    -   none
 * @Note      -   none
 */

void  SPI_Init(Spi_handle_t *pSpiHandle)
{
	uint32_t  tempcr=0;
	tempcr |=pSpiHandle->Spiconfig.Spi_Device_Mode<<2;//master or slave mode config
	if(pSpiHandle->Spiconfig.Spi_Bus_Config == SPI_BUS_CONFIG_FD)
	{                                                                     // Full duplex,Half duplex and Simplex config
		tempcr &=~(1<<SPI_CR1_BIDIMODE);

	}else  if(pSpiHandle->Spiconfig.Spi_Bus_Config == SPI_BUS_CONFIG_HD)
	{
		tempcr |=1<<SPI_CR1_BIDIMODE;

	}else  if(pSpiHandle->Spiconfig.Spi_Bus_Config == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		tempcr &=~(1<<SPI_CR1_BIDIMODE);
		tempcr |=1<<SPI_CR1_RXONLY;
	}
	tempcr |=pSpiHandle->Spiconfig.Spi_ssm<<SPI_CR1_SSM ;
	tempcr |=pSpiHandle->Spiconfig.Spi_Sclk_Speed<<SPI_CR1_BR ;// SPI SCLK speed config
	tempcr |=pSpiHandle->Spiconfig.Spi_DFF <<SPI_CR1_DFF;  //Data frame format
	tempcr |=pSpiHandle->Spiconfig.Spi_Cpha <<SPI_CR1_CPHA ; //Clock phase config
	tempcr |=pSpiHandle->Spiconfig.Spi_Cpol <<SPI_CR1_CPOL; // Clock polarity config
	pSpiHandle->pSpix->SPI_CR1 = tempcr;
}

/*
 * @fn        - SPI_Denit
 * @brief     - It is used to deintilaize
 * @param[in] -  Base address of SPI peripheral
 * @return    -   none
 * @Note      -   none
 */

void  SPI_Denit(Spi_handle_t *pSpiHandle)
{
	if(pSpiHandle->pSpix == SPI1)
	{
		SPI1_RST();
	}else if(pSpiHandle->pSpix == SPI2)
	{
		SPI2_RST();
	}
	else if(pSpiHandle->pSpix == SPI3)
	{
	SPI3_RST();
	}

}

/*
 * @fn        - SPI_SendData
 * @brief     - It is used to send data in SPI master mode
 * @param[in] -  Base address of SPI peripheral,transmit data buffer address,length of data
 * @return    -   none
 * @Note      -   none
 */

void SPI_SendData(SPI_Reg_Def_t *pSpix ,uint8_t *pTxBuffer,uint32_t Len)
{
	while(Len>0)
	{
		while(SPI_GetFlagStatus(pSpix,SPI_TXE_FLAG)== FLAG_RESET){};

			if(pSpix->SPI_CR1 & (1<<SPI_CR1_DFF))
			{
			pSpix->SPI_DR = (*(uint16_t *)pTxBuffer); // 16 bit data frame (uint16_t typecast ptxbuffer is 1byte and only copy 1 byte );
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;


			}
			else
			{
				pSpix->SPI_DR = (*pTxBuffer); // 8 bit data frame (uint16_t typecast ptxbuffer is 1byte and only copy 1 byte );
			    Len--;
			    pTxBuffer++;	//8 bit data frame
			}


	}
}

/*
 * @fn        - SPI_PeripheralControl
 * @brief     - It is used to Enable or Disable SPI peripheral
 * @param[in] -  Base address of SPI peripheral,Enable or Disable macro
 * @return    -   none
 * @Note      -   none
 */

void SPI_PeripheralControl(SPI_Reg_Def_t *ptr,uint8_t EnoDi)
{
	if(EnoDi == ENABLE)
	{
		ptr->SPI_CR1 |= (1<< SPI_CR1_SPE);
	}else
	{
		ptr->SPI_CR1 &=~ (1<< SPI_CR1_SPE);
	}

}

/*
 * @fn        - SPI_SSIConfig
 * @brief     - It is used to configure SSI bit
 * @param[in] -  Base address of SPI peripheral,Enable or Disable macro
 * @return    -   none
 * @Note      -   none
 */

void SPI_SSIConfig(SPI_Reg_Def_t *ptr,uint8_t EnoDi)
{
	if(EnoDi == ENABLE)
	{
		ptr->SPI_CR1 |= (1<< SPI_CR1_SSI);
	}else
	{
		ptr->SPI_CR1 &=~ (1<< SPI_CR1_SSI);
	}
}

/*
 * @fn        - SPI_SSOEConfig
 * @brief     - It is used to configure SSOE bit
 * @param[in] -  Base address of SPI peripheral,Enable or Disable macro
 * @return    -   none
 * @Note      -   none
 */

void SPI_SSOEConfig(SPI_Reg_Def_t *ptr,uint8_t EnoDi)
{
	if(EnoDi == ENABLE)
	{
		ptr->SPI_CR2 |= (1<< SPI_CR2_SSOE );
	}else
	{
		ptr->SPI_CR2 &=~ (1<< SPI_CR2_SSOE );
	}
}

/*
 * @fn        - SPI_RecieveData
 * @brief     - It is used to receive data from phripheral
 * @param[in] -  Base address of SPI peripheral,data length
 * @return    -   none
 * @Note      -   none
 */

void SPI_RecieveData(SPI_Reg_Def_t *pSpix , uint8_t  *pRxBuffer,uint32_t Len)
{
	while(Len>0)
	{
		while(SPI_GetFlagStatus(pSpix,SPI_RXE_FLAG)== FLAG_RESET){};

			if(pSpix->SPI_CR1 & (1<<SPI_CR1_DFF))
			{
			*((uint16_t *)pRxBuffer) =pSpix->SPI_DR  ; // 16 bit data frame (uint16_t typecast ptxbuffer is 1byte and only copy 1 byte );
			Len--;
			Len--;
			(uint16_t*)pRxBuffer++;


			}
			else
			{
				(*pRxBuffer)=pSpix->SPI_DR ; // 8 bit data frame (uint16_t typecast ptxbuffer is 1byte and only copy 1 byte );
			    Len--;
			    pRxBuffer++;	//8 bit data frame
			}


	}
}

