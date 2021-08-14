#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
#include "menu_manager.h"
#include "stm32f47xx.h"
#include "DS3231.h"
#include "LCD.h"
#define MY_ADDR            0x61
#define SlaveAddr          0x27
#define set_date            0
#define set_time            0

/*
 * Different flag for application
 */
extern bool menu_mode,select_time,select_hour,select_minute,select_second,select_tf,select_mode,time_setting;
extern bool select_date,select_month,select_year,select_day;
extern bool alrm1_min,alrm1_hh,alrm1_ss,alrm1_ft;
extern bool alrm2_min,alrm2_hh,alrm2_ss,alrm2_ft;
uint8_t alarm1_state = 1 ,alarm2_state =1;
 RTC_Time_t alarm1,alarm2;





I2C_handle_t I2C_1;

void delay(uint32_t time)
{
	int y=0;
	for(int i=0;i<=time;i++)
	{
		y++;
	}
}

/*
 * I2C Pin initialization
 */
void I2C1_Gpio_int(void)
{


    GPIO_Handle_t I2C_GPIO ;

    I2C_GPIO.pGPIOx=GPIOB;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinMode          =     GPIO_MODE_ALTFN;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinOPType        =     GPIO_OP_TYPE_OD;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinSpeed         =     GPIO_SPEED_FAST;

    I2C_GPIO.GPIO_PinConfig.GPIO_pinAltFunMode    =     ALTFN_04;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl   =     GPIO_NO_PUPD;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinNumber        =     GPIO_PIN_NO6;

    GPIO_Init(&I2C_GPIO); //Initializing SCL;

    I2C_GPIO.GPIO_PinConfig.GPIO_PinNumber        =     GPIO_PIN_NO9;

    GPIO_Init(&I2C_GPIO); //Initializing SDA;
}
/*
 * I2C Peripheral Initialization
 */
void I2C1_init(void)
{



	 I2C_1.pI2Cx=I2C1;

	 I2C_1.I2C_Config.I2C_ACKControl=I2C_ACK_ENABLE;

	 I2C_1.I2C_Config.I2C_SCLSpeed=I2C_SCL_SPEED_SM;

	 I2C_1.I2C_Config.I2C_DEVICEAddress=MY_ADDR;

	 I2C_1.I2C_Config.I2C_FMDutyCycle  =I2C_FM_DUTY2;

	 I2C_Init(&I2C_1);



}
/*
 * Switch initialization
 */
void switch_config(void)
{


	GPIO_Handle_t switch1;

	switch1.pGPIOx = GPIOA;

	switch1.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_IN;



	switch1.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PD;
	switch1.GPIO_PinConfig.GPIO_PinOPType =GPIO_OP_TYPE_PP;


	switch1.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST ;
    switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO0;
	GPIO_Init(&switch1);


}
/*
 * Interrupt pin configuration
 * @Note : Pin  is used to enter  menu mode
 */
void mode_interrupt(void)
{

	GPIO_Handle_t switch1;

	switch1.pGPIOx = GPIOA;

	switch1.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_IT_FT;

	switch1.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO1;

	switch1.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PU;
	switch1.GPIO_PinConfig.GPIO_PinOPType =GPIO_OP_TYPE_PP;

	switch1.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST ;

	GPIO_Init(&switch1);


}
int main()
{
   uint8_t display_data[] = "REAL TIME CLOCK";

   keypad_config();

   switch_config();

   I2C1_Gpio_int();

   mode_interrupt();

   I2C1_init();

   GPIO_IRQConfig(IRQ_NO_EXTI1 ,IRQ_PRIORITY_00,ENABLE);

    I2C_PeripheralControl(I2C_1.pI2Cx,ENABLE);

	I2C_Peripheral_ACK_Control(I2C_1.pI2Cx,ENABLE);

	I2C_lcd_int(I2C_1.pI2Cx);

	lcd_set_cursor(1, 1, I2C_1.pI2Cx);

	for(int i=0;i<9;i++)
		Lcd_Send_Data(display_data[i],I2C_1.pI2Cx);

	lcd_set_cursor(2, 1, I2C_1.pI2Cx);

	for(int i=9;i<strlen((char*)display_data);i++)
			Lcd_Send_Data(display_data[i],I2C_1.pI2Cx);

	delay(1000000);

     lcd_clear_display(I2C_1.pI2Cx);

     rtc_lcd_int();


	 set_systick_timer(1);

     while(1)
       {

	      menu_manager();

        }

}
void set_systick_timer(uint32_t value)
{

   uint32_t *sysctrl = (uint32_t *)0xE000E010;

   uint32_t *sysload = (uint32_t *)0xE000E014;

   uint32_t *sysval = (uint32_t *)0xE000E018;

   uint32_t load_value = (GetCLKValue(processor_clock)/value)-1;

   *sysload &= ~(0xFFFFFFFF); // clear

   *sysload |=load_value;

   *sysctrl  |=1<<SYSTICK_CLKSOURCE;

   *sysctrl  |=1<<SYSTICK_TICKINT;

   *sysctrl  |=1<<SYSTICK_ENABLE;


   (void )sysval;





}

