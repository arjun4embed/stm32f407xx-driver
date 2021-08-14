#include"stm32f47xx.h"
#include "LCD.h"


static void delay(uint32_t k)
{
	uint32_t j;
	for(int i=0;i<=k;i++)
	{
		j++;
	}
}
void Lcd_Send_Command(uint8_t data,I2C_Reg_Def_t *pI2c)
{
	lcd_t lcd;
	uint8_t temp =  data;
	lcd.Lcd_Data=(temp &0xF0);
	lcd.port_t.Register_Select =0;
	lcd.port_t.X=1;
	lcd.port_t.Read_write=0;
	lcd.port_t.Enable=1;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,1);
	delay(5000);
	lcd.port_t.Enable=0;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,1);
	delay(5000);
	lcd.Lcd_Data=(temp &0x0F)<<4;
    lcd.port_t.Register_Select =0;
    lcd.port_t.X=1;
	lcd.port_t.Enable=1;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,1);
	delay(5000);
	lcd.port_t.Enable=0;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,1);
	delay(5000);



}
void Lcd_Send_Data(uint8_t data,I2C_Reg_Def_t *pI2c)
{
	lcd_t lcd;

	uint8_t temp =  data;
	lcd.Lcd_Data=(temp &0xF0);
	lcd.port_t.Register_Select =1;
	lcd.port_t.X=1;
	lcd.port_t.Read_write=0;
	lcd.port_t.Enable=1;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,0);
	delay(10000);
	lcd.port_t.Enable=0;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,0);
	delay(10000);
	lcd.Lcd_Data=(temp &0x0F)<<4;
	lcd.port_t.Register_Select =1;
	lcd.port_t.X=1;
	lcd.port_t.Enable=1;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,0);
	delay(10000);
	lcd.port_t.Enable=0;
	I2C_MasterSendData(pI2c,&lcd.Lcd_Data,1,I2C_LCD_ADDR,0);
	delay(10000);
	data++;



}
void lcd_set_cursor(uint8_t row, uint8_t column,I2C_Reg_Def_t *pI2c)
{
  column--;
  switch (row)
  {
    case 1:

    	Lcd_Send_Command((column |= 0x80),pI2c);
      break;
    case 2:

    	Lcd_Send_Command((column |= 0xC0),pI2c);
      break;
    default:
      break;
  }
}
void lcd_clear_display(I2C_Reg_Def_t *pI2c)
{
	Lcd_Send_Command(0x1,pI2c);
}
void I2C_lcd_int(I2C_Reg_Def_t *pI2c)
{
	delay(1000);
	char init_cmd[]={0x28,0x02,0x0C,0X01,0X06,0x80};//INT command
    for(int i=0;i<6;i++)
	 {
		Lcd_Send_Command(init_cmd[i],I2C1);

	 }
}
