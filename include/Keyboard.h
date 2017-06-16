#pragma once

#include "Main.h"
#include <GL\glut.h>

void Keyboard(unsigned char key, int x, int y)
{
	Logs cords;

	if (key == 'w') {
		eyez -= 0.1;
		centerz -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 's') {
		eyez += 0.1;
		centerz += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 'a') {
		eyex -= 0.1;
		centerx -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 'd') {
		eyex += 0.1;
		centerx += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 'q') {
		rotatey -= 1;
		eyez -= 0.01;
		centerz += 0.01;
	}
	if (key == 'e') {
		rotatey += 1;
		eyez += 0.01;
		centerz -= 0.01;
	}
	if (key == '+') {
		eyey += 0.1;
		centery += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == '-') {
		eyey -= 0.1;
		centery -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}

	// Display new frame
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void SpecialKeys(int key, int x, int y)
{
	Logs cords;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (upx > -1) {
			upx -= 0.01;
		}
		break;

	case GLUT_KEY_UP:
		rotatex -= 1;
		break;

	case GLUT_KEY_RIGHT:
		if (upx < 1) {
			upx += 0.01;
		}
		break;

	case GLUT_KEY_DOWN:
		rotatex += 1;
		break;
	}

	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}