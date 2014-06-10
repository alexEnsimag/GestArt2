
#include "Activite.hpp"

Activite::Activite(string n, string p, int nb){
	name = n;
	param = p;
        nbEssai = nb;
        wellDone = false;
}

string Activite::getName(){
	return name;
}

string Activite::getParam(){
	return param;
}

int Activite::getEssais(){
	return nbEssai;
}

string Activite::toString(){
	std::stringstream nbEss;
	nbEss << nbEssai;
	string result = name + ", " + param + " x" + nbEss.str();
	return result;
}

bool Activite::getWellDone(){
	return wellDone;
}

void Activite::launch(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}
