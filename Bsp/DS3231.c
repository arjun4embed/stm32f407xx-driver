#include"DS3231.h"
#include "stm32f47xx.h"
#include<stdio.h>

static uint8_t get_reg_value(I2C_handle_t *pI2CHandle,uint8_t regaddr);
static uint8_t decimal_to_bcd(uint8_t value);
static void ds3231_write(I2C_handle_t *pI2CHandle,uint8_t value,uint8_t rtc_reg_addr);
static uint8_t ds3231_read(I2C_handle_t *pI2CHandle,uint8_t rtc_reg_addr);
static uint8_t bcd_to_decimal(uint8_t value);

void ds3231_set_time(I2C_handle_t *pI2CHandle,RTC_Time_t  *pTime)
{
    uint8_t hrs;
	// Seconds byte setting
    ds3231_write(pI2CHandle,decimal_to_bcd(pTime->seconds),DS3231_ADDR_SEC);

    //Minute byte setting
    ds3231_write(pI2CHandle,decimal_to_bcd(pTime->minutes),DS3231_ADDR_MIN);
    //Hour byte setting
    hrs=decimal_to_bcd(pTime->hours);
    if( pTime->time_format == TIME_FORMATS_24HRS)
    {
    	hrs &=~(1<<6);

    }
    else
    {
    	hrs |=1<<6;


    hrs |=	(pTime->time_format == TIME_FORMAT_12HRS_PM)? hrs|(1<<5) : hrs & ~(1<<5);
    }

    ds3231_write(pI2CHandle,hrs,DS3231_ADDR_HRS);



}
void ds3231_get_time(I2C_handle_t *pI2CHandle,RTC_Time_t  *pTime)
{
	pTime->seconds = ds3231_read(pI2CHandle,DS3231_ADDR_SEC);
	pTime->seconds = bcd_to_decimal(pTime->seconds);

	pTime->minutes = ds3231_read(pI2CHandle,DS3231_ADDR_MIN);
	pTime->minutes = bcd_to_decimal(pTime->minutes);

	pTime->hours  = ds3231_read(pI2CHandle,DS3231_ADDR_HRS);



	if(pTime->hours & ( 1 << 6)){

		pTime->time_format =  !((pTime->hours & ( 1 << 5)) == 0) ;
		pTime->hours &= ~(0x3 << 5);//Clear 6 and 5
		}else{
			//24 hr format
			pTime->time_format = TIME_FORMATS_24HRS;
		}

	pTime->hours = bcd_to_decimal(pTime->hours);

}

void ds3231_set_date(I2C_handle_t *pI2CHandle,RTC_Date_t *pdate)
{
	//Setting Day
	ds3231_write(pI2CHandle,decimal_to_bcd(pdate->day),DS3231_ADDR_DAY);

	ds3231_write(pI2CHandle,decimal_to_bcd(pdate->date),DS3231_ADDR_DATE);

	ds3231_write(pI2CHandle,decimal_to_bcd(pdate->month),DS3231_ADDR_MONTH);

	ds3231_write(pI2CHandle,decimal_to_bcd(pdate->year),DS3231_ADDR_YEAR);


}
void ds3231_get_date(I2C_handle_t *pI2CHandle,RTC_Date_t *pdate)
{

	pdate->day = bcd_to_decimal(ds3231_read(pI2CHandle,DS3231_ADDR_DAY));

	pdate->date = bcd_to_decimal(ds3231_read(pI2CHandle,DS3231_ADDR_DATE));

	pdate->month = bcd_to_decimal(ds3231_read(pI2CHandle,DS3231_ADDR_MONTH));

	pdate->year  = bcd_to_decimal(ds3231_read(pI2CHandle,DS3231_ADDR_YEAR));

}


static void ds3231_write(I2C_handle_t *pI2CHandle,uint8_t value,uint8_t rtc_reg_addr)
{
	uint8_t temp[2];
	temp[0]=rtc_reg_addr;
	temp[1]=value;
	I2C_MasterSendData(pI2CHandle->pI2Cx,temp,2,DS3231_I2C_ADDRESS,0);
}

static uint8_t ds3231_read(I2C_handle_t *pI2CHandle,uint8_t rtc_reg_addr)
{
	uint8_t pRxBuffer;
	I2C_MasterSendData(pI2CHandle->pI2Cx,&rtc_reg_addr,1,DS3231_I2C_ADDRESS,1);
	I2C_RecieveData(pI2CHandle,&pRxBuffer, 1,DS3231_I2C_ADDRESS, 0);
	return pRxBuffer;
}

static uint8_t bcd_to_decimal(uint8_t value)
{
	uint8_t h_nibble ,l_nibble;
	h_nibble = (value>>4)*10;
	l_nibble = value & (uint8_t)0xf;

	return h_nibble+l_nibble;
}

static uint8_t get_reg_value(I2C_handle_t *pI2CHandle,uint8_t regaddr)
{
	uint8_t pRxBuffer;
	I2C_MasterSendData(pI2CHandle->pI2Cx,(uint8_t*)regaddr,1,DS3231_I2C_ADDRESS,1);
	I2C_RecieveData(pI2CHandle,&pRxBuffer, 1,DS3231_I2C_ADDRESS, 0);
	return pRxBuffer;

}
static uint8_t decimal_to_bcd(uint8_t value)
{

	uint8_t h_nibble ,l_nibble;
	uint8_t bcd=value;
	if(value>=10)
	{
		h_nibble = value/10;
		l_nibble = value%10;
		bcd =h_nibble <<4;
		bcd |=l_nibble;
	}
	return bcd;

}
