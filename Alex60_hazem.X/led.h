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
}led_t;

void LED_INIT(led_t* LED,uint8_t PORT_PIN_NUM);
void LED_ON(const led_t* LED);
void LED_ON_ARR(const led_t LEDs[],uint8_t size);
void LED_OFF(const led_t* LED);
void LED_OFF_ARR(const led_t LEDs[],uint8_t size);
void LED_TOGGLE(const led_t* LED);
void LED_TOGGLE_ARR(const led_t LEDs[],uint8_t size);
void LED_BLINK(const led_t* LED,uint8_t FREQ,uint32_t CYCLES);
void LED_BLINK_ARR(const led_t LEDs[],uint8_t size,uint8_t FREQ,uint32_t CYCLES);

#endif	

