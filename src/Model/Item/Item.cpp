#include "Item.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define QR_PATH "Ressources/QrCodes"

Item::Item( string n, string image,string audio){
    name = n;
    imageFileName = image;
    audioFileName = audio;
}


// Genère un Qr code correspendant à l'objet dans le Dossier ressources.
void Item::qrEncode (string qrFileName) {
        char * arg[4];
        string arg0 = "qrencode";
        string arg1 ="-o";
        string arg2 = QR_PATH ;
        arg2 = arg2+ name+".png";
        string arg3 = "'"+name+"'";
          
        arg[0] = (char *) arg0.c_str();
        arg[1] = (char *) arg1.c_str();
        arg[2] = (char *) arg2.c_str();
        arg[3] =(char *) arg3.c_str();
        pid_t pid = fork() ;
        if(pid < 0) { // Failed
            cerr << "Failed to fork in function qrEncode" << endl;
            exit(1);
        } else if (pid == 0 ) { //Child
            if( execvp(arg[0],arg))
                cerr << "failed execute in function qrEncode"<< endl;
        } else {  //Parent
            waitpid(pid, NULL, 0);
        }
    }

string Item::getName(){
    return name;
}
