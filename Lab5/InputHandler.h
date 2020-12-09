/*
 * HandlerUSART.h
 *
 * Created: 2020-12-08 10:32:25
 *  Author: Oscar
 */ 


#ifndef INPUTHANDLER_H_ //FUNKAR VA??? COPY PASTEA MANUELLT
#define INPUTHANDLER_H_

typedef struct {
	Object super;
	TrafficLight *trafficLight;
	CarQueue *carQueue;
	Bridge *bridge;
	} InputHandler;

void readUSART(InputHandler *self, int arg);


#define inputHandlerInit(trafficLight, carQueue, bridge) {initObject(), trafficLight, carQueue, bridge}
#endif /* INPUTHANDLER_H_ */