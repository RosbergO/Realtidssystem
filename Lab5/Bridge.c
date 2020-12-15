/*
 * Bridge.c
 *
 * Created: 2020-12-08 14:27:03
 *  Author: Oscar
 */ 

#include "TinyTimber.h"
#include "Bridge.h"
#include "CarQueue.h"

#define NORTBOUND_ENTRY 2
#define SOUTHBOUND_ENTRY 4

void enteredBridge(Bridge *self, int direction) {
	if(direction == NORTBOUND_ENTRY) {
		self->northboundEntry++;
	}
	else if(direction == SOUTHBOUND_ENTRY) {
		self->southboundEntry++;
	}
	ASYNC(self->carQueue, decrementQueue, direction);
	AFTER(SEC(5), self, exitBridge, direction);
}
void exitBridge(Bridge *self, int direction) {
	if(direction == NORTBOUND_ENTRY) {
		self->northboundEntry--;
	}
	else if(direction == SOUTHBOUND_ENTRY) {
		self->southboundEntry--;
	}
}

/*
//Använda för att flippa var 7e? bra idé!!!!!!!!         FLYTTA TILL BRIDGE????
int swapDirection(Bridge *self, int arg) {
	if(self->count % 7 == 0) {
		if(self->southWasOn == 0) {
			self->southWasOn = 1;
		}
		else if(self->southWasOn == 1) {
			self->southWasOn = 0;
		}
		self->count = 1;
	}
	else {
		self->count++;
	}
	ASYNC(self->lcd, updateOutput, self->count);
	return 0;
}
*/