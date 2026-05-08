#include "ugv_drive_servo.h"
#include "string.h"
#include "stdlib.h"

void MotorControl_Init(MotorControl* motor, TIM_HandleTypeDef* timer, uint8_t ch) {
    motor->htim = timer;
    motor->channel = ch;
    HAL_TIM_PWM_Start(motor->htim, motor->channel);
}

void MotorControl_SetSpeed(MotorControl* motor, float velocity, int dc) {
	motor->htim->Instance->CCR1 = dc;
	if (velocity > 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0);
	}
	else if (velocity < 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);
	}
	else {
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0);
	}
}


