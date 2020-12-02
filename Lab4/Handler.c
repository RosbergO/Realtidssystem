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



void initHandlers(Handler *self) {
	long x = 3;
	SYNC(self->lcd, LCD_Init, 0);
	//SYNC(self->lcd, printTest, );
}

void joystickPINB(Handler *self, int arg) {
	if (((PINB >> 6) & 1) == 0) {
		ASYNC(self->pulseGenerator[self->selected], increaseFrequency, 0);
	}
	else if(((PINB >> 7) & 1) == 0) {
		ASYNC(self->pulseGenerator[self->selected], decreaseFrequency, 0);
	}
	else if(((PINB >> 4) & 1) == 0) {
		ASYNC(self->pulseGenerator[self->selected], saveFrequency, 0);
	}
	ASYNC(self->lcd, updateLCD, 0);
}

void joystickPINE(Handler *self, int arg) {
	if(((PINE >> 3) & 1) && (self->selected == 0)) {
		self->selected = 1;
	}
	else if(((PINE >> 2) & 1) && (self->selected == 1)) {
		self->selected = 0;
	}
	
}