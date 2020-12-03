/*
 * PulseGenerator.h
 *
 * Created: 2019-03-11 15:28:54
 *  Author: Linnea
 */ 
#ifndef PULSEGENERATOR_H_
#define PULSEGENERATOR_H_
#include "TinyTimber.h"
#include "PortWriter.h"

typedef struct {
	Object super;
	int frequency;
	int savedFrequency;
	int position;
	PortWriter *port;
} PulseGenerator;

void increaseFrequency(PulseGenerator *self, int arg);
void decreaseFrequency(PulseGenerator *self, int arg);
void saveFrequency(PulseGenerator *self, int arg);

#define initPulseGenerator(pos, port){initObject(), 0, 0, pos, port};

#endif /* PULSEGENERATOR_H_ */