/*
 * interrupts.h
 *
 * Created: 25-Sep-22 7:08:33 PM
 *  Author: s-abd
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

//Includes
#include "..\..\Utilities\types.h"

//Types
typedef enum {INT_0, INT_1, INT_2} EN_intrpt_src;
typedef enum {LOW_LVL, ANY_CHNG, FAL_EDG, RIS_EDG} EN_intrpt_trgr_typ;

//And define ISR function-like macro
#define ISR(int_vect)	void int_vect(void) __attribute__ ((signal,used)); \
						void int_vect(void)

//Interrupt vectors
#define _VECTOR(N) __vector_ ## N
#define INT0 _VECTOR(1)
#define TIMER0_OVF _VECTOR(11)

//Functions prototypes
EN_error interrupt_en	(EN_intrpt_src ext_int, EN_intrpt_trgr_typ trigg);
void test_interrupt (void);

#endif /* INTERRUPTS_H_ */