/*
 * CarQueue.h
 *
 * Created: 2020-12-08 14:28:17
 *  Author: Oscar
 */ 

#include "TinyTimber.h"

#ifndef CARQUEUE_H_
#define CARQUEUE_H_

typedef struct {
	Object super;
	int northQueue;
	int southQueue;
	} CarQueue;


void incrementQueue(TrafficLight *self, int arg);
void decrementQueue(TrafficLight *self, int arg);

#define initCarQueue() {initObject(), 0, 0}

#endif /* CARQUEUE_H_ */