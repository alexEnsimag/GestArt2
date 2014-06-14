
#include "InterfaceG.hpp"

/*
* Création d'un jeu, d'un menu et d'une classe admin.
*/
InterfaceG::InterfaceG(int argc, char** argv) : main(argc, argv) {
	
	// initialisation de glut pour la vue opengl
	glutInit(&argc, argv);
	jeu = new Game;
	menu = new Menu(argc, argv, this, jeu);
	admin = new PageAdmin(this, jeu);
	afficheScenar = NULL;
	modifScenar = NULL;
}

void InterfaceG::run(){
	//Affichage des widget
	menu->show_all();
	//Boucle principale
	Gtk::Main::run(*menu);
}

/*
* Cache le menu et affiche la page administrateur
*/
void InterfaceG::pageAdmin(){
	menu->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}
void InterfaceG::retMenuFromAdmin(){
	admin->hide();
	menu->show_all();
	Gtk::Main::run(*menu);
}

/*
* Permet l'affichage de la page de gestion des scenarios 
*/
void InterfaceG::pageAfficheScenar(){
	if (afficheScenar != NULL)
		afficheScenar->hide();
	// cache la fenetre admin
	admin->hide();
	maj();
	// affiche la fenetre de gestion d'un scenario 
	afficheScenar = new AfficheScenar(this, jeu);
	afficheScenar->show_all();
	Gtk::Main::run(*afficheScenar);
}

/*
* Permet de retourner a la page administrateur a partir
* de la page de gestion des scenarios
*/
void InterfaceG::retAdminFromScenar(){
	afficheScenar->hide();
	admin->show_all();
	Gtk::Main::run(*admin);
}

/*
* Permet d'afficher la fenetre d'ajout ou modif d'un scenario
*/
void InterfaceG::pageModifScenar(){
	if (modifScenar != NULL)
		modifScenar->hide();
	afficheScenar->hide();
	modifScenar = new ModifScenar(this, NULL);
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

/*
* Permet d'afficher la fenetre de modification du scenario donné
* en parametre
*/
void InterfaceG::pageModifScenar(Scenario *s){
	if (modifScenar != NULL)
		modifScenar->hide();
	afficheScenar->hide();
	modifScenar = new ModifScenar(this, s);
	modifScenar->show_all();
	Gtk::Main::run(*modifScenar);
}

void InterfaceG::retFromModifScenar(){
	maj();
	afficheScenar = new AfficheScenar(this, jeu);
	modifScenar->hide();
	afficheScenar->show_all();
	Gtk::Main::run(*afficheScenar);
}

/*
* mise a jour des modifications pour l'affichage
*/
void InterfaceG::maj(){
	jeu->updateScenar();
}

InterfaceG::~InterfaceG(){
	delete menu;
}
