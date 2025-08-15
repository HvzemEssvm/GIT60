/* 
 * File:   main.c
 * Author: Lenovo
 *
 * Created on August 8, 2025, 8:45 AM
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

