#pragma once
#include "Main.h"

#include <GL\glut.h>

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
	glTranslatef(5, 5, 5);

	// Commands to execute
	glFlush();

	// Change buffer
	glutSwapBuffers();
}
