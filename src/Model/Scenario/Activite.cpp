#include <iostream>
#include "Activite.hpp"

Activite::Activite(string n, string p){
	name = n;
	param = p;
}

string Activite::getName(){
	return name;
}

string Activite::getParam(){
	return param;
}

void Activite::launch(){
	cout<< "Not yet implemented:" << name << ", " << param << endl;
}
