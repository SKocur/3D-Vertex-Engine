#pragma once

#include "GUI.h"
#include "Generator.h"
#include "Logs.h"
#include "Scene.h"

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

enum
{
	FULL_WINDOW, 
	ASPECT_1_1,
	EXIT
};

int Aspect = FULL_WINDOW;

void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (Aspect == ASPECT_1_1)
	{
		if (width < height && width > 0)
			glFrustum(-2.0, 2.0, -2.0 * height / width, 2.0 * height / width, 1.0, 500.0);
		else
			if (width >= height && height > 0)
				glFrustum(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0, 1, 500.0);
	}
	else
		glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 500.0);

	Display();
}

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
