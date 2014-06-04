#ifndef DEF_SEGMENT_
#define	DEF_SEGMENT_

#include <vector>
#include <stdio.h>
#include "math_3d.h"

#include "Mesh.hpp"

class Segment{
	public:
	Vector3f *p1;
	Vector3f *p2;
	std::vector<Vertex*> verticesAssocies;
	Segment(Vector3f* a, Vector3f* b){
		p1 = a;
		p2=b;
	}
};


#endif

