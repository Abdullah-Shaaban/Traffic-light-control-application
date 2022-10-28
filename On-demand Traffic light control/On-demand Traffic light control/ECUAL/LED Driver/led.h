/*
 * led.h
 *
 * Created: 25-Sep-22 7:06:54 PM
 *  Author: s-abd
 */ 


#ifndef LED_H_
#define LED_H_

//Includes
#include "..\..\MCAL\GPIO Driver\gpio.h"
#include "..\..\Utilities\types.h"

//Functions prototypes
EN_error led_init	(Port p, char pinNumber);
EN_error led_on		(Port p, char pinNumber);
EN_error led_off	(Port p, char pinNumber);
EN_error led_toggle	(Port p, char pinNumber);
void test_led	(void);

#endif /* LED_H_ */