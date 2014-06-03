#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "Viewer.hpp"
#include "../../Model/OpenGL/Mesh.hpp"


// A modifier !
Mesh m_pMesh;

Viewer::Viewer(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	squelette = new Squelette();
}


static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	m_pMesh->Render();
        glutSwapBuffers();

}

static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
}

static bool InitMesh(){

	m_pMesh = new Mesh();

	return m_pMesh->LoadMesh("../Content/phoenix_ugv.md2");

}

void Viewer::launch(){
	glutCreateWindow("Game Mode");
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}

	if(! InitMesh()){
		fprintf(stderr, "Error: '%s'\n", "error while loading the mesh");
	}

	InitializeGlutCallbacks();
	glutMainLoop();
}


Viewer::~Viewer(){
	delete m_pMesh;
}
