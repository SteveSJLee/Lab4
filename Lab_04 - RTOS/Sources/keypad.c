#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"
#include <stdio.h>


GPIO_InitTypeDef GPIO_InitCol;
GPIO_InitTypeDef GPIO_InitRow;

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
  * @brief  read input from keypad
  * @param  None
  * @retval int key
  */
int read_keypad(void)
{
	int key = -1;
	int counter = 0;
	GPIO_KP_init();
	
	while(counter !=4) {
		// scan row 1
		if (counter == 0) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
				key = 1;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) > 0)
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
				key = 2;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
				key = 3;
			}
		}
		// scan row 2
		else if (counter == 1) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
				key = 4;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) > 0)
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
				key = 5;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
				key = 6;
			}
		}
		// scan row 3
		else if (counter == 2) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
				key = 7;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) > 0)
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) == 1);
				key = 8;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
				key = 9;
			}
		}
		// scan row 4
		else if (counter == 3) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8) == 1);
				key = 10;  // this is for *
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) > 0)
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9) > 0);
				return 0;
			}
			else if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) > 0) 
			{
				//while(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == 1);
				key = 11;  // this is for #
			}
		}
		counter += 1;
	}
	return key;
}


void key_press(void) 
{		int pressed_key = -1;
		int key = read_keypad();
		int key_counter = 0;
	
		if(key != -1)
		{
			pressed_key = key;
			printf("key: %d\n", pressed_key);
			if(key_counter < 1000)
			{
				key_counter++;
			}
		}
		else if(key != pressed_key && key == -1)
		{
			printf("The key %d was pressed for %d ms. \n", pressed_key, key_counter * 7);
			//fsmEvent(pressed_key, key_counter);
			pressed_key = -1;
			key_counter = 0;
		}

}

