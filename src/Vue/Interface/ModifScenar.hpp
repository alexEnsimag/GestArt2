#ifndef DEF_MODIF_SCENAR
#define DEF_MODIF_SCENAR

#include <gtkmm/window.h>  
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/stock.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/comboboxtext.h>

#include <unistd.h>
#include <stdlib.h>


class ModifScenar;
#include "InterfaceG.hpp"

#include <vector>
using namespace std;

class ModifScenar : public Gtk::Window {
	public : 
		ModifScenar(InterfaceG* const it, Scenario *s);
		~ModifScenar();

	private :
		Gtk::HBox *boxH;
		Gtk::VBox *boxVG;
		Gtk::VBox *boxVM;
		Gtk::VBox *boxVD;
		Gtk::Button *annuler;
		Gtk::Button *valider;
		Gtk::Button *validerActivite;
		Gtk::Entry *nomScenar;
		
		Gtk::Label *newActivite;
		Gtk::Entry *nbEssais;
		Gtk::ComboBoxText *listeActivite;
		Gtk::ComboBoxText *listeParam;

		InterfaceG *it;
		Scenario *scenar;
	
		void updateParam();
		void retAfficheScenar();
		void validation();
		void delActivite(int i);
		void addActivite(string s);
};
#endif
