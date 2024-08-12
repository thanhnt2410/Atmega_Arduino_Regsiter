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
	DDRA = 0xff;		//Khai b�o thanh ghi PortA la output
	PORTA = 0x00;		//Khai b�o PA0 t?i PA7 xuat ra 0v
	DDRB = 0x00;		//Chan B0 input
	PORTB = 0x01;		//Chan B0 keo cao
	
    /* Replace with your application code */
    while (1) 
    {
		//PORTA =  0xff;
		//_delay_ms(500);
		//PORTA = 0x00;
		//_delay_ms(500);
		//1<<PINB0 ngh?a l� d?ch bit 1 sang tr�i t?i v? tr� c?a ch�n PINB0. N?u PINB0 l� 0, k?t qu? s? l� 0b00000001. 
		//N?u PINB0 l� 1, k?t qu? s? l� 0b00000010, v� t??ng t? cho c�c v? tr� kh�c.
		//if((PINB &(1<<PINB0))==0)	
		//{
			//PORTA = 0x01;	//output 5v chan A0
			//
		//}
		//else
		//{
			//PORTA = 0x00;	//output 0v chan A0
		//}
		PORTA = 0b11100111;		//?? bit 34 ? 0 th� ?�n s? s�ng
		for(int i =3; i>=0; i--)	//?? led ch?y sang hai b�n
		{
			PORTA &=~ (1<<(i)); //clear bit thu i
			PORTA &=~ (1<<(7-i));
			_delay_ms(200);
			PORTA |= (1<<(i));
			PORTA |=(1<<(7-i));
		}
    }
}

