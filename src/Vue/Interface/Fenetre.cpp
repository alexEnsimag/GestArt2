
#include "Fenetre.hpp"

using namespace std;

/*
* Affichage du message donné en paramètre dans une nouvelle
* fenetre
*/
void Fenetre::afficherMessage(string s){
	fen.set_border_width(50);
	Gtk::Label lab(s);
	fen.add(lab);
	//fen.resize(100, 50);
	fen.show_all();
	Gtk::Main::run(fen);
}
