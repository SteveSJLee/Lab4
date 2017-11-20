#include "cmsis_os.h"
#include "stm32f4xx_hal.h"   
#include "leddisplay.h"
#include "LIS3DSH.h"
#include "filter.h"
#include "keypad.h"
#include "math.h"

osThreadId tid_thread1;                          // ID for thread 1
osThreadId tid_thread2;                          // ID for thread 2
osThreadId tid_thread3;                          // ID for thread 2
  
osSemaphoreId semaphore;                         // Semaphore ID
osSemaphoreDef(semaphore);                       // Semaphore definition

// LED Variables
int digitIndex = 0;
int digit[4] = {0,0,0,0};

// Accelerometer Variables
LIS3DSH_InitTypeDef 		Acc_instance;
float finalAccX;
float finalAccY;
float finalAccZ;
double rollAngle;
double pitchAngle;

// Keypad Variables
int currentKey = -1;
int targetRollAngle  = 0;
int targetPitchAngle = 0;


// Functions declared 
void initializeACC(void);
void displayLED(int);
void computeAngles(void);
//
//   Thread 1 - High Priority - Active every 3ms
//

// Accelerometer Thread
void thread1 (void const *argument) {
		
	float inputBuffer[3];

	initializeACC();

	while (1) {
                                      // Pass control to other tasks for 3ms
			osDelay(10);
			osSemaphoreWait (semaphore, osWaitForever);        // Wait 1ms for the free semaphore
					LIS3DSH_ReadACC(&inputBuffer[0]);
					filterRawData(&inputBuffer[0]);
					finalAccX = getFinalAccX();
					finalAccY = getFinalAccY();
					finalAccZ = getFinalAccZ();
					computeAngles();
			osSemaphoreRelease (semaphore);            // Return a token back to a semaphore
    }
  }

  

//  LED thread
void thread2 (void const *argument) {
  while (1) {
			displayLED(finalAccX);
			osDelay(1);
			osSemaphoreWait (semaphore, osWaitForever);  // Wait indefinitely for a free semaphore
				showDigit(digit[digitIndex],digitIndex+1);
				digitIndex = (digitIndex+1) % 4;
			osSemaphoreRelease (semaphore);              // Return a token back to a semaphore.
		}																				// OK, the interface is free now, use it.
  }
//  Keypad thread
void thread3 (void const *argument) {
  while (1) {
			osDelay(1);
			osSemaphoreWait (semaphore, osWaitForever);
				currentKey = getKeyPressed();
			osSemaphoreRelease (semaphore);              // Return a token back to a semaphore.
		}																				// OK, the interface is free now, use it.
  }  
// Thread definitions 
osThreadDef(thread1, osPriorityNormal, 1, 0);
osThreadDef(thread2, osPriorityNormal, 1, 0);
osThreadDef(thread3, osPriorityNormal, 1, 0);
GPIO_InitTypeDef 				LED_configuration;   
void StartApplication (void) {
  semaphore = osSemaphoreCreate(osSemaphore(semaphore), 2);
  tid_thread1 = osThreadCreate(osThread(thread1), NULL);
  tid_thread2 = osThreadCreate(osThread(thread2), NULL);
	tid_thread3 = osThreadCreate(osThread(thread3), NULL);
}

	void initializeLED_IO (void){
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	LED_configuration.Pin		= GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	LED_configuration.Mode 	= GPIO_MODE_OUTPUT_PP;
	LED_configuration.Speed	= GPIO_SPEED_FREQ_VERY_HIGH;
	LED_configuration.Pull	= GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD, &LED_configuration);	
}
void initializeACC(void)
{
	Acc_instance.Axes_Enable				        = LIS3DSH_XYZ_ENABLE;
	Acc_instance.AA_Filter_BW				        = LIS3DSH_AA_BW_50;
	Acc_instance.Full_Scale					        = LIS3DSH_FULLSCALE_2;
	Acc_instance.Power_Mode_Output_DataRate	= LIS3DSH_DATARATE_100;
	Acc_instance.Self_Test					        = LIS3DSH_SELFTEST_NORMAL;
	Acc_instance.Continous_Update           = LIS3DSH_ContinousUpdate_Enabled;
	
	LIS3DSH_Init(&Acc_instance);	
	
	/* Enabling interrupt conflicts with push button. Be careful when you plan to 
	use the interrupt of the accelerometer sensor connceted to PIN A.0 */
}
void displayLED(int value){
	digit[0] = (value/100)%10;
	digit[1] = (value/10)%10;
	digit[2] = value%10;
	digit[3] = 0;
}
void computeAngles(void){
	// COMPUTE THE ROLL AND PITCH ANGLES.
	rollAngle  = (180/3.141592654) * atan2f(((-1) * finalAccX), finalAccZ);
	pitchAngle = (180/3.141592654) * atan2f(finalAccY, finalAccZ);
	
	if(rollAngle < 0)
	{
		 rollAngle = rollAngle + 360;
	}
	if(pitchAngle < 0)
	{
		 pitchAngle = pitchAngle + 360;
	}
}
/*----------------------------------------------------------------------------
 *      
 *---------------------------------------------------------------------------*/