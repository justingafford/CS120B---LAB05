/*	Partner 1 Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *	Partner 2 Name & E-mail: Wang Sitao 934415487@qq.com
 *	Lab Section: 022
 *	Assignment: Lab #5 Exercise #3
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

//modified code from lab 4 exercise 1
#include <avr/io.h>
enum states {Init, blank, buttonpress, display1,buttonpress1,display2,buttonpress2,display3,buttonpress3} state;
	
#define buttonPressed (PINA & 0x01)

void light_show () {
	switch(state) {
	case Init:
		state = blank;
		break;
	case blank:
		if(buttonPressed) {
			state = buttonpress;
		}
		else {
			state = blank;
		}
		break;
	case buttonpress:
		if (buttonPressed) {
			state = buttonpress;
		}
		else {
			state = display1;
		}
		break;
	case display1:
		if (buttonPressed) {
			state = buttonpress1;
		}
		else {
			state = display1;
		}
		break;
	case buttonpress1:
		if (buttonPressed) {
			state = buttonpress1;
		}
		else {
			state = display2;
		}
		break;
	case display2:
		if(buttonPressed) {
			state = buttonpress2;
		}
		else {
			state = display2;
		}
		break;
	case buttonpress2:
		if(buttonPressed) {
			state = buttonpress2;
		}
		else {
			state = display3;
		}
		break;
	case display3:
		if(buttonPressed) {
			state = buttonpress3;
		}
		else {
			state = display3;
		}
		break;
	case buttonpress3:
		if (buttonPressed) {
			state = buttonpress3;
		}
		else {
			state = blank;
		}
		break;
	default:
		state = Init;
		break;
	}
	switch(state) {
		case blank:
			PORTB = 0x00;
			break;
		case buttonpress:
			PORTB = 0x2A;
			break;
		case display1:
			PORTB = 0x2A;
			break;
		case buttonpress1:
			PORTB = 0x15;
			break;
		case display2:
			PORTB = 0x15;
			break;
		case buttonpress2:
			PORTB = 0x3F;
			break;
		case display3:
			PORTB = 0x3F;
			break;
		case buttonpress3:
			PORTB = 0x00;
			break;
		default:
			break;
		
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRB = 0xFF; PORTB = 0x00; //outputs
	PORTB = 0x00;
	state = Init;
	while (1)
	{
		light_show();
	}
}
