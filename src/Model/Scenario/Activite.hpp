#ifndef DEF_ACTIVITE
#define DEF_ACTIVITE

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../../Vue/Interface/Fenetre.hpp"

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
	private:
		bool wellDone;
		int nbEssai;
		std::string name;
		std::string param;
		int duree;
	protected:
		
};
#endif
