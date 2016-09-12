/*
Name:		Opdracht1S210.ino
Created:	12/9/2016 7:14:56 PM
Author:	Tim Hintzbergen
Exercise: S2 - 1.10
*/
int main(void) {
	DDRC = 0xFF; //Defines all pins as output

	byte incoming = PINB;
	PORTC = incoming;
}