
#include <stdio.h>
#include <GL/freeglut.h>
#include "Squelette.hpp"

Squelette::Squelette(){


	head[0] = 0.0f;
	head[2] = 0.0f;
	head[1] = 0.8f;
	
	neck[0] = 0.0f;
	neck[2] = 0.0f;
	neck[1] = 0.6f;

	schoulderG[0] = 0.2f; 
	schoulderG[2] = 0.0f;
	schoulderG[1] = 0.6f;
	schoulderD[0] = -0.2f;
	schoulderD[2] = 0.0f;
	schoulderD[1] = 0.6f;
	coudeG[0] = 0.4f;
	coudeG[2] = 0.0f;     
	coudeG[1] = 0.2f;
	coudeD[0] = -0.4f;
	coudeD[2] = 0.0f; 
	coudeD[1] = 0.2f;
	mainG[0] = 0.8f;
	mainG[2] = 0.0f; 
	mainG[1] = -0.1f;
	mainD[0] = -0.8f;
	mainD[2] = 0.0f; 
	mainD[1] = -0.1f;
	torse[0] = 0.0f;
	torse[2] = 0.0f; 
	torse[1] = 0.0f;
	bassinG[0] = 0.2f;
	bassinG[2] = 0.0f; 
	bassinG[1] = -0.2f;
	bassinD[0] = -0.2f;
	bassinD[2] = 0.0f; 
	bassinD[1] = -0.2f;
	genouxG[0] = 0.25f;
	genouxG[2] = 0.0f; 
	genouxG[1] = -0.6f;
	genouxD[0] = -0.25f;
	genouxD[2] = 0.0f; 
	genouxD[1] = -0.6f;
	piedG[0] = 0.2f;
	piedG[2] = 0.0f; 
	piedG[1] = -1.0f;
	piedD[0] = -0.2f;
	piedD[2] = 0.0f; 
	piedD[1] = -1.0f;
	

	// Initialisation des os
	os.push_back(new Segment(head, neck));
	os.push_back(new Segment(neck, schoulderD));

	os.push_back(new Segment(neck, schoulderG));
	os.push_back(new Segment(neck, torse));
	os.push_back(new Segment(schoulderG, coudeG));
	os.push_back(new Segment(mainG, coudeG));
	os.push_back(new Segment(schoulderD, coudeD));
	os.push_back(new Segment(mainD, coudeD));
	os.push_back(new Segment(torse, bassinD));
	os.push_back(new Segment(torse, bassinG));
	os.push_back(new Segment(bassinD, genouxD));
	os.push_back(new Segment(bassinG, genouxG));
	os.push_back(new Segment(piedD, genouxD));
	os.push_back(new Segment(piedG, genouxG));
	
	
}

void Squelette::draw(){

	
	glBegin(GL_LINES);
		glVertex3fv(head);	
		glVertex3fv(neck);	
	glEnd();	
	
	glBegin(GL_LINES);
		glVertex3fv(neck);	
		glVertex3fv(schoulderG);	
	glEnd();	
	
	glBegin(GL_LINES);
		glVertex3fv(neck);	
		glVertex3fv(schoulderD);	
	glEnd();	
	
	glBegin(GL_LINES);
		glVertex3fv(schoulderG);	
		glVertex3fv(coudeG);	
	glEnd();	
	
	glBegin(GL_LINES);
		glVertex3fv(coudeG);	
		glVertex3fv(mainG);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(schoulderD);	
		glVertex3fv(coudeD);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(coudeD);	
		glVertex3fv(mainD);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(neck);	
		glVertex3fv(torse);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(torse);	
		glVertex3fv(bassinD);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(torse);	
		glVertex3fv(bassinG);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(bassinD);	
		glVertex3fv(genouxD);	
	glEnd();	

	glBegin(GL_LINES);
		glVertex3fv(genouxD);	
		glVertex3fv(piedD);	
	glEnd();	
	glBegin(GL_LINES);
		glVertex3fv(bassinG);	
		glVertex3fv(genouxG);	
	glEnd();	

	glBegin(GL_LINES);
		glVertex3fv(genouxG);	
		glVertex3fv(piedG);	
	glEnd();	

}

static void setCoord(float *dest, float *src){
	dest[2] = src[2];
	dest[1] = src[1];
	dest[0] = src[0];
	
}
void Squelette::setHead(float *p){
	setCoord(head, p);
}

void Squelette::setNeck(float *p){
	setCoord(neck, p);
}

void Squelette::setSchoulderG(float *p){
	setCoord(schoulderG, p);
}

void Squelette::setSchoulderD(float *p){
	setCoord(schoulderD, p);
}
void Squelette::setCoudeG(float *p){
	setCoord(coudeG, p);
}
void Squelette::setCoudeD(float *p){
	setCoord(coudeD, p);
}
void Squelette::setMainG(float *p){
	setCoord(mainG, p);
}
void Squelette::setMainD(float *p){
	setCoord(mainD, p);
}
void Squelette::setTorse(float *p){
	setCoord(torse, p);
}
void Squelette::setBassinG(float *p){
	setCoord(bassinG, p);
}
void Squelette::setBassinD(float *p){
	setCoord(bassinD, p);
}
void Squelette::setGenouxG(float *p){
	setCoord(genouxG, p);
}

void Squelette::setGenouxD(float *p){
	setCoord(genouxD, p);
}

void Squelette::setPiedG(float *p){
	setCoord(piedG, p);
}
void Squelette::setPiedD(float *p){
	setCoord(piedD, p);
}










