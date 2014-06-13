
#include "Scenario.hpp"
using namespace std;

void Scenario::addActivite(Activite *a){
	activites.push_back(a);
}

void Scenario::enregistrer(){
	string nomFichier = "Scenario/" + name + ".txt";
	ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);
	if(!fichier){
		cout << "Erreur a la création du Fichier" << endl;
		return;
	}
	fichier << name << endl;
	for(int i=0; i<activites.size(); i++){
		fichier << activites[i]->getName() << endl;
		fichier << activites[i]->getParam() << endl;
		fichier << activites[i]->getEssais() << endl;
	}
	fichier.close();
}

void Scenario::charger(string nomFichier){
	//Ouverture du fichier
	ifstream fichier(nomFichier.c_str(), ios::in);
	if(!fichier){
		cout << "Erreur à l'ouverture du Fichier" << endl;
		return;
	}
	string mot;
	string param;
	fichier >> mot;
	setName(mot);
	int nbEssai;


	while(!fichier.eof()){
		fichier >> mot >> param >> nbEssai;
		if (mot == "ActiviteObjet"){
			addActivite(new ActiviteObjet(param, nbEssai));
		}else if (mot == "ActiviteForme"){
			addActivite(new ActiviteForme(param, nbEssai));
		}else{
			cout << "Activitée non reconnue" << endl;
		}
	}
	//On enleve le doublon de fin
	activites.pop_back();
	fichier.close();
}

void Scenario::setName(string s){
	name = s;
}

string Scenario::getName(){
	return name;
}


	
/*
* Lancement du scenario : - video d'initialisation
			  - lancement of et processing
			  - lance chaque activite
			  - fermeture of et processing 
			   
*/
bool b = false;
void Scenario::launch(){
	// lancement video debut
	Video::lancerVideo("Video/Intro.avi", 7000);
	// lancement processing et of

	for(int i=0; i<activites.size(); i++){
		if(!b && activites[i]->getName()=="ActiviteForme"){
			b = true;
			of = new Of();
			of->lancementOfRecognize();
		}
		
		cout<<activites[i]->getName()<<", "<<activites[i]->getParam()<<endl;
		activites[i]->launch();
	//	sleep(2);
	}
	killOf();
}

int Scenario::getNbActivite(){
	return activites.size();
}

Activite* Scenario::getActivite(int i){
	return(activites[i]);
}

void Scenario::removeActivite(int i){
	activites.erase(activites.begin()+i);
}

void Scenario::killOf(){
	of->killOf();
}


