
#include "PageAdmin.hpp"

using namespace std;

string texteField;

PageAdmin::PageAdmin(InterfaceG* const itG, Game *j){

		set_title("Gest-Art Application : Admin");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(500,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		//Link vers le parent
		viewerParser = new ViewerParser();
		it = itG;
		jeu = j;

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

		newMouv = new Gtk::Button("Enregistrer\nles points\nd'un\nMouvement");
		newMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrement));

		newMouvSamples = new Gtk::Button("Enregistrer\nun\nMouvement");
		newMouvSamples->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::launchEnregistrementSamples));

		testMouv = new Gtk::Button("Tester\nun\nMouvement");
		testMouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::testerMouvement));
	
		mouv = new Gtk::Button("Visualiser\n un \nMouvement");
		mouv->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::loadMouv));

		quitter = new Gtk::Button("Retour Menu");
		quitter->signal_clicked().connect(sigc::mem_fun(*this, &PageAdmin::retMenu));

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVD);

		boxVG->pack_start(*mouv);
		boxVG->pack_start(*newMouv);
		boxVG->pack_start(*newMouvSamples);
		boxVG->pack_start(*testMouv);
		boxVG->pack_start(*quitter,Gtk::PACK_SHRINK);

		//boxVD->pack_start(*modifGeste);
		//boxVD->pack_start(*modifObjet);
		//boxVD->pack_start(*modifAvatar);
		boxVD->pack_start(*modifScenario);
		//boxVD->pack_start(*modifTheme);
		//boxVD->pack_start(*getData, Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);

		//admin = new Admin();
		MapGestes::addGestesFile();
}

PageAdmin::~PageAdmin(){
	delete quitter;
	delete boxVD;
	delete boxVG;
	delete boxH;
	delete mouv;
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

void PageAdmin::launchEnregistrementSamples(){
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	diag.set_texte("choix");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		Of *of = new Of();
		of->lancementOfRegister();
		MapGestes::enregistrementGeste(texteField);
	} else {
		cout << "Erreur dans le nom du fichier" << endl;	
	}
}

void PageAdmin::launchEnregistrement(){
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	diag.set_texte("choix");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		// TODO
		//Processing *proc = new Processing();
		//proc->lancementProcessing();
	} else {
		cout << "Erreur dans le nom du fichier" << endl;	
	}
}

void PageAdmin::testerMouvement() {
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom de fichier");
	diag.set_texte("choix");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		int key = MapGestes::getGestByName(texteField);
		if(key == -1) {
			cout << "Geste inexistant" << endl;
			return;		
		} else {

			cout << "ClassLabel du geste : " << key << endl;		
			Of *of = new Of();
			of->lancementOfRecognize(); 
		}
	} else {
		cout << "Erreur dans le nom du fichier" << endl;	
	}
}

