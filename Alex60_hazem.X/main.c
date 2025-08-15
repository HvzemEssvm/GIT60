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
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr//io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

/*
 * 
 */
int main()
{
//    DDRC
    DDRA |= 1<<2;
    while(1)
    {
        PORTA |= 1<<2;
        _delay_ms(500); // try implement your own delay function
        PORTA &= ~(1<<2);
    }
    return (EXIT_SUCCESS);
}

