#ifndef DEF_MENU
#define DEF_MENU  

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>

#include "../OpenGLViewer/Viewer.hpp"

class Menu : public Gtk::Window {
	public : 
		Menu();
		~Menu();
	private :
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVD;
		Gtk::Button *jouer;
		Gtk::Button *login;
		Gtk::Button *mouv;
		Gtk::Button *quitter;
		Gtk::CheckButton *screen;
		Gtk::Image *img;
		Viewer *glView;
		ViewerParser *glViewParser;
	
		void fullsc();
		void launch();
		void loadMouv();
};
#endif
