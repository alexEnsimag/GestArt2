#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <gtkmm/main.h>

class InterfaceG;
#include "Menu.hpp"
#include "PageAdmin.hpp"
#include "ModifScenar.hpp"
//#include <GL/glut.h>

class InterfaceG {
	public:
		InterfaceG(int argc, char** argv);
		void run();
		~InterfaceG();	
		void pageAdmin();
		void retMenuFromAdmin();
		void pageModifScenar();
		void retAdminFromScenar();
	private:
		Gtk::Main main;
		Menu *menu;
		PageAdmin *admin;
		ModifScenar *modifScenar;
		Game *jeu;
};
#endif
