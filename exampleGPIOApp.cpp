// exampleApp.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <conio.h>
#include "jetsonGPIO.h"

#define LOG_FILE "../MobileNet-YOLO/outLog"

std::string getLastLine(std::ifstream& in)
{
    std::string line;
    while (in >> std::ws && std::getline(in, line));

    return line;
}

void LEDBlink(jetsonGPIO gpio){
	usleep(80);
	gpioSetValue(gpio, on);
	usleep(80);
	gpioSetValue(gpio, off);
}

int* decToBinary(int n) 
{ 
    int binaryNum[5]; 
   
    int i = 0; 
    while (n > 0) {  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    return binaryNum; 
} 

void LEDNum(int Num, jetsonGPIO* gpio){
	int* bin = decToBinary(Num);
	for(int i = 0; i < 5; i++){
		gpioSetValue(gpio[i], bin[i]);
	}
}

int main(int argc, char *argv[]){
	
	if(argc == 2){
		std::string mode = *argv[1];
	}else{
		std::string mode = "PlayBack";
	}

    std::cout << "Output the GPIO Pins" << std::endl;

	jetsonTX2GPIONumber LEDBlk = gpio394;
	jetsonTX2GPIONumber LEDEdg = gpio393;
	
	gpioExport(LEDBlk);
	gpioExport(LEDEdg);
	gpioSetDirection(LEDBlk,outputPin);
	gpioSetDirection(LEDEdg,outputPin);
	
    jetsonTX2GPIONumber LEDNum[] = [gpio398, gpio298, gpio389, gpio395, gpio388];
	
	for(int i = 0; i < 5; i++){
		gpioExport(LED[i]);
		gpioSetDirection(LED[i],outputPin);
	}
    
	if(mode == "PlayBack"){
		std::ifstream file(LOG_FILE);
		std::string line;
		while (getline(file, line)) {
			if(line.front() == "_"){
				int Num = static_cast<int>(line.substr(1, input.find(" ")));
				LEDNum(Num, LEDNum);
				usleep(100);
			}else{
				LEDBlink(LEDBlk);
				gpioSetEdge(LEDEdg, "rising")
			}
		}
		file.close();
		
		std::cout<<"exited: "<<std::endl;
	}else if(mode =="Online"){
		std::ifstream file(LOG_FILE);
		char flag;
		std::cout<<"press esc to exit! "<<std::endl;
		while(true){
			flag = getch();
			if (flag == 27) { file.close(); break; }
			
			std::string line = getLastLine(file);
			
			if(line.front() == "_"){
				int Num = static_cast<int>(line.substr(1, input.find(" ")));
				LEDNum(Num, LEDNum);
				usleep(100);
			}else{
				LEDBlink(LEDBlk);
				gpioSetEdge(LEDEdg, "rising")
			}
		}
		std::cout<<"exited: "<<std::endl;
	}else{
		std::out << "Arguement ERROR" << std::endl;
	}

    std::cout << "GPIO output finished." << std::endl;
	gpioUnexport(LEDBlk);
	gpioUnexport(LEDEdg);
	for(int i = 0, i < 5, i++){
		gpioUnexport(LED[i]);
	}
    return 0;
}


