/*	Author: houjiacheng
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //input
    DDRB = 0xFF; PORTB = 0x00; //output

    unsigned char tmpA0 = 0x00; 
	unsigned char tmpA1 = 0x00; 
    unsigned char tmpB0 = 0x00;
 
    /* Insert your solution below */
    while (1) {
        tmpA0 = PINA & 0x01;
        tmpA1 = PINA & 0x02;

        if (!tmpA1 && tmpA0)
            tmpB0 = 0x01;
        else
            tmpB0 = 0x00;
        
        
        
        PORTB = tmpB0;
    }
    return 1;
}
