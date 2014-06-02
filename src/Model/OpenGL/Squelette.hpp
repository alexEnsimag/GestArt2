
#ifndef DEF_SQUELETTE
#define DEF_SQUELETTE

#include "math_3d.h"
using namespace std;
#include <vector>

class Squelette {
	public:
		Squelette();
		void draw();
		vector<Segment*> os;

		void setHead(float* p);		
		void setNeck(float* p);		
		void setAss(float* p);		
		void setSchoulderG(float* p);		
		void setSchoulderD(float* p);		
		void setCoudeG(float* p);		
		void setCoudeD(float* p);		
		void setMainG(float* p);		
		void setMainD(float* p);		
		void setTorse(float* p);		
		void setBassinG(float* p);		
		void setBassinD(float* p);		
		void setGenouxG(float* p);		
		void setGenouxD(float* p);		
		void setPiedG(float* p);		
		void setPiedD(float* p);		

	private:

		float head[3];
		float neck[3];
		float ass[3];
		float schoulderG[3];
		float schoulderD[3];
		float coudeG[3];
		float coudeD[3];
		float mainG[3];
		float mainD[3];
		float torse[3];
		float bassinG[3];
		float bassinD[3];
		float genouxG[3];
		float genouxD[3];
		float piedG[3];
		float piedD[3];
		
		

};
#endif
