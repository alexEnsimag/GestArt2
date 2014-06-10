
#include "Scenario.hpp"

void Scenario::addActivite(Activite *a){
	activites.push_back(a);
}

void Scenario::enregistrer(){
	ofstream fichier(name.c_str(), ios::out | ios::trunc);
	if(!fichier){
		cout << "Erreur a la création du Fichier" << endl;
		return;
	}
	//fichier << name << endl;
	for(int i=0; i<activites.size(); i++){
		//fichier << activites[i].getName(); << endl;
		//fichier << activites[i].getParam() << endl;
	}
	fichier.close();
}

void Scenario::charger(string nomFichier){
	//Ouverture du fichier
	ifstream fichier(nomFichier.c_str(), ios::in);
	if(!fichier){
		cout << "Erreur a l'ouverture du Fichier" << endl;
		return;
	}
	string mot;
	string param;
	fichier >> mot;
	setName(mot);
	
	while(!fichier.eof()){
		fichier >> mot >> param;
		addActivite(new Activite(mot, param));
	}
	fichier.close();
}

void Scenario::setName(string s){
	name = s;
}

string Scenario::getName(){
	return name;
}
