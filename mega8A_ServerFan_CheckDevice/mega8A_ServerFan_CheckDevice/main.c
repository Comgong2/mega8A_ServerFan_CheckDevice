/*
 * mega8A_ServerFan_CheckDevice.c
 *
 * Created: 2018-06-19 오후 5:39:45
 * Author : juwon
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1000000UL

int T0_Counter = 30,
MCU_LED = 0,
for_G_LED = 1;

ISR(TIMER0_OVF_vect)
{
	TCNT0 = T0_Counter;
}


void RED_LED(void)
{
	
	PORTD = (1 << PORTD6) | (0 << PORTD5) | (1 << PORTD3);
	
}

void GREEN_LED(void)
{
	
	PORTD = (1 << PORTD5);

}

void Timer0_set(void)
{
	TCCR0 = 0x05;
	TIMSK = 0x01;
	TCNT0 = 216;
}

void PORT_set(void)
{
	DDRD = (1 << PORTD7) | (1 << PORTD6) | (1 << PORTD5) | (1 << PORTD3) | (1 << PORTD2);
}

void PAN_AL(void)
{
	TCNT0 = 0;
	while(((PINC & (1 << PINC0)) >> PINC0) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC0)) >> PINC0) != 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC0)) >> PINC0) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}

	TCNT0 = 0;
	while(((PINC & (1 << PINC1)) >> PINC1) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC1)) >> PINC1) != 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC1)) >> PINC1) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}

	TCNT0 = 0;
	while(((PINC & (1 << PINC2)) >> PINC2) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC2)) >> PINC2) != 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}
	TCNT0 = 0;
	while(((PINC & (1 << PINC2)) >> PINC2) == 1)
	{
		if (TCNT0 > T0_Counter)
		{
			RED_LED();
			return;
		}
	}

	GREEN_LED();
}

int main(void)
{
	cli();
	Timer0_set();
	PORT_set();
	sei();
	
	for (int i = 0; i <= 10; i++)
	{

		for_G_LED ^= 1;

		PORTD = (for_G_LED << PORTD6) | (1 << PORTD5);

		_delay_ms(400);

	}


	PORTD = (1 << PORTD6) | (1 << PORTD5);
	_delay_ms(400);

	while (1)
	{
		PAN_AL();
	}
	
}

