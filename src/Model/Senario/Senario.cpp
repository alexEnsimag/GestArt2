
#include "Senario.hpp"

void Senario::addActivite(Activite a){
	activites.push_back(a);
}

void Senario::enregistrer(){

}

void Senario::charger(string nomFichier){

}

void Senario::setName(string s){
	name = s;
}

string Senario::getName(){
	return name;
}
