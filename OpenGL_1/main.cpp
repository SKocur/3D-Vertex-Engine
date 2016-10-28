/*	
	Author: Szymon Kocur
	e-mail: skocur10@gmail.com
	LinkedIn: https://pl.linkedin.com/in/szymon-kocur
	
	Project:
	GitHub: https://github.com/SKocur/3D-Vertex-Engine
*/

#include "Main.h"
#include "Keyboard.h"

int main(int argc, char * argv[])
{
	Logs cords;
	GUI gui;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(720, 720);
	glutCreateWindow("3D Vertex Engine");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);
	glutCreateMenu(Menu);
	cords.writeCords(eyex, eyey, eyez, centerx, centery, centerz);

	glutAddMenuEntry("Aspect ratio - full window", FULL_WINDOW);
	glutAddMenuEntry("Aspect ratio 1:1", ASPECT_1_1);
	glutAddMenuEntry("Exit", EXIT);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}