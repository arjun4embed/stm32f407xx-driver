

#ifndef LCD_H_
#define LCD_H_

#define I2C_LCD_ADDR   0X27
void lcd_set_cursor(uint8_t row, uint8_t column,I2C_Reg_Def_t *pI2c);
typedef union
{
	struct
	{
	uint8_t     Register_Select:1;
	uint8_t     Read_write:1;
	uint8_t     Enable:1;
	uint8_t     X:1;
	uint8_t     Data_0:1;
	uint8_t     Data_1:1;
	uint8_t     Data_2:1;
	uint8_t     Data_3:1;
	}port_t;
   uint8_t     Lcd_Data;

}lcd_t ;



void I2C_lcd_int(I2C_Reg_Def_t *pI2c);
void Lcd_Send_Data(uint8_t data,I2C_Reg_Def_t *pI2c);
void Lcd_Send_Command(uint8_t data,I2C_Reg_Def_t *pI2c);
void lcd_clear_display(I2C_Reg_Def_t *pI2c);
#endif /* LCD_H_ */
