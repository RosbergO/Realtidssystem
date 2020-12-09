/*
 * CarQueue.c
 *
 * Created: 2020-12-08 14:37:25
 *  Author: Oscar
 */ 

#include "CarQueue.h"

#define NorthboundCarArrival = 0
#define NorthboundBridgeEntry = 1
#define SouthboundCarArrival = 2
#define SouthboundBridgeEntry = 3

void incrementQueue(CarQueue *self, int direction) {
	if(direction == NorthboundCarArrival) {
		self->northQueue++;
	}
	else if(direction == SouthboundCarArrival) {
		self->southQueue++;
	}
int hello;
}
void decrementQueue(CarQueue *self, int direction) {
	if(direction == NorthboundBridgeEntry && self->northQueue > 0) {
		self->northQueue--;
	}
	else if(direction == SouthboundBridgeEntry && self->southQueue > 0) {
		self->southQueue--;
	}
}