

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "stm32f47xx.h"

typedef struct
{
	uint8_t Spi_Device_Mode;  // @Device_mode
	uint8_t Spi_Bus_Config;
	uint8_t Spi_DFF;
	uint8_t Spi_Cpha;
	uint8_t Spi_Cpol;
	uint8_t Spi_ssm;
	uint8_t Spi_Sclk_Speed;
}Spi_config_t;

typedef struct
{    SPI_Reg_Def_t *pSpix;
	Spi_config_t Spiconfig;
}Spi_handle_t;


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/


void  SPI_PCLKControl(SPI_Reg_Def_t *pSpix,uint8_t EnorDi);
void  SPI_Init(Spi_handle_t *pSpiHandle);
void  SPI_Denit(Spi_handle_t *pSpiHandle);
void  SPI_SendData(SPI_Reg_Def_t *pSpix ,uint8_t *pTxBuffer,uint32_t Len);
void  SPI_RecieveData(SPI_Reg_Def_t *pSpix ,uint8_t *pTxBuffer,uint32_t Len);
void  SPI_IRQPriorityConfig(uint8_t IRQNumber , uint8_t IRQPriority);
void  SPI_IRQHandling(Spi_handle_t *pHandle);
void  SPI_PeripheralControl(SPI_Reg_Def_t *ptr,uint8_t EnoDi);
void SPI_SSIConfig(SPI_Reg_Def_t *ptr,uint8_t EnoDi);
void SPI_SSOEConfig(SPI_Reg_Def_t *ptr,uint8_t EnoDi);



/*
 * @Device_mode
 */
#define  SPI_DEVICE_MODE_MASTER 1
#define  SPI_DEVICE_MODE_SLAVE 0

/*
 * @Bus_config
 */
#define SPI_BUS_CONFIG_FD                  1
#define SPI_BUS_CONFIG_HD                  2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY      3

/*
 * @SPI_SCLKSpeed
 */
#define SPI_SCLK_SPEED_DIV_2               0
#define SPI_SCLK_SPEED_DIV_4               1
#define SPI_SCLK_SPEED_DIV_8               2
#define SPI_SCLK_SPEED_DIV_16              3
#define SPI_SCLK_SPEED_DIV_32              4
#define SPI_SCLK_SPEED_DIV_64              5
#define SPI_SCLK_SPEED_DIV_128             6
#define SPI_SCLK_SPEED_DIV_256             7
/*
 * @SPI_DFF
 */
#define SPI_DIFF_8BITS   0
#define SPI_DIFF_16BITS  1
/*
 * @CPOL
 */
#define SPI_CPOL_HIGH     1
#define SPI_CPOL_LOW      0

/*
 * @CPHL
 */
#define SPI_CPHL_HIGH     1
#define SPI_CPHL_LOW      0

/*
 *  @SPI_SSM
 */
#define SPI_SSM_EN      1
#define SPI_SSM_DI      0


/*
 * Bit position
 */
#define   SPI_CR1_CPHA         0
#define   SPI_CR1_CPOL         1
#define   SPI_CR1_MSTR         2
#define   SPI_CR1_BR           3
#define   SPI_CR1_SPE          6
#define   SPI_CR1_LSBFIRST     7
#define   SPI_CR1_SSI          8
#define   SPI_CR1_SSM          9
#define   SPI_CR1_RXONLY       10
#define   SPI_CR1_DFF          11
#define   SPI_CR1_CRCNEXT      12
#define   SPI_CR1_CRCEN        13
#define   SPI_CR1_BIDIOE       14
#define   SPI_CR1_BIDIMODE     15


#define   SPI_CR2_RXDMAEN      0
#define   SPI_CR2_TXDMAEN      1
#define   SPI_CR2_SSOE         2
#define   Reserved             3
#define   SPI_CR2_FRF          4
#define   SPI_CR2_ERRIE        5
#define   SPI_CR2_RXNEIE       6
#define   SPI_CR2_TXEIE        7

#define   SPI_SR_RXNE          0
#define   SPI_SR_TXE           1
#define   SPI_SR_CHSIDE        2
#define   SPI_SR_UDR           3
#define   SPI_SR_CRCERR        4
#define   SPI_SR_MODF          5
#define   SPI_SR_OVR           6
#define   SPI_SR_BSY           7
#define   SPI_SR_FRE           8


#define  RX_BUFFER_EMPTY      0
#define  RX_BUFFER_NOT_EMPTY  1

#define  TX_BUFFER_EMPTY      1
#define  TX_BUFFER_NOT_EMPTY  0

#define  SPI_TXE_FLAG         (1<<SPI_SR_TXE)
#define  SPI_RXE_FLAG         (1<<SPI_SR_RXNE)
#define  SPI_BUSY_FLAG        (1<<SPI_SR_BSY)
#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
