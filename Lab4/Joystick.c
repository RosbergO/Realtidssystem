/*
 * Joystick.c
 *
 * Created: 2020-12-03 13:38:55
 *  Author: Oscar
 */ 
#include "Joystick.h"

void isHeld(Joystick *self, int arg) {
	if (((PINB >> 6) & 1) == 0) {
		self->held = 1;
		ASYNC(self->lcd->pulseGenerator[arg], increaseFrequency, 0);
		AFTER(MSEC(200), self, isHeld, arg);
	}
	else if(((PINB >> 7) & 1) == 0) {
		self->held = 1;
		ASYNC(self->lcd->pulseGenerator[arg], decreaseFrequency, 0);
		AFTER(MSEC(200), self, isHeld, arg);
	}
	else {
		self->held = 0;
	}
	updateLCD(self->lcd, arg);
}