/*
 * OutputHandler.c
 *
 * Created: 2020-12-08 15:14:41
 *  Author: Oscar
 */
#include "OutputHandler.h"

 
void writeUSART(OutputHandler *self, int arg) {
	UDR0 = arg;
}