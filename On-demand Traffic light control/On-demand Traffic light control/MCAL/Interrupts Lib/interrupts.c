/*
 * interrupts.c
 *
 * Created: 28-Sep-22 9:35:17 PM
 *  Author: s-abd
 */ 

//Includes
#include <stdio.h>
#include "..\..\Utilities\bit_operations.h"
#include "..\..\Utilities\MCU_registers.h"
#include "interrupts.h"

//Global variables
char test_int0 = 0;

//Functions definitions
EN_error interrupt_en	(EN_intrpt_src ext_int, EN_intrpt_trgr_typ trigg)
{
	//General function flow
		//1. enable global interrupts.
		//2. choose the interrupt source
			//3. choose trigger type
	//Code
	SET_HIGH(SREG, 7);
	switch (ext_int) {
		case INT_0:
		switch (trigg) 
		{
			case LOW_LVL:
			SET_LOW(MCUCR,0); SET_LOW(MCUCR,1);
			break;
			case ANY_CHNG:
			SET_HIGH(MCUCR,0); SET_LOW(MCUCR,1);
			break;
			case FAL_EDG:
			SET_LOW(MCUCR,0); SET_HIGH(MCUCR,1);
			break;
			case RIS_EDG:
			SET_HIGH(MCUCR,0); SET_HIGH(MCUCR,1);
			break;
			default:
			return intrpt_err; //printf("Error! Could not set trigger method of interrupt");
			break;
		}
		SET_HIGH(GICR,6);	//The default interrupt trigger is LOW. That's why we can't enable INT0 unless we specify the correct trigger first.
							//Otherwise, it will keep triggering the interrupt and the application won't run at all!
		break;
		case INT_1:
		switch (trigg) {
			case LOW_LVL:
			SET_LOW(MCUCR,2); SET_LOW(MCUCR,3);
			break;
			case ANY_CHNG:
			SET_HIGH(MCUCR,2); SET_LOW(MCUCR,3);
			break;
			case FAL_EDG:
			SET_LOW(MCUCR,2); SET_HIGH(MCUCR,3);
			break;
			case RIS_EDG:
			SET_HIGH(MCUCR,2); SET_HIGH(MCUCR,3);
			break;
			default:
			return intrpt_err; //printf("Error! Could not set trigger method of interrupt");
			break;
		}
		SET_HIGH(GICR, 7);
		break;
		case INT_2:
		switch (trigg) {
			case FAL_EDG:
			//.........
			break;
			case RIS_EDG:
			//.........
			break;
			default:
			return intrpt_err; //printf("Error! Could not set trigger method of interrupt");
			break;
		}
		SET_HIGH(GICR, 5);
		break;
		default:
		return intrpt_err; //printf("Error! Could not enable the appropriate external interrupt source");
		break;
	}
	return no_err;
}

void test_interrupt (void)	//call driver's APIs and validate their outputs
{
	//Test flow: do the following, and see the result in simulator (See the Registers).
		//1. interrupt_en: enable INT0, and make it RISING_EDG triggered
		//2. Implement an ISR that prints "Inside INT0 ISR"
		//3. Press pin2 of portD (INT0 button)
		//4. Check if ISR message is printed
	//Code
	EN_error error = no_err;
	error = interrupt_en(INT_0, RIS_EDG);
	if (error!=no_err)
	{
		printf("ERROR");
	}
}

/*
ISR(INT0)
{
	test_int0 = 1;
}
*/