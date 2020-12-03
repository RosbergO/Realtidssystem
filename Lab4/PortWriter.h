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
	int currentPort;
} PortWriter;

void writePort(PortWriter *self, int arg);

#define initPort() {initObject(), 4}



#endif /* PORTWRITER_H_ */