
#include "Dialogue.hpp"

/*
* Creation de la boite de dialogue avec une zone texte et quelques
* boutons
*/
Dialogue::Dialogue(std::string titre, Gtk::Window* parent, std::string message) : Gtk::Dialog(titre, *parent), boiteV(get_vbox()), etiquette(message) { //Récupération de la boîte verticale avec get_vbox().
    boiteV->pack_start(etiquette);
    boiteV->pack_start(zoneTexte);
    //Ajout de boutons à la boîte de dialogue.
    add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    show_all();
}

/*
* Permet de recuperer le texte de la boite de dialogue
*/
std::string Dialogue::get_texte() {
    return zoneTexte.get_text();
}

/*
* Permet de modifier le texte de la boite de dialogue
*/
void Dialogue::set_texte(std::string texte) {
    zoneTexte.set_text(texte);
}
