#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "DcMotor.h"
int main(void)
{

	uint8 temp;
	ADC_ConfigType Adc_config={Internal_Voltage,F_CPU_8};
	LCD_init(); /* initialize LCD driver */
	ADC_init(&Adc_config); /* initialize ADC driver */
	DcMotor_Init();

	while(1)
	{

		temp = LM35_getTemperature();
		LCD_moveCursor(0,4);
		if(temp<30)
		{
			DcMotor_Rotate(Stop, 0);
			LCD_displayString("Fan is off");
		}
		else if(temp>=30&&temp<60)
		{
			DcMotor_Rotate(Clockwise, 25);
			//LCD_moveCursor(1,7);
			LCD_displayString("Fan is on ");
		}
		else if(temp>=60&&temp<90)
		{
			DcMotor_Rotate(Clockwise, 50);
			//	LCD_moveCursor(1,7);
			LCD_displayString("Fan is on ");
		}
		else if(temp>=90&&temp<120)
		{
			DcMotor_Rotate(Clockwise, 75);
			//LCD_moveCursor(1,7);
			LCD_displayString("Fan is on ");
		}
		else if(temp>=120)
		{
			DcMotor_Rotate(Clockwise, 100);
			//	LCD_moveCursor(1,7);
			LCD_displayString("Fan is on ");

		}

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,4);
		LCD_displayString("Temp =");
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		LCD_displayString("C");

	}



}
