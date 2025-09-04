/* 
 * File:   INTERRUPT.h
 * Author: Hazem
 *
 * Created on August 30, 2025, 7:43 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H
#include "DIO.h"
#include <avr/interrupt.h>

#define LOW_LEVEL 0x00 // 0b0000000
#define CHANGE 0x01  // 0b0000001
#define FALLING 0x02 // 0b00000010
#define RISING 0x03  // 0b00000011

/**
 * 
 * @param INT_NUM --> (INT0,INT1,INT2)
 * @param MODE    --> (LOW_LEVEL, CHANGE, FALLING, RISING)
 * @param ISR_FN 
 */
void INTERRUPT_ENABLE(uint8_t INT_NUM,uint8_t MODE,void(*ISR_FN)());

/**
 * 
 * @param INT_NUM --> (INT0,INT1,INT2);
 */
void INTERRUPT_DISABLE(uint8_t INT_NUM);

#endif	

