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
		Gtk::Button *modifGeste;
		Gtk::Button *modifObjet;
		Gtk::Button *modifAvatar;
		Gtk::Button *modifScenario;
		Gtk::Button *modifTheme;
		Gtk::Button *getData;
		Gtk::CheckButton *screen;
		InterfaceG *it;
	
		void fullsc();
		void retMenu();
		void modifGesteFunc();
		void modifObjetFunc();
		void modifAvatarFunc();
		void modifScenarioFunc();
		void modifThemeFunc();
		void getDataFunc();
};
#endif
