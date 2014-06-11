#include "Of.hpp"
#include "Processing.hpp"

#define OF_PATH "lib/OpenFrameworks/of_v0.8.1_linux64_release/apps/myApps/recognizeGesture/bin/"

void Of::lancementOf(){
	char *argOf[2];
	string nameCommandOf = OF_PATH;
	nameCommandOf = nameCommandOf + "./recognizeGesture_debug";
	argOf[0] = (char *) nameCommandOf.c_str();
	argOf[1] = NULL;


	signal(SIGCHLD, SIG_IGN);
	pidOf = fork();
	if(pidOf<0){
		cerr << "Failed to fork" <<endl;
	}else if(pidOf==0){
		if(execvp(argOf[0],argOf)){
			cerr<< "failed execute" <<endl;
		}
	}else{			
		Processing *proc = new Processing();
	        pidProc = proc->lancementProcessing();
	}
}


void Of::killOf(){
	kill(pidOf, SIGKILL);
	kill(pidProc, SIGKILL);
	system("killall -9 java");
}
