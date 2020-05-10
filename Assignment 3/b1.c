#define F_CPU 16e6

#include <avr/io.h>
#include <util/delay.h>

#include lcd.h

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int8_t counter = 0;

int main( void )
{
	while(1)
	{
		if (PINC & 0x01) 
		{
			counter++;
			set_cursor(1);
			display_text((char) counter);
		}
	}
}
