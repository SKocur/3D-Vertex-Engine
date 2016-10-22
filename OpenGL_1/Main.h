#pragma once

#include "GUI.h"
#include "cube_1.h"
#include "Logs.h"

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

/* Basic funtions of our engine:
-Menu()
-Display()
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

// Coordinate of player's camera

GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 3;

// Coordinates of the direction

GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = -100;

// Function which generates 3D scene
void Display()
{
	GUI gui;
	cube_1 cube1;
	// Background color
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Type of matrix
	glMatrixMode(GL_MODELVIEW);

	// Identity matrix
	glLoadIdentity();

	// Position of player
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, 0, 1, 0);

	cube1.render();
	glutWireCube(1);
	glTranslatef(1.0, -1.0, 0.0);
	glutWireCube(1);

	// Commands to execute
	glFlush();

	// Change buffer
	glutSwapBuffers();
}

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
			glFrustum(-2.0, 2.0, -2.0 * height / width, 2.0 * height / width, 1.0, 5.0);
		else
			if (width >= height && height > 0)
				glFrustum(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0, 1.0, 5.0);
	}
	else
		glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 5.0);

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
