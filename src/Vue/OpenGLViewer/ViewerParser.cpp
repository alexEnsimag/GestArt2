#include "ViewerParser.hpp"

// A modifier !
Squelette *squel;
Parser *parser;

ViewerParser::ViewerParser(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	squel = new Squelette();
	parser = new Parser();
}

static void sleep2(unsigned int ms){
	clock_t goal = ms + clock();
	while(goal>clock());
}

static void RenderSceneCB()
{
    sleep2(100000);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4, 0.6, 0.0);
    squel->draw();
    glFlush();
	//animation
     parser->parse(squel);
    glutPostRedisplay();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

void ViewerParser::launch(string nomFichier){
	glutCreateWindow("Tutorial 01");
	parser->openFichier(nomFichier);
	InitializeGlutCallbacks();
	glutMainLoop();
	parser->close();
}


ViewerParser::~ViewerParser(){
	delete squel;
}
