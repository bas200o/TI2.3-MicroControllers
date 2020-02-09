#include <avr/io.h>
#include <util/delay.h>

void wait(int ms)
{
	for(int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}	
}


void main()
{
	DDRD = 0b11111111;	
	while (1)
	{
		uint8_t modes = 0x01;
		
		for (int i = 0; i < 8; i++)
		{
			PORTD = modes;
			
			wait(50);
			
			modes << 1;			
		}
		
		
		
		
	}
}
