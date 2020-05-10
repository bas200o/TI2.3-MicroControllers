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

int main( void )
{
	init();
	display_text('h');
	set_cursor(2);
	display_text('e');
	display_text('y');
}
