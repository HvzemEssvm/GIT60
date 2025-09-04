/* 
 * File:   lcd1602.h
 * Author: Lenovo
 *
 * Created on August 30, 2025, 12:34 AM
 */

#ifndef LCD1602_H
#define	LCD1602_H
#include <stdlib.h>
#include "DIO.h"
#include <util/delay.h>

#define __4BIT_MODE__ 

#define RS_CMD LOW
#define RS_DATA HIGH
#define CMD_CLEAR_DISPLAY_RETURN_HOME 0x01
#define CMD_RETURN_HOME 0x02
#define CMD_ENTRY_MODE_LTR 0x06 
#define CMD_ENTRY_MODE_RTL 0x04
#define CMD_4BIT 0x20
#define CMD_4BIT_2LINE 0x28
#define CMD_8BIT 0x30
#define CMD_8BIT_2LINE 0x38
#define CMD_DISPLAY_ON 0x0C 
#define CMD_DISPLAY_OFF 0x08
#define CMD_SHIFT_CURSOR_LEFT 0x10 // 0b00010000
#define CMD_SHIFT_CURSOR_RIGHT 0x14 // 0b00010100
#define CMD_SHIFT_DISPLAY_LEFT 0x18
#define CMD_SHIFT_DISPLAY_RIGHT 0x1C


typedef struct {
  
#ifdef __4BIT_MODE__
  uint8_t PORT_PIN_D[4]; // arr[0] = D4, and so on..
#else
  uint8_t PORT_PIN_D[8]; // arr[0] = D0, and so on..
#endif
  uint8_t PORT_PIN_RS;
  uint8_t PORT_PIN_E;
}lcd1602_t;

#ifdef __4BIT_MODE__
void LCD1602_INIT(lcd1602_t* LCD,uint8_t PORT_PIN_D7,
                  uint8_t PORT_PIN_D6,uint8_t PORT_PIN_D5,
                  uint8_t PORT_PIN_D4,uint8_t PORT_PIN_RS,
                  uint8_t PORT_PIN_E,bool_t two_line_on,
                  bool_t cursor_on,bool_t blink_on);
#else
void LCD1602_INIT(lcd1602_t* LCD,uint8_t PORT_PIN_D7,
                  uint8_t PORT_PIN_D6,uint8_t PORT_PIN_D5,
                  uint8_t PORT_PIN_D4,uint8_t PORT_PIN_D3,
                  uint8_t PORT_PIN_D2,uint8_t PORT_PIN_D1,
                  uint8_t PORT_PIN_D0,uint8_t PORT_PIN_RS,
                  uint8_t PORT_PIN_E,bool_t two_line_on,
                  bool_t cursor_on,bool_t blink_on);
#endif

void LCD1602_CMD(const lcd1602_t* LCD, uint8_t CMD);
void LCD1602_CHAR(const lcd1602_t* LCD, char DATA);
void LCD1602_STR(const lcd1602_t* LCD, char str[]);
void LCD1602_INT(const lcd1602_t* LCD, int32_t val);
void LCD1602_CLEAR_CHAR_RTL(const lcd1602_t* LCD);
void LCD1602_CLEAR_CHAR_LTR(const lcd1602_t* LCD);

#endif	/* LCD1602_H */

