
int main(void) {
	DDRB = 0b00000000;

	while (1) {
		if (PINC & (1 << PORTC5)) {
			PORTB = 0x55;
		}
		else {
			PORTB = 0xAA;
		}
	}
}
