
#ifndef DEF_SQUELETTE
#define DEF_SQUELETTE
#include <stdio.h>
#include <math.h>


#include "Segment.hpp"
#include <GL/freeglut.h>
using namespace std;
#include <vector>

class Skeleton {
	public:
		Skeleton();
		Skeleton(Mesh *abd, Mesh* abg, Mesh* bd, Mesh* bg, Mesh* chest, Mesh* tete, Mesh* pelvis, Mesh* jd, Mesh* jg, Mesh* md, Mesh* mg);
		void draw();
		vector<Bone*> os;

		void setHead(Vector3f p);		
		void setNeck(Vector3f p);		
		void setAss(Vector3f p);		
		void setShoulderG(Vector3f p);		
		void setShoulderD(Vector3f p);		
		void setElbowG(Vector3f p);		
		void setElbowD(Vector3f p);		
		void setHandG(Vector3f p);		
		void setHandD(Vector3f p);		
		void setChest(Vector3f p);		
		void setPelvisG(Vector3f p);		
		void setPelvisD(Vector3f p);		
		void setKneexG(Vector3f p);		
		void setKneexD(Vector3f p);		
		void setFootG(Vector3f p);		
		void setFootD(Vector3f p);		

	private:

		Vector3f head;
		Vector3f neck;
		Vector3f ass;
		Vector3f shoulderG;
		Vector3f shoulderD;
		Vector3f elbowG;
		Vector3f elbowD;
		Vector3f handG;
		Vector3f handD;
		Vector3f chest;
		Vector3f pelvisG;
		Vector3f pelvisD;
		Vector3f kneexG;
		Vector3f kneexD;
		Vector3f footG;
		Vector3f footD;

};
#endif
