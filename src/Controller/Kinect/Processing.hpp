#ifndef DEF_PROCESSING
#define DEF_PROCESSING

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sys/wait.h>
#include <unistd.h>


#include <string>

using namespace std;

#define FILE_PROCESSING_PATH "lib/Processing/processing-2.2.1/pointsMain" 
#define FILE_PROCESSING_REC_PATH "lib/Processing/processing-2.2.1/TestPosition" 
#define MVT_PATH "mouvements/"
#define PROCESSING_PATH "lib/Processing/processing-2.2.1/"


class Processing{
	public:
		pid_t launchProcessing(bool recognition);
		pid_t launchProcessingWithMove(string text);
	private:
};


#endif



