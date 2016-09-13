/*
Name:		Opdracht1Section3.ino
Created:	12/9/2016 7:14:56 PM
Author:	Tim Hintzbergen
Exercise: S3 - 1.19
*/
#define PORTC7 7

int main(void) {
	DDRC = 0b10000000; //Defines pin 7 as output, which is interesting since it is a "Don't Care" pin...

	while (1) {
		byte incoming = PINB; //Read all 8 bits from B
		byte data = (incoming & (1 << PB5)) << 2; //Read bit 5 from incoming. Then shift it two to the left in order to assign it to PC7 later
		if (data) { //There is a 1 in the data set we can bitewise OR it (we masked out only one bit)
			PORTC |= data;
		}
		else { //The masked bit (bit 5 from incoming) is zero, to set it zero we need the complement of data to set bit 7 to zero
			PORTC &= ~(1 << PORTC7); //Bit 5 of incoming was empty, set bit 7 of C to zero.
		}
	}
}