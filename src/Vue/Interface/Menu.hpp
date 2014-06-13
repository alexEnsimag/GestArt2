#ifndef DEF_MENU
#define DEF_MENU  

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/main.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/filefilter.h>
#include <string>
#include <gtkmm/entry.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/label.h>

#include "Dialogue.hpp"
#include "../OpenGLViewer/ViewerJeux.hpp"
#include "../OpenGLViewer/ViewerTps.hpp"
#include "../../Model/Jeu/Game.hpp"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "../../Controler/Kinect/Of.hpp"

class Menu;
#include "InterfaceG.hpp"

class Menu : public Gtk::Window {
	public : 
		Menu(int argc, char** argv, InterfaceG* const it, Game *g);
		~Menu();
		void afficherMessage(string s);
	private :
		Gtk::HBox *boxH;
		Gtk::HBox *boxScenar;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVD;
		Gtk::Button *jouer;
		Gtk::Button *login;
		Gtk::Button *quitter;

		Gtk::Label *scenarLabel;
		Gtk::Button *scenarG;
		Gtk::Button *scenarD;
		int selectedScenar;

		Gtk::Image *imgMenu;
		Gtk::Image *imgSponsor;
		ViewerJeux *viewerJeux;
		ViewerTps *viewerTps;
		InterfaceG *it;
		Game *jeu;
	
		void launchTps();
		void launch();
		void identification();
		void nextScen();
		void prevScen();
};
#endif
