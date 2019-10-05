/*	Author: Matthew Walsh (mwals003)
 *      Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #0
 *	Exercise Description: Introduction to AVR Toolchain
 *
 *	I acknowledge all content contained herein, excluding
 *      template or example code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    unsigned char tmpB = 0xFF;
    unsigned char tmpA = 0xFF;
    
    while(1) {
        tmpA = PINA;
	tmpB = 0x00;
        
        if (tmpA == 0x01) {
            tmpB = 0x01;
        }
        
        PORTB = tmpB;
    }
    
    return 1;

}
