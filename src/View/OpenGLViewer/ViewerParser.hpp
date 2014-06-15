#ifndef DEF_VIEWERPARSER
#define DEF_VIEWERPARSER
#include <stdio.h>
//#include <GL/glew.h>
#include <string>
#include "../../Controller/Kinect/Parser.hpp"
#include <unistd.h>
#include <time.h>


#include "../../Model/OpenGL/Skeleton.hpp"
#include "../../Model/OpenGL/Scene.hpp"
//#include <GL/freeglut.h>


class ViewerParser {
	public:
		ViewerParser();
		~ViewerParser();
		void launch(string nomFichier);
	private:
		bool InitMesh();
		Mesh* aBrasD;
		Mesh* aBrasG;
		Mesh* brasD;
		Mesh* brasG;
		Mesh* torse;
		Mesh* tete;
		Mesh* bassin;
		Mesh* jambeD;
		Mesh* jambeG;
		Mesh* molletD;
		Mesh* molletG;
		
};

#endif
