#include "Processing.hpp"
#include "../../Vue/Interface/Fenetre.hpp"

pid_t Processing::lancementProcessing(){
	char *argProcessing[6];
	string nameCommand = PROCESSING_PATH;
	nameCommand = nameCommand + "./processing-java";
	string nameFile = FILE_PROCESSING_PATH;
	//nameFile = nameFile+"/pointsMain.pde";
	string arg1 = "--sketch="+nameFile+"";
	string arg2 = MVT_PATH;
	arg2 = "--output="+arg2+"toto";
	string arg3 = "--force";
	string arg4 = "--run";
	argProcessing[0] = (char *) nameCommand.c_str();
	argProcessing[1] = (char *) arg1.c_str();
	argProcessing[2] = (char *) arg2.c_str();
	argProcessing[3] = (char *) arg3.c_str();
	argProcessing[4] = (char *) arg4.c_str();
	argProcessing[5] = NULL;

	signal(SIGCHLD, SIG_IGN);
	pid_t pidProcess = fork();
	if(pidProcess<0){
		cerr << "Failed to fork" <<endl;
	}else if(pidProcess==0){
		if(execvp(argProcessing[0],argProcessing)){
			cerr<< "failed execute" <<endl;
		}
	}else{			
	}
	return pidProcess;
}


pid_t Processing::lancementProcessingWithMove(string texte){
	char *argProcessing[6];
	string nameCommand = PROCESSING_PATH;
	nameCommand = nameCommand + "./processing-java";
	string nameFile = FILE_PROCESSING_PATH;
	//nameFile = nameFile+"/pointsMain.pde";
	string arg1 = "--sketch="+nameFile+"";
	string arg2 = MVT_PATH;
	arg2 = "--output="+arg2+"toto";
	string arg3 = "--force";
	string arg4 = "--run";
	argProcessing[0] = (char *) nameCommand.c_str();
	argProcessing[1] = (char *) arg1.c_str();
	argProcessing[2] = (char *) arg2.c_str();
	argProcessing[3] = (char *) arg3.c_str();
	argProcessing[4] = (char *) arg4.c_str();
	argProcessing[5] = NULL;

	signal(SIGCHLD, SIG_IGN);
	pid_t pidProcess = fork();
	if(pidProcess<0){
		cerr << "Failed to fork" <<endl;
	}else if(pidProcess==0){
		//Fenetre *fen;
		//fen->afficherMessage("Fin du mouvement");
		if(execvp(argProcessing[0],argProcessing)){
			cerr<< "failed execute" <<endl;
		}
		
	}else{			
		waitpid(pidProcess, NULL, 0);
		string cmde = FILE_PROCESSING_PATH;
		cmde = "mv " + cmde + "/positions.txt mouvements/"+texte;
		system(cmde.c_str());
	}
	return pidProcess;
}
