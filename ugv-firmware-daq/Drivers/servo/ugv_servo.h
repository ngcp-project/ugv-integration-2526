#include "stm32f7xx_hal.h"


typedef struct{
	TIM_HandleTypeDef* timerInstance;
	volatile long unsigned int* timerCCRX;
	uint16_t timerCh;
	uint16_t timerARR;
	float minPulse; //in microseconds
	float maxPulse; //in microseconds
	float timerPeriod; //in microseconds
	int minPeriod;
	int maxPeriod;
	float setPointAngle; //The commanded angle of motor
	float travelAngle; //The total amount of travel that the motor can turn in degrees
	float travelOffset; //Offset for angle in case there are discrepancies
	float minLimit; //minimum limit before offset
	float maxLimit; //max limit before offset
}ugvServo_t;

/**
 * 	initialize servo to be able to use servo
 *
 * @param s: pointer pointing to servo struct
 */
void ugv_servoInitServo(ugvServo_t *servoM);

/**
 *	Make the servo move to a specific angle
 * @param s
 * @param angle
 */
void ugv_servoSetAngle(ugvServo_t *servoM, float angle);
