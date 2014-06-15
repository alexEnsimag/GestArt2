#ifndef DEF_PARSER
#define DEF_PARSER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


#include <string>
#include "../../Model/OpenGL/Skeleton.hpp"

using namespace std;

class Parser{
	public:
		void openFile(string fileName);
		void parse(Skeleton *skeleton);
		void close();
	private:
		ifstream *file;
};


#endif



