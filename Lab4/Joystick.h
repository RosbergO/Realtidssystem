/*
 * Joystick.h
 *
 * Created: 2020-12-03 13:39:11
 *  Author: Oscar
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_
#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include "TinyTimber.h"
#include "LCD.h"

typedef struct {
	Object super;
	int held;
	LCD *lcd;
	} Joystick;

void isHeld(Joystick *self, int arg);
#define initJoystick(lcd) {initObject(), 1, lcd}


#endif /* JOYSTICK_H_ */