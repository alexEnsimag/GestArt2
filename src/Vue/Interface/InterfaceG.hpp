#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <gtkmm/main.h>
#include "Menu.hpp"
//#include <GL/glut.h>

class InterfaceG {
	public:
		InterfaceG(int argc, char** argv);
		void run();
		~InterfaceG();	
	private:
		Gtk::Main main;
		Menu *menu;
		
};
#endif
