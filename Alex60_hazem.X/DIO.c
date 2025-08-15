#include "DIO.h"

uint8 getPINA(uint8 pinNum)
{
    if(PINA & (1<<pinNum))
        return 1;
    else
        return 0;
}

void togglePORTA()
{
    PORTA ^= 0xff;
}