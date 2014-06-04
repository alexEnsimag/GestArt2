//#include <windows.h>

#include <iostream>
#include "math_3d.h"

#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

using namespace std;

#include "shader.hpp"

GLuint VBO;
//Initializes 3D rendering

void initRendering() {

	//Makes 3D drawing work when something is in front of something else

	glEnable(GL_DEPTH_TEST);

}

//Called when the window is resized

void handleResize(int w, int h) {

	//Tell OpenGL how to convert from coordinates to pixel values

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective

	glLoadIdentity(); //Reset the camera

	gluPerspective(45.0,                  //The camera angle

			(double)w / (double)h, //The width-to-height ratio

			1.0,                   //The near z clipping coordinate

			200.0);                //The far z clipping coordinate

}

//Draws the 3D scene

void drawScene() {

	GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	//Clear information from last draw

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Trapezoid

	glVertex3f(-0.7f, -1.5f, -5.0f);

	glVertex3f(0.7f, -1.5f, -5.0f);

	glVertex3f(0.7f, -0.5f, -5.0f);

	glVertex3f(-0.7f, -0.5f, -5.0f);

	glEnd(); //End quadrilateral coordinates

	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
   		-1.0f, -1.0f, 0.0f,
   	1.0f, -1.0f, 0.0f,
   	0.0f,  1.0f, 0.0f,
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);	

	glUseProgram(programID);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
/*
	glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//Triangle

	glVertex3f(-0.5f, 0.5f, -5.0f);

	glVertex3f(-1.0f, 1.5f, -5.0f);

	glVertex3f(-1.5f, 0.5f, -5.0f);

	glEnd(); //End triangle coordinates
*/
	glutSwapBuffers(); //Send the 3D scene to the screen

}

int main(int argc, char** argv) {

	//Initialize GLUT

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(400, 400); //Set the window size

	//Create the window

	glutCreateWindow("Basic Shapes - programming-technique.blogspot.com");

	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glewInit();




	glutDisplayFunc(drawScene);

	//glutKeyboardFunc(handleKeypress);

	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop

	return 0;

}