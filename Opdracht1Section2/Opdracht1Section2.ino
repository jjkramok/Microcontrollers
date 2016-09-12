/*
Name:		Opdracht1Section2.ino
Created:	12/9/2016 7:14:56 PM
Author:	Tim Hintzbergen
Exercise: S2 - 1.9
*/

int main(void) {
	DDRB = 0xFF; //Defines all pins as output
	
	while (1) {
		int num;
		for (num = 0; num < 0xFF; num++) {
			
			PORTB = 0x00; //Clear all bits so we can begin with the next number
			int i;
			for (i = 0; i < 8; i++) { //Loop over all bits and decide for each if it should become 1 or not.
				if (num % 2)
					PORTB |= (1 << i); //Shift to the correct bit location, make this bit HIGH without disturbing other bits.
				num /= 2;
				if (!num) { //If num becomes 0 (something what will happen a lot in the beginning of the program) break out of the forloop and go to the next number to increase speed
					break; //Going on and dividing 0 for the next couple of bits is not going to change anything but the waiting time.
				}
			}
		}

	}
}