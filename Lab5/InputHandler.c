/*
 * HandlerUSART.c
 *
 * Created: 2020-12-08 10:31:56
 *  Author: Oscar
 */ 
#include "InputHandler.h"
/*
 Bit 0	Northbound car arrival sensor activated
 Bit 1	Northbound bridge entry sensor activated
 Bit 2	Southbound car arrival sensor activated
 Bit 3	Southbound bridge entry sensor activated
*/

void readUSART(InputHandler *self, int arg) {
	int data = UDR0;
	if((data & 1) == 1) {
		//ASYNC(self->lcd, updateLCD, 1);
		ASYNC(self->carQueue, incrementQueue, 1);
	}	
	else if (((data >> 1) & 1) == 1) {
		//ASYNC(self->lcd, updateLCD, 2);
		ASYNC(self->bridge, enteredBridge, 2);
	}
	else if (((data >> 2) & 1) == 1) {
		//ASYNC(self->lcd, updateLCD, 3);
		ASYNC(self->carQueue, incrementQueue, 3);
	}
	else if (((data >> 3) & 1) == 1) {
		//ASYNC(self->lcd, updateLCD, 4);
		ASYNC(self->bridge, enteredBridge, 4);
	}
}
