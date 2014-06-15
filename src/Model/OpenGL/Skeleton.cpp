
#include "Skeleton.hpp"


Skeleton::Skeleton(){


	head.x = 0.0f;
	head.z = 2.0f;
	head.y = 0.8f;

	shoulderG.x = 0.18f; 
	shoulderG.z = 2.0f;
	shoulderG.y = 0.6f;
	shoulderD.x = -0.18f;
	shoulderD.z = 2.0f;
	shoulderD.y = 0.6f;


	elbowG.x = 0.2f;
	elbowG.z = 2.0f;     
	elbowG.y = 0.18f;
	elbowD.x = -0.2f;
	elbowD.z = 2.0f; 
	elbowD.y = 0.18f;
	handG.x = 0.22f;
	handG.z = 2.0f; 
	handG.y = -0.1f;
	handD.x = -0.22f;
	handD.z = 2.0f; 
	handD.y = -0.1f;
	chest.x = 0.0f;
	chest.z = 2.0f; 
	chest.y = 0.0f;
	pelvisG.x = 0.1f;
	pelvisG.z = 2.0f; 
	pelvisG.y = 0.1f;
	pelvisD.x = -0.1f;
	pelvisD.z = 2.0f; 
	pelvisD.y = 0.1f; 
	kneexG.x = 0.1f;
	kneexG.z = 2.0f; 
	kneexG.y = -0.35f;
	kneexD.x = -0.1f;
	kneexD.z = 2.0f; 
	kneexD.y = -0.35f;
/*
	footG.x = 0.1f;
	footG.z = 2.0f; 
	footG.y = -0.7f;
	footD.x = -0.1f;
	footD.z = 2.0f; 
	footD.y = -0.7f;
*/
	os.push_back(new Bone(&pelvisD, &pelvisG));	
	os.push_back(new Bone(&neck, &chest));	
	os.push_back(new Bone(&chest, &ass));	
	//os.push_back(new Bone(&head, &neck));	
	os.push_back(new Bone(&shoulderD, &shoulderG));	
	os.push_back(new Bone(&shoulderG, &elbowG));	
	os.push_back(new Bone(&shoulderD, &elbowD));	
	os.push_back(new Bone(&pelvisG, &kneexG));	
	os.push_back(new Bone(&pelvisD, &kneexD));	
	os.push_back(new Bone(&elbowG, &handG));	
	os.push_back(new Bone(&elbowD, &handD));	
	//os.push_back(new Bone(&kneexG, &footG));	
	//os.push_back(new Bone(&kneexD, &footD));	
}


Skeleton::Skeleton(Mesh *aBrasD, Mesh* aBrasG, Mesh* brasD, Mesh* brasG, Mesh* torso, Mesh* tete, Mesh* pelvis, Mesh* jambeD, Mesh* jambeG, Mesh* molletD, Mesh* molletG){

	head.x = 0.0f;head.y = 0.8f;head.z = 0.0f;
	shoulderG.x = 0.18f;shoulderG.y = 0.6f;shoulderG.z = 0.0f;
	shoulderD.x = -0.18f;shoulderD.y = 0.6f;shoulderD.z = 0.0f;
	elbowG.x = 0.4f;elbowG.y = 0.6f;elbowG.z = 0.0f;     
	elbowD.x = -0.4f;elbowD.y = 0.6f;elbowD.z = 0.0f; 
	handG.x = 0.6f;handG.y = -0.6f;handG.z = 0.0f; 
	handD.x = -0.6f;handD.y = -0.6f;handD.z = 0.0f; 
	chest.x = 0.0f;chest.y = 0.0f;chest.z = 0.0f;
	pelvisG.x = 0.1f;pelvisG.y = 0.1f;pelvisG.z = 0.0f; 
	pelvisD.x = -0.1f;pelvisD.y = 0.1f;pelvisD.z = 0.0f; 
	kneexG.x = 0.1f;kneexG.y = -0.35f;kneexG.z = 0.0f; 
	kneexD.x = -0.1f;kneexD.y = -0.35f;kneexD.z = 0.0f; 
	//footG.x = 0.1f;footG.y = -0.7f;footG.z = 0.0f; 
	//footD.x = -0.1f;footD.y = -0.7f;footD.z = 0.0f; 

	os.push_back(new Bone(&pelvisD, &pelvisG));
	os.push_back(new Bone(&chest, &ass, pelvis));	
	os.push_back(new Bone(&shoulderD, &shoulderG));	
	os.push_back(new Bone(&shoulderG, &elbowG, brasG));	
	os.push_back(new Bone(&shoulderD, &elbowD, brasD));	
	os.push_back(new Bone(&neck, &chest, torso));	
	os.push_back(new Bone(&head, &neck, tete));	
	os.push_back(new Bone(&elbowG, &handG, aBrasG));	
	os.push_back(new Bone(&elbowD, &handD, aBrasD));	
	os.push_back(new Bone(&pelvisG, &kneexG, jambeG));	
	os.push_back(new Bone(&pelvisD, &kneexD, jambeD));	
	//os.push_back(new Bone(&kneexG, &footG, molletG));	
	//os.push_back(new Bone(&kneexD, &footD, molletD));	
}

