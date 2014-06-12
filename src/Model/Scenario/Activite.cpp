
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
int Activite::getDuree(){
	return duree;
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

void Activite::init(){
	setWellDone(false);
}

void Activite::exec(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}

void Activite::closeAct(){
}

void Activite::launch(){
	init();
	int count =0;
	while (count < nbEssai && !wellDone){
		if(count>0){
			afficherMessage("essaie encore");
		}
		count ++;
		exec();
	}
	closeAct();
}

void Activite::afficherMessage(string s){
	Fenetre *fen = new Fenetre();
	fen->afficherMessage(s);

}
