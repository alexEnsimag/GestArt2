
#include "Game.hpp"

Game::Game(){
	//Parcours du dossier Scenar/
	//Ajout des différents Scenar
}

int Game::getNbScenar(){
	return scenar.size();
}

Scenario Game::getScenar(int i){
	if (i >= scenar.size()){
		cout << "Erreur, tentative d'acces a un scénario inexistant" << endl;
		return scenar[0];
	}
	return scenar[i];
}
