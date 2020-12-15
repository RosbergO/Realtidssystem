//
// Created by oscar on 2020-12-11.
//
#include "Shared.h"
#include "Simulator.h"
#include "SerialPort.h"

#define NORTHBOUND_BRIDGE_ENTRY 0x2
#define SOUTHBOUND_BRIDGE_ENTRY 0x8
void *enterBridge(void *a) {
    while(1) {
        if(northGreenLight && (northboundQueue > 0)) {
            northboundQueue--;
            writeToController(NORTHBOUND_BRIDGE_ENTRY);
            pthread_t car;
            pthread_create(&car, NULL, bridgeDrive, NULL);
        }
        else if(southGreenLight && (southboundQueue > 0)) {
            southboundQueue--;
            writeToController(SOUTHBOUND_BRIDGE_ENTRY);
            pthread_t car;
            pthread_create(&car, NULL, bridgeDrive, NULL);
        }
    }
}

void *bridgeDrive(void *a) {
    onBridge++;
    usleep(5000000);
    onBridge--;
    pthread_exit(0);
}
