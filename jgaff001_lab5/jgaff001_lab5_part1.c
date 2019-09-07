/*	Partner 1's Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *  Partner 2's Name & E-mail: Wang Sitao 934415487@qq.com
 *	Lab Section: 022
 *	Assignment: Lab #5 Exercise #1
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
//code from lab 3, part 2.
#include <avr/io.h>
//setbit and getbit functions from the lab manual
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0x00; PORTB = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs
	unsigned char temp = 0x00;

	while(1) {
		unsigned char i; //iterator
		unsigned char bits = 0x00; //total on(1) bits
		for (i = 0; i < 8; i++) {
			temp = PINA;
			if(GetBit(temp,i)) {
				bits++;
			}
			temp = PINB;
			if(GetBit(temp,i)) {
				bits++;
			}
		}
		PORTC = bits;
	}
	return 0;
}
