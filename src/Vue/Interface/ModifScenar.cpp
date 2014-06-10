#include "ModifScenar.hpp"


ModifScenar::ModifScenar(int argc, char** argv, InterfaceG* const itG, Game *g){

		set_title("Gest-Art Application : Admin");
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
		boxVM = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		retour = new Gtk::Button("Retour Menu");
		retour->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::retAdmin));
		newScenar = new Gtk::Button("Nouveau Scénario");
		retour->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::addScenar));
		

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVM,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);

		boxVG->pack_start(*retour,Gtk::PACK_SHRINK);
		boxVG->pack_start(*newScenar,Gtk::PACK_SHRINK);

		for (int i=0; i<jeu->getNbScenar(); i++){
			Gtk::Label* lab = new Gtk::Label(jeu->getScenar(i).getName());
			nomsScenar.push_back(lab);

			Gtk::Button* mod = new Gtk::Button("modifier");
			mod->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &ModifScenar::modifScenar), i));
			modif.push_back(mod);
			
			boxVM->pack_start(*lab,Gtk::PACK_SHRINK);
			boxVD->pack_start(*mod,Gtk::PACK_SHRINK);
		}

		boxH->show();
		add(*boxH);
}

ModifScenar::~ModifScenar(){
	delete boxVD;
	delete boxVM;
	delete boxVG;
	delete boxH;
	delete retour;
	delete newScenar;
}


void ModifScenar::retAdmin(){
	it->retMenuFromAdmin();
}

void ModifScenar::addScenar(){
}

void ModifScenar::modifScenar(int i){
	//Modifier jeu->getScenar(i)
}
