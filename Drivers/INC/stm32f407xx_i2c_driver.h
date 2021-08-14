

#ifndef INC_STM32F407XX_I2C_DRIVER_H_
#define INC_STM32F407XX_I2C_DRIVER_H_
#include "stm32f47xx.h"

typedef struct
{
	uint32_t I2C_SCLSpeed;
	uint8_t I2C_DEVICEAddress;
	uint8_t I2C_ACKControl;
	uint8_t I2C_FMDutyCycle;

}I2C_Config_t;
typedef struct
{
	I2C_Reg_Def_t *pI2Cx;
	I2C_Config_t   I2C_Config;



}	I2C_handle_t;

#define I2C_READY         0
#define I2C_BUSY_IN_RX   1
#define I2C_BUSY_IN_TX   2

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

void  I2C_PCLKControl(I2C_Reg_Def_t *pI2Cx,uint8_t EnorDi);
void  I2C_Init(I2C_handle_t *pI2CHandle);
void  I2C_Denit(I2C_handle_t *pI2CHandle);
void  I2C_RecieveData(I2C_handle_t *pI2CHandle,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);
void  I2C_MasterSendData(I2C_Reg_Def_t *pI2Cx ,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);
void  I2C_PeripheralControl(I2C_Reg_Def_t *ptr,uint8_t EnoDi);
void I2C_Peripheral_ACK_Control(I2C_Reg_Def_t *ptr,uint8_t EnoDi);
uint8_t I2C_GetFlagStatus(I2C_Reg_Def_t *pI2Cx,uint8_t FlagName);




#define I2C_DISABLE_SR    0
#define I2C_ENABLE_SR    1

/*
 * @I2C_SCLSpeed
 */
#define  I2C_SCL_SPEED_SM    100000
#define  I2C_SCL_SPEED_FM2K  200000
#define  I2C_SCL_SPEED_FM4K  400000

/*
 * @I2C_ACKControl
 */
#define I2C_ACK_ENABLE      1
#define I2C_ACK_DISABLE     0

/*
 * I2C_FMDutyCycle
 */
#define  I2C_FM_DUTY2        0
#define  I2C_FM_DUTY_16_9    1

/*
 *I2C Related status  definition
 */
#define  I2C_FLAG_TXE          (1<<TxE )
#define  I2C_FLAG_RXNE          (1<<RXNE)
#define  I2C_FLAG_SB           (1<< SB)
#define  I2C_FLAG_BERR         (1<<BERR)
#define  I2C_FLAG_ARLO         (1<<ARLO)
#define  I2C_FLAG_AF           (1<<AF)
#define  I2C_FLAG_OVR          (1<<OVR)
#define  I2C_FLAG_TIMEOUT      (1<<TIMEOUT)
#define  I2C_FLAG_ADDR         (1<<ADDR)
#define  I2C_FLAG_BTF          (1<<BTF)



/*
 * I2C_CR1_Macros
 */
#define PE        0
#define SMBUS     1
#define SMBTYPE   3
#define ENARP     4
#define ENPEC     5
#define ENGC      6
#define NOSTRETCH 7
#define START     8
#define STOP      9
#define ACK       10
#define POS       11
#define PEC_CR1   12
#define ALERT     13
#define SWRST     15
/*
 * I2C_CR2_Macros
 */
#define FREQ        0
#define ITERREN     8
#define ITEVTEN     9
#define ITBUFEN     10
#define DMAEN       11
#define LAST        12

/*
 * I2C_SR1_Macros
 */

#define  SB         0
#define  ADDR       1
#define  BTF        2
#define  ADD10      3
#define  STOPF      4
#define  RXNE       6
#define  TxE        7
#define  BERR       8
#define  ARLO       9
#define  AF         10
#define  OVR        11
#define  PECERR     12
#define  TIMEOUT    14
#define  SMBALERT   15
/*
 * I2C_SR2_Macros
 */
#define  MSL             0
#define  BUSY            1
#define  TRA             2
#define  GENCALL         4
#define  SMBDEFAULT      5
#define  SMBHOST         6
#define  DUALF           7
#define  PEC             8
/*
 * I2C_CCR_Macros
 */

#define CCR      0
#define DUTY     14
#define FS       15
#define REPEAT_START  RESET
#define REPEAT_STOP          SET





#endif /* INC_STM32F407XX_I2C_DRIVER_H_ */
