#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>



void wait(int time) {
	for (int i = 0; i < time; i++){
		_delay_ms(1);
	}
}

void setCharliePlexingLed(int led)
{
		if (led == 0)
		{
			DDRA = 0x00;
		} 
		else if (led == 1)
		{
			DDRA = 0b00000011;
			PORTA = 0b00000001;
		}
		else if (led == 2)
		{
			DDRA = 0b00000011;
			PORTA = 0b00000010;
		}
		else if (led == 3)
		{
			DDRA = 0b00000110;
			PORTA = 0b00000010;
		}
		else if (led == 4)
		{
			DDRA = 0b00000110;
			PORTA = 0b00000100;
		}
		else if (led == 5)
		{
			DDRA = 0b00000101;
			PORTA = 0b00000100;
		}		
		else if (led == 6)
		{
			DDRA = 0b00000101;
			PORTA = 0b00000001;
		}	
}


void main()
{
	DDRD = 0b11111111;
	DDRC = 0b11111110;
	char led = 0;
	bool forward = false;
	bool noDelay = false;
	
	while (1)
	{
		if (led == 0 || led == 7){
			forward = !forward;
		}
		
		if (forward)
		{
			led++;
		}else{
			led--;
		}
		
		setCharliePlexingLed(led);
		
		if (!noDelay) // if disabled all leds will apear to be on
		{
			wait(500);
		}
			
				
	}

	return 1;
}
