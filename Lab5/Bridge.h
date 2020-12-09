/*
 * Bridge.h
 *
 * Created: 2020-12-08 14:27:17
 *  Author: Oscar
 */ 
#include "TinyTimber.h"
#include "CarQueue.h"

#ifndef BRIDGE_H_
#define BRIDGE_H_

typedef struct {
	Object super;
	CarQueue *carQueue;
	int northboundEntry;
	int southBoundEntry;
	} Bridge;

void enteredBridge(Bridge *self, int arg);
void exitBridge(Bridge *self, int arg);

#define initBridge(carQueue) {initObject(), carQueue, 0, 0}

#endif /* BRIDGE_H_ */