/*
 * motor.c
 *
 * Created: 2021-12-29 오후 3:45:09
 *  Author: ncslab
 */ 
#include "motor.h"
char out_data0[4]={0x01, 0x02, 0x04, 0x08};
char out_data2[4]={0x10, 0x20, 0x40, 0x80};
void motor0_init(){
	cli();
	DDRA |=0x0F;
	TCCR0 = 0x0F;
	OCR0 = 0xFF;
	TCNT0 = 0x00;
	ASSR = 0x00;
	TIMSK |= 0x02;
	TIFR &= ~(0x03);
	sei();
	i=0;
	PORTA = 0x00;
	prevport0 = 0x00;
}
void motor2_init(){
	cli();
	DDRA |=0xF0;
	TCCR2 = 0x0D;
	OCR2 = 0xFF;
	TCNT0 = 0x00;
	ASSR = 0x00;
	TIMSK |= 0x80;
	TIFR &= ~(0xC0);
	sei();
	j=0;
	PORTA = 0x00;
	prevport2 = 0x00;
}
ISR(TIMER0_COMP_vect){
	if(leftipps<0) {
		PORTA |= out_data0[3-i%4];
		PORTA &= (~prevport0);
		prevport0 = out_data0[3-i%4];
	}
	else {
		PORTA |= out_data0[i%4];
		PORTA &= (~prevport0);
		prevport0 = out_data0[i%4];
	}
	i++;
}
ISR(TIMER2_COMP_vect){
	if(rightipps<0) {
		PORTA |= out_data2[3-j%4];
		PORTA &= (~prevport2);
		prevport2 = out_data2[3-j%4];
	}
	else {
		PORTA |= out_data2[j%4];
		PORTA &= (~prevport2);
		prevport2 = out_data2[j%4];
	}
	j++;
}
void motor0_set(int leftspeed){
	leftipps = leftspeed;
	if(leftipps==0) TIMSK &= ~(0x03);
	else {OCR0 = 15625/abs(leftipps)-1;TIMSK |= 0x02;}
}
void motor2_set(int rightspeed){
	rightipps = rightspeed;
	if(rightipps==0) TIMSK &= ~(0xC0);
	else {OCR2 = 15625/abs(rightipps)-1; TIMSK |= 0x80;}
}