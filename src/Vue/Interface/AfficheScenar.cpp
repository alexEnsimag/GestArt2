#include "AfficheScenar.hpp"

AfficheScenar::AfficheScenar(InterfaceG* const itG, Game *g){

		set_title("Gest-Art Application : Scénarios");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(500,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		it = itG;
		jeu = g;

		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVM = new Gtk::VBox(false ,25);
		boxVD = new Gtk::VBox(false ,10);
		boxVED = new Gtk::VBox(false ,10);

		retour = new Gtk::Button("Retour");
		retour->signal_clicked().connect(sigc::mem_fun(*this, &AfficheScenar::retAdmin));
		newScenar = new Gtk::Button("New Scénario");
		newScenar->signal_clicked().connect(sigc::mem_fun(*this, &AfficheScenar::addScenar));
		

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVM);
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVED,Gtk::PACK_SHRINK);

		boxVG->pack_start(*retour,Gtk::PACK_SHRINK);
		boxVG->pack_start(*newScenar,Gtk::PACK_SHRINK);

		for (int i=0; i<jeu->getNbScenar(); i++){
			Gtk::Label* lab = new Gtk::Label(jeu->getScenar(i)->getName());

			Gtk::Button* mod = new Gtk::Button("modifier");
			mod->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &AfficheScenar::modifScenar), i));
			Gtk::Button* del = new Gtk::Button("-");
			del->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &AfficheScenar::delScenar), i));
			
			boxVM->pack_start(*lab,Gtk::PACK_SHRINK);
			boxVD->pack_start(*mod,Gtk::PACK_SHRINK);
			boxVED->pack_start(*del,Gtk::PACK_SHRINK);
		}

		boxH->show();
		add(*boxH);
}

AfficheScenar::~AfficheScenar(){
	delete boxVD;
	delete boxVM;
	delete boxVG;
	delete boxH;
	delete retour;
	delete newScenar;
}


void AfficheScenar::retAdmin(){
	it->retAdminFromScenar();
}

void AfficheScenar::addScenar(){
	it->pageModifScenar();
}

void AfficheScenar::modifScenar(int i){
	it->pageModifScenar(jeu->getScenar(i));
}

void AfficheScenar::delScenar(int i){
	jeu->delScenar(i);
	it->pageAfficheScenar();
}
