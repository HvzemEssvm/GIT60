/* 
 * File:   LED.h
 * Author: Hazem
 *
 * Created on August 15, 2025, 4:58 AM
 */

#ifndef LED_H
#define	LED_H
#include "DIO.h"
#include <util/delay.h>

typedef struct
{
  uint8_t PORT_PIN_NUM;
}LED_t;

void LED_INIT(LED_t* LED,uint8_t PORT_PIN_NUM);
void LED_ON(const LED_t* LED);
void LED_ON_ARR(const LED_t LEDs[],uint8_t size);
void LED_OFF(const LED_t* LED);
void LED_OFF_ARR(const LED_t LEDs[],uint8_t size);
void LED_TOGGLE(const LED_t* LED);
void LED_TOGGLE_ARR(const LED_t LEDs[],uint8_t size);
void LED_BLINK(const LED_t* LED,uint8_t FREQ,uint32_t CYCLES);
void LED_BLINK_ARR(const LED_t LEDs[],uint8_t size,uint8_t FREQ,uint32_t CYCLES);

#endif	

