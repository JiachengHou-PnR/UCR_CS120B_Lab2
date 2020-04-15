/*	Author: houjiacheng
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 4
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
    // Inputs
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTA = 0xFF;
    DDRC = 0x00; PORTA = 0xFF;
    // Outputs
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmpA, tmpB, tmpC, tmpD;
    
    unsigned char c_diff;
    unsigned short c_total;
    unsigned char b_overweight, b_unbalance;

    /* Insert your solution below */
    while (1) {
        // get inputs
        tmpA = PINA;
        tmpB = PINB;
        tmpC = PINC;

        // calc numbers
        c_diff = tmpA - tmpC;
        c_total = tmpA + tmpB + tmpC;

        // set booleans
        b_overweight = (c_total > 140);
        b_unbalance = ((c_diff > 80) || (c_diff < -80));

        // round c_total
        if (c_total > 0xFC)
            c_total = 0xFC;
        if ((c_total & 0x03) < 2) {
           c_total = (c_total & 0xFC);
        } else {
            c_total = (c_total & 0xFC) + 0x04;
        }
        
        

        // construct output
        tmpD = b_overweight | (b_unbalance << 1) | c_total;
 
        PORTD = tmpD;
    }
    return 1;
}
