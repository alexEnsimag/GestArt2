
#include "Squelette.hpp"


Squelette::Squelette(){


	head.x = 0.0f;
	head.z = 2.0f;
	head.y = 0.8f;

	schoulderG.x = 0.18f; 
	schoulderG.z = 2.0f;
	schoulderG.y = 0.6f;
	schoulderD.x = -0.18f;
	schoulderD.z = 2.0f;
	schoulderD.y = 0.6f;


	coudeG.x = 0.2f;
	coudeG.z = 2.0f;     
	coudeG.y = 0.18f;
	coudeD.x = -0.2f;
	coudeD.z = 2.0f; 
	coudeD.y = 0.18f;
	mainG.x = 0.22f;
	mainG.z = 2.0f; 
	mainG.y = -0.1f;
	mainD.x = -0.22f;
	mainD.z = 2.0f; 
	mainD.y = -0.1f;
	torse.x = 0.0f;
	torse.z = 2.0f; 
	torse.y = 0.0f;
	bassinG.x = 0.1f;
	bassinG.z = 2.0f; 
	bassinG.y = 0.1f;
	bassinD.x = -0.1f;
	bassinD.z = 2.0f; 
	bassinD.y = 0.1f; 

	genouxG.x = 0.1f;
	genouxG.z = 2.0f; 
	genouxG.y = -0.35f;
	genouxD.x = -0.1f;
	genouxD.z = 2.0f; 
	genouxD.y = -0.35f;
	piedG.x = 0.1f;
	piedG.z = 2.0f; 
	piedG.y = -0.7f;
	piedD.x = -0.1f;
	piedD.z = 2.0f; 
	piedD.y = -0.7f;

	os.push_back(new Segment(&head, &neck));	
	os.push_back(new Segment(&schoulderG, &neck));	
	os.push_back(new Segment(&schoulderD, &neck));	
	os.push_back(new Segment(&schoulderG, &coudeG));	
	os.push_back(new Segment(&schoulderD, &coudeD));	
	os.push_back(new Segment(&coudeG, &mainG));	
	os.push_back(new Segment(&coudeD, &mainD));	
	os.push_back(new Segment(&neck, &torse));	
	os.push_back(new Segment(&ass, &bassinG));	
	os.push_back(new Segment(&ass, &bassinD));	
	os.push_back(new Segment(&torse, &ass));	
	os.push_back(new Segment(&bassinG, &genouxG));	
	os.push_back(new Segment(&genouxG, &piedG));	
	os.push_back(new Segment(&bassinD, &genouxD));	
	os.push_back(new Segment(&genouxD, &piedD));	
}


Squelette::Squelette(vector<Vertex> *vert){
	vertices = vert;
	head.x = 0.0f;
	head.z = 2.0f;
	head.y = 0.8f;

	schoulderG.x = 0.18f; 
	schoulderG.z = 2.0f;
	schoulderG.y = 0.6f;
	schoulderD.x = -0.18f;
	schoulderD.z = 2.0f;
	schoulderD.y = 0.6f;


	coudeG.x = 0.2f;
	coudeG.z = 2.0f;     
	coudeG.y = 0.18f;
	coudeD.x = -0.2f;
	coudeD.z = 2.0f; 
	coudeD.y = 0.18f;
	mainG.x = 0.22f;
	mainG.z = 2.0f; 
	mainG.y = -0.1f;
	mainD.x = -0.22f;
	mainD.z = 2.0f; 
	mainD.y = -0.1f;
	torse.x = 0.0f;
	torse.z = 2.0f; 
	torse.y = 0.0f;
	bassinG.x = 0.1f;
	bassinG.z = 2.0f; 
	bassinG.y = 0.1f;
	bassinD.x = -0.1f;
	bassinD.z = 2.0f; 
	bassinD.y = 0.1f; 

	genouxG.x = 0.1f;
	genouxG.z = 2.0f; 
	genouxG.y = -0.35f;
	genouxD.x = -0.1f;
	genouxD.z = 2.0f; 
	genouxD.y = -0.35f;
	piedG.x = 0.1f;
	piedG.z = 2.0f; 
	piedG.y = -0.7f;
	piedD.x = -0.1f;
	piedD.z = 2.0f; 
	piedD.y = -0.7f;

	os.push_back(new Segment(&head, &neck));	
	os.push_back(new Segment(&schoulderG, &neck));	
	os.push_back(new Segment(&schoulderD, &neck));	
	os.push_back(new Segment(&schoulderG, &coudeG));	
	os.push_back(new Segment(&schoulderD, &coudeD));	
	os.push_back(new Segment(&coudeG, &mainG));	
	os.push_back(new Segment(&coudeD, &mainD));	
	os.push_back(new Segment(&neck, &torse));	
	os.push_back(new Segment(&ass, &bassinG));	
	os.push_back(new Segment(&ass, &bassinD));	
	os.push_back(new Segment(&torse, &ass));	
	os.push_back(new Segment(&bassinG, &genouxG));	
	os.push_back(new Segment(&genouxG, &piedG));	
	os.push_back(new Segment(&bassinD, &genouxD));	
	os.push_back(new Segment(&genouxD, &piedD));

	setVertices();
}

