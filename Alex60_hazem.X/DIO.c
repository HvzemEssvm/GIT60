#include "DIO.h"

void SET_PINA(uint8_t PIN_NUM, state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTA &= ~(1<<PIN_NUM);
            break;
        case HIGH:
            PORTA |= (1<<PIN_NUM);
            break;
    }
}

void SET_PINB(uint8_t PIN_NUM, state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTB &= ~(1<<PIN_NUM);
            break;
        case HIGH:
            PORTB |= (1<<PIN_NUM);
            break;
    }
}

void SET_PINC(uint8_t PIN_NUM, state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTC &= ~(1<<PIN_NUM);
            break;
        case HIGH:
            PORTC |= (1<<PIN_NUM);
            break;
    }
}

void SET_PIND(uint8_t PIN_NUM, state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTD &= ~(1<<PIN_NUM);
            break;
        case HIGH:
            PORTD |= (1<<PIN_NUM);
            break;
    }
}

void SET_PINA_DIR(uint8_t PIN_NUM, dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRA &= ~(1<<PIN_NUM);
            break;
        case OUTPUT:
            DDRA |= (1<<PIN_NUM);
            break;
    }
}

void SET_PINB_DIR(uint8_t PIN_NUM, dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRB &= ~(1<<PIN_NUM);
            break;
        case OUTPUT:
            DDRB |= (1<<PIN_NUM);
            break;
    }
}

void SET_PINC_DIR(uint8_t PIN_NUM, dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRC &= ~(1<<PIN_NUM);
            break;
        case OUTPUT:
            DDRC |= (1<<PIN_NUM);
            break;
    }
}

void SET_PIND_DIR(uint8_t PIN_NUM, dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRD &= ~(1<<PIN_NUM);
            break;
        case OUTPUT:
            DDRD |= (1<<PIN_NUM);
            break;
    }
}

void SET_PORTA(state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTA = 0x00;
            break;
        case HIGH:
            PORTA = 0xff;
            break;
    }
}

void SET_PORTB(state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTB = 0x00;
            break;
        case HIGH:
            PORTB = 0xff;
            break;
    }
}

void SET_PORTC(state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTC = 0x00;
            break;
        case HIGH:
            PORTC = 0xff;
            break;
    }
}

void SET_PORTD(state_t STATE)
{
    switch(STATE)
    {
        case LOW:
            PORTD = 0x00;
            break;
        case HIGH:
            PORTD = 0xff;
            break;
    }
}

void SET_PORTA_DIR(dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRA = 0x00;
            break;
        case OUTPUT:
            DDRA = 0xff;
            break;
    }
}

void SET_PORTB_DIR(dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRB = 0x00;
            break;
        case OUTPUT:
            DDRB = 0xff;
            break;
    }
}

void SET_PORTC_DIR(dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRC = 0x00;
            break;
        case OUTPUT:
            DDRC = 0xff;
            break;
    }
}

void SET_PORTD_DIR(dir_t DIR)
{
    switch(DIR)
    {
        case INPUT:
            DDRD = 0x00;
            break;
        case OUTPUT:
            DDRD = 0xff;
            break;
    }
}

uint8_t GET_PINA(uint8_t PIN_NUM)
{
    return (PINA & (1<<PIN_NUM))?1:0;
}

uint8_t GET_PINB(uint8_t PIN_NUM)
{
    return (PINB & (1<<PIN_NUM))?1:0;
}

uint8_t GET_PINC(uint8_t PIN_NUM)
{
    return (PINC & (1<<PIN_NUM))?1:0;
}

uint8_t GET_PIND(uint8_t PIN_NUM)
{
    return (PIND & (1<<PIN_NUM))?1:0;
}

void TOGGLE_PINA(uint8_t PIN_NUM)
{
    PORTA ^= (1<<PIN_NUM);
}

void TOGGLE_PINB(uint8_t PIN_NUM)
{
    PORTB ^= (1<<PIN_NUM);
}

void TOGGLE_PINC(uint8_t PIN_NUM)
{
    PORTC ^= (1<<PIN_NUM);
}

void TOGGLE_PIND(uint8_t PIN_NUM)
{
    PORTD ^= (1<<PIN_NUM);
}

void TOGGLE_PORTA()
{
    PORTA ^= 0xff;
}

void TOGGLE_PORTB()
{
    PORTB ^= 0xff;
}

void TOGGLE_PORTC()
{
    PORTC ^= 0xff;
}

void TOGGLE_PORTD()
{
    PORTD ^= 0xff;
}