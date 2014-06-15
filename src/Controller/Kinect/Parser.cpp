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

void Parser::openFile(string fileName) {
	file = new ifstream(fileName.c_str(), ios::in);
}

void Parser::parse(Skeleton *skeleton){

	string mot1;
	float pos1, pos2, pos3;

	for(int i=0; i<NBPOINTS; i++){
		*file >> mot1 >> pos1 >> pos2 >> pos3;
		Vector3f p;
		p.x = pos1/1000;
		p.y = pos2/1000;
		p.z = (pos3-3000)/1500;
//		p.z = 0;
		if(! mot1.compare(MAING)){
			skeleton->setHandD(p);
		}else if(! mot1.compare(MAIND)){
			skeleton->setHandG(p);
		}else if(! mot1.compare(SHOULDERL)){
			skeleton->setShoulderD(p);
		}else if(! mot1.compare(SHOULDERR)){
			skeleton->setShoulderG(p);
		}else if(! mot1.compare(ELBOWL)){
			skeleton->setElbowD(p);
		}else if(! mot1.compare(ELBOWR)){
			skeleton->setElbowG(p);
		}else if(! mot1.compare(TORSO)){
			skeleton->setChest(p);
		}else if(! mot1.compare(HIPL)){
			skeleton->setPelvisD(p);
		}else if(! mot1.compare(HIPR)){
			skeleton->setPelvisG(p);
		}else if(! mot1.compare(KNEEL)){
			skeleton->setKneexD(p);
		}else if(! mot1.compare(KNEER)){
			skeleton->setKneexG(p);
		}else if(! mot1.compare(FOOTL)){
			skeleton->setFootD(p);
		}else if(! mot1.compare(FOOTR)){
			skeleton->setFootG(p);
		}else if(! mot1.compare(HEAD)){
			skeleton->setHead(p);
		}else{
		} 
	}
}

void Parser::close(){
	file->close();
}


