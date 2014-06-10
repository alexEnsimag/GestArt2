
#ifndef DEF_ACTIVITEFORMES
#define DEF_ACTIVITEFORMES

#include "Activite.hpp"


class ActiviteFormes : public Activite {
	public: 
		ActiviteFormes(string p) : Activite("ActiviteFormes",p){};
		virtual void launch();

	private:
};

#endif
