
#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"


class ActiviteFormes : public Activite {
	public: 
		ActiviteFormes(string p,int nb) : Activite("ActiviteFormes",p, nb){};
		virtual void launch();

	private:
};

#endif
