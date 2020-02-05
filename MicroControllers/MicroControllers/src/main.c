/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <util/delay.h>
#include <avr/io.h>
#include <asf.h>

void wait(int ms)
{

	for (int i = 0; i < ms; i++) {

		_delay_ms(1);
	}
}

int main (void)
{

	/* Insert system clock initialization code here (sysclk_init()). */

	DDRD = 0xff;

	while (1) {

		PORTD = 0x80;
		wait(500);
		PORTD = 0x40;
		wait(500);
	}

	/* Insert application code here, after the board has been initialized. */
}
