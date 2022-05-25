//main.c
//실습과제1번
//#include "main.h"
//int main()
//{
	//char out_data[4]={0x01,0x02,0x04,0x08};
	//int i=0,j=0;
	//DDRA |= 0x0F;
	//while(1){
		//j=i++%4;
		//PORTA=out_data[3-j];
		//_delay_ms(2);
	//}
	//return 0;
//}
//main.c
//실습과제2번
//#include "main.h"
//int main()
//{
	//char out_data[4]={0x03,0x06,0x0C,0x09};
	//int i=0,j=0;
	//DDRA |= 0x0F;
	//while(1){
		//j=i++%4;
		//PORTA=out_data[3-j];
		//_delay_ms(2);
	//}
	//return 0;
//}
//main.c
//실습과제3번
//#include "main.h"
//int main()
//{
	//char out_data[8]={0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09};
	//int i=0,j=0;
	//DDRA |= 0x0F;
	//while(1){
		//j=i++%8;
		//PORTA=out_data[8-j];
		//_delay_ms(2);
	//}
	//return 0;
//}
//main.c
//실습과제4번
//#include "main.h"
//int main()
//{
	//char out_data[4]={0x01, 0x02, 0x04, 0x08};//1상여자
	//int i=0,j=0;
	//DDRA |=0x0F;
	//while(i<100){
		//j = i++%4;
		//PORTA = out_data[j];
		//_delay_ms(2);
	//}
	//return 0;
//}
//main.c
//실습과제5번
//#include "main.h"
//int main()
//{
	//int iangle = 0;
	//int dangle = 0;
	//char out_data[4]={0x01, 0x02, 0x04, 0x08};//1상여자
	//usart0_init();
	//int i,j;
	//DDRA |=0x0F;
	//while(1){
		//i=0;j=0;
		//iangle = usart0_getintnum();
		//dangle = abs((double)iangle/1.8);
		//if(iangle>=0){
			//while(i<dangle){
				//j = i++%4;
				//PORTA = out_data[j];
				//_delay_ms(1000/PPS);
			//}
		//}
		//else{
			//while(i<dangle){
				//j = i++%4;
				//PORTA = out_data[3-j];
				//_delay_ms(1000/PPS);
			//}
		//}
	//}
	//return 0;
//}
//main.c
//실습과제6번
//#include "main.h"
//int main()
//{
	//int ipps = 0;
	//int iangle = 0;
	//
	//motor_init();
	//usart0_init();
	//usart0_printf("\033[H\033[J");
	//
	//while(1){
		//ipps = usart0_getintnum();
		//iangle = usart0_getintnum();
		//motor_play(ipps,iangle);
	//}
	//return 0;
//}
//main.c
//실습과제7번
//#include "main.h"
//int main()
//{
	//motor_init();
	//usart0_init();
	//usart0_printf("\033[H\033[J");
	//int a,b,c;
	//while(1) {
		//a = usart0_getintnum();
		//b = usart0_getintnum();
		//c = usart0_getintnum();
		//motor_set(a,b,c);
	//}
	//return 0;
//}
//main.c
//실습과제8번
//#include "main.h"
//int main()
//{
	//motor_init();
	//usart0_init();
	//usart0_printf("\033[H\033[J");
	//int leftspeed,rightspeed;
	//while(1) {
		//leftspeed = usart0_getintnum();
		//rightspeed = usart0_getintnum();
		//motor_set(leftspeed,rightspeed);
		//_delay_ms(1);
	//}
	//return 0;
//}
//main.c
//실습과제 1번
#include "main.h"
int main()
{
	motor0_init();
	motor2_init();
	usart0_init();
	sensor_init();
	usart0_printf("\033[H\033[J");
	int leftspeed,rightspeed;
	int error= 0;
	while(1) {
		error = get_error();
		leftspeed = 300-error*100;
		rightspeed = 300+error*100;
		motor0_set(-leftspeed);
		motor2_set(rightspeed);
		_delay_ms(30);
	}
	return 0;
}