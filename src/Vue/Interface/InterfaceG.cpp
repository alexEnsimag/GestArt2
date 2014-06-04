
#include "InterfaceG.hpp"

InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	menu = new Menu(argc, argv);
}

void InterfaceG::run(){
	//Affichage des widget
	menu->show_all();
	//Boucle principale
	Gtk::Main::run(*menu);
}

InterfaceG::~InterfaceG(){
	delete menu;
}
