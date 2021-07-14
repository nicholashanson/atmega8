#include <avr/io.h>

int main(void)
{
  DDRC = 0x01;
  PORTC = 0x02;
  while (1) 
  {
    if (PINC & 0x02) 
    {
      PORTC |= 0x01;
		}
		else 
		{
		  PORTC &= 0xFE;
		}
  }
}