void Skeleton::draw(){

	glLineWidth(6);

	// maj neck et ass
	Vector3f pNeck;
	pNeck.x =  (shoulderG.x+shoulderD.x)/2;
	pNeck.y =  (shoulderG.y+shoulderD.y)/2;
	pNeck.z =  (shoulderG.z+shoulderD.z)/2;
	setNeck(pNeck);
	Vector3f pAss;
	pAss.x =  (pelvisG.x+pelvisD.x)/2;
	pAss.y =  (pelvisG.y+pelvisD.y)/2;
	pAss.z =  (pelvisG.z+pelvisD.z)/2;
	setAss(pAss);

	//maj foot et kneex
	/*
	kneexD.x = pelvisD.x;
	kneexD.z = pelvisD.z;
	kneexG.x = pelvisG.x;
	kneexG.z = pelvisG.z;
	footD.x = kneexD.x;
	footD.z = kneexD.z;
	footG.x = kneexG.x;
	footG.z = kneexG.z;
	*/
	 

	for(int i=0; i<os.size(); i++){
		os[i]->display();
	}
}

static void setCoord(Vector3f *dest, Vector3f src){
	dest->z = src.z;
	dest->y = src.y;
	dest->x = src.x;
}

void Skeleton::setHead(Vector3f p){ setCoord(&head, p);}
void Skeleton::setNeck(Vector3f p){ setCoord(&neck, p);}
void Skeleton::setAss(Vector3f p){ setCoord(&ass, p);}
void Skeleton::setShoulderG(Vector3f p){ setCoord(&shoulderG, p);}
void Skeleton::setShoulderD(Vector3f p){ setCoord(&shoulderD, p);}
void Skeleton::setElbowG(Vector3f p){ setCoord(&elbowG, p);}
void Skeleton::setElbowD(Vector3f p){ setCoord(&elbowD, p);}
void Skeleton::setHandG(Vector3f p){ setCoord(&handG, p);}
void Skeleton::setHandD(Vector3f p){setCoord(&handD, p);}
void Skeleton::setChest(Vector3f p){ setCoord(&chest, p);}
void Skeleton::setPelvisG(Vector3f p){ setCoord(&pelvisG, p);}
void Skeleton::setPelvisD(Vector3f p){ setCoord(&pelvisD, p);}
void Skeleton::setKneexG(Vector3f p){	setCoord(&kneexG, p);}
void Skeleton::setKneexD(Vector3f p){	setCoord(&kneexD, p);}
void Skeleton::setFootG(Vector3f p){ setCoord(&footG, p);}
void Skeleton::setFootD(Vector3f p){ setCoord(&footD, p);}

