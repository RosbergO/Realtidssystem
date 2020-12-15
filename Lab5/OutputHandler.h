/*
 * OutputHandler.h
 *
 * Created: 2020-12-08 15:14:54
 *  Author: Oscar
 */ 

#include "TinyTimber.h"
#include "LCD.h"
#include <avr/io.h>

#ifndef OUTPUTHANDLER_H_
#define OUTPUTHANDLER_H_

typedef struct {
	Object super;
	LCD *lcd;
	//int northboundGreenLight;
	//int northboundRedLight;
	//int southboundGreenLight;
	//int southboundRedLight;
	}OutputHandler;

#define initOutputHandler(lcd) {initObject(), lcd}
void writeUSART(OutputHandler *self, int arg);

#endif /* OUTPUTHANDLER_H_ */