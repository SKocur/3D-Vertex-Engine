#include "Generator.h"
#include "Logs.h"

#include <GL/glut.h>

Generator::Generator()
{
	//Logs log;
	//log.initClasses("Generator");
}


Generator::~Generator()
{
}

void Generator::render() {
	// Color of borders
	glColor3f(0.0, 0.0, 0.0);

	// Definition of cube
	glBegin(GL_LINES);

		// Coordinates (and colors) of corners
		glVertex3f(1.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);

		glVertex3f(1.0, -1.0, 1.0);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(1.0, -1.0, -1.0);
		glColor3f(0.0, 1.0, 0.0);

		glVertex3f(1.0, -1.0, -1.0);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, -1.0);
		glColor3f(0.0, 0.0, 1.0);

		glVertex3f(1.0, 1.0, -1.0);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(1.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);

		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);

		glVertex3f(-1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, 1.0, -1.0);

		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(-1.0, 1.0, 1.0);

		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(-1.0, 1.0, 1.0);

		glVertex3f(1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);

		glVertex3f(1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);

		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(-1.0, 1.0, -1.0);

	// End of cube's definition
	glEnd();
}

// Generate linear wall
void Generator::renderLinearWall(int lengthX) {
	//Black color
	glColor3f(0.0, 0.0, 0.0);
	
	for (int a = 0; a < lengthX; a++) {
		glutWireCube(1);
		glTranslatef(1.0, 0.0, 0.0);
	}
}

// Generate a plane with given parameters
void Generator::renderPlane(int lengthX, int widthZ) {
	Generator cube;

	for (int a = 0; a < widthZ; a++) {
		cube.renderLinearWall(lengthX);
		glTranslatef(-lengthX, 0.0, -1.0);
	}
}

// Generate a wall with given parameters
void Generator::renderWall(int lengthX, int widthZ, int heightY) {
	Generator plane;

	for (int a = 0; a < heightY; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(0.0, 1.0, widthZ);
	}
}

// Generate a stairs (to the left) with given parameters
void Generator::renderLStairs(int lengthX, int widthZ, int steps) {
	Generator plane;

	for (int a = 0; a < steps; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(-lengthX, 1.0, widthZ);
	}
}

// Generate a stairs (to the right) with given parameters
void Generator::renderRStairs(int lengthX, int widthZ, int heightY) {
	Generator plane;

	for (int a = 0; a < heightY; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(lengthX, 1.0, widthZ);
	}
}