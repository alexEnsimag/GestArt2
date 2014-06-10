#include "ModifScenar.hpp"


ModifScenar::ModifScenar(InterfaceG* const itG, Scenario *s){

		set_title("Gest-Art Application : Modification de scénario");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(500,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		it = itG;
		scenar = s;
		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVM = new Gtk::VBox(false , 25);
		boxVD = new Gtk::VBox(false ,10);

		annuler = new Gtk::Button("Annuler");
		annuler->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::retAfficheScenar));

		valider = new Gtk::Button("Valider");
		valider->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::validation));

		nomScenar = new Gtk::Entry();
		nomScenar->set_text(scenar->getName());

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVM);
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);

		boxVG->pack_start(*nomScenar,Gtk::PACK_SHRINK);
		boxVG->pack_start(*annuler,Gtk::PACK_SHRINK);
		boxVG->pack_start(*valider,Gtk::PACK_SHRINK);

		for (int i=0; i<scenar->getNbActivite(); i++){
			Gtk::Label* lab = new Gtk::Label(scenar->getActivite(i)->toString());

			Gtk::Button* mod = new Gtk::Button("-");
			mod->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &ModifScenar::delActivite), i));
	
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
	delete annuler;
	delete valider;
}


void ModifScenar::retAfficheScenar(){
	it->retFromModifScenar();
}

void ModifScenar::validation(){
	scenar->setName(nomScenar->get_text());
	scenar->enregistrer();
	it->retFromModifScenar();
}

void ModifScenar::delActivite(int i){
	scenar->removeActivite(i);
	delete boxVD;
	delete boxVM;
	delete boxVG;
	delete boxH;
	delete annuler;
	delete valider;
	it->pageModifScenar(scenar);
}
