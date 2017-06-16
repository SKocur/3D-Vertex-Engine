#include "../include/Logs.h"

#include <GL/glew.h>
#include <iostream>

Logs::Logs()
{
}

Logs::~Logs()
{
}

void Logs::writeCords(double &eyex, double &eyey, double &eyez) {
	printf("x: %-10.1f", eyex);
	printf("y: %-10.1f", eyey);
	printf("z: %-10.1f \n", eyez);
}

void Logs::initClasses(char* name) {
	std::cout << "run " << name << std::endl;
}