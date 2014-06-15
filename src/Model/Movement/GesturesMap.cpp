#include <iostream>
#include <fstream>

#include "GesturesMap.hpp"
using namespace std;



std::map<int, std::string> gests;

const string GesturesMap::gestFileName = "gestFile.txt";


void GesturesMap::addGestesFile(){
     //Ouverture du fichier
     ifstream fichier(GesturesMap::gestFileName.c_str(), ios::in);

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

//const std::map<int, string> GesturesMap::gests = remplirMap();

void GesturesMap::addGest(string name, int number){
    gests.insert ( std::pair<int,string>(number,name) );
    const char * space = " ";
    const char * endLine = "\n";
    ofstream gestFile(GesturesMap::gestFileName.c_str(), ios_base::app);
    gestFile << number;
    gestFile << space;
    gestFile << name.c_str();
    gestFile << endLine;
    gestFile.close();
}

void GesturesMap::recordGeste(string name){
	addGest(name, gests.size() + 1);
}

string GesturesMap::getGestByKey(int key) { 
	return gests[key]; 
}
	
int GesturesMap::getGestByName(string name) { 
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

