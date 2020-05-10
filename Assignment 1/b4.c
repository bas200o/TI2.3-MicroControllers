#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>

char counter;

void wait(int time) {
	for (int i = 0; i < time; i++){
		_delay_ms(1);
	}
}
void main() {
	DDRD = 0xFF;     // set direction to be output
	PORTD = 0x00;    // turn OFF the PORTD leds
	
	while (1) {
		for (counter=0; counter<8; counter++){
			PORTD = 1 << counter;
			wait(500);
		}	
		/************************************************************************/
		/* Niet gelukt om de loop terug te maken.                               */
		/************************************************************************/
		for (counter=8; counter>0; counter--){
			PORTD = 1 >> counter;
			wait(500);
		}
       
	}
}
