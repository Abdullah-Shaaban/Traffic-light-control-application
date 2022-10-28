/*
 * button.h
 *
 * Created: 25-Sep-22 7:06:45 PM
 *  Author: s-abd
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//Includes
#include "..\..\MCAL\GPIO Driver\gpio.h"
#include "..\..\Utilities\types.h"

//Functions prototypes
EN_error butt_init		(Port port, char pinNum);
EN_error butt_read_state(Port port, char pinNum, char* butState);
void	 test_but		(void);	//call driver's APIs and validate their outputs

#endif /* BUTTON_H_ */