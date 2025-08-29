#include "buzzer.h"

void BUZZER_OFF(const buzzer_t* BUZZER)
{
    SET_PIN (BUZZER->PORT_PIN_NUM,LOW);
}

void BUZZER_INIT(buzzer_t* BUZZER,uint8_t PORT_PIN_NUM)
{
    BUZZER->PORT_PIN_NUM = PORT_PIN_NUM;
    SET_PIN_DIR (PORT_PIN_NUM,OUTPUT);
    BUZZER_OFF (BUZZER);
}

void BUZZER_ON(const buzzer_t* BUZZER)
{
    SET_PIN (BUZZER->PORT_PIN_NUM,HIGH);
}

void BUZZER_TOGGLE(const buzzer_t* BUZZER)
{
    TOGGLE_PIN (BUZZER->PORT_PIN_NUM);
}

void BUZZER_BLINK(const buzzer_t* BUZZER,uint8_t FREQ,uint32_t CYCLES)
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
