/*
 * PortWriter.c
 *
 * Created: 2020-12-02 18:40:51
 *  Author: Oscar
 */ 

#include <setjmp.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include "PortWriter.h"
#include "TinyTimber.h"

//Kan vara fel med PIN4 och PIN6 i selectPort !!!!!!!!!!!!
void writePort(PortWriter *self, int port) {
	if(self->currentPort == 4) {
		PORTE = (1 << PINE4);
	} 
	else if (self->currentPort == 6) {
		PORTE = (1 << PINE6);
	}
}