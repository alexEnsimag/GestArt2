
#include "Game.hpp"

using namespace std;

Game::Game(){
	updateScenar();
}

int Game::getNbScenar(){
	return scenar.size();
}

Scenario *Game::getScenar(int i){
	if (i >= scenar.size()){
		cout << "Erreur, tentative d'acces a un scénario inexistant" << endl;
		return &(scenar[0]);
	}
	return &(scenar[i]);
}

void Game::launch(int i){
	scenar[i].launch();
}

void Game::updateScenar(){
	scenar.clear();
	//Parcours du dossier Scenar/ et ajout au jeu
	DIR* rep = opendir("Scenario/");
	if(rep == NULL){
		cout << "ERREUR DOSSIER SCENARIO NOT FOUND" << endl;
		return;
	}
	struct dirent* fichier = NULL;
	string comp = "txt";
	string badswp = "~";
	string nomF;
	string dir = "Scenario/";
	size_t found;

	while ((fichier = readdir(rep)) != NULL){
		nomF = dir + fichier->d_name;
		found = nomF.find(badswp);
		if (found!=std::string::npos){
		}else{
			found = nomF.find(comp);
			if (found!=std::string::npos){
				Scenario *s = new Scenario();
				s->charger(nomF);
				scenar.push_back(*s);
			}
		}
	}
	closedir(rep);
}

void Game::delScenar(int i){
	string nomFile = "Scenario/" + scenar[i].getName() + ".txt";
	int res = remove(nomFile.c_str());
	scenar.erase(scenar.begin()+i);
}
