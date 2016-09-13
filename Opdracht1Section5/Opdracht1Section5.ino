/*
Name:		Opdracht1Section5.ino
Created:	12/9/2016 7:14:56 PM
Author:		Tim Hintzbergen
Exercise:	S5 - 1.35
*/

//We'll just read the first 8 bits since launch of main() since we didn't handle strings and end flags yet.
int main(void) {
	byte incoming = 0x00; //This byte will hold all received bits
	
	int i;
	for (i = 0; i < 8; i++)
		incoming |= ((PINC & (1 << PIN3)) >> PIN3) << i; //Create mask for PC3 and read the bit, then shift back to the LSB, but after each iteration shift one more to the MSB.
}