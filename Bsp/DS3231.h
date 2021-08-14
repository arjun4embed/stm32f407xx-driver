#ifndef DS3231_H_
#define DS3231_H_

#include "stm32f47xx.h"


/* DS231 Device Address*/

#define DS3231_I2C_ADDRESS   0X68


/* DS3231 Adrdress Word */

#define   DS3231_ADDR_SEC           0X0
#define	  DS3231_ADDR_MIN           0x1
#define   DS3231_ADDR_HRS       	0x2
#define   DS3231_ADDR_DAY        	0x3
#define	  DS3231_ADDR_DATE     		0x4
#define   DS3231_ADDR_MONTH      	0x5
#define   DS3231_ADDR_YEAR       	0x6
#define	  DS3231_ADDR_ALRM1_SEC  	0x7
#define   DS3231_ADDR_ALRM1_MIN     0x8
#define   DS3231_ADDR_ALRM1_HRS     0x9
#define	  DS3231_ADDR_ALRM1_DAY     0x0A
#define   DS3231_ADDR_ALRM2_MIN		0X0B
#define   DS3231_ADDR_ALRM2_HRS     0X0C
#define	  DS3231_ADDR_ALRM2_DAY   	0X0D
#define   DS3231_ADDR_CONTROL 		0X0E
#define   DS3231_ADDR_STATUS			0X0F
#define   DS3231_ADDR_AGING_OFFSET	0X10
#define   DS3231_ADDR_MSB_TEMP		0X11
#define   DS3231_ADDR_LSB_TEMP		0X12

/*DS3231 CONTRO REGISTER & STAUS REGISTER MACROS*/

#define A1IE  0
#define A2IE  1
#define INTCN 2
#define RS1   3
#define RS2   4
#define CONV  5
#define BBSQW 6
#define EOSC  7

#define A1F       0
#define A2F       1
#define BSY       2
#define EN32kHz   3
#define OSF       7




#define	  TIME_FORMAT_12HRS_AM   0
#define	  TIME_FORMAT_12HRS_PM   1
#define   TIME_FORMATS_24HRS     2


#define   SUNDAY              1
#define   MONDAY              2
#define   TUESDAY             3
#define   WEDNESDAY           4
#define   THURSDAY            5
#define   FRIDAY              6
#define   SATURDAY            7


#define  DS3231_I2C             I2C1

#define DATE__HH_MM_SS_MATHCED  0
#define HOUR_MIN_SEC_MATCHED    1
#define MIN_SEC_MATCHED         2
#define SEC_MATCHED             3
#define ONCE_PER_SECOND         4


typedef struct
{
	uint8_t date;
	uint8_t month;
	uint8_t year;
	uint8_t day;

}RTC_Date_t;

typedef struct
{
	uint8_t  seconds;
	uint8_t  minutes;
	uint8_t  hours;
	uint8_t  time_format;
}RTC_Time_t;

typedef struct
{
	uint8_t  seconds;
	uint8_t  minutes;
	uint8_t  hours;
	uint8_t  time_format;
	uint8_t  date;
	uint8_t  mode;
}RTC_Alarm_Time_t;

/*   Implemented API */

void ds3231_get_time(I2C_handle_t *pI2CHandle,RTC_Time_t  *pTime);
void ds3231_set_time(I2C_handle_t *pI2CHandle,RTC_Time_t  *pTime);
void ds3231_get_date(I2C_handle_t *pI2CHandle,RTC_Date_t *pdate);
void ds3231_set_date(I2C_handle_t *pI2CHandle,RTC_Date_t *pdate);
void ds3231_set_alarm1(I2C_handle_t *pI2CHandle,RTC_Alarm_Time_t  *pTime,uint8_t mode);

#endif /* DS3231_H_ */
