#pragma once

#include "../include/Main.h"

enum BackgroundColors {
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PURPLE,
	CYAN,
	ORANGE
};

void MenuColor(int color) {
	switch (color) {
	case BLACK:
		color_R = 0.0;
		color_G = 0.0;
		color_B = 0.0;
		glutSwapBuffers();
		break;

	case WHITE:
		color_R = 1.0;
		color_G = 1.0;
		color_B = 1.0;
		glutSwapBuffers();
		break;

	case RED:
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
		glutSwapBuffers();
		break;

	case GREEN:
		color_R = 0.0;
		color_G = 1.0;
		color_B = 0.0;
		glutSwapBuffers();
		break;

	case BLUE:
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
		glutSwapBuffers();
		break;

	case YELLOW:
		color_R = 1.0;
		color_G = 1.0;
		color_B = 0.0;
		glutSwapBuffers();
		break;
	
	case PURPLE:
		color_R = 1.0;
		color_G = 0.0;
		color_B = 1.0;
		glutSwapBuffers();
		break;

	case CYAN:
		color_R = 0.0;
		color_G = 1.0;
		color_B = 1.0;
		glutSwapBuffers();
		break;

	case ORANGE:
		color_R = 1.0;
		color_G = 0.5;
		color_B = 0.0;
		glutSwapBuffers();
		break;
	}
}
