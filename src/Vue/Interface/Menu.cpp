#include <gtkmm/main.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/filefilter.h>
#include <string>
#include "Menu.hpp"
#include "../../Controler/Kinect/Parser.hpp"

Menu::Menu(){
		set_title("Gest-Art Application");
		set_icon_from_file("Images/icon.png");
		set_border_width(20);

		//Redimensionnement
		resize(800,500);
		//Positionnement
	 	set_position(Gtk::WIN_POS_CENTER);
		
		//Creation de la vue openGL
		glView = new Viewer();
		glViewParser = new ViewerParser();

		//Création des widget
		boxH = new Gtk::HBox(false, 10);

		boxVG = new Gtk::VBox(false ,10);
		boxVD = new Gtk::VBox(false ,10);

		screen = new Gtk::CheckButton("Plein Ecran");
		screen->signal_toggled().connect(sigc::mem_fun(*this, &Menu::fullsc));
		jouer = new Gtk::Button("JOUER");
		jouer->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launch));
		mouv = new Gtk::Button("Visualiser\n un \nMouvement");
		mouv->signal_clicked().connect(sigc::mem_fun(*this, &Menu::loadMouv));
		jouer->signal_clicked().connect(sigc::mem_fun(*this, &Menu::launch));
		login = new Gtk::Button("S'identifier");
		quitter = new Gtk::Button(Gtk::Stock::QUIT);
		quitter->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
		img = new Gtk::Image("Images/menu.png");

		//Ajout des Widgets
		boxH->pack_start(*boxVD,Gtk::PACK_SHRINK);
		boxH->pack_start(*boxVG);

		boxVG->pack_start(*img);
		boxVG->pack_start(*jouer);

		boxVD->pack_start(*mouv);
		boxVD->pack_start(*login);
		boxVD->pack_start(*screen, Gtk::PACK_SHRINK);
		boxVD->pack_start(*quitter,Gtk::PACK_SHRINK);

		boxH->show();
		add(*boxH);
}

Menu::~Menu(){
	delete jouer;
	delete login;
	delete quitter;
	delete mouv;
	delete img;
	delete screen;
	delete boxVD;
	delete boxVG;
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
	glView->launch();
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
		glViewParser->launch(nomFichier);
	}
}