void Squelette::draw(){

	glLineWidth(6);

	// maj neck et ass
	Vector3f pNeck;
	pNeck.x =  (schoulderG.x+schoulderD.x)/2;
	pNeck.y =  (schoulderG.y+schoulderD.y)/2;
	pNeck.z =  (schoulderG.z+schoulderD.z)/2;
	setNeck(pNeck);
	Vector3f pAss;
	pAss.x =  (bassinG.x+bassinD.x)/2;
	pAss.y =  (bassinG.y+bassinD.y)/2;
	pAss.z =  (bassinG.z+bassinD.z)/2;
	setAss(pAss);

	//	setHead(pNeck);


	for(int i=0; i<os.size(); i++){

	   	glBegin(GL_LINES);
		glVertex3f((os[i]->p1)->x,(os[i]->p1)->y,(os[i]->p1)->z);	
		glVertex3f((os[i]->p2)->x,(os[i]->p2)->y,(os[i]->p2)->z);	
		glEnd();	
	}
	/*
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
	   glVertex3fv(ass);	
	   glEnd();	
	   glBegin(GL_LINES);
	   glVertex3fv(ass);	
	   glVertex3fv(bassinD);	
	   glEnd();	
	   glBegin(GL_LINES);
	   glVertex3fv(ass);	
	   glVertex3fv(bassinG);	
	   glEnd();	
	   glBegin(GL_LINES);
	   glVertex3fv(bassinD);	
	   glVertex3fv(genouxD);	
	   glEnd();	

	   glBegin(GL_LINES);
	//		glVertex3fv(genouxD);	
	//		glVertex3fv(piedD);	
	glEnd();	
	glBegin(GL_LINES);
	glVertex3fv(bassinG);	
	glVertex3fv(genouxG);	
	glEnd();	

	glBegin(GL_LINES);
	//		glVertex3fv(genouxG);	
	//		glVertex3fv(piedG);	
	glEnd();	
	 */
}

static float computeDistance(Segment *seg, Vertex v){
	if(distancePoints(*(seg->p1), v.m_pos) < distancePoints(*(seg->p2), v.m_pos)){
		Vector3f v1 = Vector3f(seg->p2->x-seg->p1->x, seg->p2->x-seg->p1->x, seg->p2->x-seg->p1->x);
		Vector3f v2 = Vector3f(v.m_pos.x-seg->p1->x,v.m_pos.y-seg->p1->y,v.m_pos.z-seg->p1->z);
		Vector3f vecProj = projection(v2, v1);
		if(scal(v2,v1)>0){
			Vector3f vResult = Vector3f(v2.x - vecProj.x, v2.y - vecProj.y, v2.z - vecProj.z);
			return longueur(vResult);
		}else{
			return distancePoints(v.m_pos, *(seg->p1));
		}
	}else{
		Vector3f v1 = Vector3f(seg->p2->x-seg->p1->x, seg->p2->x-seg->p1->x, seg->p2->x-seg->p1->x);
		Vector3f v2 = Vector3f(v.m_pos.x-seg->p2->x,v.m_pos.y-seg->p2->y,v.m_pos.z-seg->p2->z);
		Vector3f vecProj = projection(v2, v1);
		if(scal(v2,v1)>0){
			Vector3f vResult = Vector3f(v2.x - vecProj.x, v2.y - vecProj.y, v2.z - vecProj.z);
			return longueur(vResult);
		}else{
			return distancePoints(v.m_pos, *(seg->p2));
		}

	}
}

