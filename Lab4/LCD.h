/*
 * LCD.h
 *
 * Created: 2019-03-06 16:31:28
 *  Author: oscros-7, linoss-7
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "TinyTimber.h"
#include "PulseGenerator.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

typedef struct {
	Object super;
	PulseGenerator *pulseGenerator[2];
	} LCD;

void updateLCD(LCD *self, int arg);
void printTest(LCD *self, int num);
void writeLong(long i);
struct numbers getChar(char ch);
void writeChar(char ch, int pos);
void LCD_Init(LCD *self, int arg);
void printAt(long num, int pos);
void indicatePulseGen(int selected);

#define initLCD(pulseGen1, pulseGen2) {initObject(), {pulseGen1, pulseGen2}}



#endif /* LCD_H_ */