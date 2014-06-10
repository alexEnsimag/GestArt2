
#include "InterfaceG.hpp"

InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	jeu = new Game;
	menu = new Menu(argc, argv, this, jeu);
	admin = new PageAdmin(argc, argv, this);
	modifScenar = new ModifScenar(argc, argv, this, jeu);
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

void InterfaceG::retAdminFromScenar(){
	modifScenar->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}

void InterfaceG::pageModifScenar(){
	admin->hide();
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

InterfaceG::~InterfaceG(){
	delete menu;
}
