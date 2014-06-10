#ifndef DEF_MODIF_SCENAR
#define DEF_MODIF_SCENAR

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include <unistd.h>
#include <stdlib.h>


class ModifScenar;
#include "InterfaceG.hpp"

#include <vector>
using namespace std;

class ModifScenar : public Gtk::Window {
	public : 
		ModifScenar(int argc, char** argv, InterfaceG* const it, Game *g);
		~ModifScenar();
	private :
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVM;
		Gtk::VBox *boxVD;
		Gtk::Button *retour;
		Gtk::Button *newScenar;
		vector<Gtk::Button*> modif;
		vector<Gtk::Label*> nomsScenar;
		Game *jeu;

		InterfaceG *it;
	
		void retAdmin();
		void modifScenar(int i);
		void addScenar();
};
#endif
