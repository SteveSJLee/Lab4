#include "filter.h"

// THESE VARIABLES STORE THE CURRENT RAW VALUES FROM THE ACCELEROMETER SENSOR.
float accX, accY, accZ;

// THESE CONSTANTS ARE USED TO CALIBRATE THE VALUES OF THE ACCELEROMETER SENSOR.
float	acc11 = 0.00101492331;
float	acc12 = 0.00000698307;
float	acc13 = 0.00000805562;
float	acc10 = 0.00221516886;
float	acc21 = -0.00007170752;
float	acc22 = 0.00095980401;
float	acc23 = 0.00002352682;
float	acc20 = 0.01772957335;
float	acc31 = -0.00010254170;
float	acc32 = -0.00001399401;
float	acc33 = 0.00098730978;
float	acc30 = -0.00523204952;

// THESE VARIABLES STORE THE CURRENT CALIBRATED VALUES.
float normalizedAccX, normalizedAccY, normalizedAccZ;

// Arrays storing last 3 inputs for IIR filter: {x[n], x[n-1], x[n-2]}.
float inputAccX[3] = {0.0, 0.0, 0.0};
float inputAccY[3] = {0.0, 0.0, 0.0};
float inputAccZ[3] = {0.0, 0.0, 0.0};

// Arrays storing last 2 outputs for IIR filter: {y[n-1], y[n-2]}.
float outputAccX[2] = {0.0, 0.0};
float outputAccY[2] = {0.0, 0.0};
float	outputAccZ[2] = {0.0, 0.0};

// THESE CONSTANTS ARE THE IIR FILTER COEFFICIENTS.
float b0 = 0.2;
float b1 = 0.2;
float b2 = 0.2;
float a1 = 0.2;
float a2 = 0.2;

// Stores filtered values {x,y,z}
float finalAcc[3] = {0,0,0};

void filterRawData(float* inputBuffer) {
	
	// Get Raw Accelerometer Data
	accX = (float)inputBuffer[0];
	accY = (float)inputBuffer[1];
	accZ = (float)inputBuffer[2];
	
	// Calibrate Raw Data
	normalizedAccX = (accX * acc11) + (accY * acc12) + (accZ * acc13) + acc10;
	normalizedAccY = (accX * acc21) + (accY * acc22) + (accZ * acc23) + acc20;
	normalizedAccZ = (accX * acc31) + (accY * acc32) + (accZ * acc33) + acc30;
	
	// FILTER THE ACCELEROMETER VALUES.
	
	// Shift input array

	for (int i=2; i>0; i--) {
		inputAccX[i] = inputAccX[i-1];
		inputAccY[i] = inputAccY[i-1];
		inputAccZ[i] = inputAccZ[i-1];
	}
	// Store in input array
	inputAccX[0] = normalizedAccX;
	inputAccY[0] = normalizedAccY;
	inputAccZ[0] = normalizedAccZ;
	
	// Perform IIR filter
	finalAcc[0] = (b0 * inputAccX[0]) + (b1 * inputAccX[1]) + (b2 * inputAccX[2]) + (a1 * outputAccX[0]) + (a2 * outputAccX[1]);
	finalAcc[1] = (b0 * inputAccY[0]) + (b1 * inputAccY[1]) + (b2 * inputAccY[2]) + (a1 * outputAccY[0]) + (a2 * outputAccY[1]);
	finalAcc[2] = (b0 * inputAccZ[0]) + (b1 * inputAccZ[1]) + (b2 * inputAccZ[2]) + (a1 * outputAccZ[0]) + (a2 * outputAccZ[1]);
	
	// Update Output array
	outputAccX[1] = outputAccX[0];
	outputAccX[0] = finalAcc[0];
	outputAccY[1] = outputAccY[0];
	outputAccY[0] = finalAcc[1];
	outputAccZ[1] = outputAccZ[0];
	outputAccZ[0] = finalAcc[2];
}
float getFinalAccX(void){
	return finalAcc[0];
}
float getFinalAccY(void){
	return finalAcc[1];
}
float getFinalAccZ(void){
	return finalAcc[2];
}
