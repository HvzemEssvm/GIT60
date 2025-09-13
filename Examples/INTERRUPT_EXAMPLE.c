#include "DIO.h"
#include "INTERRUPT.h"
#include <stdio.h>
#include <stdlib.h>
#include <avr//io.h>
#include <util/delay.h>

#include "seg_7.h"
#include "keypad_3x3.h"
#include "lcd1602.h"
#include "led.h"

led_t led_1;

void handlebtn()
{
  LED_TOGGLE (&led_1); 
}

int main()
{
   LED_INIT (&led_1,B1);
   INTERRUPT_ENABLE (INT0,CHANGE,handlebtn);
   LED_ON(&led_1);
   _delay_ms(10);
   while(1);
   return (EXIT_SUCCESS);
}