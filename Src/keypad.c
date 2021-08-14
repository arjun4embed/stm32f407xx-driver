/* IMPLEMENTAION FOR 3X3 KEYPAD */


#include "stm32f47xx.h"



void keypad_config(void)
{

	GPIO_Handle_t switch1;

	switch1.pGPIOx = GPIOE;

	switch1.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PD;

	switch1.GPIO_PinConfig.GPIO_PinOPType =GPIO_OP_TYPE_PP;
   //FOR ROW
	switch1.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST ;
	switch1.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_OP;
	switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO7;
	GPIO_Init(&switch1);
	switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO8;
    GPIO_Init(&switch1);
    switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO9;
    GPIO_Init(&switch1);
  //For column
    switch1.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_IN;
    switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO10;
   	GPIO_Init(&switch1);
   	switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO11;
   	GPIO_Init(&switch1);
   	switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO12;
    GPIO_Init(&switch1);


}

uint8_t keypad_scan()
{


	GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO7,1);
	GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO8,0);
	GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO9,0);

	 if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO10) == 1)
	  {
		  return 1;
	  }
	  else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO11) == 1)
	  {
		  return 2;
	  }
	  else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO12) == 1)
	   {
	 	  return 3;
	   }

	   GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO7,0);
	   GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO8,1);
	   GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO9,0);

	  if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO10) == 1)
		{
		  return 4;
		}
	 else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO11) == 1)
		{
		  return 5;
		 }
	else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO12) == 1)
		 {
		 	 return 6;
		  }
		 GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO7,0);
		 GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO8,0);
		 GPIO_Write_Outputpin(GPIOE, GPIO_PIN_NO9,1);

	if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO10) == 1)
		 {
		 	 return 7;
		 }
	else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO11) == 1)
		 {
		 	  return 8;
		 }
	else if(GPIO_Read_InputPin(GPIOE, GPIO_PIN_NO12) == 1)
		 {
		 	 return 9;
		 }


 return 0;
}
