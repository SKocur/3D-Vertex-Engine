#include "GUI.h"

#include <GL/glut.h>

GUI::GUI()
{
}


GUI::~GUI()
{
}

// TODO: Repair text()
// Display 2D text 
void GUI::text() {
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
}