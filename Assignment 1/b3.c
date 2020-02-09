#include <avr/io.h>
#include <util/delay.h>

void main()
{
	// set PORTD for output
	DDRD = 0b11111111;					// PORTD.7 input all other bits output 		
	DDRC = 0b11111110;
	
	while (1)
	{
		if (PINC & 0x01) 
		{
			PORTD = 0x80;				// write 1 to all the bits of PortD
		}
		else 
		{
			PORTD = 0x00;				// write 0 to all the bits of PortD
		}
	}

	return 1;
}
