#ifndef DEF_OF
#define DEF_OF

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


#include <string>

using namespace std;

class Of{
	public:
		void launchOfRecognize();
		void launchOfRegister();
		void killOf();
	private:
		pid_t pidProc;
		pid_t pidOf;
};


#endif



