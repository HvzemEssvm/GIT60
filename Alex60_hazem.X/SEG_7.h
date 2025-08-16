/* 
 * File:   SEG_7.h
 * Author: Hazem
 *
 * 
 *                     ___a___
 *                    |       | b
 *                  f |       |
 *                     ___g___
 *                  e |       | c
 *                    |       |     _
 *                     ___d___     |_| <--dp
 *                
 *  Created on August 16, 2025, 12:51 AM
 */

#ifndef SEG_7_H
#define	SEG_7_H
#include "LED.h"
#include "DIO.h"

typedef enum{FALSE ,TRUE}bool_t;

typedef struct
{
  LED_t SEGMENTS[8];
  bool_t common_anode;
}SEG_t;

void SEG_OFF(const SEG_t* SEG);

void SEG_INIT(SEG_t* SEG,
              char PORT_A,uint8_t PIN_A,
              char PORT_B,uint8_t PIN_B,
              char PORT_C,uint8_t PIN_C,
              char PORT_D,uint8_t PIN_D,
              char PORT_E,uint8_t PIN_E,
              char PORT_F,uint8_t PIN_F,
              char PORT_G,uint8_t PIN_G,
              char PORT_DP,uint8_t PIN_DP,
              bool_t is_common_anode);

void SEG_DRAW(const SEG_t* SEG,state_t SEG_STATES[8]);

void SEG_DISPLAY_HEX(const SEG_t* SEG,uint8_t digit,state_t DP);

#endif

