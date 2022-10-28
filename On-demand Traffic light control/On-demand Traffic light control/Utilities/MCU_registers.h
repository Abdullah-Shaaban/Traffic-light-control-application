/*
 * MCU_registers.h
 *
 * Created: 25-Sep-22 7:03:54 PM
 *  Author: s-abd
 */ 


#ifndef MCU_REGISTERS_H_
#define MCU_REGISTERS_H_

//Port A
#define PORTA	*((volatile char*)0x3B) 
#define DDRA	*((volatile char*)0x3A) 
#define PINA	*((volatile char*)0x39) 

//Port B
#define PORTB	*((volatile char*)0x38) 
#define DDRB	*((volatile char*)0x37) 
#define PINB	*((volatile char*)0x36) 

//Interrupts
#define SREG	*((volatile char*)0x5F) 
#define GICR	*((volatile char*)0x5B) 
#define GIFR	*((volatile char*)0x5A) 
#define MCUCR	*((volatile char*)0x55) 
 
//Counter
#define TCCR0	*((volatile char*)0x53) 	//- Timer/Counter control Register
#define TCNT0	*((volatile char*)0x52) 	//- The Timer/Counter Register. 
#define TIFR	*((volatile char*)0x58) 	//- Timer Interrupt Flag Register
#define TIMSK	*((volatile char*)0x59) 	//- Timer Interrupt Mask Register

#endif /* MCU_REGISTERS_H_ */