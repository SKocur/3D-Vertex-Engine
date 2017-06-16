#include "../include/Generator.h"
#include "../include/Logs.h"

#include <GL/glut.h>
#include <iostream>
#include <fstream>

Generator cube;

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

void Generator::renderWall(int &lengthX, int &widthZ, int &heightY) {
	for (int a = 0; a < heightY; a++) {
		cube.renderPlane(lengthX, widthZ);
		glTranslatef(0.0, 1.0, widthZ);
	}
}

void Generator::renderPlane(int &lengthX, int &widthZ) {
	for (int a = 0; a < widthZ; a++) {
		cube.renderLinearWall(lengthX);
		glTranslatef(-lengthX, 0.0, -1.0);
	}
}

void Generator::renderLinearWall(int &lengthX) {
	//Below one changes color of rendered shapes
	glColor3f(1.0, 0.5, 0.0);
	
	for (int a = 0; a < lengthX; a++) {
		glutWireCube(1);
		glTranslatef(1.0, 0.0, 0.0);
	}
}

void Generator::renderLStairs(int &lengthX, int &widthZ, int &steps) {
	for (int a = 0; a < steps; a++) {
		cube.renderPlane(lengthX, widthZ);
		glTranslatef(-lengthX, 1.0, widthZ);
	}
}

void Generator::renderRStairs(int &lengthX, int &widthZ, int &steps) {
	for (int a = 0; a < steps; a++) {
		cube.renderPlane(lengthX, widthZ);
		glTranslatef(lengthX, 1.0, widthZ);
	}
}

using namespace std;
void Generator::getObjFromFile(char * path) {
	fstream object(path, ios::in);
	int length, height, width;

	object >> length >> height >> width;
	printf("wall size: %d %d %-5d", length, height, width);
	//cout << "wall size: " << length << height << width << endl;

	cube.renderWall(length, width, height);

	object.close();
}