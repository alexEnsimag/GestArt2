
#include "Activite.hpp"
using namespace std;


Activite::Activite(string n, string p, int nb){
	name = n;
	param = p;
        nbEssai = nb;
        wellDone = false;

	chargerDuree();
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
	if(name == "ActiviteTestMouv" && b){
		afficherMessage("mouvement reconnue");		
	}	
}

void Activite::init(){
	wellDone = false;
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
			Video::lancerVideo("Video/EssaieEncore.avi", 5000);
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

void Activite::chargerDuree(){
	string nomFichier = "Scenario/Activite/" + getName() + ".txt";

	ifstream fichier(nomFichier.c_str(), ios::in);
	if(!fichier){
		cout << "Erreur à l'ouverture du Fichier" << endl;
		return;
	}
	string param2;
	int duree2;
		while(!fichier.eof()){
			fichier >> param2>> duree2;
			if(param2 == getParam()){
				duree=duree2;
			}
		}	
	fichier.close();

}

int Activite::getDuration() {
	return duration;
}
