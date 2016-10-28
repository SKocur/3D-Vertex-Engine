#pragma once

#include "Main.h"

enum
{
	FULL_WINDOW,
	ASPECT_1_1,
	EXIT
};

int Aspect = FULL_WINDOW;

void Menu(int value)
{
	switch (value)
	{
	case FULL_WINDOW:
		Aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

	case ASPECT_1_1:
		Aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

	case EXIT:
		exit(0);
	}
}