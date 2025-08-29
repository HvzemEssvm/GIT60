/* 
 * File:   BUZZER.h
 * Author: Lenovo
 *
 * Created on August 16, 2025, 5:00 AM
 */

#ifndef BUZZER_H
#define	BUZZER_H

#include "DIO.h"
#include <util/delay.h>

typedef struct
{
  uint8_t PORT_PIN_NUM;
}buzzer_t;

void BUZZER_INIT(buzzer_t* BUZZER,uint8_t PORT_PIN_NUM);
void BUZZER_ON(const buzzer_t* BUZZER);
void BUZZER_OFF(const buzzer_t* BUZZER);
void BUZZER_TOGGLE(const buzzer_t* BUZZER);
void BUZZER_BLINK(const buzzer_t* BUZZER,uint8_t FREQ,uint32_t CYCLES);

#endif	/* BUZZER_H */

