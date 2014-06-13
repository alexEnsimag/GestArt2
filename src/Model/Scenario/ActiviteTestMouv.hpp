
#ifndef DEF_ACTIVITETESTMOUV
#define DEF_ACTIVITETESTMOUV

#include "Activite.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../../Vue/Interface/Dialogue.hpp"
#include "../../Controler/Kinect/Osc.hpp"
#include "../../Controler/Kinect/Of.hpp"


class ActiviteTestMouv : Activite{
	public: 
		ActiviteTestMouv() : Activite("ActiviteTestMouv", "", 0){};
		void testerMouvement(std::string nomMouv);
		virtual void init(){};
		virtual void exec(){};
		virtual void closeAct(){};
		
	private:
};

#endif
