/*
 * button.c
 *
 * Created: 25-Sep-22 7:06:31 PM
 *  Author: s-abd
 */ 

//Includes
#include "..\..\Utilities\bit_operations.h"
#include "button.h"

//Functions definitions
EN_error butt_init		(Port port, char pinNum)
{
	//General function flow
	//1. It should call the GPIO init function and make the direction always as input.
	//Code
	return gpio_init(port, pinNum, Input);
}
EN_error butt_read_state(Port port, char pinNum, char* butState)
{
	//General function flow
	//1. It should call the GPIO get value function.
	//Code
	return gpio_get_value(port, pinNum, butState);
}
void test_but (void)	//call driver's APIs and validate their outputs
{
	//Test flow: do the following, and see the result in simulator (See the Registers).
		//1. butt_init: Make pin1 of portA as button.
		//2. butt_read_state: Make pin0 of portA HIGH/LOW and read it.
	//Code
	EN_error error = no_err;
	char pin_value = 5;
	error = butt_init(PORT_A,1);
	//Manually set pin1 of portA to HIGH
	error = butt_read_state(PORT_A,1,&pin_value);
	if (error!=no_err)
	{
		printf("ERROR");
	}
}