/*
 * PulseGenerator.c
 *
 * Created: 2019-03-11 15:28:37
 *  Author: Linnea
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include "PulseGenerator.h"
#include "TinyTimber.h"


void increaseFrequency(PulseGenerator *self, int arg) {
	if (self->frequency < 99) {
		self->frequency += 1;
	}
}

void decreaseFrequency(PulseGenerator *self, int arg) {
	if (self->frequency > 0) {
		self->frequency -= 1;
	}
}
	
void saveFrequency(PulseGenerator *self, int arg) {
	if (self->frequency > 0) {
		self->savedFrequency = self->frequency;
		self->frequency = 0;
	} 
	else if(self->frequency == 0) {
		self->frequency = self->savedFrequency;
	}
}