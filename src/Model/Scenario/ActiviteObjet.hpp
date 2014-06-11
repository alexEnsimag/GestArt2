
#ifndef DEF_ACTIVITEOBJET
#define DEF_ACTIVITEOBJET

#include "Activite.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


class ActiviteObjet : public Activite {
	public: 
		ActiviteObjet(std::string p, int nb) : Activite("ActiviteObjet",p, nb){}
		virtual void init();
		virtual void exec();
		virtual void close();

	private:
};

#endif
