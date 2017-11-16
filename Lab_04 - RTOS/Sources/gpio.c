/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */


void MX_GPIO_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();		
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	
	//7-segment display
	GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15; 
	// initialize the 7-segment display for the LEDs pin
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; //set pins to output push pull mode
	GPIO_InitStruct.Pull = GPIO_NOPULL; // no pull for 7-segment pins
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM; //Speed of pin
	
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET); 
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

	/* FOR LEDs
	GPIO_PIN_12 - Green
	GPIO_PIN_13 - Orange
	GPIO_PIN_14 - Red
	GPIO_PIN_15 - Blue
	*/
	GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	//Set up LEDs for alternate function PWM push pull
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	//setting up alternate function on TIM4
	GPIO_InitStruct.Alternate = GPIO_AF2_TIM4; 
	GPIO_InitStruct.Pull = GPIO_NOPULL; // No pull for LEDs pins
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;	//Speed of pin

	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	
}

// 7 segment decoder, given a number between 0 and 9, it turns on/off the proper pins
int segmentDecoder(int value) 
{
	/*
	A = PE8
	B = PE9
	C = PE10
	D = PE11
	E = PE12
	F = PE13
	G = PE14
	*/
	if ( value == 0 ) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
	}
	else if ( value == 1) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
	}
	else if ( value == 2) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	else if ( value == 3) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}		
	else if ( value == 4) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	else if ( value == 5) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	else if ( value == 6) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	else if ( value == 7) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
	}
	else if ( value == 8) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	else if ( value == 9) {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
	}
	//Reset all
	else if ( value == -1){
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8,  GPIO_PIN_RESET); // A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9,  GPIO_PIN_RESET); // B
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); // C
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
	}
	return 0;
}

// Given 4 avaiable digit slots on the LED, useDigit selects which slot to turn on (1 to 4).
void useDigit(int digit)
{
	if ( digit == 1 ){
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
	}
	else if ( digit == 2 ) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);	
	}
	else if ( digit == 3 ) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);	
	}
	else if ( digit == 4 ) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);	
	}

}

// reset all pins
void resetDisplay(void)
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET); 
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
}
