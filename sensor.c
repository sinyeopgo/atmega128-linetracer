//sensor.c
#include "sensor.h"
const char cnumber[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void sensor_init(){
	PORTB = 0x0F;
	DDRB = 0x0;
}
char get_sensor(){
	int index = 0;
	if(PINB&0x01) index+=1;
	if(PINB&0x02) index+=2;
	if(PINB&0x04) index+=4;
	if(PINB&0x08) index+=8;
	
	return cnumber[index];
}
int get_error(){
	return abs((~PINB&0x01)*3-((~PINB&0x02)/2))-abs(((~PINB&0x08)/8)*3-((~PINB&0x04)/4));
}