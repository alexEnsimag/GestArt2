
#include "Scenario.hpp"
using namespace std;

void Scenario::addActivity(Activity *a){
	activities.push_back(a);
}

void Scenario::record(){
	string fileName = "Scenario/" + name + ".txt";
	ofstream file(fileName.c_str(), ios::out | ios::trunc);
	if(!file){
		cout << "Erreur a la création du Fichier" << endl;
		return;
	}
	file << name << endl;
	for(int i=0; i<activities.size(); i++){
		file << activities[i]->getName() << endl;
		file << activities[i]->getParam() << endl;
		file << activities[i]->getTrialsNumber() << endl;
	}
	file.close();
}

void Scenario::load(string fileName){
	//Ouverture du fichier
	ifstream file(fileName.c_str(), ios::in);
	if(!file){
		cout << "Erreur à l'ouverture du Fichier" << endl;
		return;
	}
	string mot;
	string param;
	file >> mot;
	setName(mot);
	int trialsNb;


	while(!file.eof()){
		file >> mot >> param >> trialsNb;
		if (mot == "ActiviteObjet"){
			addActivity(new ObjectActivity(param, trialsNb));
		}else if (mot == "ActiviteForme"){
			addActivity(new ShapeActivity(param, trialsNb));
		}else{
			cout << "Activitée non reconnue" << endl;
		}
	}
	//On enleve le doublon de fin
	activities.pop_back();
	file.close();
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
	Video::launchVideo("Video/Intro.avi", 7000);
	// lancement processing et of

	for(int i=0; i<activities.size(); i++){
		if(!b && activities[i]->getName()=="ActiviteForme"){
			b = true;
			of = new Of();
			of->launchOfRecognize();
		}
		if(b && activities[i]->getName()=="ActiviteObjet"){
			killOf();
			b = false;
		}	
		cout<<activities[i]->getName()<<", "<<activities[i]->getParam()<<endl;
		activities[i]->launch();
	}
	if(b){
		killOf();
	}
}

int Scenario::getNbActivities(){
	return activities.size();
}

Activity* Scenario::getActivity(int i){
	return(activities[i]);
}

void Scenario::removeActivity(int i){
	activities.erase(activities.begin()+i);
}

void Scenario::killOf(){
	of->killOf();
}


