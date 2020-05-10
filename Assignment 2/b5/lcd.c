#include "lcd.h"

#define F_CPU 16e6

#include <avr/io.h>
#include <util/delay.h>

#define e PORTD.0
#define rw PORTD.1
#define rs PORTD.2

void init()
{
	PORTD = 0x30
	rs = false;
	e = true;
	_delay_ms( 1 );
	e = false;
	
	PORTD = 0F;
	rs = false;
	e = true;
	_delay_ms( 1 );
	e = false;

}

void display_text(char *str)
{
	PORTD = &str;
	rs = true;
	e = true;
	_delay_ms( 1 );
	e = false;
}

void set_cursor(int position)
{
	PORTD = 128 + position;
	rs = false;
	e = true;
	_delay_ms( 1 );
	e = false;
}
