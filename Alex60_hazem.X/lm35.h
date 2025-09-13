/* 
 * File:   lm35.h
 * Author: Hazem
 * 
 * 1) You should Initialize ADC with ADC_AUTOTRIG_INIT() or ADC_INIT
 * 2) Do not use LM35_SAMPLE() in case of AUTOTRIG_MODE
 * 3) Create an variabe lm35_t storing the port & pin num --> ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
 * 4) Use LM35_SENSOR_SELECT() to make it ADC fetch input from the correct pin
 * 5) call LM35_READ() in the callback function.
 *
 * Created on September 12, 2025, 4:11 PM
 */

#ifndef LM35_H
#define	LM35_H
#include "ADC.h"
#include <stdint.h>

typedef uint8_t lm35_t; // ADCx x:[0,1,2,3,4,5,6,7]

/**
 * DO NOT USE IN CASE OF ADC_AUTOTRIG_MODE()
 * @param LM35
 */
void LM35_SAMPLE(lm35_t LM35);

void LM35_SENSOR_SELECT(lm35_t LM35);

/**
 * @return the returned value must be multiplied by ADC VREF and then divide all by ADC Levels number  
 */
float LM35_READ();

#endif	/* LM35_H */
