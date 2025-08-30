#include "lcd1602.h"

#ifdef __4BIT_MODE__
void LCD1602_INIT(lcd1602_t* LCD,uint8_t PORT_PIN_D7,
                  uint8_t PORT_PIN_D6,uint8_t PORT_PIN_D5,
                  uint8_t PORT_PIN_D4,uint8_t PORT_PIN_RS,
                  uint8_t PORT_PIN_E,bool_t two_line_on,
                  bool_t cursor_on,bool_t blink_on)
{
    LCD->PORT_PIN_D[0] = PORT_PIN_D4;
    LCD->PORT_PIN_D[1] = PORT_PIN_D5;
    LCD->PORT_PIN_D[2] = PORT_PIN_D6;
    LCD->PORT_PIN_D[3] = PORT_PIN_D7;
    LCD->PORT_PIN_RS = PORT_PIN_RS;
    LCD->PORT_PIN_E = PORT_PIN_E;
    
    for(int i=0;i<4;i++)
    {
        SET_PIN_DIR (LCD->PORT_PIN_D[i],OUTPUT);
    }
    
    SET_PIN_DIR (PORT_PIN_RS,OUTPUT);
    SET_PIN_DIR (PORT_PIN_E,OUTPUT);
    
    LCD1602_CMD (LCD,0x02);
    
    uint8_t temp_register = CMD_4BIT; // 001 DL N FS X X change to 0b00110000 if 8-bit mode
    temp_register |= two_line_on<<3;
    
    LCD1602_CMD (LCD,temp_register); // 0x28
    _delay_us (50);

    temp_register = CMD_DISPLAY_ON; // 0b00001100;
    temp_register |= (cursor_on<<1) | blink_on; // 0x0F
    
    LCD1602_CMD (LCD,temp_register);
    _delay_us (50);
    
    LCD1602_CMD (LCD,CMD_CLEAR_DISPLAY_RETURN_HOME); // clear cmd and return cursor home 
    _delay_ms (3);
    
    LCD1602_CMD (LCD,CMD_ENTRY_MODE_LTR); // 000001 I/D SH
}
#else
void LCD1602_INIT(lcd1602_t* LCD,uint8_t PORT_PIN_D7,
                  uint8_t PORT_PIN_D6,uint8_t PORT_PIN_D5,
                  uint8_t PORT_PIN_D4,uint8_t PORT_PIN_D3,
                  uint8_t PORT_PIN_D2,uint8_t PORT_PIN_D1,
                  uint8_t PORT_PIN_D0,uint8_t PORT_PIN_RS,
                  uint8_t PORT_PIN_E,bool_t two_line_on,
                  bool_t cursor_on,bool_t blink_on)
{
    LCD->PORT_PIN_D[0] = PORT_PIN_D0;
    LCD->PORT_PIN_D[1] = PORT_PIN_D1;
    LCD->PORT_PIN_D[2] = PORT_PIN_D2;
    LCD->PORT_PIN_D[3] = PORT_PIN_D3;
    LCD->PORT_PIN_D[4] = PORT_PIN_D4;
    LCD->PORT_PIN_D[5] = PORT_PIN_D5;
    LCD->PORT_PIN_D[6] = PORT_PIN_D6;
    LCD->PORT_PIN_D[7] = PORT_PIN_D7;
    LCD->PORT_PIN_RS = PORT_PIN_RS;
    LCD->PORT_PIN_E = PORT_PIN_E;
    
    for(int i=0;i<8;i++)
    {
        SET_PIN_DIR (LCD->PORT_PIN_D[i],OUTPUT);
    }
    
    SET_PIN_DIR (PORT_PIN_RS,OUTPUT);
    SET_PIN_DIR (PORT_PIN_E,OUTPUT);
    
    uint8_t temp_register = CMD_8BIT; // 001 DL N FS X X change to 0b00100000 if 4-bit mode
    temp_register |= two_line_on<<3;
    
    LCD1602_CMD (LCD,temp_register);  // 0x38
    _delay_us (50);
    
    temp_register = CMD_DISPLAY_ON; // 0b00001100;
    temp_register |= (cursor_on<<1) | blink_on; // 0x0F
    
    LCD1602_CMD (LCD,temp_register);
    _delay_us (50);
    
    LCD1602_CMD (LCD,CMD_CLEAR_DISPLAY_RETURN_HOME); // clear cmd and return cursor home 
    _delay_ms (3);
    
    LCD1602_CMD (LCD,CMD_ENTRY_MODE_LTR); // 000001 I/D SH
}
#endif

void LCD1602_EN(const lcd1602_t* LCD)
{
    SET_PIN (LCD->PORT_PIN_E,HIGH);
    _delay_ms (2);
    SET_PIN (LCD->PORT_PIN_E,LOW);
}

void LCD1602_CMD(const lcd1602_t* LCD, uint8_t CMD)
{
    SET_PIN (LCD->PORT_PIN_RS,RS_CMD);
#ifdef __4BIT_MODE__

    for(int i =0;i<4;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],CMD&(1<<(i+4))?HIGH:LOW);
    }
    LCD1602_EN (LCD);
    for(int i =0;i<4;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],CMD&(1<<i)?HIGH:LOW);
    }
    LCD1602_EN (LCD);
#else 
    for(int i=0;i<8;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],CMD&(1<<i)?HIGH:LOW);
    }
    LCD1602_EN (LCD);
#endif
}

void LCD1602_CHAR(const lcd1602_t* LCD, char DATA)
{
    SET_PIN (LCD->PORT_PIN_RS,RS_DATA);
#ifdef __4BIT_MODE__

    for(int i =0;i<4;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],DATA&(1<<(i+4))?HIGH:LOW);
    }
    LCD1602_EN (LCD);
    for(int i =0;i<4;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],DATA&(1<<i)?HIGH:LOW);
    }
    LCD1602_EN (LCD);
#else
    for(int i=0;i<8;i++)
    {
        SET_PIN (LCD->PORT_PIN_D[i],DATA&(1<<i)?HIGH:LOW);
    }
    LCD1602_EN (LCD);
#endif
}

void LCD1602_STR(const lcd1602_t* LCD, char str[])
{
    for(int i =0;str[i]!='\0';i++)
    {
        LCD1602_CHAR (LCD,str[i]);
    }
}

void LCD1602_INT(const lcd1602_t* LCD, int32_t val)
{
    char temp[12];
    sprintf(temp,"%ld",val);
    LCD1602_STR (LCD,temp);
}

void LCD1602_CLEAR_CHAR_LTR(const lcd1602_t* LCD)
{
    LCD1602_CMD (LCD,CMD_SHIFT_CURSOR_LEFT);
    LCD1602_CHAR (LCD,' ');
    LCD1602_CMD (LCD,CMD_SHIFT_CURSOR_LEFT);
}

void LCD1602_CLEAR_CHAR_RTL(const lcd1602_t* LCD)
{
    LCD1602_CMD (LCD,CMD_SHIFT_CURSOR_RIGHT);
    LCD1602_CHAR (LCD,' ');
    LCD1602_CMD (LCD,CMD_SHIFT_CURSOR_RIGHT);
}

