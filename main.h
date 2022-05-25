//main.h
#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#define TRUE 1
#define FALSE 0
#define STEP 100 //회전스텝수
#define PPS 500 //회전속도

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "motor.h"
#include "usart.h"
#include "sensor.h"

#endif