/*
 * gpio.c
 *
 * Created: 25-Sep-22 7:08:15 PM
 *  Author: s-abd
 */ 

//Includes
#include <stdio.h>
#include "..\..\Utilities\bit_operations.h"
#include "..\..\Utilities\MCU_registers.h"
#include "gpio.h"

//Functions definitions
EN_error gpio_init	(Port port, char pinNum, PinDirection direct)
{
	//General function flow
		//1. Determine the port based on value of port
		//2. Using pin_Num, sit the chosen pin in register DDRx to input or output based on value of direct.
	//Code
	switch (port) {
		case PORT_A:
			if(direct==Input)
			{
				SET_LOW(DDRA,pinNum);
			}
			else
			{
				SET_HIGH(DDRA,pinNum);
			}
			break;
		case PORT_B:
			if(direct==Input)
			{
				SET_LOW(DDRB,pinNum);
			}
			else
			{
				SET_HIGH(DDRB,pinNum);
			}
			break;
		default:
			return gpio_err; //printf("Error! Could not initialize GPIO");
			break;
	}
	return no_err;
}
EN_error gpio_set_value	(Port port, char pinNum, bitValue value)
{
	//General function flow
		//1. Determine the port based on value of port
		//2. Using pin_Num, sit the chosen pin in register PORTx to HIGH or LOW based on value of "value".
	//Code
	switch (port) {
		case PORT_A:
		if(value==LOW)
		{
			SET_LOW(PORTA,pinNum);
		}
		else
		{
			SET_HIGH(PORTA,pinNum);
		}
		break;
		case PORT_B:
		if(value==LOW)
		{
			SET_LOW(PORTB,pinNum);
		}
		else
		{
			SET_HIGH(PORTB,pinNum);
		}
		break;
		default:
		return gpio_err; //printf("Error! Could not set GPIO value");
		break;
	}
	return no_err;
}
EN_error gpio_get_value	(Port port, char pinNum, char* value)
{
	//General function flow
		//1. Determine the port based on value of port
		//2. Using pin_Num, get the value of the chosen pin from register PINx and put it in the pointer "value".
	//Code
	switch (port) {
		case PORT_A:
		READ_BIT(PINA,pinNum,*value);
		break;
		case PORT_B:
		READ_BIT(PINB,pinNum,*value);		
		break;
		default:
		return gpio_err; //printf("Error! Could not read GPIO value");
		break;
	}
	return no_err;
}
EN_error gpio_toggle	(Port port, char pinNum)
{
	//General function flow
		//1. Determine the port based on value of port
		//2. Using pin_Num, toggle the chosen pin in register PORTx.
	//Code
	switch (port) {
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNum);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,pinNum);
		break;
		default:
		return gpio_err; //printf("Error! Could not toggle GPIO");
		break;
	}
	return no_err;
}
void test_gpio		(void)	//call driver's APIs and validate their outputs
{
	//Test flow: do the following, and see the result in simulator.
		//1. gpio_init: Make pin0 of portA as output AND make pin0 of portB as input.
		//2. gpio_set_value: Make pin0 of portA HIGH/LOW. 
		//3. gpio_toggle: toggle pin0 of portA.
		//4. gpio_get_value: Make make pin0 of portB HIGH/LOW and read.
	//Code
	EN_error error = no_err;
	char	pin_value = 5;
	error = gpio_init(PORT_A,0,Output);
	error = gpio_init(PORT_B,0,Input);
	error = gpio_set_value(PORT_A,0,HIGH);
	error = gpio_set_value(PORT_A,0,LOW);
	error = gpio_toggle(PORT_A, 0);
	//Set pin0 of portB to HIGH
	
	gpio_get_value(PORT_B,0,&pin_value);
	if (error!=no_err)
	{
		printf("ERROR");
	}
}