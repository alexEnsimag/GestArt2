
#include "InterfaceG.hpp"

InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	jeu = new Game;
	menu = new Menu(argc, argv, this, jeu);
	admin = new PageAdmin(this);
	afficheScenar = new AfficheScenar(this, jeu);
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
	maj();
	admin->hide();
	afficheScenar->show_all();
	Gtk::Main::run(*afficheScenar);
}

void InterfaceG::retAdminFromScenar(){
	afficheScenar->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}

void InterfaceG::pageModifScenar(){
	modifScenar = new ModifScenar(this, NULL);
	afficheScenar->hide();
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

void InterfaceG::pageModifScenar(Scenario *s){
	modifScenar = new ModifScenar(this, s);
	afficheScenar->hide();
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

void InterfaceG::retFromModifScenar(){
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
