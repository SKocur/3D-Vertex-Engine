#pragma once
#include <GL/glew.h>
class Logs
{
public:
	Logs();
	~Logs();

	void writeCords(double eyex, double eyey, double eyez, double centerx, double centery, double centerz);
	void initClasses(char* name);
};

