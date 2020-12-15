/*fd_set rfds;FD_ZERO(&rfds);
// emtpy setFD_SET(0, &rfds);
// include keyboardFD_SET(COM1, &rfds);
// include com1:select(4,&rfds,NULL,NULL,NULL);
// waitif(FD_ISSET(0,&rfds)){
// handle keypress//handle keypress...}...
*/

#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdint.h>
#include <unistd.h>

#include "Simulator.h"
#include "UserInput.h"
#include "SerialPort.h"
#include "GUI.h"

//gcc -o main *.c -lpthread

pthread_t controllerInput;
pthread_t userInput;
pthread_t GUI;
pthread_t simulator;

int northGreenLight = 0;
int southGreenLight = 0;
int bothRedLight = 0; //neccessary???
int northboundQueue = 0;
int southboundQueue = 0;
int onBridge = 0;


int main(void) {
    openSerialPort();
    //readUserInput(NULL);
    pthread_create(&simulator, NULL, enterBridge, NULL);
    pthread_create(&GUI, NULL, printAll, NULL);
    pthread_create(&userInput, NULL, readUserInput, NULL);
    pthread_create(&controllerInput, NULL, readFromController, NULL);
    pthread_detach(GUI);
    pthread_detach(simulator);
    pthread_detach(userInput);
    pthread_detach(controllerInput);
    
    while(1) {

    }
}





