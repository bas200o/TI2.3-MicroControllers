/************************************************************************/
/* This is the entry point of the project                                                                     */
/************************************************************************/


#include <avr/io.h>
#include <util/delay.h>



int main() {
	DDRA = 0b11111111;     // set direction to be output
	DDRB = 0xFF;     // set direction to be output
	DDRC = 0xFF;     // set direction to be output
	DDRD = 0xFF;     // set direction to be output
	PORTA = 0x00;    // turn OFF the PORTA leds
	PORTB = 0x00;    // turn OFF the PORTB leds
	PORTC = 0x00;    // turn OFF the PORTC leds
	PORTD = 0x00;    // turn OFF the PORTD leds
	
	char counter;
	
	while (1) {
		
		if (PORTC & 0b00000001)
		{
			PORTD = 0b1111111;
		}
		else
		{
			PORTD = 0b00000000;
		}
		
	}
  
}