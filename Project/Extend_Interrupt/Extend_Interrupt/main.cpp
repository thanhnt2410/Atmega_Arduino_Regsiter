/*
 * Extend_Interrupt.cpp
 *
 * Created: 8/8/2024 11:23:37 PM
 * Author : ADMIN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
unsigned char led[10] ={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //Led Katot chung
volatile int i=0;

void effect1()
{
	PORTA=0x01; //xuat ra 5v o chan A0		=>0b00000001<<1 = 0x00000010;
	_delay_ms(200);
	for(int i=0; i<7; i++)
	{
		PORTA = PORTA<<1;	//Dich 1 bit tu trai sang phai
		_delay_ms(200);
	}
}
void effect2()
{
	PORTA = 0x00;// Chan PA xuat ra 0v
	_delay_ms(200);
	for(int i=0; i<4; i++)
	{
		PORTA |= (1<<i);
		PORTA |= 1<<(7-i);
		_delay_ms(200);
	}
}
void effect3()
{
	PORTA = 0x00; //Chan A xuat ra 0v
	_delay_ms(200);
	for (int i=4; i>0; i--)
	{
		PORTA |= (1<<(i-1));
		PORTA |= 1<<(7-(i-1));
		_delay_ms(200);
	}
}
int main(void)
{
	DDRA =0xff ;// output
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff; //D0 la output, D2 la input
	PORTA =0xff; //xuat 5v
	PORTB = 0xff;
	PORTC = 0xff;
	PORTD =(0<<PIND0);	//Chan D0 output 0v
	GICR |=(1<<INT2);	//Ngat 2
	//MCUCR |=(1<<ISC01);	//Ngat suon xuong
	MCUCSR |=(1<<ISC2);		//Ngat suon len
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		if(i==0)
		{
			PORTD = led[i+1];
			effect1();
			
		}
		else if(i==1)
		{
			PORTD =led[i+1];
			effect2();
			
		}
		else if(i==2)
		{
			PORTD =led[i+1];
			effect3();
		}
		else
		{
			break;
		}
    }
}

ISR(INT2_vect)
{
	//if((PIND & (1<<PIND2))==0)	//Neu gia tri nut nhan la 0
	//{
		//i++;
		//if(i>2)
		//{
			//i==0;
		//}
	//}
	i++;
	if(i>2)
	{
		i=0;
	}
}
