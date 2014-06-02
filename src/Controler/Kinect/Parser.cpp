#include "Parser.hpp"



#define MAING "/lefthand_pos_body"
#define MAIND "/righthand_pos_body"



using namespace std;

void Parser::openFichier(string nomFichier) : fichier(nomFichier.c_str(), ios::in){
}

void Parser::parse(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);


	string mot1;
	float pos1, pos2, pos3;
	fichier >> mot1 >> pos1 >> pos2 >> pos3;

	switch(mot1){
		case MAING : setMainG(pos1, pos2, pos3);
			break;

		default:break;

	}
}

void Parser::close(){
	fichier.close();
}


