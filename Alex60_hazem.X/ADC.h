/* 
 * File:   ADC.h
 * Author: Hazem
 * 
 * ADMUX_REG --> [REFS1,REFS0,ADLAR,MUX4,MUX3,MUX2,MUX1,MUX0] 
 * ADCSRA_REG --> [ADEN,ADSC,ADATE,ADIF,ADIE,ADPS2,ADPS1,ADPS0]
 *
 * NOTES:
 * Some micro-controllers needs to disable digital input on the desired pin !!!
 * For this Library must use sei() after initializing the ADC peripherals !!!!!
 * 
 * Created on September 6, 2025, 5:10 AM
 */

#ifndef ADC_H
#define	ADC_H

#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#undef __OPTIMIZE__
#include <util/delay.h>

#define ADC_PS_2 0x00
#define ADC_PS_4 0x02
#define ADC_PS_8 0x03
#define ADC_PS_16 0x04
#define ADC_PS_32 0x05
#define ADC_PS_64 0x06
#define ADC_PS_128 0x07

#ifdef F_CPU
#define MAX_ADC_FREQ 200000UL
#define MIN_DIV_FACTOR F_CPU/MAX_ADC_FREQ 
#if MIN_DIV_FACTOR <= 2
#define ADC_PS_MIN ADC_PS_2
#elif MIN_DIV_FACTOR <= 4
#define ADC_PS_MIN ADC_PS_4
#elif MIN_DIV_FACTOR <= 8
#define ADC_PS_MIN ADC_PS_8
#elif MIN_DIV_FACTOR <= 16
#define ADC_PS_MIN ADC_PS_16
#elif MIN_DIV_FACTOR <= 32
#define ADC_PS_MIN ADC_PS_32
#elif MIN_DIV_FACTOR <= 64
#define ADC_PS_MIN ADC_PS_64
#else
#define ADC_PS_MIN ADC_PS_128
#endif
#endif

// Single Ended Mode
#define ADC0 0x00
#define ADC1 0x01
#define ADC2 0x02
#define ADC3 0x03
#define ADC4 0x04
#define ADC5 0x05
#define ADC6 0x06
#define ADC7 0x07

// Differential Pair Mode
#define ADC0_ADC0_DIFFx10 0x08
#define ADC1_ADC0_DIFFx10 0x09
#define ADC0_ADC0_DIFFx200 0x0A
#define ADC1_ADC0_DIFFx200 0x0B
#define ADC2_ADC2_DIFFx10 0x0C
#define ADC3_ADC2_DIFFx10 0x0D
#define ADC2_ADC2_DIFFx200 0x0E
#define ADC3_ADC2_DIFFx200 0x0F
#define ADC0_ADC1_DIFFx1 0x10
#define ADC1_ADC1_DIFFx1 0x11
#define ADC2_ADC1_DIFFx1 0x12
#define ADC3_ADC1_DIFFx1 0x13
#define ADC4_ADC1_DIFFx1 0x14
#define ADC5_ADC1_DIFFx1 0x15
#define ADC6_ADC1_DIFFx1 0x16
#define ADC7_ADC1_DIFFx1 0x17
#define ADC0_ADC2_DIFFx1 0x18
#define ADC1_ADC2_DIFFx1 0x19
#define ADC2_ADC2_DIFFx1 0x1A
#define ADC3_ADC2_DIFFx1 0x1B
#define ADC4_ADC2_DIFFx1 0x1C
#define ADC5_ADC2_DIFFx1 0x1D

#define VREF_AREF 0x00
#define VREF_AVCC 0x40 
#define VREF_2V56 0xC0

#define AUTO_FREE_RUNNING 0x00
#define AUTO_ANALOG_COMP  0x01
#define AUTO_INT0         0x02
#define AUTO_TIMER0_COMPARE_MATCH 0x03
#define AUTO_TIMER0_OVERFLOW 0x04
#define AUTO_TIMER1_COMPARE_MATCHB 0x05
#define AUTO_TIMER1_OVERFLOW 0x06
#define AUTO_TIMER1_INPUT_CAPTURE 0x07

