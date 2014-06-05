#ifndef DEF_SEGMENT_
#define	DEF_SEGMENT_

#include <vector>
#include <stdio.h>
#include "math_3d.h"

#include "Mesh.hpp"

class Bone{
	public:

		Bone(Vector3f* a, Vector3f* b);
		Bone(Vector3f* a, Vector3f* b, Mesh *m);
		Vector3f *p1;
		Vector3f *p2;
		double length();
		void display();
	private:
		Mesh *mesh;
		void displayMesh();
		Vector3f getMiddle();
		Vector3f getRotation();
		Vector3f getVector();
};


#endif

