/*
 * timer.h
 *
 * Created: 25-Sep-22 7:08:48 PM
 *  Author: s-abd
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//Includes
#include "..\..\Utilities\types.h"

//Types
typedef enum {normal, ctc} Timer_Mode;
typedef enum {OCF0,TOV0} Timer_Flag;
	
//Functions prototypes
EN_error timer_init		(Timer_Mode mode, char init_value, int prescal_value, char inter_en);
EN_error timer_start	();
EN_error timer_get_state(Timer_Flag flag, char* flag_value);
void	 timer_stop		();
void	 timer_set_val	(char val);
void	 test_timer		(void);

#endif /* TIMER_H_ */