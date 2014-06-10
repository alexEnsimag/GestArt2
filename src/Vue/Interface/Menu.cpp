#include "Menu.hpp"
#include "../../Controler/Kinect/Processing.hpp"



string texteField;

Menu::Menu(int argc, char** argv, InterfaceG* const itG, Game* g){

		set_title("Gest-Art Application");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);
		selectedScenar = 0;

		//Redimensionnement
		resize(500,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		
		//Link avec l'interface mère
		it = itG;

		//Ajout du lien avec le jeu:
		jeu = g;
		
		//Creation de la vue openGL
		viewerJeux = new ViewerJeux(argc, argv);
		viewerMesh = new ViewerMesh(argc, argv);
		viewerTps = new ViewerTps();
		viewerParser = new ViewerParser();

		//Création des widget
		boxH = new Gtk::HBox(false, 10);
		boxScenar = new Gtk::HBox (false,10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		scenarLabel = new Gtk::Label(jeu->getScenar(0).getName());
		scenarG = new Gtk::Button ("<");
		scenarG->signal_clicked().connect(sigc::mem_fun(*this, &Menu::prevScen));
		scenarD = new Gtk::Button (">");
		scenarD->signal_clicked().connect(sigc::mem_fun(*this, &Menu::nextScen));

		newMouv = new Gtk::Button("Enregistrer\nun\nMouvement");
		newMouv->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launchEnregistrement));
		tempsReel = new Gtk::Button("Temps Reel");
		tempsReel->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launchTps));
		loadMesh = new Gtk::Button("Charger un Mesh");
		loadMesh->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launchMesh));
		
		screen = new Gtk::CheckButton("Plein Ecran");
		screen->signal_toggled().connect(sigc::mem_fun(*this, &Menu::fullsc));
		jouer = new Gtk::Button("JOUER");
		jouer->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launch));
		mouv = new Gtk::Button("Visualiser\n un \nMouvement");
		mouv->signal_clicked().connect(sigc::mem_fun(*this, &Menu::loadMouv));
		login = new Gtk::Button("S'identifier");
		login->signal_clicked().connect(sigc::mem_fun(*this, &Menu::identification));
		
		quitter = new Gtk::Button(Gtk::Stock::QUIT);
		quitter->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
		img = new Gtk::Image("Images/menu.png");

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVD);

		boxVG->pack_start(*mouv);
		boxVG->pack_start(*login);
		boxVG->pack_start(*newMouv);
		boxVG->pack_start(*loadMesh);
		boxVG->pack_start(*tempsReel);
		boxVG->pack_start(*screen, Gtk::PACK_SHRINK);
		boxVG->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxVD->pack_start(*img);
		boxVD->pack_start(*boxScenar,Gtk::PACK_SHRINK);
		boxVD->pack_start(*jouer);

		boxScenar->pack_start(*scenarG,Gtk::PACK_SHRINK);
		boxScenar->pack_start(*scenarLabel);
		boxScenar->pack_start(*scenarD,Gtk::PACK_SHRINK);
		boxH->show();
		add(*boxH);
}

Menu::~Menu(){
	delete jouer;
	delete scenarG;
	delete scenarD;
	delete scenarLabel;
	delete newMouv;
	delete tempsReel;
	delete loadMesh;
	delete login;
	delete quitter;
	delete mouv;
	delete img;
	delete screen;
	delete boxVD;
	delete boxVG;
	delete boxScenar;
	delete boxH;
}

void Menu::fullsc(){
	if(screen->get_active()){
		this->fullscreen();
	}else{
		this->unfullscreen();
	}
}

void Menu::launch(){
	jeu->launch(selectedScenar);
	//viewerJeux->launch();
}

void Menu::launchTps(){
	viewerTps->launch();
}

void Menu::launchMesh(){
	viewerMesh->launch();
}

void Menu::loadMouv(){
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

void Menu::enregistrement(){
	Dialogue diag("Choix d'un dossier", this, "Veuillez entrer le nom defichier");
	diag.set_texte("choix");
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
		texteField = diag.get_texte();
		launchEnregistrement();
	}
}

void Menu::launchEnregistrement(){
	Processing *proc = new Processing();
	proc->lancementProcessing();
/*
	char *argProcessing[6];
	string nameCommand = PROCESSING_PATH;
	nameCommand = nameCommand + "./processing-java";
	string nameFile = FILE_PROCESSING_PATH;
	//nameFile = nameFile+"/pointsMain.pde";
	string arg1 = "--sketch="+nameFile+"";
	string arg2 = MVT_PATH;
	arg2 = "--output="+arg2+"toto";
	string arg3 = "--force";
	string arg4 = "--run";
	argProcessing[0] = (char *) nameCommand.c_str();
	argProcessing[1] = (char *) arg1.c_str();
	argProcessing[2] = (char *) arg2.c_str();
	argProcessing[3] = (char *) arg3.c_str();
	argProcessing[4] = (char *) arg4.c_str();
	argProcessing[5] = NULL;


	pid_t pidProcess = fork();
	if(pidProcess<0){
		cerr << "Failed to fork" <<endl;
	}else if(pidProcess==0){
		if(execvp(argProcessing[0],argProcessing)){
			cerr<< "failed execute" <<endl;
		}
	}else{			
	}
*/
	
/*

	   char *argOf[2];
	   string nameCommandOf = OF_PATH;
	   nameCommandOf = nameCommandOf + "./oscReceiveExample_debug";
	   argOf[0] = (char *) nameCommandOf.c_str();
	   argOf[1] = NULL;
	   pid_t pidProcess = fork();
	   if(pidProcess<0){
	   cerr << "Failed to fork" <<endl;
	   }else if(pidProcess==0){
	   pid_t pidOf = fork();
	   if(pidOf<0){
	   cerr << "Failed to fork" <<endl;
	   }else if(pidOf==0){
	   if(execvp(argOf[0],argOf)){
	   cerr<< "failed execute" <<endl;
	   }
	   }else{			
	   if(execvp(argProcessing[0],argProcessing)){
	   cerr<< "failed execute" <<endl;
	   }
	   }
	   }else{
	   }
*/	 
}

void Menu::identification(){
	Dialogue diag("Acces interface Administrateur", this, "Veuillez entrer le code admministrateur");
	diag.set_texte("admin");
	diag.zoneTexte.set_visibility(false);
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
        	texteField = diag.get_texte();
	if(texteField == "admin"){
		diag.hide();
		it->pageAdmin();
	}else{
		Gtk::MessageDialog diagE(*this, "Erreur de code", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
		int reponse = diagE.run();
		identification();
	}
    	}
}

void Menu::nextScen(){
	selectedScenar +=1;
	selectedScenar %= jeu->getNbScenar(); 
	scenarLabel->set_text(jeu->getScenar(selectedScenar).getName());
}
void Menu::prevScen(){
	selectedScenar += jeu->getNbScenar() - 1 ;
	selectedScenar %= jeu->getNbScenar(); 
	scenarLabel->set_text(jeu->getScenar(selectedScenar).getName());
}
