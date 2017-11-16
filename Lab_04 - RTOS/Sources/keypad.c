#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"
#include <stdio.h>
#define DELAY_T	150

GPIO_InitTypeDef GPIO_InitCol;
GPIO_InitTypeDef GPIO_InitRow;

/**
  * @brief  convert char to int data type
  * @param  char value to convert
  * @retval converted int value
  */
int char_to_int(char c) 
{
	int convert = c - '0';
	
	return convert;
}

// gpio init function(not used)
void GPIO_KP_init(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	/* Configure GPIOs for keypad columns */
	GPIO_InitCol.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10; 
	GPIO_InitCol.Mode = GPIO_MODE_INPUT; 
	GPIO_InitCol.Pull = GPIO_PULLDOWN;
	GPIO_InitCol.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOD,&GPIO_InitCol); 
	 
	/* Configure GPIOs for keypad rows */
	GPIO_InitRow.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15; 
	GPIO_InitRow.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitRow.Pull = GPIO_NOPULL;
	GPIO_InitRow.Speed = GPIO_SPEED_FREQ_MEDIUM; 
	HAL_GPIO_Init(GPIOB,&GPIO_InitRow);

}

/**
  * @brief  wait until a key is pressed 
  * @param  none
  * @retval pressed key value as char
  */
char wait_key(void) 
{
	char wait = 0;
	
	while(!(wait)) 
	{
		wait = read_keypad();
		HAL_Delay(100);
	}	
	printf("key: %c\n", wait);
	return wait;
}

/**
  * @brief  Read value from 4x3 keypad
  * @param  None
  * @retval Pressed char value
  */
char read_keypad(void)
{
	//GPIO_KP_init();
	// scan row 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
		return '1';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1)
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
		return '2';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
		return '3';
	}
	// scan row 2
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
		return '4';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1)
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
		return '5';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
		return '6';
	}
	// scan row 3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
		return '7';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1)
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
		return '8';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
		return '9';
	}
	// scan row 4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
		return '*';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1)
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
		return '0';
	}
	else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1) 
	{
		while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
		return '#';
	}
	
	return 0;
}


/**
  * @brief  get angle from keypad input
  * @param  none
  * @retval int angle
  */
int get_angle(void) 
{
	int angle = 0;
	char key_temp = 0;
	
	// while user didn't press enter
	while(key_temp != '#') 
	{
		key_temp = wait_key();
		
		if(key_temp != '*' && key_temp != '#')
		{
			angle = angle*10 + char_to_int(key_temp);
			printf("angle: %d\n", angle);
		}
		else if (key_temp == '*') 
		{
			angle = (int) angle/10;
			printf("angle: %d\n", angle);
		}
	}
	
	printf("Input angle is : %d\n", angle);
	
	return angle;
}


