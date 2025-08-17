#include "LED.h"

void LED_INIT(LED_t* LED,char PORT,uint8_t PIN_NUM)
{
    LED->PORT = PORT;
    LED->PIN_NUM = PIN_NUM;
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
    LED_OFF (LED);
}

void LED_ON(const LED_t* LED)
{
    switch(LED->PORT)
    {
        case 'A':
            SET_PINA (LED->PIN_NUM,HIGH);
            break;
        case 'B':
            SET_PINB (LED->PIN_NUM,HIGH);
            break;
        case 'C':
            SET_PINC (LED->PIN_NUM,HIGH);
            break;
        case 'D':
            SET_PIND (LED->PIN_NUM,HIGH);
            break;
    }
}

void LED_ON_ARR (const LED_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_ON(LEDs+i);
}

void LED_OFF(const LED_t* LED)
{
    switch(LED->PORT)
    {
        case 'A':
            SET_PINA (LED->PIN_NUM,LOW);
            break;
        case 'B':
            SET_PINB (LED->PIN_NUM,LOW);
            break;
        case 'C':
            SET_PINC (LED->PIN_NUM,LOW);
            break;
        case 'D':
            SET_PIND (LED->PIN_NUM,LOW);
            break;
    }
}

void LED_OFF_ARR (const LED_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_OFF(LEDs+i);
}

void LED_TOGGLE(const LED_t* LED)
{
    switch(LED->PORT)
    {
        case 'A':
            TOGGLE_PINA(LED->PIN_NUM);
            break;
        case 'B':
            TOGGLE_PINB(LED->PIN_NUM);
            break;
        case 'C':
            TOGGLE_PINC(LED->PIN_NUM);
            break;
        case 'D':
            TOGGLE_PIND(LED->PIN_NUM);
            break;
    }
}

void LED_TOGGLE_ARR (const LED_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_TOGGLE(LEDs+i);
}

void LED_BLINK(const LED_t* LED,uint8_t FREQ,uint32_t CYCLES)
{
    LED_OFF(LED);
    _delay_ms(5);
    for(int i=0;i<CYCLES;i++)
    {
        LED_ON(LED);
        _delay_ms((1000/(FREQ*2)));
        LED_OFF(LED);
        _delay_ms((1000/(FREQ*2)));
    }
}

void LED_BLINK_ARR (const LED_t LEDs[], uint8_t size, uint8_t FREQ, uint32_t CYCLES)
{
    LED_OFF_ARR(LEDs,size);
    _delay_ms(5);
    for(int i=0;i<CYCLES;i++)
    {
        LED_ON_ARR(LEDs,size);
        _delay_ms((1000/(FREQ*2)));
        LED_OFF_ARR(LEDs,size);
        _delay_ms((1000/(FREQ*2)));
    }
}