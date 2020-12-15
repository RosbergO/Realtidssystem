/*
 * CarQueue.c
 *
 * Created: 2020-12-08 14:37:25
 *  Author: Oscar
 */ 

#include "CarQueue.h"

#define NorthboundCarArrival 1
#define NorthboundBridgeEntry 2
#define SouthboundCarArrival 3
#define SouthboundBridgeEntry 4

void incrementQueue(CarQueue *self, int direction) {
	if(direction == NorthboundCarArrival) {
		self->northQueue++;
	}
	else if(direction == SouthboundCarArrival) {
		self->southQueue++;
	}
}
void decrementQueue(CarQueue *self, int direction) {
	if(direction == NorthboundBridgeEntry && self->northQueue > 0) {
		self->northQueue--;
	}
	else if(direction == SouthboundBridgeEntry && self->southQueue > 0) {
		self->southQueue--;
	}
}