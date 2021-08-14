

#ifndef INC_STM32F407_USART_DRIVER_H_
#define INC_STM32F407_USART_DRIVER_H_

#include "stm32f47xx.h"



typedef struct
{


	uint32_t USART_Baud;
	uint8_t USART_Mode;
	uint8_t USART_NoOfStopbits;
	uint8_t USART_WordLength;
	uint8_t USART_ParityControl;
	uint8_t USART_HWFlowControl;


}USART_Config_t;



typedef struct
{

	USART_Reg_Def_t *pUSARTx;
	USART_Config_t USART_Config;

}USART_Handle_t;




#define USART_MODE_ONLY_TX    0
#define USART_MODE_ONLY_RX    1
#define USART_MODE_TXRX  2

#define  USART_WORDLENGTH_8bits 0
#define  USART_WORDLENGTH_9bits 1

#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200 				19200
#define USART_STD_BAUD_38400 				38400
#define USART_STD_BAUD_57600 				57600
#define USART_STD_BAUD_115200 				115200
#define USART_STD_BAUD_230400 				230400
#define USART_STD_BAUD_460800 				460800
#define USART_STD_BAUD_921600 				921600
#define USART_STD_BAUD_2M 					2000000
#define SUART_STD_BAUD_3M 					3000000

#define USART_PARITY_EN_ODD   2
#define USART_PARITY_EN_EVEN  1
#define USART_PARITY_DISABLE   0

#define USART_PARITY_EN_ODD   2
#define USART_PARITY_EN_EVEN  1
#define USART_PARITY_DISABLE   0


#define USART_STOPBITS_1     0
#define USART_STOPBITS_0_5   1
#define USART_STOPBITS_2     2
#define USART_STOPBITS_1_5   3

#define USART_HW_FLOW_CTRL_NONE    	0
#define USART_HW_FLOW_CTRL_CTS    	1
#define USART_HW_FLOW_CTRL_RTS    	2
#define USART_HW_FLOW_CTRL_CTS_RTS	3

#define USART_SR_PE    0
#define USART_SR_FE    1
#define USART_SR_NF    2
#define USART_SR_ORE   3
#define USART_SR_IDLE  4
#define USART_SR_RXNE  5
#define USART_SR_TC    6
#define USART_SR_TXE   7
#define USART_SR_LBD   8
#define USART_SR_CTS   9

#define USART_FLAG_TXE 1<<USART_SR_TXE
#define USART_FLAG_RXNE 1<<USART_SR_RXNE
#define USART_FLAG_TC 1<<USART_SR_TC


#define USART_CR1_SBK           0
#define USART_CR1_RWU           1
#define USART_CR1_RE            2
#define USART_CR1_TE           3
#define USART_CR1_IDLEIE        4
#define USART_CR1_RXNEIE        5
#define USART_CR1_TCIE         6
#define USART_CR1_TXEIE         7
#define USART_CR1_PEIE          8
#define USART_CR1_PS            9
#define USART_CR1_PCE           10
#define USART_CR1_WAKE          11
#define USART_CR1_M             12
#define USART_CR1_UE            13
#define USART_CR1_Reserved      14
#define USART_CR1_OVER8         15


#define USART_CR2_ADD        0
#define USART_CR2_Res        4
#define USART_CR2_LBDL       5
#define USART_CR2_LBDIE      6
#define USART_CR2_Res2        7
#define USART_CR2_LBCL       8
#define USART_CR2_CPHA      9
#define USART_CR2_CPOL      10
#define USART_CR2_CLKEN      11
#define USART_CR2_STOP       12
#define USART_CR2_LINEN      14

#define USART_CR3_EIE         0
#define USART_CR3_IREN        1
#define USART_CR3_IRLP        2
#define USART_CR3_HDSEL       3
#define USART_CR3_NACK        4
#define USART_CR3_SCEN        5
#define USART_CR3_DMAR        6
#define USART_CR3_DMAT        7
#define USART_CR3_RTSE        8
#define USART_CR3_CTSE        9
#define USART_CR3_CTSIE       10
#define USART_CR3_ONEBIT      11




uint32_t GetPCLKValue(uint8_t clock);

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

void USART_PeriClockControl(USART_Reg_Def_t *pUSARTx,uint8_t EnOrDi);
void USART_PeripheralControl(USART_Reg_Def_t *pUSARTx,uint8_t EnOrDi);
uint8_t USART_GetFlagStatus(USART_Reg_Def_t *pUSARTx,uint8_t StatusFlagName);
void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_Reg_Def_t *pUSARTx);
void USART_SendData(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len);
void USART_ReceiveData(USART_Handle_t  *pUSARTx, uint8_t *pRxBuffer, uint32_t Len);


void  USART_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority ,uint8_t EnorDi);
void USART_SetBaudRate(USART_Reg_Def_t *pUSARTx, uint32_t BaudRate);

#endif /* INC_STM32F407_USART_DRIVER_H_ */
