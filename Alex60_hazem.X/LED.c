#include "DIO.h"
#include "LED.h"

void LED_INIT(LED_t* LED,char PORT,uint8_t PIN_NUM)
{
    switch(PORT)
    {
        case 'A':
            LED->PORT = 'A';
            LED->PIN_NUM = PIN_NUM;
            SET_PINA_DIR (PIN_NUM,OUTPUT);
            SET_PINA (PIN_NUM,LOW);
            break;
        case 'B':
            LED->PORT = 'B';
            LED->PIN_NUM = PIN_NUM;
            SET_PINB_DIR (PIN_NUM,OUTPUT);
            SET_PINB (PIN_NUM,LOW);
            break;
        case 'C':
            LED->PORT = 'C';
            LED->PIN_NUM = PIN_NUM;
            SET_PINC_DIR (PIN_NUM,OUTPUT);
            SET_PINC (PIN_NUM,LOW);
            break;
        case 'D':
            LED->PORT = 'D';
            LED->PIN_NUM = PIN_NUM;
            SET_PIND_DIR (PIN_NUM,OUTPUT);
            SET_PIND (PIN_NUM,LOW);
            break;
    }
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

