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
	// Initialization glut library
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	//Size of main screen
	glutInitWindowSize(720, 720);

	//Create windows with given title
	glutCreateWindow("3D Vertex Engine");

	// It generates 3D scene
	glutDisplayFunc(Display);

	// Called when window is being resized
	glutReshapeFunc(Reshape);

	// Keyboard
	glutKeyboardFunc(Keyboard);

	// Keyboard - function keys
	glutSpecialFunc(SpecialKeys);

	// It creates pop-up menu near to cursor
	glutCreateMenu(Menu);

	//Display coordinate of default camera's position
	cords.writeCords(eyex, eyey, eyez, centerx, centery, centerz);

	// Add options to pop-up menu
	// It uses polish language when WIN32 is defined
	// if not, default is english


	glutAddMenuEntry("Aspect ratio - full window", FULL_WINDOW);
	glutAddMenuEntry("Aspect ratio 1:1", ASPECT_1_1);
	glutAddMenuEntry("Exit", EXIT);

	// Show pop-up menu when right mouse button is clicked
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Main loop - program can handle the messages
	glutMainLoop();

	return 0;
}