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

