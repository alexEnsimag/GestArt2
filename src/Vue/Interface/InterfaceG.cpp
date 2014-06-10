
#include "InterfaceG.hpp"

InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	menu = new Menu(argc, argv, this);
	admin = new PageAdmin(argc, argv, this);
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

InterfaceG::~InterfaceG(){
	delete menu;
}
