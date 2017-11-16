#include "gpio.h"
#include "leddisplay.h"

/**
  * @brief  Configure LED SEGMENT GPIOs for digit display.
  * @param  int number: desired number to be configured on LED SEGMENT GPIOs
  * @retval None
  */
void segmentDecoder(int number) 
{   
    switch(number) 
    {
      case 0:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
        break;
      
      case 1:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
        break;
        
      case 2:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 3:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 4:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 5:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 6:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 7:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); // G
        break;
      
      case 8:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
      
      case 9:
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // A
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // B
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); // C
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); // D
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); // E
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET); // F
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); // G
        break;
	}
}
/**
  * @brief  Select digit (1 to 4)
  * @param  int digit: desired digit to be turned on (1 being left most digit, 4 being right most digit)
  * @retval None
  */
void useDigit(int digit)
{
  if ( digit == 1 ){
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
	}
	else if ( digit == 2) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);		
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);	
	}
	else if ( digit == 3 ) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
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
/**
  * @brief  Set LIS3DSH Initialization.
  * @param  LIS3DSH_Config_Struct: pointer to a LIS3DSH_Config_TypeDef structure
  *         that contains the configuration setting for the LIS3DSH.
  * @retval None
  */
void showDigit(int number, int trgtDigit)
{ 
  useDigit(trgtDigit);
  segmentDecoder(number);
}
/**
  * @brief  Turn off all segments on LED (no digit to display).
  * @param  None
  * @retval None
  */
void resetDisplay(void)
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET); 
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
}

