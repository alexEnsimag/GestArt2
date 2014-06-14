
#include "PageAdmin.hpp"

using namespace std;

string texteField;

/*
* Constructeur: Cree la fenetre de la partie administrateur
*/
PageAdmin::PageAdmin(InterfaceG* const itG, Game *j){

		set_title("Gest-Art Application : Admin");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(300,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		viewerParser = new ViewerParser();
		it = itG;
		jeu = j;

		//Création des widget
		boxV = new Gtk::VBox(false ,10);
		boxH1 = new Gtk::HBox(false, 10);
		boxH2 = new Gtk::HBox(false ,10);


		// modification d'un scenario
		modifScenario = new Gtk::Button("Modifier un Scenario");
		modifScenario->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::modifScenarioFunc));

		// enregistrement d'un mvt pour la reconnaissance
		newMouv = new Gtk::Button("Enregistrement\npour\nreconnaissance");
		newMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrementSamples));

		// enregsitrement d'un mvt pour la visualisation
		newMouvSamples = new Gtk::Button("Enregistrement\npour\nvisualisation");
		newMouvSamples->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrement));

		// teste le mouvement pour la reconnaissance
		testMouv = new Gtk::Button("Test de \nReconnaissance");
		testMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::testerMouvement));
	
		// visulalise le mouvement avec le squelette openGL
		mouv = new Gtk::Button("Visualisation");
		mouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::loadMouv));

		// Retour au menu
		quitter = new Gtk::Button("Retour Menu");
		quitter->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::retMenu));

		mouvLabel = new Gtk::Label("Gestion des mouvements:");
		scenLabel = new Gtk::Label("Gestion des scenarios:");

		//Ajout des Widgets
		boxV->pack_start(*mouvLabel, Gtk::PACK_SHRINK);
		boxV->pack_start(*boxH1);
		boxV->pack_start(*boxH2);
		boxV->pack_start(*scenLabel, Gtk::PACK_SHRINK);
		
		boxH1->pack_start(*newMouvSamples);
		boxH1->pack_start(*newMouv);

		boxH2->pack_start(*mouv);
		boxH2->pack_start(*testMouv);

		boxV->pack_end(*quitter,Gtk::PACK_SHRINK);
		boxV->pack_end(*modifScenario,Gtk::PACK_SHRINK);

		boxV->show();
		add(*boxV);

		// ajout des gestes et de leurs numéros correspondant
		// a la map gestes
		MapGestes::addGestesFile();
}

PageAdmin::~PageAdmin(){
	delete quitter;
	delete boxV;
	delete boxH1;
	delete boxH2;
	delete mouv;
	delete mouvLabel;
	delete scenLabel;
	delete newMouv;
	delete modifScenario;
}

// retour au menu du jeu
void PageAdmin::retMenu(){
	it->retMenuFromAdmin();
}


// redirection vers la page de gestion des scenarios
void PageAdmin::modifScenarioFunc(){
	it->pageAfficheScenar();
}



/*
* Permet l'enregistrement d'un nouveau mouvement pour la reconnaissance
* - choix d'un nom pour le mvt
* - lancement de open framework et processing
* - enregistrement du geste et sa classLabel dans un fichier
*/
void PageAdmin::launchEnregistrementSamples(){
	Dialogue diag("Choix d'un nom", this, "Veuillez entrer le nom de votre mouvement");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		// lancement of et processing
		Of *of = new Of();
		of->lancementOfRegister();
		// enregistrement du geste
		MapGestes::enregistrementGeste(texteField);
	} else {
		cout << "Erreur dans le nom du fichier1" << endl;	
	}
}

/*
* Permet l'enregistrement d'un nouveau mouvement pour la visualisation
* - choix d'un nom pour le mouvement
* - lancement de processing et deplacement du fichier d'enregistrement
* dans le bon repertoire 
*/
void PageAdmin::launchEnregistrement(){
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		diag.hide();
		Processing *proc = new Processing();
		proc->lancementProcessingWithMove(texteField);
	} else {
		cout << "Erreur dans le nom du fichier2" << endl;	
		diag.hide();
	}
}

/*
* Apres avoir enregistre un nouveau mouvement our la reconnaissance
* cette fonction permet de tester la reconnaissance de ce mouvemtn
* - choix du mouvement a tester
* - lancement d'une fonction pour tester le mouvement
*/ 
void PageAdmin::testerMouvement() {
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	diag.set_texte("choix");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();

		ActiviteTestMouv *actMouv = new ActiviteTestMouv();
		actMouv->testerMouvement(texteField);
	} else {
		cout << "Erreur dans le nom du fichier3" << endl;	
	}
}

/*
* Apres avoir enregistrer un mouvement pour la visualisation, cette
* fonction permet la visualisation de celui-ci.
* - Choix du mouvement (fichier)
* - visualisation du mvt avec openGL 
*/
void PageAdmin::loadMouv(){
	Gtk::FileChooserDialog openf(*this, "Ouverture de fichier", Gtk::FILE_CHOOSER_ACTION_OPEN);
	//openf.set_current_folder(Glib::get_home_dir());	
	openf.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	openf.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
	openf.set_current_folder("mouvements/");
	Glib::RefPtr<Gtk::FileFilter> filtre = Gtk::FileFilter::create();
	filtre->set_name("Fichier txt");
	filtre->add_mime_type("text/plain");
	openf.add_filter(filtre);
	int resultat = openf.run();
	if(resultat == Gtk::RESPONSE_OK) {
		std::string nomFichier = openf.get_filename();
		// lance le chargement du squelete et son animation
		viewerParser->launch(nomFichier);
	}
}