void  SysTick_Handler(void)
{

			RTC_Time_t time;

			ds3231_get_time(&I2C_1,&time);

			// For every 1 second ,Seconds position in lcd display is updated .

			lcd_set_cursor(1,7,I2C_1.pI2Cx);

			Lcd_Send_Data((time.seconds/10)+48,I2C_1.pI2Cx);

			Lcd_Send_Data((time.seconds%10)+48,I2C_1.pI2Cx);

			if(time.seconds == 00)
				{
						lcd_set_cursor(1,4,I2C1);

						Lcd_Send_Data((time.minutes/10)+48,I2C_1.pI2Cx);

						Lcd_Send_Data((time.minutes%10)+48,I2C_1.pI2Cx);

				}
			// If seconds = 0 minutes position in lcd display is updated

			if(time.minutes == 00)
				{
						lcd_set_cursor(1,0,I2C_1.pI2Cx);

						Lcd_Send_Data((time.hours/10)+48,I2C_1.pI2Cx);

						Lcd_Send_Data((time.hours%10)+48,I2C_1.pI2Cx);

						lcd_set_cursor(1,10,I2C_1.pI2Cx);
			// If minutes = 0 ,hour  position in lcd display is updated

			if(time.time_format == TIME_FORMAT_12HRS_AM)
				{
						Lcd_Send_Data('A',I2C_1.pI2Cx);

						Lcd_Send_Data('M',I2C_1.pI2Cx);


				}
			else if(time.time_format == TIME_FORMAT_12HRS_PM)
			    {

						Lcd_Send_Data('P',I2C_1.pI2Cx);

						Lcd_Send_Data('M',I2C_1.pI2Cx);

		        }

				}

				if(time.hours == 12)
				{

					RTC_Date_t date;

					ds3231_get_date(&I2C_1, &date);
					lcd_set_cursor(2,1,I2C_1.pI2Cx);

					Lcd_Send_Data((date.date/10)+48,I2C_1.pI2Cx);

					Lcd_Send_Data((date.date%10)+48,I2C_1.pI2Cx);

					Lcd_Send_Data('/',I2C_1.pI2Cx);

					Lcd_Send_Data((date.month/10)+48,I2C_1.pI2Cx);

					Lcd_Send_Data((date.month%10)+48,I2C_1.pI2Cx);

					Lcd_Send_Data('/',I2C_1.pI2Cx);

					Lcd_Send_Data((date.year/10)+48,I2C_1.pI2Cx);

					Lcd_Send_Data((date.year%10)+48,I2C_1.pI2Cx);






				}


		if(time.hours == alarm1.hours && time.minutes == alarm1.minutes && time.seconds == alarm1.seconds && time.time_format == alarm1.time_format && alarm1_state)
		{
			uint32_t *sysctrl = (uint32_t *)0xE000E010;

			 *sysctrl  &=~(1<<SYSTICK_ENABLE);

			lcd_clear_display(I2C_1.pI2Cx);

			lcd_set_cursor(1, 4, I2C_1.pI2Cx);

			char display[]={'A','L','A','R','M','-','1'};
			for(int i=0;i<7;i++)
			{
			Lcd_Send_Data(display[i],I2C_1.pI2Cx);
			}
			while(alarm1_state)
			{
				alarm1_state =!(GPIO_Read_InputPin(GPIOA,GPIO_PIN_NO0));
			}
			lcd_clear_display(I2C_1.pI2Cx);

			rtc_lcd_int();

			*sysctrl  |=1<<SYSTICK_ENABLE;
		}

		if(time.hours == alarm2.hours && time.minutes == alarm2.minutes && time.seconds == alarm2.seconds && time.time_format == alarm2.time_format && alarm2_state)
			{
				uint32_t *sysctrl = (uint32_t *)0xE000E010;

				*sysctrl  &=~(1<<SYSTICK_ENABLE);

				lcd_clear_display(I2C_1.pI2Cx);

				lcd_set_cursor(1, 4, I2C_1.pI2Cx);

				char display[]={'A','L','A','R','M','-','2'};
				for(int i=0;i<7;i++)
				{
				Lcd_Send_Data(display[i],I2C_1.pI2Cx);
				}
				while(alarm2_state)
				{
					alarm2_state =!(GPIO_Read_InputPin(GPIOA,GPIO_PIN_NO0));
				}
				lcd_clear_display(I2C_1.pI2Cx);
				rtc_lcd_int();
				 *sysctrl  |=1<<SYSTICK_ENABLE;
			}
}

