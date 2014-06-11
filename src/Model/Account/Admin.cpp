#include "Admin.hpp"
#include <iostream>
#include <fstream>

Admin::Admin(string id, string mdp){ 
     identifiant = id;
     motDePasse = mdp;
     gestFileName = "gestFile.txt";
     //Ouverture du fichier
     ifstream fichier(gestFileName.c_str(), ios::in);
     if(!fichier){
         cout << "Erreur à l'ouverture du Fichier des gestes" << endl;
     } else {
         string name;
         int number;
         while(!fichier.eof()){
             fichier >> number >> name;
         }
         gests.insert ( std::pair<int,string>(number,name) );
     }

}
void Admin::addGest(string name, int number, bool addFile=false){
    gests.insert ( std::pair<int,string>(number,name) );
    if(addFile) {
        const char * space = " ";
        const char * endLine = "\n";
        ofstream gestFile(gestFileName.c_str(), ios::ate);
        gestFile << number;
        gestFile << space;
        gestFile << name.c_str();
        gestFile << endLine;
        gestFile.close();
    }
}

void Admin::enregistrementGeste(string name){
	int classLabel = gests.size();
}



