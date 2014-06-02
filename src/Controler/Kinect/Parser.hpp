#ifndef DEF_PARSER
#define DEF_PARSER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


#include <string>

using namespace std;

class Parser{
	public:
		void open(string nomFichier);
		void parse();
		void close();

	private:
		ifstream fichier;
};


#endif



