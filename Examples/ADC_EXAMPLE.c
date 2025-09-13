#include "ADC.h"
#include "DIO.h"
#include "lm35.h"
#include "lcd1602.h"
#include "keypad_3x3.h"
#include <util/delay.h>

float current_reading;
void read_temp()
{
    current_reading = LM35_READ()*5/1024;
}

int main()
{
   float temperature[4];
   int i=0;
   lm35_t temperature_sensor[4]={ADC0,ADC1,ADC2,ADC3};
   lcd1602_t LCD_1;
   keypad_3x3_t KEY_1;
   KEYPAD_3X3_INIT (&KEY_1,C3,C4,C5,C0,C1,C2,TRUE);
   LCD1602_INIT (&LCD_1,B0,B1,B2,B3,B4,B5,FALSE,FALSE,FALSE);
   ADC_INIT (VREF_AVCC,A0,read_temp,ADC_PS_MIN,FALSE);
   sei();
   
   while(1)
   {
       int temp = KEYPAD_3X3_READ (&KEY_1);
       _delay_ms(500);
       if(temp==6)
           i = (i+1)%4;
       
       if(temp == 4)
       {
           if(i==0)
               i = 3;
           else 
               i--;
       }
       
       LCD1602_INT(&LCD_1,i);

        LM35_SAMPLE (temperature_sensor[i]);
        LCD1602_CMD (&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
        LCD1602_STR(&LCD_1,"SENSOR NO.");
        LCD1602_INT(&LCD_1,i+1);
        temperature[i] = current_reading;
        LCD1602_CHAR (&LCD_1,' ');
        LCD1602_INT(&LCD_1,temperature[i]);
   }
}