#include "DIO.h"
#include "ADC.h"

volatile void (*ADC_INT_ON)() = NULL;
volatile bool_t ADLAR_ON = FALSE;

ISR(ADC_vect)
{
    if(ADC_INT_ON)
        ADC_INT_ON();
}

static void ADC_ADMUX_CONFIG(uint8_t VREF,uint8_t ADCn, bool_t ADC_LEFT_ADJUSTED)
{
    ADMUX = 0x00;
    ADMUX |= VREF;
    if(ADC_LEFT_ADJUSTED)
    {    
        ADLAR_ON = ADC_LEFT_ADJUSTED;
        ADMUX |= 1<<ADLAR;  
    }
    ADMUX |= ADCn;
}


void ADC_INIT(uint8_t VREF,uint8_t ADCn,void (*ADC_COMPLETE_CALLBACK)(), uint8_t ADC_PS, bool_t ADC_LEFT_ADJUSTED)
{
    ADCSRA = 0x00;    
    ADC_ADMUX_CONFIG(VREF,ADCn,ADC_LEFT_ADJUSTED);
    ADC_INT_ON = ADC_COMPLETE_CALLBACK;
    ADCSRA |= ADC_PS;
    ADCSRA |= 1<< ADEN;
    ADCSRA |= 1<<ADIE;
}


void ADC_AUTOTRIG_INIT(uint8_t VREF,uint8_t ADCn,void (*ADC_COMPLETE_CALLBACK)(), uint8_t ADC_PS, bool_t ADC_LEFT_ADJUSTED, uint8_t MODE)
{
    ADCSRA = 0x00;    
    ADC_ADMUX_CONFIG(VREF,ADCn,ADC_LEFT_ADJUSTED);
    ADC_INT_ON = ADC_COMPLETE_CALLBACK;
    ADCSRA |= ADC_PS;
    ADCSRA |= 1<< ADATE;
    #ifdef ADCSRB
        ADCSRB = (ADCSRB & ~0xE0) | (MODE<<5);
    #else
        SFIOR &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));
        SFIOR |= MODE <<5;
    #endif
    ADCSRA |= 1<< ADEN;
    ADCSRA |= 1<<ADIE;
    ADCSRA |= 1<< ADSC;
}

uint16_t ADC_READ()
{
    if(ADLAR_ON)
        return ((uint16_t)ADCH<<2);
    else
        return ADCW;
}

void ADC_CHANGE_CHANNEL(uint8_t ADCn)
{
    ADMUX &= ~(0x1F);
    ADMUX |= ADCn;
}

void ADC_CHANGE_CALLBACK(void(*ADC_COMPLETE_CALLBACK)())
{
    ADC_INT_ON = ADC_COMPLETE_CALLBACK;
}

void ADC_MANUAL_SAMPLE()
{
    ADCSRA |= 1<<ADSC;
}

void ADC_DISABLE ()
{
    ADCSRA &= ~(1<<ADEN);
}

void ADC_ENABLE ()
{
    ADCSRA |= (1<<ADEN);
}