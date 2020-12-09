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
#include "HandlerUSART.h"
#include "Bridge.h"

LCD lcd = LCD_Init();
InputHandler inputHandler = inputHandlerInit();
TrafficLight trafficLight = initTrafficLight();
Bridge bridge = initBridge();

int main(void)
{
	
	INSTALL(,,USART0_RX_vect);
	return TINYTIMBER(&trafficLight, changeLights, 0);
}
