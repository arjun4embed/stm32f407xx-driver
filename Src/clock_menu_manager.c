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
extern I2C_handle_t I2C_1;
/* Different menu macro */
bool menu_mode=1,select_time=1,select_hour=1,select_minute=1,select_second=1,select_tf=1,select_mode=1,time_setting=1;
bool select_date=1,select_month=1,select_year=1,select_day=1;
bool alrm1_min=1,alrm1_hh=1,alrm1_ss,alrm1_ft=1;
bool alrm2_min=1,alrm2_hh=1,alrm2_ss,alrm2_ft=1;
uint8_t mode=0;
char days[]={"SUN MON TUE WED THU FRI SAT"};
void menu_manager()
{

	while(menu_mode);
	uint32_t *sysctrl = (uint32_t *)0xE000E010;
		*sysctrl  &=~(1<<SYSTICK_ENABLE);




page1:	              select_mode=1;
					select_time=1;
					select_hour=1;
					select_minute=1;
					select_second=1;

					select_time=select_hour=select_minute=select_second=select_tf=select_mode=time_setting=1;
					select_date=select_month=select_year=select_day=1;
					alrm1_min=alrm1_hh=1,alrm1_ss=alrm1_ft=1;
					alrm2_min=alrm2_hh=alrm2_ss=alrm2_ft=1;






				lcd_clear_display(I2C_1.pI2Cx);

	    	     lcd_set_cursor(1, 1, I2C_1.pI2Cx);

	    	     char display_content[20]="SET TIME";

	    	     for(int i=0;i<strlen(display_content);i++)
	    	     {
	    	     	Lcd_Send_Data(display_content[i],I2C_1.pI2Cx);
	    	     }
	    	     strcpy(display_content,"SET DATE");
	    	     lcd_set_cursor(2, 1, I2C_1.pI2Cx);
	    	     for(int i=0;i<strlen(display_content);i++)
	    	     {
	    	         Lcd_Send_Data(display_content[i],I2C_1.pI2Cx);
	    	     }
	    	     lcd_set_cursor(1, 13, I2C_1.pI2Cx);
	    	     Lcd_Send_Data('<', I2C_1.pI2Cx);
	    	     Lcd_Send_Data('-', I2C_1.pI2Cx);
	    	     mode=0;
  while(select_mode)
   {
        bool page2 = 1;
	    		  uint8_t temp = keypad_scan();




			  if( temp == 7)
			  {
				  mode=0;
				  lcd_set_cursor(1, 13, I2C_1.pI2Cx);
				  Lcd_Send_Data('<', I2C_1.pI2Cx);
				  Lcd_Send_Data('-', I2C_1.pI2Cx);
				  lcd_set_cursor(2, 13, I2C_1.pI2Cx);
				  Lcd_Send_Data(' ', I2C_1.pI2Cx);
				  lcd_set_cursor(2, 14, I2C_1.pI2Cx);
				  Lcd_Send_Data(' ', I2C_1.pI2Cx);
			  }
			  else if (temp == 1)
			  {
				  mode=1;
				  lcd_set_cursor(1, 13, I2C_1.pI2Cx);
				  Lcd_Send_Data(' ', I2C_1.pI2Cx);
				  Lcd_Send_Data(' ', I2C_1.pI2Cx);
				  lcd_set_cursor(2, 13, I2C_1.pI2Cx);
				  Lcd_Send_Data('<', I2C_1.pI2Cx);
				  Lcd_Send_Data('-', I2C_1.pI2Cx);
			  }


			  else if(temp == 8)
			  {

				  lcd_clear_display(I2C_1.pI2Cx);
				  lcd_set_cursor(1, 1, I2C_1.pI2Cx);
				  strcpy(display_content,"SET ALARM1");

				 for(int i=0;i<strlen(display_content);i++)
				 {
					Lcd_Send_Data(display_content[i],I2C_1.pI2Cx);
				 }

				 strcpy(display_content,"SET ALARM2");
				 lcd_set_cursor(2, 1, I2C_1.pI2Cx);

				 for(int i=0;i<strlen(display_content);i++)
				 {
					 Lcd_Send_Data(display_content[i],I2C_1.pI2Cx);
				 }

				 lcd_set_cursor(1, 13, I2C_1.pI2Cx);
				 Lcd_Send_Data('<', I2C_1.pI2Cx);
				 Lcd_Send_Data('-', I2C_1.pI2Cx);

				 mode =2;
				 while(page2)
				 {
					 temp = keypad_scan();
					 if( temp == 7)
					  {
							 mode =2;
						  lcd_set_cursor(1, 13, I2C_1.pI2Cx);
						  Lcd_Send_Data('<', I2C_1.pI2Cx);
						  Lcd_Send_Data('-', I2C_1.pI2Cx);
						  lcd_set_cursor(2, 13, I2C_1.pI2Cx);
						  Lcd_Send_Data(' ', I2C_1.pI2Cx);
						  lcd_set_cursor(2, 14, I2C_1.pI2Cx);
						  Lcd_Send_Data(' ', I2C_1.pI2Cx);
					  }
					  else if (temp == 1)
					  {
						   mode=3;
						  lcd_set_cursor(1, 13, I2C_1.pI2Cx);
						  Lcd_Send_Data(' ', I2C_1.pI2Cx);
						  Lcd_Send_Data(' ', I2C_1.pI2Cx);
						  lcd_set_cursor(2, 13, I2C_1.pI2Cx);
						  Lcd_Send_Data('<', I2C_1.pI2Cx);
						  Lcd_Send_Data('-', I2C_1.pI2Cx);
				      }

					  else if(temp ==8 )
					  {
						  page2=0;
						  temp=0;
						  goto page1;

					  }
					  else if(temp == 9)
					  {

						  select_mode =0;
						  page2=0;

					  }
              }

		}
					else if(temp == 9)
					{

					  select_mode =0;

					}

					else if(temp == 4)
					{

					  goto abort;


					}



  }
  if(mode == 0)
  {
	    	  lcd_clear_display(I2C_1.pI2Cx);
	    	  lcd_set_cursor(1, 1, I2C_1.pI2Cx);
	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	    	  lcd_set_cursor(1, 8, I2C_1.pI2Cx);
	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	    	  lcd_set_cursor(2, 1, I2C_1.pI2Cx);
	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	    	  lcd_set_cursor(2, 8, I2C_1.pI2Cx);
	    	  Lcd_Send_Data('T', I2C_1.pI2Cx);
			  Lcd_Send_Data('F', I2C_1.pI2Cx);
			  Lcd_Send_Data(' ', I2C_1.pI2Cx);
			  Lcd_Send_Data(':', I2C_1.pI2Cx);
			  Lcd_Send_Data('A', I2C_1.pI2Cx);
			  Lcd_Send_Data('M', I2C_1.pI2Cx);

	    	  lcd_set_cursor(1, 6, I2C_1.pI2Cx);
	    	signed  char hh=0,mm=0,ss=0,tf=0;

		  while(select_hour)
		  {


	              delay(50000);
	    		  uint8_t temp = keypad_scan();


	    		  if(temp == 7)
	    		  {
	    			  hh++;
	    			  hh=hh>0 ?hh:0;
	    			  hh %=13;
	    			  lcd_set_cursor(1, 5, I2C_1.pI2Cx);
	    			  Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
	    			  Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

	    		  }
	    		  else if(temp == 1)
	    		  {
	    		     	hh--;
	    		     	 hh=hh>0 && hh<60?hh:0;
	    		     	 hh%=13;
	    		        lcd_set_cursor(1, 5, I2C_1.pI2Cx);
	    		     	Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
	    		     	Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

	    		   }
	    		  else if(temp == 3)
	    		  {

	    			  select_hour =0;
	    			  temp=0;

	    		  }

	    		  else if(temp == 8)
	    		  {
	    			  temp =0;
	    			  select_mode =1;
	    			  goto page1;
	    		  }
  }

	    	  	  delay(100000);

			while( select_minute)
			{
	    	         delay(50000);
	    			 uint8_t temp = keypad_scan();


	    			 if(temp == 7)
	    			   {
	    			      mm++;
	    			      mm=mm>0 ?mm:0;
	    			      mm %=61;
	    			      lcd_set_cursor(2, 5, I2C_1.pI2Cx);
	    			      Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
	    			      Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

	    			    }
	    			  else if(temp == 1)
	    			    {
	    			      mm--;
	    			      mm=mm>0 ?mm:0;
	    			      mm %=61;
	    			      lcd_set_cursor(2, 5, I2C_1.pI2Cx);
	    			      Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
	    			      Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

	    			    }
	    			  else if(temp == 3)
					  {
					  select_minute =0;
					  temp=0;
	    		       }
	    			  else if(temp == 8)
					  {
						  temp=0;
						  select_mode =1;
						  goto page1;
					   }

}
	    		  delay(100000);

			while( select_second)
			 {
				delay(50000);
				uint8_t temp = keypad_scan();


			 if(temp == 7)
				   {
					ss++;
				  ss=ss>0 ?ss:0;
				  ss %=61;
				  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
				  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
				  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);

				}
		  else if(temp == 1)
				{
				  ss--;
				  ss=ss>0 ?ss:0;
				  ss %=61;
				  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
				  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
				  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);
				}
		  else if(temp == 3)
			    {
				  select_second =0;
				  temp=0;

			     }


	      else if(temp == 8)
			  {
				  temp=0;
				  select_mode =1;
				  goto page1;
			  }

}

	            delay(100000);
