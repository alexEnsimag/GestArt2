#ifndef DEF_VIEWERPARSER
#define DEF_VIEWERPARSER
#include <stdio.h>
//#include <GL/glew.h>
#include <string>
#include "../../Controler/Kinect/Parser.hpp"
#include <unistd.h>
#include <time.h>


#include "../../Model/OpenGL/Squelette.hpp"
//#include <GL/freeglut.h>


class ViewerParser {
	public:
		ViewerParser();
		~ViewerParser();
		void launch(string nomFichier);
	private:
	//	Squelette *squelette;
};

#endif
