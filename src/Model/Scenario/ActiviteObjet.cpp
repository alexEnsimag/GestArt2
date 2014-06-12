#include "ActiviteObjet.hpp"

using namespace std;

pid_t pid;

void kill_child(int sig)
{
        kill(pid,SIGKILL);
}

void ActiviteObjet::init(){  
    //string msg = getParam();
    //msg = "ramener le "+msg;
    //afficherMessage(msg);
	string uri = "Videos/" + getParam() + ".avi";
	Video::lancerVideo(uri, getDuree());
}

void ActiviteObjet::exec(){
    string name ="";
    string commande = "zbarcam";
    int tube[2];
    char * arg[2];
    arg[0] = (char *) commande.c_str();
    arg[1] = NULL;


    signal(SIGALRM,(void (*)(int))kill_child);

    pipe(tube);
    pid = fork() ;

    if(pid < 0) { // Failed
        cerr << "Failed to fork" << endl;

        exit(1);
    } else if (pid == 0 ) { //Child

        close(tube[0]);
        dup2(tube[1], 1);
        if( execvp(arg[0],arg))
            cerr << "failed execute"<< endl;
        close(tube[1]);

    } else {  //Parent
        char    buf[80];
        close(tube[1]);
        read(tube[0], buf, sizeof(buf));
        close(tube[0]);

        bool isName = false;
        for (int i = 0; i< 80 ; i++) {
            if (buf[i] == '\n')
                isName = false ;
            if (isName)
                name = name+buf[i];
            if (buf[i] == ':')
                isName = true;

        }
        if (name != ""){
            if (name == getParam()){
                alarm(1);
                setWellDone( true);
            } else {
                alarm(1);
            }
        }
        wait(NULL);
    }
}

void ActiviteObjet::closeAct(){
    if(getWellDone() == true){
	Video::lancerVideo("Videos/gagné.avi", 2000);
    }else{
	Video::lancerVideo("Videos/perdu.avi",2000);
    }
}
