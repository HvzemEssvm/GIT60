/* 
 * File:   DIO.h
 * Author: Hazem
 *
 * Created on August 9, 2025, 7:53 AM
 * 
 * 
 */

#ifndef DIO_H
#define	DIO_H
#define F_CPU 16000000UL
#undef __OPTIMIZE__
#include <stdio.h>
#include <stdint.h>
#include <avr//io.h>

#define A0  0
#define A1  1
#define A2  2
#define A3  3
#define A4  4
#define A5  5
#define A6  6
#define A7  7

#define B0  8
#define B1  9
#define B2  10
#define B3  11
#define B4  12
#define B5  13
#define B6  14
#define B7  15

#define C0  16
#define C1  17
#define C2  18
#define C3  19
#define C4  20
#define C5  21
#define C6  22
#define C7  23

#define D0  24
#define D1  25
#define D2  26
#define D3  27
#define D4  28
#define D5  29
#define D6  30
#define D7  31

typedef enum{FALSE ,TRUE}bool_t;
typedef enum {INPUT, OUTPUT} dir_t;
typedef enum {LOW, HIGH} state_t;

void SET_PIN(uint8_t PORT_PIN_NUM, state_t STATE);
void SET_PIN_DIR(uint8_t PORT_PIN_NUM, dir_t DIR);

state_t GET_PIN(uint8_t PORT_PIN_NUM);

void TOGGLE_PIN(uint8_t PORT_PIN_NUM);

void SET_PORTA(state_t STATE);
void SET_PORTB(state_t STATE);
void SET_PORTC(state_t STATE);
void SET_PORTD(state_t STATE);

void SET_PORTA_DIR(dir_t DIR);
void SET_PORTB_DIR(dir_t DIR);
void SET_PORTC_DIR(dir_t DIR);
void SET_PORTD_DIR(dir_t DIR);

void TOGGLE_PORTA();
void TOGGLE_PORTB();
void TOGGLE_PORTC();
void TOGGLE_PORTD();

#endif

