#ifndef DEF_MENU
#define DEF_MENU  

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/stock.h>
#include <gtkmm/box.h>

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
		Gtk::Button *quitter;
		Gtk::Button *pi;
		Gtk::Button *screen;
	
		void fullsc();
};
#endif
