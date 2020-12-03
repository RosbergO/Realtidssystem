/*
 * Lab4.c
 *
 * Created: 2019-03-06 15:43:42
 * Author : Linnea
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom169p.h>
#include <avr/portpins.h>
#include <stdio.h>
#include "TinyTimber.h"
#include "LCD.h"
#include "PulseGenerator.h"
#include "PortWriter.h"
#include "Handler.h"
#include "Joystick.h"


PortWriter port = initPort();
PulseGenerator pulseGen1 = initPulseGenerator(4, &port);
PulseGenerator pulseGen2 = initPulseGenerator(3, &port);
LCD lcd = initLCD(&pulseGen1, &pulseGen2);
Joystick joystick = initJoystick(&lcd);
Handler handler = initHandler(&pulseGen1, &pulseGen2, &lcd, &joystick, &port);
//Handler handler = initHandler(&pulseGen1, &pulseGen2, &lcd);

NÄSTA STEG ÄR SKRIVA UT PULSEN!!!!!!!


int main(void)
{
	
	/*
		IRQPCINT0 - Left & Right
		IRQPCINT1 - Up, down & depressed
	*/
	LCD_Init();
	INSTALL(&handler, joystickPINB, IRQ_PCINT1);
	INSTALL(&handler, joystickPINE, IRQ_PCINT0);
	return TINYTIMBER(&lcd, updateLCD, 0);
}

