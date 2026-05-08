
#ifndef DRIVE_MOTOR_UGV_DRIVE_SERVO_H_
#define DRIVE_MOTOR_UGV_DRIVE_SERVO_H_

#include "main.h"
#include "string.h"

typedef struct {
    TIM_HandleTypeDef* htim; // Timer for PWM control
    uint8_t channel;
} MotorControl;

void MotorControl_Init(MotorControl* motor, TIM_HandleTypeDef* timer, uint8_t ch);
void MotorControl_SetSpeed(MotorControl* motor, float velocity, int dc);

#endif /* DRIVE_MOTOR_UGV_DRIVE_SERVO_H_ */
