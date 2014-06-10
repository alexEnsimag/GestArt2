
#ifndef DEF_ACTIVITEOBJET
#define DEF_ACTIVITEOBJET

#include "Activite.hpp"


class ActiviteObjet : public Activite {
	public: 
		ActiviteObjet(string p, int nb) : Activite("ActiviteObjet",p, nb){};
		virtual void launch();
		void intLaunch();

	private:
};

#endif
