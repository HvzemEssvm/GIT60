#include "INTERRUPT.h"

volatile void (*INT0_callback)() = NULL;
volatile void (*INT1_callback)() = NULL;
volatile void (*INT2_callback)() = NULL;

ISR(INT0_vect)
{
    if(INT0_callback)
        INT0_callback();
}

ISR(INT1_vect)
{
    if(INT1_callback)
        INT1_callback();
}

ISR(INT2_vect)
{
    if(INT2_callback)
        INT2_callback();
}

void INTERRUPT_ENABLE(uint8_t INT_NUM,uint8_t MODE,void(*ISR_FN)())
{
    cli();
    switch (INT_NUM)
    {
        default :
            sei();
            return;
            
        case INT0:
            if(MODE&(1<<0))
                MCUCR |= (1<<ISC00);
            else
                MCUCR &= ~(1<<ISC00);
            
            if(MODE&(1<<1))
                MCUCR |= (1<<ISC01);
            else
                MCUCR &= ~(1<<ISC01);
            INT0_callback = ISR_FN;
            break;
            
        case INT1:
            if(MODE&(1<<0))
                MCUCR |= (1<<ISC10);
            else
                MCUCR &= ~(1<<ISC10);
            
            if(MODE&(1<<1))
                MCUCR |= (1<<ISC11);
            else
                MCUCR &= ~(1<<ISC11);       
            INT1_callback = ISR_FN;
            break;
            
        case INT2:
            if(MODE&(1<<0))
                MCUCSR |= (1<<ISC2);
            else
                MCUCSR &= ~(1<<ISC2);
            INT2_callback = ISR_FN;
            break;
            
    }
    GICR |= (1<<INT_NUM);
    sei();
}

void INTERRUPT_DISABLE(uint8_t INT_NUM)
{
    cli();
    switch(INT_NUM)
    {
        default:
            sei();
        return;
        
        case INT0:
            INT0_callback =NULL;
        break;
        
        case INT1:
            INT1_callback =NULL;
        break;
        
        case INT2:
            INT2_callback =NULL;
        break;
    }        
    GICR &= ~(1<<INT_NUM);
    sei();
}
