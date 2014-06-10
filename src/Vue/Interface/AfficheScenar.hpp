#ifndef DEF_AFFICHE_SCENAR
#define DEF_AFFICHE_SCENAR

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include <unistd.h>
#include <stdlib.h>


class AfficheScenar;
#include "InterfaceG.hpp"

#include <vector>
using namespace std;

class AfficheScenar : public Gtk::Window {
	public : 
		AfficheScenar(InterfaceG* const it, Game *g);
		~AfficheScenar();
	private :
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVM;
		Gtk::VBox *boxVD;
		Gtk::Button *retour;
		Gtk::Button *newScenar;

		Game *jeu;
		InterfaceG *it;
	
		void retAdmin();
		void modifScenar(int i);
		void addScenar();
};
#endif
