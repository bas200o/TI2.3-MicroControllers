/*
 * b3.c
 *
 * Created: 29-1-2020 15:16:04
 *  Author: baswi
 */ 

#include <avr/io.h>
#include <util/delay.h>

int b3() {
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
		if (PORTC == 0b10000000)
		{
			PORTD = 0b00000001;
		}
		else
		{
			PORTD = 0b00000000;
		}
		
	}
}
