/*
 * Init.c
 *
 * Created: 2019-03-16 18:10:31
 *  Author: Linnea, bOzzbar
 */ 

#include "Init.h"
#include <avr/io.h>
#include <avr/delay.h>

void init(void){
	//LCD init
	CLKPR = 0x80;
	CLKPR = 0x00;
	LCDFRR = 0x07;
	LCDCRB = 0xB7;
	LCDCRA = 0xC0;
	LCDCCR = 0x0F;
	
	//Joystick stuff
	PORTB =	(1 << PINB7) | (1 << PINB6) | (1 << PINB4); // PINB7 is joystick pull-down, PINB6 is pull-up and PINB4 is down-press
	PORTE =	(1 << PINE3) | (1 << PINE2); // PINE3 is joystick pull-right and PINE2 is pull-left
	PCMSK1 = 1 << PCINT15;
	EIMSK = 1 << PCIE1;
	
	
}