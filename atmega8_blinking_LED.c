#include <avr/io.h>

#define LED PD4

int main()
{
	DDRD |= (1 << LED);       
	TCCR1B = (1 << CS10) | (1 << CS12);
	OCR1A = 1562;
	TCNT1 = 0;
	while(1)
	{
		while ((TIFR & (1 << OCF1A)) == 0);
		PORTD ^= (1 << LED);
		TCNT1 = 0;
		TIFR |= (1 << OCF1A) ; 
	}
}
