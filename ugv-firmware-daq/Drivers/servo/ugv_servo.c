#include "ugv_servo.h"


void ugv_servoInitServo(ugvServo_t *servoM){
	HAL_TIM_PWM_Start(servoM->timerInstance, servoM->timerCh);

	servoM->maxPeriod = (int) (servoM->timerARR)*(servoM->maxPulse/servoM->timerPeriod);
	servoM->minPeriod = (int) (servoM->timerARR)*(servoM->minPulse/servoM->timerPeriod);

	ugv_servoSetAngle(servoM, servoM->travelOffset);
}

/**
 *	Make the servo move to a specific angle
 * @param s
 * @param angle
 */
void ugv_servoSetAngle(ugvServo_t *servoM, float angle) {
	float setAngle = angle + servoM->travelOffset;

	if ((setAngle) > servoM->maxLimit) {
		*servoM->timerCCRX = (long unsigned int) ((((servoM->maxLimit)
				* (servoM->maxPeriod - servoM->minPeriod))
				/ (servoM->travelAngle)) + servoM->minPeriod);

		servoM->setPointAngle = servoM->maxLimit - servoM->travelOffset;
	} else if ((setAngle) < servoM->minLimit) {
		*servoM->timerCCRX = (long unsigned int) ((((servoM->minLimit)
				* (servoM->maxPeriod - servoM->minPeriod))
				/ (servoM->travelAngle)) + servoM->minPeriod);
		servoM->setPointAngle = servoM->minLimit;
	} else {
		*servoM->timerCCRX = (long unsigned int) ((((setAngle)
				* (servoM->maxPeriod - servoM->minPeriod))
				/ (servoM->travelAngle)) + servoM->minPeriod);
		servoM->setPointAngle = angle;
	}

}
