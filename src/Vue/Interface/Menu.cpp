#include "Menu.hpp"
//#include "../../Controler/Kinect/Processing.hpp"




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
		viewerTps = new ViewerTps();

		//Création des widget
		boxH = new Gtk::HBox(false, 10);
		boxScenar = new Gtk::HBox (false,10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		scenarLabel = new Gtk::Label(jeu->getScenar(0)->getName());
		scenarG = new Gtk::Button ("<");
		scenarG->signal_clicked().connect(sigc::mem_fun(*this, &Menu::prevScen));
		scenarD = new Gtk::Button (">");
		scenarD->signal_clicked().connect(sigc::mem_fun(*this, &Menu::nextScen));

		
		jouer = new Gtk::Button("JOUER");
		jouer->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launch));
		login = new Gtk::Button("S'identifier");
		login->signal_clicked().connect(sigc::mem_fun(*this, &Menu::identification));
		
		quitter = new Gtk::Button(Gtk::Stock::QUIT);
		quitter->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
		img = new Gtk::Image("Images/menu.png");

		//Ajout des Widgets
		boxH->pack_start(*boxVG,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVD);

		boxVG->pack_start(*login,Gtk::PACK_SHRINK);
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
	delete login;
	delete quitter;
	delete img;
	delete boxVD;
	delete boxVG;
	delete boxScenar;
	delete boxH;
}

void Menu::launch(){
	jeu->launch(selectedScenar);
	//viewerJeux->launch();
}

void Menu::launchTps(){
	viewerTps->launch();
}


void Menu::identification(){
	string texteF;
	Dialogue diag("Acces interface Administrateur", this, "Veuillez entrer le code admministrateur");
	diag.set_texte("admin");
	diag.zoneTexte.set_visibility(false);
	int reponse = diag.run();
	if(reponse == Gtk::RESPONSE_OK) { 
        	texteF = diag.get_texte();
	if(texteF == "admin"){
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
	scenarLabel->set_text(jeu->getScenar(selectedScenar)->getName());
}
void Menu::prevScen(){
	selectedScenar += jeu->getNbScenar() - 1 ;
	selectedScenar %= jeu->getNbScenar(); 
	scenarLabel->set_text(jeu->getScenar(selectedScenar)->getName());
}

void Menu::afficherMessage(string s){
	Gtk::MessageDialog diagE(*this, s, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
	int reponse = diagE.run();

}



