/*
 * Bridge.h
 *
 * Created: 2020-12-08 14:27:17
 *  Author: Oscar
 */ 
#include "TinyTimber.h"
#include "CarQueue.h"
#include "LCD.h"
#include <stdbool.h>

#ifndef BRIDGE_H_
#define BRIDGE_H_

typedef struct {
	Object super;
	LCD *lcd;
	CarQueue *carQueue;
	int northboundEntry;
	int southboundEntry;
	} Bridge;

//int swapDirection(Bridge *self, int arg);
void enteredBridge(Bridge *self, int arg);
void exitBridge(Bridge *self, int arg);

#define initBridge(lcd, carQueue) {initObject(), lcd, carQueue, 0, 0, 1, 0}

#endif /* BRIDGE_H_ */