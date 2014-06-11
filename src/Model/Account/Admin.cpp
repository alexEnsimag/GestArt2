#include "Admin.hpp"

Admin::Admin(string id, string mdp){ 
     identifiant = id;
     motDePasse = mdp;
     gestFileName = ""; // TODO à rajouter le nom du fichier 
}
void Admin::addGest(string name, int number){
    gests.insert ( std::pair<int,string>(number,name) );
}
