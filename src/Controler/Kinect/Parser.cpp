#include "Parser.hpp"


#define HEAD "/head_pos_body"
#define MAING "/lefthand_pos_body"
#define MAIND "/righthand_pos_body"
#define SHOULDERL "/leftshoulder_pos_body"
#define SHOULDERR "/rightshoulder_pos_body"
#define ELBOWL "/leftelbow_pos_body"
#define ELBOWR "/rightelbow_pos_body"
#define TORSO "/torso_pos_body"
#define HIPR "/righthip_pos_body"
#define HIPL "/lefthip_pos_body"
#define KNEER "/rightknee_pos_body"
#define KNEEL "/leftknee_pos_body"
#define FOOTR "/rightfoot_pos_body"
#define FOOTL "/leftfoot_pos_body"

#define NBPOINTS 12

void Parser::openFichier(string nomFichier) {
	fichier = new ifstream(nomFichier.c_str(), ios::in);
}

void Parser::parse(Squelette *squelette){


	string mot1;
	float pos1, pos2, pos3;

	for(int i=0; i<NBPOINTS; i++){
		*fichier >> mot1 >> pos1 >> pos2 >> pos3;
		Vector3f p;
		p.x = pos1/1000;
		p.y = pos2/1000;
//		p.z = (pos3-3000)/1500;
		p.z = 0;
		if(! mot1.compare(MAING)){
			squelette->setMainD(p);
		}else if(! mot1.compare(MAIND)){
			squelette->setMainG(p);
		}else if(! mot1.compare(SHOULDERL)){
			squelette->setSchoulderD(p);
		}else if(! mot1.compare(SHOULDERR)){
			squelette->setSchoulderG(p);
		}else if(! mot1.compare(ELBOWL)){
			squelette->setCoudeD(p);
		}else if(! mot1.compare(ELBOWR)){
			squelette->setCoudeG(p);
		}else if(! mot1.compare(TORSO)){
			squelette->setTorse(p);
		}else if(! mot1.compare(HIPL)){
			squelette->setBassinD(p);
		}else if(! mot1.compare(HIPR)){
			squelette->setBassinG(p);
		}else if(! mot1.compare(KNEEL)){
			squelette->setGenouxD(p);
		}else if(! mot1.compare(KNEER)){
			squelette->setGenouxG(p);
		}else if(! mot1.compare(FOOTL)){
			squelette->setPiedD(p);
		}else if(! mot1.compare(FOOTR)){
			squelette->setPiedG(p);
		}else if(! mot1.compare(HEAD)){
			squelette->setHead(p);
		}else{
		} 
	}
}

void Parser::close(){
	fichier->close();
}


