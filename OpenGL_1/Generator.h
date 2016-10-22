#pragma once
#include <iostream>

class Generator
{
public:
	Generator();
	~Generator();

	void render();
	void renderLinearWall(int lengthX);
	void renderWall(int lengthX, int widthZ, int heightY);
	void renderPlane(int lengthX, int widthZ);
	void renderLStairs(int lengthX, int widthZ, int steps);
	void renderRStairs(int lengthX, int widthZ, int steps);
};

