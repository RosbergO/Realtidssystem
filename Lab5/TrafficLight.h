/*
 * TrafficLight.h
 *
 * Created: 2020-12-08 09:56:52
 *  Author: Oscar
 */ 

#include "TinyTimber.h"
#include "InputHandler.h"
#include "CarQueue.h"
#include "Bridge.h"
#include "OutputHandler.h"
#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

typedef struct {
		Object super;
		CarQueue *carQueue;
		Bridge *bridge;
		OutputHandler *outputHandler;
		int lightStatus;
		bool southWasOn;
	} TrafficLight;

void changeLights(TrafficLight *self, int arg);




#define initTrafficLight(carQueue, bridge, outputHandler) {initObject(), carQueue, bridge, outputHandler, 0, 0, 0}

#endif /* TRAFFICLIGHT_H_ */