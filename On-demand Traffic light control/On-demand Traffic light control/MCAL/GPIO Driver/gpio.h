/*
 * gpio.h
 *
 * Created: 25-Sep-22 7:08:23 PM
 *  Author: s-abd
 */ 

#ifndef GPIO_H_
#define GPIO_H_

//Includes
#include "..\..\Utilities\MCU_registers.h"
#include "..\..\Utilities\bit_operations.h"
#include "..\..\Utilities\types.h"
//#include "..\..\Interrupts Lib\interrupts.h"

//User-Defined Types
typedef enum {PORT_A, PORT_B}	Port;
typedef enum {Input, Output}	PinDirection; //For the DDR, 0=input -- 1=output
typedef enum {LOW,HIGH}			bitValue;

//Functions prototypes
EN_error gpio_init		(Port port, char pinNum, PinDirection direct);
EN_error gpio_set_value	(Port port, char pinNum, bitValue value);
EN_error gpio_get_value	(Port port, char pinNum, char* value);
EN_error gpio_toggle	(Port port, char pinNum);
void	 test_gpio		(void);

#endif /* GPIO_H_ */