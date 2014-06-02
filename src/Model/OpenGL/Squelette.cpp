
#include <stdio.h>
#include <GL/freeglut.h>
#include "Squelette.hpp"

Squelette::Squelette(){

	head = new Sommet(0,0,0);
	neck = new Sommet(0,0,1);

}

void Squelette::draw(){
/*	glBegin(GL_LINES);
		//glVertex3f(head->x, head->y, head->z);	
		//glVertex3f(neck->x, neck->y, neck->z);	

	glEnd;
*/

	

}

void Squelette::setHead(Sommet p){

}
