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


class PageAdmin;
#include "InterfaceG.hpp"

class PageAdmin : public Gtk::Window {
	public : 
		PageAdmin(int argc, char** argv, InterfaceG* const it);
		~PageAdmin();
	private :
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVD;
		Gtk::Button *quitter;
		Gtk::CheckButton *screen;
		InterfaceG *it;
	
		void fullsc();
		void retMenu();
};
#endif
