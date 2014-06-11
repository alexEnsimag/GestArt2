
#ifndef DEF_ACTIVITEFORME
#define DEF_ACTIVITEFORME

#include "Activite.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


class ActiviteForme : public Activite {
	public: 
		ActiviteForme(std::string p, int nb) : Activite("ActiviteForme",p, nb){}
		virtual void launch();
		

		static const std::vector<std::string> possibleParams;
		static int getParamSize(){
			return possibleParams.size();
		}

	private:
};

#endif
