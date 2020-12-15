/*
 * TrafficLight.h
 *
 * Created: 2020-12-08 09:56:52
 *  Author: Oscar
 */ 

#include "TinyTimber.h"
#include "CarQueue.h"
#include "Bridge.h"
#include "OutputHandler.h"
#include "LCD.h"
#include <stdbool.h>
#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

typedef struct {
		Object super;
		LCD *lcd;
		CarQueue *carQueue;
		Bridge *bridge;
		OutputHandler *outputHandler;
		int lightStatus;
		int count;
		bool southWasOn;
	} TrafficLight;

void changeLights(TrafficLight *self, int arg);
//void swapDirection(TrafficLight *self, int arg);



#define initTrafficLight(lcd, carQueue, bridge, outputHandler) {initObject(), lcd, carQueue, bridge, outputHandler, 0, 0xA, 0, 0}

#endif /* TRAFFICLIGHT_H_ */