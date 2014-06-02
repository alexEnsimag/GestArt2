#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Viewer.hpp"


// A modifier !
Squelette *squelette;
float temps;

Viewer::Viewer(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	squelette = new Squelette();
}


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    squelette->draw();
    glFlush();
    temps += 0.1;
    float p[3] = {0.0f, temps, 0.0f};
    squelette->setTorse(p);
    glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void Viewer::launch(){
	glutCreateWindow("Tutorial 01");
	InitializeGlutCallbacks();
	glutMainLoop();
}


Viewer::~Viewer(){
//	delete squelette;
}
