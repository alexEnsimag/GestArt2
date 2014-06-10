#include <iostream>
#include "ActiviteObjet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

pid_t pid;
void kill_child(int sig)
{
        kill(pid,SIGKILL);
}

void ActiviteObjet::intLaunch(){
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
        close(tube[0]);

    } else {  //Parent
        //alarm(1);
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
                wellDone = true;
            } else {
                alarm(1);
            }
        }
        wait(NULL);
    }
}
void ActiviteObjet::launch(){  
    // nombre d'essai courant
    int nb = 0 ;  
    while ((nb < nbEssai) && !(wellDone)){

        intLaunch();
        nb++;
        }
}
