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
#include "Joystick.h"
#include "PortWriter.h"

typedef struct {
	Object super;
	PulseGenerator *pulseGenerator[2];
	LCD *lcd;
	int selected;
	Joystick *joystick;
	PortWriter *portWriter;
	} Handler;

void joystickPINB(Handler *self, int arg);
void joystickPINE(Handler *self, int arg);
void initPulseWrite(Handler *self, int arg);
#define initHandler(pulseGen1, pulseGen2, lcd, joystick, portWriter) {initObject(), {pulseGen1, pulseGen2}, lcd, 0, joystick, portWriter}
//#define initHandler(pulseGen1, pulseGen2, lcd, joystick) {initObject(), {pulseGen1, pulseGen2}, lcd, 0, joystick}


#endif /* HANDLER_H_ */