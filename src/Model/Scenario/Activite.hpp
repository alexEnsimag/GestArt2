#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
//#include <sstream>
#include <string>
#include <vector>

#include "../../Vue/Interface/Fenetre.hpp"
#include "../../Controler/Video/Video.hpp"

#include "../../Model/Movement/MapGestes.hpp"

class Activite {
	public:
		Activite(std::string n, std::string p,int nb);
		virtual ~Activite(){}
		std::string getName();
		std::string getParam();
		std::string toString();
		int getEssais();
		int getDuree();
		void decrementEssai();
		bool getWellDone();
		void setWellDone(bool b);
		virtual void init();
		void launch();
		virtual void exec();
		virtual void closeAct();
		void afficherMessage(std::string s);
		int getDuration();
	protected:
		bool wellDone;
		int duration; // duree de l'activite avant qu'elle soit considérée comme ratée, durée en ms
	private:
		int nbEssai;
		std::string name;
		std::string param;
		int duree;
		void chargerDuree();
		
};
#endif
