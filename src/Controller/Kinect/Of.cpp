#include "Of.hpp"

using namespace std;

/*
* Lance les applications open framework et processing
* le programme d'open framework lance est celui pour la reconnaissance
* de gestes
*/
void Of::launchOfRecognize(){
	// preparation commande pour lancer processing
	char *argOf[2];
	string nameCommandOf = OF_PATH_RECOGNIZE;
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
		// lancement de processing
		Processing *proc = new Processing();
	        pidProc = proc->launchProcessing(true);
	}
}


/*
* Lance les applications open framework et processing
* le programme d'open framework lance est celui pour l'enregistrement
* de gestes
*/
void Of::launchOfRegister(){
	// preparation commande pour lancer processing
	char *argOf[2];
	string nameCommandOf = OF_PATH_REGISTER;
	nameCommandOf = nameCommandOf + "./registerGesture_debug";
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
		// lancement de procesing
		Processing *proc = new Processing();
	        pidProc = proc->launchProcessing(false);
	}
}


/*
* permet de fermer les applications openframework et processing
*/
void Of::killOf(){
	kill(pidOf, SIGKILL);
	kill(pidProc, SIGKILL);
	system("killall -9 java");
}
