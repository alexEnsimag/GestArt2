
/*
* classe permettant l'affichage de la fenetre administrateur
*/


#ifndef DEF_ADMIN
#define DEF_ADMIN 

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include <unistd.h>
#include <stdlib.h>

#include "../OpenGLViewer/ViewerParser.hpp"
#include "../../Model/Movement/MapGestes.hpp"
#include "../../Model/Scenario/ActiviteTestMouv.hpp"

class PageAdmin;
#include "InterfaceG.hpp"

class PageAdmin : public Gtk::Window {
	public : 
		PageAdmin(InterfaceG* const it, Game *jeu);
		~PageAdmin();
		void setWellDone(bool b);
	private :
		Game *jeu;
		Gtk::HBox *boxH1;
		Gtk::HBox *boxH2;
		Gtk::VBox *boxV;
		Gtk::Button *quitter;
		Gtk::Button *modifScenario;

		Gtk::Button *mouv;
		Gtk::Button *newMouvSamples;
		Gtk::Button *newMouv;
		Gtk::Button *testMouv;
		Gtk::Label *mouvLabel;
		Gtk::Label *scenLabel;
		InterfaceG *it;
		ViewerParser *viewerParser;

		// pour tester mouvement
		bool wellDone;
	

		void retMenu();
		void modifScenarioFunc();
		void loadMouv();
		void launchEnregistrementSamples();
		void launchEnregistrement();
		void testerMouvement();
};
#endif
