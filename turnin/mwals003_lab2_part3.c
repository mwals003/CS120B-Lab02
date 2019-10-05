/*	Author: Matthew Walsh (mwals003)
 *      Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #3
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
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char cntavail = 0x00;
    
    while(1) {
    
        tmpA = PINA;
        cntavail = 0x00;
        
        // If one spot is taken.
        if ((tmpA == 0x01) || (tmpA == 0x02) || (tmpA == 0x04) || (tmpA == 0x08)) {
            cntavail = 0x03;
        }
        
        // If two spots are taken.
        else if ((tmpA == 0x03) || (tmpA == 0x05) || (tmpA == 0x09) || (tmpA == 0x06) || (tmpA == 0x0A) || (tmpA == 0x0C)) {
            cntavail = 0x02;
        }
        
        // If three sports are taken
        else if ((tmpA == 0x07) || (tmpA == 0x0D) || (tmpA == 0x0B) || (tmpA == 0x0E)) {        
	  cntavail = 0x01;
        }
        
        // If all spots are full.
        else if (tmpA == 0x0F) {
	  cntavail = 0x80;
        }
        
        PORTC = cntavail;
    }
    
    return 1;

}
