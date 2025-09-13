#include "lm35.h"

void LM35_SAMPLE(lm35_t LM35)
{
    ADC_CHANGE_CHANNEL(LM35);
    ADC_MANUAL_SAMPLE ();
}

void LM35_SENSOR_SELECT(lm35_t LM35)
{
    ADC_CHANGE_CHANNEL (LM35);
}

/**
 * @return the returned value must be multiplied by ADC VREF and then divide all by ADC Levels number:
 *         Example: LM35_READ * 5 /1024;  
 */
float LM35_READ()
{
    return (float)(ADC_READ()*100);
}
