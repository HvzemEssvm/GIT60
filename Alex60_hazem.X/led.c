#include "led.h"

void LED_INIT(led_t* LED,uint8_t PORT_PIN_NUM)
{
    LED->PORT_PIN_NUM = PORT_PIN_NUM;
    SET_PIN_DIR (PORT_PIN_NUM,OUTPUT);
    LED_OFF (LED);
}

void LED_ON(const led_t* LED)
{
    SET_PIN (LED->PORT_PIN_NUM,HIGH);
}

void LED_ON_ARR (const led_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_ON(LEDs+i);
}

void LED_OFF(const led_t* LED)
{
    SET_PIN (LED->PORT_PIN_NUM,LOW);
}

void LED_OFF_ARR (const led_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_OFF(LEDs+i);
}

void LED_TOGGLE(const led_t* LED)
{
    TOGGLE_PIN (LED->PORT_PIN_NUM);
}

void LED_TOGGLE_ARR (const led_t LEDs[], uint8_t size)
{
    for(int i=0;i<size;i++)
        LED_TOGGLE(LEDs+i);
}

void LED_BLINK(const led_t* LED,uint8_t FREQ,uint32_t CYCLES)
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

void LED_BLINK_ARR (const led_t LEDs[], uint8_t size, uint8_t FREQ, uint32_t CYCLES)
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