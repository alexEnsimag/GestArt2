
#include "InterfaceG.hpp"

InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	jeu = new Game;
	menu = new Menu(argc, argv, this, jeu);
	admin = new PageAdmin(this, jeu);
	afficheScenar = NULL;
	modifScenar = NULL;
}

void InterfaceG::run(){
	//Affichage des widget
	menu->show_all();
	//Boucle principale
	Gtk::Main::run(*menu);
}
void InterfaceG::pageAdmin(){
	menu->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}
void InterfaceG::retMenuFromAdmin(){
	admin->hide();
	menu->show_all();
	Gtk::Main::run(*menu);
}

void InterfaceG::pageAfficheScenar(){
	if (afficheScenar != NULL)
		afficheScenar->hide();
	admin->hide();
	maj();
	afficheScenar = new AfficheScenar(this, jeu);
	afficheScenar->show_all();
	Gtk::Main::run(*afficheScenar);
}

void InterfaceG::retAdminFromScenar(){
	afficheScenar->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}

void InterfaceG::pageModifScenar(){
	if (modifScenar != NULL)
		modifScenar->hide();
	afficheScenar->hide();
	modifScenar = new ModifScenar(this, NULL);
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

void InterfaceG::pageModifScenar(Scenario *s){
	if (modifScenar != NULL)
		modifScenar->hide();
	afficheScenar->hide();
	modifScenar = new ModifScenar(this, s);
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

void InterfaceG::retFromModifScenar(){
	maj();
	afficheScenar = new AfficheScenar(this, jeu);
	modifScenar->hide();
	afficheScenar->show_all();
	Gtk::Main::run(*afficheScenar);
}

void InterfaceG::maj(){
	jeu->updateScenar();
}

InterfaceG::~InterfaceG(){
	delete menu;
}
