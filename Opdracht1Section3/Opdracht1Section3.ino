/*
Name:		Opdracht1Section3.ino
Created:	12/9/2016 7:14:56 PM
Author:	Tim Hintzbergen
Exercise: S3 - 1.19
*/

int main(void) {
	DDRC = 0b10000000; //Defines pin 7 as output, which is interesting since it is a "Don't Care" pin...

	while (1) {
		byte incoming = PINB; //Read all 8 bits from B
		PORTC |= (incoming & (1 << PB5)) << 2; //Read bit 5 from incoming. Then shift it two to the left in order to assign it to PC7
	}
}