/**
 * 
 * @param VREF : maximum voltage for ADC, any value above maximum will be read as maximum voltage
 *               --> (VREF_AREF,    VREF_AVCC,  VREF_2V56)
 * 
 * @param ADCn : Channel to be the initial default input to mcu --> [ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7,ADCx_ADCy_DIFFxx...]
 *  
 * @param ADC_COMPLETE_CALLBACK : function to be called when ADC conversion is completed
 * @param ADC_PS : PRESCALER for the ADC clock cycle 
 *                 -> (ADC_PS_2, ADC_PS_4, ADC_PS_8, ADC_PS_16, ADC_PS_32, ADC_PS_64, ADC_PS_128, ADC_PS_MIN)
 * 
 * How to select the proper PRESCALER/DIVISON FACTOR:
 * 
 * if ADC conversion takes 13.5 on average ADC cycle then for F_CPU/MAXIMUM_FREQUENCY for ADC clock cycle
 * which is equal to 16000000/200000 = minimum division factor... then choosen divison factor from the table in the datasheet
 * must be >= minimum divison factor.
 * 
 * How to know the maximum SIGNAL frequency ? 
 * 
 * The maximum SAMPLING frequency = ADC_CONVERSION_CLOCK_CYCLES x F_CPU / CHOOSEN DIVSION FACTOR
 * and maximum SIGNAL frequency = maximum SAMPLING frequency / 2  
 * 
 * @param ADC_LEFT_ADJUSTED : if this value is set to true it will fill ADCH and ADCL as following:
 *                            MSB of the value will be stored in ADCH[7] and LSB of the value will be stored in ADCL[6]
 */
void ADC_INIT(uint8_t VREF,uint8_t ADCn,void (*ADC_COMPLETE_CALLBACK)(), uint8_t ADC_PS, bool_t ADC_LEFT_ADJUSTED);



/**
 * 
 * @param VREF : maximum voltage for ADC, any value above maximum will be read as maximum voltage
 *               --> (VREF_AREF,    VREF_AVCC,  VREF_2V56)
 * @param ADCn : Channel to be the initial default input to mcu --> [ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7,ADCx_ADCy_DIFFxx...]
 * @param ADC_COMPLETE_CALLBACK : function to be called when ADC conversion is completed
 * @param ADC_PS : PRESCALER for the ADC clock cycle 
 *                 -> (ADC_PS_2, ADC_PS_4, ADC_PS_8, ADC_PS_16, ADC_PS_32, ADC_PS_64, ADC_PS_128, ADC_PS_MIN)
 * @param ADC_LEFT_ADJUSTED : if this value is set to true it will fill ADCH and ADCL as following:
 *                            MSB of the value will be stored in ADCH[7] and LSB of the value will be stored in ADCL[6]
 * @param MODE : Auto-triggering mode be selected --> [AUTO_FREE_RUNNING, AUTO_ANALOG_COMP, AUTO_INT0,
 *                                                     AUTO_TIMER0_COMPARE_MATCH, AUTO_TIMER0_OVERFLOW,
 *                                                     AUTO_TIMER1_COMPARE_MATCHB, AUTO_TIMER1_OVERFLOW,
 *                                                     AUTO_TIMER1_INPUT_CAPTURE ]
 */
void ADC_AUTOTRIG_INIT(uint8_t VREF,uint8_t ADCn,void (*ADC_COMPLETE_CALLBACK)(), uint8_t ADC_PS, bool_t ADC_LEFT_ADJUSTED, uint8_t MODE);



/**
 * 
 * @return 2 Bytes representing the value read by current ADC chosen channel:
 *         Value range (0->1023)
 * 
 * How to fetch the needed current value in Volts:
 * 1) Fetch STEP_VALUE = MAX_VOLTAGE/1024  
 * 2) Multiply the STEP_VALUE by the value fetched from ADC_READ();
 * 
 * This Function MUST ONLY be called in the callback function of the ADC.
 */
uint16_t ADC_READ();

/**
 * Use only to start conversion in case of disabling the autotriggering
 */
void ADC_MANUAL_SAMPLE();

/**
 * Use this function if changing the current Analog Input Pin is needed 
 * @param ADCn : Channel to be the initial default input to mcu --> [ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7,ADCx_ADCy_DIFFxx...] 
 */
void ADC_CHANGE_CHANNEL(uint8_t ADCn);

void ADC_CHANGE_CALLBACK(void(*ADC_COMPLETE_CALLBACK)());

void ADC_DISABLE();

/**
 * Do not call without using ADC_INIT or ADC_AUTOTRIG_INIT in the code.
 */
void ADC_ENABLE();

#endif	/* ADC_H */

