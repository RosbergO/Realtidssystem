/*
 * Bridge.c
 *
 * Created: 2020-12-08 14:27:03
 *  Author: Oscar
 */ 

#include "TinyTimber.h"
#include "Bridge.h"

#define NORTBOUND_ENTRY = 1
#define SOUTHBOUND_ENTRY = 3

void enteredBridge(Bridge *self, int direction) {
	if(direction == NORTBOUND_ENTRY) {
		self->northboundEntry++;
	}
	else if(direction == SOUTHBOUND_ENTRY) {
		self->southBoundEntry++;
	}
	ASYNC(self->carQueue, decrementQueue, entryDirection);
	AFTER(SEC(5), self, exitBridge, direction)
}
void exitBridge(Bridge *self, int direction) {
	if(direction == NORTBOUND_ENTRY) {
		self->northboundEntry--;
	}
	else if(direction == SOUTHBOUND_ENTRY) {
		self->southBoundEntry--;
	}
}