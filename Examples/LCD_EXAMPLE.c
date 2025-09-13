#define F_CPU 16000000UL
#undef __OPTIMIZE__
#include "lcd1602.h"

#define LCD_D0 A0
#define LCD_D1 A1
#define LCD_D2 A2
#define LCD_D3 A3
#define LCD_D4 A4
#define LCD_D5 A5
#define LCD_D6 A6
#define LCD_D7 A7
#define LCD_RS B1
#define LCD_E B2


keypad_3x3_t KEYPAD_1;
lcd1602_t LCD_1;

int main()
{
   LCD1602_INIT (&LCD_1,LCD_D7,LCD_D6,LCD_D5,LCD_D4,LCD_RS,LCD_E,TRUE,FALSE,FALSE);
   _delay_ms (10);
   
   LCD1602_STR (&LCD_1,"Hello!");
   LCD1602_CMD(&LCD_1,CMD_SHIFT_CURSOR_LEFT);
   LCD1602_CMD(&LCD_1,CMD_SHIFT_CURSOR_LEFT);
   _delay_ms (10);
   int i = 0;
   while(1)
   {
       if(i==16)
       {
           LCD1602_CMD(&LCD_1,CMD_RETURN_HOME);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_LEFT);
           i=0;
       }
       LCD1602_CMD(&LCD_1,CMD_SHIFT_DISPLAY_RIGHT);
       _delay_ms (250);
       i++;
   }
   
   return (EXIT_SUCCESS);
}