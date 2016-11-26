#pragma once
#include "Main.h"

#include <GL\glut.h>

GLdouble eyex = 0;
GLdouble eyey = 0;
GLdouble eyez = 3;


GLdouble centerx = 0;
GLdouble centery = 0;
GLdouble centerz = -100;

GLdouble upx = 0;
GLdouble upy = 1;
GLdouble upz = 0;

GLdouble rotatex = 0.0;
GLdouble rotatey = 0.0;

double color_R = 0.0;
double color_G = 0.0;
double color_B = 0.0;

void Display()
{
	Generator cube;
	Generator objectFile;

	glClearColor(color_R, color_G, color_B, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);

	double x = 5.0;
	double y = 4.0;
	double z = 3.0;

	/*cube.renderWall(x, y, z);
	cube.render();
	glTranslatef(-5.0, 0.0, 0.0);
	cube.renderLStairs(x, y, z);
	glTranslatef(x, -1, -z);
	cube.renderRStairs(x, y, z);
	glTranslatef(5, 5, 5); */
	objectFile.getObjFromFile("../objects/walltest.3DV");

	glFlush();
	glutSwapBuffers();
}
