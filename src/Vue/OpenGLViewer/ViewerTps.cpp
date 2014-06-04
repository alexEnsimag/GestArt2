#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include "ViewerTps.hpp"
#include "../../Controler/Kinect/Parser.hpp"
#include <unistd.h>
#include <time.h>


// A modifier !
Squelette *squel2;

ViewerTps::ViewerTps(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	squel2 = new Squelette();
}

static void sleep2(unsigned int ms){
	clock_t goal = ms + clock();
	while(goal>clock());
}

static void RenderSceneCB()
{
    sleep2(100000);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    squel2->draw();
    
    glFlush();
    
/*
    temps += 0.1;
    float p[3] = {0.0f, temps, 0.0f};
    squel2->setTorse(p);
*/
    glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void ViewerTps::launch(){
	glutCreateWindow("Tutorial 01");
	InitializeGlutCallbacks();
	glutMainLoop();
}


ViewerTps::~ViewerTps(){
//	delete squel2;
}
