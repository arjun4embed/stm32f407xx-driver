# STM32F407XX DRIVER
Bare metal driver implemenation for stm32f407g peripherals 
## Implemented  Drivers
- GPIO
- SPI
- I2C
- UART
## IDE setup
- In your IDE, include  startup_stm32f407vgtx

## Driver description
 ###  GPIO
 - User configurable items is configured using GPIO_PinConfig_t structure
         
         typedef struct          
        {
        
         uint8_t GPIO_PinNumber;
         uint8_t GPIO_PinMode;
         uint8_t GPIO_PinSpeed;
         uint8_t GPIO_PinPuPdControl;
         uint8_t GPIO_PinOPType;
         uint8_t GPIO_pinAltFunMode;

        }GPIO_PinConfig_t;
 - Handle structure is used to intialize gpio pheripheral 
 
            typedef struct                      
           {
           
             Gpio_RegDef_t *pGPIOx;
             GPIO_PinConfig_t GPIO_PinConfig;
             
           }GPIO_Handle_t ;
 ### SPI
   - User configurable items is configured using Spi_config_t structure
        
           typedef struct
         {
         
          uint8_t Spi_Device_Mode;  
          uint8_t Spi_Bus_Config;
          uint8_t Spi_DFF;
          uint8_t Spi_Cpha;
          uint8_t Spi_Cpol;
          uint8_t Spi_ssm;
          uint8_t Spi_Sclk_Speed;
          
         }Spi_config_t;
 - Handle structure is used to intialize SPI pheripheral 
         
         typedef struct
         {    
         
          SPI_Reg_Def_t *pSpix;
          Spi_config_t Spiconfig;
          
         }Spi_handle_t;
         
         
### I2C
   - User configurable items is configured using I2C_Config_t structure
        
          typedef struct
           {
           
            uint32_t I2C_SCLSpeed;
            uint8_t I2C_DEVICEAddress;
            uint8_t I2C_ACKControl;
            uint8_t I2C_FMDutyCycle;

           }I2C_Config_t;
 - Handle structure is used to intialize SPI pheripheral 
         
         typedef struct
         {
         
          I2C_Reg_Def_t *pI2Cx;
          I2C_Config_t   I2C_Config;
          
          }	I2C_handle_t;
          

### USART
   - User configurable items is configured using USART_Config_t structure
        
          typedef struct
          {
         
           uint32_t USART_Baud;
           uint8_t USART_Mode;
           uint8_t USART_NoOfStopbits;
           uint8_t USART_WordLength;
           uint8_t USART_ParityControl;
           uint8_t USART_HWFlowControl;
   
         }USART_Config_t;
 - Handle structure is used to intialize USART pheripheral 
         
          typedef struct
          {
         
            I2C_Reg_Def_t *pI2Cx;
            I2C_Config_t   I2C_Config;
          
          }	I2C_handle_t;
     

## Steps to use driver
 1. Configure user configurable items in config structure
 2. Configure Handle structure 
 3. Call Init API for respective peripheral 

      

       
