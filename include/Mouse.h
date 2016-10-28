#pragma once

#include "Main.h"

int button_state = GLUT_UP;
int mouse_button_x, mouse_button_y;
int translate_x, translate_y;

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) 
	{
		button_state = state;

		if (state == GLUT_DOWN) 
		{
			mouse_button_x = x;
			mouse_button_y = y;
		}
	}
}