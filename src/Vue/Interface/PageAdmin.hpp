#ifndef DEF_ADMIN
#define DEF_ADMIN 

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>

#include <unistd.h>
#include <stdlib.h>

#include "../OpenGLViewer/ViewerParser.hpp"
#include "../../Model/Movement/MapGestes.hpp"

class PageAdmin;
#include "InterfaceG.hpp"

class PageAdmin : public Gtk::Window {
	public : 
		PageAdmin(InterfaceG* const it, Game *jeu);
		~PageAdmin();
	private :
		Game *jeu;
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVD;
		Gtk::Button *quitter;
		Gtk::Button *modifGeste;
		Gtk::Button *modifObjet;
		Gtk::Button *modifAvatar;
		Gtk::Button *modifScenario;
		Gtk::Button *modifTheme;
		Gtk::Button *getData;

		Gtk::Button *mouv;
		Gtk::Button *newMouvSamples;
		Gtk::Button *newMouv;
		Gtk::Button *testMouv;
		InterfaceG *it;
		ViewerParser *viewerParser;
	

		void retMenu();
		void modifGesteFunc();
		void modifObjetFunc();
		void modifAvatarFunc();
		void modifScenarioFunc();
		void modifThemeFunc();
		void getDataFunc();
		void loadMouv();
		void launchEnregistrementSamples();
		void launchEnregistrement();
		void testerMouvement();
};
#endif
