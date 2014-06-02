#include "Viewer.hpp"
#include <GL/glut.h>

void Viewer::launch(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01");
	//glutDisplayFunc(RenderSceneCB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
