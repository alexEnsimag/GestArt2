#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include "ViewerParser.hpp"
#include "../../Controler/Kinect/Parser.hpp"


// A modifier !
Squelette *squelette;
Parser *parser;
float temps;

ViewerParser::ViewerParser(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	squelette = new Squelette();
	parser = new Parser();
}


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    squelette->draw();
    
    glFlush();
    
     parser->parse();
/*
    temps += 0.1;
    float p[3] = {0.0f, temps, 0.0f};
    squelette->setTorse(p);
*/
    glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void ViewerParser::launch(string nomFichier){
	glutCreateWindow("Tutorial 01");
	parser->open(nomFichier);
	InitializeGlutCallbacks(nomFichier);
	glutMainLoop();
}


ViewerParser::~ViewerParser(){
//	delete squelette;
}
