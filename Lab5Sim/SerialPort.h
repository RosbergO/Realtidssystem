//
// Created by oscar on 2020-12-11.
//
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdint.h>
#include <unistd.h>
#ifndef LAB5SIM_SERIALPORT_H
#define LAB5SIM_SERIALPORT_H



void openSerialPort();
void writeToController(uint8_t instr);

void *readFromController(void *a);

#endif //LAB5SIM_SERIALPORT_H
