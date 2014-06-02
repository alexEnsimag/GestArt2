#ifndef DEF_PARSER
#define DEF_PARSER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


#include <string>
#include "../../Model/OpenGL/Squelette.hpp"

using namespace std;

class Parser{
	public:
		void openFichier(string nomFichier);
		void parse(Squelette *squelette);
		void close();

	private:
		ifstream *fichier;
};


#endif



