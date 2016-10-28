#include "../include/Logs.h"

#include <GL/glew.h>
#include <iostream>

Logs::Logs()
{
}


Logs::~Logs()
{
}

void Logs::writeCords(double eyex, double eyey, double eyez, double centerx, double centery, double centerz) {
	std::cout << "x: " << eyex;
	std::cout << " cenx: " << centerx;
	std::cout << " y: " << eyey;
	std::cout << " ceny: " << centery;
	std::cout << " z: " << eyez;
	std::cout << " cenz: "<< centerz << std::endl;
}

void Logs::initClasses(char* name) {
	std::cout << "run " << name << std::endl;
}