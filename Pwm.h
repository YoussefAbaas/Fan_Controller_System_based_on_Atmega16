/******************************************************************************
 *
 * Module: DCMotor
 *
 * File Name: Pwm.h
 *
 * Description: header file for the Pwm driver
 *
 * Author: Yousif

 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the Pwm
 */
void PWM_Timer0_Init(uint8 set_duty_cycle);


#endif /* PWM_H_ */
