/* 
 * File:   DIO.h
 * Author: Hazem
 *
 * Created on August 9, 2025, 7:53 AM
 */

#ifndef DIO_H
#define	DIO_H
#include <stdio.h>
#include <stdlib.h>
#include <avr//io.h>

typedef unsigned char uint8;
void setPORTA(uint8 state);
uint8 getPINA(uint8 PIN_NUM);
void togglePORTA();
#endif	/* DIO_H */

