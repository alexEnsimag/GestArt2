#ifndef DEF_MENU
#define DEF_MENU  

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>

#include "../OpenGLViewer/ViewerJeux.hpp"
#include "../OpenGLViewer/ViewerParser.hpp"
#include "../OpenGLViewer/ViewerTps.hpp"
#include "../OpenGLViewer/ViewerMesh.hpp"

class Menu : public Gtk::Window {
	public : 
		Menu(int argc, char** argv);
		~Menu();
	private :
		Gtk::HBox *boxH;
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
		Gtk::Image *img;
		ViewerJeux *viewerJeux;
		ViewerMesh *viewerMesh;
		ViewerTps *viewerTps;
		ViewerParser *viewerParser;
	
		void fullsc();
		void launchMesh();
		void launchTps();
		void launch();
		void loadMouv();
};
#endif
