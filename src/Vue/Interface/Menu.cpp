#include <gtkmm/main.h>
#include "Menu.hpp"

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

		screen = new Gtk::CheckButton("Plein Ecran");
		screen->signal_toggled().connect(sigc::mem_fun(*this, &Menu::fullsc));
		jouer = new Gtk::Button("JOUER");
		login = new Gtk::Button("S'identifier");
		quitter = new Gtk::Button(Gtk::Stock::QUIT);
		quitter->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
		img = new Gtk::Image("Images/menu.png");

		//Ajout des Widgets
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVG);

		boxVG->pack_start(*img);
		boxVG->pack_start(*jouer);

		boxVD->pack_start(*login);
		boxVD->pack_start(*screen, Gtk::PACK_SHRINK);
		boxVD->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);
}

Menu::~Menu(){
	delete jouer;
	delete login;
	delete quitter;
	delete img;
	delete screen;
	delete boxVD;
	delete boxVG;
	delete boxH;
}

void Menu::fullsc(){
	if(screen->get_active()){
		this->fullscreen();
	}else{
		this->unfullscreen();
	}
}
