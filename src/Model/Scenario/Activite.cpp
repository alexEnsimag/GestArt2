#include <iostream>
#include "Activite.hpp"

Activite::Activite(string n, string p){
	name = n;
	param = p;
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

void Activite::setWellDone(bool b){
	wellDone = b;
}
void Activite::launch(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}