void Squelette::setVertices(){
	for(int i=0; i<vertices->size(); i++){
		Segment *s = foundSegment((*vertices)[i]);
		s->verticesAssocies.push_back(&(*vertices)[i]);
	}
}

Segment* Squelette::foundSegment(Vertex v){
	float distMin = 500;
	float dist;
	Segment *s;
	for(int i=0; i<os.size(); i++){
		dist = computeDistance(os[i], v);	
		if(dist<distMin){
			distMin = dist;
			s = os[i];
		}
	}
	return s;
}


static void setSegment(Segment *s, float dx, float dy, float dz){
	for(int i=0; i<s->verticesAssocies.size(); i++){
		s->verticesAssocies[i]->m_pos.x += dx;
		s->verticesAssocies[i]->m_pos.y += dy;
		s->verticesAssocies[i]->m_pos.z += dz;
	}
}


static void setCoord(Vector3f *dest, Vector3f src){
	dest->z = src.z;
	dest->y = src.y;
	dest->x = src.x;

}
void Squelette::setHead(Vector3f p){
	setCoord(&head, p);
}

void Squelette::setNeck(Vector3f p){
	setCoord(&neck, p);
}

void Squelette::setAss(Vector3f p){
	setCoord(&ass, p);
}

void Squelette::setSchoulderG(Vector3f p){
	setCoord(&schoulderG, p);
}

void Squelette::setSchoulderD(Vector3f p){
	float dx, dy, dz;
	dx = p.x-schoulderD.x;
	dy = -schoulderD.y+p.y;
	dz = -schoulderD.z+p.z;

	setSegment(os[2], dx, dy, dz);
	setSegment(os[4], dx/2, dy/2, dz/2);

	setCoord(&schoulderD, p);
}
void Squelette::setCoudeG(Vector3f p){
	setCoord(&coudeG, p);
}
void Squelette::setCoudeD(Vector3f p){
	float dx, dy, dz;
	dx = p.x-coudeD.x;
	dy = -coudeD.y+p.y;
	dz = -coudeD.z+p.z;

	setSegment(os[6], dx/2, dy/2, dz/2);
	setSegment(os[4], dx/2, dy/2, dz/2);
	setCoord(&coudeD, p);
}
void Squelette::setMainG(Vector3f p){
	setCoord(&mainG, p);
}

 
void Squelette::setMainD(Vector3f p){
	float dx, dy, dz;
	dx = p.x-mainD.x;
	dy = -mainD.y+p.y;
	dz = -mainD.z+p.z;
	
	setCoord(&mainD, p);
	
	setSegment(os[6], dx/2, dy/2, dz/2);
}
void Squelette::setTorse(Vector3f p){
	setCoord(&torse, p);
}
void Squelette::setBassinG(Vector3f p){
	setCoord(&bassinG, p);
}
void Squelette::setBassinD(Vector3f p){
	setCoord(&bassinD, p);
}
void Squelette::setGenouxG(Vector3f p){
	setCoord(&genouxG, p);
}

void Squelette::setGenouxD(Vector3f p){
	setCoord(&genouxD, p);
}

void Squelette::setPiedG(Vector3f p){
	setCoord(&piedG, p);
}
void Squelette::setPiedD(Vector3f p){
	setCoord(&piedD, p);
}










