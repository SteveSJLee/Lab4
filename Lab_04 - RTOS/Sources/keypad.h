#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "stm32f4xx_hal.h"
#include "gpio.h"

int char_to_int(char c);
char read_keypad(void);
char wait_key(void); 
int get_angle(void);

#endif
