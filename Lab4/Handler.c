/*
 * Handler.c
 *
 * Created: 2020-11-30 13:20:27
 *  Author: Oscar
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include "Handler.h"
#include "TinyTimber.h"



void joystickPINB(Handler *self, int arg) {
	self->joystick->held = 1;
	if ((((PINB >> 6) & 1) == 0) && (self->joystick->held == 1)) {
		ASYNC(self->joystick, isHeld, self->selected);
	}
	else if(((PINB >> 7) & 1) == 0 && (self->joystick->held == 1)) {
		ASYNC(self->joystick, isHeld, self->selected);
	}
	else if(((PINB >> 4) & 1) == 0) {
		ASYNC(self->pulseGenerator[self->selected], saveFrequency, 0);
	}
	ASYNC(self->lcd, updateLCD, self->selected);
	ASYNC(self->portWriter, writePort, self->pulseGenerator[self->selected]->frequency); //Dubbelcheck
}

void joystickPINE(Handler *self, int arg) {
	if(((PINE >> 3) & 1) && (self->selected == 0)) {
		self->selected = 1;
		self->portWriter->currentPort = 6; //Dubbelchecka pls
	}
	else if(((PINE >> 2) & 1) && (self->selected == 1)) {
		self->selected = 0;
		self->portWriter->currentPort = 4;
	}
	ASYNC(self->lcd, updateLCD, self->selected);
}