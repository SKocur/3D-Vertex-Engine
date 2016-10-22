#pragma once
#include <GL/glew.h>
class Logs
{
public:
	Logs();
	~Logs();

	void writeCords(double eyex, double eyey, double eyez);
	void initClasses(char* name);
};

