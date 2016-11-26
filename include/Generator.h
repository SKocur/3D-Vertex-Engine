#pragma once
#include <iostream>

class Generator
{
public:
	Generator();
	~Generator();

	void render();
	void renderWall(int lengthX, int widthZ, int heightY);
	void renderPlane(int lengthX, int widthZ);
	void renderLinearWall(int lengthX);
	void renderLStairs(int lengthX, int widthZ, int steps);
	void renderRStairs(int lengthX, int widthZ, int steps);
	void getObjFromFile(char * path);
};

