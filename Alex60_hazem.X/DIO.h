/* 
 * File:   DIO.h
 * Author: Hazem
 *
 * Created on August 9, 2025, 7:53 AM
 * 
 * VIP NOTES:
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
 *                  Microcontroller Abstraction Layer (MCAL) is the layer where the manipulation and accessing the registers
 *                  of the MCU, also it is changed when we change the MCU with other architecture.
 *                  It includes (DIO - ADC - Timers - Interrupts ..)
 *                                                          |
 *                                                          |
 *      7.2) HAL:
 *                  Hardware Abstraction Layer (HAL) is a broader layer which includes device drivers for all other hardware
 *                  which is not in the MCU.
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
 */

#ifndef DIO_H
#define	DIO_H
#include <stdio.h>
#include <stdlib.h>
#include <avr//io.h>

#define uint8_t unsigned char
#define int8_t char
#define uint16_t unsigned short int
#define int16_t short int 
#define uint32_t unsigned int 
#define int32_t int;

typedef enum {INPUT, OUTPUT} dir_t;
typedef enum {LOW, HIGH} state_t;


void SET_PINA(uint8_t PIN_NUM, state_t STATE);
void SET_PINB(uint8_t PIN_NUM, state_t STATE);
void SET_PINC(uint8_t PIN_NUM, state_t STATE);
void SET_PIND(uint8_t PIN_NUM, state_t STATE);

void SET_PINA_DIR(uint8_t PIN_NUM, dir_t DIR);
void SET_PINB_DIR(uint8_t PIN_NUM, dir_t DIR);
void SET_PINC_DIR(uint8_t PIN_NUM, dir_t DIR);
void SET_PIND_DIR(uint8_t PIN_NUM, dir_t DIR);

void SET_PORTA(state_t STATE);
void SET_PORTB(state_t STATE);
void SET_PORTC(state_t STATE);
void SET_PORTD(state_t STATE);

void SET_PORTA_DIR(dir_t DIR);
void SET_PORTB_DIR(dir_t DIR);
void SET_PORTC_DIR(dir_t DIR);
void SET_PORTD_DIR(dir_t DIR);

uint8_t GET_PINA(uint8_t PIN_NUM);
uint8_t GET_PINB(uint8_t PIN_NUM);
uint8_t GET_PINC(uint8_t PIN_NUM);
uint8_t GET_PIND(uint8_t PIN_NUM);

void TOGGLE_PINA(uint8_t PIN_NUM);
void TOGGLE_PINB(uint8_t PIN_NUM);
void TOGGLE_PINC(uint8_t PIN_NUM);
void TOGGLE_PIND(uint8_t PIN_NUM);

void TOGGLE_PORTA();
void TOGGLE_PORTB();
void TOGGLE_PORTC();
void TOGGLE_PORTD();

#endif