while( select_tf)
	 {
				delay(50000);
				uint8_t temp = keypad_scan();


				if(temp == 7)
			   {
					tf=0;
				  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
				  Lcd_Send_Data('A', I2C_1.pI2Cx);
				  Lcd_Send_Data('M', I2C_1.pI2Cx);

			   }
			  else if(temp == 1)
			   {
				  tf=1;
				  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
				  Lcd_Send_Data('P', I2C_1.pI2Cx);
				  Lcd_Send_Data('M', I2C_1.pI2Cx);
			   }
			  else if(temp == 3)
			  {
				  select_tf =0;
				  temp=0;
			  }

			  else if(temp == 8)
			  {
				  temp=0;
				  select_mode =1;
				  goto page1;
			  }


 }




	    set_rtc_time(hh, mm, ss, tf);




}


  if(mode == 1)
  {
	  lcd_clear_display(I2C_1.pI2Cx);
	  lcd_set_cursor(1, 1, I2C_1.pI2Cx);
	  Lcd_Send_Data('D', I2C_1.pI2Cx);
	  Lcd_Send_Data('D', I2C_1.pI2Cx);
	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  lcd_set_cursor(1, 8, I2C_1.pI2Cx);
	  Lcd_Send_Data('Y', I2C_1.pI2Cx);
	  Lcd_Send_Data('Y', I2C_1.pI2Cx);
	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  lcd_set_cursor(2, 1, I2C_1.pI2Cx);
	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  lcd_set_cursor(2, 8, I2C_1.pI2Cx);
	  Lcd_Send_Data('D', I2C_1.pI2Cx);
	  Lcd_Send_Data('A', I2C_1.pI2Cx);
	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	  Lcd_Send_Data('U', I2C_1.pI2Cx);
	  Lcd_Send_Data('N', I2C_1.pI2Cx);

	  lcd_set_cursor(1, 6, I2C_1.pI2Cx);
	 signed char dd=0,mm=0,yy=0,da=0;

	    while(select_date)
	    {


	  	               delay(50000);
	  	    		  uint8_t temp = keypad_scan();


	  	    		  if(temp == 7)
	  	    		  {
	  	    			  dd++;
	  	    			  dd=dd>0 ?dd:0;
	  	    			  lcd_set_cursor(1, 5, I2C_1.pI2Cx);
	  	    			  Lcd_Send_Data((dd/10)+48, I2C_1.pI2Cx);
	  	    			  Lcd_Send_Data((dd%10)+48, I2C_1.pI2Cx);

	  	    		  }
	  	    		  else if(temp == 1)
	  	    		  {
	  	    		     	dd--;
	  	    		     	 dd=dd>0 ?dd:0;
	  	    		        lcd_set_cursor(1, 5, I2C_1.pI2Cx);
	  	    		     	Lcd_Send_Data((dd/10)+48, I2C_1.pI2Cx);
	  	    		     	Lcd_Send_Data((dd%10)+48, I2C_1.pI2Cx);

	  	    		   }
	  	    		  else if(temp == 3)
	  	    		  {

	  	    			  select_date =0;
	  	    			  temp=0;

	  	    		  }

	  	    		  else if(temp == 8)
	  	    		  {
	  	    			  temp =0;
	  	    			  goto page1;
	  	    		  }

	    }

	  	    	  delay(100000);

	    while( select_month)
	    {
				 delay(50000);
				 uint8_t temp = keypad_scan();


				 if(temp == 7)
				   {
					  mm++;
					  mm=mm>0 ?mm:0;
					  mm %=32;
					  lcd_set_cursor(2, 5, I2C_1.pI2Cx);
					  Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
					  Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

					}
				  else if(temp == 1)
					{
					  mm--;
					  mm=mm>0?mm:0;
					  mm %=31;
					  lcd_set_cursor(2, 5, I2C_1.pI2Cx);
					  Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
					  Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

					}
				  else if(temp == 3)
				  {

					  select_month =0;
					  temp=0;
				   }
				  else if(temp == 8)
				  {
					  temp=0;
					  select_mode =1;
					  goto page1;

				  }

	  }
	  	    		  delay(100000);

	  while( select_year)
	  	 {
					delay(50000);
					uint8_t temp = keypad_scan();


					if(temp == 7)
				   {
						yy++;
					  yy=yy>0 ?yy:0;

					  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
					  Lcd_Send_Data((yy/10)+48, I2C_1.pI2Cx);
					  Lcd_Send_Data((yy%10)+48, I2C_1.pI2Cx);

					}
				  else if(temp == 1)
					{
					  yy--;
					  yy=yy>0 ?yy:0;
					  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
					  Lcd_Send_Data((yy/10)+48, I2C_1.pI2Cx);
					  Lcd_Send_Data((yy%10)+48, I2C_1.pI2Cx);
					}
				  else if(temp == 3)
				  {
					  select_year =0;
					  temp=0;
				  }


				  else if(temp == 8)
				  {
					  temp=0;
					  select_mode =1;
					  goto page1;
				  }

	  }

	  	            delay(100000);
	  while( select_day)
	  	 {
					delay(50000);
					uint8_t temp = keypad_scan();


			if(temp == 7)
		   {

			  da++;

			  da %=7;
			  da=da>0?da:0;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);


			Lcd_Send_Data(days[da*4],I2C_1.pI2Cx);
			Lcd_Send_Data(days[(da*4)+1], I2C_1.pI2Cx);
			Lcd_Send_Data(days[(da*4)+2], I2C_1.pI2Cx);

			}
		  else if(temp == 1)
			{
			  da--;

			  da %=7;
			  da=da>0?da:0;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);

			  Lcd_Send_Data(days[da*4],I2C_1.pI2Cx);
			  Lcd_Send_Data(days[(da*4)+1], I2C_1.pI2Cx);
			  Lcd_Send_Data(days[(da*4)+2], I2C_1.pI2Cx);
			}
		  else if(temp == 3)
			  {
				  select_day =0;
				  temp=0;
			  }

		  else if(temp == 8)
			  {
				  temp=0;
				  select_mode =1;
				  goto page1;
			  }


	   }




	 set_rtc_date(da,dd,mm,yy);





 }

  if(mode == 2)
    {


	  	    	  lcd_clear_display(I2C_1.pI2Cx);
	  	    	  lcd_set_cursor(1, 1, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(1, 8, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(2, 1, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(2, 8, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('T', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('F', I2C_1.pI2Cx);
	  			  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  			  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('A', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('M', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(1, 6, I2C_1.pI2Cx);
	  	    	signed  char hh=0,mm=0,ss=0,tf=0;

	  while(alrm1_hh)
	  {


			  delay(50000);
			  uint8_t temp = keypad_scan();


		  if(temp == 7)
		  {
			  hh++;
			  hh=hh>0 ?hh:0;
			  hh %=13;
			  lcd_set_cursor(1, 5, I2C_1.pI2Cx);
			  Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

		  }
		  else if(temp == 1)
		  {
				hh--;
				hh=hh>0 ?hh:0;
				hh%=13;
				lcd_set_cursor(1, 5, I2C_1.pI2Cx);
				Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
				Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

		   }
		  else if(temp == 3)
		  {

			     alrm1_hh =0;
			     temp=0;

		  }

		  else if(temp == 8)
		  {
			  temp =0;

			  goto page1;
		  }
}

	     delay(100000);

	while( alrm1_min)
	{
		 delay(50000);
		 uint8_t temp = keypad_scan();


		 if(temp == 7)
		   {
			  mm++;
			  mm=mm>0 ?mm:0;
			  mm %=61;
			  lcd_set_cursor(2, 5, I2C_1.pI2Cx);
			  Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

			}
		  else if(temp == 1)
			{
			   mm--;
			   mm=mm>0 ?mm:0;
			   mm %=61;
			   lcd_set_cursor(2, 5, I2C_1.pI2Cx);
			   Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
			   Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

			}
		  else if(temp == 3)
		  {
				alrm1_min =0;
				temp=0;

		  }
		  else if(temp == 8)
		  {
			  temp=0;

			  goto page1;
		  }

}
	  delay(100000);

	while( alrm1_ss)
	 {
			delay(50000);
			uint8_t temp = keypad_scan();


	 if(temp == 7)
		   {
			  ss++;
			  ss=ss>0 ?ss:0;
			  ss %=61;
			  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);

			}
	  else if(temp == 1)
			{
			  ss--;
			  ss=ss>0 ?ss:0;
			  ss %=61;
			  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);
			}
	  else if(temp == 3)
			{
			  alrm1_ss = 0;
			  temp=0;

			 }


	  else if(temp == 8)
		  {
			  temp=0;

			  goto page1;
		  }

}

	delay(100000);
while( alrm1_ft)
 {
		delay(50000);
		uint8_t temp = keypad_scan();


		if(temp == 7)
	   {
			  tf=0;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data('A', I2C_1.pI2Cx);
			  Lcd_Send_Data('M', I2C_1.pI2Cx);

	   }
	  else if(temp == 1)
	   {
			  tf=1;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data('P', I2C_1.pI2Cx);
			  Lcd_Send_Data('M', I2C_1.pI2Cx);
	   }
	  else if(temp == 3)
	  {
			  alrm1_ft = 0;
			  temp=0;
	  }

	  else if(temp == 8)
	  {
			  temp=0;

			  goto page1;
	  }


}
    set_rtc_alrm1(hh, mm, ss, tf);
	lcd_clear_display(I2C_1.pI2Cx);
}


  if(mode == 3)
   {

	  	    	  lcd_clear_display(I2C_1.pI2Cx);
	  	    	  lcd_set_cursor(1, 1, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('H', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(1, 8, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('S', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(2, 1, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('M', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('0', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(2, 8, I2C_1.pI2Cx);
	  	    	  Lcd_Send_Data('T', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('F', I2C_1.pI2Cx);
	  			  Lcd_Send_Data(' ', I2C_1.pI2Cx);
	  			  Lcd_Send_Data(':', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('A', I2C_1.pI2Cx);
	  			  Lcd_Send_Data('M', I2C_1.pI2Cx);

	  	    	  lcd_set_cursor(1, 6, I2C_1.pI2Cx);
	  	    	signed  char hh=0,mm=0,ss=0,tf=0;

  while(alrm2_hh)
  {


		  delay(50000);
		  uint8_t temp = keypad_scan();


	  if(temp == 7)
	  {
			  hh++;
			  hh=hh>0 ?hh:0;
			  hh %=13;
			  lcd_set_cursor(1, 5, I2C_1.pI2Cx);
			  Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

	  }
	  else if(temp == 1)
	  {
				hh--;
				hh=hh>0 && hh<60?hh:0;
				hh%=13;
				lcd_set_cursor(1, 5, I2C_1.pI2Cx);
				Lcd_Send_Data((hh/10)+48, I2C_1.pI2Cx);
				Lcd_Send_Data((hh%10)+48, I2C_1.pI2Cx);

	   }
	  else if(temp == 3)
	  {

				  alrm2_hh=0;
				  temp=0;

	  }

	  else if(temp == 8)
	  {
					  temp =0;
					  goto page1;

	  }
}

  delay(100000);

	while( alrm2_min)
	{
			 delay(50000);
			 uint8_t temp = keypad_scan();


		 if(temp == 7)
			 {
				  mm++;
				  mm=mm>0 ?mm:0;
				  mm %=61;
				  lcd_set_cursor(2, 5, I2C_1.pI2Cx);
				  Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
				  Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

			}
		  else if(temp == 1)
			{
				  mm--;
				  mm=mm>0 ?mm:0;
				  mm %=61;
				  lcd_set_cursor(2, 5, I2C_1.pI2Cx);
				  Lcd_Send_Data((mm/10)+48, I2C_1.pI2Cx);
				  Lcd_Send_Data((mm%10)+48, I2C_1.pI2Cx);

			}
			else if(temp == 3)
			 {
				alrm2_min=0;
				temp=0;

			 }
			 else if(temp == 8)
			 {
				  temp=0;
				  goto page1;
			 }

}
		  delay(100000);

while( alrm2_ss)
 {
		delay(50000);
		uint8_t temp = keypad_scan();


	 if(temp == 7)
	 	 {
			  ss++;
			  ss=ss>0 ?ss:0;
			  ss %=61;
			  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);

		}
	else if(temp == 1)
		{
			  ss--;
			  ss=ss>0 ?ss:0;
			  ss %=61;
			  lcd_set_cursor(1, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss/10)+48, I2C_1.pI2Cx);
			  Lcd_Send_Data((ss%10)+48, I2C_1.pI2Cx);
		}
	else if(temp == 3)
		{
			  alrm2_ss=0;
			  temp=0;

        }


	  else if(temp == 8)
		  {
			  temp=0;
			  select_mode =1;
			  goto page1;
		  }

}

	  	            delay(100000);
  while( alrm2_ft)
	 {
		delay(50000);
		uint8_t temp = keypad_scan();


		if(temp == 7)
	   {
			  tf=0;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data('A', I2C_1.pI2Cx);
			  Lcd_Send_Data('M', I2C_1.pI2Cx);

	   }
	  else if(temp == 1)
	   {
			  tf=1;
			  lcd_set_cursor(2, 12, I2C_1.pI2Cx);
			  Lcd_Send_Data('P', I2C_1.pI2Cx);
			  Lcd_Send_Data('M', I2C_1.pI2Cx);
	   }
	  else if(temp == 3)
	  {
			  alrm2_ft=0;
			  temp=0;
	  }

	  else if(temp == 8)
	  {
			  temp=0;
			  select_mode =1;
			  goto page1;
	  }


}




set_rtc_alrm2(hh, mm, ss, tf);






 }

 abort:       menu_mode=1;
			  lcd_clear_display(I2C_1.pI2Cx);
			  rtc_lcd_int();
			  *sysctrl  |=1<<SYSTICK_ENABLE;

}




