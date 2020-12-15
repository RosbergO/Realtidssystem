/*
 * Lab5.c
 *
 * Created: 2020-12-07 13:48:28
 * Author : Oscar
 */ 

#include <avr/io.h>
#include "TinyTimber.h"
#include "LCD.h"
#include "TrafficLight.h"
#include "Bridge.h"
#include "CarQueue.h"
#include "OutputHandler.h"
#include "InputHandler.h"

LCD lcd = initLCD();
CarQueue carQueue = initCarQueue();
Bridge bridge = initBridge(&lcd, &carQueue);
OutputHandler outputHandler = initOutputHandler(&lcd);
TrafficLight trafficLight = initTrafficLight(&lcd, &carQueue, &bridge, &outputHandler);
InputHandler inputHandler = inputHandlerInit(&lcd, &trafficLight, &carQueue, &bridge);

// TODO : WRITE DATA TO SIM DOESNT WORK PROPERLY

int main(void)
{	
	LCD_Init();
	INSTALL(&inputHandler, readUSART, IRQ_USART0_RX);
	return TINYTIMBER(&trafficLight, changeLights, 1);
}
