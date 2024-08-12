/*
 * GccApplication1.cpp
 *
 * Created: 8/8/2024 10:35:21 AM
 * Author : ADMIN
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>


int i=0;
int main(void)
{
	DDRA = 0xff;		//Khai báo thanh ghi PortA la output
	PORTA = 0x00;		//Khai báo PA0 t?i PA7 xuat ra 0v
	DDRB = 0x00;		//Chan B0 input
	PORTB = 0x01;		//Chan B0 keo cao
	
    /* Replace with your application code */
    while (1) 
    {
		//PORTA =  0xff;
		//_delay_ms(500);
		//PORTA = 0x00;
		//_delay_ms(500);
		//1<<PINB0 ngh?a là d?ch bit 1 sang trái t?i v? trí c?a chân PINB0. N?u PINB0 là 0, k?t qu? s? là 0b00000001. 
		//N?u PINB0 là 1, k?t qu? s? là 0b00000010, và t??ng t? cho các v? trí khác.
		//if((PINB &(1<<PINB0))==0)	
		//{
			//PORTA = 0x01;	//output 5v chan A0
			//
		//}
		//else
		//{
			//PORTA = 0x00;	//output 0v chan A0
		//}
		PORTA = 0b11100111;		//?? bit 34 ? 0 thì ?èn s? sáng
		for(int i =3; i>=0; i--)	//?? led ch?y sang hai bên
		{
			PORTA &=~ (1<<(i)); //clear bit thu i
			PORTA &=~ (1<<(7-i));
			_delay_ms(200);
			PORTA |= (1<<(i));
			PORTA |=(1<<(7-i));
		}
    }
}

