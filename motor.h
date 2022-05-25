/*
 * motor.h
 *
 * Created: 2021-12-29 오후 3:45:19
 *  Author: ncslab
 */ 
#ifndef MOTOR_H_
#define MOTOR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "usart.h"

int i;
int j;
int leftipps;
int rightipps;
char prevport0;
char prevport2;

void motor0_init();
void motor2_init();
ISR(TIMER0_COMP_vect);
ISR(TIMER2_COMP_vect);
void motor0_set();
void motor2_set();

#endif /* MOTOR_H_ */