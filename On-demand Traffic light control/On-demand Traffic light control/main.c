/*
 * On-demand Traffic light control.c
 *
 * Created: 25-Sep-22 6:59:20 PM
 * Author : s-abd
 */ 

//Includes
#include <stdio.h>
#include "Application\application.h"

int main(void)
{
	//Testing drivers
		//test_gpio();
		//test_but();
		//test_led();
		//test_interrupt();
		test_timer();
		
    /* Application code */
	app_init();
    while (1) 
    {
		app_start();
    }
}