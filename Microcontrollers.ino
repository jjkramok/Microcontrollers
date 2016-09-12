#include <avr/io.h>
#include <avr/delay.h>

#define NO_OF_LEDS 6
#define DELAY 250

int main(void) {
	
	DDRD = 0b11111100;   // Knightrider led sequence
	DDRB |= (1 << DDB5); // Pin 13 output led
	PORTB |= (1 << PB2); // Pull-up pin 10 (button)

	int i;
	PORTD = 0b0000100;
	while (1) {
		
		if (PINB & (1 << PORTB2)) {
			PORTB ^= (1 << PB5);
			_delay_ms(1000);
		}
		

		/* Knight rider sequence
		for (i = 1; i < NO_OF_LEDS; i++) {
			_delay_ms(DELAY);
			PORTD = (PORTD << 1);
		}
		for (i = 1; i < NO_OF_LEDS; i++) {
			_delay_ms(DELAY);
			PORTD = (PORTD >> 1);
		}
		*/
	}
}

/*  Tekst bij Opdracht 2
De Arduino variant is komt rond de 2748 bytes terwijl de C variant op 396 bytes zit.
Ondanks de Arduino makkelijker te programmeren is geven wij de voorkeur aan de C variant
want deze neemt minder geheugen in beslag.
*/