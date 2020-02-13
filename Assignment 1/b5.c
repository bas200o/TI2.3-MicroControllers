#define F_CPU 16E6

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

void wait(int time) {
	for (int i = 0; i < time; i++){
		_delay_ms(1);
	}
}


typedef struct { 
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT; 

PATTERN_STRUCT pattern[] = { 
	{0x00, 100}, {0x01, 100}, {0x03, 100}, {0x07, 100}, {0x0f, 100}, {0x1f, 100}, {0x3f, 100}, {0x7f, 100}, {0xff, 100},

	{0xfe, 100}, {0xfc, 100}, {0xf8, 100}, {0xf0, 100}, {0xe0, 100}, {0xc0, 100}, {0x80, 100}, {0x00, 100},
	
	{0x00, 100}, {0x01, 100}, {0x03, 100}, {0x06, 100}, {0x0c, 100}, {0x18, 100}, {0x30, 100}, {0x60, 100}, {0xc0, 100}, {0x80, 100},
	
	{0x00, 0x00}
};


void main()
{
	DDRC = 0xff;					// PORTC all output 
	
	while (1)
	{
		int index = 0;

		while( pattern[index].delay != 0 ) {
			
			// Write data to PORTC	
			PORTC = pattern[index].data;
			
			wait(pattern[index].delay);
			index++;
		}
	}

	return 1;
}
