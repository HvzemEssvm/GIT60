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
  char PORT;
  uint8_t PIN_NUM;
}BUZZER_t;

void BUZZER_INIT(BUZZER_t* BUZZER,char PORT,uint8_t PIN_NUM);
void BUZZER_ON(const BUZZER_t* BUZZER);
void BUZZER_OFF(const BUZZER_t* BUZZER);
void BUZZER_TOGGLE(const BUZZER_t* BUZZER);
void BUZZER_BLINK(const BUZZER_t* BUZZER,uint8_t FREQ,uint32_t CYCLES);

#endif	/* BUZZER_H */

