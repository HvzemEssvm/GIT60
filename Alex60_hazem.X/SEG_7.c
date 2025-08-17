#include "SEG_7.h"

void SEG_OFF(const SEG_t* SEG)
{
    switch(SEG->common_anode)
    {
        case TRUE:
            for(int i=0;i<8;i++)
                LED_ON(&(SEG->SEGMENTS[i]));
            break;
            
        case FALSE:
            for(int i=0;i<8;i++)
                LED_OFF(&(SEG->SEGMENTS[i]));
            break;
    }
}

void SEG_INIT(SEG_t* SEG,
              char PORT_A,uint8_t PIN_A,
              char PORT_B,uint8_t PIN_B,
              char PORT_C,uint8_t PIN_C,
              char PORT_D,uint8_t PIN_D,
              char PORT_E,uint8_t PIN_E,
              char PORT_F,uint8_t PIN_F,
              char PORT_G,uint8_t PIN_G,
              char PORT_DP,uint8_t PIN_DP,
              bool_t is_common_anode)
{
    LED_INIT (&(SEG->SEGMENTS[0]),PORT_A,PIN_A);
    LED_INIT (&(SEG->SEGMENTS[1]),PORT_B,PIN_B);
    LED_INIT (&(SEG->SEGMENTS[2]),PORT_C,PIN_C);
    LED_INIT (&(SEG->SEGMENTS[3]),PORT_D,PIN_D);
    LED_INIT (&(SEG->SEGMENTS[4]),PORT_E,PIN_E);
    LED_INIT (&(SEG->SEGMENTS[5]),PORT_F,PIN_F);
    LED_INIT (&(SEG->SEGMENTS[6]),PORT_G,PIN_G);
    LED_INIT (&(SEG->SEGMENTS[7]),PORT_DP,PIN_DP);
    SEG->common_anode = is_common_anode;
    SEG_OFF(SEG);
}

/**
 * 
 * @param SEG
 * @param SEG_STATES array of states maps as following [A,B,C,D,E,F,G,DP] where each
 * index holds a value either LOW or HIGH.
 */
void SEG_DRAW(  const SEG_t* SEG,state_t SEG_STATES[8])
{
    for(int i=0;i<8;i++)
    {
        if(SEG_STATES[i]^SEG->common_anode)
            LED_ON (&(SEG->SEGMENTS[i]));
        else
            LED_OFF (&(SEG->SEGMENTS[i]));
    }
}

void SEG_DISPLAY_HEX(const SEG_t* SEG,uint8_t digit,state_t DP)
{
    state_t SEG_STATES[8]={LOW}; //[a,b,c,d,e,f,g,DP]
    SEG_STATES[7]=DP;
    switch(digit)
    {
        case 0:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            break;
            
        case 1:
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            break;
            
        case 2:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 3:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 4:
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 5:
            SEG_STATES[0]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 6:
            SEG_STATES[0]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 7:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[5]=HIGH;
            break;
            
        case 8:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 9:
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 0xA:
        case 'A':
        case 'a':
            SEG_STATES[0]=HIGH;
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 0xB:
        case 'B':
        case 'b':
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 0xC:
        case 'C':
        case 'c':
            SEG_STATES[0]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            break;
            
        case 0xD:
        case 'D':
        case 'd':
            SEG_STATES[1]=HIGH;
            SEG_STATES[2]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 0xE:
        case 'E':
        case 'e':
            SEG_STATES[0]=HIGH;
            SEG_STATES[3]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        case 0xF:
        case 'F':
        case 'f':
            SEG_STATES[0]=HIGH;
            SEG_STATES[4]=HIGH;
            SEG_STATES[5]=HIGH;
            SEG_STATES[6]=HIGH;
            break;
            
        default:
            return;
    }
    SEG_DRAW (SEG,SEG_STATES);
}