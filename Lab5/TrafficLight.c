/*
 * TrafficLight.c
 *
 * Created: 2020-12-08 09:56:40
 *  Author: Oscar
 */ 
#include "TrafficLight.h"
//Opposite traffic light also turns red
#define NORTHBOUND_GREEN_LIGHT 0x9 
#define SOUTHBOUND_GREEN_LIGHT 0x6
#define BOTH_RED_LIGHT 0xA
#define CHANGE_DIR_AFTER 4

void changeLights(TrafficLight *self, int arg) {
	ASYNC(self->lcd, updateTrafficLights, arg);
	if((self->carQueue->northQueue == 0 && self->carQueue->southQueue == 0)) { //Båda köer tomma
		if(self->lightStatus != BOTH_RED_LIGHT) {
			self->lightStatus = BOTH_RED_LIGHT;
			ASYNC(self->outputHandler, writeUSART, BOTH_RED_LIGHT);
			AFTER(SEC(1), self, changeLights, 1);
		}
		else {
			AFTER(SEC(1), self, changeLights, 1);
		}
	}
	else if(!(self->carQueue->northQueue) != !(self->carQueue->southQueue)) { //Om ena har kö!!! C:
		if((self->carQueue->northQueue > 0) && (self->bridge->southboundEntry == 0)) { //Om norr har kö & inget möte över bron
			self->lightStatus = NORTHBOUND_GREEN_LIGHT;
			ASYNC(self->outputHandler, writeUSART, NORTHBOUND_GREEN_LIGHT);	
		}
		else if((self->carQueue->southQueue > 0) && (self->bridge->northboundEntry == 0)) {
			self->lightStatus = SOUTHBOUND_GREEN_LIGHT;
			ASYNC(self->outputHandler, writeUSART, SOUTHBOUND_GREEN_LIGHT);
		}
		ASYNC(self->outputHandler, writeUSART, BOTH_RED_LIGHT);
		AFTER(SEC(1), self, changeLights, 1);
	}
	else if((self->carQueue->northQueue > 0) && (self->carQueue->southQueue > 0)) { //Om båda har kö //Is this needed???? is there another else?
		if((self->bridge->northboundEntry == 0) && ((self->southWasOn == 1))) { // om norr ej grön, inga bilar på bron och förra gröna ljus var söder
			self->lightStatus = SOUTHBOUND_GREEN_LIGHT;
			ASYNC(self->outputHandler, writeUSART, SOUTHBOUND_GREEN_LIGHT);
			ASYNC(self->outputHandler, writeUSART, BOTH_RED_LIGHT);
			if(arg % CHANGE_DIR_AFTER == 0) {
				self->southWasOn = 0;
			}
			AFTER(SEC(1), self, changeLights, arg+1);
		}
		else if((self->bridge->southboundEntry == 0) && (self->southWasOn == 0)) {
			self->lightStatus = NORTHBOUND_GREEN_LIGHT;
			ASYNC(self->outputHandler, writeUSART, NORTHBOUND_GREEN_LIGHT);
			ASYNC(self->outputHandler, writeUSART, BOTH_RED_LIGHT);
			if(arg % CHANGE_DIR_AFTER == 0) {
				self->southWasOn = 1;
			}
			AFTER(SEC(1), self, changeLights, arg+1);
		}
		else {
			AFTER(SEC(1), self, changeLights, arg);
		}
	}
	else {
		AFTER(SEC(1), self, changeLights, 1);
	}
}


