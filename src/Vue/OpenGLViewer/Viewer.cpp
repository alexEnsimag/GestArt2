#include "Viewer.hpp"
#include <GL/freeglut.h>




static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

Viewer::Viewer(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	squelette = new Squelette();
}

void Viewer::launch(){
	glutCreateWindow("Tutorial 01");
	InitializeGlutCallbacks();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	squelette->draw;
	glutMainLoop();
}

