#include <avr/io.h>
#include <avr/delay.h>

#define NO_OF_LEDS 6
#define DELAY 250

int main(void) {
	init();
	Serial.begin(9600);
	
	DDRD = 0b11111100;   // Knightrider led sequence
	DDRB |= (1 << DDB5); // Pin 13 output led
	PORTB |= (1 << PB2); // Pull-up pin 10 (button)

	int i = 0;
	int dir = 0; //dir 0 => left; dir 1 => right
	PORTD = 0b0000100;
	while (1) {
		//Button
		if (!(PINB & (1 << PORTB2))) {
			PORTB |= (1 << PB5);
			_delay_ms(250); //Sofware matig ontdenderen
			while ((PINB & (1 << PORTB2))) {
				_delay_ms(50);
			}
		}
		PORTB &= ~(1 << PB5);
		
		//Set the leds
		_delay_ms(DELAY);
		PORTD &= 0b00000011; //Clear our six bits designated for the leds we use
		PORTD |= 1 << (i + 2); //Assign the current led in the knightrider sequence
		
		//Increase the bit number
		if (!dir) {
			i++;
		}
		else {
			i--;
		}

		//Change direction of loop
		if (i >= NO_OF_LEDS - 1) {
			dir = 1; //Go down
		} else if(i < 1) {
			dir = 0; //Go up again
		}


		/* Button
		if (!(PINB & (1 << PORTB2))) {
		PORTB |= (1 << PB5);
		_delay_ms(250); //Sofware matig ontdenderen
		while ((PINB & (1 << PORTB2))) {
		_delay_ms(50);
		}
		}
		PORTB &= ~(1 << PB5);
		*/

		/*Knight rider sequence
		for (i = 1; i < NO_OF_LEDS; i++) {
			
			if (!(PINB & (1 << PORTB2))) {
				PORTB |= (1 << PB5);
				_delay_ms(250); //Sofware matig ontdenderen
				while ((PINB & (1 << PORTB2))) {
					_delay_ms(50);
				}
			}
			PORTB &= ~(1 << PB5);

			_delay_ms(DELAY);
			PORTD = (PORTD << 1);
		}
		for (i = 1; i < NO_OF_LEDS; i++) {

			if (!(PINB & (1 << PORTB2))) {
				PORTB |= (1 << PB5);
				_delay_ms(250); //Software matig ontdenderen
				while ((PINB & (1 << PORTB2))) {
					_delay_ms(50);
				}
			}
			PORTB &= ~(1 << PB5);

			_delay_ms(DELAY);
			PORTD = (PORTD >> 1);
		}
		*/
	}
}