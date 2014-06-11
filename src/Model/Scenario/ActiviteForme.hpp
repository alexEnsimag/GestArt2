
#ifndef DEF_ACTIVITEFORME
#define DEF_ACTIVITEFORME

#include "Activite.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#include "../../Controler/Kinect/Of.hpp"
#include "../../Controler/Kinect/Processing.hpp"


class ActiviteForme : public Activite {
	public: 
		ActiviteForme(std::string p, int nb) : Activite("ActiviteForme",p, nb){}
		virtual void launch();
		void killOf();
		

		static const std::vector<std::string> possibleParams;
		static int getParamSize(){
			return possibleParams.size();
		}

	private:
		Of *of;
		Fenetre *fen;
		void lancerOsc();
};

#endif
