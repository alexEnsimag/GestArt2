#include <gtkmm/main.h>
#include "Menu.hpp"

bool full =false;
Menu::Menu(){
		set_title("Gest-Art Application");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(800,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		screen = new Gtk::Button("Plein Ecran");
		screen->signal_clicked().connect(sigc::mem_fun(*this, &Menu::fullsc));
		jouer = new Gtk::Button("JOUER");
		login = new Gtk::Button("S'identifier");
		quitter = new Gtk::Button("Quitter");
		quitter->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
		pi = new Gtk::Button("calculer pi");

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*jouer);
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);

		boxVG->pack_start(*pi);
		boxVG->pack_start(*screen, Gtk::PACK_SHRINK);

		boxVD->pack_start(*login);
		boxVD->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);
}

Menu::~Menu(){
	delete jouer;
	delete login;
	delete quitter;
	delete pi;
	delete screen;
	delete boxVD;
	delete boxVG;
	delete boxH;
}

void Menu::fullsc(){
	if(full){
		full = false;
		this->unfullscreen();
	}else{
		full = true;
		this->fullscreen();
	}
}
		
