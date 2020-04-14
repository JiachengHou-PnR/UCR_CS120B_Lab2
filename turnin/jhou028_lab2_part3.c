/*	Author: houjiacheng
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 3
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
    DDRC = 0xFF; PORTC = 0x00; //output
    
    unsigned char tmpA;
    
    unsigned char cntavail;

    unsigned char d;
    unsigned char i;
 
    /* Insert your solution below */
    while (1) {
        tmpA = PINA & 0x0F;
        cntavail = 0x04;
        d = 0x01;

        for (i = 0; i < 4; i++) {
            
            if (tmpA & d) {
                cntavail --;
            }

            d = d * 2;
        }
        
        PORTC = (cntavail == 0x00)  ? ((cntavail & 0x0F) | 0x80) : ((cntavail & 0x0F) | 0x00);
    }
    return 1;
}
