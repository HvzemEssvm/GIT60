/* 
 * File:   main.c
 * Author: Lenovo
 *
 * Created on August 8, 2025, 8:45 AM
 * 
 * * VIP NOTES:
 * 1) Better to make typedef enum for state_t and dir_t
 * 2) lowercase_t convention is to indicate that this is a data type
 * 3) While changing a whole register with known values then assign to the needed value but do not use loops
 * 4) make it a convention to express values as hex --> 0x00 to 0xff
 * 
 * 5) when a certain pin to be output and accessed it by PINX will result to checking the current value assigned to it
 * 6) when a certain pin to be input, then you could control the Pull-up feature by manipulating with PORTX:
 *      6.1) Enable pull-up by 1 to the corresponding pin
 *      6.2) Disable pull-up by 0 to the corresponding pin
 * 
 * 7) all methods here "DIO.h" are considered as building MCAL
 *      7.1) MCAL:
 *                  Microcontroller Abstraction Layer (MCAL) is the layer where the manipulation 
 *                  and accessing the registers of the MCU, also it is changed when we change 
 *                  the MCU with other architecture.
 *                  It includes (DIO - ADC - Timers - Interrupts ..)
 *                                                          |
 *                                                          |
 *      7.2) HAL:
 *                  Hardware Abstraction Layer (HAL) is a broader layer which includes device drivers 
 *                  for all other hardware which is not in the MCU.
 *                  It includes (LED - BUZZER - Sensors ..)
 *                                                          |
 *                                                          |
 *      7.3) Application:       
 *                  In this layer we use HAL methods to do a specific application.
 *                  It includes (main.c)
 * 
 * 8) generally use switch-case instead of if-else
 * 9) convention when making methods in HAL layer like "xxx.h" to make the methods xxx_function
 * 10) delays should be included in the main file after each init/setup of pins
 * 11) better to use const ptr with structs as arguments to read-only method, not to copy the whole struct in the stack
 *     and take more RAM usage also to be const to ensure no modifying is occurred on the data.
 * 12) MCAL libs are named UPPER_CASE conventionally, while HAL libs are named lower_case conventionally
 */
#define F_CPU 16000000UL
#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!

#include "DIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <avr//io.h>
#include <avr//interrupt.h>
#include <util/delay.h>

#include "seg_7.h"
#include "keypad_3x3.h"
#include "lcd1602.h"

#define seg_a A0
#define seg_b A1
#define seg_c A2
#define seg_d A3
#define seg_e A4
#define seg_f A5
#define seg_g A6
#define seg_dp A7

#define keypad_input_1 C0
#define keypad_input_2 C1
#define keypad_input_3 C2
#define keypad_output_1 C3
#define keypad_output_2 C4
#define keypad_output_3 C5

//#define LCD_D0 A0
//#define LCD_D1 A1
//#define LCD_D2 A2
//#define LCD_D3 A3
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
    KEYPAD_3X3_INIT(&KEYPAD_1,keypad_input_1,keypad_input_2,keypad_input_3,
                    keypad_output_1,keypad_output_2,keypad_output_3,FALSE);
//    LCD1602_INIT (&LCD_1,LCD_D7,LCD_D6,LCD_D5,LCD_D4,LCD_D3,LCD_D2,LCD_D1,LCD_D0,LCD_RS,LCD_E,TRUE,TRUE,TRUE);
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

