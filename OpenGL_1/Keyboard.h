#pragma once

#include "Main.h"
#include <GL\glew.h>

//TODO: Repair upside down movement
void Keyboard(unsigned char key, int x, int y)
{
	Logs cords;

	if (key == 'w') {
		eyez -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 's') {
		eyez += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 'a') {
		eyex -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == 'd') {
		eyex += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == '+') {
		eyey += 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}
	if (key == '-') {
		eyey -= 0.1;
		cords.writeCords(eyex, eyey, eyez);
	}

	// Display new frame
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// Left arrow
	case GLUT_KEY_LEFT:
		centerx -= 0.8;
		break;

		// Up arrow
	case GLUT_KEY_UP:
		centerz -= 0.8;
		break;

		// Right arrow
	case GLUT_KEY_RIGHT:
		centerx += 0.8;
		break;

		// Bottom arrow
	case GLUT_KEY_DOWN:
		centerz += 0.8;
		break;
	}

	// Display new frame
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}