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
		bool getWellDone();
		virtual void launch();
	private:
		std::string name;
		std::string param;
	protected:
		bool wellDone;
		int nbEssai;
		
};
#endif
