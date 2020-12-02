/*
 * PortWriter.h
 *
 * Created: 2020-12-02 18:41:05
 *  Author: Oscar
 */ 


#ifndef PORTWRITER_H_
#define PORTWRITER_H_

#include "TinyTimber.h"

typedef struct {
	Object super;
	int currentPulse;
} PortWriter;

void selectPort(PortWriter *self, int arg);

#define initPort() {initObject(), 0}



#endif /* PORTWRITER_H_ */