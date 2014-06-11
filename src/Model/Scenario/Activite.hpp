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
		void decrementEssai();
		bool getWellDone();
		void setWellDone(bool b);
		virtual void init();
		void launch();
		virtual void exec();
		void afficherMessage(std::string s);
	private:
		std::string name;
		std::string param;
	protected:
		bool wellDone;
		int nbEssai;
		
};
#endif
