#pragma once

#include "GUI.h"
#include "Generator.h"
#include "Logs.h"
#include "Scene.h"

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

/* Basic funtions of our engine:
-Menu()
-Reshape()
*/

// Constants to pop-up menu

enum
{
	FULL_WINDOW, // aspect ratio - full window
	ASPECT_1_1, // aspect ratio 1:1
	EXIT // Exit
};

// Aspect ratio

int Aspect = FULL_WINDOW;

// Change size of window
void Reshape(int width, int height)
{
	// Render field - full window
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

	// Dispay 3D scene
	Display();
}

// Pop-up menu
void Menu(int value)
{
	switch (value)
	{
		// Render field- full window
	case FULL_WINDOW:
		Aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// Render field - aspect 1:1
	case ASPECT_1_1:
		Aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// Exit
	case EXIT:
		exit(0);
	}
}