void rtc_lcd_int(void)
{
	RTC_Time_t time;

	ds3231_get_time(&I2C_1,&time);

	//Displaying hour
	Lcd_Send_Data((time.hours/10)+48,I2C_1.pI2Cx);

	Lcd_Send_Data((time.hours%10)+48,I2C_1.pI2Cx);

    //Displaying minutes
	Lcd_Send_Data(':',I2C_1.pI2Cx);

	Lcd_Send_Data((time.minutes/10)+48,I2C_1.pI2Cx);

	Lcd_Send_Data((time.minutes%10)+48,I2C_1.pI2Cx);

	//Displaying seconds
	Lcd_Send_Data(':',I2C_1.pI2Cx);

	Lcd_Send_Data((time.seconds/10)+48,I2C_1.pI2Cx);

	Lcd_Send_Data((time.seconds%10)+48,I2C_1.pI2Cx);

	Lcd_Send_Data(' ',I2C_1.pI2Cx);

	if(time.time_format == TIME_FORMAT_12HRS_AM)
	  {

		Lcd_Send_Data('A',I2C_1.pI2Cx);

		Lcd_Send_Data('M',I2C_1.pI2Cx);


	  }
	else if(time.time_format == TIME_FORMAT_12HRS_PM)
	 {

	  	Lcd_Send_Data('P',I2C_1.pI2Cx);

	    Lcd_Send_Data('M',I2C_1.pI2Cx);

	}

	RTC_Date_t date;

			    ds3231_get_date(&I2C_1, &date);

			    lcd_set_cursor(2,1,I2C_1.pI2Cx);

			    Lcd_Send_Data((date.date/10)+48,I2C_1.pI2Cx);

			    Lcd_Send_Data((date.date%10)+48,I2C_1.pI2Cx);

			    Lcd_Send_Data('/',I2C_1.pI2Cx);


			    Lcd_Send_Data((date.month/10)+48,I2C_1.pI2Cx);

			    Lcd_Send_Data((date.month%10)+48,I2C_1.pI2Cx);

			    Lcd_Send_Data('/',I2C_1.pI2Cx);

			    Lcd_Send_Data((date.year/10)+48,I2C_1.pI2Cx);

			    Lcd_Send_Data((date.year%10)+48,I2C_1.pI2Cx);


}


void set_rtc_alrm1(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format)

{
    alarm1.hours = hour;
	alarm1.minutes=minute;
	alarm1.seconds = seconds;
	alarm1.time_format =time_format;
}
void set_rtc_alrm2(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format)

{
    alarm2.hours = hour;
	alarm2.minutes=minute;
	alarm2.seconds = seconds;
	alarm2.time_format =time_format;
}


void set_rtc_time(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format)
{
   RTC_Time_t time;
   time.hours      = hour;
   time.minutes    = minute;
   time.seconds     = seconds;
   time.time_format = time_format;
   ds3231_set_time(&I2C_1,&time);
}
void set_rtc_date(uint8_t day,uint8_t date,uint8_t month,uint8_t year)
{
   RTC_Date_t   pdate;

   pdate.date =  date;
   pdate.month = month;
   pdate.day   = day;
   pdate.year  = year;
   ds3231_set_date(&I2C_1,&pdate);
}

void EXTI1_IRQHandler(void)
{


menu_mode = 0;


GPIO_IRQHandling(IRQ_NO_EXTI1);


}


