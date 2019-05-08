#!/bin/bash
rm -RF recordLOG;

if [-e "exampleGPIOApp"]; then
	rm exampleGPIOApp
fi

if [-e "Unexp"]; then
	rm Unexp
fi

mkdir recordLOG

echo build exampleGPIOApp:
g++ -O2 -Wall exampleGPIOApp.cpp jetsonGPIO.c -o exampleGPIOApp 

echo build Unexp:
g++ -O2 -Wall Unexp.cpp jetsonGPIO.c -o Unexp 
