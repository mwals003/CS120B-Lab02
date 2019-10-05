/*	Author: Matthew Walsh (mwals003)
 *  Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: Introduction to AVR Toolchain
 *
 *	I acknowledge all content contained herein, excluding
 *  template or example code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	
	unsigned char total = 0x00;
	unsigned char shift = 0x00;

	while(1) {
	
		tmpA = PORTA;
		tmpB = PORTB;
		tmpC = PORTC;
        tmpD = 0x00;
		
		// Calculate total weight.
		total = tmpA + tmpB + tmpC;
		
		// Calculate shifted weight.
		if ((tmpA > tmpC) {
			shift = tmpA - tmpC;
        }
		else if ((tmpA < tmpC) {
            shift = tmpC - tmpA;
        }
        else {
			shift = 0x00;
		}
		
		// Determine if warning activates.
		if ((total > 0x8C) || (shift > 0x50)) {
			tmpD = 0x01;
		}
		
		PORTD = tmpD;
	}
	
	return 1;

}
