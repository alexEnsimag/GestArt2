#include "Admin.hpp"
#include <iostream>
#include <fstream>

Admin::Admin(){ 
     //identifiant = id;
     //motDePasse = mdp;
     gestFileName = "gestFile.txt";
     //Ouverture du fichier
     ifstream fichier(gestFileName.c_str(), ios::in);
     if(!fichier){
         cout << "Erreur à l'ouverture du Fichier des gestes" << endl;
     } else {
         string name;
         int number;
         while(!fichier.eof()){
             fichier >> number;
		fichier >> name;
		gests.insert ( std::pair<int,string>(number,name) );
         }
     }
}

void Admin::addGest(string name, int number){
    gests.insert ( std::pair<int,string>(number,name) );
    const char * space = " ";
    const char * endLine = "\n";
    ofstream gestFile(gestFileName.c_str(), ios::ate);
    gestFile << number;
    gestFile << space;
    gestFile << name.c_str();
    gestFile << endLine;
    gestFile.close();
}

void Admin::enregistrementGeste(string name){
	addGest(name, gests.size() + 1);
}

string Admin::getGestByKey(int key) { 
	return gests[key]; 
}
	
int Admin::getGestByName(string name) { 
	std::map<int, std::string>::const_iterator it;
	int key = -1;

	for (it = gests.begin(); it != gests.end(); ++it) {
		if (it->second == name) {
			key = it->first;
			break;
		}
	}
	return key;
}

