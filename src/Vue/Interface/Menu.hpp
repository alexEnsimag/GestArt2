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
#include "../OpenGLViewer/ViewerParser.hpp"
#include "../OpenGLViewer/ViewerTps.hpp"
#include "../OpenGLViewer/ViewerMesh.hpp"
#include "../../Controler/Kinect/Parser.hpp"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define PROCESSING_PATH "lib/Processing/processing-2.2.1/"
#define FILE_PROCESSING_PATH "lib/Processing/processing-2.2.1/pointsMain" 
#define OF_PATH "lib/OpenFrameworks/of_v0.8.1_linux64_release/apps/myApps/oscReceiveExample/bin/"
#define MVT_PATH "mouvements/"

class Menu;
#include "InterfaceG.hpp"

class Menu : public Gtk::Window {
	public : 
		Menu(int argc, char** argv, InterfaceG* const it);
		~Menu();
	private :
		Gtk::HBox *boxH;
		Gtk::HBox *boxScenar;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVD;
		Gtk::Button *jouer;
		Gtk::Button *login;
		Gtk::Button *mouv;
		Gtk::Button *newMouv;
		Gtk::Button *tempsReel;
		Gtk::Button *loadMesh;
		Gtk::Button *quitter;
		Gtk::CheckButton *screen;

		Gtk::Label *scenarLabel;
		Gtk::Button *scenarG;
		Gtk::Button *scenarD;
		int selectedScenar;
		vector<std::string> scenar;

		Gtk::Image *img;
		ViewerJeux *viewerJeux;
		ViewerMesh *viewerMesh;
		ViewerTps *viewerTps;
		ViewerParser *viewerParser;
		InterfaceG *it;
	
		void fullsc();
		void launchMesh();
		void launchTps();
		void launch();
		void loadMouv();
		void enregistrement();
		void identification();
		void launchEnregistrement();
		void nextScen();
		void prevScen();
};
#endif
