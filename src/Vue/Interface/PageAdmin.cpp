#include "PageAdmin.hpp"


string texteField2;

PageAdmin::PageAdmin(int argc, char** argv, InterfaceG* const itG){

		set_title("Gest-Art Application : Admin");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(800,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		it = itG;

		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		screen = new Gtk::CheckButton("Plein Ecran");
		screen->signal_toggled().connect(sigc::mem_fun(*this, &PageAdmin::fullsc));
		quitter = new Gtk::Button("Retour Menu");
		quitter->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::retMenu));

		//Ajout des Widgets
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVG);

		boxVD->pack_start(*screen, Gtk::PACK_SHRINK);
		boxVD->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);
}

PageAdmin::~PageAdmin(){
	delete quitter;
	delete screen;
	delete boxVD;
	delete boxVG;
	delete boxH;
}

void PageAdmin::fullsc(){
	if(screen->get_active()){
		this->fullscreen();
	}else{
		this->unfullscreen();
	}
}

void PageAdmin::retMenu(){
	it->retMenuFromAdmin();
}
