/*
 * OutputHandler.h
 *
 * Created: 2020-12-08 15:14:54
 *  Author: Oscar
 */ 


#ifndef OUTPUTHANDLER_H_
#define OUTPUTHANDLER_H_

typedef struct {
	Object super;
	//int northboundGreenLight;
	//int northboundRedLight;
	//int southboundGreenLight;
	//int southboundRedLight;
	}OutputHandler;

#define initOutputHandler() {initObject()}
void writeUSART(OutputHandler *self, int arg);

#endif /* OUTPUTHANDLER_H_ */