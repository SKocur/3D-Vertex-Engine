/*	
	Author: Szymon Kocur
	e-mail: skocur10@gmail.com
	LinkedIn: https://pl.linkedin.com/in/szymon-kocur
	
	Project:
	GitHub: https://github.com/SKocur/3D-Vertex-Engine
*/

#include "../include/Main.h"
#include "../include/MenuColors.h"
#include "../include/Keyboard.h"
#include "../include/Mouse.h"

int main(int argc, char * argv[])
{
	int mainMenu, colorsMenu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(720, 720);
	glutCreateWindow("3D Vertex Engine");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouseButton);

	colorsMenu = glutCreateMenu(MenuColor);
	glutAddMenuEntry("Black", BLACK);
	glutAddMenuEntry("White", WHITE);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Yellow", YELLOW);
	glutAddMenuEntry("Purple", PURPLE);
	glutAddMenuEntry("Cyan", CYAN);
	glutAddMenuEntry("Orange", ORANGE);

	mainMenu = glutCreateMenu(Menu);
	glutAddMenuEntry("Aspect ratio - full window", FULL_WINDOW);
	glutAddMenuEntry("Aspect ratio 1:1", ASPECT_1_1);
	glutAddSubMenu("Change background color", colorsMenu);
	glutAddMenuEntry("Exit", EXIT);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}