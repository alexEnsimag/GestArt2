
#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>
//#include <gtkmm/window.h>
#include <gtkmm.h>

class Fenetre  {
    public :
	Gtk::Window fen;
	void afficherMessage(std::string s);
        void detruireFenetre();
	
    private :
};
#endif
