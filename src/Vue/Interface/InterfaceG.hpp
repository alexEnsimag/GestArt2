/*
* Classe principale, qui permet de créer l'interface de jeu.
*
*/

#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <gtkmm/main.h>

class InterfaceG;

#include "Menu.hpp"
#include "PageAdmin.hpp"
#include "ModifScenar.hpp"
#include "AfficheScenar.hpp"

class InterfaceG {
	public:
		InterfaceG(int argc, char** argv);
		void run();
		~InterfaceG();	
		void pageAdmin();
		void retMenuFromAdmin();
		void pageAfficheScenar();
		void retAdminFromScenar();
		void pageModifScenar();
		void pageModifScenar(Scenario *s);
		void retFromModifScenar();
		void maj();
	private:
		Gtk::Main main;
		// Interface d'entrée de jeu
		Menu *menu;
		// Interface administrateur
		PageAdmin *admin;
		// Interface de gestion des scenarios par l'admin
		AfficheScenar *afficheScenar;
		// Interface de modifcation des scenarios
		ModifScenar *modifScenar;
		// Interface de jeu
		Game *jeu;
};
#endif
