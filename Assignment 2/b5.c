#define F_CPU 16e6

#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = {
	{0x80, 100}, {0x40, 100}, {0x20, 100}, {0x10, 100}, {0x08, 100}, {0x04, 100}, {0x80, 100},
		
	{0x80, 100}, {0x44, 100}, {0x02, 100}, {0x28, 100}, {0x10, 100},

	{0x00, 0}
	
};

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

const unsigned char
NUMBERS[37] =
{
// introducing the Alphablyat
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
	0b11101110,	//9
	0b00111111,	//a
	0b10011101,
	0b01111011,
	0b11110011,
	0b10001111,	//f
	0b11101111, //g
	0b00101111, //h
	0b01100000, //i
	0b01110000, //j
	0b01101111, //k
	0b00011101, //l
	0b11110011, // sideways m
	0b11000011,
	0b11111101,
	0b11001111,
	0b11111101, //q
	0b11101111,
	0b10110111,
	0b11100001, //t
	0b01111101, //u
	0b00111001,
	0b10011111,
	0b01100011, //x
	0b01100111,
	0b11011011,
	
	0b00000001	//error
};

void display(int digit)
{
	
	PORTB = NUMBERS[digit];		
	
}

// work in progress
int main( void )
{
	DDRB = 0b11111111;
	
	int index = 0;
	while (1)
	{
		display(index);
		index++;
		wait(200);
	}

	return 1;
}
