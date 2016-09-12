/*
 Name:		Opdracht1.ino
 Created:	12/9/2016 7:14:56 PM
 Author:	Tim Hintzbergen
 Exercise: S1 - 1.7
*/
#include <avr/delay.h>

#define DELAY 100

int main(void) {
	DDRB = 0xFF; //Defines all pins as output

	while (1) {
		PORTB = ~PORTB;
		_delay_ms(DELAY);
	}
}