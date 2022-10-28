/*
 * application.c
 *
 * Created: 25-Sep-22 7:05:41 PM
 *  Author: s-abd
 */ 

//Includes
#include "../Utilities/bit_operations.h"
#include "application.h"

//Types
typedef enum {G_R, Y_R, R_R, Y_YR, R_G, Y_YG} state;	//The color on the left is for cars, the color on the right is for peds.

//Global variables
state current_state = G_R;			//Starting from normal mode where cars led on left=G and ped led on right=R	
volatile char butt_pressed = 0;		//Used to change the current state
volatile char timer_ovf = 0;		//Used to count the number of overflows to achieve 5seconds
volatile char five_sec_passed = 0;	//Used as a flag indicating that 5sec has passed
EN_error	  error = no_err;

//Functions definitions
void app_init()
{
		//Initialize the LEDs
		error = led_init(PORT_A, 0);	error = led_init(PORT_A, 1);	error = led_init(PORT_A, 2);	//Cars LEDs
		error = led_init(PORT_B, 0);	error = led_init(PORT_B, 1);	error = led_init(PORT_B, 2);	//Pedestrians LEDs
		//Initialize the timer
			//The desired time is 5sec. F=1MHz, slect prescaler=1024 -> T_overflow=256*1.024ms=262.144ms 
			//-> Need 5000ms/262.144ms=19.1 Overflows -> Ceil: need 20 Overflows -> initial value=256-(all_ticks/20)=256-(4882.8/20)=11.86=12
			//Enable timer overflow interrupt
		error = timer_init	(normal, TIMER_INIT_VAL, TIMER_PRESCAL, 1);
		//Enable interrupts from INT0
		error = interrupt_en(INT_0,RIS_EDG);
		if (error!=no_err)
		{
			printf("ERROR: could not initialize the application");
		}
}

void app_start()
{
	//General operation
		//Initialize everything
		//Start from State S0 (Cars=G - Peds=R).
		//Go to the next state Sx depending on:
			//whether INT0 fires or not
			//OR when 5sec pass
	//Code
	timer_start();
	switch(current_state)
	{
		case G_R:
			//Change the output (LEDs colors)
			error = led_off	(port_cars_Rled, pin_cars_Rled);
			error = led_off	(port_cars_Yled, pin_cars_Yled);
			error = led_on	(port_cars_Gled, pin_cars_Gled);	//Cars GREEN LED is on
			error = led_on	(port_peds_Rled, pin_peds_Rled);	//Pedestrian RED LED is on
			error = led_off	(port_peds_Yled, pin_peds_Yled);
			error = led_off	(port_peds_Gled, pin_peds_Gled);
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (butt_pressed)
			{
				current_state = Y_YR;
				butt_pressed = 0;
			}
			else if (five_sec_passed)
			{
				current_state = Y_R;
				five_sec_passed = 0;
			}
			break;
		case Y_R:
			//Change the output (LEDs colors)
			error = led_off		(port_cars_Rled, pin_cars_Rled);
			error = led_toggle	(port_cars_Yled, pin_cars_Yled);	//Cars Yellow LED Blinking
			error = led_off		(port_cars_Gled, pin_cars_Gled);
			error = led_on		(port_peds_Rled, pin_peds_Rled);	//Pedestrian RED LED is on
			error = led_off		(port_peds_Yled, pin_peds_Yled);
			error = led_off		(port_peds_Gled, pin_peds_Gled);
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (butt_pressed)
			{
				current_state = Y_YR;
				butt_pressed = 0;
			}
			else if (five_sec_passed)
			{
				current_state = R_R;
				five_sec_passed = 0;
			}
			break;
		case R_R:
			//Change the output (LEDs colors)
			error = led_on	(port_cars_Rled, pin_cars_Rled);		//Cars RED LED is on
			error = led_off	(port_cars_Gled, pin_cars_Gled);
			error = led_off	(port_cars_Yled, pin_cars_Yled);
			error = led_on	(port_peds_Rled, pin_peds_Rled);		//Pedestrian RED LED is on
			error = led_off	(port_peds_Yled, pin_peds_Yled);
			error = led_off	(port_peds_Gled, pin_peds_Gled);
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (butt_pressed)
			{
				current_state = R_G;
				butt_pressed = 0;
			}
			else if (five_sec_passed)
			{
				current_state = G_R;
				five_sec_passed = 0;
			}
			break;
		case Y_YR:
			//Change the output (LEDs colors)
			error = led_off		(port_cars_Rled, pin_cars_Rled);	
			error = led_toggle	(port_cars_Yled, pin_cars_Yled);	//Cars Yellow LED is Blinking
			error = led_off		(port_cars_Gled, pin_cars_Gled);
			error = led_on		(port_peds_Rled, pin_peds_Rled);	//Pedestrian RED LED is on
			error = led_toggle	(port_peds_Yled, pin_peds_Yled);	//Pedestrian YELLOW LED is Blinking
			error = led_off		(port_peds_Gled, pin_peds_Gled);
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (five_sec_passed)
			{
				current_state = R_G;
				five_sec_passed = 0;
				butt_pressed = 0;
			}
			break;
		case R_G:
			//Change the output (LEDs colors)
			error = led_on		(port_cars_Rled, pin_cars_Rled);	//Cars RED LED is on
			error = led_off		(port_cars_Yled, pin_cars_Yled);	
			error = led_off		(port_cars_Gled, pin_cars_Gled);
			error = led_off		(port_peds_Rled, pin_peds_Rled);	
			error = led_off		(port_peds_Yled, pin_peds_Yled);	
			error = led_on		(port_peds_Gled, pin_peds_Gled);	//Pedestrian GREEN LED is on
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (five_sec_passed)
			{
				current_state = Y_YG;
				five_sec_passed = 0;
				butt_pressed = 0;
			}
			break;
		case Y_YG:
			//Change the output (LEDs colors)
			error = led_off		(port_cars_Rled, pin_cars_Rled);	
			error = led_toggle	(port_cars_Yled, pin_cars_Yled);	//Cars YELLOW LED is Blinking
			error = led_off		(port_cars_Gled, pin_cars_Gled);	
			error = led_off		(port_peds_Rled, pin_peds_Rled);	
			error = led_toggle	(port_peds_Yled, pin_peds_Yled);	//Pedestrian YELLOW LED is Blinking
			error = led_on		(port_peds_Gled, pin_peds_Gled);	//Pedestrian Green LED is on
			if (error!=no_err)
			{
				printf("ERROR: app failure");
			}
			//Change application state
			if (five_sec_passed)
			{
				current_state = G_R;
				five_sec_passed = 0;
				butt_pressed = 0;
			}
			break;
	}
}

//External interrupt 0 ISR
ISR(INT0)
{
	butt_pressed = 1;
	//Restart counting
	timer_set_val(TIMER_INIT_VAL);
	timer_ovf = 0;
}

//Timer overflow ISR
ISR(TIMER0_OVF)
{
	timer_ovf++;
	if(timer_ovf>=TIMER_OVERFLOWS)
	{
		timer_ovf		= 0;
		five_sec_passed = 1;
	}
}
