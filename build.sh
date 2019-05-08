#!/bin/bash
if [-e "exampleGPIOApp"]; then
	rm exampleGPIOApp
fi

g++ -O2 -Wall exampleGPIOApp.cpp jetsonGPIO.c -o exampleGPIOApp 
