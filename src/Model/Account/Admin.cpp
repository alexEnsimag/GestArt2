#include "Admin.hpp"
#include <iostream>
#include <fstream>

Admin::Admin(string id, string mdp){ 
     identifiant = id;
     motDePasse = mdp;
     gestFileName = ""; // TODO à rajouter le nom du fichier 
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
