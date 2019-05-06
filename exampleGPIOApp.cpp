// exampleApp.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "jetsonGPIO.h"
using namespace std;

int main(int argc, char *argv[]){

    cout << "Output the GPIO Pins" << endl;

    jetsonTX2GPIONumber LED = gpio398;     // Ouput
    gpioExport(LED) ;
    gpioSetDirection(LED,outputPin) ;

    // Flash the LED 5 times
    for(int i=0; i<5; i++){
        cout << "Setting the LED on" << endl;
        gpioSetValue(LED, on);
        usleep(200000);         // on for 200ms
        cout << "Setting the LED off" << endl;
        gpioSetValue(LED, off);
        usleep(200000);         // off for 200ms
    }

    cout << "GPIO output finished." << endl;
    gpioUnexport(LED);     // unexport the LED
    return 0;
}


