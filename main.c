/*
 * GccApplication2.c
 *
 * Created: 15-05-2019 10:36:25
 * Author : G J S S BHANU
 */ 

#include <avr/io.h>
#define LED PB0


int main(void)
{
	uint8_t timeroverflowcount=0;
	DDRB=0XFF;
	TCNT0=0X00;
	TCCR0=(1<<CS00)|(1<<CS02);
    /* Replace with your application code */
    while (1) 
    {
		while((TIFR&0X01)==0);
		TCNT0=0X00;
		TIFR=0X01;
		timeroverflowcount++;
		if(timeroverflowcount>=5)
		{
			PORTB^=(0X01<<LED);
			timeroverflowcount=0;
		}
	}
}
    


