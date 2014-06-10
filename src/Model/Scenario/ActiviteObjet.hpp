
#ifndef DEF_ACTIVITEOBJET
#define DEF_ACTIVITEOBJET

#include "Activite.hpp"


class ActiviteObjet : public Activite {
	public: 
		ActiviteObjet(string p) : Activite("ActiviteObjet",p){};
		virtual void launch();

	private:
};

#endif
