#include "ActiviteObjet.hpp"

using namespace std;
// pid du processus fils 
pid_t pid;

// Cette fonction set à fermer la fenêtre du webcam quand 
// la detection du Qr-Code est effectué
void kill_child(int sig)
{
        kill(pid,SIGKILL);
}

//Override de la méthode exec() dans activité 
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

    if(pid < 0) { 
        // Fork non réussit
        cerr << "Failed to fork" << endl;

        exit(1);
    } else if (pid == 0 ) { 
        // On est dans le fils
        // renvoie les données de la sortie standard 
        // sur le pipe 
        close(tube[0]);
        dup2(tube[1], 1);
        //Exécute de la commande zbarcam
        if( execvp(arg[0],arg))
            cerr << "failed execute"<< endl;
        close(tube[1]);

    } else {  
        // On est dans le père
        // Lit la chaine de caratères depuis le pipe
        char    buf[80];
        close(tube[1]);
        read(tube[0], buf, sizeof(buf));
        close(tube[0]);
        // Extrait le nom de l'objet à partir de la sortie 
        // de la commande zbarcam
        bool isName = false;
        for (int i = 0; i< 80 ; i++) {
            if (buf[i] == '\n')
                isName = false ;
            if (isName)
                name = name+buf[i];
            if (buf[i] == ':')
                isName = true;

        }
        //Met à jours l'attribut Welldone
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

// Affiche les intructions correspondantes à l'activité
void ActiviteObjet::init(){  
    string msg = getParam();
    setWellDone(false);
    msg = "ramener le "+msg;
    afficherMessage(msg);
}
// Affiche un message indiquant l'echec ou la réussite de l'activité
void ActiviteObjet::closeAct(){
    if(getWellDone()){
        afficherMessage("Bravo");
    }else{
        afficherMessage("Perdu!");
    }
}
