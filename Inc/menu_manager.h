

#ifndef MENU_MANAGER_H_
#define MENU_MANAGER_H_

void keypad_config(void);
uint8_t keypad_scan();
void set_rtc_alrm1(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format);
void set_rtc_alrm2(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format);
void set_rtc_time(uint8_t hour,uint8_t minute,uint8_t seconds,uint8_t time_format);
void set_rtc_date(uint8_t day,uint8_t date,uint8_t month,uint8_t year);
void delay(uint32_t time);
void set_systick_timer(uint32_t value);
void rtc_lcd_int(void);

void menu_manager();

#endif /* MENU_MANAGER_H_ */
