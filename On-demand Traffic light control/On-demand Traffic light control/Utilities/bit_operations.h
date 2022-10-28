/*
 * bit_operations.h
 *
 * Created: 28-Sep-22 9:55:55 PM
 *  Author: s-abd
 */ 


#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#include <stdio.h>


#define SET_HIGH(REG,BIT_NUM)		REG |= 1<<BIT_NUM
#define SET_LOW(REG,BIT_NUM)		REG &= ~(1<<BIT_NUM)
#define TOGGLE_BIT(REG,BIT_NUM)		REG ^= 1<<BIT_NUM
#define	READ_BIT(REG,BIT_NUM,OUT)	OUT  = (REG>>BIT_NUM)&1

#endif /* BIT_OPERATIONS_H_ */