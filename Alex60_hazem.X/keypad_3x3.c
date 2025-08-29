#include "keypad_3x3.h"

void KEYPAD_3X3_INIT(keypad_3x3_t* KEYPAD,
                    uint8_t INPUT_1_PORT_PIN,
                    uint8_t INPUT_2_PORT_PIN,
                    uint8_t INPUT_3_PORT_PIN,
                    uint8_t OUTPUT_1_PORT_PIN,
                    uint8_t OUTPUT_2_PORT_PIN,
                    uint8_t OUTPUT_3_PORT_PIN,
                    bool_t is_active_high)
{
    if(!KEYPAD)
        return;
    
    KEYPAD->INPUT_PORT_PIN[0]=INPUT_1_PORT_PIN;
    KEYPAD->INPUT_PORT_PIN[1]=INPUT_2_PORT_PIN;
    KEYPAD->INPUT_PORT_PIN[2]=INPUT_3_PORT_PIN;
    
    KEYPAD->OUTPUT_PORT_PIN[0]=OUTPUT_1_PORT_PIN;
    KEYPAD->OUTPUT_PORT_PIN[1]=OUTPUT_2_PORT_PIN;
    KEYPAD->OUTPUT_PORT_PIN[2]=OUTPUT_3_PORT_PIN;
    
    KEYPAD->ACTIVE_HIGH = is_active_high;
    
    SET_PIN_DIR (INPUT_1_PORT_PIN,INPUT);
    SET_PIN_DIR (INPUT_2_PORT_PIN,INPUT);
    SET_PIN_DIR (INPUT_3_PORT_PIN,INPUT);
    
    SET_PIN_DIR (OUTPUT_1_PORT_PIN,OUTPUT);
    SET_PIN_DIR (OUTPUT_2_PORT_PIN,OUTPUT);
    SET_PIN_DIR (OUTPUT_3_PORT_PIN,OUTPUT);
    
    SET_PIN (OUTPUT_1_PORT_PIN,(state_t)is_active_high);
    SET_PIN (OUTPUT_2_PORT_PIN,(state_t)is_active_high);
    SET_PIN (OUTPUT_3_PORT_PIN,(state_t)is_active_high);
}

bool_t is_triggered(uint8_t PORT_PIN_NUM, bool_t is_active_high)
{
    return (GET_PIN(PORT_PIN_NUM)==is_active_high); // based on truth table
}

int8_t KEYPAD_3X3_READ(const keypad_3x3_t* KEYPAD)
{
    int8_t val;
    if(is_triggered (KEYPAD->INPUT_PORT_PIN[0],KEYPAD->ACTIVE_HIGH))
    {
        SET_PIN (KEYPAD->OUTPUT_PORT_PIN[0],(state_t)!(KEYPAD->ACTIVE_HIGH));
        if(is_triggered (KEYPAD->INPUT_PORT_PIN[0],KEYPAD->ACTIVE_HIGH))
        {   
            SET_PIN (KEYPAD->OUTPUT_PORT_PIN[1],(state_t)!(KEYPAD->ACTIVE_HIGH));
            if(is_triggered (KEYPAD->INPUT_PORT_PIN[0],KEYPAD->ACTIVE_HIGH))
            {
                val = 3;
            }
            else
                val = 2;
        }
        else
            val = 1;
    }
    else if(is_triggered (KEYPAD->INPUT_PORT_PIN[1],KEYPAD->ACTIVE_HIGH))
    {
        SET_PIN (KEYPAD->OUTPUT_PORT_PIN[0],(state_t)!(KEYPAD->ACTIVE_HIGH));
        if(is_triggered (KEYPAD->INPUT_PORT_PIN[1],KEYPAD->ACTIVE_HIGH))
        {   
            SET_PIN (KEYPAD->OUTPUT_PORT_PIN[1],(state_t)!(KEYPAD->ACTIVE_HIGH));
            if(is_triggered (KEYPAD->INPUT_PORT_PIN[1],KEYPAD->ACTIVE_HIGH))
            {
                val = 6;
            }
            else
                val = 5;
        }
        else
            val = 4; 
    }
    else if(is_triggered (KEYPAD->INPUT_PORT_PIN[2],KEYPAD->ACTIVE_HIGH))
    {
        SET_PIN (KEYPAD->OUTPUT_PORT_PIN[0],(state_t)!(KEYPAD->ACTIVE_HIGH));
        if(is_triggered (KEYPAD->INPUT_PORT_PIN[2],KEYPAD->ACTIVE_HIGH))
        {   
            SET_PIN (KEYPAD->OUTPUT_PORT_PIN[1],(state_t)!(KEYPAD->ACTIVE_HIGH));
            if(is_triggered (KEYPAD->INPUT_PORT_PIN[2],KEYPAD->ACTIVE_HIGH))
            {
                val = 9;
            }
            else
                val = 8;
        }
        else
            val = 7;
    }
    else
        val = -1;
    
    
    SET_PIN (KEYPAD->OUTPUT_PORT_PIN[0],(state_t)KEYPAD->ACTIVE_HIGH);
    SET_PIN (KEYPAD->OUTPUT_PORT_PIN[1],(state_t)KEYPAD->ACTIVE_HIGH);
    SET_PIN (KEYPAD->OUTPUT_PORT_PIN[2],(state_t)KEYPAD->ACTIVE_HIGH);
    
    return val;
}
