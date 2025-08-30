/* 
 * File:   keypad_3x3.h
 * Author: Hazem
 *
 * Created on August 29, 2025, 2:50 AM
 * 
 *         OUTPUT_1     OUTPUT_2     OUTPUT_3
 *       -------------------------------------
 *       |   [1]    |    [2]     |    [3]    | --> INPUT_1
 *       -------------------------------------
 *       |   [4]    |    [5]     |    [6]    | --> INPUT_2
 *       -------------------------------------
 *       |   [7]    |    [8]     |    [9]    | --> INPUT_3
 *       ------------------------------------- 
 */

#ifndef KEYPAD_3X3_H
#define	KEYPAD_3X3_H
#include "DIO.h"
#include <util/delay.h>


typedef struct
{
  uint8_t INPUT_PORT_PIN[3];
  uint8_t OUTPUT_PORT_PIN[3];
  bool_t ACTIVE_HIGH;
}keypad_3x3_t;

void KEYPAD_3X3_INIT(keypad_3x3_t* KEYPAD,
                    uint8_t INPUT_1_PORT_PIN,
                    uint8_t INPUT_2_PORT_PIN,
                    uint8_t INPUT_3_PORT_PIN,
                    uint8_t OUTPUT_1_PORT_PIN,
                    uint8_t OUTPUT_2_PORT_PIN,
                    uint8_t OUTPUT_3_PORT_PIN,
                    bool_t is_active_high);

int8_t KEYPAD_3X3_READ(const keypad_3x3_t* KEYPAD);

#endif	

