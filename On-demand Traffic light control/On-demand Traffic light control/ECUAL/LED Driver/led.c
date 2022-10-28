/*
 * led.c
 *
 * Created: 25-Sep-22 7:07:05 PM
 *  Author: s-abd
 */ 

//Includes
#include "..\..\Utilities\bit_operations.h"
#include "led.h"
//Functions prototypes
EN_error led_init	(Port p, char pinNumber)
{
	//General function flow
		//1. It should call the GPIO init function and make the direction always as output.
	//Code
	return gpio_init(p, pinNumber, Output);
}

EN_error led_on		(Port p, char pinNumber)
{
	//General function flow
		//1. It should call the gpio_set_value function and make the value always as HIGH.
	//Code
	return gpio_set_value(p, pinNumber, HIGH);
}

EN_error led_off	(Port p, char pinNumber)
{
	//General function flow
		//1. It should call the gpio_set_value function and make the value always as LOW.
	//Code
	return gpio_set_value(p, pinNumber, LOW);	
}

EN_error led_toggle	(Port p, char pinNumber)
{
	//General function flow
		//1. It should call the gpio_toggle function.
	//Code
	return gpio_toggle(p, pinNumber);
}

void test_led (void)	//call driver's APIs and validate their outputs
{
	//Test flow: do the following, and see the result in simulator (See the Registers).
		//1. led_init: Make pin1 of portA as led.
		//2. led_on: Make pin1 of portA HIGH.
		//3. led_off: Make pin1 of portA LOW.
		//2. led_toggle: Toggle pin1 of portA.
	//Code
	EN_error error = no_err;
	error = led_init(PORT_A,1);
	error = led_on(PORT_A,1);
	error = led_off(PORT_A,1);
	error = led_toggle(PORT_A,1);
	if (error!=no_err)
	{
		printf("ERROR");
	}
}