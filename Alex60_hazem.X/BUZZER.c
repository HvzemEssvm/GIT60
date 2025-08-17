#include "BUZZER.h"

void BUZZER_OFF(const BUZZER_t* BUZZER)
{
    switch(BUZZER->PORT)
    {
        case 'A':
            SET_PINA (BUZZER->PIN_NUM,LOW);
            break;
        case 'B':
            SET_PINB (BUZZER->PIN_NUM,LOW);
            break;
        case 'C':
            SET_PINC (BUZZER->PIN_NUM,LOW);
            break;
        case 'D':
            SET_PIND (BUZZER->PIN_NUM,LOW);
            break;
    }
}

void BUZZER_INIT(BUZZER_t* BUZZER,char PORT,uint8_t PIN_NUM)
{
    BUZZER->PORT = PORT;
    BUZZER->PIN_NUM = PIN_NUM;
    switch(PORT)
    {
        case 'A':

            SET_PINA_DIR (PIN_NUM,OUTPUT);
            break;
        case 'B':
            SET_PINB_DIR (PIN_NUM,OUTPUT);
            break;
        case 'C':
            SET_PINC_DIR (PIN_NUM,OUTPUT);
            break;
        case 'D':
            SET_PIND_DIR (PIN_NUM,OUTPUT);
            break;
    }
    BUZZER_OFF (BUZZER);
}

void BUZZER_ON(const BUZZER_t* BUZZER)
{
    switch(BUZZER->PORT)
    {
        case 'A':
            SET_PINA(BUZZER->PIN_NUM,HIGH);
        break;
        case 'B':
            SET_PINB(BUZZER->PIN_NUM,HIGH);
        break;
        case 'C':
            SET_PINC(BUZZER->PIN_NUM,HIGH);
        break;
        case 'D':
            SET_PIND(BUZZER->PIN_NUM,HIGH);
        break;
    }
}

void BUZZER_TOGGLE(const BUZZER_t* BUZZER)
{
    switch(BUZZER->PORT)
    {
        case 'A':
            TOGGLE_PINA(BUZZER->PIN_NUM);
        break;
        case 'B':
            TOGGLE_PINB(BUZZER->PIN_NUM);
        break;
        case 'C':
            TOGGLE_PINC(BUZZER->PIN_NUM);
        break;
        case 'D':
            TOGGLE_PIND(BUZZER->PIN_NUM);
        break;   
    }
}

void BUZZER_BLINK(const BUZZER_t* BUZZER,uint8_t FREQ,uint32_t CYCLES)
{
    BUZZER_OFF(BUZZER);
    _delay_ms(5);
    for(int i=0;i<CYCLES;i++)
    {
        BUZZER_ON(BUZZER);
        _delay_ms((1000/(FREQ*2)));
        BUZZER_OFF(BUZZER);
        _delay_ms((1000/(FREQ*2)));
    }
}
