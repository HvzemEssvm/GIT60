/* 
 * File:   LED.h
 * Author: Hazem
 *
 * Created on August 15, 2025, 4:58 AM
 */

#ifndef LED_H
#define	LED_H
#include "DIO.h"

typedef struct
{
  char PORT;
  uint8_t PIN_NUM;
}LED_t;

void LED_INIT(LED_t* LED,char PORT,uint8_t PIN_NUM);
void LED_ON(const LED_t* LED);
void LED_OFF(const LED_t* LED);
void LED_TOGGLE(const LED_t* LED);

#endif	

