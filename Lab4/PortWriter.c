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

void writePort(PortWriter *self, int port) {
	if(port == 4) {
		PORTE ^= 0x10;//(1 << PINE4);
	} 
	else if (port == 6) {
		PORTE ^= 0x40;//(1 << PINE6);
	}
}
