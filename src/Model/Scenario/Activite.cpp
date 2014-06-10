#include <iostream>
#include "Activite.hpp"


Activite::Activite(string n, string p, int nb){
	name = n;
	param = p;
        nbEssai = nb;
        wellDone = false;
}

string Activite::getName(){
	return name;
}

string Activite::getParam(){
	return param;
}

string Activite::toString(){
	string result = name + ", " + param;
	return result;
}

bool Activite::getWellDone(){
	return wellDone;
}

void Activite::launch(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}
