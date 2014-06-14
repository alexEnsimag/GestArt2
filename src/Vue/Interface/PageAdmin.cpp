
#include "PageAdmin.hpp"

using namespace std;

string texteField;

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

		newMouv = new Gtk::Button("Enregistrement\npour\nreconnaissance");
		newMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrement));

		newMouvSamples = new Gtk::Button("Enregistrement\npour\nvisualisation");
		newMouvSamples->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrementSamples));

		testMouv = new Gtk::Button("Test de \nReconnaissance");
		testMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::testerMouvement));
	
		mouv = new Gtk::Button("Visualisation");
		mouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::loadMouv));

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

		//boxVD->pack_start(*modifGeste);
		//boxVD->pack_start(*modifObjet);
		//boxVD->pack_start(*modifAvatar);
		//boxVD->pack_start(*modifTheme);
		//boxVD->pack_start(*getData, Gtk::PACK_SHRINK);
		boxV->pack_end(*quitter,Gtk::PACK_SHRINK);
		boxV->pack_end(*modifScenario,Gtk::PACK_SHRINK);

		boxV->show();
		add(*boxV);

		//admin = new Admin();
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
	delete modifGeste;
	delete modifObjet;
	delete modifAvatar;
	delete modifScenario;
	delete modifTheme;
	delete getData;
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
	it->pageAfficheScenar();
}
void PageAdmin::modifThemeFunc(){
}
void PageAdmin::getDataFunc(){
}

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
		viewerParser->launch(nomFichier);
	}
}

bool PageAdmin::dialogueResponse() {
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	if(diag.run() == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		return true;
	} else {
		cout << "Erreur dans le nom du fichier" << endl;
		return false;
	}
}

void PageAdmin::launchEnregistrementSamples(){
	if(dialogueResponse()) {
		Of *of = new Of();
		of->lancementOfRegister();
		MapGestes::enregistrementGeste(texteField);
	} 
}

void PageAdmin::launchEnregistrement(){
	if(dialogueResponse()) {
		Processing *proc = new Processing();
		proc->lancementProcessingWithMove(texteField);
	}
}

void PageAdmin::testerMouvement() {
	if(dialogueResponse()) {
		ActiviteTestMouv *actMouv = new ActiviteTestMouv();
		actMouv->testerMouvement(texteField);
	}
}

