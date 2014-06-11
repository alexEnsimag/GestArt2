
#include "Activite.hpp"
using namespace std;


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

void Activite::decrementEssai(){
	nbEssai--;
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

void Activite::setWellDone(bool b){
	wellDone = b;
}

void Activite::launch(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}

void Activite::afficherMessage(string s){
	Fenetre *fen = new Fenetre();
	fen->afficherMessage(s);

}
