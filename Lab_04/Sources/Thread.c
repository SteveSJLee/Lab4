#include "cmsis_os.h"
#include "stm32f4xx_hal.h"   
#include "leddisplay.h"

osThreadId tid_thread1;                          // ID for thread 1
osThreadId tid_thread2;                          // ID for thread 2
  
osSemaphoreId semaphore;                         // Semaphore ID
osSemaphoreDef(semaphore);                       // Semaphore definition

int digitIndex = 0;
int counter = 0;
int digit[4] = {1,2,3,3};
//
//   Thread 1 - High Priority - Active every 3ms
//
void thread1 (void const *argument) {
  while (1) {
      osDelay(1);                                // Pass control to other tasks for 3ms
    
		osSemaphoreWait (semaphore, osWaitForever);        // Wait 1ms for the free semaphore
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
      osSemaphoreRelease (semaphore);            // Return a token back to a semaphore
    }
  }

  
//
//   Thread 2 - Normal Priority - looks for a free semaphore and uses
//                                the resource whenever it is available
//
void thread2 (void const *argument) {
  while (1) {
			osDelay(1);
    osSemaphoreWait (semaphore, osWaitForever);  // Wait indefinitely for a free semaphore
		
		for(int i=0; i<500; i++){
		showDigit(digit[digitIndex],digitIndex+1);
		digitIndex = (digitIndex+1) % 4;
		HAL_Delay(1);
		}																				// OK, the interface is free now, use it.
    osSemaphoreRelease (semaphore);              // Return a token back to a semaphore.
  }
}
  
// Thread definitions 
osThreadDef(thread1, osPriorityLow,   1, 0);
osThreadDef(thread2, osPriorityHigh, 500, 0);
GPIO_InitTypeDef 				LED_configuration;   
void StartApplication (void) {
  semaphore = osSemaphoreCreate(osSemaphore(semaphore), 1);
  tid_thread1 = osThreadCreate(osThread(thread1), NULL);
  tid_thread2 = osThreadCreate(osThread(thread2), NULL);
}

	void initializeLED_IO (void){
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	LED_configuration.Pin		= GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	LED_configuration.Mode 	= GPIO_MODE_OUTPUT_PP;
	LED_configuration.Speed	= GPIO_SPEED_FREQ_VERY_HIGH;
	LED_configuration.Pull	= GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD, &LED_configuration);	
}
/*----------------------------------------------------------------------------
 *      
 *---------------------------------------------------------------------------*/