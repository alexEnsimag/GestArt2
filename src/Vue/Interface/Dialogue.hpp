/*
* Classe permettant l'affichage d'une fenetre
* avec une zone de texte à remplir
* Elle hérite de la classe existante Gtk::Dialog pour l'affichage
* de pop-up
*/


#ifndef DEF_DIALOGUE
#define DEF_DIALOGUE
#include <string>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/stock.h>
#include <gtkmm/window.h>

class Dialogue : public Gtk::Dialog {
    public :
        Dialogue(std::string titre, Gtk::Window* parent, std::string message);
	// recupere le texte du dialogue
        std::string get_texte();
	// modifie le texte du dialogue
        void set_texte(std::string texte);
        Gtk::Entry zoneTexte;
        
    private :
        Gtk::Box* boiteV;
        Gtk::Label etiquette;
};
#endif
