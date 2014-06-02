#ifndef DEF_VIEWER
#define DEF_VIEWER

#include "../../Model/OpenGL/Squelette.hpp"


class Viewer {
	public:
		Viewer();
		void launch();
	private:
		Squelette *squelette;
};

#endif
