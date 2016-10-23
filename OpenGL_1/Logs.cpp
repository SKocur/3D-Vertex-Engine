#include "Logs.h"

#include <GL/glew.h>
#include <iostream>

Logs::Logs()
{
}


Logs::~Logs()
{
}

// It writes coordinates of camera to the console
void Logs::writeCords(double eyex, double eyey, double eyez, double centerx, double centery, double centerz) {
	std::cout << "x: " << eyex;
	std::cout << " cenx: " << centerx;
	std::cout << " y: " << eyey;
	std::cout << " ceny: " << centery;
	std::cout << " z: " << eyez;
	std::cout << " cenz: "<< centerz << std::endl;
}

// OPTIONAL
// Can be used to write a name of class during initialization
void Logs::initClasses(char* name) {
	std::cout << "run " << name << std::endl;
}