/******************************************************************************
 *
 * Module: DCMotor
 *
 * File Name: DcMotor.c
 *
 * Description: Source file for the DcMotor driver
 *
 * Author: Yousif

 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h"
#include "DcMotor.h"
#include "Pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the Motor:
 * 1. Setup the Motor pins directions by use the GPIO driver.
 * 2. Setup the Motor State to stop.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(Motor_PORT_ID, Motor_FIRST_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(Motor_PORT_ID, Motor_FIRST_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(Motor_PORT_ID, Motor_FIRST_PIN_ID, LOGIC_LOW);
	GPIO_writePin(Motor_PORT_ID, Motor_SECOND_PIN_ID, LOGIC_LOW);
}
/*
 * Description :
 * 1. determine the duty cycle with respect to speed
 * 2. determine state of motor
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle=(uint8)((uint32)(speed*255)/100);
	GPIO_writePort(Motor_PORT_ID, state);
	PWM_Timer0_Init(duty_cycle);
}
