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
	bool fastMode = false;
	DDRD = 0b11111111;
	DDRC = 0b11111110;
	
	while (1)
	{
		if (PINC & 0x01)
		{
			fastMode = !fastMode;
		}
		
		if (fastMode)
		{
			for (int i = 0; i < 2; i++)			//Blink with speed of 4
			{
				PORTD = 0x80;
				wait(125);
				PORTD = 0x00;
				wait(125);
			}
		} 
		else									//Blink with speed of 1HZ
		
		{
				PORTD = 0x80;
				wait(500);
				PORTD = 0x00;
				wait(500);
		}		
	}

	return 1;
}
