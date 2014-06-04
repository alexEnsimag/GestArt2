#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "Viewer.hpp"
#include "../../Model/OpenGL/math_3d.h"

GLuint VBO2;

Viewer::Viewer(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glEnable(GL_LIGHTING);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
}


static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
}


static void CreateVertexBuffer()
{
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);
	Vertices[0] = Vector3f(1.0f, 0.0f, 0.0f);
	Vertices[0] = Vector3f(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

void Viewer::launch(){
	glutCreateWindow("Game Mode");
	InitializeGlutCallbacks();
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	}
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	CreateVertexBuffer();
	glutMainLoop();
}

Viewer::~Viewer(){
	//	delete squelette;
}
