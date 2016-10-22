#include "cube_1.h"
#include "Logs.h"

#include <GL/glut.h>

cube_1::cube_1()
{
	//Logs log;
	//log.initClasses("cube_1");
}


cube_1::~cube_1()
{
}

void cube_1::render() {
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