#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "stm32f4xx_hal.h"
#include "gpio.h"

int read_keypad(void);
void GPIO_KP_init(void);

#endif
