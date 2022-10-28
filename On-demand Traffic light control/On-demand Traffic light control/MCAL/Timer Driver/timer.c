/*
 * timer.c
 *
 * Created: 25-Sep-22 7:09:02 PM
 *  Author: s-abd
 */ 

//Includes
#include "..\..\Utilities\bit_operations.h"
#include "..\..\Utilities\MCU_registers.h"
#include "..\..\MCAL\Interrupts Lib\interrupts.h"
#include "timer.h"

//Global variables
char TCCR0_temp;
volatile char test_flag;

//Functions definitions
EN_error timer_init		(Timer_Mode mode, char init_value, int prescal_value, char inter_en)
{
	//General function flow
		//1. set mode of operation, 
			//2. set timer initial value, 
			//3. enable/disable interrupts, 
			//4. “choose” the prescaler value,
	//Code
	switch (mode) 
	{
		case normal:
		TCNT0 = init_value;		//Init value of timer
		if(inter_en)
		{
			SET_HIGH(TIMSK,0);		//Enable overflow interrupt for normal mode
		}
		switch (prescal_value)	//Store prescaler value
		{
			case 1:
			TCCR0_temp |=0x01;
			break;
			case 8:
			TCCR0_temp |=0x02;
			break;
			case 64:
			TCCR0_temp |=0x03;
			break;
			case 256:
			TCCR0_temp |=0x04;
			break;
			case 1024:
			TCCR0_temp |=0x05;
			break;
			default:
			return timr_err; //("Error! Could not set prescaler of Timer0");
			break;
		}
		break;
		case ctc:
		//........
		break;
		default:
		return timr_err; //("Error! Could not initialize Timer0");
		break;
	}
	return no_err;
}
EN_error timer_start()
{
	//General function flow
		//1. change the prescaler bits (of register TCCR0) from 000 to the stored value in TCCR0_temp
	//Code
	if(TCCR0_temp==0)
	{
		return timr_err;
	}
	TCCR0 = TCCR0_temp;
	return no_err;
}
void timer_stop		()
{
	//General function flow
		//1. change the prescaler bits (of register TCCR0) to 000.
	//Code
	TCCR0 &= !(0x07);	// TCCR0 = TCCR0 & !(00000111)
}
void timer_set_val	(char val)
{
	TCNT0 = val;
}
EN_error timer_get_state(Timer_Flag flag, char* flag_value)
{
	//General function flow
		//1. change the prescaler bits (of register TCCR0) to 000.
	//Code
	switch (flag)
	{
		case OCF0:
		READ_BIT(TIFR,0,*flag_value);	//Output Compare Flag 0
		break;
		case TOV0:
		READ_BIT(TIFR,1,*flag_value);	//Timer/Counter0 Overflow Flag
		break;
		default:
		return timr_err; //("Error! Could not get the appropriate flag value");
		break;
	}
	return no_err;
}

void test_timer(void)	//call driver's APIs and validate their outputs
{
	//Test flow: do the following, and see the result in simulator (See the Registers).
		//1. timer_init: choose normal mode, with a prescaler of 1, and no initial value, use built-in clk (should count 256usec), disable interrupts
		//2. timer_start: call the function, and note the time at which this function starts
		//3. timer_get_state: call the function, and note the time at which the outputed flag is HIGH
		//4. timer_stop: call the function, and read the value of TCNT0 multiple times and check it it's the same
	//Code
	EN_error error = no_err;
	SET_HIGH(SREG, 7);	//Enable global interrupt
	timer_init(normal,0,1,1);
	//Note the time
	timer_start();	
	while (test_flag==0)
	{
		//
	}
	//Note the time
	timer_stop();
	for (int i=0; i<3; i++)
	{
		//
	}
	if (error!=no_err)
	{
		printf("ERROR");
	}
}

/*
ISR(TIMER0_OVF)
{
	test_flag = 1;
}
*/