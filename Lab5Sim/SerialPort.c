//
// Created by oscar on 2020-12-11.
//
#include "SerialPort.h"
#include "Shared.h"
int COM1;
int northGreenLight;
int southGreenLight;
int bothRedLight; //neccessary???

void openSerialPort(void) {
    struct termios config;
    COM1 = open("/dev/ttyS0", O_RDWR); //filedescriptor
    if(COM1 < 0){
        printf("File cannot open. \n");
    }
    if(!isatty(COM1)){
        printf("COM1 is not a tty. \n");
    }
    if(tcgetattr(COM1, &config) < 0){ //needed?
        printf("Cannot get termios attributes. \n");
    }

    //attributes
    tcflush(COM1, TCIFLUSH); //flushes data recieved but not read
    config.c_cflag = B9600 | CS8 | CSTOPB | CREAD | CLOCAL | HUPCL | INPCK; //set baud rate to 9600bps and some more stuff..........................
    config.c_lflag &= ~(ECHO | ECHONL | ICANON);
    config.c_cc[VTIME] = 10;
    config.c_cc[VMIN] = 1;
    cfsetispeed(&config, B9600);
    cfsetospeed(&config, B9600);

    if(tcsetattr(COM1, TCSANOW, &config)){ //tcsanow, attributes set immediately
        printf("Cannot set termios attributes. \n");
    }

}

void writeToController(uint8_t instr){ //Register is 8 bit
    int x = write(COM1, &instr, sizeof(instr));
    if(x < 0) {
        printf("Write not successfull. \n");
    }
}

void *readFromController(void *a) {
    uint8_t inData;
    while(1) {
        uint8_t data = read(COM1, &inData, sizeof(inData)); //(returns -1 if empty)
        if(data > 0){
            if(inData == 0x9) {
                northGreenLight = 1;
                southGreenLight = 0;
            }
            else if(inData == 0x6) {
                northGreenLight = 0;
                southGreenLight = 1;
            }
            else if(inData == 0xA) {
                northGreenLight = 0;
                southGreenLight = 0;
                bothRedLight = 0;
            }
        }
    }

}
