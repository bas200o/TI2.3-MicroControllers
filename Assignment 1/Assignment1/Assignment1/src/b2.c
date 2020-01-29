/*
 * b2.c
 *
 * Created: 29-1-2020 15:19:27
 *  Author: baswi
 */ 

/************************************************************************/
/* B.2: Coding I/O (easy)
	Maak een nieuwe applicatie die beurtelings de LED op PORTD, pin 7 (PORTD.7) en de LED op
	PORTD, pint 6 (PORTD.6) om de 500ms laat oplichten. Ontwikkel de applicatie in de simulator en
	programmeer daarna het board (gaat veel sneller!)                                                                     */
/************************************************************************/



#include <avr/io.h>
#include <util/delay.h>

void wait() {
	for (int i = 0; i < 500; i++){
		_delay_ms(1);
	}
}

void b2() {
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
		PORTD = 0b01000000;
		wait();
		PORTD = 0b00100000;
		wait();
		
	}
}
