//
// Created by oscar on 2020-12-11.
//
#include <stdio.h>
#include "SerialPort.h"
#include "Shared.h"
#include "GUI.h"
#define NORTHBOUND_CAR_ARRIVAL 0x1
#define SOUTHBOUND_CAR_ARRIVAL 0x4

void *readUserInput(void *a) {
    struct termios old_tio, new_tio;
    unsigned char c;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    char input;
    while(1) {
        //scanf("  %c", &input );
        c=getchar();
        if(c == 'n') {
            printf("north \n");
            northboundQueue++;
            writeToController(NORTHBOUND_CAR_ARRIVAL);
            printCarQueue();
        }
        else if(c == 's') {
            printf("south \n");
            southboundQueue++;
            writeToController(SOUTHBOUND_CAR_ARRIVAL);
            printCarQueue();
        }
    }
}