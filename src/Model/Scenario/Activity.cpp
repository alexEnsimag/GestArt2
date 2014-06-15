#include "Activity.hpp"
using namespace std;


Activity::Activity(string n, string p, int nb){
	name = n;
	param = p;
        trialsNumber = nb;
        wellDone = false;

	chargerDuree();
}

string Activity::getName(){
	return name;
}

string Activity::getParam(){
	return param;
}

int Activity::getTrialsNumber(){
	return trialsNumber;
}

int Activity::getDuree(){
	return duree;
}


void Activity::decrementTrialsNumber(){
	trialsNumber--;
}

string Activity::toString(){
	std::stringstream trialsNb;
	trialsNb << trialsNumber;
	string result = name + ", " + param + " x" + trialsNb.str();
	return result;
}

bool Activity::getWellDone(){
	return wellDone;
}

void Activity::setWellDone(bool b){
	wellDone = b;
	if(name == "ActivityTestMouv" && b){
		displayMessage("mouvement reconnue");		
	}	
}

void Activity::init(){
	wellDone = false;
}

void Activity::exec(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}

void Activity::closeAct(){
}

void Activity::launch(){
	init();
	int count =0;
	while (count < trialsNumber && !wellDone){
		if(count>0){
			Video::launchVideo("Video/EssaieEncore.avi", 5000);
		}
		count ++;
		exec();
	}
	closeAct();
}

void Activity::displayMessage(string s){
	Window *win = new Window();
	win->displayMessage(s);

}

void Activity::chargerDuree(){
	string nomFichier = "Scenario/Activity/" + getName() + ".txt";

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

int Activity::getDuration() {
	return duration;
}
