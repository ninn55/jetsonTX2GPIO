#include "jetsonGPIO.h"

int main(int argc, char *argv[]){
	jetsonTX2GPIONumber LEDBlk = gpio394;
	jetsonTX2GPIONumber LEDEdg = gpio393;
	
	jetsonTX2GPIONumber LEDNumbers[] = {gpio398, gpio298, gpio389, gpio395, gpio388};
	
	gpioUnexport(LEDBlk);
	gpioUnexport(LEDEdg);
	for(int i = 0; i < 5; i++){
		gpioUnexport(LEDNumbers[i]);
	}
}