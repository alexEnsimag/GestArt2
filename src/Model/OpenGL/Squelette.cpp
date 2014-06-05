
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

	os.push_back(new Bone(&head, &neck));	
	os.push_back(new Bone(&schoulderD, &schoulderG));	
	os.push_back(new Bone(&schoulderG, &coudeG));	
	os.push_back(new Bone(&schoulderD, &coudeD));	
	os.push_back(new Bone(&coudeG, &mainG));	
	os.push_back(new Bone(&coudeD, &mainD));	
	os.push_back(new Bone(&neck, &torse));	
	os.push_back(new Bone(&bassinD, &bassinG));	
	os.push_back(new Bone(&torse, &ass));	
	os.push_back(new Bone(&bassinG, &genouxG));	
	os.push_back(new Bone(&genouxG, &piedG));	
	os.push_back(new Bone(&bassinD, &genouxD));	
	os.push_back(new Bone(&genouxD, &piedD));	
}


Squelette::Squelette(Mesh *aBrasD, Mesh* aBrasG, Mesh* brasD, Mesh* brasG, Mesh* torso, Mesh* tete, Mesh* bassin, Mesh* jambeD, Mesh* jambeG, Mesh* molletD, Mesh* molletG){

	head.x = 0.0f;head.y = 0.8f;head.z = 0.0f;
	schoulderG.x = 0.18f;schoulderG.y = 0.6f;schoulderG.z = 0.0f;
	schoulderD.x = -0.18f;schoulderD.y = 0.6f;schoulderD.z = 0.0f;
	coudeG.x = 0.4f;coudeG.y = 0.6f;coudeG.z = 0.0f;     
	coudeD.x = -0.4f;coudeD.y = 0.6f;coudeD.z = 0.0f; 
	mainG.x = 0.6f;mainG.y = -0.6f;mainG.z = 0.0f; 
	mainD.x = -0.6f;mainD.y = -0.6f;mainD.z = 0.0f; 
	torse.x = 0.0f;torse.y = 0.0f;torse.z = 0.0f;
	bassinG.x = 0.1f;bassinG.y = 0.1f;bassinG.z = 0.0f; 
	bassinD.x = -0.1f;bassinD.y = 0.1f;bassinD.z = 0.0f; 
	genouxG.x = 0.1f;genouxG.y = -0.35f;genouxG.z = 0.0f; 
	genouxD.x = -0.1f;genouxD.y = -0.35f;genouxD.z = 0.0f; 
	piedG.x = 0.1f;piedG.y = -0.7f;piedG.z = 0.0f; 
	piedD.x = -0.1f;piedD.y = -0.7f;piedD.z = 0.0f; 

	os.push_back(new Bone(&head, &neck, tete));	
	os.push_back(new Bone(&schoulderD, &schoulderG, torso));	
	os.push_back(new Bone(&schoulderG, &coudeG, brasG));	
	os.push_back(new Bone(&schoulderD, &coudeD, brasD));	
	os.push_back(new Bone(&coudeG, &mainG, aBrasG));	
	os.push_back(new Bone(&coudeD, &mainD, aBrasD));	
	os.push_back(new Bone(&neck, &torse));	
	os.push_back(new Bone(&bassinD, &bassinG, bassin));
	os.push_back(new Bone(&torse, &ass));	
	os.push_back(new Bone(&bassinG, &genouxG, jambeG));	
	os.push_back(new Bone(&genouxG, &piedG, molletG));	
	os.push_back(new Bone(&bassinD, &genouxD, jambeD));	
	os.push_back(new Bone(&genouxD, &piedD, molletD));	
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

	for(int i=0; i<os.size(); i++){
		os[i]->display();
	}
}

static void setCoord(Vector3f *dest, Vector3f src){
	dest->z = src.z;
	dest->y = src.y;
	dest->x = src.x;
}

void Squelette::setHead(Vector3f p){ setCoord(&head, p);}
void Squelette::setNeck(Vector3f p){ setCoord(&neck, p);}
void Squelette::setAss(Vector3f p){ setCoord(&ass, p);}
void Squelette::setSchoulderG(Vector3f p){ setCoord(&schoulderG, p);}
void Squelette::setSchoulderD(Vector3f p){ setCoord(&schoulderD, p);}
void Squelette::setCoudeG(Vector3f p){ setCoord(&coudeG, p);}
void Squelette::setCoudeD(Vector3f p){ setCoord(&coudeD, p);}
void Squelette::setMainG(Vector3f p){ setCoord(&mainG, p);}
void Squelette::setMainD(Vector3f p){setCoord(&mainD, p);}
void Squelette::setTorse(Vector3f p){ setCoord(&torse, p);}
void Squelette::setBassinG(Vector3f p){ setCoord(&bassinG, p);}
void Squelette::setBassinD(Vector3f p){ setCoord(&bassinD, p);}
void Squelette::setGenouxG(Vector3f p){	setCoord(&genouxG, p);}
void Squelette::setGenouxD(Vector3f p){	setCoord(&genouxD, p);}
void Squelette::setPiedG(Vector3f p){ setCoord(&piedG, p);}
void Squelette::setPiedD(Vector3f p){ setCoord(&piedD, p);}

