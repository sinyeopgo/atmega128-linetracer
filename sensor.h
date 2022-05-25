//sensor.h
#ifndef SENSOR_H_
#define SENSOR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "usart.h"

void sensor_init();
char get_sensor();
int get_error();

#endif /* SENSOR_H_ */