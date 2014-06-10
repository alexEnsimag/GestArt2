#include "PageAdmin.hpp"


string texteField2;

PageAdmin::PageAdmin(int argc, char** argv, InterfaceG* const itG){

		set_title("Gest-Art Application : Admin");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(500,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		it = itG;

		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		modifGeste = new Gtk::Button("Modifier un Geste");
		modifGeste->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifGesteFunc));
		modifObjet = new Gtk::Button("Modifier un Objet");
		modifObjet->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifObjetFunc));
		modifAvatar = new Gtk::Button("Modifier un Avatar");
		modifAvatar->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifAvatarFunc));
		modifScenario = new Gtk::Button("Modifier un Scenario");
		modifScenario->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifScenarioFunc));
		modifTheme = new Gtk::Button("Modifier un Thème");
		modifTheme->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifThemeFunc));
		getData = new Gtk::Button("Récupérer des données");
		getData->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::getDataFunc));

		screen = new Gtk::CheckButton("Plein Ecran");
		screen->signal_toggled().connect(sigc::mem_fun(*this, &PageAdmin::fullsc));
		quitter = new Gtk::Button("Retour Menu");
		quitter->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::retMenu));

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVD);

		boxVG->pack_start(*screen, Gtk::PACK_SHRINK);
		boxVG->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxVD->pack_start(*modifGeste);
		boxVD->pack_start(*modifObjet);
		boxVD->pack_start(*modifAvatar);
		boxVD->pack_start(*modifScenario);
		boxVD->pack_start(*modifTheme);
		boxVD->pack_start(*getData, Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);
}

PageAdmin::~PageAdmin(){
	delete quitter;
	delete screen;
	delete boxVD;
	delete boxVG;
	delete boxH;
	delete modifGeste;
	delete modifObjet;
	delete modifAvatar;
	delete modifScenario;
	delete modifTheme;
	delete getData;
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


void PageAdmin::modifGesteFunc(){
}
void PageAdmin::modifObjetFunc(){
}
void PageAdmin::modifAvatarFunc(){
}
void PageAdmin::modifScenarioFunc(){
}
void PageAdmin::modifThemeFunc(){
}
void PageAdmin::getDataFunc(){
}
