#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Viewer.hpp"


// A modifier !
Squelette *squelette;
float temps;

Viewer::Viewer(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	squelette = new Squelette();
}


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    squelette->draw();
    //glFlush();

    temps += 0.1;
    float p[3] = {0.0f, temps, 0.0f};
    squelette->setTorse(p);
	
    glutPostRedisplay();
    //glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void Viewer::launch(){
	glutCreateWindow("Tutorial 01");
 	// Must be done after glut is initialized!
    	GLenum res = glewInit();
    	if (res != GLEW_OK) {
      		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    	}
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	InitializeGlutCallbacks();
	glutMainLoop();
}


Viewer::~Viewer(){
//	delete squelette;
}
