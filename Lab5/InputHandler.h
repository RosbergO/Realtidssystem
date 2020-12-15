/*
 * HandlerUSART.h
 *
 * Created: 2020-12-08 10:32:25
 *  Author: Oscar
 */ 
#include "TinyTimber.h"
#include "Bridge.h"
#include "CarQueue.h"
#include "TrafficLight.h"
#include "LCD.h"
#include <avr/io.h>

#ifndef INPUTHANDLER_H_ //FUNKAR VA??? COPY PASTEA MANUELLT
#define INPUTHANDLER_H_

typedef struct {
	Object super;
	LCD *lcd;
	TrafficLight *trafficLight;
	CarQueue *carQueue;
	Bridge *bridge;
	} InputHandler;

void readUSART(InputHandler *self, int arg);


#define inputHandlerInit(lcd, trafficLight, carQueue, bridge) {initObject(), lcd, trafficLight, carQueue, bridge}
#endif /* INPUTHANDLER_H_ */