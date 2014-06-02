
#ifndef DEF_SQUELETTE
#define DEF_SQUELETTE

#include "geom.hpp"

class Squelette {
	public:
		Squelette();
		void draw();
	private:
		void setHead(Sommet p);		
		
		Sommet *head;
		Sommet *neck;
		
		

};
#endif
