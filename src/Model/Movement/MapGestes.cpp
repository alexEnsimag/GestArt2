#include <iostream>
#include <fstream>

#include "MapGestes.hpp"
using namespace std;



std::map<int, std::string> gests;

const string MapGestes::gestFileName = "gestFile.txt";


void MapGestes::addGestesFile(){
     //Ouverture du fichier
     ifstream fichier(MapGestes::gestFileName.c_str(), ios::in | ios::ate);
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

//const std::map<int, string> MapGestes::gests = remplirMap();

void MapGestes::addGest(string name, int number){
    gests.insert ( std::pair<int,string>(number,name) );
    const char * space = " ";
    const char * endLine = "\n";
    ofstream gestFile(MapGestes::gestFileName.c_str(), ios::ate);
    gestFile << number;
    gestFile << space;
    gestFile << name.c_str();
    gestFile << endLine;
    gestFile.close();
}

void MapGestes::enregistrementGeste(string name){
	addGest(name, gests.size() + 1);
}

string MapGestes::getGestByKey(int key) { 
	return gests[key]; 
}
	
int MapGestes::getGestByName(string name) { 
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

