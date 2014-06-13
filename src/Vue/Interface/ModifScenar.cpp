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
	if (s == NULL){
		scenar = new Scenario();
		scenar->setName("New_Scenario");
	}else{
		scenar = s;
	}
	//Création des widget
	boxH = new Gtk::HBox(false, 10);

	boxVG = new Gtk::VBox(false ,10);
	boxVM = new Gtk::VBox(false , 25);
	boxVD = new Gtk::VBox(false ,10);

	annuler = new Gtk::Button("Retour");
	annuler->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::retAfficheScenar));

	valider = new Gtk::Button("Valider");
	valider->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::validation));

	newActivite = new Gtk::Label("Add an Activity:");

	listeActivite = new Gtk::ComboBoxText;
	chargerActivites();
	listeActivite->signal_changed().connect(sigc::mem_fun(*this, &ModifScenar::updateParam));


	validerActivite = new Gtk::Button("Ajouter l'activité");
	validerActivite->signal_clicked().connect(sigc::mem_fun(*this, &ModifScenar::addActivite));

	listeParam = new Gtk::ComboBoxText;

	nbEssais = new Gtk::Entry();
	nbEssais->set_text("nb essais");

	nomScenar = new Gtk::Entry();
	nomScenar->set_text(scenar->getName());

	//Ajout des Widgets
	boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
	boxH->pack_start(*boxVM);
	boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);

	boxVG->pack_start(*nomScenar,Gtk::PACK_SHRINK);
	boxVG->pack_start(*newActivite,Gtk::PACK_SHRINK);
	boxVG->pack_start(*listeActivite,Gtk::PACK_SHRINK);
	boxVG->pack_start(*listeParam,Gtk::PACK_SHRINK);
	boxVG->pack_start(*nbEssais,Gtk::PACK_SHRINK);
	boxVG->pack_start(*validerActivite);

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
	it->maj();
	it->retFromModifScenar();
}

void ModifScenar::delActivite(int i){
	scenar->removeActivite(i);
	reloadPage();
}

void ModifScenar::addActivite(){
	string s = listeActivite->get_active_text();

	if(s == "ActiviteForme"){
		ActiviteForme *a = new ActiviteForme(listeParam->get_active_text(), atoi(nbEssais->get_text().c_str()));
		scenar->addActivite(a);
	}else if(s== "ActiviteObjet"){
		ActiviteObjet *a = new ActiviteObjet(listeParam->get_active_text(), atoi(nbEssais->get_text().c_str()));
		scenar->addActivite(a);
	}else{
		cout << "Ajout d'une activité inconnue" << endl;
	}
	scenar->setName(nomScenar->get_text());
	scenar->enregistrer();
	reloadPage();
}



void ModifScenar::reloadPage(){
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

void ModifScenar::chargerActivites(){
	DIR* rep = opendir("Scenario/Activite/");
	if(rep == NULL){
		cout << "ERREUR DOSSIER SCENARIO NOT FOUND" << endl;
		return;
	}
	struct dirent* fichier = NULL;
	string comp = ".txt";
	string nomF;
	size_t found;
	string nomActivite;
	while ((fichier = readdir(rep)) != NULL){
		nomF = fichier->d_name;
		found = nomF.find(comp);
		if (found!=std::string::npos){
			nomActivite = nomF.substr(0,found);
			listeActivite->append(nomActivite);
		}
	}
	closedir(rep);
}

void ModifScenar::updateParam(){
	string nomFichier = "Scenario/Activite/" + listeActivite->get_active_text() + ".txt";

	ifstream fichier(nomFichier.c_str(), ios::in);
	if(!fichier){
		cout << "Erreur à l'ouverture du Fichier" << endl;
		return;
	}
	string param;
	int duree;
	while(!fichier.eof()){
		fichier >> param >> duree;
		listeParam->append(param);
	}
	fichier.close();
}
