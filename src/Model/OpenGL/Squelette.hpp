
#ifndef DEF_SQUELETTE
#define DEF_SQUELETTE
#include <stdio.h>
#include <math.h>


#include "Segment.hpp"
#include <GL/freeglut.h>
using namespace std;
#include <vector>

class Squelette {
	public:
		Squelette();
		Squelette(vector<Vertex> *vert);
		void draw();
		vector<Segment*> os;

		void setHead(Vector3f p);		
		void setNeck(Vector3f p);		
		void setAss(Vector3f p);		
		void setSchoulderG(Vector3f p);		
		void setSchoulderD(Vector3f p);		
		void setCoudeG(Vector3f p);		
		void setCoudeD(Vector3f p);		
		void setMainG(Vector3f p);		
		void setMainD(Vector3f p);		
		void setTorse(Vector3f p);		
		void setBassinG(Vector3f p);		
		void setBassinD(Vector3f p);		
		void setGenouxG(Vector3f p);		
		void setGenouxD(Vector3f p);		
		void setPiedG(Vector3f p);		
		void setPiedD(Vector3f p);		

	private:

		vector<Vertex*> vertices;
		
		void setVertices();
		Segment* foundSegment(Vertex *v);

		Vector3f head;
		Vector3f neck;
		Vector3f ass;
		Vector3f schoulderG;
		Vector3f schoulderD;
		Vector3f coudeG;
		Vector3f coudeD;
		Vector3f mainG;
		Vector3f mainD;
		Vector3f torse;
		Vector3f bassinG;
		Vector3f bassinD;
		Vector3f genouxG;
		Vector3f genouxD;
		Vector3f piedG;
		Vector3f piedD;
		
		

};
#endif
