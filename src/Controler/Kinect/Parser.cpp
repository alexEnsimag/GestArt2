#include "Parser.hpp"

#include <fstream>

using namespace std;

int Parser::parse(string nomFichier){
	ifstream fichier(nomFichier.c_str(), ios::in);
	// si l'ouverture a fonctionne
	if(fichier){
		string line;
		while(getline(fichier, line)){
			cout << line;
		}
	fichier.close();
	}else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
	return 0;
}

		
