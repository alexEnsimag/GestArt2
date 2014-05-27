#include <gtkmm/main.h>
#include <gtkmm/window.h>

int main(int argc, char** argv)
{
	//Création d'un objet Main de l'espace de noms GTK
	Gtk::Main app(argc, argv);
	//Création d'un objet Window de l'espace de noms GTK
	Gtk::Window fenetre;
	fenetre.set_title("Gest-Art Application");
	fenetre.set_icon_from_file("Images/icon.png");
	//Appel du main avec ajout de la fenetre -> Boucle principale
	Gtk::Main::run(fenetre);
	return 0;
}
