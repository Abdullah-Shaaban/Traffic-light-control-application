/*
 * application.h
 *
 * Created: 25-Sep-22 7:05:31 PM
 *  Author: s-abd
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

//Includes
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../MCAL/Interrupts Lib/interrupts.h"
#include "../MCAL/Timer Driver/timer.h"

//Defines
	//LEDs	
#define port_cars_Rled	PORT_A
#define pin_cars_Rled	2
#define port_cars_Gled	PORT_A
#define pin_cars_Gled	0
#define port_cars_Yled	PORT_A
#define pin_cars_Yled	1
#define port_peds_Rled	PORT_B
#define pin_peds_Rled	2
#define port_peds_Gled	PORT_B
#define pin_peds_Gled	0
#define port_peds_Yled	PORT_B
#define pin_peds_Yled	1
	//Timer
#define TIMER_INIT_VAL	12
#define TIMER_PRESCAL	1024
#define TIMER_OVERFLOWS	20

//Functions prototypes
void app_init();
void app_start();

#endif /* APPLICATION_H_ */