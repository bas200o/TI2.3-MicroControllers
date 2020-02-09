#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>



void wait(int time) {
	for (int i = 0; i < time; i++){
		_delay_ms(1);
	}
}

void main()
{
	DDRD = 0b11111111;
	DDRC = 0b11111110;
	
	while (1)
	{
		
		int led = 1;
		
		if (led == 0)
		{
			DDRA = 0x00;
		} 
		else if (led == 1)
		{
			DDRA = 0b00000011;
			PORTA = 0b00000001;
		}
		
		
		
		
	}

	return 1;
}
