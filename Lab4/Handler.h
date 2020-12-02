/*
 * Handler.h
 *
 * Created: 2020-11-30 13:20:13
 *  Author: Oscar
 */ 


#ifndef HANDLER_H_
#define HANDLER_H_
#include "TinyTimber.h"
#include "PulseGenerator.h"
#include "LCD.h"

typedef struct {
	Object super;
	PulseGenerator *pulseGenerator[2];
	LCD *lcd;
	int selected;
	} Handler;

void joystickPINB(Handler *self, int arg);
void joystickPINE(Handler *self, int arg);
void initHandlers(Handler *self);
#define initHandler(pulseGen1, pulseGen2, lcd) {initObject(), {pulseGen1, pulseGen2}, lcd, 0}
//#define initHandler(lcd) {initObject(), lcd}

#endif /* HANDLER_H_ */