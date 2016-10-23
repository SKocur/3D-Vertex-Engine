#pragma once

#include "GUI.h"
#include "Generator.h"
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

// Coordinates of up vector
GLdouble upx = 0;
GLdouble upy = 1;
GLdouble upz = 0;

GLdouble rotatex = 0.0;
GLdouble rotatey = 0.0;

// Function which generates 3D scene
void Display()
{
	GUI gui;
	Generator cube;
	// Background color
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Type of matrix
	glMatrixMode(GL_MODELVIEW);

	// Identity matrix
	glLoadIdentity();

	// Position of player
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);

	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);

	// Simple presentation of function generating some 3D objects
	double x = 5.0;
	double y = 4.0;
	double z = 3.0;

	cube.renderWall(x, y, z);
	cube.render();
	glTranslatef(-5.0, 0.0, 0.0);
	cube.renderLStairs(x, y, z);
	glTranslatef(x, -1, -z);
	cube.renderRStairs(x, y, z);

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
