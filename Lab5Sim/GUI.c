//
// Created by oscar on 2020-12-11.
//

#include <stdio.h>
#include <unistd.h>
#include "GUI.h"
#include "Shared.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128

void printCarsOnBridge(void) {
    printf("Cars on bridge: %d \n", onBridge);
}

void printCarQueue(void) {
    printf("Cars in northbound queue: %d \n", northboundQueue);
    printf("Cars in southbound queue: %d \n", southboundQueue);
}

void *printAll(void *a) {

    while(1) {
        printf("\033[2J\033[H");
        printf("Cars on bridge: %d \n", onBridge);
        printf("Cars in northbound queue: %d \n", northboundQueue);
        printf("Cars in southbound queue: %d \n", southboundQueue);
        printf("South light %d nort light %d both red %d \n", southGreenLight, northGreenLight, bothRedLight);
        //printLight();
        usleep(500000);
    }

}

void printLight(void) {
    if(northGreenLight) {
        printf("Northbound light green - Southbound light red\n");
    }
    else if(southGreenLight) {
        printf("Southbound light green - Northbound light red\n");
    }
    else if(bothRedLight) {
        printf("Southbound light red - Northbound light red\n");
    }
}


/*
 * NOT SUPPORTED IN TERMINAL
void printLights(void) {
    char greenLight[] = "../Greenlight";
    char redLight[] = "../Redlight";
    char red[] = "\x1B[31m";
    char green[] = "\x1B[32m";
    if(northGreenLight) {
        readFile(greenLight, redLight, green, red);
    }
    else if(southGreenLight) {
        readFile(redLight, greenLight, red, green);
    }
    else if(bothRedLight) {
        readFile(redLight, redLight, red, red);
    }
}

int readFile(char *file, char *file2, char *color, char *color2) {
    char *filename = file;
    char *filename2 = file2;
    FILE *fptr = NULL;
    FILE *fptr2 = NULL;
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
    if((fptr2 = fopen(filename2,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename2);
        return 1;
    }
    print_image(fptr, fptr2, color, color2);
    fclose(fptr);
    fclose(fptr2);
    return 0;
}

void print_image(FILE *fptr, FILE *fptr2, char *color, char *color2)
{
    char read_string[MAX_LEN];
    printf("North light: ");
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s %s",read_string, color);
    printf("\n \x1B[38m South light: ");
    while(fgets(read_string,sizeof(read_string),fptr2) != NULL)
        printf("%s %s",read_string, color2);
}
 */