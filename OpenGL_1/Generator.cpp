#include "Generator.h"
#include "Logs.h"

#include <GL/glut.h>

Generator::Generator()
{
}


Generator::~Generator()
{
}

void Generator::render() {
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
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
	glEnd();
}

void Generator::renderWall(int lengthX, int widthZ, int heightY) {
	Generator plane;

	for (int a = 0; a < heightY; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(0.0, 1.0, widthZ);
	}
}

void Generator::renderPlane(int lengthX, int widthZ) {
	Generator cube;

	for (int a = 0; a < widthZ; a++) {
		cube.renderLinearWall(lengthX);
		glTranslatef(-lengthX, 0.0, -1.0);
	}
}

void Generator::renderLinearWall(int lengthX) {
	glColor3f(1.0, 0.9, 0.0);
	
	for (int a = 0; a < lengthX; a++) {
		glutWireCube(1);
		glTranslatef(1.0, 0.0, 0.0);
	}
}

void Generator::renderLStairs(int lengthX, int widthZ, int steps) {
	Generator plane;

	for (int a = 0; a < steps; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(-lengthX, 1.0, widthZ);
	}
}

void Generator::renderRStairs(int lengthX, int widthZ, int steps) {
	Generator plane;

	for (int a = 0; a < steps; a++) {
		plane.renderPlane(lengthX, widthZ);
		glTranslatef(lengthX, 1.0, widthZ);
	}
}