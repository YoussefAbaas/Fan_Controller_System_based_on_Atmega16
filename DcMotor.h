/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the Dc Motor driver
 *
 * Author: Yousif
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define Motor_PORT_ID         PORTB_ID
#define Motor_FIRST_PIN_ID     PIN0_ID
#define Motor_SECOND_PIN_ID    PIN1_ID
/*******************************************************************************
 *                                Types Definitions                             *
 *******************************************************************************/
typedef enum
{
	Stop,AntiClockwise,Clockwise
}DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the dc motor
 */
void DcMotor_Init(void);
/*
 * Description :
 * Function responsible for controlling dc motor
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
