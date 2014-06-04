#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "ViewerJeux.hpp"

GLuint VBO2;

ViewerJeux::ViewerJeux(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glEnable(GL_LIGHTING);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
}

void ViewerJeux::launch(){
	glutCreateWindow("Game Mode");
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}
	printf("GL version: %s\n", glGetString(GL_VERSION));
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
}

ViewerJeux::~ViewerJeux(){
	//	delete squelette;
}
