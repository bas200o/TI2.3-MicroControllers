#define F_CPU 16e6

#include <avr/io.h>
#include <util/delay.h>



void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

const unsigned char
NUMBERS[17] =
{
// dPgfedcba
	0b11111100,	//0
	0b01100000,	//1
	0b11011010,
	0b11110010,
	0b01100110,
	0b10110110,
	0b10111110,
	0b11100000,
	0b11111110,
	0b11110110,
	0b11101111,	//9
	0b00111111,	//a
	0b10011101,
	0b01111011,
	0b11110011,
	0b10001111,	//f
	0b00000001	//error
};

void display(int digit)
{
	if (digit > 15 || digit < 0)
	{
		PORTB = NUMBERS[15];
	}else
	{
		PORTB = NUMBERS[digit];
		
	}
	
}


int main( void )
{
	DDRB = 0b11111111;					// PORTD all output 
	DDRC = 0b11111100;
	
	int ah = 0;
	while (1)
	{

		if (PINC & 0x01)
		{
			ah++;
		}
		
		if (PINA & 0x02)
		{
			ah++;
		}		
		
		if (PINA & 0x03)
		{
			ah = 0;
		}
		
		display(ah);
		wait(10);
	}

	return 1;
}
