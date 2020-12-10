/*
 * TrafficLight.c
 *
 * Created: 2020-12-08 09:56:40
 *  Author: Oscar
 */ 
#include "TrafficLight.h"
//Opposite traffic light also turns red
#define northboundGreenLight = 0x9 
#define southboundGreenLight = 0x6
#define bothRedLight = 0xA


//Om 10 sekunder gått | kön är tom && bron är tom 

//OKLART OM DETTA ÄR BRAAAAA
void changeLights(TrafficLight *self, int arg) {
	if((self->carQueue->northQueue == 0 && self->carQueue->southQueue == 0)) { //Båda köer tomma
		if(self->lightStatus != bothRedLight) {
			self->lightStatus = bothRedLight;
			ASYNC(self->outputHandler, writeUSART, bothRedLight);
			AFTER(SEC(1), self, changeLights, 0);
		}
		else {
			AFTER(SEC(1), self, changeLights, 0);
		}
	}
	else if(!(self->carQueue->northQueue) != !(self->carQueue->southQueue)) { //Om ena har kö!!! C:
		if((self->carQueue->northQueue > 0) && (self->bridge->southboundEntry == 0)) { //Om norr har kö & inget möte över bron
			self->lightStatus = northboundGreenLight;
			ASYNC(self->outputHandler, writeUSART, northboundGreenLight);	
		}
		else if((self->carQueue->southQueue > 0) && (self->bridge->northboundEntry == 0)) {
			self->lightStatus = southboundGreenLight;
			ASYNC(self->outputHandler, writeUSART, southboundGreenLight);
		}
		ASYNC(self->outputHandler, writeUSART, bothRedLight);
		AFTER(SEC(1), self, changeLights, 0);
	}
	else if((self->carQueue->northQueue > 0) && (self->carQueue->southQueue > 0)) { //Om båda har kö //Is this needed???? is there another else?
		if((self->lightStatus != northboundGreenLight) && (self->bridge->northboundEntry == 0) && (!(self->southWasOn))) { // om norr ej grön, inga bilar på bron och förra gröna ljus var söder
			self->lightStatus = southboundGreenLight;
			ASYNC(self, swapDirection, 0);
		}
		else if((self->lightStatus != southboundGreenLight) && (self->bridge->southboundEntry == 0) && (self->southWasOn)) {
			self->lightStatus = northboundGreenLight;
			ASYNC(self, swapDirection, 0);
		}
		else if (self->lightStatus != bothRedLight){ //ändrar till båda röda ljus om ett är grönt
			self->lightStatus = bothRedLight;
			ASYNC(self->outputHandler, writeUSART, bothRedLight);
		}
		AFTER(SEC(1), self, changeLights, 0);
	}
}
//Använda för att flippa var 7e? bra idé!!!!!!!!
void swapDirection(TrafficLight *self, int arg) {
	if(self->count % 7 == 0) {
		self->southWasOn = !(self->southWasOn);
	}
	else {
		self->count++;
	}
}

/*
void changeLights(TrafficLight *self, int count) {
	if((self->carQueue->northQueue == 0 && self->carQueue->southQueue == 0) && self->lightStatus != bothRedLight) {
		self->lightStatus = bothRedLight;
		ASYNC(self->outputHandler, writeUSART, bothRedLight);
		AFTER(SEC(1), self, changeLights, 0);
	}
	else if((self->lightStatus != southboundGreenLight)) {			//Ena eller båda har kö
		if((count <= 5) || (self->carQueue->northQueue != 0)) {		//Norr har kö
			self->lightStatus == northboundGreenLight;
			ASYNC(self->outputHandler, writeUSART, northboundGreenLight);
			ASYNC(self->outputHandler, writeUSART, bothRedLight);
			AFTER(SEC(1), self, changeLights, count+1);
		}
		else {
			if(self->bridge)
			self->lightStatus = southboundGreenLight;
			ASYNC(self, changeLights, 0);
		}

		//AFTER(SEC(1), self->outputHandler, writeUSART, northboundGreenLight);
	}
	else if((self->lightStatus != northboundGreenLight) && ((self->carQueue->southQueue > 0)) {
		if(count <= 5) {
			self->lightStatus == southboundGreenLight;
			ASYNC(self->outputHandler, writeUSART, southboundGreenLight);
			ASYNC(self->outputHandler, writeUSART, bothRedLight);
			AFTER(SEC(1), self, changeLights, count+1);
		}
		else {
			self->lightStatus = northboundGreenLight;
			ASYNC(self, changeLights, 0);
		}

		//AFTER(SEC(1), self->outputHandler, writeUSART, northboundGreenLight);
	}
	*/
	
	
	
	
	
	
	
	
	
	
	/*
	if((self->carQueue->northQueue == 0 && self->carQueue->southQueue == 0) && self->lightStatus != bothRedLight) {
		self->lightStatus = bothRedLight;
		ASYNC(self->outputHandler, writeUSART, bothRedLight);
	}
	else if(((self->carQueue->northQueue == 0) || (self->bridge->carsCrossed >= 5)) && ((self->bridge->onBridge == 0) && (self->lightStatus != southboundGreenLight))) {
		self->bridge->carsCrossed = 0;
		self->lightStatus = southboundGreenLight;
		ASYNC(self->outputHandler, writeUSART, southboundGreenLight);
		ASYNC(self->outputHandler, writeUSART, bothRedLight);
		AFTER(SEC(1), self, changeLights, 0);
	}
	else if(((self->carQueue->southQueue == 0) || (self->bridge->carsCrossed >= 5)) && ((self->bridge->onBridge == 0) && (self->lightStatus != northboundGreenLight))) {
		self->bridge->carsCrossed = 0;
		self->lightStatus = northboundGreenLight;
		ASYNC(self->outputHandler, writeUSART, northboundGreenLight);
	}
	AFTER(SEC(1), self, changeLights, 0);
	*/


void enterBridge(TrafficLight *self, int arg) {
	
}


