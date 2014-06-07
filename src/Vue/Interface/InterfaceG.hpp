#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <gtkmm/main.h>

class InterfaceG;
#include "Menu.hpp"
#include "PageAdmin.hpp"
//#include <GL/glut.h>

class InterfaceG {
	public:
		InterfaceG(int argc, char** argv);
		void run();
		~InterfaceG();	
		void pageAdmin();
		void retMenuFromAdmin();
	private:
		Gtk::Main main;
		Menu *menu;
		PageAdmin *admin;
};
#endif
