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
		
		listeActivite = new Gtk::ComboBoxText;
		listeActivite.append("ActiviteForme");
		listeActivite.append("ActiviteObjet");
		listeActivite->signal_changed().connect(sigc::mem_fun(*this, &ModifScenar::updateParam));
		
		listeParam = new Gtk::ComboBoxText;

		validerActivite = new Gtk::Button("Ajouter l'activité");
		validerActivite.signal_clicked().connect(sigc::bind<string>(sigc::mem_fun(*this, &ModifScenar::addActivite), listeActivite.get_active_text()));

		nbEssais = new Gtk::Entry();
		nbEssais->set_text(1);

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
	delete validerActivite;
	delete nomScenar;
	delete nbEssais;
	delete listeActivite;
	delete listeParam;
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
	delete validerActivite;
	delete nomScenar;
	delete nbEssais;
	delete listeActivite;
	delete listeParam;
	it->pageModifScenar(scenar);
}

void ModifScenar::addActivite(){
	string s = listeActivite.get_active_text();

	if(s == "ActiviteForme"){
		ActiviteFormes a = new ActiviteFormes(listeParam->get_active_text(), atoi(nbEssais.get_text()));
		scenar->addActivite(a);
	}else if(s== "ActiviteObjet"){
		ActiviteObjet a = new ActiviteFormes(listeParam->get_active_text(), atoi(nbEssais.get_text()));
		scenar->addActivite(a);
	}else{
		cout << "Ajout d'une activité inconnue" << endl;
	}
}

void modifScenar::updateParam(){
	string s = listeActivite.get_active_text();
	if(s == "ActiviteForme"){
	}else if(s== "ActiviteObjet"){
	}else{
		cout << "Ajout d'une activité inconnue" << endl;
	}

	for(int i=0; i<ActiviteForme.getParams(); i++){
		listeParam.append("ActiviteForme");
	}
}
